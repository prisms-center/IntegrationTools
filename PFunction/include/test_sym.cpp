/*
 *  template.cpp
 *
 *
 *  Created by Brian Puchala on ?.
 *	All rights reserved.
 *
 *
 */

#include <ginac/ginac.h>    // compile with: -lcln -lginac


//#include<iostream>
//#include<fstream>
//#include<istream>
//#include<cstdlib>
#include<cstring>
#include<complex>
//#include<cmath>
//#include<stdlib.h>
//#include<stdio.h>
//#include<iomanip>
//#include<time.h>
//#include<sstream>
//#include "../../external/MersenneTwister/MersenneTwister.h"

//using namespace std;


#include "BP_Vec.hh"
//#include "BP_GVec.h"
//#include "BP_Parse.cc"
//#include "BP_zParse.h"
//#include "BP_StopWatch.h"
//#include "BP_RVG.h"
//#include "BP_coords.h"
//#include "BP_Comb.h"
//#include "BP_useful.h"
//#include "BP_Plot.h"

using namespace BP;

#include "PSymFunction.hh"

using namespace PRISMS;

//using namespace std;
//using namespace GiNaC;

int main(int argc, char *argv[])
//int main()
{

    /*
    BP_Vec<string> args;
    for( int i=0; i<argc; i++)
    {
    	cout << argv[i] << " ";
    	args.add( string(argv[i]));
    }
    cout << endl;
    */

    // Test PRealSymFunction:

    GiNaC::symbol x("x"), y("y");
    GiNaC::symbol a;
    a = x;
    BP_Vec<double> var;
    var.add(2.0);
    var.add(3.0);

    BP_Vec<GiNaC::symbol> sym;
    sym.add(x);
    sym.add(y);

    GiNaC::ex e = x * x + y * y + x * y;

    std::cout << "sym: " << sym << std::endl;

    PRealSymFunction<BP_Vec> f;
    f.set("my_func", sym, e);

    std::cout << f.name() << "  " << f(var) << std::endl;
    std::cout << f.name() << "  grad: " << f.grad(var, 0) << std::endl;
    std::cout << f.name() << "  hess: " << f.hess(var, 0, 1) << std::endl;


    // Test PComplexSymFunction:

    e = x * x + GiNaC::I * y * y + exp(GiNaC::I * x * y);

    BP_Vec< complex<double> > complex_var;
    complex_var.add(complex<double>(2.0, 0.0));
    complex_var.add(complex<double>(3.0, 0.0));

    PComplexSymFunction<BP_Vec> g1;
    g1.set("my_complex_func", sym, e);

    PFunction<BP_Vec, complex<double>, complex<double> > g;
    g = g1;

    std::cout << g.name() << "  " << g(complex_var) << std::endl;
    std::cout << g.name() << "  grad: " << g.grad(complex_var, 0) << std::endl;
    std::cout << g.name() << "  hess: " << g.hess(complex_var, 0, 1) << std::endl;



    return 0;
}
