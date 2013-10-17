/*
 *  lw.cpp
 *
 *  Library Writer
 *
 *  Created by Brian Puchala.
 *	All rights reserved.
 *
 *
 */


//#include<iostream>
#include<fstream>
//#include<istream>
#include<cstdlib>
#include<cstring>
#include<vector>
//#include<getopt.h>
#include<boost/program_options.hpp>
#include<boost/filesystem.hpp>
#include<boost/regex.hpp>
//#include<cmath>
//#include<stdlib.h>
//#include<stdio.h>
//#include<iomanip>
//#include<time.h>
#include<algorithm>
#include<sstream>

#include "PFunctionWriter.hh"



template<typename T>
std::ostream& operator<<(std::ostream &sout, const std::vector<T> &v)
{
    for( int i=0; i<v.size(); i++)
        sout << v[i] << " ";
    return sout;
}

const size_t ERROR_IN_COMMAND_LINE = 1; 
const size_t SUCCESS = 0; 
const size_t ERROR_UNHANDLED_EXCEPTION = 2; 

namespace po = boost::program_options;
namespace fs = boost::filesystem;
    
void write_header( std::vector<std::string> dir, std::vector<std::string> var, std::ofstream &sout);

void write_source( std::vector<std::string> dir, std::vector<std::string> var, std::ofstream &sout);




