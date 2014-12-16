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


#include<iostream>
#include<fstream>
//#include<istream>
#include<cstdlib>
#include<cstring>
#include<vector>
//#include<getopt.h>
#include<boost/program_options.hpp>
#include<boost/filesystem.hpp>
#include<boost/filesystem/fstream.hpp>
#include<boost/regex.hpp>
//#include<cmath>
//#include<stdlib.h>
//#include<stdio.h>
//#include<iomanip>
//#include<time.h>
#include<algorithm>
#include<sstream>

#include "IntegrationTools/version.hh"


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

void write_pextern_cc( std::ofstream &sout);



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
    
}

bool not_header( fs::path p)
{
    return !is_header(p);
}

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
    
    typedef std::vector<std::vector<std::vector<std::string> > > tri_vec_string;
    
    tri_vec_string simplefunction; // [outtype][name0, name1, etc.]
    tri_vec_string function; // [outtype][name0, name1, etc.]
    tri_vec_string pwsimplefunction; // [outtype][name0, name1, etc.]
    tri_vec_string pwfunction; // [outtype][name0, name1, etc.]
    tri_vec_string basis_set; // [intype][outtype][name0, name1, etc.]
    
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
        std::vector<tri_vec_string*> functiontype;
        
        while(std::getline(infile, line))
        {
            
            functiontype.clear();
            functiontype.push_back( &simplefunction);
            bool found = scanline_for_class(line, "PSimpleBase", functiontype);
            
            functiontype.clear();
            functiontype.push_back( &function);
            found = found || scanline_for_class(line, "PFuncBase", functiontype);
            
            functiontype.clear();
            functiontype.push_back( &simplefunction);
            functiontype.push_back( &pwsimplefunction);
            found = found || scanline_for_class(line, "PPieceWiseSimpleBase", functiontype);
            
            functiontype.clear();
            functiontype.push_back( &function);
            functiontype.push_back( &pwfunction);
            found = found || scanline_for_class(line, "PPieceWiseFuncBase", functiontype);
            
            functiontype.clear();
            functiontype.push_back( &basis_set);
            found = found || scanline_for_class(line, "PBasisSetBase", functiontype);
            
            // if p contains something, make sure to save p's filename
            if( found )
            {
                if( std::find( filename.begin(), filename.end(), p.filename().string()) == filename.end() )
                    filename.push_back( p.filename().string());
            }
            
        }
    
    }
    
    // store the intype (add it to function_intype, but only if not already there)
    //   return index into function_intype
    int add_intype( const std::string &intype)
    {
        std::vector<std::string>::iterator intype_iter = std::find(function_intype.begin(), function_intype.end(), intype);
        int in_index = intype_iter - function_intype.begin();
        if( intype_iter == function_intype.end())
        {
            function_intype.push_back(intype);
            
            // resize function here
            simplefunction.push_back(std::vector<std::vector<std::string> >(0) );
            function.push_back(std::vector<std::vector<std::string> >(0) );
            pwsimplefunction.push_back(std::vector<std::vector<std::string> >(0) );
            pwfunction.push_back(std::vector<std::vector<std::string> >(0) );
            basis_set.push_back(std::vector<std::vector<std::string> >(0) );
            
            for( int i=0; i<function_outtype.size(); i++)
            {
                simplefunction.back().push_back(std::vector<std::string>(0) );
                function.back().push_back(std::vector<std::string>(0) );
                pwsimplefunction.back().push_back(std::vector<std::string>(0) );
                pwfunction.back().push_back(std::vector<std::string>(0) );
                basis_set.back().push_back(std::vector<std::string>(0) );
            }
        }
        
        return in_index;
    }
            
    // store the outtype (add it to function_outtype, but only if not already there)
    //   return index into function_outtype
    int add_outtype( const std::string &outtype)
    {        
        std::vector<std::string>::iterator outtype_iter = std::find(function_outtype.begin(), function_outtype.end(), outtype);
        int out_index = outtype_iter - function_outtype.begin();
        if( outtype_iter == function_outtype.end())
        {
            function_outtype.push_back(outtype);
            
            // resize function here
            for( int i=0; i<simplefunction.size(); i++)
            {
                simplefunction[i].push_back( std::vector<std::string>(0) );
                function[i].push_back( std::vector<std::string>(0) );
                pwsimplefunction[i].push_back( std::vector<std::string>(0) );
                pwfunction[i].push_back( std::vector<std::string>(0) );
                basis_set[i].push_back( std::vector<std::string>(0) );
            }
        }
        
        return out_index;
    }
    
    bool scanline_for_class(const std::string &line, const std::string &classname, std::vector<tri_vec_string*> &functiontype)
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
        
        boost::regex e("(class\\s+)(\\w*)(\\s*:\\s*public\\s+" + classname + "\\s*<\\s*)(.*)(\\s*,\\s*)(.*)(\\s*>)");
        boost::smatch match;
        std::vector<std::string>::iterator intype_iter, outtype_iter, name_iter;
        std::vector<std::string>* namevec;
        std::string name, intype, outtype;
        int in_index, out_index;
            
        if( boost::regex_search(line, match, e) )
        {
            //std::cout << "begin scanline_for_class()" << std::endl;
            //std::cout << line << std::endl;
            //std::cout << "### FOUND " + classname + " ###: ";
            //std::cout << "'" << match[2] << "' '" << match[4] << "' '" << match[6] << "'\n";
            
            name = std::string(match[2]);
            intype = std::string(match[4]);
            outtype = std::string(match[6]);
            
            in_index = add_intype(intype);
            out_index = add_outtype(outtype);
            
            for( int i=0; i<functiontype.size(); i++)
            {
                namevec = &((*functiontype[i])[ in_index][ out_index]);
                
                // error if name already exists
                if( std::find( (*namevec).begin(), (*namevec).end(), name) != (*namevec).end())
                {
                    std::cout << "Error. Found the " + classname + " '" << name << "' with OutType='" << outtype << "' twice." << std::endl;
                    std::cout << "   Names can not be repeated." << std::endl;
                    std::cout << "   Sorry for the inconvenience, but you must not exclude one of these and retry." << std::endl;
                    exit(1);
                     
                }
                else
                {
                    // store the name
                    (*namevec).push_back(name);
                }
            }
            
            return true;
        }
        
        return false;
    }
    
    void write( std::ostream &sout)
    {
        std::cout << "Files containing PSimpleBase, PFuncBase, PPieceWiseSimpleBase, PPieceWiseFuncBase, or PBasisSets: \n";
        std::cout << "  " << filename << "\n\n";
        
        std::cout << "Functions, & BasisSets: \n";
        for( int i=0; i<function_intype.size(); i++)
        for( int j=0; j<function_outtype.size(); j++)
        {
            std::cout << function_intype[i] << ", " << function_outtype[j] << ": \n";
            std::cout << "  PSimpleBase: " << simplefunction[i][j] << "\n\n";
            std::cout << "  PFuncBase: " << function[i][j] << "\n\n";
            std::cout << "  PPieceWiseSimpleBase: " << pwsimplefunction[i][j] << "\n\n";
            std::cout << "  PPieceWiseFuncBase: " << pwfunction[i][j] << "\n\n";
            std::cout << "  PBasisSets: " << basis_set[i][j] << "\n\n";
        }
        
    }
};



