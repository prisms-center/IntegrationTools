
#ifndef Body_HH
#define Body_HH

#include "./Mesh.hh"
#include "./PField.hh"
#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>

namespace PRISMS
{
    
    /// A class for a Body: a combination of Mesh and Field(s))
    ///
    template< class Coordinate>
    class Body
    {
        Coordinate _coord;
        
    public:
        
        Mesh<Coordinate> mesh;
        
        std::vector< PField<Coordinate, double> > scalar_field;
        
        //std::vector< PField<Coordinate, std::vector<double> > > vector_field;
        
        //std::vector< PField<Coordinate, Tensor<double> > > tensor_field;
        
        
        // ----------------------------------------------------------
        // Constructors
        Body(const Coordinate &coord):mesh(coord){_coord = coord;}; 
        
        /// Read from a 2D vtk file
        ///   For now:
        ///      only ASCII files
        ///      only rectilinear grids (though output as UNSTRUCTURED_GRID)
        ///      only (2d) Quad elements
        ///
        void read_2d_vtk( const std::string &vtkfile)
        {
            std::cout << "Begin reading 2D vtk file" << std::endl;
            
            
            // read in vtk file here
            std::ifstream infile(vtkfile);
            
            // read mesh info
            mesh.read_2d_vtk(infile);
            
            // read point data
            std::istringstream ss;
            std::string str, name, type, line;
            int numcomp;
            unsigned long int Npoints;
            
            while(!infile.eof())
            {
                std::getline( infile, line);
                
                if( line[0] == 'P')
                {
                    if( line.size() > 9 && line.substr(0,10) == "POINT_DATA")
                    {
                        std::cout << line << "\n";
                        ss.clear();
                        ss.str(line);
                        ss >> str >> Npoints;
                        
                    }
                }
                else if( line[0] == 'S')
                {
                    if( line.size() > 6 && line.substr(0,7) == "SCALARS")
                    {
                        ss.clear();
                        ss.str(line);
                        ss >> str >> name >> type >> numcomp;
                        
                        // read LOOKUP_TABLE line
                        std::getline( infile, line);
                        
                        // read data
                        std::vector<double> data(Npoints);
                        for( int i=0; i<Npoints; i++)
                        {
                            infile >> data[i];
                        }
                        
                        // construct field
                        std::vector<std::string> var_name(_coord.size());
                        std::vector<std::string> var_description(_coord.size());
                        
                        var_name[0] = "x";
                        var_name[1] = "y";
                        
                        var_description[0] = "x coordinate";
                        var_description[1] = "y coordinate";
                        
                        std::cout << "Construct PField '" << name << "'" << std::endl;
                        scalar_field.push_back( PField<Coordinate, double>( name, var_name, var_description, mesh, data, 0.0) );
                    }
                }
            }
            
            infile.close();
        }
        
        /// Read from a 3D vtk file
        ///   For now:
        ///      only ASCII files
        ///      only rectilinear grids (though output as UNSTRUCTURED_GRID)
        ///      only (3d) Hexahedron elements
        ///
        void read_3d_vtk( const std::string &vtkfile)
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
        
        PField<Coordinate, double>& find_scalar_field(std::string name)
        {
            for( int i=0; i<scalar_field.size(); i++)
            {
                if( scalar_field[i].name() == name)
                    return scalar_field[i];
            }
            throw std::invalid_argument("Could not find scalar_field named '" + name + "'" );
        }
    };
}


#endif