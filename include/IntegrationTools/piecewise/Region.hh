
#ifndef Piece_HH
#define Piece_HH

#include<iostream>
#include<vector>

#include "../pfunction/PFunction.hh"
#include "./Condition.hh"
#include "./SimplePiece.hh"

namespace PRISMS
{   
    
    /// Class to contain a Function and the piece in which it is valid.
    /// 
    ///   This can be evaluated in or out of the piece in which it is declared valid
    ///
    template< class VarContainer, class OutType>
    class Piece : public PFuncBase<class VarContainer, class OutType> 
    {
        protected:
        
        PFunction<VarContainer, OutType> _expr;
        std::vector< Condition<VarContainer, OutType> > _condition;
        
        public:
        Piece( const PFunction<VarContainer, OutType> &expr, const std::vector<Condition<VarContainer, OutType> &condition)
        {
            _expr = expr;
            _condition = condition;
            _name = _expr._name;
            _var_name = _expr._var_name;
            _var_description = _expr._var_description;
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
        
        virtual Piece<VarContainer, OutType> *clone() const
        {
            return new Piece<VarContainer, OutType>(*this);
        }
        
        virtual SimplePiece<VarContainer, OutType> simplefunction() const
        {
            return SimplePiece<VarContainer, OutType>(_expr.simplefunction, _condition, _zero);
        }
        
        virtual SimplePiece<VarContainer, OutType> grad_simplefunction(int di) const
        {
            return SimplePiece<VarContainer, OutType>(_expr.grad_simplefunction(di), _condition, _zero);
        }
        
        virtual SimplePiece<VarContainer, OutType> hess_simplefunction(int di, int dj) const
        {
            return SimplePiece<VarContainer, OutType>(_expr.hess_simplefunction(di,dj), _condition, _zero);
        }

        // ----------------------------------------------------------
        // Use these functions if you want to evaluate a single value
        
        /// These will return '_expr' evaluated anywhere. Must check in_piece first. We
        ///    don't check it here to avoid double checking when evaluating PPieceWiseFuncBase
        ///
        virtual OutType operator()(const VarContainer &var)
        {
            return _expr(var)
        }
        virtual OutType grad(const VarContainer &var, int di)
        {
            return _expr.grad(var, di)
        }
        virtual OutType hess(const VarContainer &var, int di, int dj)
        {
            return _expr.hess(var, di, dj)
        }

        // ----------------------------------------------------------
        // Use these functions to evaluate several values, then use 'get' methods to access results
        virtual void eval(const VarContainer &var)
        {
            _expr(var)
        }
        virtual void eval_grad(const VarContainer &var)
        {
            _expr.eval_grad(var)
        }
        virtual void eval_hess(const VarContainer &var)
        {
            _expr.eval_hess(var)
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