int main(int argc, char *argv[])
{
    // input variables
    std::string location;
    std::vector< std::string> dir, var, compile_options;
    std::string cxx, cflags;
     
    po::variables_map vm; 
    
    try 
    {
        /// Set command line options using boost program_options
        po::options_description desc("Options"); 
        desc.add_options() 
          ("help", "Write help documentation")
          ("version", "Write version info")
          ("compile,c", "Compile library after writing.") 
          ("cxx", po::value<std::string>(&cxx)->default_value("g++"), "Compiler to use. (\"g++\" by default)") 
          ("cflags", po::value<std::string>(&cflags)->default_value("-O3 -fPIC"), "Compiler flags to use. (\"-O3 -fPIC\" by default)") 
          ("dylib", "Compile with -dynamiclib instead of -shared") 
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
            
            /** --version option 
            */ 
            if ( vm.count("version")  ) 
            { 
                std::cout << "lw: Library Writer" << std::endl; 
                std::cout << "  version: " << PRISMS::IntegrationTools_version_id() << std::endl; 
                std::cout << "  url: " << PRISMS::IntegrationTools_repo_url() << std::endl; 
                std::cout << "  commit: " << PRISMS::IntegrationTools_commit_id() << std::endl; 
                return SUCCESS; 
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
    fs::path fileloc;
    
    
    
    // open file to write
    fileloc = location;
    fileloc /= ("PLibrary.hh");
    std::cout << "Preparing to write file: " << fileloc.c_str() << "\n\n";
    outfile.open( fileloc.c_str() );
    
    write_header( dir, var, outfile);
    outfile.close();
    
    // open file to write
    fileloc = location;
    fileloc /= ("PLibrary.cc");
    std::cout << "Preparing to write file: " << fileloc.c_str() << "\n\n";
    outfile.open( fileloc.c_str() );
    
    write_source( dir, var, outfile);
    outfile.close();
    
    
    if(vm.count("compile")) {
      // std::cout << "Compile: Not yet supported\n";
      // ---------------------------------------------
      fileloc = location;
      fileloc /= ("PLibrary.cc");
      
      std::cout << "Compile " << fileloc.string() << ": " << std::endl;
      std::string compile_cmd = cxx + " -c " + fileloc.string() + " -o " + (fs::path(location) / "PLibrary.o").string() + " " + cflags + " ";
      for( int i=0; i<dir.size(); i++) {
        compile_cmd += "-I" + dir[i] + " ";
      }
      std::cout << compile_cmd << std::endl;
      {
        FILE *fp;
        char path[PATH_MAX];
        fp = popen(compile_cmd.c_str(), "r");
        while(fgets(path, PATH_MAX, fp) != NULL) {
          std::cout << std::string(path);
        }
      }
      
      /*
      {
        FILE *fp;
        char path[PATH_MAX];
        fp = popen(("mv PLibrary.o " + location).c_str(), "r");
        while(fgets(path, PATH_MAX, fp) != NULL) {
          std::cout << std::string(path);
        }
      }
      */
      
      // ---------------------------------------------
      fileloc = location;
      fileloc /= ("PExtern.cc");
      
      fs::ofstream outfile(fileloc);
      write_pextern_cc(outfile);
      outfile.close();
      
      std::cout << "Compile " << fileloc.string() << ": " << std::endl;
      compile_cmd = cxx + " -c " + fileloc.string() + " -o " + (fs::path(location) / "PExtern.o").string() + " " +  cflags;
      std::cout << compile_cmd << std::endl;
      {
        FILE *fp;
        char path[PATH_MAX];
        fp = popen(compile_cmd.c_str(), "r");
        while(fgets(path, PATH_MAX, fp) != NULL) {
          std::cout << std::string(path);
        }
      }
      
      /*
      {
        FILE *fp;
        char path[PATH_MAX];
        fp = popen(("mv PExtern.o " + location).c_str(), "r");
        while(fgets(path, PATH_MAX, fp) != NULL) {
          std::cout << std::string(path);
        }
      }
      */
      
      // ---------------------------------------------
      if( vm.count("dylib")) {
        fileloc = location;
        fileloc /= ("libpextern.dylib");
        
        fs::path lib_o_loc = fs::path(location) / "PLibrary.o";
        fs::path extern_o_loc = fs::path(location) / "PExtern.o";
        fs::path dylib_o_loc = fileloc;
        
        std::cout << "Create dynamic library " << fileloc.string() << ":" << std::endl;
        compile_cmd = cxx + " -dynamiclib -o " + dylib_o_loc.string() + " " + extern_o_loc.string() + " " + lib_o_loc.string();
        std::cout << compile_cmd << std::endl;
      }
      else {
        fileloc = location;
        fileloc /= ("libpextern.so");
        
        fs::path lib_o_loc = fs::path(location) / "PLibrary.o";
        fs::path extern_o_loc = fs::path(location) / "PExtern.o";
        fs::path shared_o_loc = fileloc;
        
        std::cout << "Create shared library " << fileloc.string() << ":" << std::endl;
        compile_cmd = cxx + " -shared -o " + shared_o_loc.string() + " " + extern_o_loc.string() + " " + lib_o_loc.string();
        std::cout << compile_cmd << std::endl;
      }
      
      {
        FILE *fp;
        char path[PATH_MAX];
        fp = popen(compile_cmd.c_str(), "r");
        while(fgets(path, PATH_MAX, fp) != NULL) {
          std::cout << std::string(path);
        }
      }
      
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
#include \"IntegrationTools/PFunction.hh\"\n\
#include \"IntegrationTools/PPieceWise.hh\"\n\
\n\
namespace PRISMS\n\
{\n\
\n\
    /// Library where you can find functions and basis sets\n\
    ///\n\
    namespace PLibrary\n\
    {\n";

sout <<
"        // Use these functions to checkout objects which manage their own memory\n";

    sout << "\n";
    
    // write PFunction checkouts
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
                    sout << "        void checkout( std::string name, PFunction< " + var[k] + ", " + c.function_outtype[j] + " > &func);\n";
                }
            }
            else
            {
                sout << "        void checkout( std::string name, PFunction< " + c.function_intype[i] + ", " + c.function_outtype[j] + " > &func);\n";
            }
        }
    sout << "\n";
    
    for(int i=0; i<c.function_intype.size(); i++)
    for(int j=0; j<c.function_outtype.size(); j++)
        if( c.basis_set[i][j].size() > 0)
        {
            sout << "        void checkout( std::string name, PBasisSet< " + c.function_intype[i] + ", " + c.function_outtype[j] + " > &basis_set, int N);\n";
        }
    
    sout << "\n\n\n";

sout <<
"        // Use these functions to checkout new 'Base' objects which the user must delete\n";

    sout << "\n";
    
    // write PBase checkouts  ( create a 'new' object which the user must delete)
    //void checkout( std::string name, PSimpleBase<VarContainer, OutType> *simplefunc);
    //void checkout( std::string name, PFuncBase<VarContainer, OutType> *func);
    //void checkout( std::string name, PPieceWiseSimpleBase<VarContainer, OutType> *simplefunc);
    //void checkout( std::string name, PPieceWiseFuncBase<VarContainer, OutType> *func);
    //void checkout( std::string name, PBasisBase<InType, OutType> *basis_set);
    
    for(int i=0; i<c.function_intype.size(); i++)
    for(int j=0; j<c.function_outtype.size(); j++)
        if( c.simplefunction[i][j].size() > 0)
        {
            if( c.function_intype[i] == "VarContainer")
            {
                for( int k=0; k<var.size(); k++)
                {
                    sout << "        void checkout( std::string name, PSimpleBase< " + var[k] + ", " + c.function_outtype[j] + " > *&simplefunc);\n";
                }
            }
            else
            {
                sout << "        void checkout( std::string name, PSimpleBase< " + c.function_intype[i] + ", " + c.function_outtype[j] + " > *&simplefunc);\n";
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
                    sout << "        void checkout( std::string name, PFuncBase< " + var[k] + ", " + c.function_outtype[j] + " > *&func);\n";
                }
            }
            else
            {
                sout << "        void checkout( std::string name, PFuncBase< " + c.function_intype[i] + ", " + c.function_outtype[j] + " > *&func);\n";
            }
        }
    sout << "\n";
    
    for(int i=0; i<c.function_intype.size(); i++)
    for(int j=0; j<c.function_outtype.size(); j++)
        if( c.pwsimplefunction[i][j].size() > 0)
        {
            if( c.function_intype[i] == "VarContainer")
            {
                for( int k=0; k<var.size(); k++)
                {
                    sout << "        void checkout( std::string name, PPieceWiseSimpleBase< " + var[k] + ", " + c.function_outtype[j] + " > *&simplefunc);\n";
                }
            }
            else
            {
                sout << "        void checkout( std::string name, PPieceWiseSimpleBase< " + c.function_intype[i] + ", " + c.function_outtype[j] + " > *&simplefunc);\n";
            }
        }
    sout << "\n";
    
    for(int i=0; i<c.function_intype.size(); i++)
    for(int j=0; j<c.function_outtype.size(); j++)
        if( c.pwfunction[i][j].size() > 0)
        {
            if( c.function_intype[i] == "VarContainer")
            {
                for( int k=0; k<var.size(); k++)
                {
                    sout << "        void checkout( std::string name, PPieceWiseFuncBase< " + var[k] + ", " + c.function_outtype[j] + " > *&func);\n";
                }
            }
            else
            {
                sout << "        void checkout( std::string name, PPieceWiseFuncBase< " + c.function_intype[i] + ", " + c.function_outtype[j] + " > *&func);\n";
            }
        }
    sout << "\n";
    
    for(int i=0; i<c.function_intype.size(); i++)
    for(int j=0; j<c.function_outtype.size(); j++)
        if( c.basis_set[i][j].size() > 0)
        {
            sout << "        void checkout( std::string name, PBasisSetBase< " + c.function_intype[i] + ", " + c.function_outtype[j] + " > *&basis_set, int N);\n";
        }
    
sout <<
"    }\n\
\n\
}\n\
\n\
\n\
#endif\n";

}

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
#include<stdexcept>\n\
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

    // write PSimpleFunction, PFunction, PBasisSet checkouts
    //void checkout( std::string name, PSimpleFunction<VarContainer, OutType> &simplefunc);
    //void checkout( std::string name, PFunction<VarContainer, OutType> &func);
    //void checkout( std::string name, PBasisSet<InType, OutType> &basis_set, int N);
    
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
                    sout << "            typedef PSimpleFunction< " + var[k] + ", " + c.function_outtype[j] + " > psf;\n";
                    for( int ii=0; ii<c.simplefunction[i][j].size(); ii++)
                    sout << "            if( name == \"" + c.simplefunction[i][j][ii] + "\") { simplefunc = psf( " + c.simplefunction[i][j][ii] + "< " + var[k] + " >() ); return;}\n";
                    for( int ii=0; ii<c.pwsimplefunction[i][j].size(); ii++)
                    sout << "            if( name == \"" + c.pwsimplefunction[i][j][ii] + "\") { simplefunc = psf( " + c.pwsimplefunction[i][j][ii] + "< " + var[k] + " >() ); return;}\n";
                    sout << "            else throw std::runtime_error( \"PSimpleFunction< " + var[k] + ", " + c.function_outtype[j] + " > \" + name + \" was not found in the PLibrary\");\n"; 
                    sout << "        }\n";
                }
            }
            else
            {
                sout << "        void PLibrary::checkout( std::string name, PSimpleFunction< " + c.function_intype[i] + ", " + c.function_outtype[j] + " > &simplefunc)\n";
                sout << "        {\n";
                sout << "            typedef PSimpleFunction< " + c.function_intype[i] + ", " + c.function_outtype[j] + " > psf;\n";
                for( int ii=0; ii<c.simplefunction[i][j].size(); ii++)
                sout << "            if( name == \"" + c.simplefunction[i][j][ii] + "\") { simplefunc = psf( " + c.simplefunction[i][j][ii] + "() ); return;}\n";
                for( int ii=0; ii<c.pwsimplefunction[i][j].size(); ii++)
                sout << "            if( name == \"" + c.pwsimplefunction[i][j][ii] + "\") { simplefunc = psf( " + c.pwsimplefunction[i][j][ii] + "() ); return;}\n";
                sout << "            throw std::runtime_error( \"PSimpleFunction< " + c.function_intype[i] + ", " + c.function_outtype[j] + " > \" + name + \" was not found in the PLibrary\");\n"; 
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
                    sout << "            typedef PFunction< " + var[k] + ", " + c.function_outtype[j] + " > pf;\n";
                    for( int ii=0; ii<c.function[i][j].size(); ii++)
                    sout << "            if( name == \"" + c.function[i][j][ii] + "\") { func = pf( " + c.function[i][j][ii] + "< " + var[k] + " >() ); return;}\n";
                    sout << "            throw std::runtime_error( \"PFunction< " + var[k] + ", " + c.function_outtype[j] + " > \" + name + \" was not found in the PLibrary\");\n"; 
                    sout << "        }\n";
                }
            }
            else
            {
                sout << "        void PLibrary::checkout( std::string name, PFunction< " + c.function_intype[i] + ", " + c.function_outtype[j] + " > &func)\n";
                sout << "        {\n";
                sout << "            typedef PFunction< " + c.function_intype[i] + ", " + c.function_outtype[j] + " > pf;\n";
                for( int ii=0; ii<c.function[i][j].size(); ii++)
                sout << "            if( name == \"" + c.function[i][j][ii] + "\") { func = pf( " + c.function[i][j][ii] + "() ); return;}\n";
                sout << "            throw std::runtime_error( \"PFunction< " + c.function_intype[i] + ", " + c.function_outtype[j] + " > \" + name + \" was not found in the PLibrary\");\n"; 
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
            sout << "            typedef PBasisSet< " + c.function_intype[i] + ", " + c.function_outtype[j] + " > pbs;\n";
            for( int k=0; k<c.basis_set[i][j].size(); k++)
            sout << "            if( name == \"" + c.basis_set[i][j][k] + "\") { basis_set = pbs( " + c.basis_set[i][j][k] + "(N) ); return;}\n";
            sout << "            throw std::runtime_error( \"PBasisSet< " + c.function_intype[i] + ", " + c.function_outtype[j] + " > \" + name + \" was not found in the PLibrary\");\n"; 
            sout << "        }\n";
        }
    sout << "\n\n\n";
    
    // write 'Base' checkouts
    //void checkout( std::string name, PSimpleBase<VarContainer, OutType> *simplefunc);
    //void checkout( std::string name, PFuncBase<VarContainer, OutType> *func);
    //void checkout( std::string name, PPieceWiseSimpleBase<VarContainer, OutType> *simplefunc);
    //void checkout( std::string name, PPieceWiseFuncBase<VarContainer, OutType> *func);
    //void checkout( std::string name, PBasisSetBase<InType, OutType> *basis_set, int N);
    
    for(int i=0; i<c.function_intype.size(); i++)
    for(int j=0; j<c.function_outtype.size(); j++)
        if( c.simplefunction[i][j].size() > 0 || c.pwsimplefunction[i][j].size() > 0)
        {
            if( c.function_intype[i] == "VarContainer")
            {
                for( int k=0; k<var.size(); k++)
                {
                    sout << "        void PLibrary::checkout( std::string name, PSimpleBase< " + var[k] + ", " + c.function_outtype[j] + " > *&simplefunc)\n";
                    sout << "        {\n";
                    for( int ii=0; ii<c.simplefunction[i][j].size(); ii++)
                    sout << "            if( name == \"" + c.simplefunction[i][j][ii] + "\") { simplefunc = new " + c.simplefunction[i][j][ii] + "< " + var[k] + " >(); return;}\n";
                    sout << "            throw std::runtime_error( \"PSimpleBase< " + var[k] + ", " + c.function_outtype[j] + " > \" + name + \" was not found in the PLibrary\");\n"; 
                    sout << "        }\n";
                }
            }
            else
            {
                sout << "        void PLibrary::checkout( std::string name, PSimpleBase< " + c.function_intype[i] + ", " + c.function_outtype[j] + " > *&simplefunc)\n";
                sout << "        {\n";
                for( int ii=0; ii<c.simplefunction[i][j].size(); ii++)
                sout << "            if( name == \"" + c.simplefunction[i][j][ii] + "\") { simplefunc = new " + c.simplefunction[i][j][ii] + "(); return;}\n";
                sout << "            throw std::runtime_error( \"PSimpleBase< " + c.function_intype[i] + ", " + c.function_outtype[j] + " > \" + name + \" was not found in the PLibrary\");\n"; 
                sout << "        }\n";
            }
        }
    sout << "\n";
    
    for(int i=0; i<c.function_intype.size(); i++)
    for(int j=0; j<c.function_outtype.size(); j++)
        if( c.function[i][j].size() > 0 || c.pwfunction[i][j].size() > 0)
        {
            if( c.function_intype[i] == "VarContainer")
            {
                for( int k=0; k<var.size(); k++)
                {
                    sout << "        void PLibrary::checkout( std::string name, PFuncBase< " + var[k] + ", " + c.function_outtype[j] + " > *&func)\n";
                    sout << "        {\n";
                    for( int ii=0; ii<c.function[i][j].size(); ii++)
                    sout << "            if( name == \"" + c.function[i][j][ii] + "\") { func = new " + c.function[i][j][ii] + "< " + var[k] + " >(); return;}\n";
                    sout << "            throw std::runtime_error( \"PFuncBase< " + var[k] + ", " + c.function_outtype[j] + " > \" + name + \" was not found in the PLibrary\");\n"; 
                    sout << "        }\n";
                }
            }
            else
            {
                sout << "        void PLibrary::checkout( std::string name, PFuncBase< " + c.function_intype[i] + ", " + c.function_outtype[j] + " > *&func)\n";
                sout << "        {\n";
                for( int ii=0; ii<c.function[i][j].size(); ii++)
                sout << "            if( name == \"" + c.function[i][j][ii] + "\") { func = new " + c.function[i][j][ii] + "(); return;}\n";
                sout << "            throw std::runtime_error( \"PFuncBase< " + c.function_intype[i] + ", " + c.function_outtype[j] + " > \" + name + \" was not found in the PLibrary\");\n"; 
                sout << "        }\n";
            }
        }
    sout << "\n";
    
    for(int i=0; i<c.function_intype.size(); i++)
    for(int j=0; j<c.function_outtype.size(); j++)
        if( c.pwsimplefunction[i][j].size() > 0)
        {
            if( c.function_intype[i] == "VarContainer")
            {
                for( int k=0; k<var.size(); k++)
                {
                    sout << "        void PLibrary::checkout( std::string name, PPieceWiseSimpleBase< " + var[k] + ", " + c.function_outtype[j] + " > *&simplefunc)\n";
                    sout << "        {\n";
                    for( int ii=0; ii<c.pwsimplefunction[i][j].size(); ii++)
                    sout << "            if( name == \"" + c.pwsimplefunction[i][j][ii] + "\") { simplefunc = new " + c.pwsimplefunction[i][j][ii] + "< " + var[k] + " >(); return;}\n";
                    sout << "            throw std::runtime_error( \"PPieceWiseSimpleBase< " + var[k] + ", " + c.function_outtype[j] + " > \" + name + \" was not found in the PLibrary\");\n"; 
                    sout << "        }\n";
                }
            }
            else
            {
                sout << "        void PLibrary::checkout( std::string name, PPieceWiseSimpleBase< " + c.function_intype[i] + ", " + c.function_outtype[j] + " > *&simplefunc)\n";
                sout << "        {\n";
                for( int ii=0; ii<c.pwsimplefunction[i][j].size(); ii++)
                sout << "            if( name == \"" + c.pwsimplefunction[i][j][ii] + "\") { simplefunc = new " + c.pwsimplefunction[i][j][ii] + "(); return;}\n";
                sout << "            throw std::runtime_error( \"PPieceWiseSimpleBase< " + c.function_intype[i] + ", " + c.function_outtype[j] + " > \" + name + \" was not found in the PLibrary\");\n"; 
                sout << "        }\n";
            }
        }
    sout << "\n";
    
    for(int i=0; i<c.function_intype.size(); i++)
    for(int j=0; j<c.function_outtype.size(); j++)
        if( c.pwfunction[i][j].size() > 0)
        {
            if( c.function_intype[i] == "VarContainer")
            {
                for( int k=0; k<var.size(); k++)
                {
                    sout << "        void PLibrary::checkout( std::string name, PPieceWiseFuncBase< " + var[k] + ", " + c.function_outtype[j] + " > *&func)\n";
                    sout << "        {\n";
                    for( int ii=0; ii<c.pwfunction[i][j].size(); ii++)
                    sout << "            if( name == \"" + c.pwfunction[i][j][ii] + "\") { func = new " + c.pwfunction[i][j][ii] + "< " + var[k] + " >(); return;}\n";
                    sout << "            throw std::runtime_error( \"PPieceWiseFuncBase< " + var[k] + ", " + c.function_outtype[j] + " > \" + name + \" was not found in the PLibrary\");\n"; 
                    sout << "        }\n";
                }
            }
            else
            {
                sout << "        void PLibrary::checkout( std::string name, PPieceWiseFuncBase< " + c.function_intype[i] + ", " + c.function_outtype[j] + " > *&func)\n";
                sout << "        {\n";
                for( int ii=0; ii<c.pwfunction[i][j].size(); ii++)
                sout << "            if( name == \"" + c.pwfunction[i][j][ii] + "\") { func = new " + c.pwfunction[i][j][ii] + "(); return;}\n";
                sout << "            throw std::runtime_error( \"PPieceWiseFuncBase< " + c.function_intype[i] + ", " + c.function_outtype[j] + " > \" + name + \" was not found in the PLibrary\");\n"; 
                sout << "        }\n";
            }
        }
    sout << "\n";
    
    for(int i=0; i<c.function_intype.size(); i++)
    for(int j=0; j<c.function_outtype.size(); j++)
        if( c.basis_set[i][j].size() > 0)
        {
            sout << "        void PLibrary::checkout( std::string name, PBasisSetBase< " + c.function_intype[i] + ", " + c.function_outtype[j] + " > *&basis_set, int N)\n";
            sout << "        {\n";
            for( int k=0; k<c.basis_set[i][j].size(); k++)
            sout << "            if( name == \"" + c.basis_set[i][j][k] + "\") { basis_set = new " + c.basis_set[i][j][k] + "(N); return;}\n";
            sout << "            throw std::runtime_error( \"PBasisSetBase< " + c.function_intype[i] + ", " + c.function_outtype[j] + " > \" + name + \" was not found in the PLibrary\");\n"; 
            sout << "        }\n";
        }

