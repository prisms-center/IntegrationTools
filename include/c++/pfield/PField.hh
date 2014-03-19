
#ifndef PFIELD_HH
#define PFIELD_HH

namespace PRISMS
{
    class PInterpolator
    {
        
        template<class FieldType>
        
    }
    
    template<class FieldType>
    class LinearInterpolator : public PInterpolatorBase
    {
        template<class FieldType>
        FieldType operator()(const PField<FieldType> &field, const PElement &element, const Coordinate &var);
        
        template<class FieldType>
        FieldType grad()(const PField<FieldType> &field, const PElement &element, const Coordinate &var, int di);
        
        template<class FieldType>
        FieldType hess()(const PField<FieldType> &field, const PElement &element, const Coordinate &var, int di, int dj);
    }
    
    class PNode
    {
        Coordinate        coord;
        
        // Array of elements containing the node
        PElement* *element;
    }
    
    class PElement
    {
        // array of ptrs to nodes
        PNode*                      *node;
        
        // ptr to Interpolator functor, ownership either at grid or element level
        PInterpolator               *interpolator;
        
        // Similar to a PFuncBase, but also must check if element contains point, node, and return nodes
        
        
        operator()(
        
    }
    
    class PGrid
    {
        // array of nodes
        PNode* _node;
        
        // array of elements
        PElement* _element;
        
        // bin to help find element containing point
        Bin bin;
        
        // given a point, return the element that contains it
        PFuncBase* element( const VarContainer &point, PFieldBase* field)
        {
            // find element containing point
            
            // set field of element to field
            
            // return element
        }
    }
    
    
    class PFieldBase
    {
        // pointer to grid
        PGrid *_grid;
        
        virtual operator[](int i)=0;
    
    };
    
    /// A class for a field
    ///
    ///   Varcontainer contains variables, for instance 'std::vector<double>' for x, y, z
    ///   FieldType is the datatype for the field, 
    ///       for instance 'double' for temperature or 'std::vector<double>' for vector displacement
    ///
    ///   A field consists of a Grid
    template< class FieldType>
    class PField : public PFieldBase
    {
    public:
    
        // array of field values at grid nodes
        FieldType* _field;
        
        operator[]
        
        // ----------------------------------------------------------
        // Use these functions if you want to evaluate a single value
        FieldType operator()(const Coordinate &var);
        FieldType grad(const Coordinate &var, int di);
        FieldType hess(const Coordinate &var, int di, int dj);
        
        // PField unique members ------------------------------------------

    private:
        

    };
    
    template< class VarContainer, class FieldType>
    FieldType PField::operator()( const VarContainer &var)
    {
        return _grid->element(var, this)->( var);
    }
    
    template< class VarContainer, class FieldType>
    FieldType PField::grad( const VarContainer &var, int di)
    {
        return _grid->element(var, this)->grad( var, di);
    }
    
    template< class VarContainer, class FieldType>
    FieldType PField::hess( const VarContainer &var, int di, int dj)
    {
        return _grid->element(var, this)->hess( var, di, dj);
    }
    
    
    namespace FieldIO
    {
        
        template< class VarContainer, class IndexContainer> 
        read_VTK( std::string filename, 
                  PGrid *grid,
                  VarContainer tmp,
                  std::vector< PField<VarContainer, double> > &scalar_field, 
                  std::vector< PField<VarContainer, PTensor<IndexContainer, double> > &tensor_field);
        
        template< class VarContainer, class IndexContainer> 
        write_VTK(std::string filename, 
                  PGrid &grid, 
                  VarContainer tmp, 
                  std::vector< PField<VarContainer, double> > &scalar_field, 
                  std::vector< PField<VarContainer, PTensor<IndexContainer, double> > &tensor_field);
    }

}


#endif