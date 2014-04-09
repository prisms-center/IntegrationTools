
#ifndef PPieceWiseFuncBase_HH
#define PPieceWiseFuncBase_HH

#include<iostream>
#include<vector>
#include<stdexcept>

#include "../pfunction/PFuncBase.hh"
#include "./SimplePiece.hh"
#include "./PPieceWiseSimpleBase.hh"
#include "./Piece.hh"

namespace PRISMS
{   
    
    /// Class to define a PieceWise Function
    /// 
    ///   Contains a vector of 'Piece'. Throws a domain_error if it 
    ///   is evaluated outside of the valid domain of any piece.
    ///
    template< class VarContainer, class OutType>
    class PPieceWiseFuncBase : public PFuncBase<class VarContainer, class OutType> 
    {
        public:
        
        std::vector<Piece<VarContainer, OutType> > _piece;
        
        PPieceWiseFuncBase( const std::vector<Piece<VarContainer, OutType> > &piece)
        {
            _piece = piece;
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
            
            throw std::domain_error("PPieceWiseFuncBase: Not in any piece");
        }
        
        virtual PPieceWiseFuncBase<VarContainer, OutType> *clone() const
        {
            return new PPieceWiseFuncBase<VarContainer, OutType>(*this);
        }
        
        virtual PPieceWiseSimpleBase<VarContainer, OutType> simplefunction() const
        {
            std::vector<SimplePiece<VarContainer, OutType> > piece;
            
            for( int i=0; i<_piece.size(); i++)
            {
                piece.push_back( _piece.simplefunction());
            }
            
            return PPieceWiseSimpleBase<VarContainer, OutType>(piece);
        }
        
        virtual PPieceWiseSimpleBase<VarContainer, OutType> grad_simplefunction(int di) const
        {
            std::vector<SimplePiece<VarContainer, OutType> > piece;
            
            for( int i=0; i<_piece.size(); i++)
            {
                piece.push_back( _piece.grad_simplefunction(di));
            }
            
            return PPieceWiseSimpleBase<VarContainer, OutType>(piece);
        }
        
        virtual PPieceWiseSimpleBase<VarContainer, OutType> hess_simplefunction(int di, int dj) const
        {
            std::vector<SimplePiece<VarContainer, OutType> > piece;
            
            for( int i=0; i<_piece.size(); i++)
            {
                piece.push_back( _piece.hess_simplefunction(di, dj) );
            }
            
            return PPieceWiseSimpleBase<VarContainer, OutType>(piece);
        }

        // ----------------------------------------------------------
        // Use these functions if you want to evaluate a single value
        
        virtual OutType operator()(const VarContainer &var)
        {
            for( int i=0; i<_piece.size(); i++)
            {
                if( _piece[i].in_piece(var))
                    return _expr(var);
            }
            
            throw std::domain_error("PPieceWiseFuncBase: Not in any piece");
        }
        virtual OutType grad(const VarContainer &var, int di)
        {
            for( int i=0; i<_piece.size(); i++)
            {
                if( _piece[i].in_piece(var))
                    return _expr.grad(var, di);
            }
            
            throw std::domain_error("PPieceWiseFuncBase: Not in any piece");
        }
        virtual OutType hess(const VarContainer &var, int di, int dj)
        {
            for( int i=0; i<_piece.size(); i++)
            {
                if( _piece[i].in_piece(var))
                    return _expr.hess(var, di, dj);
            }
            
            throw std::domain_error("PPieceWiseFuncBase: Not in any piece");
        }

        // ----------------------------------------------------------
        // Use these functions to evaluate several values, then use 'get' methods to access results
        virtual void eval(const VarContainer &var)
        {
            for( int i=0; i<_piece.size(); i++)
            {
                if( _piece[i].in_piece(var))
                    return _expr(var);
            }
            
            throw std::domain_error("PPieceWiseFuncBase: Not in any piece");
        }
        virtual void eval_grad(const VarContainer &var)
        {
            for( int i=0; i<_piece.size(); i++)
            {
                if( _piece[i].in_piece(var))
                    return _expr.eval_grad(var);
            }
            
            throw std::domain_error("PPieceWiseFuncBase: Not in any piece");
        }
        virtual void eval_hess(const VarContainer &var)
        {
            for( int i=0; i<_piece.size(); i++)
            {
                if( _piece[i].in_piece(var))
                    return _expr.eval_hess(var);
            }
            
            throw std::domain_error("PPieceWiseFuncBase: Not in any piece");
        }
        
        /// These don't recheck the domain
        virtual OutType operator()() const
        {
            return _expr();
        }
        virtual OutType grad(int di) const
        {
            return _expr.grad(di);
        }
        virtual OutType hess(int di, int dj) const
        {
            return _expr.hess(di, dj);
        }
    };

}


#endif