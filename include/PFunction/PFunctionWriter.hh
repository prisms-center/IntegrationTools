
#ifndef PFunctionWriter_HH
#define PFunctionWriter_HH

#include<cstring>
#include<iostream>
#include<vector>


namespace PRISMS
{

    /// Base classes for functions that can be hard-coded,
    ///   then shared and used elsewhere

    template< InType, OutType, VarContainer, IndexContainer>
    class PFunctionWriter
    {
    public:

        std::string _name;
        std::vector<std::string> _var_name;
        std::vector<std::string> _var_description;
        
        std::string intype;
        std::string outtype;
        
        std::string f;
        std::vector<std::string> grad;
        std::vector< std::vector<std::string> > hess;
        
        std::vector<std::string> basis;
        std::vector< std::vector<std::string> > grad_basis;
        std::vector< std::vector< std::vector<std::string> > > hess_basis;
        
        // Constructor initializes strings to call 'undefined' message
        PFunctionWriter(const std::string &name);
        
        // After construction, need to set strings
        //   set by passing in strings
        void set_this_and_that();
        //
        //   or set by reading an input file
        void input_file(const std::string &infilename);
        
        // After setting, then write the new PFunction:
        write( const std::string &outfilename);
        write( std::ostream &sout);

    private:
        std::string undefined(std::string declaration) const
        {
            // also need to consider indents...
        
            std::string s;
            s = "virtual " + declaration + "\n" +
                "{\n" + 
                "undefined(\""  + declaration + "\");\n" +
                "};\n\n";
            return s;
        }

    };

}


#endif