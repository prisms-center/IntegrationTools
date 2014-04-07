
#ifndef PSimpleBase_HH
#define PSimpleBase_HH

#include<cstring>
#include<iostream>
#include<vector>
#include<cstdlib>

namespace PRISMS
{

    /// Base classes for functions that can be hard-coded,
    ///   then shared and used elsewhere
    
    /// A simple expression evaluator
    ///
    template< class VarContainer, class OutType>
    class PSimpleBase
    {
    protected:
        std::string _name;
        OutType _val;
        
    public:
        std::string name() const { return _name;}
        OutType operator()( const VarContainer &var){ return _val = eval(var);}
        OutType operator()() const { return _val;}
        
        void is_derived_from_PSimpleBase() const
        {
            return;
        }
        
        virtual PSimpleBase<VarContainer, OutType>* clone() const
        {
            return new PSimpleBase<VarContainer, OutType>(*this);
        }
        
        private:
        virtual OutType eval( const VarContainer &var) const { undefined("OutType eval( const VarContainer &var)"); return OutType();}
        
        void undefined(std::string fname) const
        {
            std::cout << "Error in PSimpleBase '" << _name << "'." << std::endl;
            std::cout << "   The member function '" << fname << "' has not been defined." << std::endl;
            exit(1);
        }
    };

}


#endif