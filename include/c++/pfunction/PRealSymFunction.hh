
#ifndef PRealSymFunction_HH
#define PRealSymFunction_HH

#include "PFuncBase.hh"
#include <ginac/ginac.h>    // compile with: -lcln -lginac

namespace PRISMS
{

    /// Real valued symbolic functions

    template<class VarContainer>
    class PRealSymFunction : public PFuncBase<VarContainer, double>
    {
        GiNaC::ex _e;
        std::vector< GiNaC::symbol> _sym;

        double _val;
        std::vector<double> _grad;
        std::vector< std::vector<double> > _hess;

    public:

        // ----------------------------------------------------------
        //   Non-Inherited:

        void set(const std::string &name, const std::vector<GiNaC::symbol> &sym, const GiNaC::ex &e)
        {
            _sym.clear();
            _sym.resize(_sym.size());

            this->_var_name.clear();
            this->_var_name.resize(_sym.size());

            for(int i = 0; i < sym.size(); i++)
            {
                _sym.push_back(sym[i]);
                _sym[i] = sym[i];
                this->_var_name.push_back(_sym[i].get_name());
            }

            this->_name = name;

            _e = e;
        }

        // ----------------------------------------------------------
        //   Inherited:

        virtual PRealSymFunction<VarContainer> *clone() const
        {
            return new PRealSymFunction<VarContainer>(*this);
        }

        // ----------------------------------------------------------
        // Use these functions if you want to evaluate a single value
        double operator()(const VarContainer &var);
        double grad(const VarContainer &var, int di);
        double hess(const VarContainer &var, int di, int dj);

    };
    
    

    template<class VarContainer>
    double PRealSymFunction<VarContainer>::operator()(const VarContainer &var)
    {
        GiNaC::exmap m;
        for(int i = 0; i < var.size(); i++)
            m[_sym[i]] = var[i];
        
        return GiNaC::ex_to<GiNaC::numeric>(GiNaC::evalf(_e.subs(m))).to_double();
    }


    template<class VarContainer>
    double PRealSymFunction<VarContainer>::grad(const VarContainer &var, int di)
    {
        GiNaC::ex de = _e.diff(_sym[di]);

        GiNaC::exmap m;
        for(int i = 0; i < var.size(); i++)
            m[_sym[i]] = var[i];
        
        return GiNaC::ex_to<GiNaC::numeric>(GiNaC::evalf(de.subs(m))).to_double();
    }

    template<class VarContainer>
    double PRealSymFunction<VarContainer>::hess(const VarContainer &var, int di, int dj)
    {
        GiNaC::ex de = _e.diff(_sym[di]).diff(_sym[dj]);

        GiNaC::exmap m;
        for(int i = 0; i < var.size(); i++)
            m[_sym[i]] = var[i];
        
        return GiNaC::ex_to<GiNaC::numeric>(GiNaC::evalf(de.subs(m))).to_double();
    }

}


#endif