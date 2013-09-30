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
//#include<fstream>
//#include<istream>
//#include<cstdlib>
#include<cstring>
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

#include "Poly.hh"

using namespace PRISMS;

//using namespace std;
//using namespace GiNaC;

class Class
{
public:
    template<typename T>
    void operator=(T &variable)
    {
        std::cout << "is it not a pointer! " << std::endl;
    }
    template<typename T>
    void operator=(T *&variable)
    {
        std::cout << "is it a pointer! " << std::endl;
    }
};

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

    Class A;

    double a;
    double *b;

    A = a;
    A = b;


    BP_Vec<double> var;
    var.add(2.1);

    Quadratic<BP_Vec> fq;

    std::cout << fq.name() << "  " << fq(var) << std::endl;



    Cubic<BP_Vec> fc;

    std::cout << fc.name() << "  " << fc(var) << std::endl;



    PBaseFunction<BP_Vec, double, double> *g;

    g = fq.clone();

    std::cout << (*g).name() << "  " << (*g)(var) << std::endl;


    Quadratic<BP_Vec> *k;

    k = fq.clone();

    std::cout << (*k).name() << "  " << (*k)(var) << std::endl;


    PFunction<BP_Vec, double, double> h;
    h.set(k);
    std::cout << h.name() << "  " << h(var) << std::endl;
    h = Cubic<BP_Vec>();
    std::cout << h.name() << "  " << h(var) << std::endl;


    delete g;
    delete k;

    return 0;
}
