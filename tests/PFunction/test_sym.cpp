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
    // --------------------------------------------------------------------------------
    // Test PRealSymFunction:
    {
        std::cout << "\n\n--- Test PRealSymFunction --- \n\n";
        
        GiNaC::symbol x("x"), y("y");
        std::vector<double> var;
        var.push_back(2.0);
        var.push_back(3.0);

        std::vector<GiNaC::symbol> sym;
        sym.push_back(x);
        sym.push_back(y);

        GiNaC::ex e = x * x + y * y + x * y;

        std::cout << "f = " << e << std::endl;

        PRISMS::PRealSymFunction<std::vector<double> > f;
        f.set("f", sym, e);
        
        std::cout << "\nEvaluate at x == " << var[0] << ", y == " << var[1] << ": " << std::endl;

        std::cout << f.name() << ":  " << f(var) << std::endl;
        std::cout << f.name() << " grad x: " << f.grad(var, 0) << std::endl;
        std::cout << f.name() << " hess x,y: " << f.hess(var, 0, 1) << std::endl;
    }

    // --------------------------------------------------------------------------------
    // Test PComplexSymFunction:
    {
        std::cout << "\n\n--- Test PComplexSymFunction --- \n\n";
        
        GiNaC::symbol x("x"), y("y");
        
        GiNaC::ex e = x * x + GiNaC::I * y * y + exp(GiNaC::I * x * y);
        
        std::cout << "g = " << e << std::endl;

        std::vector< std::complex<double> > complex_var;
        complex_var.push_back(std::complex<double>(2.0, 1.0));
        complex_var.push_back(std::complex<double>(3.0, 0.0));
        
        std::vector<GiNaC::symbol> sym;
        sym.push_back(x);
        sym.push_back(y);

        PRISMS::PComplexSymFunction<std::vector<std::complex<double> > > g1;
        g1.set("g", sym, e);

        PRISMS::PFunction<std::vector<std::complex<double> >, std::complex<double> > g;
        g = g1;
        
        std::cout << "\nEvaluate at x == " << complex_var[0] << ", y == " << complex_var[1] << ": " << std::endl;

        std::cout << g.name() << ":  " << g(complex_var) << std::endl;
        std::cout << g.name() << " grad x: " << g.grad(complex_var, 0) << std::endl;
        std::cout << g.name() << " hess x,y: " << g.hess(complex_var, 0, 1) << std::endl;
    }
    
    
    
    // --------------------------------------------------------------------------------
    // Test PRealSymBasisSet:
    {
        std::cout << "\n\n--- Test PRealSymRecursBasisSet --- \n\n";
        
        // Generate 20 chebyshev polynomials
        
        // create a factory
        int N = 5; 
        GiNaC::symbol x("x"), phi0("phi0"), phi1("phi1"); 
        
        std::vector<GiNaC::symbol> phi_sym(2);
        phi_sym[0] = phi0;
        phi_sym[1] = phi1;
        
        std::vector<GiNaC::ex> phi_init(2);
        phi_init[0] = 1;
        phi_init[1] = x;
        
        GiNaC::ex e_gen = 2*x*phi1 - phi0;
        
        PRISMS::PRealSymRecursBasisSet chebyshev_factory( N, x, phi_sym, phi_init, e_gen);
        
        // generate basis functions
        std::vector<PRISMS::PRealSymBasisFunction*> chebyshev;
        chebyshev.resize(N, NULL);
        for( int i = 0; i < N; i++)
            chebyshev[i] = chebyshev_factory.clone_basis_function(i);
        
        // print them
        std::cout << " Chebyshev polynomials: " << std::endl;
        for( int i = 0; i < N; i++)
        {
            std::cout << "i: " << i << "  ::  " << chebyshev[i]->_e << std::endl;
        }
        
        // evaluate them
        std::cout << "\n Chebyshev polynomials at x == 0.0: " << std::endl;
        for( int i = 0; i < N; i++)
        {
            std::cout << "i: " << i << "  ::  " << (*chebyshev[i])(0.0) << std::endl;
        }
        
        // remember to delete anything created by a factory
        for( int i = 0; i < chebyshev.size(); i++)
            delete chebyshev[i];
        
        
        
        // --------------------------------------------------------------------------------
        // Test PSeriesFunction:
        
        std::cout << "\n\n--- Test PSeriesFunction --- \n\n";
        
                
        std::vector< PRISMS::PBasisSet<double, double> > 
          basis_factories;
        basis_factories.push_back(chebyshev_factory);
        basis_factories.push_back(chebyshev_factory);
        basis_factories.push_back(chebyshev_factory);
        
        
        //std::vector< PRISMS::PBasisSet<double, double> > basis_set;
        //basis_set.push_back(chebyshev_factory);
        //basis_set.push_back(chebyshev_factory);
        //basis_set.push_back(chebyshev_factory);
        
        
        std::cout << "Constructing PSeriesFunction..." << std::endl;
        
        
        PRISMS::PSeriesFunction<double, double, std::vector<double>, std::vector<int> > 
          fxy( 0.0, 1.0, basis_factories);
        
        std::cout << " Order: " << fxy._order << std::endl;
        std::cout << " dim: " << fxy._dim << std::endl;
        std::cout << " unroll: " << fxy._unroll << std::endl;
        std::cout << " Tensor volume: " << fxy.volume() << std::endl;
        
        
        std::vector<int> term(fxy.order());
        
        // set coefficients
        for( int i=0; i<fxy.volume(); i++)
        {
            fxy.coeff(i) = fxy.volume() - i;
        }
        
        //fxy.coeff(0) = 50.0;
        
        //term[0] = 2; term[1] = 0;
        //fxy.coeff(term) = 30.0;
        
        std::vector<double> var;
        var.push_back(0.0);
        var.push_back(0.0);
        var.push_back(0.0);
        
        
        std::cout << "\n Evaluate basis functions at x == " << var[0] << ", y == " << var[1] << ", z == " << var[2] << ": \n";
        for( int b=0; b<fxy.order(); b++)
        {
            for( int i=0; i<fxy.dim(b); i++)
            {
                std::cout << fxy.basis(b, i, var) << " ";
            }
            std::cout << std::endl;
        }
        
        std::cout << "\n Evaluate basis grad functions at x == " << var[0] << ", y == " << var[1] << ", z == " << var[2] << ": \n";
        for( int b=0; b<fxy.order(); b++)
        {
            for( int i=0; i<fxy.dim(b); i++)
            {
                std::cout << fxy.basis_grad(b, i, var) << " ";
            }
            std::cout << std::endl;
        }
        
        std::cout << "\n Evaluate basis hess functions at x == " << var[0] << ", y == " << var[1] << ", z == " << var[2] << ": \n";
        for( int b=0; b<fxy.order(); b++)
        {
            for( int i=0; i<fxy.dim(b); i++)
            {
                std::cout << fxy.basis_hess(b, i, var) << " ";
            }
            std::cout << std::endl;
        }
        
        std::cout << "\n Evaluate basis function products at x == " << var[0] << ", y == " << var[1] << ", z == " << var[2] << ": \n";
        for( int i=0; i<fxy.dim(0); i++)
        {
            std::cout << "-" << i << "-" << std::endl;
            for( int j=0; j<fxy.dim(1); j++)
            {
                for( int k=0; k<fxy.dim(2); k++)
                {
                    term[0] = i;
                    term[1] = j;
                    term[2] = k;
                    std::cout << fxy.basis(term, var) << " ";
                }
                std::cout << std::endl;
            }
            
        }
        
        std::cout << "\n Evaluate basis grad x function products at x == " << var[0] << ", y == " << var[1] << ", z == " << var[2] << ": \n";
        for( int i=0; i<fxy.dim(0); i++)
        {
            std::cout << "-" << i << "-" << std::endl;
            for( int j=0; j<fxy.dim(1); j++)
            {
                for( int k=0; k<fxy.dim(2); k++)
                {
                    term[0] = i;
                    term[1] = j;
                    term[2] = k;
                    std::cout << fxy.basis_grad(term, var,0) << " ";
                }
                std::cout << std::endl;
            }
            
        }
        
        std::cout << "\n Evaluate basis hess y z function products at x == " << var[0] << ", y == " << var[1] << ", z == " << var[2] << ": \n";
        for( int i=0; i<fxy.dim(0); i++)
        {
            std::cout << "-" << i << "-" << std::endl;
            for( int j=0; j<fxy.dim(1); j++)
            {
                for( int k=0; k<fxy.dim(2); k++)
                {
                    term[0] = i;
                    term[1] = j;
                    term[2] = k;
                    std::cout << fxy.basis_hess(term, var, 1, 2) << " ";
                }
                std::cout << std::endl;
            }
            
        }
        
        std::cout << "\n Tensor coefficients: \n";
        for( int i=0; i<fxy.dim(0); i++)
        {
            std::cout << "-" << i << "-" << std::endl;
            for( int j=0; j<fxy.dim(1); j++)
            {
                for( int k=0; k<fxy.dim(2); k++)
                {
                    term[0] = i;
                    term[1] = j;
                    term[2] = k;
                    std::cout << fxy.coeff(term) << " ";
                }
                std::cout << std::endl;
            }
            
        }
        
        double delta = 0.01;
        
        var[0] = var[0] - delta;
        std::cout << "\n f(" << var[0] << ", " << var[1] << ", " << var[2] << ") = " << fxy(var) << std::endl;
        var[0] = var[0] + delta;
        std::cout << " f(" << var[0] << ", " << var[1] << ", " << var[2] << ") = " << fxy(var) << std::endl;
        var[0] = var[0] + delta;
        std::cout << " f(" << var[0] << ", " << var[1] << ", " << var[2] << ") = " << fxy(var) << std::endl;
        var[0] = var[0] - delta;
        
        var[1] = var[1] - delta;
        std::cout << "\n f(" << var[0] << ", " << var[1] << ", " << var[2] << ") = " << fxy(var) << std::endl;
        var[1] = var[1] + delta;
        std::cout << " f(" << var[0] << ", " << var[1] << ", " << var[2] << ") = " << fxy(var) << std::endl;
        var[1] = var[1] + delta;
        std::cout << " f(" << var[0] << ", " << var[1] << ", " << var[2] << ") = " << fxy(var) << std::endl;
        var[1] = var[1] - delta;
        
        var[2] = var[2] - delta;
        std::cout << "\n f(" << var[0] << ", " << var[1] << ", " << var[2] << ") = " << fxy(var) << std::endl;
        var[2] = var[2] + delta;
        std::cout << " f(" << var[0] << ", " << var[1] << ", " << var[2] << ") = " << fxy(var) << std::endl;
        var[2] = var[2] + delta;
        std::cout << " f(" << var[0] << ", " << var[1] << ", " << var[2] << ") = " << fxy(var) << std::endl;
        var[2] = var[2] - delta;
        
        
        std::cout << "\n d f(" << var[0] << ", " << var[1] << ", " << var[2] << ")/dx = " << fxy.grad(var,0) << std::endl;
        std::cout << " d f(" << var[0] << ", " << var[1] << ", " << var[2] << ")/dy = " << fxy.grad(var,1) << std::endl;
        std::cout << " d f(" << var[0] << ", " << var[1] << ", " << var[2] << ")/dz = " << fxy.grad(var,2) << std::endl;
        
        std::cout << "\n d2 f(" << var[0] << ", " << var[1] << ", " << var[2] << ")/dx/dx = " << fxy.hess(var,0,0) << std::endl;
        std::cout << " d2 f(" << var[0] << ", " << var[1] << ", " << var[2] << ")/dx/dy = " << fxy.hess(var,0,1) << std::endl;
        std::cout << " d2 f(" << var[0] << ", " << var[1] << ", " << var[2] << ")/dx/dz = " << fxy.hess(var,0,2) << std::endl;
        std::cout << " d2 f(" << var[0] << ", " << var[1] << ", " << var[2] << ")/dy/dy = " << fxy.hess(var,1,1) << std::endl;
        std::cout << " d2 f(" << var[0] << ", " << var[1] << ", " << var[2] << ")/dy/dz = " << fxy.hess(var,1,2) << std::endl;
        std::cout << " d2 f(" << var[0] << ", " << var[1] << ", " << var[2] << ")/dz/dz = " << fxy.hess(var,2,2) << std::endl;
        
    
    }


    return 0;
}
