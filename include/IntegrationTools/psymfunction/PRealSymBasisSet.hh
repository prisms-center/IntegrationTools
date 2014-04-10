
#ifndef PRealSymBasisSet_HH
#define PRealSymBasisSet_HH

#include "../pfunction/PBasisSetBase.hh"
#include "./PRealSymBasisFunction.hh"
#include <ginac/ginac.h>    // compile with: -lcln -lginac

namespace PRISMS
{    
    /// Generate PRealSymBasisFunction objects, assuming they can be written in the form:
    ///
    ///   phi_i(x) = f(i, x);
    ///
    ///   For instance, simple polynomials:  phi_i(x) = x^i;
    ///
    class PRealSymBasisSet : public PBasisSetBase<double, double>
    {
        public:
        GiNaC::ex _e;           // expression defining the basis functions = f( _var, _i)
        GiNaC::symbol _var;     // variable
        GiNaC::symbol _i;       // index of basis function
        
        PRealSymBasisSet( int N, const GiNaC::symbol &index, const GiNaC::symbol &var, const GiNaC::ex &e)
        : PBasisSetBase<double,double>(N)
        {
            _e = e;
            _var = var;
            _i = index;
        }
        
        virtual PRealSymBasisSet* clone() const
        {
            return new PRealSymBasisSet(*this);
        }
        
        virtual PRealSymBasisFunction* clone_basis_function( int term) const
        {
            return new PRealSymBasisFunction( _var, _e.subs(_i == term));
        }
        
        virtual PRealSymBasisFunction* clone_grad_basis_function( int term)const
        {
            return new PRealSymBasisFunction( _var, _e.subs(_i == term).diff(_var) );
        }
        
        virtual PRealSymBasisFunction* clone_hess_basis_function( int term)const
        {
            return new PRealSymBasisFunction( _var, _e.subs(_i == term).diff(_var, 2));
        }
        
        private:
        
        // ----------------------------------------------------------
        // Use these functions if you want to evaluate a single value
        virtual double eval(int term, const double &var)
        {
            PRealSymBasisFunction* bf = clone_basis_function(term);
            double result = (*bf)(var);
            delete bf;
            return result;
        }
        virtual double eval_grad(int term, const double &var)
        {
            PRealSymBasisFunction* bf = clone_grad_basis_function(term);
            double result = (*bf)(var);
            delete bf;
            return result;
        }
        virtual double hess(int term, const double &var)
        {
            PRealSymBasisFunction* bf = clone_hess_basis_function(term);
            double result = (*bf)(var);
            delete bf;
            return result;
        }
        
        
    };

}


#endif