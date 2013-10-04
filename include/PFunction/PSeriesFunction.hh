
#ifndef PSERIESFUNCTION_HH
#define PSERIESFUNCTION_HH

#include<cstring>
#include<iostream>
#include<vector>

namespace PRISMS
{
    
    template< class InType, class OutType>
    class PBasisFunction
    {
        public:
        OutType _val;
        
        OutType operator()( const InType &var){ _val = eval(var); return _val;};
        OutType operator()(){ return _val;};
        
        private:
        virtual OutType eval( const InType &var){ undefined("OutType eval( const InType &var)");};
        
        void undefined(std::string fname) const
        {
            std::cout << "Error. In PBasisFunction." << std::endl;
            std::cout << "   The member function '" << fname << "' has not been defined." << std::endl;
            exit(1);
        }
    };
    
    
    
    template< class InType, class OutType>
    class PBasisFunctionFactory
    {
        public:
        virtual PBasisFunction<InType, OutType>* new_basis_function( int term) =0;
        virtual PBasisFunction<InType, OutType>* new_basis_grad_function( int term) =0;
        virtual PBasisFunction<InType, OutType>* new_basis_hess_function( int term) =0;
    };
    
    
    /// This class is for a series function that is the tensor product of indepedent bases
    ///
    ///   Example for order-3 tensor:
    ///
    ///    f(x,y,z) = sum_i sum_j sum_k T_ijk * phi_xi(x) * phi_yj(y) * phi_zk(z)
    ///
    ///    summations run from i to _dim[i]
    ///    x, y, z are independent variables (dx/dy = 0, etc.)
    ///
    template< class InType, class OutType, class VarContainer, class IndexContainer>
    class PSeriesFunction : public PBaseFunction<InType, OutType, VarContainer, IndexContainer>
    {
    public:
        using PBaseFunction<double, double, VarContainer, IndexContainer>::_name;
        using PBaseFunction<double, double, VarContainer, IndexContainer>::_var_name;
        
        // tensor info
        std::vector< int > _dim;                        // number of basis functions in each basis set
        std::vector< int > _unroll;                     // used to translate from tensor indices to linear index
        std::vector< OutType > _coeff_tensor;           // unrolled tensor of coefficients (first index is outer loop)
        int _order;                                     // _dim.size()
        int _volume;                                    // _coeff_tensor.size() = product_i(_dim[i]) 
        
        OutType _identity_val;
        OutType _zero_val;
        
        // individual basis functions & derivatives
        std::vector< std::vector< PBasisFunction<InType,OutType>* > > _basis;
        std::vector< std::vector< PBasisFunction<InType,OutType>* > > _basis_grad;
        std::vector< std::vector< PBasisFunction<InType,OutType>* > > _basis_hess;
        
        // evaluated values
        OutType _val;
        std::vector<OutType> _grad_val;
        std::vector< std::vector< OutType> > _hess_val;
        
        PSeriesFunction()
        {
        
        };
        
        PSeriesFunction( OutType zero, InType identity, const IndexContainer &basis_dim, 
                  std::vector<PBasisFunctionFactory<InType,OutType>* > basis_factories) 
        {
            set( zero, identity, basis_dim, basis_factories);
        };
        
        virtual ~PSeriesFunction()
        {
            clear();
        };
        
        void clear()
        {
            for( int i=0; i<_basis.size(); i++)
            for( int j=0; j<_basis[i].size(); j++)
            {
                delete _basis[i][j];
            }
            
            for( int i=0; i<_basis_grad.size(); i++)
            for( int j=0; j<_basis_grad[i].size(); j++)
            {
                delete _basis_grad[i][j];
            }
            
            for( int i=0; i<_basis_hess.size(); i++)
            for( int j=0; j<_basis_hess[i].size(); j++)
            {
                delete _basis_hess[i][j];
            }
            
            _basis.clear();
            _basis_grad.clear();
            _basis_hess.clear();
            _coeff_tensor.clear();
            _dim.clear();
            _unroll.clear();
            _grad_val.clear();
            _hess_val.clear();
            
        }
        
