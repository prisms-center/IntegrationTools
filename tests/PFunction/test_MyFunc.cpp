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

#include "IntegrationTools/PFunction.hh"
#include "MyFunc.hh"
#include "BP_StopWatch.hh"


template<typename T>
std::ostream& operator<<(std::ostream &sout, const std::vector<T> &v)
{
    for( int i=0; i<v.size(); i++)
        sout << v[i] << " ";
    return sout;
}

template<class T>
double nonvirtual(const T &var)
{
    return (var[0]*var[0])*var[1]+(var[0]*var[0]*var[0])+var[0]*(var[1]*var[1])+(var[1]*var[1]*var[1]);
}

template<class T>
double nonvirtual(const T &var, int di)
{
    if( di == 0)
        return 2.0*var[1]*var[0]+3.0*(var[0]*var[0])+(var[1]*var[1]);
    else if( di == 1)
        return 3.0*(var[1]*var[1])+2.0*var[1]*var[0]+(var[0]*var[0]);
    return 0.0;
}

template<class T>
double nonvirtual(const T &var, int di, int dj)
{
    if( di == 0)
    {
        if( dj == 0)
            return 6.0*var[0]+2.0*var[1];
        else if( dj == 1)
            return 2.0*var[0]+2.0*var[1];
    }
    else if( di == 1)
    {
        if( dj == 0)
            return 2.0*var[0]+2.0*var[1];
        else if( dj == 1)
            return 2.0*var[0]+6.0*var[1];
    }
    return 0.0;
}

