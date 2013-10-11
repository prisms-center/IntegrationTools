
#ifndef PFUNCTION_HH
#define PFUNCTION_HH

#include<cstring>
#include<iostream>
#include<vector>

namespace PRISMS
{

    /// Base classes for functions that can be hard-coded,
    ///   then shared and used elsewhere
    
    /// A simple expression evaluator
    ///
    template< class VarContainer, class OutType>
    class PSimpleFunction
    {
        public:
        OutType _val;
        
        OutType operator()( const VarContainer &var){ return _val = eval(var);};
        OutType operator()() const { return _val;};
        
        private:
        virtual OutType eval( const VarContainer &var) const { undefined("OutType eval( const InType &var)");};
        
        void undefined(std::string fname) const
        {
            std::cout << "Error. In PSimpleFunction." << std::endl;
            std::cout << "   The member function '" << fname << "' has not been defined." << std::endl;
            exit(1);
        }
    };
    

    
    /// A Base class for a function, including grad & hess & basis sets
    ///
    template< class InType, class OutType, class VarContainer, class IndexContainer>
    class PBaseFunction
    {
    public:

        std::string _name;
        std::vector<std::string> _var_name;
        std::vector<std::string> _var_description;
        
        virtual ~PBaseFunction(){};

        std::string name()
        {
            return _name;
        };
        std::string var_name(int i)
        {
            return _var_name[i];
        };
        std::string var_description(int i)
        {
            return _var_description[i];
        };

        void is_derived_from_PBaseFunction() const
        {
            return;
        };

        virtual PBaseFunction<InType, OutType, VarContainer, IndexContainer> *clone() const
        {
            return new PBaseFunction<InType, OutType, VarContainer, IndexContainer>(*this);
        };

        // ----------------------------------------------------------
        // Use these functions if you want to evaluate a single value
        virtual OutType operator()(const VarContainer &var)
        {
            undefined("OutType operator()(const VarContainer &var)");
        };
        virtual OutType grad(const VarContainer &var, int di)
        {
            undefined("OutType grad(const VarContainer &var, int di)");
        };
        virtual OutType hess(const VarContainer &var, int di, int dj)
        {
            undefined("OutType hess(const VarContainer &var, int di, int dj)");
        };

        // ----------------------------------------------------------
        // Use these functions to evaluate several values, then use 'get' methods to access results
        virtual void eval(const VarContainer &var)
        {
            undefined("void eval()(const VarContainer &var)");
        };
        virtual void eval_grad(const VarContainer &var)
        {
            undefined("void eval_grad( const VarContainer &var)");
        };
        virtual void eval_hess(const VarContainer &var)
        {
            undefined("void eval_hess( const VarContainer &var)");
        };

        virtual OutType operator()() const
        {
            undefined("OutType operator()");
        };
        virtual OutType grad(int di) const
        {
            undefined("OutType grad(int di)");
        };
        virtual OutType hess(int di, int dj) const
        {
            undefined("OutType hess(int di, int dj)");
        };


        // Functions for evaluating basis functions & their derivatives:

        // ----------------------------------------------------------
        // Use these functions if you want to evaluate a single value

        //   use basis index and term index for individual basis function
        virtual OutType basis(int bindex, int term, const VarContainer &var)
        {
            undefined("OutType basis(int bindex, int term, const VarContainer &var)");
        };
        virtual OutType basis_grad(int bindex, int term, const VarContainer &var, int di)
        {
            undefined("OutType basis_grad(int bindex, int term, const VarContainer &var, int di)");
        };
        virtual OutType basis_hess(int bindex, int term, const VarContainer &var, int di, int dj)
        {
            undefined("OutType basis_hess(int bindex, int term, const VarContainer &var, int di, int dj)");
        };

        //   or use tensor indices to evaluate basis function product
        virtual OutType basis(const IndexContainer &term, const VarContainer &var)
        {
            undefined("OutType basis(const IndexContainer &term, const VarContainer &var)");
        };
        virtual OutType basis_grad(const IndexContainer &term, const VarContainer &var, int di)
        {
            undefined("OutType basis_grad(const IndexContainer &term, const VarContainer &var, int di)");
        };
        virtual OutType basis_hess(const IndexContainer &term, const VarContainer &var, int di, int dj)
        {
            undefined("OutType basis_hess(const IndexContainer &term, const VarContainer &var, int di, int dj)");
        };