        /// generate the PSeriesFunction
        ///   basis_dim is the number of terms in each basis
        ///   'factories' are arrays of length basis_dim.size() of PBasisFunctionFactory objects 
        ///
        void set( OutType zero, InType identity, const IndexContainer &basis_dim, 
                  std::vector<PBasisFunctionFactory<InType,OutType>* > basis_factories)
        {
            clear();
            
            _zero_val = zero;
            _identity_val = identity;

            _order = basis_dim.size();
            
            if( basis_factories.size() != _order )
            {    
                std::cout << "Error in PSeriesFunction::set." << std::endl;
                std::cout << "  basis_factories.size() != basis_dim.size()" << std::endl;
                exit(1);
            }
            
            _dim.resize( _order );
            _basis.resize( _order );
            _basis_grad.resize( _order );
            _basis_hess.resize( _order );
            
            _grad_val.resize( _order );
            _hess_val.resize( _order );
            
            for( int i=0; i<_order; i++)
            {
                _dim[i] = basis_dim[i];
                _basis[i].resize( basis_dim[i], NULL);
                _basis_grad[i].resize( basis_dim[i], NULL);
                _basis_hess[i].resize( basis_dim[i], NULL);
                
                // Construct basis functions (& grad & hess)
                for( int j=0; j<_dim[i]; j++)
                {
                    _basis[i][j] = basis_factories[i]->new_basis_function(j);
                    _basis_grad[i][j] = basis_factories[i]->new_basis_grad_function(j);
                    _basis_hess[i][j] = basis_factories[i]->new_basis_hess_function(j);
                }
                
                _hess_val[i].resize( _order );
            }
            
            generate_unroll();
            _volume = _dim[0]*_unroll[0];
            _coeff_tensor.resize(_volume);
            
        };
        
        int order() const
        {
            return _order;
        }
        
        int volume() const
        {
            return _volume;
        }
        
        int dim(int i) const
        {
            return _dim[i];
        }
        
        OutType& coeff( int i)
        {
            return _coeff_tensor[i];
        }
        
        OutType& coeff( const IndexContainer &term)
        {
            return _coeff_tensor[linear_index(term)];
        }
        
        int linear_index( const IndexContainer &term) const
        {
            int lindex = 0;
            for( int i=0; i<_unroll.size(); i++)
                lindex += term[i]*_unroll[i];
            return lindex;
        };
        
        template <class Container> void tensor_indices( int lindex, Container &term) const
        {   // assumes term.size() == basis_dim.size()  (the tensor dimensions)
            //   not sure if this is how we want to do it, but it avoids assuming push_back()
            
            for( int i=0; i<_unroll.size(); i++)
            {
                term[i] = lindex/_unroll[i];
                lindex -= term[i]*_unroll[i];
            }
        }

        virtual PSeriesFunction<InType, OutType, VarContainer, IndexContainer> *clone() const
        {
            return new PSeriesFunction<InType, OutType, VarContainer, IndexContainer>(*this);
        };

        // ----------------------------------------------------------
        // Use these functions if you want to evaluate a single value
        virtual OutType operator()(const VarContainer &var)
        {
            // evaluate basis functions needed
            eval_basis(var);
            
            // evaluate basis function products, multiply by _coeff_tensor & sum
            return calc_val();
        };
        
        virtual OutType grad(const VarContainer &var, int di)
        {
            // evaluate basis functions needed
            for( int i=0; i<_order; i++)
            {
                if( i == di)
                {   
                    for( int j=0; j<_dim[i]; j++)
                        (*_basis_grad[i][j])(var[i]);
                }
                else
                {
                    for( int j=0; j<_dim[i]; j++)
                        (*_basis[i][j])(var[i]);
                }
            }
            
            // evaluate basis function products, multiply by _coeff_tensor & sum
            return calc_grad_val(di);
        };
        
        virtual OutType hess(const VarContainer &var, int di, int dj)
        {
            // evaluate basis functions needed
            for( int i=0; i<_order; i++)
            {
                if( i == di || i == dj)
                {   
                    if( di == dj)
                    {
                        for( int j=0; j<_dim[i]; j++)
                            (*_basis_hess[i][j])(var[i]);
                    }
                    else
                    {
                        for( int j=0; j<_dim[i]; j++)
                            (*_basis_grad[i][j])(var[i]);
                    }
                }
                else
                {
                    for( int j=0; j<_dim[i]; j++)
                        (*_basis[i][j])(var[i]);
                }
            }
            
            // evaluate basis function products, multiply by _coeff_tensor & sum
            return calc_hess_val(di,dj);
        };

