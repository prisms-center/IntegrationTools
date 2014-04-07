
#ifndef PFuncBase_HH
#define PFuncBase_HH

#include<cstring>
#include<iostream>
#include<vector>
#include<cstdlib>

#include "./PSimpleFunction.hh"

namespace PRISMS
{    
    /// A Base class for a function, including grad & hess
    /// 
    template< class VarContainer, class OutType>
    class PFuncBase
    {
    protected:
        std::string _name;
        std::vector<std::string> _var_name;
        std::vector<std::string> _var_description;
        
    public:
        
        PFuncBase(){}
        
        PFuncBase( const std::string &name,
                  const std::vector<std::string> &var_name,
                  const std::vector<std::string> &var_description) :
                  _name(name), _var_name(var_name), _var_description(var_description)
        {
        
        }
        
        virtual ~PFuncBase(){}

        std::string name()
        {
            return _name;
        }
        int size() const
        {
            return _var_name.size();
        }
        std::string var_name(int i)
        {
            return _var_name[i];
        }
        std::string var_description(int i)
        {
            return _var_description[i];
        }

        void is_derived_from_PFuncBase() const
        {
            return;
        }

        virtual PFuncBase<VarContainer, OutType> *clone() const
        {
            return new PFuncBase<VarContainer, OutType>(*this);
        }
        
        virtual PSimpleFunction<VarContainer, OutType> simplefunction() const
        {
            undefined("PSimpleFunction<VarContainer, OutType> simplefunction() const");
            return PSimpleFunction<VarContainer, OutType>();
        }
        
        virtual PSimpleFunction<VarContainer, OutType> grad_simplefunction(int di) const
        {
            undefined("PSimpleFunction<VarContainer, OutType> grad_simplefunction() const");
            return PSimpleFunction<VarContainer, OutType>();
        }
        
        virtual PSimpleFunction<VarContainer, OutType> hess_simplefunction(int di, int dj) const
        {
            undefined("PSimpleFunction<VarContainer, OutType> hess_simplefunction(int di, int dj) const");
            return PSimpleFunction<VarContainer, OutType>();
        }

        // ----------------------------------------------------------
        // Use these functions if you want to evaluate a single value
        virtual OutType operator()(const VarContainer &var)
        {
            undefined("OutType operator()(const VarContainer &var)");
            return OutType();
        }
        virtual OutType grad(const VarContainer &var, int di)
        {
            undefined("OutType grad(const VarContainer &var, int di)");
            return OutType();
        }
        virtual OutType hess(const VarContainer &var, int di, int dj)
        {
            undefined("OutType hess(const VarContainer &var, int di, int dj)");
            return OutType();
        }

        // ----------------------------------------------------------
        // Use these functions to evaluate several values, then use 'get' methods to access results
        virtual void eval(const VarContainer &var)
        {
            undefined("void eval_grad( const VarContainer &var)");
        }
        virtual void eval_grad(const VarContainer &var)
        {
            undefined("void eval_grad( const VarContainer &var)");
        }
        virtual void eval_hess(const VarContainer &var)
        {
            undefined("void eval_hess( const VarContainer &var)");
        }

        virtual OutType operator()() const
        {
            undefined("OutType operator()");
            return OutType();
        }
        virtual OutType grad(int di) const
        {
            undefined("OutType grad(int di)");
            return OutType();
        }
        virtual OutType hess(int di, int dj) const
        {
            undefined("OutType hess(int di, int dj)");
            return OutType();
        }

    private:
        void undefined(std::string fname) const
        {
            std::cout << "Error in PFuncBase '" << _name << "'." << std::endl;
            std::cout << "   The member function '" << fname << "' has not been defined." << std::endl;
            exit(1);
        }

    };

}


#endif