        // ----------------------------------------------------------
        // Use these functions to evaluate all basis functions,
        //   then use 'get' methods to access results.

        virtual void eval_basis(const VarContainer &var)
        {
            undefined("void eval_basis( const VarContainer &var)");
        };
        virtual void eval_basis_grad(const VarContainer &var)
        {
            undefined("void eval_basis_grad( const VarContainer &var)");
        };
        virtual void eval_basis_hess(const VarContainer &var)
        {
            undefined("void eval_basis_hess( const VarContainer &var)");
        };

        //   use basis index and term index for individual basis function
        virtual OutType basis(int bindex, int term) const
        {
            undefined("OutType basis(int bindex, int term)");
        };
        virtual OutType basis_grad(int bindex, int term, int di) const
        {
            undefined("OutType basis_grad(int bindex, int term, int di)");
        };
        virtual OutType basis_hess(int bindex, int term, int di, int dj) const
        {
            undefined("OutType basis_hess(int bindex, int term, int di, int dj)");
        };

        //   or use tensor indices to evaluate basis function product
        virtual OutType basis(const IndexContainer &term) const
        {
            undefined("OutType basis(const IndexContainer &term)");
        };
        virtual OutType basis_grad(const IndexContainer &term, int di) const
        {
            undefined("OutType basis_grad(const IndexContainer &term, int di)");
        };
        virtual OutType basis_hess(const IndexContainer &term, int di, int dj) const
        {
            undefined("OutType basis_hess(const IndexContainer &term, int di, int dj)");
        };

    private:
        void undefined(std::string fname) const
        {
            std::cout << "Error. In PBaseFunction '" << _name << "'." << std::endl;
            std::cout << "   The member function '" << fname << "' has not been defined." << std::endl;
            exit(1);
        }

    };
    
    /// A class that contains a ptr to a PBaseFunction
    ///   - essentially a smart ptr class
    ///   - same interface as PBaseFunction
    ///   - allows for using PBaseFunctions polymorphically 
    ///     without dereferencing and without worrying about new/delete
    ///    
    ///   example: MyFuncA, MyFuncB, MyFuncC, etc. are defined:
    ///     template< class VarContainer, class IndexContainer>
    ///     MyFuncX : public PBaseFunction<double, double, VarContainer, IndexContainer>
    ///
    ///   // Then you can do things like this:
    ///   
    ///   MyFuncA<std::vector<double>, std::vector<int> > my_func_a;
    ///   MyFuncB<std::vector<double>, std::vector<int> > my_func_b;
    ///
    ///   PBaseFunction<double, double, std::vector<double>, std::vector<int> >* my_func_c_ptr;
    ///   my_func_c_ptr = new MyFuncC<std::vector<double>, std::vector<int> >();
    ///
    ///   PFunction<double, double, std::vector<double>, std::vector<int> > f, g, h;
    ///
    ///   f = my_func_a;
    ///   f = my_func_b;
    ///   g.set(my_func_c_ptr->clone());
    ///   h.set(my_func_c_ptr);
    ///   double result = f(3.0) + g(4.0) + h(5.0);
    ///   
    ///   - No deletions are used in this example.  
    ///     PFunction::set makes PFunction the 'owner' of the MyFuncC object and it will delete it.
    ///
    template< class InType, class OutType, class VarContainer, class IndexContainer>
    class PFunction 
    {
    public:

        std::string name() const
        {
            return (*ptr).name();
        };
        std::string var_name(int i)
        {
            return (*ptr).var_name(i);
        };
        std::string var_description(int i)
        {
            return (*ptr).var_description(i);
        };

        // ----------------------------------------------------------
        // Use these functions if you want to evaluate a single value
        OutType operator()(const VarContainer &var)
        {
            return (*ptr)(var);
        };
        OutType grad(const VarContainer &var, int di)
        {
            return (*ptr).grad(var, di);
        };
        OutType hess(const VarContainer &var, int di, int dj)
        {
            return (*ptr).hess(var, di, dj);
        };

        // ----------------------------------------------------------
        // Use these functions to evaluate several values, then use 'get' methods to access results
        void eval(const VarContainer &var)
        {
            return (*ptr).eval(var);
        };
        void eval_grad(const VarContainer &var)
        {
            return (*ptr).eval_grad(var);
        };
        void eval_hess(const VarContainer &var)
        {
            return (*ptr).eval_hess(var);
        };

