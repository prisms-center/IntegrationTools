
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
    
    void PSimpleFunction_dsd_new(char* name, PRISMS::PSimpleBase<double*,double>* &f);
    
    void PSimpleFunction_dsd_delete(PRISMS::PSimpleBase<double*,double>* &f);
    
    void PSimpleFunction_dsd_name(PRISMS::PSimpleBase<double*,double>* f, char* name);
    
    void PSimpleFunction_dsd_calc( PRISMS::PSimpleBase<double*,double>* f, double* var, double &val);
    
    void PSimpleFunction_dsd_get( PRISMS::PSimpleBase<double*,double>* f, double &val);
    
    
    
    // Functions for using a PSimpleBase externally (say Python or Fortran)
    //   written for VarContainer=double, OutType=double, hence 'dd' in function names
    
    void PSimpleFunction_dd_new(char* name, PRISMS::PSimpleBase<double,double>* &f);
    
    void PSimpleFunction_dd_delete(PRISMS::PSimpleBase<double,double>* &f);
    
    void PSimpleFunction_dd_name(PRISMS::PSimpleBase<double,double>* f, char* name);
    
    void PSimpleFunction_dd_calc( PRISMS::PSimpleBase<double,double>* f, double var, double &val);
    
    void PSimpleFunction_dd_get( PRISMS::PSimpleBase<double,double>* f, double &val);
    
    
    
    
    
    // Functions for using a PFuncBase externally (say Python or Fortran)
    //   written for VarContainer=double*, OutType=double, hence 'dsd' in function names
    
    void PFunction_dsd_new(char* name, PRISMS::PFuncBase<double*,double>* &f);
    
    void PFunction_dsd_delete(PRISMS::PFuncBase<double*,double>* &f);
    
    void PFunction_dsd_name(PRISMS::PFuncBase<double*,double>* f, char* name);
    
    void PFunction_dsd_size(PRISMS::PFuncBase<double*,double>* f, int &size);
    
    void PFunction_dsd_var_name(PRISMS::PFuncBase<double*,double>* f, int i, char* var_name);
    
    void PFunction_dsd_var_description(PRISMS::PFuncBase<double*,double>* f, int i, char* var_description);
    
    //void PFunction_dsd_simplefunc(PRISMS::PFuncBase<double*,double>* f, PSimpleBase<double*, double>* &simplefunc);
    //void PFunction_dsd_grad_simplefunc(PRISMS::PFuncBase<double*,double>* f, int di, PSimpleBase<double*, double>* &simplefunc);
    //void PFunction_dsd_hess_simplefunc(PRISMS::PFuncBase<double*,double>* f, int di, int dj, PSimpleBase<double*, double>* &simplefunc);
    
    void PFunction_dsd_calc(PRISMS::PFuncBase<double*,double>* f, double* var, double &val);
    
    void PFunction_dsd_calc_grad(PRISMS::PFuncBase<double*,double>* f, double* var, int di, double &val);
    
    void PFunction_dsd_calc_hess(PRISMS::PFuncBase<double*,double>* f, double* var, int di, int dj, double &val);
    
    void PFunction_dsd_eval(PRISMS::PFuncBase<double*,double>* f, double* var);
    
    void PFunction_dsd_eval_grad(PRISMS::PFuncBase<double*,double>* f, double* var, int di);
    
    void PFunction_dsd_eval_hess(PRISMS::PFuncBase<double*,double>* f, double* var, int di, int dj);
    
    void PFunction_dsd_get(PRISMS::PFuncBase<double*,double>* f, double &val);
    
    void PFunction_dsd_get_grad(PRISMS::PFuncBase<double*,double>* f, int di, double &val);
    
    void PFunction_dsd_get_hess(PRISMS::PFuncBase<double*,double>* f, int di, int dj, double &val);
    
    
    
    
    
    // Functions for using a PBasisSetBase externally (say Python or Fortran)
    //   written for InType=double, OutType=double, hence 'dd' in function names
    
    void PBasisSet_dd_new(char* name, PRISMS::PBasisSetBase<double,double>* &b, int N);
    
    void PBasisSet_dd_delete(PRISMS::PBasisSetBase<double,double>* &b);
    
    void PBasisSet_dd_name(PRISMS::PBasisSetBase<double,double>* b, char* name);
    
    void PBasisSet_dd_description(PRISMS::PBasisSetBase<double,double>* b, char* description);
    
    void PBasisSet_dd_size(PRISMS::PBasisSetBase<double,double>* b, int &size);
    
    void PBasisSet_dd_resize(PRISMS::PBasisSetBase<double,double>* b, int N);
    
    void PBasisSet_dd_max_size(PRISMS::PBasisSetBase<double,double>* b, int &max_size);
    
    //void PBasisSet_dd_basis_function(PRISMS::PFuncBase<double*,double>* b, int term, PFuncBase<double,double>* &f);
    
    void PBasisSet_dd_calc(PRISMS::PBasisSetBase<double,double>* b, int term, double var, double &val);
    
    void PBasisSet_dd_calc_grad(PRISMS::PBasisSetBase<double,double>* b, int term, double var, double &val);
    
    void PBasisSet_dd_calc_hess(PRISMS::PBasisSetBase<double,double>* b, int term, double var, double &val);
        
    void PBasisSet_dd_eval(PRISMS::PBasisSetBase<double,double>* b, double var);
    
    void PBasisSet_dd_eval_grad(PRISMS::PBasisSetBase<double,double>* b, double var);
    
    void PBasisSet_dd_eval_hess(PRISMS::PBasisSetBase<double,double>* b, double var);
    
    void PBasisSet_dd_get(PRISMS::PBasisSetBase<double,double>* b, int term, double &val);
    
    void PBasisSet_dd_get_grad(PRISMS::PBasisSetBase<double,double>* b, int term, double &val);
    
    void PBasisSet_dd_get_hess(PRISMS::PBasisSetBase<double,double>* b, int term, double &val);
    
    //void PBasisSet_dd_getall(PRISMS::PBasisSetBase<double,double>* b, const double* &val);
    //void PBasisSet_dd_getall_grad(PRISMS::PBasisSetBase<double,double>* b, const double* &val);
    //void PBasisSet_dd_getall_hess(PRISMS::PBasisSetBase<double,double>* b, const double* &val);
    
}


#endif