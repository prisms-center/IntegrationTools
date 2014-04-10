
#ifndef PPieceWiseSimpleBase_HH
#define PPieceWiseSimpleBase_HH

#include<iostream>
#include<vector>
#include<stdexcept>

#include "../pfunction/PSimpleBase.hh"
#include "./SimplePiece.hh"

namespace PRISMS
{
    /// Class to define a PieceWise SimpleFunction
    /// 
    ///   Contains a vector of 'SimplePiece'. Throws a domain_error if it 
    ///   is evaluated outside of the valid domain of any piece.
    ///
    template< class VarContainer, class OutType>
    class PPieceWiseSimpleBase : public PSimpleBase<VarContainer, OutType> 
    {
        public:
        
        std::vector<SimplePiece<VarContainer, OutType> > _piece;
        
        PPieceWiseSimpleBase() {}
        
        PPieceWiseSimpleBase( const std::vector<SimplePiece<VarContainer, OutType> > &piece)
        {
            _piece = piece;
        }
        
        virtual PPieceWiseSimpleBase<VarContainer, OutType>* clone() const
        {
            return new PPieceWiseSimpleBase<VarContainer, OutType>(*this);
        }
        
        bool in_piece( const VarContainer &var) const
        {
            for( int i=0; i<_piece.size(); i++)
            {
                if( _piece[i].in_piece(var) )
                    return true;
            }
            return false;
        }
        
        int piece(const VarContainer &var)
        {
            for( int i=0; i<_piece.size(); i++)
            {
                if( _piece[i].in_piece(var))
                    return i;
            }
            
            throw std::domain_error("PPieceWiseSimpleBase: Not in any piece");
        }
        
        private:
        virtual OutType eval( const VarContainer &var) 
        { 
            for( int i=0; i<_piece.size(); i++)
            {
                if( _piece[i].in_piece(var))
                    return this->_val = _piece[i](var);
            }
            
            throw std::domain_error("PPieceWiseSimpleBase: Not in any piece");
        }
    };
}


#endif