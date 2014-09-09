// created: 2014-9-8 12:27:31
// version: develop
// url: https://github.com/prisms-center/IntegrationTools.git
// commit: ef1bd09854d368ff3c34036c1fc3f97128eee51f

#ifndef MyPieceWiseFunc_HH
#define MyPieceWiseFunc_HH

#include <cmath>
#include <cstdlib>
#include "IntegrationTools/PFunction.hh"
#include "IntegrationTools/PPieceWise.hh"

namespace PRISMS
{
    template< class VarContainer>
    class MyPieceWiseFunc_piece0_f : public PSimpleBase< VarContainer, double>
    {
        double eval( const VarContainer &var) const
        {
            return var[0];
        }

    public:

        MyPieceWiseFunc_piece0_f()
        {
            this->_name = "MyPieceWiseFunc_piece0_f";
        }

        std::string csrc() const
        {
            return "var[0]";
        }

        std::string sym() const
        {
            return "x";
        }

        std::string latex() const
        {
            return "x";
        }

        MyPieceWiseFunc_piece0_f* clone() const
        {
            return new MyPieceWiseFunc_piece0_f(*this);
        }
    };

    template< class VarContainer>
    class MyPieceWiseFunc_piece0_grad_0 : public PSimpleBase< VarContainer, double>
    {
        double eval( const VarContainer &var) const
        {
            return 1.0;
        }

    public:

        MyPieceWiseFunc_piece0_grad_0()
        {
            this->_name = "MyPieceWiseFunc_piece0_grad_0";
        }

        std::string csrc() const
        {
            return "1.0";
        }

        std::string sym() const
        {
            return "1";
        }

        std::string latex() const
        {
            return "1";
        }

        MyPieceWiseFunc_piece0_grad_0* clone() const
        {
            return new MyPieceWiseFunc_piece0_grad_0(*this);
        }
    };

    template< class VarContainer>
    class MyPieceWiseFunc_piece0_grad_1 : public PSimpleBase< VarContainer, double>
    {
        double eval( const VarContainer &var) const
        {
            return 0.0;
        }

    public:

        MyPieceWiseFunc_piece0_grad_1()
        {
            this->_name = "MyPieceWiseFunc_piece0_grad_1";
        }

        std::string csrc() const
        {
            return "0.0";
        }

        std::string sym() const
        {
            return "0";
        }

        std::string latex() const
        {
            return "0";
        }

        MyPieceWiseFunc_piece0_grad_1* clone() const
        {
            return new MyPieceWiseFunc_piece0_grad_1(*this);
        }
    };

    template< class VarContainer>
    class MyPieceWiseFunc_piece0_hess_0_0 : public PSimpleBase< VarContainer, double>
    {
        double eval( const VarContainer &var) const
        {
            return 0.0;
        }

    public:

        MyPieceWiseFunc_piece0_hess_0_0()
        {
            this->_name = "MyPieceWiseFunc_piece0_hess_0_0";
        }

        std::string csrc() const
        {
            return "0.0";
        }

        std::string sym() const
        {
            return "0";
        }

        std::string latex() const
        {
            return "0";
        }

        MyPieceWiseFunc_piece0_hess_0_0* clone() const
        {
            return new MyPieceWiseFunc_piece0_hess_0_0(*this);
        }
    };

    template< class VarContainer>
    class MyPieceWiseFunc_piece0_hess_0_1 : public PSimpleBase< VarContainer, double>
    {
        double eval( const VarContainer &var) const
        {
            return 0.0;
        }

    public:

        MyPieceWiseFunc_piece0_hess_0_1()
        {
            this->_name = "MyPieceWiseFunc_piece0_hess_0_1";
        }

        std::string csrc() const
        {
            return "0.0";
        }

        std::string sym() const
        {
            return "0";
        }

        std::string latex() const
        {
            return "0";
        }

        MyPieceWiseFunc_piece0_hess_0_1* clone() const
        {
            return new MyPieceWiseFunc_piece0_hess_0_1(*this);
        }
    };

