
#ifndef Quad_HH
#define Quad_HH

#include "../../pfunction/PSimpleBase.hh"
#include "../../pfunction/PSimpleFunction.hh"
#include "../../pfunction/PFuncBase.hh"
#include "./Interpolator.hh"

namespace PRISMS
{
    template< class VarContainer>
    class Quad_f : public PSimpleBase< VarContainer, double>
    {
        double eval( const VarContainer &var) const
        {
            // var[0]: coordinate to be evaluated
            // var[1]: nodal coordinate
            // var[2]: element dimension
            // var[3]: +/- 1 depending on which 'corner' of quad
            //
            // f = (1.0 - e0)*(1.0 - e1)
            // e = var[3]*(var[0] - var[1])/var[2]
            
            return (1.0 - var[3][0]*(var[0][0] - var[1][0])/var[2][0])*(1.0 - var[3][1]*(var[0][1] - var[1][1])/var[2][1]);
        }

    public:

        Quad_f()
        {
            this->_name = "Quad_f";
        }

        Quad_f* clone() const
        {
            return new Quad_f(*this);
        }
    };
    
    template< class VarContainer>
    class Quad_grad_0 : public PSimpleBase< VarContainer, double>
    {
        double eval( const VarContainer &var) const
        {
            return -var[3][0]*(1.0 - var[3][1]*(var[0][1] - var[1][1])/var[2][1])/var[2][0];
        }

    public:

        Quad_grad_0()
        {
            this->_name = "Quad_grad_0";
        }

        Quad_grad_0* clone() const
        {
            return new Quad_grad_0(*this);
        }
    };
    
    template< class VarContainer>
    class Quad_grad_1 : public PSimpleBase< VarContainer, double>
    {
        double eval( const VarContainer &var) const
        {
            return -var[3][1]*(1.0 - var[3][0]*(var[0][0] - var[1][0])/var[2][0])/var[2][1]);
        
        }

    public:

        Quad_grad_1()
        {
            this->_name = "Quad_grad_1";
        }

