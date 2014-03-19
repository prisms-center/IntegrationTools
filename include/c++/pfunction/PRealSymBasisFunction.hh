
#ifndef PRealSymBasisFunction_HH
#define PRealSymBasisFunction_HH

#include "PSimpleBase.hh"
#include <ginac/ginac.h>    // compile with: -lcln -lginac

namespace PRISMS
{
    
    class PRealSymBasisFunction : public PSimpleBase<double, double>
    {
        public:
        GiNaC::ex _e;
        GiNaC::symbol _var;
        
        PRealSymBasisFunction( GiNaC::symbol var, GiNaC::ex e)
        {
            _var = var;
            _e = e;
        }
        
        private:
        virtual double eval( const double &var) const
        { 
            return GiNaC::ex_to<GiNaC::numeric>(GiNaC::evalf(_e.subs(_var == var))).to_double();
        }
        
        
    };

}


#endif