    template< class VarContainer>
    class MyPieceWiseFunc_piece0_hess_1_0 : public PSimpleBase< VarContainer, double>
    {
        double eval( const VarContainer &var) const
        {
            return 0.0;
        }

    public:

        MyPieceWiseFunc_piece0_hess_1_0()
        {
            this->_name = "MyPieceWiseFunc_piece0_hess_1_0";
        }

        std::string csrc() const
        {
            return "0.0";
        }

        std::string sym() const
        {
            return "0";
        }

        std::string latex() const
        {
            return "0";
        }

        MyPieceWiseFunc_piece0_hess_1_0* clone() const
        {
            return new MyPieceWiseFunc_piece0_hess_1_0(*this);
        }
    };

    template< class VarContainer>
    class MyPieceWiseFunc_piece0_hess_1_1 : public PSimpleBase< VarContainer, double>
    {
        double eval( const VarContainer &var) const
        {
            return 0.0;
        }

    public:

        MyPieceWiseFunc_piece0_hess_1_1()
        {
            this->_name = "MyPieceWiseFunc_piece0_hess_1_1";
        }

        std::string csrc() const
        {
            return "0.0";
        }

        std::string sym() const
        {
            return "0";
        }

        std::string latex() const
        {
            return "0";
        }

        MyPieceWiseFunc_piece0_hess_1_1* clone() const
        {
            return new MyPieceWiseFunc_piece0_hess_1_1(*this);
        }
    };

    template<class VarContainer>
    class MyPieceWiseFunc_piece0 : public PFuncBase< VarContainer, double>
    {
    public:
        
        PSimpleBase< VarContainer, double> *_val;
        PSimpleBase< VarContainer, double> **_grad_val;
        PSimpleBase< VarContainer, double> ***_hess_val;
        
        MyPieceWiseFunc_piece0()
        {
            construct();
        }

        MyPieceWiseFunc_piece0(const MyPieceWiseFunc_piece0 &RHS )
        {
            construct();
        }

        MyPieceWiseFunc_piece0& operator=(const MyPieceWiseFunc_piece0 &RHS )
        {
            _val = RHS._val;
            
            _grad_val[0] = RHS._grad_val[0];
            _grad_val[1] = RHS._grad_val[1];
            _hess_val[0][0] = RHS._hess_val[0][0];
            _hess_val[0][1] = RHS._hess_val[0][1];
            _hess_val[1][0] = RHS._hess_val[1][0];
            _hess_val[1][1] = RHS._hess_val[1][1];
        }

        ~MyPieceWiseFunc_piece0()
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

        MyPieceWiseFunc_piece0<VarContainer>* clone() const
        {
            return new MyPieceWiseFunc_piece0<VarContainer>(*this);
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
            this->_name = "MyPieceWiseFunc_piece0";
            this->_var_name.clear();
            this->_var_name.push_back("x");
            this->_var_name.push_back("y");
            this->_var_description.clear();
            this->_var_description.push_back("x variable");
            this->_var_description.push_back("y variable");
            
            _val = new MyPieceWiseFunc_piece0_f<VarContainer>();
            
            _grad_val = new PSimpleBase< VarContainer, double>*[2];
            _grad_val[0] = new MyPieceWiseFunc_piece0_grad_0<VarContainer>();
            _grad_val[1] = new MyPieceWiseFunc_piece0_grad_1<VarContainer>();
            
            _hess_val = new PSimpleBase< VarContainer, double>**[2];
            _hess_val[0] = new PSimpleBase< VarContainer, double>*[2];
            _hess_val[1] = new PSimpleBase< VarContainer, double>*[2];
            _hess_val[0][0] = new MyPieceWiseFunc_piece0_hess_0_0<VarContainer>();
            _hess_val[0][1] = new MyPieceWiseFunc_piece0_hess_0_1<VarContainer>();
            _hess_val[1][0] = new MyPieceWiseFunc_piece0_hess_1_0<VarContainer>();
            _hess_val[1][1] = new MyPieceWiseFunc_piece0_hess_1_1<VarContainer>();
        }

    };


