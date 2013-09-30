
#ifndef PComplexSymFunction_HH
#define PComplexSymFunction_HH

#include "PFunction.hh"
#include <ginac/ginac.h>    // compile with: -lcln -lginac
#include <complex>

namespace PRISMS
{

    /// Real valued symbolic functions

    template< template<class> class Container>
    class PComplexSymFunction : public PBaseFunction< Container, complex<double>, complex<double> >
    {
        GiNaC::ex _e;
        std::vector< GiNaC::symbol> _sym;

        complex<double> _val;
        std::vector< complex<double> > _grad;
        std::vector< std::vector< complex<double> > > _hess;

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
                std::cout << "PComplexSymFunction::sym i: " << i << "  sym: " << _sym[i] << "  _var_name: " << _var_name[i] << std::endl;

            }

            _name = name;

            _e = e;
        }


        // ----------------------------------------------------------
        //   Inherited:

        using PBaseFunction< Container, complex<double>, complex<double> >::_name;
        using PBaseFunction< Container, complex<double>, complex<double> >::_var_name;

        virtual PComplexSymFunction<Container> *clone() const
        {
            return new PComplexSymFunction<Container>(*this);
        };

        // ----------------------------------------------------------
        // Use these functions if you want to evaluate a single value
        complex<double> operator()(const Container< complex<double> > &var) const;
        complex<double> grad(const Container< complex<double> > &var, int di) const;
        complex<double> hess(const Container< complex<double> > &var, int di, int dj) const;

        // ----------------------------------------------------------
        // Use these functions to evaluate several values, then use 'get' methods to access results
        //virtual void eval(const Container< complex<double> > &var);
        //virtual void eval_grad( const Container< complex<double> > &var);
        //virtual void eval_hess( const Container< complex<double> > &var);

        //virtual complex<double> operator()() const;
        //virtual complex<double> grad(int di) const;
        //virtual complex<double> hess(int di, int dj) const;

    };

    template< template<class> class Container>
    complex<double> PComplexSymFunction<Container>::operator()(const Container< complex<double> > &var) const
    {
        GiNaC::exmap m;
        for(int i = 0; i < var.size(); i++)
        {
            std::cout << "i: " << var[i] << "  " << _sym[i] << std::endl;
            m[_sym[i]] = var[i].real() + var[i].imag() * GiNaC::I;
        }

        std::cout << m << std::endl;
        std::cout << _e.subs(m) << std::endl;

        return complex<double>(GiNaC::ex_to<GiNaC::numeric>(GiNaC::evalf(_e.real_part().subs(m))).to_double(),
                               GiNaC::ex_to<GiNaC::numeric>(GiNaC::evalf(_e.imag_part().subs(m))).to_double());
    }


    template< template<class> class Container>
    complex<double> PComplexSymFunction<Container>::grad(const Container< complex<double> > &var, int di) const
    {
        GiNaC::ex de = _e.diff(_sym[di]);

        GiNaC::exmap m;
        for(int i = 0; i < var.size(); i++)
        {
            std::cout << "i: " << var[i] << "  " << _sym[i] << std::endl;
            m[_sym[i]] = var[i].real() + var[i].imag() * GiNaC::I;
        }
        std::cout << m << std::endl;
        std::cout << "de: " << de << " :: " << de.subs(m) << std::endl;

        return complex<double>(GiNaC::ex_to<GiNaC::numeric>(GiNaC::evalf(de.real_part().subs(m))).to_double(),
                               GiNaC::ex_to<GiNaC::numeric>(GiNaC::evalf(de.imag_part().subs(m))).to_double());
    };

    template< template<class> class Container>
    complex<double> PComplexSymFunction<Container>::hess(const Container< complex<double> > &var, int di, int dj) const
    {
        GiNaC::ex de = _e.diff(_sym[di]).diff(_sym[dj]);

        GiNaC::exmap m;
        for(int i = 0; i < var.size(); i++)
        {
            std::cout << "i: " << var[i] << "  " << _sym[i] << std::endl;
            m[_sym[i]] = var[i].real() + var[i].imag() * GiNaC::I;
        }
        std::cout << m << std::endl;
        std::cout << "de: " << de << " :: " << de.subs(m) << std::endl;

        return complex<double>(GiNaC::ex_to<GiNaC::numeric>(GiNaC::evalf(de.real_part().subs(m))).to_double(),
                               GiNaC::ex_to<GiNaC::numeric>(GiNaC::evalf(de.imag_part().subs(m))).to_double());
    };

    // ----------------------------------------------------------
    // Use these functions to evaluate several values, then use 'get' methods to access results
    //virtual void eval(const Container< complex<double> > &var);
    //virtual void eval_grad( const Container< complex<double> > &var);
    //virtual void eval_hess( const Container< complex<double> > &var);

    //virtual complex<double> operator()() const;
    //virtual complex<double> grad(int di) const;
    //virtual complex<double> hess(int di, int dj) const;

}


#endif