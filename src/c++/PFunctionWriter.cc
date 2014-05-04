
#ifndef PFunctionWriter_CC
#define PFunctionWriter_CC

#include<cstring>
#include<iostream>
#include<sstream>
#include<vector>
#include<time.h>
#include<cstdlib>
#include<stdexcept>

//#include <boost/property_tree/ptree.hpp>
//#include <boost/property_tree/json_parser.hpp>
#include "json_spirit/json_spirit_reader_template.h"
#include "json_spirit/json_spirit_writer_template.h"

#include <ginac/ginac.h>    // compile with: -lcln -lginac

#include<boost/regex.hpp>

#include "IntegrationTools/writer/PFunctionWriter.hh"
#include "IntegrationTools/version.hh"

namespace PRISMS
{
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


    PFunctionWriter::PFunctionWriter(const std::string &name)
    {
        _name = name;
        
        // set defaults:
        template_intype_on();
        f_on();
        grad_on();
        hess_on();
        set_basic_indent("    ");
        set_types("double", "double");
    }
    
    void PFunctionWriter::set_basic_indent( std::string basic_indent)
    {
        _basic_indent = basic_indent;
    }
    
    void PFunctionWriter::set_intype(std::string intype)
    {
        _intype = intype;
    }
    
    void PFunctionWriter::set_outtype(std::string outtype)
    {
        _outtype = outtype;
    }
    
    void PFunctionWriter::set_types( std::string intype, std::string outtype)
    {
        _intype = intype;
        _outtype = outtype;
    }
    
    void PFunctionWriter::template_intype_on()
    {
        _template_intype = true;
    }
    
    void PFunctionWriter::template_intype_off()
    {
        _template_intype = false;
    }
    
    void PFunctionWriter::f_on()
    {
        _write_f = true;
    }
    
    void PFunctionWriter::f_off()
    {
        _write_f = false;
    }
    
    void PFunctionWriter::grad_on()
    {
        _write_grad = true;
    }
    
    void PFunctionWriter::grad_off()
    {
        _write_grad = false;
    }
    
    void PFunctionWriter::hess_on()
    {
        _write_hess = true;
    }
    
