
#ifndef PSERIESFUNCTION_HH
#define PSERIESFUNCTION_HH

#include<cstring>
#include<iostream>
#include<vector>
#include<limits>

#include "PFunction.hh"

namespace PRISMS
{
    /// Evaluate basis functions and their derivatives. Store and access the results.
    ///
    template< class InType, class OutType>
    class PBasisSet
    {
        public:
        
        std::string _name;
        std::string _description;
        
        std::vector<OutType> _val;
        std::vector<OutType> _grad_val;
        std::vector<OutType> _hess_val;
        
        std::string name() const
        {
            return _name;
        };
        std::string description() const
        {
            return _description;
        };
        int size() const
        {
            return _val.size();
        };
        
        PBasisSet( int N)
        {
            resize(N);
        };
        
        virtual void resize( int N)
        {
            _val.resize(N);
            _grad_val.resize(N);
            _hess_val.resize(N);
        };
        
        virtual ~PBasisSet()
        {
        
        };
        
        virtual int max_size()
        {
            // default to (essentially) no limit
            return std::numeric_limits<int>::max();
        };
        
        virtual PBasisSet<InType,OutType>* clone()
        {
            return new PBasisSet<InType, OutType>(*this);
        };
        
        virtual PSimpleFunction<InType, OutType>* clone_basis_function( int term)
        {
            undefined("PSimpleFunction<InType, OutType>* PBasisSet::clone_basis_function( int term)");
        };
        virtual PSimpleFunction<InType, OutType>* clone_grad_basis_function( int term)
        {
            undefined("PSimpleFunction<InType, OutType>* PBasisSet::clone_grad_basis_function( int term)");
        };
        virtual PSimpleFunction<InType, OutType>* clone_hess_basis_function( int term)
        {
            undefined("PSimpleFunction<InType, OutType>* PBasisSet::clone_hess_basis_function( int term)");
        };
        
        // ----------------------------------------------------------
        // Use these functions if you want to evaluate a single value
        OutType operator()(int term, const InType &var)
        {
            return _val[term] = eval(term, var);
        };
        OutType grad(int term, const InType &var)
        {
            return _grad_val[term] = eval_grad(term, var);
        };
        OutType hess(int term, const InType &var)
        {
            return _hess_val[term] = eval_hess(term, var);
        };
        

        // ----------------------------------------------------------
        // Use these functions to evaluate several values, then use 'get' methods to access results
        
        // By default, evaluate each individual term one-by-one. 
        // These are virtual so derived classes may implement more efficient methods.
        //    Returns vector containing results
        virtual const std::vector<OutType>& eval(const InType &var)
        {
            for( int i=0; i<_val.size(); i++)
                (*this)(i,var);
            return _val;
        };
        virtual const std::vector<OutType>& eval_grad(const InType &var)
        {
            for( int i=0; i<_val.size(); i++)
                (*this).grad(i,var);
            return _grad_val;
        };
        virtual const std::vector<OutType>& eval_hess(const InType &var)
        {
            for( int i=0; i<_val.size(); i++)
                (*this).hess(i,var);
            return _hess_val;
        };

        // Getters for individual terms
        OutType operator()(int term) const
        {
            return _val[term];
        };
        OutType grad(int term) const
        {
            return _grad_val[term];
        };
        OutType hess(int term) const
        {
            return _hess_val[term];
        };
        
        // Getters returning vector containing all terms
        const std::vector<OutType>& operator()() const
        {
            return _val;
        };
        const std::vector<OutType>& grad() const
        {
            return _grad_val;
        };
        const std::vector<OutType>& hess() const
        {
            return _hess_val;
        };

    private:
        
        /// ----------------------------------------------------------
        /// !!! Derived classes must define these functions !!!
        ///   Usually this is done using PBasisSetWriter
        virtual OutType eval(int term, const InType &var)
        {
            undefined("OutType PBasisSet::eval(int term, const InType &var)");
        };
        virtual OutType eval_grad(int term, const InType &var)
        {
            undefined("OutType PBasisSet::eval_grad(int term, const InType &var)");
        };
        virtual OutType eval_hess(int term, const InType &var)
        {
            undefined("OutType PBasisSet::eval_hess(int term, const InType &var)");
        };
    
        void undefined(std::string fname) const
        {
            std::cout << "Error. In PBasisSet '" << _name << "'." << std::endl;
            std::cout << "   The member function '" << fname << "' has not been defined." << std::endl;
            exit(1);
        }
    };
    
    
    /// Should I do a PBasisSet smart pointer class like PFunction?
    
    
    /// This class is for a series function that is the tensor product of indepedent bases
    ///
    ///   Example for order-3 tensor:
    ///
    ///    f(x,y,z) = sum_i sum_j sum_k T_ijk * phix_i(x) * phiy_j(y) * phiz_k(z)
    ///
    ///    summations run from i to _dim[i]
    ///    x, y, z are independent variables (dx/dy = 0, etc.)
    ///
    template< class InType, class OutType, class VarContainer, class IndexContainer>
    class PSeriesFunction : public PBaseFunction<InType, OutType, VarContainer, IndexContainer>
    {
    public:
        using PBaseFunction<InType, OutType, VarContainer, IndexContainer>::_name;
        using PBaseFunction<InType, OutType, VarContainer, IndexContainer>::_var_name;
        
        // tensor info
        std::vector< int > _dim;                        // number of basis functions in each basis set
        std::vector< int > _unroll;                     // used to translate from tensor indices to linear index
        std::vector< OutType > _coeff_tensor;           // unrolled tensor of coefficients (first index is outer loop)
        int _order;                                     // _dim.size()
        int _volume;                                    // _coeff_tensor.size() = product_i(_dim[i]) 
        
