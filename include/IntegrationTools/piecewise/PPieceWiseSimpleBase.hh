
#ifndef PPieceWiseSimpleBase_HH
#define PPieceWiseSimpleBase_HH

#include<iostream>
#include<vector>
#include<stdexcept>

#include "../pfunction/PSimpleBase.hh"
#include "./SimpleRegion.hh"

namespace PRISMS
{
    /// Class to define a PieceWise SimpleFunction
    /// 
    ///   Contains a vector of 'SimpleRegion'. Throws a domain_error if it 
    ///   is evaluated outside of the valid domain of any region.
    ///
    template< class VarContainer, class OutType>
    class PPieceWiseSimpleBase : public PSimpleBase<class VarContainer, class OutType> 
    {
        public:
        
        std::vector<SimpleRegion<VarContainer, OutType> > _region;
        
        PPieceWiseSimpleBase( const std::vector<SimpleRegion<VarContainer, OutType> > &region)
        {
            _region = region;
        }
        
        virtual PPieceWiseSimpleBase<VarContainer, OutType>* clone() const
        {
            return new PPieceWiseSimpleBase<VarContainer, OutType>(*this);
        }
        
        bool in_region( const VarContainer &var) const
        {
            for( int i=0; i<_region.size(); i++)
            {
                if( _region[i].in_region(var) )
                    return true;
            }
            return false;
        }
        
        int region(const VarContainer &var)
        {
            for( int i=0; i<_region.size(); i++)
            {
                if( _region[i].in_region(var))
                    return i;
            }
            
            throw std::domain_error("PPieceWiseSimpleBase: Not in any region");
        }
        
        private:
        virtual OutType eval( const VarContainer &var) 
        { 
            for( int i=0; i<_region.size(); i++)
            {
                if( _region[i].in_region(var))
                    return _val = _region[i](var);
            }
            
            throw std::domain_error("PPieceWiseSimpleBase: Not in any region");
        }
    };
}


#endif