    template< class VarContainer>
    class MyPieceWiseFunc_piece0_cond0 : public PSimpleBase< VarContainer, bool>
    {
        bool eval( const VarContainer &var) const
        {
            return var[0] < 0.0;
        }

    public:

        MyPieceWiseFunc_piece0_cond0()
        {
            this->_name = "MyPieceWiseFunc_piece0_cond0";
        }

        std::string csrc() const
        {
            return "var[0] < 0.0";
        }

        std::string sym() const
        {
            return "x < 0";
        }

        std::string latex() const
        {
            return "x < 0";
        }

        MyPieceWiseFunc_piece0_cond0* clone() const
        {
            return new MyPieceWiseFunc_piece0_cond0(*this);
        }
    };

    template< class VarContainer>
    class MyPieceWiseFunc_piece1_f : public PSimpleBase< VarContainer, double>
    {
        double eval( const VarContainer &var) const
        {
            return  (var[0]*var[0])+(var[1]*var[1]);
        }

    public:

        MyPieceWiseFunc_piece1_f()
        {
            this->_name = "MyPieceWiseFunc_piece1_f";
        }

        std::string csrc() const
        {
            return " (var[0]*var[0])+(var[1]*var[1])";
        }

        std::string sym() const
        {
            return "y^2+x^2";
        }

        std::string latex() const
        {
            return "y^{2}+x^{2}";
        }

        MyPieceWiseFunc_piece1_f* clone() const
        {
            return new MyPieceWiseFunc_piece1_f(*this);
        }
    };

    template< class VarContainer>
    class MyPieceWiseFunc_piece1_grad_0 : public PSimpleBase< VarContainer, double>
    {
        double eval( const VarContainer &var) const
        {
            return 2.0*var[0];
        }

    public:

        MyPieceWiseFunc_piece1_grad_0()
        {
            this->_name = "MyPieceWiseFunc_piece1_grad_0";
        }

        std::string csrc() const
        {
            return "2.0*var[0]";
        }

        std::string sym() const
        {
            return "2*x";
        }

        std::string latex() const
        {
            return "2  x";
        }

        MyPieceWiseFunc_piece1_grad_0* clone() const
        {
            return new MyPieceWiseFunc_piece1_grad_0(*this);
        }
    };

    template< class VarContainer>
    class MyPieceWiseFunc_piece1_grad_1 : public PSimpleBase< VarContainer, double>
    {
        double eval( const VarContainer &var) const
        {
            return 2.0*var[1];
        }

    public:

        MyPieceWiseFunc_piece1_grad_1()
        {
            this->_name = "MyPieceWiseFunc_piece1_grad_1";
        }

        std::string csrc() const
        {
            return "2.0*var[1]";
        }

        std::string sym() const
        {
            return "2*y";
        }

        std::string latex() const
        {
            return "2  y";
        }

        MyPieceWiseFunc_piece1_grad_1* clone() const
        {
            return new MyPieceWiseFunc_piece1_grad_1(*this);
        }
    };

    template< class VarContainer>
    class MyPieceWiseFunc_piece1_hess_0_0 : public PSimpleBase< VarContainer, double>
    {
        double eval( const VarContainer &var) const
        {
            return 2.0;
        }

    public:

        MyPieceWiseFunc_piece1_hess_0_0()
        {
            this->_name = "MyPieceWiseFunc_piece1_hess_0_0";
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

        MyPieceWiseFunc_piece1_hess_0_0* clone() const
        {
            return new MyPieceWiseFunc_piece1_hess_0_0(*this);
        }
    };

    template< class VarContainer>
    class MyPieceWiseFunc_piece1_hess_0_1 : public PSimpleBase< VarContainer, double>
    {
        double eval( const VarContainer &var) const
        {
            return 0.0;
        }

    public:

        MyPieceWiseFunc_piece1_hess_0_1()
        {
            this->_name = "MyPieceWiseFunc_piece1_hess_0_1";
        }

