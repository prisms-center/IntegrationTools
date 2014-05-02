
#ifndef Interpolator_HH
#define Interpolator_HH

#include "../../pfunction/PFuncBase.hh"

namespace PRISMS
{
    
    /// A base class for interpolating functions
    ///
    template <class Coordinate>
    class Interpolator
    {
    protected:
    
        unsigned long int _node;    //index of nodal value or control point
        PFuncBase<std::vector<Coordinate>, double>* _bfunc;          // basis function to evaluate
        
    public:
        
        Interpolator( unsigned long int node, PFuncBase<std::vector<Coordinate>, double>* bfunc):
        _node(node), _bfunc(bfunc)
        {};
        
        unsigned long int node()
        {
            return _node;
        }
        
        virtual Coordinate min() const
        {
            undefined("Coordinate min() const");
            return Coordinate();
        }
        
        virtual Coordinate max() const
        {
            undefined("Coordinate max() const");
            return Coordinate();
        }
        
        virtual bool is_in_range(const Coordinate &coord)
        {
            undefined("bool is_in_range(Coordinate coord) const");
            return false;
        }
        
        virtual double operator()(const Coordinate &coord)
        {
            undefined("double operator()(Coordinate coord)");
            return double();
        }
        
        virtual double grad(const Coordinate &coord, int di)
        {
            undefined("double grad()(Coordinate coord, int di)");
            return double();
        }
        
        virtual double hess(const Coordinate &coord, int di, int dj)
        {
            undefined("double hess()(Coordinate coord, int di, int dj)");
            return double();
        }
        
    private:
        
        void undefined(std::string fname) const
        {
            std::cout << "Error in Interpolator." << std::endl;
            std::cout << "   The member function '" << fname << "' has not been defined." << std::endl;
            exit(1);
        }

    };

}


#endif