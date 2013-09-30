/*
 *  template.cpp
 *
 *
 *  Created by Brian Puchala on ?.
 *	All rights reserved.
 *
 *
 */



//#include<iostream>
//#include<fstream>
//#include<istream>
//#include<cstdlib>
#include<cstring>
#include<complex>
#include<vector>
//#include<cmath>
//#include<stdlib.h>
//#include<stdio.h>
//#include<iomanip>
//#include<time.h>
//#include<sstream>
#include <ginac/ginac.h>    // compile with: -lcln -lginac

#include "PSymFunction.hh"

template<typename T>
std::ostream& operator<<(std::ostream &sout, const std::vector<T> &v)
{
    for( int i=0; i<v.size(); i++)
        sout << v[i] << " ";
    return sout;
}

int main(int argc, char *argv[])
{
    // Test PRealSymFunction:

    GiNaC::symbol x("x"), y("y");
    GiNaC::symbol a;
    a = x;
    std::vector<double> var;
    var.push_back(2.0);
    var.push_back(3.0);

    std::vector<GiNaC::symbol> sym;
    sym.push_back(x);
    sym.push_back(y);

    GiNaC::ex e = x * x + y * y + x * y;

    std::cout << "sym: " << sym << std::endl;

    PRISMS::PRealSymFunction<std::vector<double>, std::vector<int> > f;
    f.set("my_func", sym, e);

    std::cout << f.name() << "  " << f(var) << std::endl;
    std::cout << f.name() << "  grad: " << f.grad(var, 0) << std::endl;
    std::cout << f.name() << "  hess: " << f.hess(var, 0, 1) << std::endl;


    // Test PComplexSymFunction:

    e = x * x + GiNaC::I * y * y + exp(GiNaC::I * x * y);

    std::vector< std::complex<double> > complex_var;
    complex_var.push_back(std::complex<double>(2.0, 0.0));
    complex_var.push_back(std::complex<double>(3.0, 0.0));

    PRISMS::PComplexSymFunction<std::vector<std::complex<double> >, std::vector<int> > g1;
    g1.set("my_complex_func", sym, e);

    PRISMS::PFunction<std::complex<double>, std::complex<double>, std::vector<std::complex<double> >, std::vector<int> > g;
    g = g1;

    std::cout << g.name() << "  " << g(complex_var) << std::endl;
    std::cout << g.name() << "  grad: " << g.grad(complex_var, 0) << std::endl;
    std::cout << g.name() << "  hess: " << g.hess(complex_var, 0, 1) << std::endl;



    return 0;
}
