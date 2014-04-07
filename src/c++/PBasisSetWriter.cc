
#ifndef PBasisSetWriter_CC
#define PBasisSetWriter_CC

#include<cstring>
#include<iostream>
#include<sstream>
#include<vector>
#include<time.h>
#include<cstdlib>
#include <ginac/ginac.h>    // compile with: -lcln -lginac

#include "IntegrationTools/PSymFunction.hh"
#include "IntegrationTools/writer/PBasisSetWriter.hh"
#include "IntegrationTools/writer/PFunctionWriter.hh"
#include "IntegrationTools/version.hh"

namespace PRISMS
{
    // -- included in PFunctionWriter for now...
    /*
    // convert int to string
    std::string itos( int i)
    {
        std::stringstream ss;
        ss << i;
        return ss.str();
    }
    
    // return current date and time as: YEAR-MM-DD HH:MM:SS
    std::string now()
    {
        time_t t = time(0);   // get time now
        struct tm * _now = localtime( & t );
        std::ostringstream ss;
        
        std::string smin = "";
        int min = _now->tm_min;
        if( min < 10)
            smin = "0" + itos(min);
        else
            smin = itos(min);
        
        std::string ssec = "";
        int sec = _now->tm_sec;
        if( sec < 10)
            ssec = "0" + itos(sec);
        else
            ssec = itos(sec);
        
                
        ss << (_now->tm_year + 1900) << '-' 
             << (_now->tm_mon + 1) << '-'
             <<  _now->tm_mday
             << " " << _now->tm_hour << ":" << smin << ":" << ssec;
        return ss.str();
        
    }
    */

    PBasisSetWriter::PBasisSetWriter(const std::string &name, const std::string &description)
    {
        _name = name;
        _description = description;
        
        // set defaults:
        phi_on();
        grad_on();
        hess_on();
        set_basic_indent("    ");
        set_types("double", "double");
    }
    
    void PBasisSetWriter::set_basic_indent( std::string basic_indent)
    {
        _basic_indent = basic_indent;
    }
    
    void PBasisSetWriter::set_intype(std::string intype)
    {
        _intype = intype;
    }
    
    void PBasisSetWriter::set_outtype(std::string outtype)
    {
        _outtype = outtype;
    }
    
    void PBasisSetWriter::set_types( std::string intype, std::string outtype)
    {
        _intype = intype;
        _outtype = outtype;
    }
    
    void PBasisSetWriter::phi_on()
    {
        _write_phi = true;
    }
    
    void PBasisSetWriter::phi_off()
    {
        _write_phi = false;
    }
    
    void PBasisSetWriter::grad_on()
    {
        _write_grad = true;
    }
    
    void PBasisSetWriter::grad_off()
    {
        _write_grad = false;
    }
    
    void PBasisSetWriter::hess_on()
    {
        _write_hess = true;
    }
    
    void PBasisSetWriter::hess_off()
    {
        _write_hess = false;
    }
    
    void PBasisSetWriter::sym2code(     std::string f, 
                              std::string var, 
                              std::string index,
                              int N,
                              std::ostream &sout)
    {
        _phi.clear();
        _grad.clear();
        _hess.clear();
        
        // create a symbolic basis set
        
        // create GiNaC symbols & expression parser
        GiNaC::symbol symvar("var"), symindex("i");
        GiNaC::symtab table;
        table[ var] = symvar;
        table[ index] = symindex;
        GiNaC::parser reader(table,true);
        
        // create generating GiNaC expression
        GiNaC::ex e_gen;
        try
        {
            e_gen = reader(f);
        }
        catch (std::invalid_argument& err)
        {
            throw err;
        }
        
        // create recursive symbolic basis set
        PRISMS::PRealSymBasisSet bset( N, symindex, symvar, e_gen);
        
        // generate phi
        if( _write_phi)
        {
            for( int i=0; i<N; i++)
            {
                PRISMS::PRealSymBasisFunction* bf;
                bf = bset.clone_basis_function(i);
                
                std::ostringstream ss;
                ss << GiNaC::csrc_double << bf->_e;    
                
                _phi.push_back( ss.str());
                
                delete bf;
            }
        }
        
        // generate grad
        if( _write_grad)
        {
            for( int i=0; i<N; i++)
            {
                PRISMS::PRealSymBasisFunction* bf;
                bf = bset.clone_grad_basis_function(i);
                
                std::ostringstream ss;
                ss << GiNaC::csrc_double << bf->_e;    
                
                _grad.push_back( ss.str());
                
                delete bf;
            }
        }
        
        // generate hess
        if( _write_hess)
        {
            for( int i=0; i<N; i++)
            {
                PRISMS::PRealSymBasisFunction* bf;
                bf = bset.clone_hess_basis_function(i);
                
                std::ostringstream ss;
                ss << GiNaC::csrc_double << bf->_e;    
                
                _hess.push_back( ss.str());
                
                delete bf;
            }
        }
        
        head(sout);
        code(sout);
        foot(sout);
        
    }
    