        std::string csrc() const
        {
            return "0.0";
        }

        std::string sym() const
        {
            return "0";
        }

        std::string latex() const
        {
            return "0";
        }

        MyPieceWiseFunc_piece1_hess_0_1* clone() const
        {
            return new MyPieceWiseFunc_piece1_hess_0_1(*this);
        }
    };

    template< class VarContainer>
    class MyPieceWiseFunc_piece1_hess_1_0 : public PSimpleBase< VarContainer, double>
    {
        double eval( const VarContainer &var) const
        {
            return 0.0;
        }

    public:

        MyPieceWiseFunc_piece1_hess_1_0()
        {
            this->_name = "MyPieceWiseFunc_piece1_hess_1_0";
        }

        std::string csrc() const
        {
            return "0.0";
        }

        std::string sym() const
        {
            return "0";
        }

        std::string latex() const
        {
            return "0";
        }

        MyPieceWiseFunc_piece1_hess_1_0* clone() const
        {
            return new MyPieceWiseFunc_piece1_hess_1_0(*this);
        }
    };

    template< class VarContainer>
    class MyPieceWiseFunc_piece1_hess_1_1 : public PSimpleBase< VarContainer, double>
    {
        double eval( const VarContainer &var) const
        {
            return 2.0;
        }

    public:

        MyPieceWiseFunc_piece1_hess_1_1()
        {
            this->_name = "MyPieceWiseFunc_piece1_hess_1_1";
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

        MyPieceWiseFunc_piece1_hess_1_1* clone() const
        {
            return new MyPieceWiseFunc_piece1_hess_1_1(*this);
        }
    };

    template<class VarContainer>
    class MyPieceWiseFunc_piece1 : public PFuncBase< VarContainer, double>
    {
    public:
        
        PSimpleBase< VarContainer, double> *_val;
        PSimpleBase< VarContainer, double> **_grad_val;
        PSimpleBase< VarContainer, double> ***_hess_val;
        
        MyPieceWiseFunc_piece1()
        {
            construct();
        }

        MyPieceWiseFunc_piece1(const MyPieceWiseFunc_piece1 &RHS )
        {
            construct();
        }

        MyPieceWiseFunc_piece1& operator=(const MyPieceWiseFunc_piece1 &RHS )
        {
            _val = RHS._val;
            
            _grad_val[0] = RHS._grad_val[0];
            _grad_val[1] = RHS._grad_val[1];
            _hess_val[0][0] = RHS._hess_val[0][0];
            _hess_val[0][1] = RHS._hess_val[0][1];
            _hess_val[1][0] = RHS._hess_val[1][0];
            _hess_val[1][1] = RHS._hess_val[1][1];
        }

        ~MyPieceWiseFunc_piece1()
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

        MyPieceWiseFunc_piece1<VarContainer>* clone() const
        {
            return new MyPieceWiseFunc_piece1<VarContainer>(*this);
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
            this->_name = "MyPieceWiseFunc_piece1";
            this->_var_name.clear();
            this->_var_name.push_back("x");
            this->_var_name.push_back("y");
            this->_var_description.clear();
            this->_var_description.push_back("x variable");
            this->_var_description.push_back("y variable");
            
            _val = new MyPieceWiseFunc_piece1_f<VarContainer>();
            
            _grad_val = new PSimpleBase< VarContainer, double>*[2];
            _grad_val[0] = new MyPieceWiseFunc_piece1_grad_0<VarContainer>();
            _grad_val[1] = new MyPieceWiseFunc_piece1_grad_1<VarContainer>();
            
            _hess_val = new PSimpleBase< VarContainer, double>**[2];
            _hess_val[0] = new PSimpleBase< VarContainer, double>*[2];
            _hess_val[1] = new PSimpleBase< VarContainer, double>*[2];
            _hess_val[0][0] = new MyPieceWiseFunc_piece1_hess_0_0<VarContainer>();
            _hess_val[0][1] = new MyPieceWiseFunc_piece1_hess_0_1<VarContainer>();
            _hess_val[1][0] = new MyPieceWiseFunc_piece1_hess_1_0<VarContainer>();
            _hess_val[1][1] = new MyPieceWiseFunc_piece1_hess_1_1<VarContainer>();
        }

    };


