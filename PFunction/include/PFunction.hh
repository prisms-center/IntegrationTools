
#ifndef PFUNCTION_HH
#define PFUNCTION_HH

#include<cstring>
#include<iostream>
#include<vector>

namespace PRISMS
{

    /// Base classes for functions that can be hard-coded,
    ///   then shared and used elsewhere

    template< template<class> class Container, class InType, class OutType>
    class PBaseFunction
    {
    public:

        std::string _name;
        std::vector<std::string> _var_name;

        std::string name()
        {
            return _name;
        };
        std::string var_name(int i)
        {
            return _var_name[i];
        };

        void is_derived_from_PBaseFunction() const
        {
            return;
        };

        virtual PBaseFunction<Container, InType, OutType> *clone() const
        {
            return new PBaseFunction<Container, InType, OutType>(*this);
        };

        // ----------------------------------------------------------
        // Use these functions if you want to evaluate a single value
        virtual OutType operator()(const Container<InType> &var) const
        {
            undefined("OutType operator()(const Container<InType> &var)");
        };
        virtual OutType grad(const Container<InType> &var, int di) const
        {
            undefined("OutType grad(const Container<InType> &var, int di)");
        };
        virtual OutType hess(const Container<InType> &var, int di, int dj) const
        {
            undefined("OutType hess(const Container<InType> &var, int di, int dj)");
        };

        // ----------------------------------------------------------
        // Use these functions to evaluate several values, then use 'get' methods to access results
        virtual void eval(const Container<InType> &var)
        {
            undefined("void eval()(const Container<InType> &var)");
        };
        virtual void eval_grad(const Container<InType> &var)
        {
            undefined("void eval_grad( const Container<InType> &var)");
        };
        virtual void eval_hess(const Container<InType> &var)
        {
            undefined("void eval_hess( const Container<InType> &var)");
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

        //   use unrolled index
        virtual OutType basis(int term, const Container<InType> &var) const
        {
            undefined("OutType basis(int term, const Container<InType> &var)");
        };
        virtual OutType basis_grad(int term, const Container<InType> &var, int di) const
        {
            undefined("OutType basis_grad(int term, const Container<InType> &var, int di)");
        };
        virtual OutType basis_hess(int term, const Container<InType> &var, int di, int dj) const
        {
            undefined("OutType basis_hess(int term, const Container<InType> &var, int di, int dj)");
        };

        //   or use tensor indices
        virtual OutType basis(const Container<int> &term, const Container<InType> &var) const
        {
            undefined("OutType basis(const Container<int> &term, const Container<InType> &var)");
        };
        virtual OutType basis_grad(const Container<int> &term, const Container<InType> &var, int di) const
        {
            undefined("OutType basis_grad(const Container<int> &term, const Container<InType> &var, int di)");
        };
        virtual OutType basis_hess(const Container<int> &term, const Container<InType> &var, int di, int dj) const
        {
            undefined("OutType basis_hess(const Container<int> &term, const Container<InType> &var, int di, int dj)");
        };

        // ----------------------------------------------------------
        // Use these functions to evaluate all basis functions,
        //   then use 'get' methods to access results.

        virtual void eval_basis(const Container<InType> &var)
        {
            undefined("void eval_basis( const Container<InType> &var)");
        };
        virtual void eval_basis_grad(const Container<InType> &var)
        {
            undefined("void eval_basis_grad( const Container<InType> &var)");
        };
        virtual void eval_basis_hess(const Container<InType> &var)
        {
            undefined("void eval_basis_hess( const Container<InType> &var)");
        };

        //   use unrolled index
        virtual OutType basis(int term) const
        {
            undefined("OutType basis(int term)");
        };
        virtual OutType basis_grad(int term, int di) const
        {
            undefined("OutType basis_grad(int term, int di)");
        };
        virtual OutType basis_hess(int term, int di, int dj) const
        {
            undefined("OutType basis_hess(int term, int di, int dj)");
        };

        //   or use tensor indices
        virtual OutType basis(const Container<int> &term) const
        {
            undefined("OutType basis(const Container<int> &term)");
        };
        virtual OutType basis_grad(const Container<int> &term, int di) const
        {
            undefined("OutType basis_grad(const Container<int> &term, int di)");
        };
        virtual OutType basis_hess(const Container<int> &term, int di, int dj) const
        {
            undefined("OutType basis_hess(const Container<int> &term, int di, int dj)");
        };

    private:
        void undefined(std::string fname) const
        {
            std::cout << "Error. In PBaseFunction '" << _name << "'." << std::endl;
            std::cout << "   The member function '" << fname << "' has not been defined." << std::endl;
            exit(1);
        }

    };




