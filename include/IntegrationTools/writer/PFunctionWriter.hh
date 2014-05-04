
#ifndef PFunctionWriter_HH
#define PFunctionWriter_HH

#include<cstring>
#include<iostream>
#include<vector>


namespace PRISMS
{

    // convert int to string
    std::string itos( int i);
    
    // return current date and time as: YEAR-MM-DD HH:MM:SS
    std::string now();

    /// Class used to write PFunction classes

    class PFunctionWriter
    {
    public:

        std::string _name;
        std::vector<std::string> _var_name;
        std::vector<std::string> _var_description;
        
        std::string _basic_indent;
        
        bool _template_intype;
        std::string _intype;
        std::string _outtype;
        
        bool _write_f;
        std::string _f;
        std::string _f_sym;
        std::string _f_latex;
        
        bool _write_grad;
        std::vector<std::string> _grad;
        std::vector<std::string> _grad_sym;
        std::vector<std::string> _grad_latex;
        
        bool _write_hess;
        std::vector< std::vector<std::string> > _hess;
        std::vector< std::vector<std::string> > _hess_sym;
        std::vector< std::vector<std::string> > _hess_latex;
        
        //std::vector<std::string> _basis;
        //std::vector< std::vector<std::string> > _grad_basis;
        //std::vector< std::vector< std::vector<std::string> > > _hess_basis;
        
        // Constructor initializes strings to call 'undefined' message
        PFunctionWriter(const std::string &name);
        
        // After construction, need to set things
        void set_basic_indent(std::string basic_indent);
        void set_intype(std::string intype);
        void set_outtype(std::string outtype);
        void set_types(std::string intype, std::string outtype);
        void template_intype_on();
        void template_intype_off();
        void f_on();
        void f_off();
        void grad_on();
        void grad_off();
        void hess_on();
        void hess_off();
        void set_var( const std::vector< std::string> &var_name, const std::vector< std::string> &var_description);
        
        // Write the PFuntion
        //   Different styles are be possible:
        
        void sym2code( const std::string &f, std::ostream &sout);
        void piecewise2code( const std::string &f, std::ostream &sout);
        
        void code( 
          const std::string &f, 
          const std::vector<std::string> &grad,
          const std::vector<std::vector< std::string> > &hess,
          std::ostream &sout);
        
        // TODO:
        //void sym( std::string f, std::ostream &sout);
        //void code(  const std::string &json_str, std::ostream &sout);
        //void autodiff_writer( std::ostream &sout);
        //void series_writer( std::ostream &sout);
        void head( std::ostream &sout, bool piecewise = false) const;
        
        void foot( std::ostream &sout) const;
        
    private:
        
        std::string indent(int step) const;
        
        // generate c src, sym, latex for symbolic expression string 'f'
        std::string sym_start() const;
        static std::string add_escapes(const std::string str);
        std::string sym2csrc( const std::string &f, int di=-1, int dj=-1) const;
        std::string sym2sym( const std::string &f, int di=-1, int dj=-1) const;
        std::string sym2latex( const std::string &f, int di=-1, int dj=-1) const;
        
        // parse a relational expression into a lhs expression, relational operator, and rhs expression
        void parse_condition( const std::string &cond, std::string &lhs, std::string &oper, std::string &rhs);
        
        void write_basis_function(int I, const std::string &name, const std::string &csrc, const std::string &sym, const std::string &latex, std::ostream &sout) const;
        
        void write_condition_function(int I, const std::string &name, const std::string &csrc, const std::string &sym, const std::string &latex, std::ostream &sout) const;
    
        // use polymorphic basis functions
        void code_poly( std::ostream &sout) const;
        
        // use if/else statements
        void code_ifelse( std::ostream &sout) const;
        
        
    };

}


#endif