        // ----------------------------------------------------------
        // Use these functions to evaluate several values, then use 'get' methods to access results
        virtual void eval(const VarContainer &var)
        {
            (*this)(var);
        };
        virtual void eval_grad(const VarContainer &var)
        {
            eval_basis(var);
            
            eval_basis_grad(var);
            
            for( int i=0; i<_order; i++)
                (*this).calc_grad_val(i);
        };
        virtual void eval_hess(const VarContainer &var)
        {
            eval_basis(var);
            
            eval_basis_grad(var);
            
            eval_basis_hess(var);
            
            
            for( int i=0; i<_order; i++)
            for( int j=0; j<_order; j++)
                (*this).calc_hess_val(i,j);
        };

        virtual OutType operator()() const
        {
            return _val;
        };
        virtual OutType grad(int di) const
        {
            return _grad_val[di];
        };
        virtual OutType hess(int di, int dj) const
        {
            return _hess_val[di][dj];
        };


        // Functions for evaluating basis functions & their derivatives:

        // ----------------------------------------------------------
        // Use these functions if you want to evaluate a single value

        //   use basis index and term index for individual basis function
        virtual OutType basis(int bindex, int term, const VarContainer &var)
        {
            return (*_basis[bindex][term])(var[bindex]);
        };
        virtual OutType basis_grad(int bindex, int term, const VarContainer &var)
        {
            return (*_basis_grad[bindex][term])(var[bindex]);
        };
        virtual OutType basis_hess(int bindex, int term, const VarContainer &var)
        {
            return (*_basis_hess[bindex][term])(var[bindex]);
        };

        //   or use tensor indices to evaluate basis function product
        virtual OutType basis(const IndexContainer &term, const VarContainer &var)
        {
            // evaluate basis functions needed
            OutType tmp = _identity_val;
            for( int i=0; i<_order; i++)
                tmp *= (*_basis[i][term[i]])(var[i]);
                
            return tmp;
        };
        virtual OutType basis_grad(const IndexContainer &term, const VarContainer &var, int di)
        {
            // evaluate basis functions needed
            OutType tmp = _identity_val;
            for( int i=0; i<_order; i++)
            {
                if( i == di)
                {   
                    tmp *= (*_basis_grad[i][term[i]])(var[i]);
                }
                else
                {
                    tmp *= (*_basis[i][term[i]])(var[i]);
                }
            }
            
            return tmp;
        };
        virtual OutType basis_hess(const IndexContainer &term, const VarContainer &var, int di, int dj)
        {
            // evaluate basis functions needed
            OutType tmp = _identity_val;
            for( int i=0; i<_order; i++)
            {
                if( i == di || i == dj)
                {   
                    if( di == dj)
                    {
                        tmp *= (*_basis_hess[i][term[i]])(var[i]);
                    }
                    else
                    {
                        tmp *= (*_basis_grad[i][term[i]])(var[i]);
                    }
                }
                else
                {
                    tmp *= (*_basis[i][term[i]])(var[i]);
                }
            }
            
            return tmp;
        };

        // ----------------------------------------------------------
        // Use these functions to evaluate all basis functions,
        //   then use following methods to access results.

        virtual void eval_basis(const VarContainer &var)
        {
            // evaluate basis functions
            for( int i=0; i<_order; i++)
            for( int j=0; j<_dim[i]; j++)
                (*_basis[i][j])(var[i]);
            
        };
        virtual void eval_basis_grad(const VarContainer &var)
        {
            // evaluate basis grad functions
            for( int i=0; i<_order; i++)
            for( int j=0; j<_dim[i]; j++)
                (*_basis_grad[i][j])(var[i]);
        };
        virtual void eval_basis_hess(const VarContainer &var)
        {
            // evaluate basis hess functions
            for( int i=0; i<_order; i++)
            for( int j=0; j<_dim[i]; j++)
                (*_basis_hess[i][j])(var[i]);
        };

