// created: 2014-9-8 12:27:31
// version: develop
// url: https://github.com/prisms-center/IntegrationTools.git
// commit: ef1bd09854d368ff3c34036c1fc3f97128eee51f

#ifndef MyFunc_HH
#define MyFunc_HH

#include <cmath>
#include <cstdlib>
#include "IntegrationTools/PFunction.hh"

namespace PRISMS
{
    template< class VarContainer>
    class MyFunc_f : public PSimpleBase< VarContainer, double>
    {
        double eval( const VarContainer &var) const
        {
            return  (var[1]*var[1]*var[1])+(var[0]*var[0])*var[1]+(var[0]*var[0]*var[0])+var[0]*(var[1]*var[1]);
        }

    public:

        MyFunc_f()
        {
            this->_name = "MyFunc_f";
        }

        std::string csrc() const
        {
            return " (var[1]*var[1]*var[1])+(var[0]*var[0])*var[1]+(var[0]*var[0]*var[0])+var[0]*(var[1]*var[1])";
        }

        std::string sym() const
        {
            return "x^3+y^2*x+y*x^2+y^3";
        }

        std::string latex() const
        {
            return " x^{2} y+y^{3}+ x y^{2}+x^{3}";
        }

        MyFunc_f* clone() const
        {
            return new MyFunc_f(*this);
        }
    };

    template< class VarContainer>
    class MyFunc_grad_0 : public PSimpleBase< VarContainer, double>
    {
        double eval( const VarContainer &var) const
        {
            return  2.0*var[0]*var[1]+3.0*(var[0]*var[0])+(var[1]*var[1]);
        }

    public:

        MyFunc_grad_0()
        {
            this->_name = "MyFunc_grad_0";
        }

        std::string csrc() const
        {
            return " 2.0*var[0]*var[1]+3.0*(var[0]*var[0])+(var[1]*var[1])";
        }

        std::string sym() const
        {
            return "2*y*x+3*x^2+y^2";
        }

        std::string latex() const
        {
            return "y^{2}+3 x^{2}+2  x y";
        }

        MyFunc_grad_0* clone() const
        {
            return new MyFunc_grad_0(*this);
        }
    };

    template< class VarContainer>
    class MyFunc_grad_1 : public PSimpleBase< VarContainer, double>
    {
        double eval( const VarContainer &var) const
        {
            return  2.0*var[0]*var[1]+(var[0]*var[0])+3.0*(var[1]*var[1]);
        }

    public:

        MyFunc_grad_1()
        {
            this->_name = "MyFunc_grad_1";
        }

        std::string csrc() const
        {
            return " 2.0*var[0]*var[1]+(var[0]*var[0])+3.0*(var[1]*var[1])";
        }

        std::string sym() const
        {
            return "3*y^2+x^2+2*x*y";
        }

        std::string latex() const
        {
            return "2  y x+x^{2}+3 y^{2}";
        }

        MyFunc_grad_1* clone() const
        {
            return new MyFunc_grad_1(*this);
        }
    };

    template< class VarContainer>
    class MyFunc_hess_0_0 : public PSimpleBase< VarContainer, double>
    {
        double eval( const VarContainer &var) const
        {
            return  6.0*var[0]+2.0*var[1];
        }

    public:

        MyFunc_hess_0_0()
        {
            this->_name = "MyFunc_hess_0_0";
        }

        std::string csrc() const
        {
            return " 6.0*var[0]+2.0*var[1]";
        }

        std::string sym() const
        {
            return "6*x+2*y";
        }

        std::string latex() const
        {
            return "2 y+6 x";
        }

        MyFunc_hess_0_0* clone() const
        {
            return new MyFunc_hess_0_0(*this);
        }
    };

    template< class VarContainer>
    class MyFunc_hess_0_1 : public PSimpleBase< VarContainer, double>
    {
        double eval( const VarContainer &var) const
        {
            return  2.0*var[1]+2.0*var[0];
        }

    public:

        MyFunc_hess_0_1()
        {
            this->_name = "MyFunc_hess_0_1";
        }

        std::string csrc() const
        {
            return " 2.0*var[1]+2.0*var[0]";
        }

        std::string sym() const
        {
            return "2*x+2*y";
        }

        std::string latex() const
        {
            return "2 x+2 y";
        }

        MyFunc_hess_0_1* clone() const
        {
            return new MyFunc_hess_0_1(*this);
        }
    };

    template< class VarContainer>
    class MyFunc_hess_1_0 : public PSimpleBase< VarContainer, double>
    {
        double eval( const VarContainer &var) const
        {
            return  2.0*var[1]+2.0*var[0];
        }

    public:

        MyFunc_hess_1_0()
        {
            this->_name = "MyFunc_hess_1_0";
        }

        std::string csrc() const
        {
            return " 2.0*var[1]+2.0*var[0]";
        }

