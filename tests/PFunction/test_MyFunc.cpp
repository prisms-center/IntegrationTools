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

#include "PFunction.hh"
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
    return 2.0*(var[2]*var[2]*var[2])*(var[3]*var[3])*((var[0]*var[0])*(var[0]*var[0]))+2.0*var[2]*(var[3]*(var[3]*var[3])*(var[3]*var[3]))*var[1]+2.0*exp(var[2]*var[3])*(var[0]*var[0]);
}

template<class T>
double nonvirtual(const T &var, int di)
{
    if( di == 0)
        return 4.0*var[0]+8.0*(var[0]*var[0]*var[0]);
    else if( di == 1)
        return 2.0;
    return 0.0;
}

template<class T>
double nonvirtual(const T &var, int di, int dj)
{
    if( di == 0)
    {
        if( dj == 0)
            return 24.0*(var[0]*var[0])+4.0;
        else if( dj == 0)
            return 0.0;
    }
    else if( di == 1)
    {
        if( dj == 0)
            return 0.0;
        else if( dj == 1)
            return 0.0;
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
    
    double d = 0.0;
    double count = 1e7;
    srand( time(NULL));
    int di = 0; //rand() % 2;
    int dj = 0; //rand() % 2;
    
    std::cout << "\n --- val --- \n" << std::endl;
    
    
    
    d = 0.0;
    timer.set_start();
    for( double i=0; i<count; i++)
    {
        var[0]=(1.0*rand())/RAND_MAX;
        d += f(var);
    }
    std::cout << "f sum: " << d << std::endl;
    d = timer.total_time_s();
    std::cout << "f time: " << d << std::endl;
    
    d = 0.0;
    timer.set_start();
    for( double i=0; i<count; i++)
    {
        var[0]=(1.0*rand())/RAND_MAX;
        d += g(var);
    }
    std::cout << "g sum: " << d << std::endl;
    d = timer.total_time_s();
    std::cout << "g time: " << d << std::endl;
    
    /*
    d = 0.0;
    timer.set_start();
    for( double i=0; i<count; i++)
        d += h(var);
    std::cout << "h sum: " << d << std::endl;
    d = timer.total_time_s();
    std::cout << "h time: " << d << std::endl;
    */
    
    timer.set_start();
    d = 0.0;
    for( double i=0; i<count; i++)
    {
        var[0]=(1.0*rand())/RAND_MAX;
        //d += 2.0*(var[0]*var[0])+2.0*var[1]+2.0*((var[0]*var[0])*(var[0]*var[0]));
        d += 2.0*(var[2]*var[2]*var[2])*(var[3]*var[3])*((var[0]*var[0])*(var[0]*var[0]))+2.0*var[2]*(var[3]*(var[3]*var[3])*(var[3]*var[3]))*var[1]+2.0*exp(var[2]*var[3])*(var[0]*var[0]);
    }
    std::cout << "code sum: " << d << std::endl;
    d = timer.total_time_s();
    std::cout << "code time: " << d << std::endl;
    
    timer.set_start();
    d = 0.0;
    for( double i=0; i<count; i++)
    {
        var[0]=(1.0*rand())/RAND_MAX;
        d += nonvirtual(var);
    }
    std::cout << "nonvirtual sum: " << d << std::endl;
    d = timer.total_time_s();
    std::cout << "nonvirtual time: " << d << std::endl;
    
    std::cout << "\n --- grad --- \n" << std::endl;
    
    d = 0.0;
    timer.set_start();
    for( double i=0; i<count; i++)
    {
        var[0]=(1.0*rand())/RAND_MAX;
        d += f.grad(var,di);
    }
    std::cout << "f sum: " << d << std::endl;
    d = timer.total_time_s();
    std::cout << "f time: " << d << std::endl;
    
    d = 0.0;
    timer.set_start();
    for( double i=0; i<count; i++)
    {
        var[0]=(1.0*rand())/RAND_MAX;
        d += g.grad(var, di);
    }
    std::cout << "g sum: " << d << std::endl;
    d = timer.total_time_s();
    std::cout << "g time: " << d << std::endl;
    
    /*
    d = 0.0;
    timer.set_start();
    for( double i=0; i<count; i++)
        d += hgrad(var);
    std::cout << "h sum: " << d << std::endl;
    d = timer.total_time_s();
    std::cout << "h time: " << d << std::endl;
    */
    
    timer.set_start();
    d = 0.0;
    for( double i=0; i<count; i++)
    {
        var[0]=(1.0*rand())/RAND_MAX;
        //d += 4.0*var[0]+8.0*(var[0]*var[0]*var[0]);
        d += 8.0*(var[2]*var[2]*var[2])*(var[3]*var[3])*(var[0]*var[0]*var[0])+4.0*exp(var[2]*var[3])*var[0];
    }
    std::cout << "code sum: " << d << std::endl;
    d = timer.total_time_s();
    std::cout << "code time: " << d << std::endl;
    
    timer.set_start();
    d = 0.0;
    for( double i=0; i<count; i++)
    {
        var[0]=(1.0*rand())/RAND_MAX;
        d += nonvirtual(var, di);
    }
    std::cout << "nonvirtual sum: " << d << std::endl;
    d = timer.total_time_s();
    std::cout << "nonvirtual time: " << d << std::endl;
    
    std::cout << "\n --- hess --- \n" << std::endl;
    
    d = 0.0;
    timer.set_start();
    for( double i=0; i<count; i++)
    {
        var[0]=(1.0*rand())/RAND_MAX;
        d += f.hess(var,di,dj);
    }
    std::cout << "f sum: " << d << std::endl;
    d = timer.total_time_s();
    std::cout << "f time: " << d << std::endl;
    
    d = 0.0;
    timer.set_start();
    for( double i=0; i<count; i++)
    {
        var[0]=(1.0*rand())/RAND_MAX;
        d += g.hess(var, di,dj);
    }
    std::cout << "g sum: " << d << std::endl;
    d = timer.total_time_s();
    std::cout << "g time: " << d << std::endl;
    
    /*
    d = 0.0;
    timer.set_start();
    for( double i=0; i<count; i++)
        d += hhess(var);
    std::cout << "h sum: " << d << std::endl;
    d = timer.total_time_s();
    std::cout << "h time: " << d << std::endl;
    */
    
    timer.set_start();
    d = 0.0;
    for( double i=0; i<count; i++)
    {
        var[0]=(1.0*rand())/RAND_MAX;
        //d += 24.0*(var[0]*var[0])+4.0;
        d += 4.0*exp(var[2]*var[3])+24.0*(var[2]*var[2]*var[2])*(var[3]*var[3])*(var[0]*var[0]);
    }
    std::cout << "code sum: " << d << std::endl;
    d = timer.total_time_s();
    std::cout << "code time: " << d << std::endl;
    
    timer.set_start();
    d = 0.0;
    for( double i=0; i<count; i++)
    {
        var[0]=(1.0*rand())/RAND_MAX;
        d += nonvirtual(var, di, dj);
    }
    std::cout << "nonvirtual sum: " << d << std::endl;
    d = timer.total_time_s();
    std::cout << "nonvirtual time: " << d << std::endl;

    return 0;
}
