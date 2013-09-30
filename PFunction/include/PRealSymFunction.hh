
#ifndef PRealSymFunction_HH
#define PRealSymFunction_HH

#include "PFunction.hh"
#include <ginac/ginac.h>    // compile with: -lcln -lginac

namespace PRISMS
{

    /// Real valued symbolic functions

    template< template<class> class Container>
    class PRealSymFunction : public PBaseFunction< Container, double, double>
    {
        GiNaC::ex _e;
        std::vector< GiNaC::symbol> _sym;

        double _val;
        std::vector<double> _grad;
        std::vector< std::vector<double> > _hess;

    public:

        // ----------------------------------------------------------
        //   Non-Inherited:

        void set(const std::string &name, const Container<GiNaC::symbol> &sym, const GiNaC::ex &e)
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

        using PBaseFunction< Container, double, double>::_name;
        using PBaseFunction< Container, double, double>::_var_name;

        virtual PRealSymFunction<Container> *clone() const
        {
            return new PRealSymFunction<Container>(*this);
        };

        // ----------------------------------------------------------
        // Use these functions if you want to evaluate a single value
        double operator()(const Container<double> &var) const;
        double grad(const Container<double> &var, int di) const;
        double hess(const Container<double> &var, int di, int dj) const;

        // ----------------------------------------------------------
        // Use these functions to evaluate several values, then use 'get' methods to access results
        //virtual void eval(const Container<double> &var);
        //virtual void eval_grad( const Container<double> &var);
        //virtual void eval_hess( const Container<double> &var);

        //virtual double operator()() const;
        //virtual double grad(int di) const;
        //virtual double hess(int di, int dj) const;

    };

    template< template<class> class Container>
    double PRealSymFunction<Container>::operator()(const Container<double> &var) const
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


    template< template<class> class Container>
    double PRealSymFunction<Container>::grad(const Container<double> &var, int di) const
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

    template< template<class> class Container>
    double PRealSymFunction<Container>::hess(const Container<double> &var, int di, int dj) const
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
    //virtual void eval(const Container<double> &var);
    //virtual void eval_grad( const Container<double> &var);
    //virtual void eval_hess( const Container<double> &var);

    //virtual double operator()() const;
    //virtual double grad(int di) const;
    //virtual double hess(int di, int dj) const;

}


#endif