        std::string sym() const
        {
            return "2*x+2*y";
        }

        std::string latex() const
        {
            return "2 y+2 x";
        }

        MyFunc_hess_1_0* clone() const
        {
            return new MyFunc_hess_1_0(*this);
        }
    };

    template< class VarContainer>
    class MyFunc_hess_1_1 : public PSimpleBase< VarContainer, double>
    {
        double eval( const VarContainer &var) const
        {
            return  2.0*var[0]+6.0*var[1];
        }

    public:

        MyFunc_hess_1_1()
        {
            this->_name = "MyFunc_hess_1_1";
        }

        std::string csrc() const
        {
            return " 2.0*var[0]+6.0*var[1]";
        }

        std::string sym() const
        {
            return "2*x+6*y";
        }

        std::string latex() const
        {
            return "2 x+6 y";
        }

        MyFunc_hess_1_1* clone() const
        {
            return new MyFunc_hess_1_1(*this);
        }
    };

    template<class VarContainer>
    class MyFunc : public PFuncBase< VarContainer, double>
    {
    public:
        
        PSimpleBase< VarContainer, double> *_val;
        PSimpleBase< VarContainer, double> **_grad_val;
        PSimpleBase< VarContainer, double> ***_hess_val;
        
        MyFunc()
        {
            construct();
        }

        MyFunc(const MyFunc &RHS )
        {
            construct();
        }

        MyFunc& operator=(const MyFunc &RHS )
        {
            _val = RHS._val;
            
            _grad_val[0] = RHS._grad_val[0];
            _grad_val[1] = RHS._grad_val[1];
            _hess_val[0][0] = RHS._hess_val[0][0];
            _hess_val[0][1] = RHS._hess_val[0][1];
            _hess_val[1][0] = RHS._hess_val[1][0];
            _hess_val[1][1] = RHS._hess_val[1][1];
        }

        ~MyFunc()
        {
            delete _val;

            delete _grad_val[0];
            delete _grad_val[1];
            delete [] _grad_val;

            delete _hess_val[0][0];
            delete _hess_val[0][1];
            delete _hess_val[1][0];
            delete _hess_val[1][1];
            delete [] _hess_val[0];
            delete [] _hess_val[1];
            delete [] _hess_val;
        }

        MyFunc<VarContainer>* clone() const
        {
            return new MyFunc<VarContainer>(*this);
        }

        PSimpleFunction< VarContainer, double> simplefunction() const
        {
            return PSimpleFunction< VarContainer, double>( *_val );
        }

        PSimpleFunction< VarContainer, double> grad_simplefunction(int di) const
        {
            return PSimpleFunction< VarContainer, double>( *_grad_val[di] );
        }

        PSimpleFunction< VarContainer, double> hess_simplefunction(int di, int dj) const
        {
            return PSimpleFunction< VarContainer, double>( *_hess_val[di][dj] );
        }

        double operator()(const VarContainer &var)
        {
            return (*_val)(var);
        }

        double grad(const VarContainer &var, int di)
        {
            return (*_grad_val[di])(var);
        }

        double hess(const VarContainer &var, int di, int dj)
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
            (*_grad_val[1])(var);
        }

        void eval_hess(const VarContainer &var)
        {
            (*_hess_val[0][0])(var);
            (*_hess_val[0][1])(var);
            (*_hess_val[1][0])(var);
            (*_hess_val[1][1])(var);
        }

        double operator()() const
        {
            return (*_val)();
        }

        double grad(int di) const
        {
            return (*_grad_val[di])();
        }

        double hess(int di, int dj) const
        {
            return (*_hess_val[di][dj])();
        }

    private:
        void construct()
        {
            this->_name = "MyFunc";
            this->_var_name.clear();
            this->_var_name.push_back("x");
            this->_var_name.push_back("y");
            this->_var_description.clear();
            this->_var_description.push_back("x variable");
            this->_var_description.push_back("y variable");
            
            _val = new MyFunc_f<VarContainer>();
            
            _grad_val = new PSimpleBase< VarContainer, double>*[2];
            _grad_val[0] = new MyFunc_grad_0<VarContainer>();
            _grad_val[1] = new MyFunc_grad_1<VarContainer>();
            
            _hess_val = new PSimpleBase< VarContainer, double>**[2];
            _hess_val[0] = new PSimpleBase< VarContainer, double>*[2];
            _hess_val[1] = new PSimpleBase< VarContainer, double>*[2];
            _hess_val[0][0] = new MyFunc_hess_0_0<VarContainer>();
            _hess_val[0][1] = new MyFunc_hess_0_1<VarContainer>();
            _hess_val[1][0] = new MyFunc_hess_1_0<VarContainer>();
            _hess_val[1][1] = new MyFunc_hess_1_1<VarContainer>();
        }

    };


}
#endif