    template< class VarContainer>
    class MyPieceWiseFunc_piece1_cond0 : public PSimpleBase< VarContainer, bool>
    {
        bool eval( const VarContainer &var) const
        {
            return  (var[0]*var[0])+(var[1]*var[1]) < 2.5000000000000000e-01;
        }

    public:

        MyPieceWiseFunc_piece1_cond0()
        {
            this->_name = "MyPieceWiseFunc_piece1_cond0";
        }

        std::string csrc() const
        {
            return " (var[0]*var[0])+(var[1]*var[1]) < 2.5000000000000000e-01";
        }

        std::string sym() const
        {
            return "x^2+y^2 < 0.25";
        }

        std::string latex() const
        {
            return "x^{2}+y^{2} < 0.25";
        }

        MyPieceWiseFunc_piece1_cond0* clone() const
        {
            return new MyPieceWiseFunc_piece1_cond0(*this);
        }
    };

    template< class VarContainer>
    class MyPieceWiseFunc_piece1_cond1 : public PSimpleBase< VarContainer, bool>
    {
        bool eval( const VarContainer &var) const
        {
            return var[0] >= 0.0;
        }

    public:

        MyPieceWiseFunc_piece1_cond1()
        {
            this->_name = "MyPieceWiseFunc_piece1_cond1";
        }

        std::string csrc() const
        {
            return "var[0] >= 0.0";
        }

        std::string sym() const
        {
            return "x >= 0";
        }

        std::string latex() const
        {
            return "x \\geq 0";
        }

        MyPieceWiseFunc_piece1_cond1* clone() const
        {
            return new MyPieceWiseFunc_piece1_cond1(*this);
        }
    };

    template< class VarContainer>
    class MyPieceWiseFunc_piece2_f : public PSimpleBase< VarContainer, double>
    {
        double eval( const VarContainer &var) const
        {
            return  pow( (var[1]*var[1])+(var[0]*var[0]),(1.0/2.0))-2.5000000000000000e-01;
        }

    public:

        MyPieceWiseFunc_piece2_f()
        {
            this->_name = "MyPieceWiseFunc_piece2_f";
        }

        std::string csrc() const
        {
            return " pow( (var[1]*var[1])+(var[0]*var[0]),(1.0/2.0))-2.5000000000000000e-01";
        }

        std::string sym() const
        {
            return "-0.25+sqrt(x^2+y^2)";
        }

        std::string latex() const
        {
            return "-0.25+\\sqrt{x^{2}+y^{2}}";
        }

        MyPieceWiseFunc_piece2_f* clone() const
        {
            return new MyPieceWiseFunc_piece2_f(*this);
        }
    };

    template< class VarContainer>
    class MyPieceWiseFunc_piece2_grad_0 : public PSimpleBase< VarContainer, double>
    {
        double eval( const VarContainer &var) const
        {
            return var[0]*pow( (var[1]*var[1])+(var[0]*var[0]),-(1.0/2.0));
        }

    public:

        MyPieceWiseFunc_piece2_grad_0()
        {
            this->_name = "MyPieceWiseFunc_piece2_grad_0";
        }

        std::string csrc() const
        {
            return "var[0]*pow( (var[1]*var[1])+(var[0]*var[0]),-(1.0/2.0))";
        }

        std::string sym() const
        {
            return "x*(x^2+y^2)^(-1/2)";
        }

        std::string latex() const
        {
            return "\\frac{x}{\\sqrt{y^{2}+x^{2}}}";
        }

        MyPieceWiseFunc_piece2_grad_0* clone() const
        {
            return new MyPieceWiseFunc_piece2_grad_0(*this);
        }
    };