    void PBasisSetWriter::sym2code( std::string f, 
                              std::string var, 
                              const std::vector<std::string> &phi_init,
                              const std::vector<std::string> &phi_sym,
                              int N,
                              std::ostream &sout)
    {
        _phi.clear();
        _grad.clear();
        _hess.clear();
        
        // create a symbolic basis set
        
        // create GiNaC symbols & expression parser
        std::vector<GiNaC::symbol> symvec( phi_sym.size() + 1);
        GiNaC::symtab table;
        for( int i=0; i<phi_sym.size(); i++)
        {
            symvec[i] = GiNaC::symbol(phi_sym[i]);
            table[ phi_sym[i]] = symvec[i];
        }
        symvec[ phi_sym.size()] = GiNaC::symbol("var");
        table[ var] = symvec[ phi_sym.size()];
        GiNaC::parser reader(table, true);
        
        // create list of phi_sym GiNaC symbols
        std::vector<GiNaC::symbol> tphi_sym( phi_sym.size());
        for( int i=0; i<phi_sym.size(); i++)
            tphi_sym[i] = symvec[i];
        
        // create list of phi_init GiNaC expression
        std::vector<GiNaC::ex> phi_ex_init( phi_init.size());
        for( int i=0; i<phi_init.size(); i++)
            phi_ex_init[i] = reader(phi_init[i]);
        
        // create generating GiNaC expression
        GiNaC::ex e_gen;
        try
        {
            e_gen = reader(f);
        }
        catch (std::invalid_argument& err)
        {
            throw err;
        }
        
        // create recursive symbolic basis set
        PRISMS::PRealSymRecursBasisSet bset( N, symvec[ phi_sym.size()], tphi_sym, phi_ex_init, e_gen);
        
        // generate phi
        if( _write_phi)
        {
            for( int i=0; i<N; i++)
            {
                PRISMS::PRealSymBasisFunction* bf;
                bf = bset.clone_basis_function(i);
                
                std::ostringstream ss;
                ss << GiNaC::csrc_double << bf->_e;    
                
                _phi.push_back( ss.str());
                
                delete bf;
            }
        }
        
        // generate grad
        if( _write_grad)
        {
            for( int i=0; i<N; i++)
            {
                PRISMS::PRealSymBasisFunction* bf;
                bf = bset.clone_grad_basis_function(i);
                
                std::ostringstream ss;
                ss << GiNaC::csrc_double << bf->_e;    
                
                _grad.push_back( ss.str());
                
                delete bf;
            }
        }
        
        // generate hess
        if( _write_hess)
        {
            for( int i=0; i<N; i++)
            {
                PRISMS::PRealSymBasisFunction* bf;
                bf = bset.clone_hess_basis_function(i);
                
                std::ostringstream ss;
                ss << GiNaC::csrc_double << bf->_e;    
                
                _hess.push_back( ss.str());
                
                delete bf;
            }
        }
        
        head(sout);
        code(sout);
        foot(sout);
    }
    
    /*
    void PBasisSetWriter::code( const std::string &json_str,  std::ostream &sout)
    {
    
    }
    */
    
    void PBasisSetWriter::code( 
      const std::vector<std::string> &phi, 
      const std::vector<std::string> &grad,
      const std::vector<std::string> &hess,
      std::ostream &sout)
    {
        _phi = phi;
        _grad = grad;
        _hess = hess;
        head(sout);
        code(sout);
        foot(sout);
    }
    
    
    //private:
        
    
    
