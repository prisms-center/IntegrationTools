#ifndef Quadratic_HH
#define Quadratic_HH

#include <cmath>
#include <cstdlib>
#include "IntegrationTools/PFunction.hh"

namespace PRISMS
{
    template< class VarContainer>
    class Quadratic_f : public PSimpleBase< VarContainer, double>
    {
        double eval( const VarContainer &var) const
        {
            return  var[0]+(var[0]*var[0])+1.0;
        }

    public:

        Quadratic_f()
        {
            this->_name = "Quadratic_f";
        }

        std::string csrc() const
        {
            return " var[0]+(var[0]*var[0])+1.0";
        }

        std::string sym() const
        {
            return "1+x+x^2";
        }

        std::string latex() const
        {
            return "1+x^{2}+x";
        }

        Quadratic_f* clone() const
        {
            return new Quadratic_f(*this);
        }
    };

    template< class VarContainer>
    class Quadratic_grad_0 : public PSimpleBase< VarContainer, double>
    {
        double eval( const VarContainer &var) const
        {
            return  2.0*var[0]+1.0;
        }

    public:

        Quadratic_grad_0()
        {
            this->_name = "Quadratic_grad_0";
        }

        std::string csrc() const
        {
            return " 2.0*var[0]+1.0";
        }

        std::string sym() const
        {
            return "1+2*x";
        }

        std::string latex() const
        {
            return "1+2 x";
        }

        Quadratic_grad_0* clone() const
        {
            return new Quadratic_grad_0(*this);
        }
    };

    template< class VarContainer>
    class Quadratic_hess_0_0 : public PSimpleBase< VarContainer, double>
    {
        double eval( const VarContainer &var) const
        {
            return 2.0;
        }

    public:

        Quadratic_hess_0_0()
        {
            this->_name = "Quadratic_hess_0_0";
        }

        std::string csrc() const
        {
            return "2.0";
        }

        std::string sym() const
        {
            return "2";
        }

        std::string latex() const
        {
            return "2";
        }

        Quadratic_hess_0_0* clone() const
        {
            return new Quadratic_hess_0_0(*this);
        }
    };

    template<class VarContainer>
    class Quadratic : public PFuncBase< VarContainer, double>
    {
    public:
        
        typedef typename PFuncBase< VarContainer, double>::size_type size_type;
        
        PSimpleBase< VarContainer, double> *_val;
        PSimpleBase< VarContainer, double> **_grad_val;
        PSimpleBase< VarContainer, double> ***_hess_val;
        
        Quadratic()
        {
            construct();
        }

        Quadratic(const Quadratic &RHS )
        {
            construct(false);
            
            _val = RHS._val->clone();
            _grad_val[0] = RHS._grad_val[0]->clone();
            _hess_val[0][0] = RHS._hess_val[0][0]->clone();
            
        }

        Quadratic& operator=( Quadratic RHS )
        {
            using std::swap;
            
            swap(_val, RHS._val);
            swap(_grad_val[0], RHS._grad_val[0]);
            swap(_hess_val[0][0], RHS._hess_val[0][0]);
            
            return *this;
        }
        
        ~Quadratic()
        {
            delete _val;

            delete _grad_val[0];
            delete [] _grad_val;

            delete _hess_val[0][0];
            delete [] _hess_val[0];
            delete [] _hess_val;
        }

        Quadratic<VarContainer>* clone() const
        {
            return new Quadratic<VarContainer>(*this);
        }

        PSimpleFunction< VarContainer, double> simplefunction() const
        {
            return PSimpleFunction< VarContainer, double>( *_val );
        }

        PSimpleFunction< VarContainer, double> grad_simplefunction(size_type di) const
        {
            return PSimpleFunction< VarContainer, double>( *_grad_val[di] );
        }

        PSimpleFunction< VarContainer, double> hess_simplefunction(size_type di, size_type dj) const
        {
            return PSimpleFunction< VarContainer, double>( *_hess_val[di][dj] );
        }

        double operator()(const VarContainer &var)
        {
            return (*_val)(var);
        }

        double grad(const VarContainer &var, size_type di)
        {
            return (*_grad_val[di])(var);
        }

        double hess(const VarContainer &var, size_type di, size_type dj)
        {
            return (*_hess_val[di][dj])(var);
        }

        void eval(const VarContainer &var)
        {
            (*_val)(var);
        }

        void eval_grad(const VarContainer &var)
        {
            (*_grad_val[0])(var);
        }

        void eval_hess(const VarContainer &var)
        {
            (*_hess_val[0][0])(var);
        }

        double operator()() const
        {
            return (*_val)();
        }

        double grad(size_type di) const
        {
            return (*_grad_val[di])();
        }

        double hess(size_type di, size_type dj) const
        {
            return (*_hess_val[di][dj])();
        }

    private:
        void construct(bool allocate = true)
        {
            this->_name = "Quadratic";
            this->_var_name.clear();
            this->_var_name.push_back("x");
            this->_var_description.clear();
            this->_var_description.push_back("A quadratic function of one variable");
            
            _grad_val = new PSimpleBase< VarContainer, double>*[1];
            
            _hess_val = new PSimpleBase< VarContainer, double>**[1];
            _hess_val[0] = new PSimpleBase< VarContainer, double>*[1];
            
            if(!allocate) return;
            
            _val = new Quadratic_f<VarContainer>();
            
            _grad_val[0] = new Quadratic_grad_0<VarContainer>();
            
            _hess_val[0][0] = new Quadratic_hess_0_0<VarContainer>();
        }

    };


}
#endif
