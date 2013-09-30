
#ifndef POLY_HH
#define POLY_HH

#include "PFunction.hh"

namespace PRISMS
{

    /// Base classes for functions that can be hard-coded,
    ///   then shared and used elsewhere

    template< template<class> class Container>
    class Quadratic : public PBaseFunction< Container, double, double>
    {
    public:

        using PBaseFunction< Container, double, double>::_name;
        using PBaseFunction< Container, double, double>::_var_name;

        double a;
        double b;
        double c;

        double val;
        double grad_val;
        double hess_val;

        Quadratic()
        {
            _name = "Quadratic";
            _var_name.push_back("x");

            a = 1.0;
            b = 1.0;
            c = 1.0;
        };

        virtual Quadratic<Container> *clone() const
        {
            return new Quadratic<Container>(*this);
        };

        // ----------------------------------------------------------
        // Use these functions if you want to evaluate a single value
        virtual double operator()(const Container<double> &var) const
        {
            return a + b * var[0] + c * var[0] * var[0];
        };
        virtual double grad(const Container<double> &var, int di) const
        {
            return b + 2.0 * c * var[0];
        };
        virtual double hess(const Container<double> &var, int di, int dj) const
        {
            return 2.0 * c;
        };

        // ----------------------------------------------------------
        // Use these functions to evaluate several values, then use 'get' methods to access results
        virtual void eval(const Container<double> &var)
        {
            val = a + b * var[0] + c * var[0] * var[0];
        };
        virtual void eval_grad(const Container<double> &var)
        {
            grad_val = b * var[0] + 2.0 * c * var[0];
        };
        virtual void eval_hess(const Container<double> &var)
        {
            hess_val = 2.0 * c;
        };

        virtual double operator()() const
        {
            return val;
        };
        virtual double grad(int di) const
        {
            return grad_val;
        };
        virtual double hess(int di, int dj) const
        {
            return hess_val;
        };


        // Functions for evaluating basis functions & their derivatives:

        // ----------------------------------------------------------
        // Use these functions if you want to evaluate a single value

        //   use unrolled index
        //virtual double basis(int term, const Container<double> &var) const {undefined("double basis(int term, const Container<double> &var)");};
        //virtual double basis_grad(int term, const Container<double> &var, int di) const {undefined("double basis_grad(int term, const Container<double> &var, int di)");};
        //virtual double basis_hess(int term, const Container<double> &var, int di, int dj) const {undefined("double basis_hess(int term, const Container<double> &var, int di, int dj)");};

        //   or use tensor indices
        //virtual double basis(const Container<int> &term, const Container<double> &var) const {undefined("double basis(const Container<int> &term, const Container<double> &var)");};
        //virtual double basis_grad(const Container<int> &term, const Container<double> &var, int di) const {undefined("double basis_grad(const Container<int> &term, const Container<double> &var, int di)");};
        //virtual double basis_hess(const Container<int> &term, const Container<double> &var, int di, int dj) const {undefined("double basis_hess(const Container<int> &term, const Container<double> &var, int di, int dj)");};

        // ----------------------------------------------------------
        // Use these functions to evaluate all basis functions,
        //   then use 'get' methods to access results.

        //virtual void eval_basis( const Container<double> &var) {undefined("void eval_basis( const Container<double> &var)");};
        //virtual void eval_basis_grad( const Container<double> &var) {undefined("void eval_basis_grad( const Container<double> &var)");};
        //virtual void eval_basis_hess( const Container<double> &var) {undefined("void eval_basis_hess( const Container<double> &var)");};

        //   use unrolled index
        //virtual double basis(int term) const {undefined("double basis(int term)");};
        //virtual double basis_grad(int term, int di) const {undefined("double basis_grad(int term, int di)");};
        //virtual double basis_hess(int term, int di, int dj) const {undefined("double basis_hess(int term, int di, int dj)");};

        //   or use tensor indices
        //virtual double basis(const Container<int> &term) const {undefined("double basis(const Container<int> &term)");};
        //virtual double basis_grad(const Container<int> &term, int di) const {undefined("double basis_grad(const Container<int> &term, int di)");};
        //virtual double basis_hess(const Container<int> &term, int di, int dj) const {undefined("double basis_hess(const Container<int> &term, int di, int dj)");};



    };




