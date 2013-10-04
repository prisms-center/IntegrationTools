
#ifndef PFunctionWriter_CC
#define PFunctionWriter_CC

#include<cstring>
#include<iostream>
#include<sstream>
#include<vector>
#include <ginac/ginac.h>    // compile with: -lcln -lginac

#include "PFunctionWriter.hh"

namespace PRISMS
{

    PFunctionWriter::PFunctionWriter(const std::string &name)
    {
        _name = name;
        
        // set defaults:
        f_on();
        grad_on();
        hess_on();
        set_basic_indent("    ");
        set_types("double", "double");
    };
    
    void PFunctionWriter::set_basic_indent( std::string basic_indent)
    {
        _basic_indent = basic_indent;
    };
    
    void PFunctionWriter::set_types( std::string intype, std::string outtype)
    {
        _intype = intype;
        _outtype = outtype;
    };
    
    void PFunctionWriter::f_on()
    {
        _write_f = true;
    };
    
    void PFunctionWriter::f_off()
    {
        _write_f = false;
    };
    
    void PFunctionWriter::grad_on()
    {
        _write_grad = true;
    };
    
    void PFunctionWriter::grad_off()
    {
        _write_grad = false;
    };
    
    void PFunctionWriter::hess_on()
    {
        _write_hess = true;
    };
    
    void PFunctionWriter::hess_off()
    {
        _write_hess = false;
    };
    
    void PFunctionWriter::set_var( const std::vector< std::string> &var_name, 
                  const std::vector< std::string> &var_description)
    {
        if( var_name.size() != var_description.size())
        {
            std::cout << "Error in PFunctionWriter::set_var" << std::endl;
            std::cout << "  var_name.size() != var_description.size()" << std::endl;
            exit(1);
        }
        _var_name = var_name;
        _var_description = var_description;
    };


    
    void PFunctionWriter::sym_writer( std::string f, std::ostream &sout)
    {
        _f = f;
    };
    
    void PFunctionWriter::sym2code_writer( const std::string &f, std::ostream &sout)
    {
        // read 'f' into a GiNaC expression 'symf', 
        //    using the variables names already given
        GiNaC::symtab table;
        std::vector<GiNaC::symbol> symvar(_var_name.size());
        for( int i=0; i<_var_name.size(); i++)
            table[_var_name[i]] = symvar[i];
        GiNaC::parser reader(table);
        GiNaC::ex symf = reader(f);
        
        
        // use 'symf' to generate c code strings for f, grad_f, hess_f
        
        _f = "";
        _grad.clear();
        _hess.clear();
        
        if( _write_f)
        {
            std::ostringstream ss;
            ss << GiNaC::csrc_double << symf;    
            std::cout << " f :: " << ss.str() << std::endl;
            _f = ss.str();
        }
        
        std::cout << "\n";
        if( _write_grad)
        {
            for( int i=0; i<_var_name.size(); i++)
            {
                std::ostringstream ss;
                ss << GiNaC::csrc_double << symf.diff(symvar[i]);
                std::cout << " grad " << i << " :: " << ss.str() << std::endl;
                _grad.push_back( ss.str());
            }
        }
        
        std::cout << "\n";
        if( _write_hess)
        {
            _hess.resize(_var_name.size());
            for( int i=0; i<_var_name.size(); i++)
            {
                for( int j=0; j<_var_name[i].size(); j++)
                {
                    std::ostringstream ss;
                    ss << GiNaC::csrc_double << symf.diff(symvar[i]).diff(symvar[j]);
                    std::cout << " hess " << i << " " << j << " :: " << ss.str() << std::endl;
                    _hess[i].push_back( ss.str());
                }
            }
        }
        
    };
    
    void PFunctionWriter::code_writer( 
      const std::string &json_str, 
      std::ostream &sout)
    {
    
    };
    
    void PFunctionWriter::code_writer( 
      const std::string &f, 
      const std::vector<std::string> &grad,
      const std::vector<std::vector< std::string> > &hess,
      std::ostream &sout)
    {
        _f = f;
        _grad = grad;
        _hess = hess;
        code_writer(sout);
    };
    
    void PFunctionWriter::code_writer( 
      std::ostream &sout)
    {
    
    };
    
    void PFunctionWriter::autodiff_writer( std::ostream &sout)
    {
    
    };
    
    void PFunctionWriter::series_writer( std::ostream &sout)
    {
    
    };

    //private:
        
        
    std::string PFunctionWriter::undefined(std::string declaration) const
    {
        // also need to consider indents...
    
        std::string s;
        s = "virtual " + declaration + "\n" +
            "{\n" + 
            "undefined(\""  + declaration + "\");\n" +
            "};\n\n";
        return s;
    };
    
    std::string PFunctionWriter::indent(int step) const
    {
        std::string tmp = "";
        for( int i=0; i<step; i++)
            tmp += _basic_indent;
        return tmp;
    };

}


#endif