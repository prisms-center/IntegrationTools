
#ifndef Mesh_HH
#define Mesh_HH

#include <fstream>
#include <sstream>
#include <algorithm>
#include <cstdlib>

#include "../datastruc/Bin.hh"
#include "../pfunction/PFuncBase.hh"
#include "./interpolation/Interpolator.hh"
#include "./interpolation/Quad.hh"

namespace PRISMS
{
    
    /// A template class for a finite element mesh
    ///   Needs: Coordinate::operator[]() for use in Bin
    ///
    template< class Coordinate>
    class Mesh
    {
        Coordinate _coord;
        
        // min and max coordinate of cuboid surrounding the body
        Coordinate _min;
        Coordinate _max;
        
        /// Vector of nodal coordinates
        ///    nodal values live in 'Field' class
        ///
        std::vector<Coordinate> _node;          
        
        /// array containing interpolating functions: 
        ///    owns the interpolating functions
        ///    interpolating functions contain basis function / element info, 
        ///    these point to _bfunc pfunctions which are used to evaluate
        ///
        std::vector<Interpolator<Coordinate>* > _interp;  
        
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
        Mesh(const Coordinate &coord){_coord = coord; _min = coord; _max = coord;};
        
        // reads vtk file through 'CELL_TYPES' and then returns
        void read_2d_vtk(std::ifstream &infile)
        {
            std::istringstream ss;
            std::string line, str, type;
            
            int i_dummy;
            unsigned long int uli_dummy;
            double d_dummy;
            
            unsigned long int Npoints, Ncells, Ncell_numbers;
            unsigned long int cell_node[4];
            
            while(!infile.eof())
            {
                std::getline( infile, line);
                
                if( line[0] == 'P')
                {
                    // read POINTS info:
                    // POINTS # type
                    // x y z
                    // x y z
                    // ... 
                    if( line.size() > 5 && line.substr(0,6) == "POINTS")
                    {
                        // read header line
                        //std::cout << line << "\n";
                        ss.clear();
                        ss.str(line);
                        ss >> str >> Npoints >> type;
                        
                        // read points
                        std::vector< std::vector<double> > value(2);
                        std::vector< std::vector<int> > hist(2);
                        
                        std::cout << "Read POINTS: " << Npoints << std::endl;
                        _node.reserve(Npoints);
                        for( int i=0; i<Npoints; i++)
                        {
                            infile >> _coord[0] >> _coord[1] >> d_dummy;
                            
                            //std::cout << _coord[0] << " " << _coord[1] << " " << d_dummy << std::endl;
                            
                            for( int j=0; j<2; j++)
                                add_once( value[j], hist[j], _coord[j]);
                            _node.push_back(_coord);
                        }
                        std::cout << "  done" << std::endl;
                        
                        // create bins
                        std::vector<double> min;
                        std::vector<int> N;
                        std::vector<double> incr;
                        
                        std::cout << "Determine Body size" << std::endl;
                        for( int j=0; j<2; j++)
                        {
                            for( int i=1; i<hist[j].size(); i++)
                            {
                                /*if( hist[j][i] != hist[j][i-1])
                                {
                                    std::cout << "Error reading 2D vtk file." << std::endl;
                                    std::cout << "  Not rectangular." << std::endl;
                                    std::cout << "  Dimension: " << j << std::endl;
                                    std::cout << value[j][i-1] << ": " << hist[j][i-1] << "  " << value[j][i] << ": " << hist[j][i] << std::endl;
                                    exit(1);
                                }
                                */
                            }
                            
                            std::sort( value[j].begin(), value[j].end());
                            std::cout << "j: " << j << " back(): " << value[j].back() << std::endl;
                            min.push_back( value[j][0]);
                            N.push_back( value[j].size());
                            incr.push_back( (value[j].back() - value[j][0])/(1.0*N.back()));
                            
                            // get min and max surrounding coordinates
                            _min[j] = value[j][0];
                            _max[j] = value[j].back();
                            
                            // for short term, expand bin to avoid edge issues 
                            min[j] -= incr[j];
                            N[j] += 2;
                        }
                        std::cout << "  Min Coordinate: ";
                        for( int j=0; j<2; j++)
                            std::cout << _min[j] << " ";
                        std::cout << std::endl;
                        std::cout << "  Max Coordinate: ";
                        for( int j=0; j<2; j++)
                            std::cout << _max[j] << " ";
                        std::cout << std::endl;
                        
                        std::cout << "  done" << std::endl;
                        
                        std::cout << "Initialize Bin" << std::endl;
                        _bin = Bin<Interpolator<Coordinate>*, Coordinate>(min, incr, N);
                        std::cout << "  done" << std::endl;
                        
                    }
                    
                    
                }
                else if( line[0] == 'C')
                {
                    
                    if( line.size() > 4 && line.substr(0,5) == "CELLS")
                    {
                        //std::cout << line << "\n";
                        ss.clear();
                        ss.str(line);
                        
                        ss >> str >> Ncells >> Ncell_numbers;
                        
                        // add Quad basis function
                        PFuncBase<std::vector<Coordinate>, double>* quad_ptr;
                        _bfunc.push_back( quad_ptr);
                        _bfunc.back() = new PRISMS::Quad<std::vector<Coordinate> >();
                        quad_ptr = _bfunc.back();
                        
                        Interpolator<Coordinate>* _interp_ptr;
                        
                        std::cout << "Read CELLS: " << Ncells << std::endl;
                        for( int i=0; i<Ncells; i++)
                        {
                            infile >> uli_dummy >> cell_node[0] >> cell_node[1] >> cell_node[2] >> cell_node[3];
                            
                            //std::cout << cell_node[0] << " " << cell_node[1] << " " << cell_node[2] << " " << cell_node[3] << std::endl;
                            
                            // create interpolator
                            _coord[0] = _node[ cell_node[2]][0] - _node[ cell_node[0]][0];
                            _coord[1] = _node[ cell_node[2]][1] - _node[ cell_node[0]][1];
                            
                            // QuadValues(const Coordinate &node, const Coordinate &dim, int node_index)
                            for( int j=0; j<4; j++)
                            {
                                _interp.push_back( _interp_ptr );
                                
                                //std::cout << "cell_node: " << cell_node[j] << std::endl;
                                //std::cout << "quad_ptr: " << quad_ptr << std::endl;
                                //std::cout << "node_coord: " << _node[ cell_node[j]] << std::endl;
                                //std::cout << "dim: " << _coord << std::endl;
                                //std::cout << "j: " << j << std::endl;
                                _interp.back() = new PRISMS::QuadValues<Coordinate>(cell_node[j], quad_ptr, _node[ cell_node[j]], _coord, j);
                            }
                        }
                        std::cout << "  done" << std::endl;
                        
                        // bin interpolators
                        std::cout << "Bin interpolating functions" << std::endl;
                        
                        for( int i=0; i<_interp.size(); i++)
                        {
                            _bin.add_range(_interp[i], _interp[i]->min(), _interp[i]->max());
                        }
                        std::cout << "  done  max_bin_size: " << _bin.max_size() << std::endl;
                        
                        
                    }
                    else if( line.size() > 9 && line.substr(0,10) == "CELL_TYPES")
                    {
                        //std::cout << line << "\n";
                        ss.clear();
                        ss.str(line);
                        
                        //std::cout << "ss.str()" << ss.str() << std::endl;
                        ss >> str >> Ncells;
                        
                        for( int i=0; i<Ncells; i++)
                        {
                            infile >> uli_dummy;
                            
                            if( uli_dummy != 9)
                            {
                                std::cout << "Error reading CELL_TYPES: CELL TYPE != 9" << std::endl;
                                std::cout << "   CELL TYPE: " << uli_dummy << std::endl;
                                exit(1);
                            }
                        }
                        
                        return;
                    }
                    
                }
            }
        }
        
        Coordinate min(){ return _min;}
        Coordinate max(){ return _max;}
        
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
            //std::cout << "begin Mesh::basis_functions()" << std::endl;
            std::vector<Interpolator<Coordinate>* > &bin = _bin.contents(coord);
            s = bin.size();
            for( int i=0; i<s; i++)
            {
                bfunc[i] = (*bin[i])(coord); 
                node_index[i] = (*bin[i]).node();
                //std::cout << "i: " << i << "  bfunc: " << bfunc[i] << "  node: " << node_index[i] << std::endl;
            }
            //std::cout << "finish Mesh::basis_functions()" << std::endl;
            
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
    
    private:
        
        void add_once( std::vector<double> &list, std::vector<int> &hist, double val)
        {
            //std::cout << "begin add_once()" << std::endl;
            
            for( int i=0; i<list.size(); i++)
            {
                if( list[i] == val)
                {
                    hist[i]++;
                    return;
                }
            }
            
            list.push_back(val);
            hist.push_back(1);
            
            //std::cout << "finish add_once()" << std::endl;
            
        }
    };

}


#endif