    template< template<class> class Container>
    class Cubic : public PBaseFunction< Container, double, double>
    {
    public:

        using PBaseFunction< Container, double, double>::_name;
        using PBaseFunction< Container, double, double>::_var_name;

        double a;
        double b;
        double c;
        double d;

        double val;
        double grad_val;
        double hess_val;

        Cubic()
        {
            _name = "Cubic";
            _var_name.push_back("x");

            a = 1.0;
            b = 1.0;
            c = 1.0;
            d = 1.0;
        };

        virtual Cubic<Container> *clone() const
        {
            return new Cubic<Container>(*this);
        };

        // ----------------------------------------------------------
        // Use these functions if you want to evaluate a single value
        virtual double operator()(const Container<double> &var) const
        {
            return a + b * var[0] + c * var[0] * var[0] + d * var[0] * var[0] * var[0];
        };
        virtual double grad(const Container<double> &var, int di) const
        {
            return b + 2.0 * c * var[0] + 3.0 * d * var[0] * var[0];
        };
        virtual double hess(const Container<double> &var, int di, int dj) const
        {
            return 2.0 * c + 6.0 * d * var[0];
        };

        // ----------------------------------------------------------
        // Use these functions to evaluate several values, then use 'get' methods to access results
        virtual void eval(const Container<double> &var)
        {
            val = a + b * var[0] + c * var[0] * var[0] + d * var[0] * var[0] * var[0];
        };
        virtual void eval_grad(const Container<double> &var)
        {
            grad_val = b + 2.0 * c * var[0] + 3.0 * d * var[0] * var[0];
        };
        virtual void eval_hess(const Container<double> &var)
        {
            hess_val = 2.0 * c + 6.0 * d * var[0];
        };

        virtual double operator()() const
        {
            return val;
        };
        virtual double grad(int di) const
        {
            return grad_val;
        };
        virtual double hess(int di, int dj) const
        {
            return hess_val;
        };


        // Functions for evaluating basis functions & their derivatives:

        // ----------------------------------------------------------
        // Use these functions if you want to evaluate a single value

        //   use unrolled index
        //virtual double basis(int term, const Container<double> &var) const {undefined("double basis(int term, const Container<double> &var)");};
        //virtual double basis_grad(int term, const Container<double> &var, int di) const {undefined("double basis_grad(int term, const Container<double> &var, int di)");};
        //virtual double basis_hess(int term, const Container<double> &var, int di, int dj) const {undefined("double basis_hess(int term, const Container<double> &var, int di, int dj)");};

        //   or use tensor indices
        //virtual double basis(const Container<int> &term, const Container<double> &var) const {undefined("double basis(const Container<int> &term, const Container<double> &var)");};
        //virtual double basis_grad(const Container<int> &term, const Container<double> &var, int di) const {undefined("double basis_grad(const Container<int> &term, const Container<double> &var, int di)");};
        //virtual double basis_hess(const Container<int> &term, const Container<double> &var, int di, int dj) const {undefined("double basis_hess(const Container<int> &term, const Container<double> &var, int di, int dj)");};

        // ----------------------------------------------------------
        // Use these functions to evaluate all basis functions,
        //   then use 'get' methods to access results.

        //virtual void eval_basis( const Container<double> &var) {undefined("void eval_basis( const Container<double> &var)");};
        //virtual void eval_basis_grad( const Container<double> &var) {undefined("void eval_basis_grad( const Container<double> &var)");};
        //virtual void eval_basis_hess( const Container<double> &var) {undefined("void eval_basis_hess( const Container<double> &var)");};

        //   use unrolled index
        //virtual double basis(int term) const {undefined("double basis(int term)");};
        //virtual double basis_grad(int term, int di) const {undefined("double basis_grad(int term, int di)");};
        //virtual double basis_hess(int term, int di, int dj) const {undefined("double basis_hess(int term, int di, int dj)");};

        //   or use tensor indices
        //virtual double basis(const Container<int> &term) const {undefined("double basis(const Container<int> &term)");};
        //virtual double basis_grad(const Container<int> &term, int di) const {undefined("double basis_grad(const Container<int> &term, int di)");};
        //virtual double basis_hess(const Container<int> &term, int di, int dj) const {undefined("double basis_hess(const Container<int> &term, int di, int dj)");};



    };

}


#endif