
#ifndef POLY_HH
#define POLY_HH

#include "PFunction.hh"

namespace PRISMS
{

    /// Base classes for functions that can be hard-coded,
    ///   then shared and used elsewhere

    template<class VarContainer>
    class Quadratic : public PFuncBase<VarContainer, double>
    {
    public:

        using PFuncBase<VarContainer, double>::_name;
        using PFuncBase<VarContainer, double>::_var_name;

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

        virtual Quadratic<VarContainer> *clone() const
        {
            return new Quadratic<VarContainer>(*this);
        };

        // ----------------------------------------------------------
        // Use these functions if you want to evaluate a single value
        virtual double operator()(const VarContainer &var)
        {
            return a + b * var[0] + c * var[0] * var[0];
        };
        virtual double grad(const VarContainer &var, int di)
        {
            return b + 2.0 * c * var[0];
        };
        virtual double hess(const VarContainer &var, int di, int dj)
        {
            return 2.0 * c;
        };

        // ----------------------------------------------------------
        // Use these functions to evaluate several values, then use 'get' methods to access results
        virtual void eval(const VarContainer &var)
        {
            val = a + b * var[0] + c * var[0] * var[0];
        };
        virtual void eval_grad(const VarContainer &var)
        {
            grad_val = b * var[0] + 2.0 * c * var[0];
        };
        virtual void eval_hess(const VarContainer &var)
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

    };




    template<class VarContainer>
    class Cubic : public PFuncBase<VarContainer, double>
    {
    public:

        using PFuncBase<VarContainer, double>::_name;
        using PFuncBase<VarContainer, double>::_var_name;

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

        virtual Cubic<VarContainer> *clone() const
        {
            return new Cubic<VarContainer>(*this);
        };

        // ----------------------------------------------------------
        // Use these functions if you want to evaluate a single value
        virtual double operator()(const VarContainer &var) 
        {
            return a + b * var[0] + c * var[0] * var[0] + d * var[0] * var[0] * var[0];
        };
        virtual double grad(const VarContainer &var, int di) 
        {
            return b + 2.0 * c * var[0] + 3.0 * d * var[0] * var[0];
        };
        virtual double hess(const VarContainer &var, int di, int dj) 
        {
            return 2.0 * c + 6.0 * d * var[0];
        };

        // ----------------------------------------------------------
        // Use these functions to evaluate several values, then use 'get' methods to access results
        virtual void eval(const VarContainer &var)
        {
            val = a + b * var[0] + c * var[0] * var[0] + d * var[0] * var[0] * var[0];
        };
        virtual void eval_grad(const VarContainer &var)
        {
            grad_val = b + 2.0 * c * var[0] + 3.0 * d * var[0] * var[0];
        };
        virtual void eval_hess(const VarContainer &var)
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


    };

}


#endif