        OutType operator()() const
        {
            return (*ptr)();
        };
        OutType grad(int di) const
        {
            return (*ptr).grad(di);
        };
        OutType hess(int di, int dj) const
        {
            return (*ptr).hess(di, dj);
        };



        // Functions for evaluating basis functions & their derivatives:

        // ----------------------------------------------------------
        // Use these functions if you want to evaluate a single value

        //   use unrolled index
        virtual OutType basis(int bindex, int term, const VarContainer &var)
        {
            return (*ptr).basis(bindex, term, var);
        };
        virtual OutType basis_grad(int bindex, int term, const VarContainer &var, int di)
        {
            return (*ptr).basis_grad(bindex, term, var, di);
        };
        virtual OutType basis_hess(int bindex, int term, const VarContainer &var, int di, int dj)
        {
            return (*ptr).basis_hess(bindex, term, var, di, dj);
        };

        //   or use tensor indices
        virtual OutType basis(const IndexContainer &term, const VarContainer &var)
        {
            return (*ptr).basis(term, var);
        };
        virtual OutType basis_grad(const IndexContainer &term, const VarContainer &var, int di)
        {
            return (*ptr).basis_grad(term, var, di);
        };
        virtual OutType basis_hess(const IndexContainer &term, const VarContainer &var, int di, int dj)
        {
            return (*ptr).basis_hess(term, var, di, dj);
        };

        // ----------------------------------------------------------
        // Use these functions to evaluate all basis functions,
        //   then use 'get' methods to access results.

        virtual void eval_basis(const VarContainer &var)
        {
            (*ptr).eval_basis(var);
        };
        virtual void eval_basis_grad(const VarContainer &var)
        {
            (*ptr).eval_basis_grad(var);
        };
        virtual void eval_basis_hess(const VarContainer &var)
        {
            (*ptr).eval_basis_hess(var);
        };

        //   use unrolled index
        virtual OutType basis(int bindex, int term) const
        {
            return (*ptr).basis(bindex, term);
        };
        virtual OutType basis_grad(int bindex, int term, int di) const
        {
            return (*ptr).basis_grad(bindex, term, di);
        };
        virtual OutType basis_hess(int bindex, int term, int di, int dj) const
        {
            return (*ptr).basis_hess(bindex, term, di, dj);
        };

        //   or use tensor indices
        virtual OutType basis(const IndexContainer &term) const
        {
            return (*ptr).basis(term);
        };
        virtual OutType basis_grad(const IndexContainer &term, int di) const
        {
            return (*ptr).basis_grad(term, di);
        };
        virtual OutType basis_hess(const IndexContainer &term, int di, int dj) const
        {
            return (*ptr).basis_hess(term, di, dj);
        };


        // PFunction unique members ------------------------------------------

        PBaseFunction<InType, OutType, VarContainer, IndexContainer> *clone() const
        {
            return new PBaseFunction<InType, OutType, VarContainer, IndexContainer>(*ptr);
        };

        PFunction &operator=(const PFunction &RHS)
        {
            if(ptr != NULL)
                delete ptr;
            ptr = RHS.clone();
            return *this;
        }

        template<class T> PFunction &operator=(const T &RHS)
        {
            RHS.is_derived_from_PBaseFunction();

            if(ptr != NULL)
                delete ptr;
            ptr = RHS.clone();
            return *this;
        }

        // If you use this, PFunction becomes the 'owner' of the function RHS points to
        //    and it will delete it
        PFunction &set( PBaseFunction<InType, OutType, VarContainer, IndexContainer> *RHS)
        {
            if(RHS == NULL)
            {
                std::cout << "Error in PFunction::set. RHS == NULL." << std::endl;
                exit(1);
            }
            if(ptr != NULL)
                delete ptr;
            ptr = RHS;
            return *this;
        }

        PFunction()
        {
            ptr = NULL;
        }

        PFunction(const PFunction &RHS)
        {
            if(ptr != NULL)
                delete ptr;
            ptr = RHS.clone();
        }

        ~PFunction()
        {
            if(ptr != NULL)
                delete ptr;
        };

    private:
        PBaseFunction<InType, OutType, VarContainer, IndexContainer> *ptr;

    };

}


#endif