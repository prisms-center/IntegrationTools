
#ifndef PEXTERN_HH
#define PEXTERN_HH

#include<cstring>
#include<iostream>
#include<vector>
#include<cstdlib>

#include "PFunction.hh"
#include "PLibrary.hh"

// In future, might have more complicated OutType, 
//   so make all have 'void' return and pass everything by reference


extern "C"
{
    // Functions for using a PSimpleBase externally (say Python or Fortran)
    //   written for VarContainer=double*, OutType=double, hence 'dsd' in function names
    
    void PSimpleFunction_dsd_new(char* name, PRISMS::PSimpleBase<double*,double>* &f)
    { 
        std::cout << "!!new: " << std::string(name) << "!!" << std::endl;
        PRISMS::PLibrary::checkout(std::string(name), f);
    };
    
    void PSimpleFunction_dsd_delete(PRISMS::PSimpleBase<double*,double>* &f)
    { 
        delete f;
        f = NULL;
    };
    
    void PSimpleFunction_dsd_name(PRISMS::PSimpleBase<double*,double> *f, char* name)
    {
        std::strcpy(name, f->name().c_str());
    };
    
    void PSimpleFunction_dsd_calc( PRISMS::PSimpleBase<double*,double> *f, double* var, double &val)
    {
        val = (*f)(var);
    };
    
    void PSimpleFunction_dsd_get( PRISMS::PSimpleBase<double*,double> *f, double  &val)
    {
        val = (*f)();
    };
    
    
    
    
    
    // Functions for using a PSimpleBase externally (say Python or Fortran)
    //   written for VarContainer=double, OutType=double, hence 'dd' in function names
    
    void PSimpleFunction_dd_new(char* name, PRISMS::PSimpleBase<double,double>* &f)
    { 
        std::cout << "!!new: " << std::string(name) << "!!" << std::endl;
        PRISMS::PLibrary::checkout(std::string(name), f);
    };
    
    void PSimpleFunction_dd_delete(PRISMS::PSimpleBase<double,double>* &f)
    { 
        delete f;
        f = NULL;
    };
    
    void PSimpleFunction_dd_name(PRISMS::PSimpleBase<double,double> *f, char* name)
    {
        std::strcpy(name, f->name().c_str());
    };
    
    void PSimpleFunction_dd_calc( PRISMS::PSimpleBase<double,double> *f, double var, double &val)
    {
        val = (*f)(var);
    };
    
    void PSimpleFunction_dd_get( PRISMS::PSimpleBase<double,double> *f, double  &val)
    {
        val = (*f)();
    };
    
    
    
    
    
    // Functions for using a PFuncBase externally (say Python or Fortran)
    //   written for VarContainer=double*, OutType=double, hence 'dsd' in function names
    
    void PFunction_dsd_new(char* name, PRISMS::PFuncBase<double*,double>* &f)
    { 
        PRISMS::PLibrary::checkout(std::string(name), f);
    };
    
    void PFunction_dsd_delete(PRISMS::PFuncBase<double*,double>* &f)
    { 
        delete f;
        f = NULL;
    };
    
    void PFunction_dsd_name(PRISMS::PFuncBase<double*,double>* f, char* name)
    {
        std::strcpy(name, f->name().c_str());
    };
    
    void PFunction_dsd_size(PRISMS::PFuncBase<double*,double>* f, int &size)
    {
        size = f->size();
    };
    
    void PFunction_dsd_var_name(PRISMS::PFuncBase<double*,double>* f, int i, char* var_name)
    {
        std::strcpy(var_name, f->var_name(i).c_str());
    };
    
    void PFunction_dsd_var_description(PRISMS::PFuncBase<double*,double>* f, int i, char* var_description)
    {
        std::strcpy(var_description, f->var_description(i).c_str());
    };
    
    //void PFunction_dsd_simplefunc(PRISMS::PFuncBase<double*,double> *f, PSimpleBase<double*, double> *simplefunc);
    //void PFunction_dsd_grad_simplefunc(PRISMS::PFuncBase<double*,double> *f, int *di, PSimpleBase<double*, double> *simplefunc);
    //void PFunction_dsd_hess_simplefunc(PRISMS::PFuncBase<double*,double> *f, int *di, int *dj, PSimpleBase<double*, double> *simplefunc);
    
    void PFunction_dsd_calc(PRISMS::PFuncBase<double*,double>* f, double* var, double &val)
    {
        val = (*f)(var);
    };
    
    void PFunction_dsd_calc_grad(PRISMS::PFuncBase<double*,double>* f, double* var, int di, double &val)
    {
        val = (*f).grad(var, di);
    };
    
    void PFunction_dsd_calc_hess(PRISMS::PFuncBase<double*,double>* f, double* var, int di, int dj, double &val)
    {
        val = (*f).hess(var, di, dj);
    };
    
    void PFunction_dsd_eval(PRISMS::PFuncBase<double*,double>* f, double* var)
    {
        (*f)(var);
    };
    
    void PFunction_dsd_eval_grad(PRISMS::PFuncBase<double*,double>* f, double* var, int di)
    {
        (*f).grad(var, di);
    };
    
    void PFunction_dsd_eval_hess(PRISMS::PFuncBase<double*,double>* f, double* var, int di, int dj)
    {
        (*f).hess(var, di, dj);
    };
    
    void PFunction_dsd_get(PRISMS::PFuncBase<double*,double>* f, double &val)
    {
        val = (*f)();
    };
    
    void PFunction_dsd_get_grad(PRISMS::PFuncBase<double*,double>* f, int di, double &val)
    {
        val = (*f).grad(di);
    };
    
    void PFunction_dsd_get_hess(PRISMS::PFuncBase<double*,double>* f, int di, int dj, double &val)
    {
        val = (*f).hess(di, dj);
    };
    
    
    
    
    
    // Functions for using a PBasisSetBase externally (say Python or Fortran)
    //   written for InType=double, OutType=double, hence 'dd' in function names
    
    void PBasisSet_dd_new(char* name, PRISMS::PBasisSetBase<double,double>* &b, int N)
    { 
        PRISMS::PLibrary::checkout(std::string(name), b, N);
    };
    
    void PBasisSet_dd_delete(PRISMS::PBasisSetBase<double,double>* &b)
    { 
        delete b;
        b = NULL;
    };
    
    void PBasisSet_dd_name(PRISMS::PBasisSetBase<double,double>* b, char* name)
    {
        std::strcpy(name, b->name().c_str());
    };
    
    void PBasisSet_dd_description(PRISMS::PBasisSetBase<double,double>* b, char* description)
    {
        std::strcpy(description, b->description().c_str());
    };
    
    void PBasisSet_dd_size(PRISMS::PBasisSetBase<double,double>* b, int &size)
    {
        size = b->size();
    };
    
    void PBasisSet_dd_resize(PRISMS::PBasisSetBase<double,double>* b, int N)
    {
        b->resize(N);
    };
    
    void PBasisSet_dd_max_size(PRISMS::PBasisSetBase<double,double>* b, int &max_size)
    {
        max_size = b->max_size();
    };
    
    //void PBasisSet_dd_basis_function(PRISMS::PFuncBase<double*,double> *b, int* term, PFuncBase<double,double> *f);
    
    void PBasisSet_dd_calc(PRISMS::PBasisSetBase<double,double>* b, int term, double var, double &val)
    {
        val = (*b)(term, var);
    };
    
    void PBasisSet_dd_calc_grad(PRISMS::PBasisSetBase<double,double>* b, int term, double var, double &val)
    {
        val = (*b).grad(term, var);
    };
    
    void PBasisSet_dd_calc_hess(PRISMS::PBasisSetBase<double,double>* b, int term, double var, double &val)
    {
        val = (*b).hess(term, var);
    };
        
    void PBasisSet_dd_eval(PRISMS::PBasisSetBase<double,double>* b, double var)
    {
        (*b).eval(var);
    };
    
    void PBasisSet_dd_eval_grad(PRISMS::PBasisSetBase<double,double>* b, double var)
    {
        (*b).eval_grad(var);
    };
    
    void PBasisSet_dd_eval_hess(PRISMS::PBasisSetBase<double,double>* b, double var)
    {
        (*b).eval_hess(var);
    };
    
    void PBasisSet_dd_get(PRISMS::PBasisSetBase<double,double>* b, int term, double &val)
    {
        val = (*b)(term);
    };
    
    void PBasisSet_dd_get_grad(PRISMS::PBasisSetBase<double,double>* b, int term, double &val)
    {
        val = (*b).grad(term);
    };
    
    void PBasisSet_dd_get_hess(PRISMS::PBasisSetBase<double,double>* b, int term, double &val)
    {
        val = (*b).hess(term);
    };
    
    //void PBasisSet_dd_getall(PRISMS::PBasisSetBase<double,double>* b, const double* &val);
    //void PBasisSet_dd_getall_grad(PRISMS::PBasisSetBase<double,double>* b, const double* &val);
    //void PBasisSet_dd_getall_hess(PRISMS::PBasisSetBase<double,double>* b, const double* &val);
    
}


#endif