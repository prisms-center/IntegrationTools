
#ifndef Body_HH
#define Body_HH

#include "./Mesh.hh"
#include "./PField.hh"
#include <iostream>
#include <fstream>
#include <string>

namespace PRISMS
{
    
    /// A class for a Body: a combination of Mesh and Field(s))
    ///
    template< class Coordinate>
    class Body
    {
    public:
        
        Mesh<Coordinate> mesh;
        
        std::vector< PField<Coordinate, double> > scalar_field;
        
        //std::vector< PField<Coordinate, double> > scalar_field;
        
        //std::vector< PField<Coordinate, Tensor<double> > > tensor_field;
        
        
        // ----------------------------------------------------------
        // Constructors
        // PField(); 
        
        /// Construct a Body from a vtk file
        ///   For now:
        ///      only ASCII files
        ///      only rectilinear grids (though output as UNSTRUCTURED_GRID)
        ///      only (2d) Quad or (3d) Hexahedron elements
        ///
        Body( const std::string &vtkfile)
        {
            // read in vtk file here
            std::ifstream infile(vtkfile);
            
            std::string line;
            
            while(!infile.eof())
            {
                std::getline( infile, line);
                std::cout << line << "\n";
            }
            
        }
    };
}


#endif