    void PFunctionWriter::hess_off()
    {
        _write_hess = false;
    }
    
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
    }


    /*
    void PFunctionWriter::sym( std::string f, std::ostream &sout)
    {
        std::cout << "PFunctionWriter::sym( std::string f, std::ostream &sout) is undefined" << std::endl;
        exit(1);
    }
    */
    
    std::string PFunctionWriter::sym_start() const
    {
        std::string str = "f(";
        
        for( int i=0; i<_var_name.size(); i++)
        {
            if( i>0)
                str += ",";
            str += _var_name[i];
        }
        str += ") = ";
        
        return str;
    }
    
    std::string PFunctionWriter::add_escapes(const std::string str) const
    {
        std::string _str = str;
        int pos;
        for( int i=0; i<_str.size(); i++)
        {
            pos = _str.find("\\",i);
            
            if( pos == std::string::npos)
                break;
            
            _str.replace(pos, 1, "\\\\");
            
            i = pos + 1;
        }
        return _str;
    }
    
    std::string PFunctionWriter::sym2csrc( const std::string &f, int di, int dj) const
    {
        // read 'f' into a GiNaC expression 'symf', 
        //    using the variables names already given
        GiNaC::symtab table;
        std::vector<GiNaC::symbol> symvar(_var_name.size());
        
        for( int i=0; i<_var_name.size(); i++)
        {
            symvar[i] = GiNaC::symbol( "var[" + itos(i) + "]");
            table[_var_name[i]] = symvar[i];
        }
        
        GiNaC::parser reader(table, true);
        GiNaC::ex symf;
        
        try
        {
            symf = reader(f);
        }
        catch (std::invalid_argument& err)
        {
            throw err;
        }
        
        
        // use 'symf' to generate c code string for f
        
        std::ostringstream ss;
        if( di == -1)
        {
            ss << GiNaC::csrc_double << symf;    
        }
        else if (dj == -1)
        {
            ss << GiNaC::csrc_double << symf.diff(symvar[di]);    
        }
        else
        {
            ss << GiNaC::csrc_double << symf.diff(symvar[di]).diff(symvar[dj]);    
        }
        return ss.str();
    }
    
    std::string PFunctionWriter::sym2sym( const std::string &f, int di, int dj) const
    {
        // read 'f' into a GiNaC expression 'symf', 
        //    using the variables names already given
        GiNaC::symtab table;
        std::vector<GiNaC::symbol> symvar(_var_name.size());
        
        for( int i=0; i<_var_name.size(); i++)
        {
            symvar[i] = GiNaC::symbol( _var_name[i]);
            table[_var_name[i]] = symvar[i];
        }
        
        GiNaC::parser reader(table, true);
        GiNaC::ex symf;
        
        try
        {
            symf = reader(f);
        }
        catch (std::invalid_argument& err)
        {
            throw err;
        }
        
        
        // use 'symf' to generate c code string for f
        
        std::ostringstream ss;
        if( di == -1)
        {
            ss << GiNaC::dflt << symf;    
        }
        else if (dj == -1)
        {
            ss << GiNaC::dflt << symf.diff(symvar[di]);    
        }
        else
        {
            ss << GiNaC::dflt << symf.diff(symvar[di]).diff(symvar[dj]);    
        }
        return ss.str();
    }
    
    std::string PFunctionWriter::sym2latex( const std::string &f, int di, int dj) const
    {
        // read 'f' into a GiNaC expression 'symf', 
        //    using the variables names already given
        GiNaC::symtab table;
        std::vector<GiNaC::symbol> symvar(_var_name.size());
        
        for( int i=0; i<_var_name.size(); i++)
        {
            symvar[i] = GiNaC::symbol( _var_name[i]);
            table[_var_name[i]] = symvar[i];
        }
        
        GiNaC::parser reader(table, true);
        GiNaC::ex symf;
        
        try
        {
            symf = reader(f);
        }
        catch (std::invalid_argument& err)
        {
            throw err;
        }
        
        
        // use 'symf' to generate c code string for f
        
        std::ostringstream ss;
        if( di == -1)
        {
            ss << GiNaC::latex << symf;    
        }
        else if (dj == -1)
        {
            ss << GiNaC::latex << symf.diff(symvar[di]);    
        }
        else
        {
            ss << GiNaC::latex << symf.diff(symvar[di]).diff(symvar[dj]);    
        }
        return add_escapes(ss.str());
    }
    
    void PFunctionWriter::sym2code( const std::string &f, std::ostream &sout)
    {
        std::cout << "Input f = " << f << std::endl;
        
        _f = "";
        _grad.clear();
        _hess.clear();
        
        std::cout << "\n";
        if( _write_f)
        {
            _sym = sym2sym(f);
            std::cout << " f :expr: " << _sym << std::endl;
            
            _f = sym2csrc(f);
            std::cout << " f :csrc: " << _f << std::endl;
            
            _latex = sym2latex(f);
            std::cout << " f :latex: " << _latex << std::endl;
        }
        
        std::cout << "\n";
        if( _write_grad)
        {
            for( int i=0; i<_var_name.size(); i++)
            {
                _grad.push_back( sym2csrc(f,i) );
                std::cout << " grad " << i << " :: " << _grad.back() << std::endl;
                
            }
        }
        
        std::cout << "\n";
        if( _write_hess)
        {
            _hess.resize(_var_name.size());
            for( int i=0; i<_var_name.size(); i++)
            {
                for( int j=0; j<_var_name.size(); j++)
                {
                    _hess[i].push_back( sym2csrc(f,i,j) );
                    std::cout << " hess " << i << " " << j << " :: " << _hess[i].back() << std::endl;
                    
                }
            }
        }
        
        std::cout << " ------------------------------- \n";
        
        code_poly( sout);
        
    }
    
    /// Read JSON string, parse into function and condition expressions, write to sout
    ///
    ///   Format: list of Piece objects: [{piece1}, {piece2}, ...]
    ///           Piece object: {"func":"expression", "cond": [cond1, cond2, ...]}
    ///           Condition array: ["lhs expression", "operation", "rhs expression"]
    ///           Possible operatoins: 
    ///              <  : less than
    ///              <= : less than or equal to
    ///              >  : greater than
    ///              >= : greater than or equal to
    ///              == : equal to
    ///              != : not equal to
    ///
    ///   Format example: 
    ///   '[ { "func": "0", 
    ///        "cond": [ ["x<0"] ] }, 
    ///      { "func": "pow(x,2)", 
    ///        "cond":["x >= 0", "x<1"] }, 
    ///      { "func": "2x",  
    ///        "cond":["x >= 1"] } 
    ///    ]'
    ///
    ///    Translates to:
    ///      f(x) = 0 if x < 0; x^2 if x >= 0 and x < 1; 2x if 1 <= x 
    
    void PFunctionWriter::piecewise2code( const std::string &f, std::ostream &sout)
    {
        // read JSON
        json_spirit::mValue pieces;
        json_spirit::read_string( f, pieces);
        
        std::cout << "\n";
        json_spirit::write_stream( pieces, std::cout);
        std::cout << "\n";
        
        // construct function strings
        std::string csrc, sym, latex;
        latex = "\\\\left\\\\{ \\\\begin{array}{ll} ";
        
        // remember the piecewise function's name
        std::string piecewise_funcname = _name;
        
        // remember which functions we want
        bool piecewise_write_f = _write_f;
        bool piecewise_write_grad = _write_grad;
        bool piecewise_write_hess = _write_hess;
        
        // save a list of the condition operations
        std::vector< std::vector<std::string> > operation( pieces.get_array().size(), std::vector<std::string>());
        
        // save a list of the condition names
        std::vector< std::vector<std::string> > cond_name( pieces.get_array().size(), std::vector<std::string>());
        
        // save a list of the piece names
        std::vector< std::string > piece_name;
        
        // write each function piece
        for( int i=0; i<pieces.get_array().size(); i++)
        {
            std::cout << "\n++++++++++++++++++++++++++++" << std::endl;
            std::cout << "Piece " << i << ": " << std::endl;
        
            std::string func;
            
            // for this piece of the function
            //   collect the function expression and the conditions array of arrays
            json_spirit::mObject &piece = pieces.get_array()[i].get_obj();
            func = piece["func"].get_str();
            json_spirit::mArray all_cond = piece["cond"].get_array();
            
            // write this piece's function
            //std::cout << "  Function: " << func << std::endl;
            std::stringstream ss;
            ss << i;
            piece_name.push_back( _name + "_piece" + ss.str());
            _name = piece_name.back();
            sym2code(func, sout);
            
            std::string str = "";
            std::string lstr = "";
            if( i > 0)
            {
                str += "; ";
                if( i == pieces.get_array().size()-1)
                    str += "and ";
                
                lstr += " \\\\\\\\ ";
                
            }
            
            csrc += str + _f;
            sym += str + _sym;
            latex += lstr + _latex;
            
            // write this piece's conditions
            _write_f = true;
            _write_grad = false;
            _write_hess = false;
            for( int j=0; j<all_cond.size(); j++)
            {
                std::string cond, lhs, oper, rhs;
                cond = all_cond[j].get_str();
                
                std::cout << "  Condition " << j << ": \'" << cond << "\'" << std::endl;
                
                parse_condition( cond, lhs, oper, rhs);
                
                std::cout << "     lhs: \'" << lhs << "\'" << std::endl;
                std::cout << "     oper: \'" << oper << "\'" << std::endl;
                std::cout << "     rhs: \'" << rhs << "\'" << std::endl;
                
                ss.str("");
                ss << j;
                cond_name[i].push_back( piece_name.back() + "_cond" + ss.str());
                
                // read the condition expressions and operation,
                //   and write the condition expressions
                write_condition_function(1, cond_name[i].back(), sym2csrc(lhs), oper, sym2csrc(rhs), sout); 
                
                str = "";
                if( j == 0)
                {
                    str += " if ";
                }
                else if( j == all_cond.size() -1)
                {
                    str += " and ";
                }
                else
                {
                    str += ", ";
                }
                
                lstr = "";
                if( j == 0)
                {
                    lstr += " & \\\\mbox{if } ";
                }
                else if( j == all_cond.size() -1)
                {
                    lstr += " \\\\mbox{ and } ";
                }
                else
                {
                    lstr += " \\\\mbox{, } ";
                }
                
                std::string loper = oper;
                if( loper == "<=")
                    loper = "\\\\leq";
                if( loper == ">=")
                    loper = "\\\\geq";
                if( loper == "==")
                    loper = "=";
                if( loper == "!=")
                    loper = "\\\\neq";
                
                csrc += str + sym2csrc(lhs) + " " + oper + " " + sym2csrc(rhs);
                sym += str + sym2sym(lhs) + " " + oper + " " + sym2sym(rhs);
                latex += lstr + sym2latex(lhs) + " " + loper + " " + sym2latex(rhs);
                
            }
            std::cout << std::endl;
            
            _name = piecewise_funcname;
            _write_f = piecewise_write_f;
            _write_grad = piecewise_write_grad;
            _write_hess = piecewise_write_hess;
            
        }
        
        latex += " \\\\end{array} \\\\right.";
        
        //std::cout << "Begin writing PPieceWiseFuncBase" << std::endl;
        
        
        // write the PPieceWiseFuncBase piecewise function
        int I = 1;
        sout << indent(I) << "template< class VarContainer >\n";
        sout << indent(I) << "class " << _name << " : public PPieceWiseFuncBase<VarContainer, " << _outtype << ">\n"; 
        sout << indent(I) << "{\n";
        sout << indent(I) << "public:\n";
        I++;
        
        // write constructor
        sout << indent(I) << _name << "()\n";
        sout << indent(I) << "{\n";
        I++;
        
        sout << indent(I) << "this->_csrc = \"" + csrc + "\";\n";
        sout << indent(I) << "this->_sym = \"" + sym_start() + sym + "\";\n";
        sout << indent(I) << "this->_latex = \"" + sym_start() + latex + "\";\n";
        sout << indent(I) << "this->_name = \"" + _name + "\";\n";
        sout << indent(I) << "this->_var_name.clear();\n";
        for( int i=0; i<_var_name.size(); i++)
            sout << indent(I) << "this->_var_name.push_back(\"" + _var_name[i] + "\");\n";
        sout << indent(I) << "this->_var_description.clear();\n";
        for( int i=0; i<_var_description.size(); i++)
            sout << indent(I) << "this->_var_description.push_back(\"" + _var_description[i] + "\");\n";
        
        sout << indent(I) << "typedef Piece<VarContainer, " << _outtype << "> Pc;\n";
        sout << indent(I) << "typedef PSimpleFunction<VarContainer, bool> Cond;\n";
        sout << indent(I) << "typedef PSimpleFunction<VarContainer, " << _outtype << "> psf;\n";
        sout << indent(I) << "typedef PFunction<VarContainer, " << _outtype << "> pf;\n\n";
            
        sout << indent(I) << "std::vector<Cond> cond;\n\n";
        
        // write each piece here
        for( int i=0; i< piece_name.size(); i++)
        {
        //std::cout << "i: " << i << std::endl;
        for( int j=0; j< cond_name[i].size(); j++)
        {
        //std::cout << "  j: " << j << std::endl;
        sout << indent(I) << "cond.push_back( Cond("<< cond_name[i][j] << "<VarContainer>()));\n";
        }
        sout << indent(I) << "this->_piece.push_back( Pc( pf(" << piece_name[i] << "<VarContainer>()), cond) );\n";
        sout << indent(I) << "cond.clear();\n\n";
        }
        I--;
        sout << indent(I) << "}\n";
        
        // close class
        I--;
        sout << indent(I) << "};\n\n\n";
        
        //std::cout << "Finish writing PPieceWiseFuncBase" << std::endl;
        
    }
    
    void PFunctionWriter::parse_condition( const std::string &cond, std::string &lhs, std::string &oper, std::string &rhs)
    {
        std::vector< boost::regex> e;
        e.push_back( boost::regex("(.*)(<=)(.*)") );
        e.push_back( boost::regex("(.*)(>=)(.*)") );
        e.push_back( boost::regex("(.*)(==)(.*)") );
        e.push_back( boost::regex("(.*)(!=)(.*)") );
        e.push_back( boost::regex("(.*)(~=)(.*)") );
        e.push_back( boost::regex("(.*)(<)(.*)") );
        e.push_back( boost::regex("(.*)(>)(.*)") );
        e.push_back( boost::regex("(.*)(=)(.*)") );
        boost::smatch match;
        
        for( int i=0; i<e.size(); i++)
        {
            if( boost::regex_search(cond, match, e[i]) )
            {
                lhs = std::string(match[1]);
                oper = std::string(match[2]);
                rhs = std::string(match[3]);
                
                if( oper == "~=" )
                    oper = "!=";
                if( oper == "=")
                    oper = "==";
                
                return;
            }
        }
        
        
        throw std::invalid_argument("Could not parse condition: " + cond);
    }
    
    /*
    void PFunctionWriter::code( const std::string &json_str,  std::ostream &sout)
    {
        std::cout << "PFunctionWriter::code( const std::string &json_str, std::ostream &sout) is undefined" << std::endl;
        exit(1);
    }
    */
    
    void PFunctionWriter::code( 
      const std::string &f, 
      const std::vector<std::string> &grad,
      const std::vector<std::vector< std::string> > &hess,
      std::ostream &sout)
    {
        _f = f;
        _grad = grad;
        _hess = hess;
        
        code_poly(sout);
        
    }
    
    void PFunctionWriter::write_basis_function(int I, const std::string &name, const std::string &f, std::ostream &sout) const
    {
        std::string PSimpleBaseTemplate;
        if( _template_intype) PSimpleBaseTemplate = "PSimpleBase< VarContainer, " + _outtype + ">";
        else PSimpleBaseTemplate = "PSimpleBase< " + _intype + ", " + _outtype + ">";
        
        if( _template_intype) sout << indent(I) << "template< class VarContainer>\n";
        sout << indent(I) << "class " + name + " : public " + PSimpleBaseTemplate + "\n";
        sout << indent(I) << "{\n";
        I++;
        if( _template_intype) sout << indent(I) << _outtype + " eval( const VarContainer &var) const\n";
        else sout << indent(I) << _outtype + " eval( const " + _intype + " &var) const\n";
        sout << indent(I) << "{\n";
        I++;
        sout << indent(I) << "return " + f + ";\n";
        I--;
        sout << indent(I) << "}\n\n";
        I--;
        sout << indent(I) << "public:\n\n";
        I++;
        
        sout << indent(I) << name + "()\n";
        sout << indent(I) << "{\n";
        I++;
        sout << indent(I) << "this->_name = \"" + name + "\";\n";
        I--;
        sout << indent(I) << "}\n\n";
        
        sout << indent(I) << name + "* clone() const\n";
        sout << indent(I) << "{\n";
        I++;
        sout << indent(I) << "return new " + name + "(*this);\n";
        I--;
        sout << indent(I) << "}\n";
        
        I--;
        sout << indent(I) << "};\n\n";
    }
    
    void PFunctionWriter::write_condition_function(int I, const std::string &name, const std::string &f_lhs, const std::string &oper, const std::string &f_rhs, std::ostream &sout) const
    {
        std::string PSimpleBaseTemplate;
        if( _template_intype) PSimpleBaseTemplate = "PSimpleBase< VarContainer, bool>";
        else PSimpleBaseTemplate = "PSimpleBase< " + _intype + ", bool>";
        
        if( _template_intype) sout << indent(I) << "template< class VarContainer>\n";
        sout << indent(I) << "class " + name + " : public " + PSimpleBaseTemplate + "\n";
        sout << indent(I) << "{\n";
        I++;
        if( _template_intype) sout << indent(I) << "bool eval( const VarContainer &var) const\n";
        else sout << indent(I) << "bool eval( const " + _intype + " &var) const\n";
        sout << indent(I) << "{\n";
        I++;
        sout << indent(I) << "return ( (" + f_lhs + ") " + oper + " (" + f_rhs + ") );\n";
        I--;
        sout << indent(I) << "}\n\n";
        I--;
        sout << indent(I) << "public:\n\n";
        I++;
        
        sout << indent(I) << name + "()\n";
        sout << indent(I) << "{\n";
        I++;
        sout << indent(I) << "this->_name = \"" + name + "\";\n";
        I--;
        sout << indent(I) << "}\n\n";
        
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
    void PFunctionWriter::code_poly( 
      std::ostream &sout) const
    {
        int I = 1;
        
        std::string PFuncBaseTemplate, PSimpleBaseTemplate, PSimpleFunctionTemplate, instring, instringtemp;
        if( _template_intype)
        {
            PFuncBaseTemplate = "PFuncBase< VarContainer, " + _outtype + ">";
            PSimpleBaseTemplate = "PSimpleBase< VarContainer, " + _outtype + ">";
            PSimpleFunctionTemplate = "PSimpleFunction< VarContainer, " + _outtype + ">";
            instring = "VarContainer";
            instringtemp = "<VarContainer>";
        }
        else
        {
            PFuncBaseTemplate = "PFuncBase< " + _intype + ", " + _outtype + ">";
            PSimpleBaseTemplate = "PSimpleBase< " + _intype + ", " + _outtype + ">";
            PSimpleFunctionTemplate = "PSimpleFunction< " + _intype + ", " + _outtype + ">";
            instring = _intype;
            instringtemp = "";
        }
        
        // write function classes for f, grad_f, hess_f
        if( _write_f)
        {
            write_basis_function(I, _name + "_f", _f, sout);
        }
        if( _write_grad)
        {
            for( int i=0; i<_var_name.size(); i++)
                write_basis_function(I, _name + "_grad_" + itos(i), _grad[i], sout);
        }
        if( _write_hess)
        {
            for( int i=0; i<_var_name.size(); i++)
            for( int j=0; j<_var_name.size(); j++)
                write_basis_function(I, _name + "_hess_" + itos(i) + "_" + itos(j), _hess[i][j], sout);
        }
        
        
        // write class header
        if( _template_intype) sout << indent(I) << "template<class VarContainer>\n";
        sout << indent(I) << "class " + _name + " : public " + PFuncBaseTemplate + "\n";
        sout << indent(I) << "{\n";
        
        
        // write members
        sout << indent(I) << "public:\n";
        I++;
        //sout << indent(I) << "using " + PFuncBaseTemplate + "::_name;\n";
        //sout << indent(I) << "using " + PFuncBaseTemplate + "::_var_name;\n";
        //sout << indent(I) << "using " + PFuncBaseTemplate + "::_var_description;\n";
        sout << indent(I) << "\n";
        sout << indent(I) << PSimpleBaseTemplate + " *_val;\n";
        sout << indent(I) << PSimpleBaseTemplate + " **_grad_val;\n";
        sout << indent(I) << PSimpleBaseTemplate + " ***_hess_val;\n";
        sout << indent(I) << "\n";
        
        
        // write constructor
        sout << indent(I) << _name + "()\n";
        sout << indent(I) << "{\n";
        I++;
        sout << indent(I) << "construct();\n";
        I--;
        sout << indent(I) << "}\n\n";
        
        // write copy constructor
        sout << indent(I) << _name + "(const " + _name + " &RHS )\n";
        sout << indent(I) << "{\n";
        I++;
        sout << indent(I) << "construct();\n";
        I--;
        sout << indent(I) << "}\n\n";
        
        // write assignment operator
        sout << indent(I) << _name + "& operator=(const " + _name + " &RHS )\n";
        sout << indent(I) << "{\n";
        I++;
        if( _write_f)
        {
            sout << indent(I) << "_val = RHS._val;\n";
        }
        if( _write_grad)
        {
            sout << indent(I) << "\n";
            for( int i=0; i<_var_name.size(); i++)
                sout << indent(I) << "_grad_val[" + itos(i) + "] = RHS._grad_val[" + itos(i) + "];\n";
        }
        if( _write_hess)
        {
            for( int i=0; i<_var_name.size(); i++)
            for( int j=0; j<_var_name.size(); j++)
                sout << indent(I) << "_hess_val[" + itos(i) + "][" + itos(j) + "] = RHS._hess_val[" + itos(i) + "][" + itos(j) + "];\n";
        }
        I--;
        sout << indent(I) << "}\n\n";
        
        
        // write destructor
        sout << indent(I) << "~" + _name + "()\n";
        sout << indent(I) << "{\n";
        I++;
        if( _write_f)
        {
            sout << indent(I) << "delete _val;\n\n";
        }
        if( _write_grad)
        {
            for( int i=0; i<_var_name.size(); i++)
                sout << indent(I) << "delete _grad_val[" + itos(i) + "];\n";
            sout << indent(I) << "delete [] _grad_val;\n\n";
        }
        if( _write_hess)
        {
            for( int i=0; i<_var_name.size(); i++)
            for( int j=0; j<_var_name.size(); j++)
                sout << indent(I) << "delete _hess_val[" + itos(i) + "][" + itos(j) + "];\n";
            for( int i=0; i<_var_name.size(); i++)
                sout << indent(I) << "delete [] _hess_val[" + itos(i) + "];\n";
            sout << indent(I) << "delete [] _hess_val;\n";
        }
        I--;
        sout << indent(I) << "}\n\n";
        
        
        // write clone
        sout << indent(I) << _name + instringtemp + "* clone() const\n";
        sout << indent(I) << "{\n";
        I++;
        sout << indent(I) << "return new " + _name + instringtemp + "(*this);\n";
        I--;
        sout << indent(I) << "}\n\n";
        
        // write simplefunction getter
        if( _write_f)
        {
        sout << indent(I) << PSimpleFunctionTemplate + " simplefunction() const\n";
        sout << indent(I) << "{\n";
        I++;
        sout << indent(I) << "return " + PSimpleFunctionTemplate + "( *_val );\n";
        I--;
        sout << indent(I) << "}\n\n";
        }
        
        if( _write_grad)
        {
        sout << indent(I) << PSimpleFunctionTemplate + " grad_simplefunction(int di) const\n";
        sout << indent(I) << "{\n";
        I++;
        sout << indent(I) << "return " + PSimpleFunctionTemplate + "( *_grad_val[di] );\n";
        I--;
        sout << indent(I) << "}\n\n";
        }
        
        if( _write_hess)
        {
        sout << indent(I) << PSimpleFunctionTemplate + " hess_simplefunction(int di, int dj) const\n";
        sout << indent(I) << "{\n";
        I++;
        sout << indent(I) << "return " + PSimpleFunctionTemplate + "( *_hess_val[di][dj] );\n";
        I--;
        sout << indent(I) << "}\n\n";
        }
        
        
        // write operators
        if( _write_f)
        {
        sout << indent(I) << _outtype + " operator()(const " + instring + " &var)\n";
        sout << indent(I) << "{\n";
        I++;
        sout << indent(I) << "return (*_val)(var);\n";
        I--;
        sout << indent(I) << "}\n\n";
        }
        
        if( _write_grad)
        {
        sout << indent(I) << _outtype + " grad(const " + instring + " &var, int di)\n";
        sout << indent(I) << "{\n";
        I++;
        sout << indent(I) << "return (*_grad_val[di])(var);\n";
        I--;
        sout << indent(I) << "}\n\n";
        }
        
        if( _write_hess)
        {
        sout << indent(I) << _outtype + " hess(const " + instring + " &var, int di, int dj)\n";
        sout << indent(I) << "{\n";
        I++;
        sout << indent(I) << "return (*_hess_val[di][dj])(var);\n";
        I--;
        sout << indent(I) << "}\n\n";
        }
        
        // write evals
        if( _write_f)
        {
        sout << indent(I) << "void eval(const " + instring + " &var)\n";
        sout << indent(I) << "{\n";
        I++;
        sout << indent(I) << "(*_val)(var);\n";
        I--;
        sout << indent(I) << "}\n\n";
        }
        
        if( _write_grad)
        {
        sout << indent(I) << "void eval_grad(const " + instring + " &var)\n";
        sout << indent(I) << "{\n";
        I++;
        for( int i=0; i<_var_name.size(); i++)
            sout << indent(I) << "(*_grad_val[" + itos(i) + "])(var);\n";
        I--;
        sout << indent(I) << "}\n\n";
        }
        
        if( _write_hess)
        {
        sout << indent(I) << "void eval_hess(const " + instring + " &var)\n";
        sout << indent(I) << "{\n";
        I++;
        for( int i=0; i<_var_name.size(); i++)
        for( int j=0; j<_var_name.size(); j++)
        sout << indent(I) << "(*_hess_val[" + itos(i) + "][" + itos(j) + "])(var);\n";
        I--;
        sout << indent(I) << "}\n\n";
        }
        
        // write getters
        if( _write_f)
        {
        sout << indent(I) << _outtype + " operator()() const\n";
        sout << indent(I) << "{\n";
        I++;
        sout << indent(I) << "return (*_val)();\n";
        I--;
        sout << indent(I) << "}\n\n";
        }
        
        if( _write_grad)
        {
        sout << indent(I) << _outtype + " grad(int di) const\n";
        sout << indent(I) << "{\n";
        I++;
        sout << indent(I) << "return (*_grad_val[di])();\n";
        I--;
        sout << indent(I) << "}\n\n";
        }
        
        if( _write_hess)
        {
        sout << indent(I) << _outtype + " hess(int di, int dj) const\n";
        sout << indent(I) << "{\n";
        I++;
        sout << indent(I) << "return (*_hess_val[di][dj])();\n";
        I--;
        sout << indent(I) << "}\n\n";
        }
        
        // write construct
        I--;
        sout << indent(I) << "private:\n";
        I++;
        sout << indent(I) << "void construct()\n";
        sout << indent(I) << "{\n";
        I++;
        
        sout << indent(I) << "this->_csrc = \"" + _f + "\";\n";
        sout << indent(I) << "this->_sym = \"" + _sym + "\";\n";
        sout << indent(I) << "this->_latex = \"" + _latex + "\";\n";
        
        sout << indent(I) << "this->_name = \"" + _name + "\";\n";
        sout << indent(I) << "this->_var_name.clear();\n";
        for( int i=0; i<_var_name.size(); i++)
            sout << indent(I) << "this->_var_name.push_back(\"" + _var_name[i] + "\");\n";
        sout << indent(I) << "this->_var_description.clear();\n";
        for( int i=0; i<_var_description.size(); i++)
            sout << indent(I) << "this->_var_description.push_back(\"" + _var_description[i] + "\");\n";
        if( _write_f)
        {
            sout << indent(I) << "\n";
            sout << indent(I) << "_val = new " + _name + "_f" + instringtemp + "();\n";
        }
        if( _write_grad)
        {
            sout << indent(I) << "\n";
            sout << indent(I) << "_grad_val = new " + PSimpleBaseTemplate + "*[" + itos(_var_name.size()) + "];\n";
            for( int i=0; i<_var_name.size(); i++)
                sout << indent(I) << "_grad_val[" + itos(i) + "] = new " +_name + "_grad_" + itos(i) + instringtemp + "();\n";
        }
        if( _write_hess)
        {
            sout << indent(I) << "\n";
            sout << indent(I) << "_hess_val = new " + PSimpleBaseTemplate + "**[" + itos(_var_name.size()) + "];\n";
            for( int i=0; i<_var_name.size(); i++)
                sout << indent(I) << "_hess_val[" + itos(i) + "] = new " + PSimpleBaseTemplate + "*[" + itos(_var_name.size()) + "];\n";
            for( int i=0; i<_var_name.size(); i++)
            for( int j=0; j<_var_name.size(); j++)
                sout << indent(I) << "_hess_val[" + itos(i) + "][" + itos(j) + "] = new " +_name + "_hess_" + itos(i) + "_" + itos(j) + instringtemp + "();\n";
        }
        I--;
        sout << indent(I) << "}\n\n";
        
        
        // close class
        I--;
        sout << indent(I) << "};\n\n\n";
        
        
    }
    
    // use if/else statements
    void PFunctionWriter::code_ifelse( 
      std::ostream &sout) const
    {
        int I = 0;
        std::string PFuncBaseTemplate, PSimpleBaseTemplate, PSimpleFunctionTemplate, instring, instringtemp;
        if( _template_intype)
        {
            PFuncBaseTemplate = "PFuncBase< VarContainer, " + _outtype + ">";
            PSimpleBaseTemplate = "PSimpleBase< VarContainer, " + _outtype + ">";
            PSimpleFunctionTemplate = "PSimpleFunction< VarContainer, " + _outtype + ">";
            instring = "VarContainer";
            instringtemp = "<VarContainer>";
        }
        else
        {
            PFuncBaseTemplate = "PFuncBase< " + _intype + ", " + _outtype + ">";
            PSimpleBaseTemplate = "PSimpleBase< " + _intype + ", " + _outtype + ">";
            PSimpleFunctionTemplate = "PSimpleFunction< " + _intype + ", " + _outtype + ">";
            instring = _intype;
            instringtemp = "";
        }
        // write function classes for f, grad_f, hess_f
        if( _write_f)
        {
            write_basis_function(I, _name + "_f", _f, sout);
        }
        if( _write_grad)
        {
            for( int i=0; i<_var_name.size(); i++)
                write_basis_function(I, _name + "_grad_" + itos(i), _grad[i], sout);
        }
        if( _write_hess)
        {
            for( int i=0; i<_var_name.size(); i++)
            for( int j=0; j<_var_name.size(); j++)
                write_basis_function(I, _name + "_hess_" + itos(i) + "_" + itos(j), _hess[i][j], sout);
        }
        
        // write class header
        if( _template_intype) sout << indent(I) << "template<class VarContainer>\n";
        sout << indent(I) << "class " + _name + " : public " + PFuncBaseTemplate + "\n";
        sout << indent(I) << "{\n";
        
        
        // write members
        sout << indent(I) << "public:\n";
        I++;
        sout << indent(I) << "using " + PFuncBaseTemplate + "::_name;\n";
        sout << indent(I) << "using " + PFuncBaseTemplate + "::_var_name;\n";
        sout << indent(I) << "using " + PFuncBaseTemplate + "::_var_description;\n";
        sout << indent(I) << "\n";
        sout << indent(I) << _outtype + " _val;\n";
        sout << indent(I) << _outtype + " *_grad_val;\n";
        sout << indent(I) << _outtype + " **_hess_val;\n";
        sout << indent(I) << "\n";
        
        
        // write constructor
        sout << indent(I) << _name + "()\n";
        sout << indent(I) << "{\n";
        I++;
        sout << indent(I) << "construct();\n";
        I--;
        sout << indent(I) << "}\n\n";
        
        // write copy constructor
        sout << indent(I) << _name + "(const " + _name + " &RHS )\n";
        sout << indent(I) << "{\n";
        I++;
        sout << indent(I) << "construct();\n";
        I--;
        sout << indent(I) << "}\n\n";
        
        // write assignment operator
        sout << indent(I) << _name + "& operator=(const " + _name + " &RHS )\n";
        sout << indent(I) << "{\n";
        I++;
        if( _write_f)
        {
            sout << indent(I) << "_val = RHS._val;\n";
        }
        if( _write_grad)
        {
            sout << indent(I) << "\n";
            for( int i=0; i<_var_name.size(); i++)
                sout << indent(I) << "_grad_val[" + itos(i) + "] = RHS._grad_val[" + itos(i) + "];\n";
        }
        if( _write_hess)
        {
            sout << indent(I) << "\n";
            for( int i=0; i<_var_name.size(); i++)
            for( int j=0; j<_var_name.size(); j++)
                sout << indent(I) << "_hess_val[" + itos(i) + "][" + itos(j) + "] = RHS._hess_val[" + itos(i) + "][" + itos(j) + "];\n";
        }
        sout << indent(I) << "return *this;\n";
        I--;
        sout << indent(I) << "}\n\n";
        
        
        // write destructor
        sout << indent(I) << "~" + _name + "()\n";
        sout << indent(I) << "{\n";
        I++;
        if( _write_grad)
        {
            sout << indent(I) << "delete [] _grad_val;\n\n";
        }
        if( _write_hess)
        {
            for( int i=0; i<_var_name.size(); i++)
                sout << indent(I) << "delete [] _hess_val[" + itos(i) + "];\n";
            sout << indent(I) << "delete [] _hess_val;\n";
        }
        I--;
        sout << indent(I) << "}\n\n";
        
        
        // write clone
        sout << indent(I) << _name + instringtemp + "* clone() const\n";
        sout << indent(I) << "{\n";
        I++;
        sout << indent(I) << "return new " + _name + instringtemp + "(*this);\n";
        I--;
        sout << indent(I) << "}\n\n";
        
        
        // write simplefunction getter
        if( _write_f)
        {
        sout << indent(I) << PSimpleFunctionTemplate + " simplefunction() const\n";
        sout << indent(I) << "{\n";
        I++;
        sout << indent(I) << "return " + PSimpleFunctionTemplate + "(" + _name + "_f());\n";
        I--;
        sout << indent(I) << "}\n\n";
        }
        
        if( _write_grad)
        {
        sout << indent(I) << PSimpleFunctionTemplate + " grad_simplefunction(int di) const\n";
        sout << indent(I) << "{\n";
        I++;
        for( int i=0; i<_var_name.size(); i++)
        {
            if( i == 0)
                sout << indent(I) << "if( di == " << i << " )\n";
            else
                sout << indent(I) << "else if( di == " << i << " )\n";
            sout << indent(I) << "{\n";
            I++;
            sout << indent(I) << "return " + PSimpleFunctionTemplate + "(" + _name + "_grad_" + itos(i) + "());\n";
            I--;
            sout << indent(I) << "}\n";
        }
        I--;
        sout << indent(I) << "}\n\n";
        }
        
        if( _write_hess)
        {
        sout << indent(I) << PSimpleFunctionTemplate + " hess_simplefunction(int di, int dj) const\n";
        sout << indent(I) << "{\n";
        I++;
        for( int i=0; i<_var_name.size(); i++)
        {
            if( i == 0)
                sout << indent(I) << "if( di == " << i << " )\n";
            else
                sout << indent(I) << "else if( di == " << i << " )\n";
            sout << indent(I) << "{\n";
            I++;
            for( int j=0; j<_var_name.size(); j++)
            {
                if( j == 0)
                    sout << indent(I) << "if( dj == " << j << " )\n";
                else
                    sout << indent(I) << "else if( dj == " << j << " )\n";
                sout << indent(I) << "{\n";
                I++;
                sout << indent(I) << "return " + PSimpleFunctionTemplate + "(" + _name + "_hess_" + itos(i) + "_" + itos(j) + "());\n";
                I--;
                sout << indent(I) << "}\n";
            }
            I--;
            sout << indent(I) << "}\n";
        }
        I--;
        sout << indent(I) << "}\n\n";
        }
        
        // write operators
        if( _write_f)
        {
        sout << indent(I) << _outtype + " operator()(const " + instring + " &var)\n";
        sout << indent(I) << "{\n";
        I++;
        sout << indent(I) << "return _val = " + _f + ";\n";
        I--;
        sout << indent(I) << "}\n\n";
        }
        
        if( _write_grad)
        {
        sout << indent(I) << _outtype + " grad(const " + instring + " &var, int di)\n";
        sout << indent(I) << "{\n";
        I++;
        for( int i=0; i<_var_name.size(); i++)
        {
            if( i == 0)
                sout << indent(I) << "if( di == " << i << " )\n";
            else
                sout << indent(I) << "else if( di == " << i << " )\n";
            sout << indent(I) << "{\n";
            I++;
            sout << indent(I) << "return _grad_val[di] = " + _grad[i] + ";\n";
            I--;
            sout << indent(I) << "}\n";
        }
        I--;
        sout << indent(I) << "}\n\n";
        }
        
        if( _write_hess)
        {
        sout << indent(I) << _outtype + " hess(const " + instring + " &var, int di, int dj)\n";
        sout << indent(I) << "{\n";
        I++;
        for( int i=0; i<_var_name.size(); i++)
        {
            if( i == 0)
                sout << indent(I) << "if( di == " << i << " )\n";
            else
                sout << indent(I) << "else if( di == " << i << " )\n";
            sout << indent(I) << "{\n";
            I++;
            for( int j=0; j<_var_name.size(); j++)
            {
                if( j == 0)
                    sout << indent(I) << "if( dj == " << j << " )\n";
                else
                    sout << indent(I) << "else if( dj == " << j << " )\n";
                sout << indent(I) << "{\n";
                I++;
                sout << indent(I) << "return _hess_val[di][dj] = " + _hess[i][j] + ";\n";
                I--;
                sout << indent(I) << "}\n";
            }
            I--;
            sout << indent(I) << "}\n";
        }
        I--;
        sout << indent(I) << "}\n\n";
        }
        
        // write evals
        if( _write_f)
        {
        sout << indent(I) << "void operator()(const " + instring + " &var)\n";
        sout << indent(I) << "{\n";
        I++;
        sout << indent(I) << "_val = " + _f + ";\n";
        I--;
        sout << indent(I) << "}\n\n";
        }
        
        if( _write_grad)
        {
        sout << indent(I) << "void grad(const " + instring + " &var)\n";
        sout << indent(I) << "{\n";
        I++;
        for( int i=0; i<_var_name.size(); i++)
            sout << indent(I) << "_grad_val[" + itos(i) + "] = " + _grad[i] + ";\n";
        I--;
        sout << indent(I) << "}\n\n";
        }
        
        if( _write_hess)
        {
        sout << indent(I) << "void hess(const " + instring + " &var)\n";
        sout << indent(I) << "{\n";
        I++;
        for( int i=0; i<_var_name.size(); i++)
        for( int j=0; j<_var_name.size(); j++)
        sout << indent(I) << "_hess_val[" + itos(i) + "][" + itos(j) + "] = " + _hess[i][j] + ";\n";
        I--;
        sout << indent(I) << "}\n\n";
        }
        
        // write getters
        if( _write_f)
        {
        sout << indent(I) << _outtype + " operator()() const\n";
        sout << indent(I) << "{\n";
        I++;
        sout << indent(I) << "return _val;\n";
        I--;
        sout << indent(I) << "}\n\n";
        }
        
        if( _write_grad)
        {
        sout << indent(I) << _outtype + " grad(int di) const\n";
        sout << indent(I) << "{\n";
        I++;
        sout << indent(I) << "return _grad_val[di];\n";
        I--;
        sout << indent(I) << "}\n\n";
        }
        
        if( _write_hess)
        {
        sout << indent(I) << _outtype + " hess(int di, int dj) const\n";
        sout << indent(I) << "{\n";
        I++;
        sout << indent(I) << "return _hess_val[di][dj];\n";
        I--;
        sout << indent(I) << "}\n\n";
        }
        
        // write construct
        I--;
        sout << indent(I) << "private:\n";
        I++;
        sout << indent(I) << "void construct()\n";
        sout << indent(I) << "{\n";
        I++;
        sout << indent(I) << "_name = \"" + _name + "\";\n";
        sout << indent(I) << "_var_name.clear();\n";
        for( int i=0; i<_var_name.size(); i++)
            sout << indent(I) << "_var_name.push_back(\"" + _var_name[i] + "\");\n";
        sout << indent(I) << "_var_description.clear();\n";
        for( int i=0; i<_var_description.size(); i++)
            sout << indent(I) << "_var_description.push_back(\"" + _var_description[i] + "\");\n";
        
        if( _write_grad)
        {
            sout << indent(I) << "\n";
            sout << indent(I) << "_grad_val = new " + _outtype + "[" + itos(_var_name.size()) + "];\n";
        }
        if( _write_hess)
        {
            sout << indent(I) << "\n";
            sout << indent(I) << "_hess_val = new " + _outtype + "*[" + itos(_var_name.size()) + "];\n";
            for( int i=0; i<_var_name.size(); i++)
                sout << indent(I) << "_hess_val[" + itos(i) + "] = new " + _outtype + "[" + itos(_var_name.size()) + "];\n";
        }
        I--;
        sout << indent(I) << "}\n\n";
        
        
        // close class
        I--;
        sout << indent(I) << "};\n\n\n";
        
    }
    
    /*
    void PFunctionWriter::autodiff( std::ostream &sout)
    {
        std::cout << "PFunctionWriter::autodiff( std::ostream &sout) is undefined" << std::endl;
        exit(1);
    }
    */
    
    /*
    void PFunctionWriter::series( std::ostream &sout)
    {
        std::cout << "PFunctionWriter::series( std::ostream &sout) is undefined" << std::endl;
        exit(1);
    }
    */
    
    //private:
    
    std::string PFunctionWriter::indent(int step) const
    {
        std::string tmp = "";
        for( int i=0; i<step; i++)
            tmp += _basic_indent;
        return tmp;
    }
    
    void PFunctionWriter::head( std::ostream &sout, bool piecewise) const
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
        sout << indent(I) << "#include \"IntegrationTools/PFunction.hh\"\n";
        if( piecewise) sout << indent(I) << "#include \"IntegrationTools/PPieceWise.hh\"\n\n";
        else sout << "\n";
        sout << indent(I) << "namespace PRISMS\n"; 
        sout << indent(I) << "{\n";
        I++;
        
    }
    
    void PFunctionWriter::foot( std::ostream &sout) const
    {
        // close namespace
        sout << indent(0) << "}\n";
        
        // finish
        sout << indent(0) << "#endif\n";
        
    }

}


#endif