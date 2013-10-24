/*
 *  test_PExtern.cpp
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

#include "PExtern_Example.hh"


template<typename T>
std::ostream& operator<<(std::ostream &sout, const std::vector<T> &v)
{
    for( int i=0; i<v.size(); i++)
        sout << v[i] << " ";
    return sout;
}

int main(int argc, char *argv[])
{
    char c[] = "Chebyshev_1";
    PRISMS::PSimpleBase<double, double> *f = NULL;
    
    std::cout << "string: " << std::string(c) << std::endl;
    std::cout << "new " << c << "  f: " << f << std::endl;
    PSimpleFunction_dd_new(c, f);
    std::cout << "  OK   f: " << f << std::endl;
    
    double var = 0.2;
    double val;
    
    std::cout << "calc with var: " << var << std::endl;
    PSimpleFunction_dd_calc(f,var,val);
    std::cout << "  result: " << val << std::endl;
    
    std::cout << "delete " << c << "  f: " << f << std::endl;
    PSimpleFunction_dd_delete(f);
    std::cout << "  OK    f: " << f << std::endl;
    
    
    return 0;
}
