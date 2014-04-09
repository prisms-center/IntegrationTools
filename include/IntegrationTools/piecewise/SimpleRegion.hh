
#ifndef SimpleRegion_HH
#define SimpleRegion_HH

#include<iostream>
#include<vector>

#include "./Condition.hh"
#include "../pfunction/PSimpleFunction.hh"

namespace PRISMS
{   
    /// Class to contain a SimpleFunction and the region in which it is valid.
    /// 
    ///   This can be evaluated in or out of the region in which it is declared valid
    ///
    template< class VarContainer, class OutType>
    class SimpleRegion : public PSimpleBase<class VarContainer, class OutType> 
    {
        protected:
        
        OutType _zero;
        PSimpleFunction<VarContainer, OutType> _expr;
        std::vector< Condition<VarContainer, OutType> > _condition;
        
        public:
        
        SimpleRegion( const PSimpleFunction<VarContainer, OutType> &RHS, const std::vector<Condition<VarContainer, OutType> &condition, const OutType &zero)
        {
            _expr = RHS;
            _zero = zero;
            _name = _expr._name;
        }
        
        virtual SimpleRegion<VarContainer, OutType>* clone() const
        {
            return new SimpleRegion<VarContainer, OutType>(*this);
        }
        
        bool in_region( const VarContainer &var) const
        {
            for( int i=0; i<_condition.size(); i++)
            {
                if( _condition[i].is_false(var) )
                    return false;
            }
            return true;
        }
        
        private:
        
        /// This will return '_expr' evaluated anywhere. Must check in_region first. We
        ///    don't check it here to avoid double checking when evaluating PPieceWiseSimpleBase
        ///
        virtual OutType eval( const VarContainer &var) 
        { 
            return _val = _expr(var);
        }
    };

}


#endif