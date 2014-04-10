/*
 *  template.cpp
 *
 *
 *  Created by Brian Puchala on ?.
 *	All rights reserved.
 *
 *
 */

//#include <ginac/ginac.h>    // compile with: -lcln -lginac


//#include<iostream>
#include<fstream>
//#include<istream>
//#include<cstdlib>
#include<cstring>
#include<vector>
//#include<cmath>
//#include<stdlib.h>
//#include<stdio.h>
//#include<iomanip>
//#include<time.h>
//#include<sstream>
//#include "../../external/MersenneTwister/MersenneTwister.h"

#include "PFunctionWriter.hh"


template<typename T>
std::ostream& operator<<(std::ostream &sout, const std::vector<T> &v)
{
    for( int i=0; i<v.size(); i++)
        sout << v[i] << " ";
    return sout;
}


int main(int argc, char *argv[])
{
    
    PRISMS::PFunctionWriter writer("MyFunc");
    
    std::vector<std::string> var_name;
      var_name.push_back("c");
      var_name.push_back("grad");
      var_name.push_back("x");
      var_name.push_back("y");
    
    std::vector<std::string> var_desc;
      var_desc.push_back("concentration");
      var_desc.push_back("concentration gradient");
      var_desc.push_back("x");
      var_desc.push_back("y");
    
    writer.set_var( var_name, var_desc);
    
    std::ofstream outfile;
    outfile.open("MyFunc.hh");
    
    //writer.sym2code("2*c^4 + 2*c^2 + grad*2", outfile);
    writer.head(outfile);
    writer.sym2code("2*c^4*x^3*y^2 + 2*c^2*exp(x*y) + x*y^5*grad*2", outfile);
    writer.foot(outfile);
    
    return 0;
}
