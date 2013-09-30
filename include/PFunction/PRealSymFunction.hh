
#ifndef PRealSymFunction_HH
#define PRealSymFunction_HH

#include "PFunction.hh"
#include <ginac/ginac.h>    // compile with: -lcln -lginac

namespace PRISMS
{

    /// Real valued symbolic functions

    template<class VarContainer, class IndexContainer>
    class PRealSymFunction : public PBaseFunction<double, double, VarContainer, IndexContainer>
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

            _var_name.clear();
            _var_name.resize(_sym.size());

            for(int i = 0; i < sym.size(); i++)
            {
                _sym.push_back(sym[i]);
                _sym[i] = sym[i];
                _var_name.push_back(_sym[i].get_name());
                std::cout << "PRealSymFunction::sym i: " << i << "  sym: " << _sym[i] << "  _var_name: " << _var_name[i] << std::endl;

            }

            _name = name;

            _e = e;
        }


        // ----------------------------------------------------------
        //   Inherited:

        using PBaseFunction<double, double, VarContainer, IndexContainer>::_name;
        using PBaseFunction<double, double, VarContainer, IndexContainer>::_var_name;

        virtual PRealSymFunction<VarContainer, IndexContainer> *clone() const
        {
            return new PRealSymFunction<VarContainer, IndexContainer>(*this);
        };

        // ----------------------------------------------------------
        // Use these functions if you want to evaluate a single value
        double operator()(const VarContainer &var) const;
        double grad(const VarContainer &var, int di) const;
        double hess(const VarContainer &var, int di, int dj) const;

        // ----------------------------------------------------------
        // Use these functions to evaluate several values, then use 'get' methods to access results
        //virtual void eval(const VarContainer &var);
        //virtual void eval_grad( const VarContainer &var);
        //virtual void eval_hess( const VarContainer &var);

        //virtual double operator()() const;
        //virtual double grad(int di) const;
        //virtual double hess(int di, int dj) const;

    };

    template<class VarContainer, class IndexContainer>
    double PRealSymFunction<VarContainer, IndexContainer>::operator()(const VarContainer &var) const
    {
        GiNaC::exmap m;
        for(int i = 0; i < var.size(); i++)
        {
            std::cout << "i: " << var[i] << "  " << _sym[i] << std::endl;
            m[_sym[i]] = var[i];
        }

        std::cout << m << std::endl;
        std::cout << _e.subs(m) << std::endl;

        return GiNaC::ex_to<GiNaC::numeric>(GiNaC::evalf(_e.subs(m))).to_double() ;
    }


    template<class VarContainer, class IndexContainer>
    double PRealSymFunction<VarContainer, IndexContainer>::grad(const VarContainer &var, int di) const
    {
        GiNaC::ex de = _e.diff(_sym[di]);

        GiNaC::exmap m;
        for(int i = 0; i < var.size(); i++)
        {
            std::cout << "i: " << var[i] << "  " << _sym[i] << std::endl;
            m[_sym[i]] = var[i];
        }
        std::cout << m << std::endl;
        std::cout << "de: " << de << " :: " << de.subs(m) << std::endl;

        return GiNaC::ex_to<GiNaC::numeric>(GiNaC::evalf(de.subs(m))).to_double();
    };

    template<class VarContainer, class IndexContainer>
    double PRealSymFunction<VarContainer, IndexContainer>::hess(const VarContainer &var, int di, int dj) const
    {
        GiNaC::ex de = _e.diff(_sym[di]).diff(_sym[dj]);

        GiNaC::exmap m;
        for(int i = 0; i < var.size(); i++)
        {
            std::cout << "i: " << var[i] << "  " << _sym[i] << std::endl;
            m[_sym[i]] = var[i];
        }
        std::cout << m << std::endl;
        std::cout << "de: " << de << " :: " << de.subs(m) << std::endl;

        return GiNaC::ex_to<GiNaC::numeric>(GiNaC::evalf(de.subs(m))).to_double();
    };

    // ----------------------------------------------------------
    // Use these functions to evaluate several values, then use 'get' methods to access results
    //virtual void eval(const VarContainer &var);
    //virtual void eval_grad( const VarContainer &var);
    //virtual void eval_hess( const VarContainer &var);

    //virtual double operator()() const;
    //virtual double grad(int di) const;
    //virtual double hess(int di, int dj) const;

}


#endif