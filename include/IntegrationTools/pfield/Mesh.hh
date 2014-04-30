
#ifndef Mesh_HH
#define Mesh_HH

#include "../datastruc/Bin.hh"
#include "../pfunction/PFuncBase.hh"
#include "./interpolation/Interpolator.hh"

namespace PRISMS
{
    
    /// A template class for a finite element mesh
    ///   Needs: Coordinate::operator[]() for use in Bin
    ///
    template< class Coordinate>
    class Mesh
    {
        /// Vector of nodal coordinates
        ///    nodal values live in 'Field' class
        ///
        std::vector<Coordinate> _node;          
        
        /// array containing interpolating functions: 
        ///    owns the interpolating functions
        ///    interpolating functions contain basis function / element info, 
        ///    these point to _bfunc pfunctions which are used to evaluate
        ///
        std::vector<Interpolator<Coordinate>*> _binfo;  
        
        /// array containing PFunctions evaluated by interpolating functions
        ///    owns the pfunctions, which are pointed to by the interpolating functions
        ///    !!! do not modify after initial construction or pointers will be messed up !!!
        ///
        std::vector< PFuncBase<std::vector<Coordinate>, double>* > _bfunc;
        
        /// bin of interpolating functions (this might be updated to be either Element or Spline Bins)
        ///
        Bin<Interpolator<Coordinate>*, Coordinate> _bin;
	
	public:
    
        // still need a constructor
        Mesh(){};
        
        int max_bin_size()
        {
            return _bin.max_size();
        }
            
        // Set 'bfunc' to evaluated basis functions at 'coord', 
        //     'node_index' to node indices for each basis function,
        //     and 's' is the length (number of basis functions)
        //  - 'bfunc' and 'node_index' are not resized, they must be big enough
        //
        void basis_functions(const Coordinate &coord, std::vector<double> &bfunc, std::vector<unsigned long int> &node_index, int &s) 
        {
            std::vector<Interpolator<Coordinate>* > &bin = _bin.contents(coord);
            s = bin.size();
            for( int i=0; i<s; i++)
            {
                bfunc[i] = (*bin[i])(coord); 
                node_index[i] = (*bin[i]).node();
            }
        };
        
        // Set 'bfunc' to evaluated grad basis functions at coord, and 's' is the length
        void grad_basis_functions(const Coordinate &coord, int di, std::vector<double> &bfunc, std::vector<unsigned long int> &node_index, int &s)
        {
            std::vector<Interpolator<Coordinate>* > &bin = _bin.contents(coord);
            s = bin.size();
            for( int i=0; i<s; i++)
            {
                bfunc[i] = (*bin[i]).grad(coord, di);
                node_index[i] = (*bin[i]).node();
            }
        }
        
        // Set 'bfunc' to evaluated hess basis functions at coord, and 's' is the length
        void hess_basis_functions(Coordinate coord, int di, int dj, std::vector<double> &bfunc, std::vector<unsigned long int> &node_index, int &s)
        {
            std::vector<Interpolator<Coordinate>* > &bin = _bin.contents(coord);
            s = bin.size();
            for( int i=0; i<s; i++)
            {
                bfunc[i] = (*bin[i]).hess(coord, di, dj);
                node_index[i] = (*bin[i]).node();
            }
        }
    };

}


#endif