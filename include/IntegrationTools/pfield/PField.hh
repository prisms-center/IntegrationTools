
#ifndef PField_HH
#define PField_HH

namespace PRISMS
{
    
    /// A class for a field
    ///
    ///   Varcontainer contains variables, for instance 'std::vector<double>' for x, y, z
    ///   FieldType is the datatype for the field, 
    ///       for instance 'double' for temperature or 'std::vector<double>' for vector displacement
    ///
    ///   A field consists of a pointer to a mesh, a list field values (at mesh nodes)
    template<class FieldType>
    class PField : public PFuncBase<Coordinate, FieldType>
    {
    public:
        
        // pointer to a Mesh that lives in a Body
        Mesh *_mesh;
        
        // array of field values at mesh nodes
        std::vector<FieldType> _field;
        
        FieldType _zero;
        
        FieldType _val;
        std::vector<FieldType> _grad_val;
        std::vector< std::vector<FieldType> > _hess_val;
        
        // ----------------------------------------------------------
        // Constructors
        // PField(); 
        
        PField(const std::string &name,
                  const std::vector<std::string> &var_name,
                  const std::vector<std::string> &var_description
                  Mesh &mesh, 
                  const std::vector<FieldType> &field, 
                  const FieldType &zero) :
                  _name(name), _var_name(var_name), _var_description(var_description), _mesh(&mesh), _field(field), _zero(zero)
        {
        }
        
        // ----------------------------------------------------------
        // Clone
        
        PField<FieldType>* clone() const
        {
            return new PField<FieldType>(*this);
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
        

    };
    
    template<class FieldType>
    FieldType PField::operator()( const Coordinate &coord)
    {
        std::vector<BasisFunctionBase*> bfunc;
        
        // get evaluated basis functions
		(*_mesh).basis_functions(coord,bfunc);
		
        // sum them
        _val = _zero;
		for( int i=0; i<bfunc.size(); i++)
			_val += bfunc[i]()*field[bfunc[i].node()];
		return _val;
    }
    
    template<class FieldType>
    FieldType PField::grad( const Coordinate &var, int di)
    {
        std::vector<BasisFunctionBase*> bfunc;
        
        // get evaluated basis functions
		(*_mesh).grad_basis_functions(coord,bfunc,di);
		
        // sum them
        _grad_val[di] = _zero;
		for( int i=0; i<bfunc.size(); i++)
			_grad_val[di] += bfunc[i]()*field[bfunc[i].node()];
		return _grad_val[di];
    }
    
    template<class FieldType>
    FieldType PField::hess( const Coordinate &coord, int di, int dj)
    {
        std::vector<BasisFunctionBase*> bfunc;
        
        // get evaluated basis functions
		(*_mesh).hess_basis_functions(coord,bfunc,di,dj);
		
        // sum them
        _hess_val[di][dj] = _zero;
		for( int i=0; i<bfunc.size(); i++)
			_hess_val[di][dj] += bfunc[i]()*field[bfunc[i].node()];
		return _hess_val[di][dj];
    }

    template<class FieldType>
    void PField::eval( const Coordinate &coord)
    {
        (*this)(coord);
    }
    
    template<class FieldType>
    void PField::eval_grad( const Coordinate &coord)
    {
        for( int di=0; di<coord.size(); di++)
            (*this).grad(coord, di);
    }
    
    template<class FieldType>
    void PField::eval_hess( const Coordinate &coord)
    {
        for( int di=0; di<coord.size(); di++)
            for( int dj=0; dj<coord.size(); dj++)
                (*this).grad(coord, di, dj);
    }
    
    template<class FieldType>
    void PField::operator()() const
    {
        return _val;
    }
    
    template<class FieldType>
    void PField::eval_grad( int di) const
    {
        return _grad_val[di];
    }
    
    template<class FieldType>
    void PField::eval_hess( int di, int dj) const
    {
        return _hess_val[di][dj];
    }

}


#endif