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
#include<vector>
//#include<cmath>
//#include<stdlib.h>
//#include<stdio.h>
//#include<iomanip>
//#include<time.h>
//#include<sstream>
//#include "../../external/MersenneTwister/MersenneTwister.h"

#include "Poly.hh"


template<typename T>
std::ostream& operator<<(std::ostream &sout, const std::vector<T> &v)
{
    for( int i=0; i<v.size(); i++)
        sout << v[i] << " ";
    return sout;
}


int main(int argc, char *argv[])
{
    
    std::vector<double> var;
    var.push_back(2.1);

    PRISMS::Quadratic<std::vector<double>, std::vector<int> > fq;

    std::cout << fq.name() << "  " << fq(var) << std::endl;



    PRISMS::Cubic<std::vector<double>, std::vector<int> > fc;

    std::cout << fc.name() << "  " << fc(var) << std::endl;



    PRISMS::PBaseFunction<double, double, std::vector<double>, std::vector<int> > *g;

    g = fq.clone();

    std::cout << (*g).name() << "  " << (*g)(var) << std::endl;


    PRISMS::Quadratic<std::vector<double>, std::vector<int> > *k;

    k = fq.clone();

    std::cout << (*k).name() << "  " << (*k)(var) << std::endl;


    PRISMS::PFunction<double, double, std::vector<double>, std::vector<int> > h;
    h.set(k);
    std::cout << h.name() << "  " << h(var) << std::endl;
    h = PRISMS::Cubic<std::vector<double>, std::vector<int> >();
    std::cout << h.name() << "  " << h(var) << std::endl;


    delete g;
    
    return 0;
}
