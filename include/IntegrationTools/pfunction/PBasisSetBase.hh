
#ifndef PBasisSetBase_HH
#define PBasisSetBase_HH

#include<cstring>
#include<iostream>
#include<vector>
#include<limits>

#include "./PFunction.hh"

namespace PRISMS
{
    /// Evaluate basis functions and their derivatives. Store and access the results.
    ///
    template< class InType, class OutType>
    class PBasisSetBase
    {
        public:
        
        std::string _name;
        std::string _description;
        
        std::vector<OutType> _val;
        std::vector<OutType> _grad_val;
        std::vector<OutType> _hess_val;
        
        std::string name() const
        {
            return _name;
        }
        std::string description() const
        {
            return _description;
        }
        int size() const
        {
            return _val.size();
        }
        
        PBasisSetBase( int N)
        {
            resize(N);
        }
        
        void is_derived_from_PBasisSetBase() const
        {
            return;
        }
        
        virtual void resize( int N)
        {
            _val.resize(N);
            _grad_val.resize(N);
            _hess_val.resize(N);
        }
        
        virtual ~PBasisSetBase()
        {
            
        }
        
        virtual int max_size()
        {
            // default to (essentially) no limit
            return std::numeric_limits<int>::max();
        }
        
        virtual PBasisSetBase<InType,OutType>* clone() const
        {
            return new PBasisSetBase<InType, OutType>(*this);
        }
        
        virtual PFunction<InType, OutType> basis_function(int term) const
        {
            undefined("const PFunction<InType, OutType>& basis_function(int term) const");
            return PFunction<InType, OutType>();
        }
        
        // ----------------------------------------------------------
        // Use these functions if you want to evaluate a single value
        OutType operator()(int term, const InType &var)
        {
            return _val[term] = eval(term, var);
        }
        OutType grad(int term, const InType &var)
        {
            return _grad_val[term] = eval_grad(term, var);
        }
        OutType hess(int term, const InType &var)
        {
            return _hess_val[term] = eval_hess(term, var);
        }
        

        // ----------------------------------------------------------
        // Use these functions to evaluate several values, then use 'get' methods to access results
        
        // By default, evaluate each individual term one-by-one. 
        // These are virtual so derived classes may implement more efficient methods.
        //    Returns vector containing results
        virtual const std::vector<OutType>& eval(const InType &var)
        {
            for( int i=0; i<_val.size(); i++)
                (*this)(i,var);
            return _val;
        }
        virtual const std::vector<OutType>& eval_grad(const InType &var)
        {
            for( int i=0; i<_val.size(); i++)
                (*this).grad(i,var);
            return _grad_val;
        }
        virtual const std::vector<OutType>& eval_hess(const InType &var)
        {
            for( int i=0; i<_val.size(); i++)
                (*this).hess(i,var);
            return _hess_val;
        }

        // Getters for individual terms
        OutType operator()(int term) const
        {
            return _val[term];
        }
        OutType grad(int term) const
        {
            return _grad_val[term];
        }
        OutType hess(int term) const
        {
            return _hess_val[term];
        }
        
        // Getters returning vector containing all terms
        const std::vector<OutType>& operator()() const
        {
            return _val;
        }
        const std::vector<OutType>& grad() const
        {
            return _grad_val;
        }
        const std::vector<OutType>& hess() const
        {
            return _hess_val;
        }

    private:
        
        /// ----------------------------------------------------------
        /// !!! Derived classes must define these functions !!!
        ///   Usually this is done using PBasisSetWriter
        virtual OutType eval(int term, const InType &var)
        {
            undefined("OutType PBasisSetBase::eval(int term, const InType &var)");
            return OutType();
        }
        virtual OutType eval_grad(int term, const InType &var)
        {
            undefined("OutType PBasisSetBase::eval_grad(int term, const InType &var)");
            return OutType();
        }
        virtual OutType eval_hess(int term, const InType &var)
        {
            undefined("OutType PBasisSetBase::eval_hess(int term, const InType &var)");
            return OutType();
        }
    
        void undefined(std::string fname) const
        {
            std::cout << "Error. In PBasisSetBase '" << _name << "'." << std::endl;
            std::cout << "   The member function '" << fname << "' has not been defined." << std::endl;
            exit(1);
        }
    };

}


#endif