    template< class VarContainer>
    class MyPieceWiseFunc_piece2_grad_1 : public PSimpleBase< VarContainer, double>
    {
        double eval( const VarContainer &var) const
        {
            return var[1]*pow( (var[0]*var[0])+(var[1]*var[1]),-(1.0/2.0));
        }

    public:

        MyPieceWiseFunc_piece2_grad_1()
        {
            this->_name = "MyPieceWiseFunc_piece2_grad_1";
        }

        std::string csrc() const
        {
            return "var[1]*pow( (var[0]*var[0])+(var[1]*var[1]),-(1.0/2.0))";
        }

        std::string sym() const
        {
            return "(y^2+x^2)^(-1/2)*y";
        }

        std::string latex() const
        {
            return "\\frac{y}{\\sqrt{x^{2}+y^{2}}}";
        }

        MyPieceWiseFunc_piece2_grad_1* clone() const
        {
            return new MyPieceWiseFunc_piece2_grad_1(*this);
        }
    };

    template< class VarContainer>
    class MyPieceWiseFunc_piece2_hess_0_0 : public PSimpleBase< VarContainer, double>
    {
        double eval( const VarContainer &var) const
        {
            return  pow( (var[1]*var[1])+(var[0]*var[0]),-(1.0/2.0))-pow( (var[1]*var[1])+(var[0]*var[0]),-(3.0/2.0))*(var[0]*var[0]);
        }

    public:

        MyPieceWiseFunc_piece2_hess_0_0()
        {
            this->_name = "MyPieceWiseFunc_piece2_hess_0_0";
        }

        std::string csrc() const
        {
            return " pow( (var[1]*var[1])+(var[0]*var[0]),-(1.0/2.0))-pow( (var[1]*var[1])+(var[0]*var[0]),-(3.0/2.0))*(var[0]*var[0])";
        }

        std::string sym() const
        {
            return "-(x^2+y^2)^(-3/2)*x^2+(x^2+y^2)^(-1/2)";
        }

        std::string latex() const
        {
            return "\\frac{1}{\\sqrt{y^{2}+x^{2}}}-\\frac{x^{2}}{{(y^{2}+x^{2})}^{{(\\frac{3}{2})}}}";
        }

        MyPieceWiseFunc_piece2_hess_0_0* clone() const
        {
            return new MyPieceWiseFunc_piece2_hess_0_0(*this);
        }
    };

    template< class VarContainer>
    class MyPieceWiseFunc_piece2_hess_0_1 : public PSimpleBase< VarContainer, double>
    {
        double eval( const VarContainer &var) const
        {
            return -var[0]*var[1]*pow( (var[0]*var[0])+(var[1]*var[1]),-(3.0/2.0));
        }

    public:

        MyPieceWiseFunc_piece2_hess_0_1()
        {
            this->_name = "MyPieceWiseFunc_piece2_hess_0_1";
        }

        std::string csrc() const
        {
            return "-var[0]*var[1]*pow( (var[0]*var[0])+(var[1]*var[1]),-(3.0/2.0))";
        }

        std::string sym() const
        {
            return "-(y^2+x^2)^(-3/2)*x*y";
        }

        std::string latex() const
        {
            return "-\\frac{ y x}{{(x^{2}+y^{2})}^{{(\\frac{3}{2})}}}";
        }

        MyPieceWiseFunc_piece2_hess_0_1* clone() const
        {
            return new MyPieceWiseFunc_piece2_hess_0_1(*this);
        }
    };

    template< class VarContainer>
    class MyPieceWiseFunc_piece2_hess_1_0 : public PSimpleBase< VarContainer, double>
    {
        double eval( const VarContainer &var) const
        {
            return -var[0]*var[1]*pow( (var[0]*var[0])+(var[1]*var[1]),-(3.0/2.0));
        }

    public:

        MyPieceWiseFunc_piece2_hess_1_0()
        {
            this->_name = "MyPieceWiseFunc_piece2_hess_1_0";
        }