int main(int argc, char *argv[])
{
    BP::BP_StopWatch timer;
    PRISMS::MyFunc<std::vector<double> > f;
    PRISMS::PFunction<std::vector<double>, double> g;
    //PRISMS::MyFunc_f<std::vector<double> > h;
    //PRISMS::MyFunc_grad_0<std::vector<double> > hgrad;
    //PRISMS::MyFunc_hess_0_0<std::vector<double> > hhess;
    g = f;
    
    std::vector<double> var;
    var.push_back(3.0);
    var.push_back(2.0);
    
    std::cout << "f(var): " << f(var) << std::endl;
    std::cout << "f(): " << f() << std::endl;
    
    std::cout << "f.grad(var,0): " << f.grad(var,0) << std::endl;
    std::cout << "f.grad(var,1): " << f.grad(var,1) << std::endl;
    std::cout << "f.grad(0): " << f.grad(0) << std::endl;
    std::cout << "f.grad(1): " << f.grad(1) << std::endl;
    
    std::cout << "f.hess(var,0,0): " << f.hess(var,0,0) << std::endl;
    std::cout << "f.hess(var,0,1): " << f.hess(var,0,1) << std::endl;
    std::cout << "f.hess(var,1,0): " << f.hess(var,1,0) << std::endl;
    std::cout << "f.hess(var,1,1): " << f.hess(var,1,1) << std::endl;
    
    double codet;
    double d = 0.0;
    double tmp;
    double count = 1e8;
    srand( time(NULL));
    int di = 0; //rand() % 2;
    int dj = 0; //rand() % 2;
    
    std::cout << "\n --- val --- \n" << std::endl;
    
    
    
    timer.set_start();
    d = 0.0;
    for( double i=0; i<count; i++)
    {
        var[0]=(1.0*rand())/RAND_MAX;
        var[1]=(1.0*rand())/RAND_MAX;
        //d += 2.0*(var[0]*var[0])+2.0*var[1]+2.0*((var[0]*var[0])*(var[0]*var[0]));
        d += tmp = (var[0]*var[0])*var[1]+(var[0]*var[0]*var[0])+var[0]*(var[1]*var[1])+(var[1]*var[1]*var[1]);
    }
    std::cout << "code sum: " << d << std::endl;
    d = timer.total_time_s();
    std::cout << "code time: " << d << std::endl << std::endl;
    codet = d;
    
    timer.set_start();
    d = 0.0;
    for( double i=0; i<count; i++)
    {
        var[0]=(1.0*rand())/RAND_MAX;
        var[1]=(1.0*rand())/RAND_MAX;
        d += tmp = nonvirtual(var);
    }
    std::cout << "nonvirtual sum: " << d << std::endl;
    d = timer.total_time_s();
    std::cout << "nonvirtual time: " << d << std::endl;
    std::cout << "relative to code: " << d/codet << std::endl << std::endl;
    
    timer.set_start();
    d = 0.0;
    for( double i=0; i<count; i++)
    {
        var[0]=(1.0*rand())/RAND_MAX;
        var[1]=(1.0*rand())/RAND_MAX;
        d += f(var);
    }
    std::cout << "Specialized PFunction sum: " << d << std::endl;
    d = timer.total_time_s();
    std::cout << "Specialized PFunction time: " << d << std::endl;
    std::cout << "relative to code: " << d/codet << std::endl << std::endl;
    
    timer.set_start();
    d = 0.0;
    for( double i=0; i<count; i++)
    {
        var[0]=(1.0*rand())/RAND_MAX;
        var[1]=(1.0*rand())/RAND_MAX;
        d += g(var);
    }
    std::cout << "PFunction sum: " << d << std::endl;
    d = timer.total_time_s();
    std::cout << "PFunction time: " << d << std::endl;
    std::cout << "relative to code: " << d/codet << std::endl << std::endl;
    
    
    
    
    
    
    std::cout << "\n --- grad --- \n" << std::endl;
    
    timer.set_start();
    d = 0.0;
    for( double i=0; i<count; i++)
    {
        var[0]=(1.0*rand())/RAND_MAX;
        var[1]=(1.0*rand())/RAND_MAX;
        //d += 4.0*var[0]+8.0*(var[0]*var[0]*var[0]);
        d += tmp = 2.0*var[1]*var[0]+3.0*(var[0]*var[0])+(var[1]*var[1]);
    }
    std::cout << "code sum: " << d << std::endl;
    d = timer.total_time_s();
    std::cout << "code time: " << d << std::endl << std::endl;
    codet = d;
    
    timer.set_start();
    d = 0.0;
    for( double i=0; i<count; i++)
    {
        var[0]=(1.0*rand())/RAND_MAX;
        var[1]=(1.0*rand())/RAND_MAX;
        d += tmp = nonvirtual(var, di);
    }
    std::cout << "nonvirtual sum: " << d << std::endl;
    d = timer.total_time_s();
    std::cout << "nonvirtual time: " << d << std::endl;
    std::cout << "relative to code: " << d/codet << std::endl << std::endl;
    
    timer.set_start();
    d = 0.0;
    for( double i=0; i<count; i++)
    {
        var[0]=(1.0*rand())/RAND_MAX;
        var[1]=(1.0*rand())/RAND_MAX;
        d += f.grad(var,di);
    }
    std::cout << "Specialized PFunction sum: " << d << std::endl;
    d = timer.total_time_s();
    std::cout << "Specialized PFunction time: " << d << std::endl;
    std::cout << "relative to code: " << d/codet << std::endl << std::endl;
    
    timer.set_start();
    d = 0.0;
    for( double i=0; i<count; i++)
    {
        var[0]=(1.0*rand())/RAND_MAX;
        var[1]=(1.0*rand())/RAND_MAX;
        d += g.grad(var, di);
    }
    std::cout << "PFunction sum: " << d << std::endl;
    d = timer.total_time_s();
    std::cout << "PFunction time: " << d << std::endl;
    std::cout << "relative to code: " << d/codet << std::endl << std::endl;
    
    
    
    
    
    
    
    std::cout << "\n --- hess --- \n" << std::endl;
    
    timer.set_start();
    d = 0.0;
    for( double i=0; i<count; i++)
    {
        var[0]=(1.0*rand())/RAND_MAX;
        var[1]=(1.0*rand())/RAND_MAX;
        //d += 24.0*(var[0]*var[0])+4.0;
        d += tmp = 6.0*var[0]+2.0*var[1];
    }
    std::cout << "code sum: " << d << std::endl;
    d = timer.total_time_s();
    std::cout << "code time: " << d << std::endl << std::endl;
    codet = d;
    
    timer.set_start();
    d = 0.0;
    for( double i=0; i<count; i++)
    {
        var[0]=(1.0*rand())/RAND_MAX;
        var[1]=(1.0*rand())/RAND_MAX;
        d += tmp = nonvirtual(var, di, dj);
    }
    std::cout << "nonvirtual sum: " << d << std::endl;
    d = timer.total_time_s();
    std::cout << "nonvirtual time: " << d << std::endl;
    std::cout << "relative to code: " << d/codet << std::endl << std::endl;
    
    timer.set_start();
    d = 0.0;
    for( double i=0; i<count; i++)
    {
        var[0]=(1.0*rand())/RAND_MAX;
        var[1]=(1.0*rand())/RAND_MAX;
        d += f.hess(var,di,dj);
    }
    std::cout << "Specialized PFunction sum: " << d << std::endl;
    d = timer.total_time_s();
    std::cout << "Specialized PFunction time: " << d << std::endl;
    std::cout << "relative to code: " << d/codet << std::endl << std::endl;
    
    timer.set_start();
    d = 0.0;
    for( double i=0; i<count; i++)
    {
        var[0]=(1.0*rand())/RAND_MAX;
        var[1]=(1.0*rand())/RAND_MAX;
        d += g.hess(var, di,dj);
    }
    std::cout << "PFunction sum: " << d << std::endl;
    d = timer.total_time_s();
    std::cout << "PFunction time: " << d << std::endl;
    std::cout << "relative to code: " << d/codet << std::endl << std::endl;
    
    return 0;
}
