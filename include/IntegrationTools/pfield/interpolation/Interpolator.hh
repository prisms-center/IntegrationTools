
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
        unsigned long int _node;    //index of nodal value or control point
        PFuncBase<std::vector<Coordinate>, double>* _bfunc;          // basis function to evaluate
        
    public:
        
        unsigned long int node()
        {
            return _node;
        }
        
        virtual bool is_in_range(Coordinate coord) const
        {
            undefined("bool is_in_range(Coordinate coord)");
            return false;
        }
        
        virtual double operator()(Coordinate coord)
        {
            undefined("double operator()(Coordinate coord)");
            return double();
        }
        
        virtual double grad(Coordinate coord, int di)
        {
            undefined("double grad()(Coordinate coord, int di)");
            return double();
        }
        
        virtual double hess(Coordinate coord, int di, int dj)
        {
            undefined("double hess()(Coordinate coord, int di, int dj)");
            return double();
        }
        
    private:
        
        void undefined(std::string fname) const
        {
            std::cout << "Error in InterpolatorBase." << std::endl;
            std::cout << "   The member function '" << fname << "' has not been defined." << std::endl;
            exit(1);
        }

    };

}


#endif