bool is_header( fs::path p)
{
    std::string s = p.filename().string();
    
    if( s.size() < 3)
        return false;
    
    if( s.compare( s.size()-3, 3, ".hh") == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
    
};

bool not_header( fs::path p)
{
    return !is_header(p);
};

bool is_generated_header( fs::path p)
{
    // check if it is a header file
    if( not_header(p) )
        return false;

    // check that it is not a PFunction header file
    std::string s = p.filename().string();
    
    if( s == "PLibrary.hh")
        return false;
    if( s == "PFunction.hh")
        return false;
    if( s == "PSeriesFunction.hh")
        return false;
    if( s == "PRealSymFunction.hh")
        return false;
    if( s == "PComplexSymFunction.hh")
        return false;
        
    return true;
}

bool not_generated_header( fs::path p)
{
    return !is_generated_header(p);
}

class Collection
{
public:
    std::vector<std::string> filename;  // .hh files containing PSimpleFunctions, PFunctions, and PBasisSets

    std::vector<std::string> function_intype;
    std::vector<std::string> function_outtype;
    std::vector<std::vector<std::vector<std::string> > > simplefunction; // [outtype][name0, name1, etc.]
    std::vector<std::vector<std::vector<std::string> > > function; // [outtype][name0, name1, etc.]
    std::vector<std::vector<std::vector<std::string> > > basis_set; // [intype][outtype][name0, name1, etc.]
    
    Collection(std::vector< std::string> dir)
    {
        // scan directories given for PSimpleFunctions, PFunctions, and PBasisSets
        //   and collect the names by type
        
        for( int i=0; i<dir.size(); i++)
            scandir(dir[i]);
    }
    
    void scandir(std::string dir)
    {
        
        // scan directory for header files
        std::vector <fs::path> n;
            
        remove_copy_if(fs::directory_iterator(dir),
             fs::directory_iterator(),
             std::back_inserter(n),
             not_generated_header);
        
        // scan files for PSimpleBase, PFuncBase, and PBasisSetBase derived classes
        for( int i=0; i<n.size(); i++)
            scanfile(n[i]);
        
        
    }
    
    void scanfile(fs::path p)
    {
        std::cout << "scanfile: " << p.filename() << std::endl;
        
        std::ifstream infile;
        infile.open(p.c_str());
        std::string line;
        while(std::getline(infile, line))
        {
            bool a = scanline_for_PSimpleBase(line);
            bool b = scanline_for_PFuncBase(line);
            bool c = scanline_for_PBasisSetBase(line);
            
            // if p contains something, make sure to save p's filename
            if( a || b || c)
            {
                if( std::find( filename.begin(), filename.end(), p.filename().string()) == filename.end() )
                    filename.push_back( p.filename().string());
            }
            
        }
    
    }
    
    bool scanline_for_PSimpleBase(const std::string &line)
    {
        // want to match:
        //    "class" + (1+ whtspace) 
        //    + classname 
        //    + (0+ whtspace) + ":" + (0+ whtspace) + "public" + (1+ whtspace) +  "PSimpleBase" + (0+ whtspace) + "<" + (0+ whtspace) 
        //    + VarContainerType 
        //    + (0+ whtspace) + "," + (0+ whtspace) 
        //    + OutType 
        //    + (0+ whtspace) + ">"
        // and determine classname, OutType
        
        // store classname by OutType,
        //   error on finding repeat classname
        
        // return true if match found
        
        boost::regex e("(class\\s+)(\\w*)(\\s*:\\s*public\\s+PSimpleBase\\s*<\\s*)(.*)(\\s*,\\s*)(.*)(\\s*>)");
        boost::smatch match;
        std::vector<std::string>::iterator intype_iter, outtype_iter, name_iter;
        std::vector<std::string>* namevec;
        std::string name, intype, outtype;
        int in_index, out_index;
            
        if( boost::regex_search(line, match, e) )
        {
            std::cout << "begin scanline_for_PSimpleBase()" << std::endl;
            //std::cout << line << std::endl;
            //std::cout << "### FOUND PSimpleBase ###: ";
            std::cout << "'" << match[2] << "' '" << match[4] << "' '" << match[6] << "'\n";
            
            name = std::string(match[2]);
            intype = std::string(match[4]);
            outtype = std::string(match[6]);
            
            std::cout << "A" << std::endl;
            // store the intype (add it to function_intype, but only if not already there)
            intype_iter = std::find(function_intype.begin(), function_intype.end(), intype);
            in_index = intype_iter - function_intype.begin();
            if( intype_iter == function_intype.end())
            {
                function_intype.push_back(intype);
                
                // resize function here
                simplefunction.push_back(std::vector<std::vector<std::string> >(0) );
                function.push_back(std::vector<std::vector<std::string> >(0) );
                basis_set.push_back(std::vector<std::vector<std::string> >(0) );
                
                for( int i=0; i<function_outtype.size(); i++)
                {
                    simplefunction.back().push_back(std::vector<std::string>(0) );
                    function.back().push_back(std::vector<std::string>(0) );
                    basis_set.back().push_back(std::vector<std::string>(0) );
                }
            }
            
            std::cout << "B" << std::endl;
            // store the outtype (add it to function_outtype, but only if not already there)
            outtype_iter = std::find(function_outtype.begin(), function_outtype.end(), outtype);
            out_index = outtype_iter - function_outtype.begin();
            if( outtype_iter == function_outtype.end())
            {
                function_outtype.push_back(outtype);
                
                // resize function here
                for( int i=0; i<simplefunction.size(); i++)
                {
                    simplefunction[i].push_back( std::vector<std::string>(0) );
                    function[i].push_back( std::vector<std::string>(0) );
                    basis_set[i].push_back( std::vector<std::string>(0) );
                }
            }
            
            std::cout << "C: " << in_index << " " << out_index << std::endl;
            std::cout << "bs: " << simplefunction.size() << std::endl;
            std::cout << " bs: " << simplefunction[in_index].size() << std::endl;
            std::cout << "bs: " << function.size() << std::endl;
            std::cout << " bs: " << function[in_index].size() << std::endl;
            std::cout << "bs: " << basis_set.size() << std::endl;
            std::cout << " bs: " << basis_set[in_index].size() << std::endl;
            namevec = &simplefunction[ in_index][ out_index];
            
            std::cout << "D" << std::endl;
            std::cout << "s: " << (*namevec).size() << std::endl;
            // error if name already exists
            if( std::find( (*namevec).begin(), (*namevec).end(), name) != (*namevec).end())
            {
                std::cout << "Error. Found the PSimpleFunction '" << name << "' with OutType='" << outtype << "' twice." << std::endl;
                std::cout << "   Names can not be repeated." << std::endl;
                std::cout << "   Sorry for the inconvenience, but you must not exclude one of these and retry." << std::endl;
                exit(1);
                 
            }
            else
            {
                // store the name
                std::cout << "E" << std::endl;
                (*namevec).push_back(name);
            }
            
            std::cout << "F" << std::endl;
            
            return true;
        }
        
        return false;
    }
    
    bool scanline_for_PFuncBase(const std::string &line)
    {
        // want to match:
        //    "class" + (1+ whtspace) 
        //    + classname 
        //    + (0+ whtspace) + ":" + (0+ whtspace) + "public" + (1+ whtspace) +  "PFuncBase" + (0+ whtspace) + "<" + (0+ whtspace) 
        //    + VarContainerType 
        //    + (0+ whtspace) + "," + (0+ whtspace) 
        //    + OutType 
        //    + (0+ whtspace) + ">"
        // and determine classname, OutType
        
        boost::regex e("(class\\s+)(\\w*)(\\s*:\\s*public\\s+PFuncBase\\s*<\\s*)(.*)(\\s*,\\s*)(.*)(\\s*>)");
        boost::smatch match;
        std::vector<std::string>::iterator intype_iter, outtype_iter, name_iter;
        std::vector<std::string>* namevec;
        std::string name, intype, outtype;
        int in_index, out_index;
        
        if( boost::regex_search(line, match, e) )
        {
            std::cout << "begin scanline_for_PFuncBase()" << std::endl;
            //std::cout << line << std::endl;
            //std::cout << "$$$ FOUND PFuncBase $$$: ";
            std::cout << "'" << match[2] << "' '" << match[4] << "' '" << match[6] << "'\n";
            
            name = std::string(match[2]);
            intype = std::string(match[4]);
            outtype = std::string(match[6]);
            
            // store the intype (add it to function_intype, but only if not already there)
            intype_iter = std::find(function_intype.begin(), function_intype.end(), intype);
            in_index = intype_iter - function_intype.begin();
            if( intype_iter == function_intype.end())
            {
                function_intype.push_back(intype);
                
                // resize function here
                simplefunction.push_back(std::vector<std::vector<std::string> >(0) );
                function.push_back(std::vector<std::vector<std::string> >(0) );
                basis_set.push_back(std::vector<std::vector<std::string> >(0) );
                
                for( int i=0; i<function_outtype.size(); i++)
                {
                    simplefunction.back().push_back(std::vector<std::string>(0) );
                    function.back().push_back(std::vector<std::string>(0) );
                    basis_set.back().push_back(std::vector<std::string>(0) );
                }
            }
            
            // store the outtype (add it to function_outtype, but only if not already there)
            outtype_iter = std::find(function_outtype.begin(), function_outtype.end(), outtype);
            out_index = outtype_iter - function_outtype.begin();
            if( outtype_iter == function_outtype.end())
            {
                function_outtype.push_back(outtype);
                
                // resize function here
                for( int i=0; i<function.size(); i++)
                {
                    simplefunction[i].push_back( std::vector<std::string>(0) );
                    function[i].push_back( std::vector<std::string>(0) );
                    basis_set[i].push_back( std::vector<std::string>(0) );
                }
            }
            
            namevec = &function[ in_index][ out_index];
            
            // error if name already exists
            if( std::find( (*namevec).begin(), (*namevec).end(), name) != (*namevec).end())
            {
                std::cout << "Error. Found the PFunction '" << name << "' with OutType='" << outtype << "' twice." << std::endl;
                std::cout << "   Names can not be repeated." << std::endl;
                std::cout << "   Sorry for the inconvenience, but you must not exclude one of these and retry." << std::endl;
                exit(1);
                 
            }
            else
            {
                (*namevec).push_back(name);
            }
            
            return true;
        }
        
        return false;
    }
    
    bool scanline_for_PBasisSetBase(const std::string &line)
    {
        // want to match:
        //    "class" + (1+ whtspace) 
        //    + classname 
        //    + (0+ whtspace) + ":" + (0+ whtspace) + "public" + (1+ whtspace) +  "PFuncBase" + (0+ whtspace) + "<" + (0+ whtspace) 
        //    + InType 
        //    + (0+ whtspace) + "," + (0+ whtspace) 
        //    + OutType 
        //    + (0+ whtspace) + ">"
        // and determine classname, InType, OutType
        
        boost::regex e("(class\\s+)(\\w*)(\\s*:\\s*public\\s+PBasisSetBase\\s*<\\s*)(.*)(\\s*,\\s*)(.*)(\\s*>)");
        boost::smatch match;
        std::vector<std::string>::iterator intype_iter, outtype_iter, name_iter;
        std::vector<std::string>* namevec;
        std::string name, intype, outtype;
        int in_index, out_index;
            
        if( boost::regex_search(line, match, e) )
        {
            std::cout << "begin scanline_for_PBasisSetBase()" << std::endl;
            //std::cout << line << std::endl;
            //std::cout << "@@@ FOUND PSimpleBase @@@: ";
            std::cout << "'" << match[2] << "' '" << match[4] << "' '" << match[6] << "'\n";
            
            name = std::string(match[2]);
            intype = std::string(match[4]);
            outtype = std::string(match[6]);
            
            std::cout << "A" << std::endl;
            // store the intype (add it to function_intype, but only if not already there)
            intype_iter = std::find(function_intype.begin(), function_intype.end(), intype);
            in_index = intype_iter - function_intype.begin();
            if( intype_iter == function_intype.end())
            {
                function_intype.push_back(intype);
                
                // resize function here
                simplefunction.push_back(std::vector<std::vector<std::string> >(0) );
                function.push_back(std::vector<std::vector<std::string> >(0) );
                basis_set.push_back(std::vector<std::vector<std::string> >(0) );
                
                for( int i=0; i<function_outtype.size(); i++)
                {
                    simplefunction.back().push_back(std::vector<std::string>(0) );
                    function.back().push_back(std::vector<std::string>(0) );
                    basis_set.back().push_back(std::vector<std::string>(0) );
                }
            }
            
            std::cout << "B" << std::endl;
            // store the outtype (add it to function_outtype, but only if not already there)
            outtype_iter = std::find(function_outtype.begin(), function_outtype.end(), outtype);
            out_index = outtype_iter - function_outtype.begin();
            if( outtype_iter == function_outtype.end())
            {
                function_outtype.push_back(outtype);
                
                // resize function here
                for( int i=0; i<basis_set.size(); i++)
                {
                    simplefunction[i].push_back( std::vector<std::string>(0) );
                    function[i].push_back( std::vector<std::string>(0) );
                    basis_set[i].push_back( std::vector<std::string>(0) );
                }
            }
            
            std::cout << "C: " << in_index << " " << out_index << std::endl;
            std::cout << "bs: " << basis_set.size() << std::endl;
            std::cout << " bs: " << basis_set[in_index].size() << std::endl;
            namevec = &basis_set[ in_index][ out_index];
            
            std::cout << "D" << std::endl;
            std::cout << "s: " << (*namevec).size() << std::endl;
            // error if name already exists
            if( std::find( (*namevec).begin(), (*namevec).end(), name) != (*namevec).end())
            {
                std::cout << "Error. Found the PBasisSet '" << name << "' with InType='" << intype << "' and OutType='" << outtype << "' twice." << std::endl;
                std::cout << "   Names can not be repeated." << std::endl;
                std::cout << "   Sorry for the inconvenience, but you must not exclude one of these and retry." << std::endl;
                exit(1);
                 
            }
            else
            {
                // store the name
                (*namevec).push_back(name);
            }
            
            return true;
        }
        
        return false;
    }
    
    void write( std::ostream &sout)
    {
        std::cout << "Files containing PSimpleFunctions, PFunctions, or PBasisSets: \n";
        std::cout << "  " << filename << "\n\n";
        
        std::cout << "SimpleFunctions, Functions, & BasisSets: \n";
        for( int i=0; i<function_intype.size(); i++)
        for( int j=0; j<function_outtype.size(); j++)
        {
            std::cout << function_intype[i] << ", " << function_outtype[j] << ": \n";
            std::cout << "  PSimpleFunctions: " << simplefunction[i][j] << "\n\n";
            std::cout << "  PFunctions: " << function[i][j] << "\n\n";
            std::cout << "  PBasisSets: " << basis_set[i][j] << "\n\n";
        }
        
    }
};



int main(int argc, char *argv[])
{
    // input variables
    std::string location;
    std::vector< std::string> dir, var;
    
     
    po::variables_map vm; 
    
    try 
    {
        /// Set command line options using boost program_options
        po::options_description desc("Options"); 
        desc.add_options() 
          ("hh,h", "Write header file (.hh)") 
          ("cc,c", "Write source file (.cc)") 
          ("dir,d", po::value<std::vector<std::string> >(&dir)->multitoken(), "Directories to check for PSimpleFunctions, PFunctions and PBasisSets") 
          ("var,v", po::value<std::vector<std::string> >(&var)->multitoken()->required(), "Variable container types")
          ("location,l", po::value<std::string>(&location)->default_value("."), "Location to write library"); 
          
        
        
        try 
        { 
            po::store(po::parse_command_line(argc, argv, desc), vm); // can throw 

            /** --help option 
            */ 
            if ( vm.count("help")  ) 
            { 
            std::cout << "lw: Library Writer Usage" << std::endl 
                      << desc << std::endl; 
            return SUCCESS; 
            } 
            
            if( !(vm.count("hh") != vm.count("cc")) )
            {
                throw po::error("Error writing library. Either choose (--hh) or (--cc).");
            }
            

            po::notify(vm); // throws on error, so do after help in case 
                          // there are any problems 
        } 
        catch(po::error& e) 
        { 
          std::cerr << "ERROR: " << e.what() << std::endl << std::endl; 
          std::cerr << desc << std::endl; 
          return ERROR_IN_COMMAND_LINE; 
        }
    }
    catch(std::exception& e) 
    { 
        std::cerr << "Unhandled Exception reached the top of main: " 
                  << e.what() << ", application will now exit" << std::endl; 
        return ERROR_UNHANDLED_EXCEPTION; 

    } 
    
    std::ofstream outfile;
    fs::path fileloc(location);
    
    
    
    // if --hh: just write header file
    if( vm.count("hh"))
    {
        // open file to write
        fileloc /= ("PLibrary.hh");
        std::cout << "Preparing to write file: " << fileloc.c_str() << "\n\n";
        outfile.open( fileloc.c_str() );
        
        write_header( dir, var, outfile);
    
    }
    else
    {
        // open file to write
        fileloc /= ("PLibrary.cc");
        std::cout << "Preparing to write file: " << fileloc.c_str() << "\n\n";
        outfile.open( fileloc.c_str() );
        
        write_source( dir, var, outfile);
    }
    
    
    return 0;
}


void write_header( std::vector<std::string> dir, std::vector<std::string> var, std::ofstream &sout)
{
    Collection c(dir);
    
    std::cout << "\n";
    c.write(std::cout);
    
sout <<    
"#ifndef PLIBRARY_HH\n\
#define PLIBRARY_HH\n\
\n\
#include<cstring>\n\
#include<vector>\n\
\n\
namespace PRISMS\n\
{\n\
\n\
    /// Library where you can find functions and basis sets\n\
    ///\n\
    class PLibrary\n\
    {\n\
        public:\n";

    // write PSimpleFunction checkouts
    //void checkout( std::string name, PSimpleFunction<VarContainer, OutType> &simplefunc);
    //void checkout( std::string name, PFunction<VarContainer, OutType> &func);
    //void checkout( std::string name, PBasisSet<InType, OutType> &basis_set);
    
    for(int i=0; i<c.function_intype.size(); i++)
    for(int j=0; j<c.function_outtype.size(); j++)
        if( c.simplefunction[i][j].size() > 0)
        {
            if( c.function_intype[i] == "VarContainer")
            {
                for( int k=0; k<var.size(); k++)
                {
                    sout << "        void checkout( std::string name, PSimpleFunction< " + var[k] + ", " + c.function_outtype[j] + " > &simplefunc);\n";
                }
            }
            else
            {
                sout << "        void checkout( std::string name, PSimpleFunction< " + c.function_intype[i] + ", " + c.function_outtype[j] + " > &simplefunc);\n";
            }
        }
    sout << "\n";
    
    for(int i=0; i<c.function_intype.size(); i++)
    for(int j=0; j<c.function_outtype.size(); j++)
        if( c.function[i][j].size() > 0)
        {
            if( c.function_intype[i] == "VarContainer")
            {
                for( int k=0; k<var.size(); k++)
                {
                    sout << "        void checkout( std::string name, PFunction< " + var[k] + ", " + c.function_outtype[j] + " > &simplefunc);\n";
                }
            }
            else
            {
                sout << "        void checkout( std::string name, PFunction< " + c.function_intype[i] + ", " + c.function_outtype[j] + " > &simplefunc);\n";
            }
        }
    sout << "\n";
    
    for(int i=0; i<c.function_intype.size(); i++)
    for(int j=0; j<c.function_outtype.size(); j++)
        if( c.basis_set[i][j].size() > 0)
        {
            sout << "        void checkout( std::string name, PBasisSet< " + c.function_intype[i] + ", " + c.function_outtype[j] + " > &basis_set, int N);\n";
        }
    
sout <<
"    };\n\
\n\
}\n\
\n\
\n\
#endif\n";

};

void write_source( std::vector<std::string> dir, std::vector<std::string> var, std::ofstream &sout)
{
    Collection c(dir);
    
    std::cout << "\n";
    c.write(std::cout);
    
sout <<    
"#ifndef PLIBRARY_CC\n\
#define PLIBRARY_CC\n\
\n\
#include<cstring>\n\
#include<vector>\n";    // < -- edit this

    for( int i=0; i<c.filename.size(); i++)
    {
        sout << "#include \"" + c.filename[i] + "\"\n";
    }
sout << "#include \"PLibrary.hh\"\n";

sout <<
"\n\
namespace PRISMS\n\
{\n\
\n";

    // write PSimpleFunction checkouts
    //void checkout( std::string name, PSimpleFunction<VarContainer, OutType> &simplefunc);
    //void checkout( std::string name, PFunction<VarContainer, OutType> &func);
    //void checkout( std::string name, PBasisSet<InType, OutType> &basis_set);
    
    for(int i=0; i<c.function_intype.size(); i++)
    for(int j=0; j<c.function_outtype.size(); j++)
        if( c.simplefunction[i][j].size() > 0)
        {
            if( c.function_intype[i] == "VarContainer")
            {
                for( int k=0; k<var.size(); k++)
                {
                    sout << "        void PLibrary::checkout( std::string name, PSimpleFunction< " + var[k] + ", " + c.function_outtype[j] + " > &simplefunc)\n";
                    sout << "        {\n";
                    for( int ii=0; ii<c.simplefunction[i][j].size(); ii++)
                    sout << "            if( name == \"" + c.simplefunction[i][j][ii] + "\") simplefunc = PSimpleFunction< " + var[k] + ", " + c.function_outtype[j] + " >( " + c.simplefunction[i][j][ii] + "< " + var[k] + " >() );\n";
                    sout << "        }\n";
                }
            }
            else
            {
                sout << "        void PLibrary::checkout( std::string name, PSimpleFunction< " + c.function_intype[i] + ", " + c.function_outtype[j] + " > &simplefunc)\n";
                sout << "        {\n";
                for( int ii=0; ii<c.simplefunction[i][j].size(); ii++)
                sout << "            if( name == \"" + c.simplefunction[i][j][ii] + "\") simplefunc = PSimpleFunction< " + c.function_intype[i] + ", " + c.function_outtype[j] + " >( " + c.simplefunction[i][j][ii] + "() );\n";
                sout << "        }\n";
            }
        }
    sout << "\n";
    
    for(int i=0; i<c.function_intype.size(); i++)
    for(int j=0; j<c.function_outtype.size(); j++)
        if( c.function[i][j].size() > 0)
        {
            if( c.function_intype[i] == "VarContainer")
            {
                for( int k=0; k<var.size(); k++)
                {
                    sout << "        void PLibrary::checkout( std::string name, PFunction< " + var[k] + ", " + c.function_outtype[j] + " > &func)\n";
                    sout << "        {\n";
                    for( int ii=0; ii<c.function[i][j].size(); ii++)
                    sout << "            if( name == \"" + c.function[i][j][ii] + "\") func = PFunction< " + var[k] + ", " + c.function_outtype[j] + " >( " + c.function[i][j][ii] + "< " + var[k] + " >() );\n";
                    sout << "        }\n";
                }
            }
            else
            {
                sout << "        void PLibrary::checkout( std::string name, PFunction< " + c.function_intype[i] + ", " + c.function_outtype[j] + " > &func)\n";
                sout << "        {\n";
                for( int ii=0; ii<c.function[i][j].size(); ii++)
                sout << "            if( name == \"" + c.function[i][j][ii] + "\") func = PFunction< " + c.function_intype[i] + ", " + c.function_outtype[j] + " >( " + c.function[i][j][ii] + "() );\n";
                sout << "        }\n";
            }
        }
    sout << "\n";
    
    
    for(int i=0; i<c.function_intype.size(); i++)
    for(int j=0; j<c.function_outtype.size(); j++)
        if( c.basis_set[i][j].size() > 0)
        {
            sout << "        void PLibrary::checkout( std::string name, PBasisSet< " + c.function_intype[i] + ", " + c.function_outtype[j] + " > &basis_set, int N)\n";
            sout << "        {\n";
            for( int k=0; k<c.basis_set[i][j].size(); k++)
            sout << "            if( name == \"" + c.basis_set[i][j][k] + "\") basis_set = PBasisSet< " + c.function_intype[i] + ", " + c.function_outtype[j] + " >( " + c.basis_set[i][j][k] + "(N) );\n";
            sout << "        }\n";
        }

sout <<
"\n\
}\n\
\n\
\n\
#endif\n";

};