    template< template<class> class Container, class InType, class OutType>
    class PFunction : public PBaseFunction<Container, InType, OutType>
    {
    public:

        virtual std::string name() const
        {
            return (*ptr).name();
        };

        // ----------------------------------------------------------
        // Use these functions if you want to evaluate a single value
        OutType operator()(const Container<InType> &var) const
        {
            return (*ptr)(var);
        };
        OutType grad(const Container<InType> &var, int di) const
        {
            return (*ptr).grad(var, di);
        };
        OutType hess(const Container<InType> &var, int di, int dj) const
        {
            return (*ptr).hess(var, di, dj);
        };

        // ----------------------------------------------------------
        // Use these functions to evaluate several values, then use 'get' methods to access results
        void eval(const Container<InType> &var)
        {
            return (*ptr).eval(var);
        };
        void eval_grad(const Container<InType> &var)
        {
            return (*ptr).eval_grad(var);
        };
        void eval_hess(const Container<InType> &var)
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
        virtual OutType basis(int term, const Container<InType> &var) const
        {
            return (*ptr).basis(term, var);
        };
        virtual OutType basis_grad(int term, const Container<InType> &var, int di) const
        {
            return (*ptr).basis_grad(term, var, di);
        };
        virtual OutType basis_hess(int term, const Container<InType> &var, int di, int dj) const
        {
            return (*ptr).basis_hess(term, var, di, dj);
        };

        //   or use tensor indices
        virtual OutType basis(const Container<int> &term, const Container<InType> &var) const
        {
            return (*ptr).basis(term, var);
        };
        virtual OutType basis_grad(const Container<int> &term, const Container<InType> &var, int di) const
        {
            return (*ptr).basis_grad(term, var, di);
        };
        virtual OutType basis_hess(const Container<int> &term, const Container<InType> &var, int di, int dj) const
        {
            return (*ptr).basis_hess(term, var, di, dj);
        };

        // ----------------------------------------------------------
        // Use these functions to evaluate all basis functions,
        //   then use 'get' methods to access results.

        virtual void eval_basis(const Container<InType> &var)
        {
            (*ptr).eval_basis(var);
        };
        virtual void eval_basis_grad(const Container<InType> &var)
        {
            (*ptr).eval_basis_grad(var);
        };
        virtual void eval_basis_hess(const Container<InType> &var)
        {
            (*ptr).eval_basis_hess(var);
        };

        //   use unrolled index
        virtual OutType basis(int term) const
        {
            return (*ptr).basis(term);
        };
        virtual OutType basis_grad(int term, int di) const
        {
            return (*ptr).basis_grad(term, di);
        };
        virtual OutType basis_hess(int term, int di, int dj) const
        {
            return (*ptr).basis_hess(term, di, dj);
        };

        //   or use tensor indices
        virtual OutType basis(const Container<int> &term) const
        {
            return (*ptr).basis(term);
        };
        virtual OutType basis_grad(const Container<int> &term, int di) const
        {
            return (*ptr).basis_grad(term, di);
        };
        virtual OutType basis_hess(const Container<int> &term, int di, int dj) const
        {
            return (*ptr).basis_hess(term, di, dj);
        };


        // PFunction unique members ------------------------------------------

        PBaseFunction<Container, InType, OutType> *clone() const
        {
            return new PBaseFunction<Container, InType, OutType>(*ptr);
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

        PFunction &set(const PBaseFunction<Container, InType, OutType> *RHS)
        {
            if(ptr != NULL)
                delete ptr;
            ptr = RHS->clone();
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
        PBaseFunction<Container, InType, OutType> *ptr;

    };

}


#endif