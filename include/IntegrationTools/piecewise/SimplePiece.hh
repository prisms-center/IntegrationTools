
#ifndef SimplePiece_HH
#define SimplePiece_HH

#include<iostream>
#include<vector>

#include "./Condition.hh"
#include "../pfunction/PSimpleFunction.hh"

namespace PRISMS
{   
    /// Class to contain a SimpleFunction and the piece in which it is valid.
    /// 
    ///   This can be evaluated in or out of the piece in which it is declared valid
    ///
    template< class VarContainer, class OutType>
    class SimplePiece : public PSimpleBase<VarContainer, OutType> 
    {
        protected:
        
        PSimpleFunction<VarContainer, OutType> _expr;
        mutable std::vector< Condition<VarContainer, OutType> > _condition;
        
        public:
        
        SimplePiece( const PSimpleFunction<VarContainer, OutType> &expr, const std::vector<Condition<VarContainer, OutType> > &condition)
        {
            _expr = expr;
            this->_name = _expr.name();
        }
        
        virtual SimplePiece<VarContainer, OutType>* clone() const
        {
            return new SimplePiece<VarContainer, OutType>(*this);
        }
        
        bool in_piece( const VarContainer &var) const
        {
            for( int i=0; i<_condition.size(); i++)
            {
                if( _condition[i].is_false(var) )
                    return false;
            }
            return true;
        }
        
        PSimpleFunction<VarContainer, OutType> expr() const
        {
            return _expr;
        }
        
        std::vector< Condition<VarContainer, OutType> > condition() const
        {
            return _condition;
        }
        
        private:
        
        /// This will return '_expr' evaluated anywhere. Must check in_piece first. We
        ///    don't check it here to avoid double checking when evaluating PPieceWiseSimpleBase
        ///
        virtual OutType eval( const VarContainer &var) 
        { 
            return this->_val = _expr(var);
        }
    };

}


#endif