sout <<
"\n\
}\n\
\n\
\n\
#endif\n";

}

void write_pextern_cc( std::ofstream &sout) {
  sout <<
"#ifndef PExtern_CC\n\
#define PExtern_CC\n\
\n\
#include<cstring>\n\
#include<iostream>\n\
#include<vector>\n\
#include<cstdlib>\n\
\n\
#include \"IntegrationTools/PExtern.hh\"\n\
#include \"IntegrationTools/PFunction.hh\"\n\
#include \"IntegrationTools/PField.hh\"\n\
\n\
// In future, might have more complicated OutType, \n\
//   so make all have 'void' return and pass everything by reference\n\
\n\
\n\
extern \"C\"\n\
{\n\
    // Functions for using a PSimpleBase externally (say Python or Fortran)\n\
    //   written for VarContainer=double*, OutType=double, hence 'dsd' in function names\n\
    \n\
    void PSimpleFunction_dsd_new(char* name, PRISMS::PSimpleBase<double*,double>* &f)\n\
    { \n\
        PRISMS::PLibrary::checkout(std::string(name), f);\n\
    }\n\
    \n\
    void PSimpleFunction_dsd_delete(PRISMS::PSimpleBase<double*,double>* &f)\n\
    { \n\
        delete f;\n\
        f = NULL;\n\
    }\n\
    \n\
    void PSimpleFunction_dsd_name(PRISMS::PSimpleBase<double*,double> *f, char* name)\n\
    {\n\
        std::strcpy(name, f->name().c_str());\n\
    }\n\
    \n\
    void PSimpleFunction_dsd_calc( PRISMS::PSimpleBase<double*,double> *f, double* var, double &val)\n\
    {\n\
        val = (*f)(var);\n\
    }\n\
    \n\
    void PSimpleFunction_dsd_get( PRISMS::PSimpleBase<double*,double> *f, double  &val)\n\
    {\n\
        val = (*f)();\n\
    }\n\
    \n\
    \n\
    \n\
    \n\
    \n\
    // Functions for using a PSimpleBase externally (say Python or Fortran)\n\
    //   written for VarContainer=double, OutType=double, hence 'dd' in function names\n\
    \n\
    void PSimpleFunction_dd_new(char* name, PRISMS::PSimpleBase<double,double>* &f)\n\
    { \n\
        PRISMS::PLibrary::checkout(std::string(name), f);\n\
    }\n\
    \n\
    void PSimpleFunction_dd_delete(PRISMS::PSimpleBase<double,double>* &f)\n\
    { \n\
        delete f;\n\
        f = NULL;\n\
    }\n\
    \n\
    void PSimpleFunction_dd_name(PRISMS::PSimpleBase<double,double> *f, char* name)\n\
    {\n\
        std::strcpy(name, f->name().c_str());\n\
    }\n\
    \n\
    void PSimpleFunction_dd_calc( PRISMS::PSimpleBase<double,double> *f, double var, double &val)\n\
    {\n\
        val = (*f)(var);\n\
    }\n\
    \n\
    void PSimpleFunction_dd_get( PRISMS::PSimpleBase<double,double> *f, double  &val)\n\
    {\n\
        val = (*f)();\n\
    }\n\
    \n\
    \n\
    \n\
    \n\
    \n\
    // Functions for using a PFuncBase externally (say Python or Fortran)\n\
    //   written for VarContainer=double*, OutType=double, hence 'dsd' in function names\n\
    \n\
    void PFunction_dsd_new(char* name, PRISMS::PFuncBase<double*,double>* &f)\n\
    { \n\
        PRISMS::PLibrary::checkout(std::string(name), f);\n\
    }\n\
    \n\
    void PFunction_dsd_delete(PRISMS::PFuncBase<double*,double>* &f)\n\
    { \n\
        delete f;\n\
        f = NULL;\n\
    }\n\
    \n\
    void PFunction_dsd_name(PRISMS::PFuncBase<double*,double>* f, char* name)\n\
    {\n\
        std::strcpy(name, f->name().c_str());\n\
    }\n\
    \n\
    void PFunction_dsd_size(PRISMS::PFuncBase<double*,double>* f, int &size)\n\
    {\n\
        size = f->size();\n\
    }\n\
    \n\
    void PFunction_dsd_var_name(PRISMS::PFuncBase<double*,double>* f, int i, char* var_name)\n\
    {\n\
        std::strcpy(var_name, f->var_name(i).c_str());\n\
    }\n\
    \n\
    void PFunction_dsd_var_description(PRISMS::PFuncBase<double*,double>* f, int i, char* var_description)\n\
    {\n\
        std::strcpy(var_description, f->var_description(i).c_str());\n\
    }\n\
    \n\
    //void PFunction_dsd_simplefunc(PRISMS::PFuncBase<double*,double> *f, PSimpleBase<double*, double> *simplefunc);\n\
    //void PFunction_dsd_grad_simplefunc(PRISMS::PFuncBase<double*,double> *f, int *di, PSimpleBase<double*, double> *simplefunc);\n\
    //void PFunction_dsd_hess_simplefunc(PRISMS::PFuncBase<double*,double> *f, int *di, int *dj, PSimpleBase<double*, double> *simplefunc);\n\
    \n\
    void PFunction_dsd_calc(PRISMS::PFuncBase<double*,double>* f, double* var, double &val)\n\
    {\n\
        val = (*f)(var);\n\
    }\n\
    \n\
    void PFunction_dsd_calc_grad(PRISMS::PFuncBase<double*,double>* f, double* var, int di, double &val)\n\
    {\n\
        val = (*f).grad(var, di);\n\
    }\n\
    \n\
    void PFunction_dsd_calc_hess(PRISMS::PFuncBase<double*,double>* f, double* var, int di, int dj, double &val)\n\
    {\n\
        val = (*f).hess(var, di, dj);\n\
    }\n\
    \n\
    void PFunction_dsd_eval(PRISMS::PFuncBase<double*,double>* f, double* var)\n\
    {\n\
        (*f)(var);\n\
    }\n\
    \n\
    void PFunction_dsd_eval_grad(PRISMS::PFuncBase<double*,double>* f, double* var, int di)\n\
    {\n\
        (*f).grad(var, di);\n\
    }\n\
    \n\
    void PFunction_dsd_eval_hess(PRISMS::PFuncBase<double*,double>* f, double* var, int di, int dj)\n\
    {\n\
        (*f).hess(var, di, dj);\n\
    }\n\
    \n\
    void PFunction_dsd_get(PRISMS::PFuncBase<double*,double>* f, double &val)\n\
    {\n\
        val = (*f)();\n\
    }\n\
    \n\
    void PFunction_dsd_get_grad(PRISMS::PFuncBase<double*,double>* f, int di, double &val)\n\
    {\n\
        val = (*f).grad(di);\n\
    }\n\
    \n\
    void PFunction_dsd_get_hess(PRISMS::PFuncBase<double*,double>* f, int di, int dj, double &val)\n\
    {\n\
        val = (*f).hess(di, dj);\n\
    }\n\
    \n\
    \n\
    \n\
    \n\
    \n\
    // Functions for using a PBasisSetBase externally (say Python or Fortran)\n\
    //   written for InType=double, OutType=double, hence 'dd' in function names\n\
    \n\
    void PBasisSet_dd_new(char* name, PRISMS::PBasisSetBase<double,double>* &b, int N)\n\
    { \n\
        PRISMS::PLibrary::checkout(std::string(name), b, N);\n\
    }\n\
    \n\
    void PBasisSet_dd_delete(PRISMS::PBasisSetBase<double,double>* &b)\n\
    { \n\
        delete b;\n\
        b = NULL;\n\
    }\n\
    \n\
    void PBasisSet_dd_name(PRISMS::PBasisSetBase<double,double>* b, char* name)\n\
    {\n\
        std::strcpy(name, b->name().c_str());\n\
    }\n\
    \n\
    void PBasisSet_dd_description(PRISMS::PBasisSetBase<double,double>* b, char* description)\n\
    {\n\
        std::strcpy(description, b->description().c_str());\n\
    }\n\
    \n\
    void PBasisSet_dd_size(PRISMS::PBasisSetBase<double,double>* b, int &size)\n\
    {\n\
        size = b->size();\n\
    }\n\
    \n\
    void PBasisSet_dd_resize(PRISMS::PBasisSetBase<double,double>* b, int N)\n\
    {\n\
        b->resize(N);\n\
    }\n\
    \n\
    void PBasisSet_dd_max_size(PRISMS::PBasisSetBase<double,double>* b, int &max_size)\n\
    {\n\
        max_size = b->max_size();\n\
    }\n\
    \n\
    //void PBasisSet_dd_basis_function(PRISMS::PFuncBase<double*,double> *b, int* term, PFuncBase<double,double> *f);\n\
    \n\
    void PBasisSet_dd_calc(PRISMS::PBasisSetBase<double,double>* b, int term, double var, double &val)\n\
    {\n\
        val = (*b)(term, var);\n\
    }\n\
    \n\
    void PBasisSet_dd_calc_grad(PRISMS::PBasisSetBase<double,double>* b, int term, double var, double &val)\n\
    {\n\
        val = (*b).grad(term, var);\n\
    }\n\
    \n\
    void PBasisSet_dd_calc_hess(PRISMS::PBasisSetBase<double,double>* b, int term, double var, double &val)\n\
    {\n\
        val = (*b).hess(term, var);\n\
    }\n\
        \n\
    void PBasisSet_dd_eval(PRISMS::PBasisSetBase<double,double>* b, double var)\n\
    {\n\
        (*b).eval(var);\n\
    }\n\
    \n\
    void PBasisSet_dd_eval_grad(PRISMS::PBasisSetBase<double,double>* b, double var)\n\
    {\n\
        (*b).eval_grad(var);\n\
    }\n\
    \n\
    void PBasisSet_dd_eval_hess(PRISMS::PBasisSetBase<double,double>* b, double var)\n\
    {\n\
        (*b).eval_hess(var);\n\
    }\n\
    \n\
    void PBasisSet_dd_get(PRISMS::PBasisSetBase<double,double>* b, int term, double &val)\n\
    {\n\
        val = (*b)(term);\n\
    }\n\
    \n\
    void PBasisSet_dd_get_grad(PRISMS::PBasisSetBase<double,double>* b, int term, double &val)\n\
    {\n\
        val = (*b).grad(term);\n\
    }\n\
    \n\
    void PBasisSet_dd_get_hess(PRISMS::PBasisSetBase<double,double>* b, int term, double &val)\n\
    {\n\
        val = (*b).hess(term);\n\
    }\n\
    \n\
    //void PBasisSet_dd_getall(PRISMS::PBasisSetBase<double,double>* b, const double* &val);\n\
    //void PBasisSet_dd_getall_grad(PRISMS::PBasisSetBase<double,double>* b, const double* &val);\n\
    //void PBasisSet_dd_getall_hess(PRISMS::PBasisSetBase<double,double>* b, const double* &val);\n\
    \n\
    \n\
    \n\
    \n\
    \n\
    // Functions for using a PSeriesFunction externally (say Python or Fortran)\n\
    //   written for InType=double, OutType=double, VarContainer=double*, IndexContainer=int*, hence 'dsis'\n\
    \n\
    void PSeriesFunction_dsis_new(PRISMS::PSeriesFunction<double,double,double*,int*>* &f)\n\
    {\n\
        f = new PRISMS::PSeriesFunction<double,double,double*,int*>(0.0, 1.0);\n\
    }\n\
    \n\
    void PSeriesFunction_dsis_setnew(PRISMS::PSeriesFunction<double,double,double*,int*>* &f, PRISMS::PBasisSetBase<double,double>** basis_set, int order)\n\
    {\n\
        std::vector<PRISMS::PBasisSet<double, double> > basis_set_vec;\n\
        for( int i=0; i<order; i++)\n\
            basis_set_vec.push_back( *basis_set[i]);\n\
        \n\
        f = new PRISMS::PSeriesFunction<double,double,double*,int*>(0.0, 1.0, basis_set_vec);\n\
    }\n\
        \n\
    void PSeriesFunction_dsis_delete(PRISMS::PSeriesFunction<double,double,double*,int*>* &f)\n\
    {\n\
        delete f;\n\
        f = NULL;\n\
    }\n\
    \n\
    void PSeriesFunction_dsis_clear(PRISMS::PSeriesFunction<double,double,double*,int*>* f)\n\
    {\n\
        (*f).clear();\n\
    }\n\
    \n\
    void PSeriesFunction_dsis_set(PRISMS::PSeriesFunction<double,double,double*,int*>* f, PRISMS::PBasisSetBase<double,double>** basis_set, int order)\n\
    {\n\
        std::vector<PRISMS::PBasisSet<double,double> > basis_set_vec;\n\
        PRISMS::PBasisSet<double,double> tmp;\n\
        for( int i=0; i<order; i++)\n\
        {\n\
            PRISMS::PLibrary::checkout( (*(basis_set[i])).name(), tmp, (*(basis_set[i])).size());\n\
            basis_set_vec.push_back( tmp);\n\
        }\n\
        \n\
        (*f).set(basis_set_vec);\n\
    }\n\
    \n\
    void PSeriesFunction_dsis_order(PRISMS::PSeriesFunction<double,double,double*,int*>* f, int &order)\n\
    {\n\
        order = (*f).coeff().order();\n\
    }\n\
    \n\
    void PSeriesFunction_dsis_volume(PRISMS::PSeriesFunction<double,double,double*,int*>* f, int &volume)\n\
    {\n\
        volume = (*f).coeff().volume();\n\
    }\n\
    \n\
    void PSeriesFunction_dsis_dim(PRISMS::PSeriesFunction<double,double,double*,int*>* f, int i, int &dim)\n\
    {\n\
        dim = (*f).coeff().dim(i);\n\
    }\n\
    \n\
    void PSeriesFunction_dsis_get_linear_coeff(PRISMS::PSeriesFunction<double,double,double*,int*>* f, int i, double &coeff)\n\
    {\n\
        coeff = (*f).coeff()(i);\n\
    }\n\
    \n\
    void PSeriesFunction_dsis_get_tensor_coeff(PRISMS::PSeriesFunction<double,double,double*,int*>* f, int* term, double &coeff)\n\
    {\n\
        coeff = (*f).coeff()(term);\n\
    }\n\
    \n\
    void PSeriesFunction_dsis_set_linear_coeff(PRISMS::PSeriesFunction<double,double,double*,int*>* f, int i, double coeff)\n\
    {\n\
        (*f).coeff()(i) = coeff;\n\
    }\n\
    \n\
    void PSeriesFunction_dsis_set_tensor_coeff(PRISMS::PSeriesFunction<double,double,double*,int*>* f, int* term, double coeff)\n\
    {\n\
        (*f).coeff()(term) = coeff;\n\
    }\n\
    \n\
    void PSeriesFunction_dsis_linear_index(PRISMS::PSeriesFunction<double,double,double*,int*>* f, int* term, int &linear_index)\n\
    {\n\
        linear_index = (*f).coeff().linear_index(term);\n\
    }\n\
    \n\
    void PSeriesFunction_dsis_tensor_indices(PRISMS::PSeriesFunction<double,double,double*,int*>* f, int linear_index, int* term)\n\
    {\n\
        // assumes term.size() == order()  (the tensor dimensions)\n\
        //   not sure if this is how we want to do it, but it avoids assuming push_back()\n\
        (*f).coeff().tensor_indices(linear_index, term);\n\
    }\n\
    \n\
    // ----------------------------------------------------------\n\
    // Use these functions if you want to evaluate a single value\n\
    \n\
    void PSeriesFunction_dsis_calc(PRISMS::PSeriesFunction<double,double,double*,int*>* f, double* var, double &val)\n\
    {\n\
        val = (*f)(var);\n\
    }\n\
    \n\
    void PSeriesFunction_dsis_calc_grad(PRISMS::PSeriesFunction<double,double,double*,int*>* f, double* var, int di, double &val)\n\
    {\n\
        val = (*f).grad(var,di);\n\
    }\n\
    \n\
    void PSeriesFunction_dsis_calc_hess(PRISMS::PSeriesFunction<double,double,double*,int*>* f, double* var, int di, int dj, double &val)\n\
    {\n\
        val = (*f).hess(var,di,dj);\n\
    }\n\
    \n\
    // ----------------------------------------------------------\n\
    // Use these functions to evaluate several values, then use 'get' methods to access results\n\
    \n\
    void PSeriesFunction_dsis_eval(PRISMS::PSeriesFunction<double,double,double*,int*>* f, double* var)\n\
    {\n\
        (*f).eval(var);\n\
    }\n\
    \n\
    void PSeriesFunction_dsis_eval_grad(PRISMS::PSeriesFunction<double,double,double*,int*>* f, double* var)\n\
    {\n\
        (*f).eval_grad(var);\n\
    }\n\
    \n\
    void PSeriesFunction_dsis_eval_hess(PRISMS::PSeriesFunction<double,double,double*,int*>* f, double* var)\n\
    {\n\
        (*f).eval_hess(var);\n\
    }\n\
    \n\
    void PSeriesFunction_dsis_get(PRISMS::PSeriesFunction<double,double,double*,int*>* f, double &val)\n\
    {\n\
        val = (*f)();\n\
    }\n\
    \n\
    void PSeriesFunction_dsis_get_grad(PRISMS::PSeriesFunction<double,double,double*,int*>* f, int di, double &val)\n\
    {\n\
        val = (*f).grad(di);\n\
    }\n\
    \n\
    void PSeriesFunction_dsis_get_hess(PRISMS::PSeriesFunction<double,double,double*,int*>* f, int di, int dj, double &val)\n\
    {\n\
        val = (*f).hess(di,dj);\n\
    }\n\
    \n\
    \n\
    // ----------------------------------------------------------\n\
    // Functions for evaluating basis functions & their derivatives:\n\
\n\
    // Use these functions if you want to evaluate a single value\n\
\n\
    //   use basis index and term index for individual basis function\n\
    \n\
    void PSeriesFunction_dsis_calc_basis(PRISMS::PSeriesFunction<double,double,double*,int*>* f, int bindex, int term, double* var, double &val)\n\
    {\n\
        val = (*f).basis(bindex,term,var);\n\
    }\n\
    \n\
    void PSeriesFunction_dsis_calc_basis_grad(PRISMS::PSeriesFunction<double,double,double*,int*>* f, int bindex, int term, double* var, double &val)\n\
    {\n\
        val = (*f).basis_grad(bindex,term,var);\n\
    }\n\
    \n\
    void PSeriesFunction_dsis_calc_basis_hess(PRISMS::PSeriesFunction<double,double,double*,int*>* f, int bindex, int term, double* var, double &val)\n\
    {\n\
        val = (*f).basis_hess(bindex,term,var);\n\
    }\n\
    \n\
    //   or use tensor indices to evaluate basis function product\n\
    void PSeriesFunction_dsis_calc_tensor_basis(PRISMS::PSeriesFunction<double,double,double*,int*>* f, int* term, double* var, double &val)\n\
    {\n\
        val = (*f).basis(term,var);\n\
    }\n\
    \n\
    void PSeriesFunction_dsis_calc_tensor_basis_grad(PRISMS::PSeriesFunction<double,double,double*,int*>* f, int* term, double* var, int di, double &val)\n\
    {\n\
        val = (*f).basis_grad(term,var,di);\n\
    }\n\
    \n\
    void PSeriesFunction_dsis_calc_tensor_basis_hess(PRISMS::PSeriesFunction<double,double,double*,int*>* f, int* term, double* var, int di, int dj, double &val)\n\
    {\n\
        val = (*f).basis_hess(term,var,di,dj);\n\
    }\n\
    \n\
    // ----------------------------------------------------------\n\
    // Use these functions to evaluate all basis functions,\n\
    //   then use following methods to access results.\n\
    \n\
    void PSeriesFunction_dsis_eval_basis_all(PRISMS::PSeriesFunction<double,double,double*,int*>* f, double* var)\n\
    {\n\
        (*f).eval_basis(var);\n\
    }\n\
    \n\
    void PSeriesFunction_dsis_eval_basis(PRISMS::PSeriesFunction<double,double,double*,int*>* f, double* var, int i)\n\
    {\n\
        (*f).eval_basis(var,i);\n\
    }\n\
    \n\
    void PSeriesFunction_dsis_eval_basis_grad_all(PRISMS::PSeriesFunction<double,double,double*,int*>* f, double* var)\n\
    {\n\
        (*f).eval_basis_grad(var);\n\
    }\n\
    \n\
    void PSeriesFunction_dsis_eval_basis_grad(PRISMS::PSeriesFunction<double,double,double*,int*>* f, double* var, int i)\n\
    {\n\
        (*f).eval_basis_grad(var,i);\n\
    }\n\
    \n\
    void PSeriesFunction_dsis_eval_basis_hess_all(PRISMS::PSeriesFunction<double,double,double*,int*>* f, double* var)\n\
    {\n\
        (*f).eval_basis_hess(var);\n\
    }\n\
    \n\
    void PSeriesFunction_dsis_eval_basis_hess(PRISMS::PSeriesFunction<double,double,double*,int*>* f, double* var, int i)\n\
    {\n\
        (*f).eval_basis_hess(var,i);\n\
    }\n\
    \n\
\n\
    //   use basis index and term index for individual basis function\n\
    void PSeriesFunction_dsis_get_basis(PRISMS::PSeriesFunction<double,double,double*,int*>* f, int bindex, int term, double &val)\n\
    {\n\
        val = (*f).basis(bindex,term);\n\
    }\n\
    \n\
    void PSeriesFunction_dsis_get_basis_grad(PRISMS::PSeriesFunction<double,double,double*,int*>* f, int bindex, int term, double &val)\n\
    {\n\
        val = (*f).basis_grad(bindex,term);\n\
    }\n\
    \n\
    void PSeriesFunction_dsis_get_basis_hess(PRISMS::PSeriesFunction<double,double,double*,int*>* f, int bindex, int term, double &val)\n\
    {\n\
        val = (*f).basis_hess(bindex,term);\n\
    }\n\
    \n\
    //   or use tensor indices to evaluate basis function product\n\
    void PSeriesFunction_dsis_get_tensor_basis(PRISMS::PSeriesFunction<double,double,double*,int*>* f, int* term, double &val)\n\
    {\n\
        val = (*f).basis(term);\n\
    }\n\
    \n\
    void PSeriesFunction_dsis_get_tensor_basis_grad(PRISMS::PSeriesFunction<double,double,double*,int*>* f, int* term, int di, double &val)\n\
    {\n\
        val = (*f).basis_grad(term,di);\n\
    }\n\
    \n\
    void PSeriesFunction_dsis_get_tensor_basis_hess(PRISMS::PSeriesFunction<double,double,double*,int*>* f, int* term, int di, int dj, double &val)\n\
    {\n\
        val = (*f).basis_hess(term,di,dj);\n\
    }\n\
    \n\
    // Functions for using constructing a 2D PRISMS::Body externally (say Python or Fortran),\n\
    //   allowing access to PFields\n\
    //   written for Coordinate=double*, OutType=double, DIM=2\n\
    \n\
    void Body2D_new(char* vtkfile, PRISMS::Body<double*,2>* &b)\n\
    {\n\
        b = new PRISMS::Body<double*,2>();\n\
        (*b).read_vtk(std::string(vtkfile));\n\
    };\n\
    \n\
    void Body2D_delete(PRISMS::Body<double*,2>* &b)\n\
    {\n\
        delete b;\n\
        b = NULL;\n\
    };\n\
    \n\
    \n\
    // Functions for using a 2D scalar PField externally (say Python or Fortran), as a PFunction.\n\
    //   From a Body pointer, returns a pointer to a PFuncBase\n\
    //   written for Coordinate=double*, OutType=double, DIM=2\n\
    //   don't delete this! it will be deleted by deleting the Body\n\
    \n\
    void ScalarField2D(char* name, PRISMS::Body<double*,2>* b, PRISMS::PFuncBase<double*,double>* &f)\n\
    {\n\
        f = &((*b).find_scalar_field(std::string(name)));\n\
    };\n\
    \n\
    \n\
    // Functions for using constructing a 3D PRISMS::Body externally (say Python or Fortran),\n\
    //   allowing access to PFields\n\
    //   written for Coordinate=double*, OutType=double, DIM=3\n\
    \n\
    void Body3D_new(char* vtkfile, PRISMS::Body<double*,3>* &b)\n\
    {\n\
        b = new PRISMS::Body<double*,3>();\n\
        (*b).read_vtk(std::string(vtkfile));\n\
    };\n\
    \n\
    void Body3D_delete(PRISMS::Body<double*,3>* &b)\n\
    {\n\
        delete b;\n\
        b = NULL;\n\
    };\n\
    \n\
    \n\
    // Functions for using a 3D scalar PField externally (say Python or Fortran), as a PFunction.\n\
    //   From a Body pointer, returns a pointer to a PFuncBase\n\
    //   written for Coordinate=double*, OutType=double, DIM=2\n\
    //   don't delete this! it will be deleted by deleting the Body\n\
    \n\
    void ScalarField3D(char* name, PRISMS::Body<double*,3>* b, PRISMS::PFuncBase<double*,double>* &f)\n\
    {\n\
        f = &((*b).find_scalar_field(std::string(name)));\n\
    };\n\
    \n\
    \n\
}\n\
\n\
\n\
#endif\n";
}

