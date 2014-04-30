
#ifndef Bin_HH
#define Bin_HH

#include <cmath>
#include <stdexcept>
#include "PNDArray.hh"

namespace PRISMS
{
    
    /// A class for binning things
    ///   template class T: the type of thing being binned
    ///     - should have T::operator==() defined to use 'Bin::add_once'
    ///   template class Coordinate:
    ///     - expected to be 'vector<double> like'
    ///     - should have Coordinate::operator[]() defined
    ///
    template< class T, class Coordinate>
    class Bin
    {
        PNDArray<std::vector<T> > _item;
	
        std::vector<double> _min;	// min coord
        std::vector<double> _incr;	// histogram spacing along each direction (uniform along each dimension)
        std::vector<int> _N;		// number of bins along each direction
        std::vector<double> _max;	// max coord
        std::vector<int> _indices;
	
	public:
        
        Bin<T>(){};
        
        /// Construct a Bin
        ///   'min': minimum value of each coordinate component
        ///   'incr': bin spacing along each direction (this is uniform along each dimension)
        ///   'N': number of bins along each direction
        ///
        /// For example, to bin the range (0->10, 0->20, 10->100), with size 1 bin spacing:
        ///    Bin<T>( {0,0,10}, {1,1,1}, {10, 20, 90})
        ///
        Bin<T>(const std::vector<double> &min, std::vector<double> &incr, std::vector<int> &N)
        {
            _min = min;
            _incr = incr;
            _N = N;
            _max = std::vector<double>(_min.size());
            for( int i=0; i<_min.size(); i++)
                _max[i] = _min[i] + _incr[i]*_N[i];
            _indices = _N;
            _item.resize(_N);
        }
            
        /// Add a new item to the bin containing a given coordinate
        void add( const T &newitem, const Coordinate &coord)
        {
            indices( coord, &_indices);
            _item(_indices).push_back(newitem);
        }
        
        /// Add a new item to the bin containing a given coordinate,
        ///   if an equivalent item is not already present
        /// return 'true' if added succesfully, 'false' if not
        void add_once( const T &newitem, const Coordinate &coord)
        {
            indices( coord, &_indices);
            std::vector<T> &singlebin = _item(_indices);
            for( int i=0; i<singlebin.size(); i++)
            {
                if( singlebin[i] == newitem)
                    return;
            }
            
            singlebin.push_back(newitem);
        }
                
        std::vector<T>& contents( const Coordinate &coord)
        {    
            indices( coord, &_indices);
            return _item(_indices);
        }
        
        // maximum size of any bin
        int max_size()
        {
            int max = 0;
            for( int i=0; i<_item.volume(); i++)
                if( _item(i).size() > max)
                    max = _item(i).size();
            return max;
        }
        
    private:
    
        /// Set 'term' to be the indices into '_item' PNDArray of the bin that contains 'coord'
        ///   Return 'false' if unsuccesful, 'true' if succesful
        void indices(const Coordinate &coord, std::vector<int> *term)
        {
            for( int i=0; i<_item.order(); i++)
            {
                if( (coord[i] < _min[i]) || (coord[i] > _max[i]) )
                    throw std::domain_error("Invalid coord, out of bin range");
                (*term)[i] = std::floor( (coord[i] - _min[i])/_incr[i]);
            }
        }
    };

}


#endif