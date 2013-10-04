
#ifndef PFunctionWriter_HH
#define PFunctionWriter_HH

#include<cstring>
#include<iostream>
#include<vector>

namespace PRISMS
{

    /// Base classes for functions that can be hard-coded,
    ///   then shared and used elsewhere

    class PFunctionWriter
    {
    public:

        std::string _name;
        std::vector<std::string> _var_name;
        std::vector<std::string> _var_description;
        
        std::string _basic_indent;
        
        std::string _intype;
        std::string _outtype;
        
        bool _write_f;
        std::string _f;
        
        bool _write_grad;
        std::vector<std::string> _grad;
        
        bool _write_hess;
        std::vector< std::vector<std::string> > _hess;
        
        std::vector<std::string> _basis;
        std::vector< std::vector<std::string> > _grad_basis;
        std::vector< std::vector< std::vector<std::string> > > _hess_basis;
        
        // Constructor initializes strings to call 'undefined' message
        PFunctionWriter(const std::string &name);
        
        // After construction, need to set things
        void set_basic_indent(std::string basic_indent);
        void set_types(std::string intype, std::string outtype);
        void f_on();
        void f_off();
        void grad_on();
        void grad_off();
        void hess_on();
        void hess_off();
        void set_var( const std::vector< std::string> &var_name, const std::vector< std::string> &var_description);
        
        // Write the PFuntion
        //   Different styles are possible:
        
        void sym_writer( std::string f, std::ostream &sout);
        void sym2code_writer( const std::string &f, std::ostream &sout);
        void code_writer( 
          const std::string &json_str, 
          std::ostream &sout);
        void code_writer( 
          const std::string &f, 
          const std::vector<std::string> &grad,
          const std::vector<std::vector< std::string> > &hess,
          std::ostream &sout);
        void code_writer( 
          std::ostream &sout);
        void autodiff_writer( std::ostream &sout);
        void series_writer( std::ostream &sout);

    private:
        
        
        std::string undefined(std::string declaration) const;
        
        std::string indent(int step) const;

    };

}


#endif