        OutType _identity_val;
        OutType _zero_val;
        
        // basis sets
        std::vector< PBasisSet<InType, OutType>* > _basis_set;
        
        // evaluated values
        OutType _val;
        std::vector<OutType> _grad_val;
        std::vector< std::vector< OutType> > _hess_val;
        
        PSeriesFunction(OutType zero, OutType identity)
        {
            _zero_val = zero;
            _identity_val = identity;
        };
        
        PSeriesFunction( OutType zero, OutType identity, const std::vector<PBasisSet<InType,OutType>* > &basis_set) 
        {
            _zero_val = zero;
            _identity_val = identity;

            set(basis_set);
        };
        
        virtual ~PSeriesFunction()
        {
            clear();
        };
        
        void clear()
        {
            for( int i=0; i<_basis_set.size(); i++)
                delete _basis_set[i];
            _basis_set.clear();
            
            _coeff_tensor.clear();
            _dim.clear();
            _unroll.clear();
            _grad_val.clear();
            _hess_val.clear();
            
        }
        
        /// generate the PSeriesFunction, by cloning 'basis_set' and resizing everything to match
        ///
        void set( const std::vector<PBasisSet<InType,OutType>* > &basis_set)
        {
            clear();
            
            _order = basis_set.size();
            _basis_set.resize(basis_set.size());
            
            _dim.resize( _order );
            
            _grad_val.resize( _order );
            _hess_val.resize( _order );
            
            for( int i=0; i<_order; i++)
            {
                _dim[i] = (*basis_set[i]).size();
                _hess_val[i].resize( _order );
                _basis_set[i] = basis_set[i]->clone();
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
            return (*_basis_set[i]).size();
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
                    (*_basis_set[i]).eval_grad(var[i]);
                }
                else
                {
                    (*_basis_set[i]).eval(var[i]);
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
                            (*_basis_set[i]).eval_hess(var[i]);
                    }
                    else
                    {
                        (*_basis_set[i]).eval_grad(var[i]);
                    }
                }
                else
                {
                    (*_basis_set[i]).eval(var[i]);
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
            return (*_basis_set[bindex])(term,var[bindex]);
        };
        virtual OutType basis_grad(int bindex, int term, const VarContainer &var)
        {
            return (*_basis_set[bindex]).grad(term, var[bindex]);
        };
        virtual OutType basis_hess(int bindex, int term, const VarContainer &var)
        {
            return (*_basis_set[bindex]).hess(term, var[bindex]);
        };

        //   or use tensor indices to evaluate basis function product
        virtual OutType basis(const IndexContainer &term, const VarContainer &var)
        {
            // evaluate basis functions needed
            OutType tmp = _identity_val;
            for( int i=0; i<_order; i++)
                tmp *= (*_basis_set[i])(term[i],var[i]);
                
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
                    tmp *= (*_basis_set[i]).grad(term[i], var[i]);
                }
                else
                {
                    tmp *= (*_basis_set[i])(term[i], var[i]);
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
                        tmp *= (*_basis_set[i]).hess(term[i], var[i]);
                    }
                    else
                    {
                        tmp *= (*_basis_set[i]).grad(term[i], var[i]);
                    }
                }
                else
                {
                    tmp *= (*_basis_set[i])(term[i], var[i]);
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
                (*_basis_set[i]).eval(var[i]);
            
        };
        virtual void eval_basis_grad(const VarContainer &var)
        {
            // evaluate basis grad functions
            for( int i=0; i<_order; i++)
                (*_basis_set[i]).eval_grad(var[i]);
        };
        virtual void eval_basis_hess(const VarContainer &var)
        {
            // evaluate basis hess functions
            for( int i=0; i<_order; i++)
                (*_basis_set[i]).eval_hess(var[i]);
        };

        //   use basis index and term index for individual basis function
        virtual OutType basis(int bindex, int term) const
        {
            return (*_basis_set[bindex])(term);
        };
        virtual OutType basis_grad(int bindex, int term, int di) const
        {
            return (*_basis_set[bindex]).grad(term);
        };
        virtual OutType basis_hess(int bindex, int term, int di, int dj) const
        {
            return (*_basis_set[bindex]).hess(term);
        };

        //   or use tensor indices to evaluate basis function product
        virtual OutType basis(const IndexContainer &term) const
        {
            // evaluate basis function product
            OutType tmp = _identity_val;
            for( int i=0; i<_order; i++)
                tmp *= (*_basis_set[i])(term[i]);
                
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
                    tmp *= (*_basis_set[i]).grad(term[i]);
                }
                else
                {
                    tmp *= (*_basis_set[i])(term[i]);
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
                        tmp *= (*_basis_set[i]).hess(term[i]);
                    }
                    else
                    {
                        tmp *= (*_basis_set[i]).grad(term[i]);
                    }
                }
                else
                {
                    tmp *= (*_basis_set[i])(term[i]);
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
                    tmp *= (*_basis_set[j])(tindex[j]);
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
                        tmp *= (*_basis_set[j]).grad(tindex[j]);
                    }
                    else
                    {
                        tmp *= (*_basis_set[j])(tindex[j]);
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
                            tmp *= (*_basis_set[j]).hess(tindex[j]);
                        }
                        else
                        {
                            tmp *= (*_basis_set[j]).grad(tindex[j]);
                        }
                    }
                    else
                    {
                        tmp *= (*_basis_set[j])(tindex[j]);
                    }
                }
                _hess_val[di][dj] += tmp;
            }
            return _hess_val[di][dj];
        }
    };
    

}


#endif