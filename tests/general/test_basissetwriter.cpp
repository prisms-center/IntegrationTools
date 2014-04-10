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

#include "PBasisSetWriter.hh"


template<typename T>
std::ostream& operator<<(std::ostream &sout, const std::vector<T> &v)
{
    for( int i=0; i<v.size(); i++)
        sout << v[i] << " ";
    return sout;
}


int main(int argc, char *argv[])
{
    
    PRISMS::PBasisSetWriter writer("MyBasisSet", "Chebyshev Polynomials, up to 30");
    
    std::vector<std::string> phi_init;
      phi_init.push_back("1");
      phi_init.push_back("x");
    
    std::vector<std::string> phi_sym;
      phi_sym.push_back("phi0");
      phi_sym.push_back("phi1");
    
    std::ofstream outfile;
    outfile.open("MyBasisSet.hh");
    
    writer.sym2code( "2*x*phi1 - phi0", "x",  phi_init, phi_sym, 30, outfile);
        

    return 0;
}