        std::string csrc() const
        {
            return "-var[0]*var[1]*pow( (var[0]*var[0])+(var[1]*var[1]),-(3.0/2.0))";
        }

        std::string sym() const
        {
            return "-x*y*(x^2+y^2)^(-3/2)";
        }

        std::string latex() const
        {
            return "-\\frac{ y x}{{(x^{2}+y^{2})}^{{(\\frac{3}{2})}}}";
        }

        MyPieceWiseFunc_piece2_hess_1_0* clone() const
        {
            return new MyPieceWiseFunc_piece2_hess_1_0(*this);
        }
    };

    template< class VarContainer>
    class MyPieceWiseFunc_piece2_hess_1_1 : public PSimpleBase< VarContainer, double>
    {
        double eval( const VarContainer &var) const
        {
            return  pow( (var[0]*var[0])+(var[1]*var[1]),-(1.0/2.0))-(var[1]*var[1])*pow( (var[0]*var[0])+(var[1]*var[1]),-(3.0/2.0));
        }

    public:

        MyPieceWiseFunc_piece2_hess_1_1()
        {
            this->_name = "MyPieceWiseFunc_piece2_hess_1_1";
        }

        std::string csrc() const
        {
            return " pow( (var[0]*var[0])+(var[1]*var[1]),-(1.0/2.0))-(var[1]*var[1])*pow( (var[0]*var[0])+(var[1]*var[1]),-(3.0/2.0))";
        }

        std::string sym() const
        {
            return "-y^2*(x^2+y^2)^(-3/2)+(x^2+y^2)^(-1/2)";
        }

        std::string latex() const
        {
            return "\\frac{1}{\\sqrt{y^{2}+x^{2}}}-\\frac{y^{2}}{{(y^{2}+x^{2})}^{{(\\frac{3}{2})}}}";
        }

        MyPieceWiseFunc_piece2_hess_1_1* clone() const
        {
            return new MyPieceWiseFunc_piece2_hess_1_1(*this);
        }
    };

    template<class VarContainer>
    class MyPieceWiseFunc_piece2 : public PFuncBase< VarContainer, double>
    {
    public:
        
        PSimpleBase< VarContainer, double> *_val;
        PSimpleBase< VarContainer, double> **_grad_val;
        PSimpleBase< VarContainer, double> ***_hess_val;
        
        MyPieceWiseFunc_piece2()
        {
            construct();
        }

        MyPieceWiseFunc_piece2(const MyPieceWiseFunc_piece2 &RHS )
        {
            construct();
        }

        MyPieceWiseFunc_piece2& operator=(const MyPieceWiseFunc_piece2 &RHS )
        {
            _val = RHS._val;
            
            _grad_val[0] = RHS._grad_val[0];
            _grad_val[1] = RHS._grad_val[1];
            _hess_val[0][0] = RHS._hess_val[0][0];
            _hess_val[0][1] = RHS._hess_val[0][1];
            _hess_val[1][0] = RHS._hess_val[1][0];
            _hess_val[1][1] = RHS._hess_val[1][1];
        }

        ~MyPieceWiseFunc_piece2()
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

        MyPieceWiseFunc_piece2<VarContainer>* clone() const
        {
            return new MyPieceWiseFunc_piece2<VarContainer>(*this);
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
            this->_name = "MyPieceWiseFunc_piece2";
            this->_var_name.clear();
            this->_var_name.push_back("x");
            this->_var_name.push_back("y");
            this->_var_description.clear();
            this->_var_description.push_back("x variable");
            this->_var_description.push_back("y variable");
            
            _val = new MyPieceWiseFunc_piece2_f<VarContainer>();
            
            _grad_val = new PSimpleBase< VarContainer, double>*[2];
            _grad_val[0] = new MyPieceWiseFunc_piece2_grad_0<VarContainer>();
            _grad_val[1] = new MyPieceWiseFunc_piece2_grad_1<VarContainer>();
            
            _hess_val = new PSimpleBase< VarContainer, double>**[2];
            _hess_val[0] = new PSimpleBase< VarContainer, double>*[2];
            _hess_val[1] = new PSimpleBase< VarContainer, double>*[2];
            _hess_val[0][0] = new MyPieceWiseFunc_piece2_hess_0_0<VarContainer>();
            _hess_val[0][1] = new MyPieceWiseFunc_piece2_hess_0_1<VarContainer>();
            _hess_val[1][0] = new MyPieceWiseFunc_piece2_hess_1_0<VarContainer>();
            _hess_val[1][1] = new MyPieceWiseFunc_piece2_hess_1_1<VarContainer>();
        }

    };


