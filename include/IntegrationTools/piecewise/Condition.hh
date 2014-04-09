
#ifndef Condition_HH
#define Condition_HH

#include<iostream>
#include<string>
#include<stdexcept>

#include "../pfunction/PSimpleFunction.hh"

namespace PRISMS
{   
    
    template< class VarContainer, class OutType>
    class Condition
    {
        enum COMPARISON {GT, GE, LT, LE, EQ, NE};
        
        PSimpleFunction<VarContainer, OutType> _lhs;
        PSimpleFunction<VarContainer, OutType> _rhs;
        COMPARISON _operation;
        
        public:
        
        Condition( const PSimpleFunction<VarContainer, OutType> &lhs, COMPARISON operation, const PSimpleFunction<VarContainer, OutType> &rhs)
        {
            _lhs = lhs;
            _operation = operation;
            _rhs = rhs;
        }
        
        Condition( std::string operation)
        {
            _lhs = lhs;
            _rhs = rhs;
            _operation = Condtion::get_operation( operation);
        }
        
        static COMPARISON get_operation( std::string operation)
        {
            if(operation == "gt" || operation == "GT")
            {
                return GT;
            }
            else if(operation == "ge" || operation == "GE")
            {
                return GE;
            }
            else if(operation == "lt" || operation == "LT")
            {
                return LT;
            }
            else if(operation == "le" || operation == "LE")
            {
                return LE;
            }
            else if(operation == "eq" || operation == "EQ")
            {
                return EQ;
            }
            else if(operation == "ne" || operation == "NE")
            {
                return NE;
            }
            
            throw std::invalid_argument(operation);
        }
        
        bool is_true( const VarContainer &var)
        {
            switch (_operation)
            {
                case GT:
                    return _lhs(var) > _rhs(var);
                case GE:
                    return _lhs(var) >= _rhs(var);
                case LT:
                    return _lhs(var) < _rhs(var);
                case LE:
                    return _lhs(var) <= _rhs(var);
                case EQ:
                    return _lhs(var) == _rhs(var);
                case NE:
                    return _lhs(var) != _rhs(var);
                default:
                    throw std::invalid_argument(_operation);
            }
        }
        
        bool is_false( const VarContainer &var)
        {
            return !is_true(var);
        }
    };

}


#endif