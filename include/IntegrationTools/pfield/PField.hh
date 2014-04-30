
#ifndef PField_HH
#define PField_HH

#include "../pfunction/PFuncBase.hh"
#include "./Mesh.hh"

//_name(name), 
//_var_name(var_name), 
//_var_description(var_description), 
                  

namespace PRISMS
{
    
    /// A class for a field
    ///
    ///   Varcontainer contains variables, for instance 'std::vector<double>' for x, y, z
    ///   FieldType is the datatype for the field, 
    ///       for instance 'double' for temperature or 'std::vector<double>' for vector displacement
    ///
    ///   A field consists of a pointer to a mesh, a list field values (at mesh nodes)
    template<class Coordinate, class FieldType>
    class PField : public PFuncBase<Coordinate, FieldType>
    {
    public:
        
        // pointer to a Mesh that lives in a Body
        Mesh<Coordinate> *_mesh;
        
        // array of field values at mesh nodes
        std::vector<FieldType> _field;
        
        FieldType _zero;
        
        FieldType _val;
        std::vector<FieldType> _grad_val;
        std::vector< std::vector<FieldType> > _hess_val;
        
        // ----------------------------------------------------------
        // Constructors
        // PField(); 
        
        PField(   const std::string &name,
                  const std::vector<std::string> &var_name,
                  const std::vector<std::string> &var_description,
                  Mesh<Coordinate> &mesh, 
                  const std::vector<FieldType> &field, 
                  const FieldType &zero) :
                  PFuncBase<Coordinate, FieldType>(name, var_name, var_description),
                  _mesh(&mesh), 
                  _field(field), 
                  _zero(zero)
                  
        {
            int max = mesh.max_bin_size();
            _bfunc.resize(max);
            _node_index.resize(max);
        }
        
        // ----------------------------------------------------------
        // Clone
        
        PField<Coordinate,FieldType>* clone() const
        {
            return new PField<Coordinate,FieldType>(*this);
        }
        
        
        // ----------------------------------------------------------
        // Use these functions if you want to evaluate a single value
        FieldType operator()(const Coordinate &coord);
        FieldType grad(const Coordinate &coord, int di);
        FieldType hess(const Coordinate &coord, int di, int dj);
        
        // ----------------------------------------------------------
        // Use these functions to evaluate several values, then use 'get' methods to access results
        void eval(const Coordinate &coord);
        void eval_grad(const Coordinate &coord);
        void eval_hess(const Coordinate &coord);
        
        FieldType operator()() const;
        FieldType grad(int di) const;
        FieldType hess(int di, int dj) const;
        
        // PField unique members ------------------------------------------

    private:
        
        // temporary vector
        std::vector<double> _bfunc;
        std::vector<unsigned long int> _node_index;
        int _Nbfunc;
        

    };
    
    template<class Coordinate, class FieldType>
    FieldType PField<Coordinate,FieldType>::operator()( const Coordinate &coord)
    {
        // get evaluated basis functions
		(*_mesh).basis_functions(coord, _bfunc, _node_index, _Nbfunc);
		
        // sum them
        _val = _zero;
		for( int i=0; i<_Nbfunc; i++)
			_val += _bfunc[i]*_field[_node_index[i]];
		return _val;
    }
    
    template<class Coordinate, class FieldType>
    FieldType PField<Coordinate,FieldType>::grad( const Coordinate &coord, int di)
    {
        // get evaluated basis functions
		(*_mesh).grad_basis_functions(coord, di, _bfunc, _node_index, _Nbfunc);
		
        // sum them
        _grad_val[di] = _zero;
		for( int i=0; i<_Nbfunc; i++)
			_grad_val[di] += _bfunc[i]*_field[_node_index[i]];
		return _grad_val[di];
    }
    
    template<class Coordinate, class FieldType>
    FieldType PField<Coordinate,FieldType>::hess( const Coordinate &coord, int di, int dj)
    {
        // get evaluated basis functions
		(*_mesh).hess_basis_functions(coord, di, dj, _bfunc, _node_index, _Nbfunc);
		
        // sum them
        _hess_val[di][dj] = _zero;
		for( int i=0; i<_Nbfunc; i++)
			_hess_val[di][dj] += _bfunc[i]*_field[_node_index[i]];
		return _hess_val[di][dj];
    }

    template<class Coordinate, class FieldType>
    void PField<Coordinate,FieldType>::eval( const Coordinate &coord)
    {
        (*this)(coord);
    }
    
    template<class Coordinate, class FieldType>
    void PField<Coordinate,FieldType>::eval_grad( const Coordinate &coord)
    {
        for( int di=0; di<coord.size(); di++)
            (*this).grad(coord, di);
    }
    
    template<class Coordinate, class FieldType>
    void PField<Coordinate,FieldType>::eval_hess( const Coordinate &coord)
    {
        for( int di=0; di<coord.size(); di++)
            for( int dj=0; dj<coord.size(); dj++)
                (*this).hess(coord, di, dj);
    }
    
    template<class Coordinate, class FieldType>
    FieldType PField<Coordinate,FieldType>::operator()() const
    {
        return _val;
    }
    
    template<class Coordinate, class FieldType>
    FieldType PField<Coordinate,FieldType>::grad( int di) const
    {
        return _grad_val[di];
    }
    
    template<class Coordinate, class FieldType>
    FieldType PField<Coordinate,FieldType>::hess( int di, int dj) const
    {
        return _hess_val[di][dj];
    }

}


#endif