    template< class VarContainer>
    class MyPieceWiseFunc_piece2_cond0 : public PSimpleBase< VarContainer, bool>
    {
        bool eval( const VarContainer &var) const
        {
            return  (var[0]*var[0])+(var[1]*var[1]) >= 2.5000000000000000e-01;
        }

    public:

        MyPieceWiseFunc_piece2_cond0()
        {
            this->_name = "MyPieceWiseFunc_piece2_cond0";
        }

        std::string csrc() const
        {
            return " (var[0]*var[0])+(var[1]*var[1]) >= 2.5000000000000000e-01";
        }

        std::string sym() const
        {
            return "x^2+y^2 >= 0.25";
        }

        std::string latex() const
        {
            return "x^{2}+y^{2} \\geq 0.25";
        }

        MyPieceWiseFunc_piece2_cond0* clone() const
        {
            return new MyPieceWiseFunc_piece2_cond0(*this);
        }
    };

    template< class VarContainer>
    class MyPieceWiseFunc_piece2_cond1 : public PSimpleBase< VarContainer, bool>
    {
        bool eval( const VarContainer &var) const
        {
            return var[0] >= 0.0;
        }

    public:

        MyPieceWiseFunc_piece2_cond1()
        {
            this->_name = "MyPieceWiseFunc_piece2_cond1";
        }

        std::string csrc() const
        {
            return "var[0] >= 0.0";
        }

        std::string sym() const
        {
            return "x >= 0";
        }

        std::string latex() const
        {
            return "x \\geq 0";
        }

        MyPieceWiseFunc_piece2_cond1* clone() const
        {
            return new MyPieceWiseFunc_piece2_cond1(*this);
        }
    };

    template< class VarContainer >
    class MyPieceWiseFunc : public PPieceWiseFuncBase<VarContainer, double>
    {
    public:
        MyPieceWiseFunc()
        {
            this->_name = "MyPieceWiseFunc";
            this->_var_name.clear();
            this->_var_name.push_back("x");
            this->_var_name.push_back("y");
            this->_var_description.clear();
            this->_var_description.push_back("x variable");
            this->_var_description.push_back("y variable");
            typedef Piece<VarContainer, double> Pc;
            typedef PSimpleFunction<VarContainer, bool> Cond;
            typedef PSimpleFunction<VarContainer, double> psf;
            typedef PFunction<VarContainer, double> pf;

            std::vector<Cond> cond;

            cond.push_back( Cond(MyPieceWiseFunc_piece0_cond0<VarContainer>()));
            this->_piece.push_back( Pc( pf(MyPieceWiseFunc_piece0<VarContainer>()), cond) );
            cond.clear();

            cond.push_back( Cond(MyPieceWiseFunc_piece1_cond0<VarContainer>()));
            cond.push_back( Cond(MyPieceWiseFunc_piece1_cond1<VarContainer>()));
            this->_piece.push_back( Pc( pf(MyPieceWiseFunc_piece1<VarContainer>()), cond) );
            cond.clear();

            cond.push_back( Cond(MyPieceWiseFunc_piece2_cond0<VarContainer>()));
            cond.push_back( Cond(MyPieceWiseFunc_piece2_cond1<VarContainer>()));
            this->_piece.push_back( Pc( pf(MyPieceWiseFunc_piece2<VarContainer>()), cond) );
            cond.clear();

        }
    };


}
#endif
