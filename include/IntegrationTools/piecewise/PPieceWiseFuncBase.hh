
#ifndef PPieceWiseFuncBase_HH
#define PPieceWiseFuncBase_HH

#include<iostream>
#include<vector>
#include<stdexcept>

#include "../pfunction/PFuncBase.hh"
#include "./SimpleRegion.hh"
#include "./PPieceWiseSimpleBase.hh"
#include "./Region.hh"

namespace PRISMS
{   
    
    /// Class to define a PieceWise Function
    /// 
    ///   Contains a vector of 'Region'. Throws a domain_error if it 
    ///   is evaluated outside of the valid domain of any region.
    ///
    template< class VarContainer, class OutType>
    class PPieceWiseFuncBase : public PFuncBase<class VarContainer, class OutType> 
    {
        public:
        
        std::vector<Region<VarContainer, OutType> > _region;
        
        PPieceWiseFuncBase( const std::vector<Region<VarContainer, OutType> > &region)
        {
            _region = region;
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
            
            throw std::domain_error("PPieceWiseFuncBase: Not in any region");
        }
        
        virtual PPieceWiseFuncBase<VarContainer, OutType> *clone() const
        {
            return new PPieceWiseFuncBase<VarContainer, OutType>(*this);
        }
        
        virtual PPieceWiseSimpleBase<VarContainer, OutType> simplefunction() const
        {
            std::vector<SimpleRegion<VarContainer, OutType> > region;
            
            for( int i=0; i<_region.size(); i++)
            {
                region.push_back( _region.simplefunction());
            }
            
            return PPieceWiseSimpleBase<VarContainer, OutType>(region);
        }
        
        virtual PPieceWiseSimpleBase<VarContainer, OutType> grad_simplefunction(int di) const
        {
            std::vector<SimpleRegion<VarContainer, OutType> > region;
            
            for( int i=0; i<_region.size(); i++)
            {
                region.push_back( _region.grad_simplefunction(di));
            }
            
            return PPieceWiseSimpleBase<VarContainer, OutType>(region);
        }
        
        virtual PPieceWiseSimpleBase<VarContainer, OutType> hess_simplefunction(int di, int dj) const
        {
            std::vector<SimpleRegion<VarContainer, OutType> > region;
            
            for( int i=0; i<_region.size(); i++)
            {
                region.push_back( _region.hess_simplefunction(di, dj) );
            }
            
            return PPieceWiseSimpleBase<VarContainer, OutType>(region);
        }

        // ----------------------------------------------------------
        // Use these functions if you want to evaluate a single value
        
        virtual OutType operator()(const VarContainer &var)
        {
            for( int i=0; i<_region.size(); i++)
            {
                if( _region[i].in_region(var))
                    return _expr(var);
            }
            
            throw std::domain_error("PPieceWiseFuncBase: Not in any region");
        }
        virtual OutType grad(const VarContainer &var, int di)
        {
            for( int i=0; i<_region.size(); i++)
            {
                if( _region[i].in_region(var))
                    return _expr.grad(var, di);
            }
            
            throw std::domain_error("PPieceWiseFuncBase: Not in any region");
        }
        virtual OutType hess(const VarContainer &var, int di, int dj)
        {
            for( int i=0; i<_region.size(); i++)
            {
                if( _region[i].in_region(var))
                    return _expr.hess(var, di, dj);
            }
            
            throw std::domain_error("PPieceWiseFuncBase: Not in any region");
        }

        // ----------------------------------------------------------
        // Use these functions to evaluate several values, then use 'get' methods to access results
        virtual void eval(const VarContainer &var)
        {
            for( int i=0; i<_region.size(); i++)
            {
                if( _region[i].in_region(var))
                    return _expr(var);
            }
            
            throw std::domain_error("PPieceWiseFuncBase: Not in any region");
        }
        virtual void eval_grad(const VarContainer &var)
        {
            for( int i=0; i<_region.size(); i++)
            {
                if( _region[i].in_region(var))
                    return _expr.eval_grad(var);
            }
            
            throw std::domain_error("PPieceWiseFuncBase: Not in any region");
        }
        virtual void eval_hess(const VarContainer &var)
        {
            for( int i=0; i<_region.size(); i++)
            {
                if( _region[i].in_region(var))
                    return _expr.eval_hess(var);
            }
            
            throw std::domain_error("PPieceWiseFuncBase: Not in any region");
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