    void PBasisSetWriter::write_basis_function(int I, const std::string &name, const std::string &f, std::ostream &sout) const
    {
        std::string PSimpleBaseTemplate = "PSimpleBase< " + _intype + ", " + _outtype + ">";
        
        sout << indent(I) << "class " + name + " : public " + PSimpleBaseTemplate + "\n";
        sout << indent(I) << "{\n";
        I++;
        sout << indent(I) << _outtype + " eval( const " + _intype + " &var) const\n";
        sout << indent(I) << "{\n";
        I++;
        sout << indent(I) << "return " + f + ";\n";
        I--;
        sout << indent(I) << "}\n\n";
        I--;
        sout << indent(I) << "public:\n";
        I++;
        sout << indent(I) << name + "* clone() const\n";
        sout << indent(I) << "{\n";
        I++;
        sout << indent(I) << "return new " + name + "(*this);\n";
        I--;
        sout << indent(I) << "}\n";
        I--;
        sout << indent(I) << "};\n\n";
    }
    
    
    
    
    // use polymorphic basis functions
    void PBasisSetWriter::code( 
      std::ostream &sout) const
    {
        int I = 1;
        std::string PBasisSetBaseTemplate = "PBasisSetBase<" + _intype + ", " + _outtype + ">";
        std::string PSimpleBaseTemplate = "PSimpleBase< " + _intype + ", " + _outtype + ">";
        std::string PSimpleFunctionTemplate = "PSimpleFunction< " + _intype + ", " + _outtype + ">";
        std::string PFunctionTemplate = "PFunction< " + _intype + ", " + _outtype + ">";
        
        
        // write function classes for phi, grad, hess
        
        
        if( _write_phi)
        {
            for( int i=0; i<_phi.size(); i++)
                write_basis_function(I, _name + "_" + itos(i), _phi[i], sout);
        }
        if( _write_grad)
        {
            for( int i=0; i<_grad.size(); i++)
                write_basis_function(I, _name + "_" + itos(i) + "_grad" , _grad[i], sout);
        }
        if( _write_hess)
        {
            for( int i=0; i<_hess.size(); i++)
                write_basis_function(I, _name + "_" + itos(i) + "_hess" , _hess[i], sout);
        }
        
        /*
        std::vector<std::string> var_name, var_description;
        var_name.push_back("x");
        var_description.push_back("x");
        
        for( int i=0; i<_phi.size(); i++)
        {
            PFunctionWriter writer( _name + "_" + itos(i));
            writer.set_basic_indent( _basic_indent );
            writer.set_types(_intype, _outtype);
            writer.template_intype_off();
            if( !_write_phi) writer.f_off();
            if( !_write_grad) writer.grad_off();
            if( !_write_hess) writer.hess_off();
            writer.set_var( var_name, var_description);
            
            std::vector<std::string> tmp_grad;
            tmp_grad.push_back(_grad[i]);
            
            std::vector< std::vector<std::string> > tmp_hess(1);
            tmp_hess[0].push_back(_hess[i]);
            
            writer.code( _phi[i], tmp_grad, tmp_hess, sout);
            
            sout << "\n";
        }
        */
        
        // write basis set class header
        sout << indent(I) << "class " + _name + " : public " + PBasisSetBaseTemplate + "\n";
        sout << indent(I) << "{\n";
        
        
        // write members
        sout << indent(I) << "public:\n";
        I++;
        //sout << indent(I) << "using " + PBasisSetBaseTemplate + "::_name;\n";
        //sout << indent(I) << "using " + PBasisSetBaseTemplate + "::_description;\n";
        //sout << indent(I) << "using " + PBasisSetBaseTemplate + "::_val;\n";
        //sout << indent(I) << "using " + PBasisSetBaseTemplate + "::_grad_val;\n";
        //sout << indent(I) << "using " + PBasisSetBaseTemplate + "::_hess_val;\n";
        sout << indent(I) << "\n";
        sout << indent(I) << "std::vector< " + PFunctionTemplate + " > _basis_function;\n";
        //sout << indent(I) << PSimpleBaseTemplate + "** _phi;\n";
        //sout << indent(I) << PSimpleBaseTemplate + "** _grad_phi;\n";
        //sout << indent(I) << PSimpleBaseTemplate + "** _hess_phi;\n";
        sout << indent(I) << "\n";
        
        
        // write constructor
        sout << indent(I) << _name + "(int N) : " + PBasisSetBaseTemplate + "(N)\n";
        sout << indent(I) << "{\n";
        I++;
        sout << indent(I) << "construct(N);\n";
        I--;
        sout << indent(I) << "}\n\n";
        
        
        // write copy constructor
        sout << indent(I) << _name + "(const " + _name + " &RHS ) : " + PBasisSetBaseTemplate + "(RHS.size())\n";
        sout << indent(I) << "{\n";
        I++;
        sout << indent(I) << "construct(RHS.size());\n";
        sout << indent(I) << "copy(RHS);\n";
        I--;
        sout << indent(I) << "}\n\n";
        
        
        // write assignment operator
        sout << indent(I) << _name + "& operator=(const " + _name + " &RHS )\n";
        sout << indent(I) << "{\n";
        I++;
        sout << indent(I) << "if( this == &RHS) return *this;\n";
        //sout << indent(I) << "destruct();\n";
        sout << indent(I) << "construct(RHS.size());\n";
        sout << indent(I) << "copy(RHS);\n";
        sout << indent(I) << "return *this;\n";
        I--;
        sout << indent(I) << "}\n\n";
        
        
        // write destructor
        sout << indent(I) << "~" + _name + "()\n";
        sout << indent(I) << "{\n";
        I++;
        //sout << indent(I) << "destruct();\n";
        I--;
        sout << indent(I) << "}\n\n";
        
        
        // write clone
        sout << indent(I) << _name + "* clone() const\n";
        sout << indent(I) << "{\n";
        I++;
        sout << indent(I) << "return new " + _name + "(*this);\n";
        I--;
        sout << indent(I) << "}\n\n";
        
        
        // write     PFunction<InType, OutType> basis_function(term) const
        sout << indent(I) << PFunctionTemplate + " basis_function( int term) const\n";
        sout << indent(I) << "{\n";
        I++;
        sout << indent(I) << "if(term >= max_size()){ std::cout << \"Error in " + _name + "::basis_function( int term). term >= max_size().\" << std::endl; exit(1);}\n\n";
        
        sout << indent(I) << "std::string name;\n";
        sout << indent(I) << "std::vector< std::string> var_name(1, \"x\");\n";
        sout << indent(I) << "std::vector< std::string> var_description(1, \"x\");\n\n";
        
        std::string psf = "psf";
        sout << indent(I) << "typedef " + PSimpleFunctionTemplate + " " + psf + ";\n\n";
        
        sout << indent(I) << psf + " simplef;\n";
        sout << indent(I) << "std::vector< " + psf + " > grad_simplef;\n";
        sout << indent(I) << "std::vector< std::vector< " + psf + " > > hess_simplef;\n";
        sout << indent(I) << "hess_simplef.resize(1);\n";
            
        sout << indent(I) << "switch( term )\n";
        sout << indent(I) << "{\n";
        I++;
        //for( int i=0; i<_phi.size(); i++)
        //{
        //    sout << indent(I) << "case " + itos(i) + ": return " + PFunctionTemplate + "( " + _name + "_" + itos(i) + "() ); break;\n";
        //}
        for( int i=0; i<_phi.size(); i++)
        {
            sout << indent(I) << "case " + itos(i) + ":\n";
            I++;
            sout << indent(I) << "name = \"" + _name + "_" + itos(i) + "\";\n";
            sout << indent(I) << "simplef = " + _name + "_" + itos(i) + "();\n";
            sout << indent(I) << "grad_simplef.push_back( " + psf + "( " + _name + "_" + itos(i) + "_grad() ) );\n";
            sout << indent(I) << "hess_simplef[0].push_back( " + psf + "( " + _name + "_" + itos(i) + "_hess() ) );\n";
            sout << indent(I) << "break;\n";
            I--;
        }
        I--;
        sout << indent(I) << "}\n";
        sout << indent(I) << "PFlexFunction< " + _intype + ", " + _outtype + " > tmp( name, var_name, var_description, simplef, grad_simplef, hess_simplef);\n"; 
        sout << indent(I) << "return " + PFunctionTemplate + "( tmp );\n";
        I--;
        sout << indent(I) << "}\n\n";
        
        /*
        // write     PSimpleFunction<InType, OutType>* clone_basis_function( int term)
        sout << indent(I) << PSimpleBaseTemplate + "* clone_basis_function( int term)\n";
        sout << indent(I) << "{\n";
        I++;
        sout << indent(I) << "if(term >= max_size()){ std::cout << \"Error in " + _name + "::clone_basis_function( int term). term >= max_size().\" << std::endl; exit(1);}\n";
        sout << indent(I) << "switch( term )\n";
        sout << indent(I) << "{\n";
        I++;
        for( int i=0; i<_phi.size(); i++)
        {
            sout << indent(I) << "case " + itos(i) + ": return new " + _name + "_" + itos(i) + "(); break;\n";
        }
        I--;
        sout << indent(I) << "}\n";
        I--;
        sout << indent(I) << "}\n\n";
        
        
        // write     PSimpleFunction<InType, OutType>* clone_basis_grad_function( int term)
        sout << indent(I) << PSimpleBaseTemplate + "* clone_grad_basis_function( int term)\n";
        sout << indent(I) << "{\n";
        I++;
        sout << indent(I) << "if(term >= max_size()){ std::cout << \"Error in " + _name + "::clone_grad_basis_function( int term). term >= max_size().\" << std::endl; exit(1);}\n";
        sout << indent(I) << "switch( term )\n";
        sout << indent(I) << "{\n";
        I++;
        for( int i=0; i<_grad.size(); i++)
        {
            sout << indent(I) << "case " + itos(i) + ": return new " + _name + "_grad_" + itos(i) + "(); break;\n";
        }
        I--;
        sout << indent(I) << "}\n";
        I--;
        sout << indent(I) << "}\n\n";
        
        
        // write      PSimpleFunction<InType, OutType>* clone_basis_hess_function( int term)
        sout << indent(I) << PSimpleBaseTemplate + "* clone_hess_basis_function( int term)\n";
        sout << indent(I) << "{\n";
        I++;
        sout << indent(I) << "if(term >= max_size()){ std::cout << \"Error in " + _name + "::clone_hess_basis_function( int term). term >= max_size().\" << std::endl; exit(1);}\n";
        sout << indent(I) << "switch( term )\n";
        sout << indent(I) << "{\n";
        I++;
        for( int i=0; i<_hess.size(); i++)
        {
            sout << indent(I) << "case " + itos(i) + ": return new " + _name + "_hess_" + itos(i) + "(); break;\n";
        }
        I--;
        sout << indent(I) << "}\n";
        I--;
        sout << indent(I) << "}\n\n";
        */
        
        // write max_size
        sout << indent(I) << "int max_size() const\n";
        sout << indent(I) << "{\n";
        I++;
        sout << indent(I) << "return " << _phi.size() << ";\n";
        I--;
        sout << indent(I) << "}\n\n";
        
        
        // write resize
        sout << indent(I) << "void resize(int N) \n";
        sout << indent(I) << "{\n";
        I++;
        sout << indent(I) << _name + " tmp(*this);\n";
        //sout << indent(I) << "destruct();\n";
        sout << indent(I) << "construct(N);\n";
        sout << indent(I) << "copy(tmp);\n";
        I--;
        sout << indent(I) << "}\n\n";
        
        
        
        /// ----- Private members -----------------------------------------
        
        I--;
        sout << indent(I) << "private:\n";
        I++;
        
        
        // write eval
        sout << indent(I) << _outtype + " eval(int term, const " + _intype + " &var)\n";
        sout << indent(I) << "{\n";
        I++;
        sout << indent(I) << "return _basis_function[term](var);\n";
        I--;
        sout << indent(I) << "}\n\n";
        
        // write eval_grad
        sout << indent(I) << _outtype + " eval_grad(int term, const " + _intype + " &var)\n";
        sout << indent(I) << "{\n";
        I++;
        sout << indent(I) << "return _basis_function[term].grad(var, 0);\n";
        I--;
        sout << indent(I) << "}\n\n";
        
        // write eval_hess
        sout << indent(I) << _outtype + " eval_hess(int term, const " + _intype + " &var)\n";
        sout << indent(I) << "{\n";
        I++;
        sout << indent(I) << "return _basis_function[term].hess(var, 0, 0);\n";
        I--;
        sout << indent(I) << "}\n\n";
        
        
        // write construct
        sout << indent(I) << "void construct(int N)\n";
        sout << indent(I) << "{\n";
        I++;
        sout << indent(I) << "if( N > max_size() ){ std::cout << \"Error in " << _name << ". Requested size \" << N << \". Max size is\" << max_size() << \".\"; exit(1);}\n";
        sout << indent(I) << "this->_name = \"" + _name + "\";\n";
        sout << indent(I) << "this->_description = \"" + _description + "\";\n";
        sout << indent(I) << "this->_val.resize(N);\n";
        sout << indent(I) << "this->_grad_val.resize(N);\n";
        sout << indent(I) << "this->_hess_val.resize(N);\n";
        sout << indent(I) << "_basis_function.resize(N);\n";
        sout << indent(I) << "for( int i=0; i<size(); i++)\n";
        sout << indent(I) << "{\n";
        I++;
        sout << indent(I) << "_basis_function[i] = basis_function(i);\n";
        I--;
        sout << indent(I) << "}\n";
        I--;
        sout << indent(I) << "}\n\n";
        
        
        /*
        // write destruct
        sout << indent(I) << "void destruct()\n";
        sout << indent(I) << "{\n";
        I++;
        sout << indent(I) << "for( int i=0; i<size(); i++)\n";
        sout << indent(I) << "{\n";
        I++;
        sout << indent(I) << "delete _phi[i];\n";
        sout << indent(I) << "delete _grad_phi[i];\n";
        sout << indent(I) << "delete _hess_phi[i];\n";
        I--;
        sout << indent(I) << "}\n";
        sout << indent(I) << "delete [] _phi;\n";
        sout << indent(I) << "delete [] _grad_phi;\n";
        sout << indent(I) << "delete [] _hess_phi;\n";
        I--;
        sout << indent(I) << "}\n\n";
        */
        
        // write copy 
        sout << indent(I) << "void copy(const " + _name + " &RHS )\n";
        sout << indent(I) << "{\n";
        I++;
        sout << indent(I) << "this->_name = RHS._name;\n";
        sout << indent(I) << "this->_description = RHS._description;\n";
        sout << indent(I) << "int lim = RHS.size() < this->size() ? RHS.size() : this->size();\n";
        sout << indent(I) << "for( int i=0; i<lim; i++)\n";
        sout << indent(I) << "{\n";
        I++;
        sout << indent(I) << "this->_val[i] = RHS._val[i];\n";
        sout << indent(I) << "this->_grad_val[i] = RHS._grad_val[i];\n";
        sout << indent(I) << "this->_hess_val[i] = RHS._hess_val[i];\n";
        sout << indent(I) << "_basis_function[i] = RHS._basis_function[i];\n";
        /*
        sout << indent(I) << "(*_phi[i])._val = (*RHS._phi[i])._val;\n";
        sout << indent(I) << "(*_grad_phi[i])._val = (*RHS._grad_phi[i])._val;\n";
        sout << indent(I) << "(*_hess_phi[i])._val = (*RHS._hess_phi[i])._val;\n";
        */
        I--;
        sout << indent(I) << "}\n";
        I--;
        sout << indent(I) << "}\n\n";
        
        
        
        // close class
        I--;
        sout << indent(I) << "};\n";
        
        
    }
    

    
    std::string PBasisSetWriter::indent(int step) const
    {
        std::string tmp = "";
        for( int i=0; i<step; i++)
            tmp += _basic_indent;
        return tmp;
    }
    
    void PBasisSetWriter::head( std::ostream &sout) const
    {
        int I = 0;
        
        // write date this was written
        
        sout << indent(I) << "// created: " << now() << "\n";
        sout << indent(I) << "// version: " << IntegrationTools_version_id() << "\n";
        sout << indent(I) << "// url: " << IntegrationTools_repo_url() << "\n";
        sout << indent(I) << "// commit: " << IntegrationTools_commit_id() << "\n\n";
        
        // write include guards & namespace
        sout << indent(I) << "#ifndef " + _name + "_HH\n"; 
        sout << indent(I) << "#define " + _name + "_HH\n\n"; 
        sout << indent(I) << "#include <cmath>\n";
        sout << indent(I) << "#include <cstdlib>\n";
        sout << indent(I) << "#include \"IntegrationTools/PFunction.hh\"\n\n";
        sout << indent(I) << "namespace PRISMS\n"; 
        sout << indent(I) << "{\n";
        I++;
        
    }
    
    void PBasisSetWriter::foot( std::ostream &sout) const
    {
        // close namespace
        sout << indent(0) << "}\n";
        
        // finish
        sout << indent(0) << "#endif\n";
        
    }

}


#endif