        //   use basis index and term index for individual basis function
        virtual OutType basis(int bindex, int term) const
        {
            return (*_basis[bindex][term])();
        };
        virtual OutType basis_grad(int bindex, int term, int di) const
        {
            return (*_basis_grad[bindex][term])();
        };
        virtual OutType basis_hess(int bindex, int term, int di, int dj) const
        {
            return (*_basis_hess[bindex][term])();
        };

        //   or use tensor indices to evaluate basis function product
        virtual OutType basis(const IndexContainer &term) const
        {
            // evaluate basis function product
            OutType tmp = _identity_val;
            for( int i=0; i<_order; i++)
                tmp *= (*_basis[i][term[i]])();
                
            return tmp;
        };
        virtual OutType basis_grad(const IndexContainer &term, int di) const
        {
            // evaluate basis function product
            OutType tmp = _identity_val;
            for( int i=0; i<_order; i++)
            {
                if( i == di)
                {   
                    tmp *= (*_basis_grad[i][term[i]])();
                }
                else
                {
                    tmp *= (*_basis[i][term[i]])();
                }
            }
            
            return tmp;
        };
        virtual OutType basis_hess(const IndexContainer &term, int di, int dj) const
        {
            // evaluate basis function product
            OutType tmp = _identity_val;
            for( int i=0; i<_order; i++)
            {
                if( i == di || i == dj)
                {   
                    if( di == dj)
                    {
                        tmp *= (*_basis_hess[i][term[i]])();
                    }
                    else
                    {
                        tmp *= (*_basis_grad[i][term[i]])();
                    }
                }
                else
                {
                    tmp *= (*_basis[i][term[i]])();
                }
            }
            
            return tmp;
        };
        
        
        ///
        private:
        
        void generate_unroll()
        {
            _unroll.resize(_dim.size());
            _unroll[_dim.size()-1] = 1;
            for( int i=_dim.size()-2; i>=0; i--)
                _unroll[i] = _unroll[i+1]*_dim[i+1];
        };
        
        // ----------------------------------------------------------
        // These assume you've evaluated the necessary _basis, _basis_grad, and _basis_hess functions
        //   and just need to take products & sum
        
        // evaluate basis function products, multiply by _coeff_tensor & sum
        OutType calc_val()
        {
            std::vector<int> tindex(_order);
            OutType tmp;
            _val = _zero_val;
            for( int i=0; i<_volume; i++)
            {
                tmp = _coeff_tensor[i];
                tensor_indices(i, tindex);
                
                for( int j=0; j<_order; j++)
                {
                    tmp *= (*_basis[j][tindex[j]])();
                }
                _val += tmp;
            }
            
            return _val;
        };
        
        // evaluate basis function products, multiply by _coeff_tensor & sum
        OutType calc_grad_val(int di)
        {
            std::vector<int> tindex(_order);
            OutType tmp;
            _grad_val[di] = _zero_val;
            for( int i=0; i<_volume; i++)
            {
                tmp = _coeff_tensor[i];
                tensor_indices(i, tindex);
                for( int j=0; j<_order; j++)
                {
                    if( j == di)
                    {
                        tmp *= (*_basis_grad[j][tindex[j]])();
                    }
                    else
                    {
                        tmp *= (*_basis[j][tindex[j]])();
                    }
                }
                
                _grad_val[di] += tmp;
                
            }
            return _grad_val[di];
        };
        
        // evaluate basis function products, multiply by _coeff_tensor & sum
        OutType calc_hess_val(int di, int dj)
        {
            std::vector<int> tindex(_order);
            OutType tmp;
            _hess_val[di][dj] = _zero_val;
            for( int i=0; i<_volume; i++)
            {
                tmp = _coeff_tensor[i];
                tensor_indices(i, tindex);
                for( int j=0; j<_order; j++)
                {
                    if( j == di || j == dj)
                    {
                        if( di == dj)
                        {
                            tmp *= (*_basis_hess[j][tindex[j]])();
                        }
                        else
                        {
                            tmp *= (*_basis_grad[j][tindex[j]])();
                        }
                    }
                    else
                    {
                        tmp *= (*_basis[j][tindex[j]])();
                    }
                }
                _hess_val[di][dj] += tmp;
            }
            return _hess_val[di][dj];
        }
    };
    

}


#endif