        Quad_grad_1* clone() const
        {
            return new Quad_grad_1(*this);
        }
    };
    
    template< class VarContainer>
    class Quad_hess_0_0 : public PSimpleBase< VarContainer, double>
    {
        double eval( const VarContainer &var) const
        {
            return 0.0;
        }

    public:

        Quad_hess_0_0()
        {
            this->_name = "Quad_hess_0_0";
        }

        Quad_hess_0_0* clone() const
        {
            return new Quad_hess_0_0(*this);
        }
    };
    
    template< class VarContainer>
    class Quad_hess_0_1 : public PSimpleBase< VarContainer, double>
    {
        double eval( const VarContainer &var) const
        {
            return var[3][0]*var[3][1]/var[2][0]/var[2][1];
        }

    public:

        Quad_hess_0_1()
        {
            this->_name = "Quad_hess_0_1";
        }

        Quad_hess_0_1* clone() const
        {
            return new Quad_hess_0_1(*this);
        }
    };
    
    template< class VarContainer>
    class Quad_hess_1_0 : public PSimpleBase< VarContainer, double>
    {
        double eval( const VarContainer &var) const
        {
            return var[3][0]*var[3][1]/var[2][0]/var[2][1];
        }

    public:

        Quad_hess_1_0()
        {
            this->_name = "Quad_hess_1_0";
        }

        Quad_hess_1_0* clone() const
        {
            return new Quad_hess_1_0(*this);
        }
    };
    
    template< class VarContainer>
    class Quad_hess_1_1 : public PSimpleBase< VarContainer, double>
    {
        double eval( const VarContainer &var) const
        {
            return 0.0;
        }

    public:

        Quad_hess_1_1()
        {
            this->_name = "Quad_hess_1_1";
        }

        Quad_hess_1_1* clone() const
        {
            return new Quad_hess_1_1(*this);
        }
    };
    
    
    /// VarContainer is a vector-like container of Coordinates
    template<class VarContainer>
    class Quad : public PFuncBase<VarContainer, double>
    {
        PSimpleBase<VarContainer, double>* _val;
        PSimpleBase<VarContainer, double>** _grad_val;
        PSimpleBase<VarContainer, double>*** _hess_val;
        
        Quad()
        {
            construct();
        }
        
        Quad( const Quad &RHS)
        {
            construct();
        }
        
        ~Quad()
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
        
        Quad<VarContainer>* clone() const
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
            this->_name = "Quad";
            this->_var_name.clear();
            this->_var_name.push_back("r");
            this->_var_name.push_back("n");
            this->_var_name.push_back("h");
            this->_var_name.push_back("s");
            this->_var_description.clear();
            this->_var_description.push_back("Coordinate to be evaluated (Cartesian)");
            this->_var_description.push_back("Coordinate of node");
            this->_var_description.push_back("Coordinate containing element dimensions");
            this->_var_description.push_back("Coordinate containing +/- 1.0, depending on which corner of quad element");
            
            _val = new Quad_f<VarContainer>();
            
            _grad_val = new PSimpleBase< VarContainer, double>*[2];
            _grad_val[0] = new Quad_grad_0<VarContainer>();
            _grad_val[1] = new Quad_grad_1<VarContainer>();
            
            _hess_val = new PSimpleBase< VarContainer, double>**[2];
            _hess_val[0] = new PSimpleBase< VarContainer, double>*[2];
            _hess_val[1] = new PSimpleBase< VarContainer, double>*[2];
            _hess_val[0][0] = new Quad_hess_0_0<VarContainer>();
            _hess_val[0][1] = new Quad_hess_0_1<VarContainer>();
            _hess_val[1][0] = new Quad_hess_1_0<VarContainer>();
            _hess_val[1][1] = new Quad_hess_1_1<VarContainer>();
        }
    };
    
    
    /// A base class for interpolating functions
    ///
    template <class Coordinate>
    class QuadValues : public Interpolator<Coordinate>
    {
        //_var[0]: Coordinate _r;  // coordinate to evaluate field at
        //_var[1]: Coordinate _n;  // coordinate of node
        //_var[2]: Coordinate _h;  // quad dimensions
        //_var[3]: Coordinate _s;  // +/- 1, depending on orientation of basis function
        std::vector<Coordinate> _var;
        
    public:
    
        // node: Coordinate of node
        // dim: Coordinate containing x and y dimension of element
        // node_index: 0 == bottom left, proceed counter clockwise to 3 == top left of element
        
        QuadValues(const Coordinate &node, const Coordinate &dim, int node_index)
        : _var(4, node)
        {
            _var[2] = dim;
            
            if( node_index == 0)
            {
                _var[3][0] = 1.0;
                _var[3][1] = 1.0;
            }
            else if( node_index == 1)
            {
                _var[3][0] = -1.0;
                _var[3][1] = 1.0;
            }
            else if( node_index == 1)
            {
                _var[3][0] = -1.0;
                _var[3][1] = -1.0;
            }
            else if( node_index == 1)
            {
                _var[3][0] = 1.0;
                _var[3][1] = -1.0;
            }
        }
    
        bool is_in_range(const Coordinate &coord) const
        {
            _var[0] = coord;
            double e;
            
            for( int i=0; i<2; i++)
            {
                e = _var[3][i]*(_var[0][i] - _var[1][i])/_var[2][i];
                if( e < 0.0 || e >= 1.0)
                    return false;
            }
            
            return true;
        }
        
        double operator()(const Coordinate &coord)
        {
            _var[0] = coord;
            return (*_bfunc)(var);
        }
        
        double grad()(const Coordinate &coord, int di)
        {
            _var[0] = coord;
            return (*_bfunc).grad(var,di);
        }
        
        double hess()(const Coordinate &coord, int di, int dj)
        {
            _var[0] = coord;
            return (*_bfunc).hess(var,di,dj);
        }

    };

}


#endif