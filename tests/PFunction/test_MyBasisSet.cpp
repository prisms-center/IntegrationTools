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

#include "MyBasisSet.hh"


template<typename T>
std::ostream& operator<<(std::ostream &sout, const std::vector<T> &v)
{
    for( int i=0; i<v.size(); i++)
        sout << v[i] << " ";
    return sout;
}


int main(int argc, char *argv[])
{
    
    PRISMS::MyBasisSet bset(30);
    double x = 0.0;
    
    std::cout << "Test evaluations:\n";
    for( int i = 0; i<bset.size(); i++)
    {
        std::cout << "i: " << i << "  " << bset(i,x) << "  " << bset.grad(i,x) << "  " << bset.hess(i,x) << std::endl;
    }
    std::cout << bset() << std::endl;
    std::cout << bset.grad() << std::endl;
    std::cout << bset.hess() << std::endl;
    std::cout << "\n";
    
    
    std::cout << "Test getting basis functions:\n";
    x = 1.0;
    for( int i = 0; i<bset.size(); i++)
    {
        PRISMS::PSimpleFunction<double, double> phi;
        PRISMS::PSimpleFunction<double, double> grad_phi;
        PRISMS::PSimpleFunction<double, double> hess_phi;
        
        phi = bset.basis_function(i).simplefunction();
        grad_phi = bset.basis_function(i).grad_simplefunction(0);
        hess_phi = bset.basis_function(i).hess_simplefunction(0,0);
        
        std::cout << "i: " << i << "  " << phi(x) << "  " << grad_phi(x) << "  " << hess_phi(x) << std::endl;
    }
    std::cout << bset() << std::endl;
    std::cout << "\n";
    
    std::cout << "Eval all..." << std::flush;
    bset(x);
    std::cout << " Done." << std::endl;
    std::cout << bset() << std::endl;
    
    std::cout << "Eval grad all..." << std::flush;
    bset.grad(x);
    std::cout << " Done." << std::endl;
    std::cout << bset.grad() << std::endl;
    
    std::cout << "Eval hess all..." << std::flush;
    bset.hess(x);
    std::cout << " Done." << std::endl;
    std::cout << bset.hess() << std::endl;
    
    std::cout << "Copy Construct..." << std::flush;
    PRISMS::MyBasisSet bset2(bset);
    std::cout << " Done." << std::endl;
    std::cout << bset2() << std::endl;
    
    std::cout << "Resize(10)..." << std::flush;
    bset2.resize(10);
    std::cout << " Done." << std::endl;
    std::cout << bset2() << std::endl;
    
    std::cout << "Resize(20)..." << std::flush;
    bset2.resize(20);
    std::cout << " Done." << std::endl;
    std::cout << bset2() << std::endl;
    
    std::cout << "Assignment..." << std::flush;
    bset2 = bset;
    std::cout << " Done." << std::endl;
    std::cout << bset2() << std::endl;
    
    
    

    return 0;
}
