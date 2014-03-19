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

DECLARE_FUNCTION_3P(f)
DECLARE_FUNCTION_1P(c)
DECLARE_FUNCTION_1P(op)
DECLARE_FUNCTION_1P(E)

REGISTER_FUNCTION(f, dummy())
REGISTER_FUNCTION(c, dummy())
REGISTER_FUNCTION(op, dummy())
REGISTER_FUNCTION(E, dummy())


// assume 3d space for now

GiNaC::matrix grad( const GiNaC::ex &f, const GiNaC::matrix &x)
{
    using namespace GiNaC;
    
    matrix gradx = ex_to<matrix>(symbolic_matrix(3,1,"gradx"));
    
    gradx(0,0) = f.diff(ex_to<symbol>(x(0,0)));
    gradx(1,0) = f.diff(ex_to<symbol>(x(1,0)));
    gradx(2,0) = f.diff(ex_to<symbol>(x(2,0)));
    
    return gradx;
};

GiNaC::ex div( const GiNaC::matrix &f, const GiNaC::matrix &x)
{
    using namespace GiNaC;
    
    matrix gradx = grad(f,x);
    return f(0,0).diff(ex_to<symbol>(x(0,0))) + 
           f(1,0).diff(ex_to<symbol>(x(1,0))) + 
           f(2,0).diff(ex_to<symbol>(x(2,0)));
};

GiNaC::ex laplacian( const GiNaC::ex &f, const GiNaC::matrix &x)
{
    using namespace GiNaC;
    
    return div( grad(f,x), x);
};


int main(int argc, char *argv[])
{
    using namespace GiNaC;

    symbol r_sym("r"), e1_sym("e1"), e2_sym("e2"), e3_sym("e3");
    symbol x_sym("x"), y_sym("y"), z_sym("z");
    
    matrix e1(3,1);
    e1(0,0) = 1;
    e1(1,0) = 0;
    e1(2,0) = 0;
    
    matrix e2(3,1);
    e2(0,0) = 0;
    e2(1,0) = 1;
    e2(2,0) = 0;
    
    matrix e3(3,1);
    e3(0,0) = 0;
    e3(1,0) = 0;
    e3(2,0) = 1;
   
    matrix r = ex_to<matrix>(symbolic_matrix(3, 1, "r"));
    ex x = ex_to<symbol>(r(0,0));
    ex y = ex_to<symbol>(r(1,0));
    ex z = ex_to<symbol>(r(2,0));
    
    
    ex f = x*x + x*y + x*z + y*y + y*z + z*z;
    
    matrix gradx = grad( f, r);
    
    std::cout << "\n";
    std::cout << "grad: " << gradx(0,0).subs(lst(r(0,0)==x_sym,r(1,0)==y_sym,r(2,0)==z_sym)) << std::endl;
    std::cout << "\n";
    std::cout << "laplacian: " << laplacian(f,r) << std::endl;
    std::cout << "\n";
    std::cout << "df/dx : " << collect( gradx(0,0).subs(r==r_sym).subs(e1==e1_sym), e1_sym) << std::endl;
    std::cout << "df/dy : " << collect( gradx(1,0).subs(r==r_sym).subs(e2==e2_sym), e2_sym) << std::endl;
    std::cout << "df/dz : " << collect( gradx(2,0).subs(r==r_sym).subs(e3==e3_sym), e3_sym) << std::endl;
    
    
    return 0;
}
