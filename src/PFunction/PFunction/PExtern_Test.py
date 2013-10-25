import ctypes
lib = ctypes.cdll.LoadLibrary("libpextern.dylib")

# use this data structure for passing double* input variables
# - input a list or numpy.array, and it will return a c_dbl_array
# - can not be resized
def c_dbl_array(var):
    return (ctypes.c_double * len(var))(*var)

# expects a number for input (var), returns a number for output
class PSimple_dd(object):
    def __init__(self,name):
        self.ptr = ctypes.c_void_p(None)
        lib.PSimpleFunction_dd_new(name,ctypes.byref(self.ptr))
        if( self.ptr.value == None):
            print "Error, PSimple_dd '" + name + "' not found"
            exit()
        
        # use this to avoid allocating memory each time something is evaluated
        self.tval = ctypes.c_double()
    
    def delete(self):
        lib.PSimpleFunction_dd_delete(ctypes.byref(self.ptr))
    
    def name(self):
        str = ctypes.c_char_p()
        lib.PSimpleFunction_dd_name(self.ptr, ctypes.byref(str))
        return str.value
    
    def calc(self, var):
        lib.PSimpleFunction_dd_calc(self.ptr, ctypes.c_double(var), ctypes.byref(self.tval))
        return self.tval.value;
    
    def get(self):
        lib.PSimpleFunction_dd_get(self.ptr, ctypes.byref(self.tval))
        return self.tval.value;
        
# expects a PFunction.c_dbl_array for input (var), returns a number for output
class PSimple_dsd(object):
    def __init__(self,name):
        self.ptr = ctypes.c_void_p(None)
        lib.PSimpleFunction_dsd_new(name,ctypes.byref(self.ptr))
        if( self.ptr.value == None):
            print "Error, PSimple_dsd '" + name + "' not found"
            exit()
        
        # use this to avoid allocating memory each time something is evaluated
        self.tval = ctypes.c_double()
        
    
    def delete(self):
        lib.PSimpleFunction_dsd_delete(ctypes.byref(self.ptr))
    
    def name(self):
        str = ctypes.c_char_p()
        lib.PSimpleFunction_dsd_name(self.ptr, ctypes.byref(str))
        return str.value
    
    def calc(self, var):
        lib.PSimpleFunction_dsd_calc(self.ptr, var, ctypes.byref(self.tval))
        return self.tval.value;
    
    def get(self):
        lib.PSimpleFunction_dsd_get(self.ptr, ctypes.byref(self.tval))
        return self.tval.value;

# expects a PFunction.c_dbl_array for input (var), returns a number for output
class PFunc_dsd(object):
    def __init__(self,name):
        self.ptr = ctypes.c_void_p(None)
        lib.PFunction_dsd_new(name,ctypes.byref(self.ptr))
        if( self.ptr.value == None):
            print "Error, PFunc_dsd '" + name + "' not found"
            exit()
        
        # use this to avoid allocating memory each time something is evaluated
        self.tval = ctypes.c_double()
        self.tint = ctypes.c_int()
    
    def delete(self):
        lib.PFunction_dsd_delete(ctypes.byref(self.ptr))
    
    def name(self):
        str = ctypes.c_char_p()
        lib.PFunction_dsd_name(self.ptr, ctypes.byref(str))
        return str.value
    
    def size(self):
        lib.PFunction_dsd_size(self.ptr, ctypes.byref(self.tint))
        return self.tint.value;
    
    def var_name(self, i):
        str = ctypes.c_char_p();
        lib.PFunction_dsd_var_name(self.ptr, ctypes.c_int(i), ctypes.byref(str))
        return str.value;
    
    def var_description(self, i):
        str = ctypes.c_char_p();
        lib.PFunction_dsd_var_description(self.ptr, ctypes.c_int(i), ctypes.byref(str))
        return str.value;
        
    #void PFunction_dsd_simplefunc(PRISMS::PFuncBase<double*,double>* f, PSimpleBase<double*, double>* &simplefunc);
    #void PFunction_dsd_grad_simplefunc(PRISMS::PFuncBase<double*,double>* f, int di, PSimpleBase<double*, double>* &simplefunc);
    #void PFunction_dsd_hess_simplefunc(PRISMS::PFuncBase<double*,double>* f, int di, int dj, PSimpleBase<double*, double>* &simplefunc);
    
    def calc(self, var):
        lib.PFunction_dsd_calc(self.ptr, var, ctypes.byref(self.tval))
        return self.tval.value;
    
    def calc_grad(self, var, di):
        lib.PFunction_dsd_calc_grad(self.ptr, var, ctypes.c_int(di), ctypes.byref(self.tval))
        return self.tval.value;
    
    def calc_hess(self, var, di, dj):
        lib.PFunction_dsd_calc_hess(self.ptr, var, ctypes.c_int(di), ctypes.c_int(dj), ctypes.byref(self.tval))
        return self.tval.value;
    
    def eval(self, var):
        lib.PFunction_dsd_eval(self.ptr, var)
    
    def eval_grad(self, var, di):
        lib.PFunction_dsd_eval_grad(self.ptr, var, ctypes.c_int(di))
    
    def eval_hess(self, var, di, dj):
        lib.PFunction_dsd_eval_hess(self.ptr, var, ctypes.c_int(di), ctypes.c_int(dj))
    
    def get(self):
        lib.PFunction_dsd_get(self.ptr, ctypes.byref(self.tval))
        return self.tval.value
    
    def get_grad(self, di):
        lib.PFunction_dsd_get(self.ptr, ctypes.c_int(di), ctypes.byref(self.tval))
        return self.tval.value
    
    def get_hess(self, di, dj):
        lib.PFunction_dsd_get(self.ptr, ctypes.c_int(di), ctypes.c_int(dj), ctypes.byref(self.tval))
        return self.tval.value


# expects a number for input (var), returns a number for output
class PBasisSet_dd(object):
    def __init__(self,name,N):
        self.ptr = ctypes.c_void_p(None)
        lib.PBasisSet_dd_new(name,ctypes.byref(self.ptr),ctypes.c_int(N))
        if( self.ptr.value == None):
            print "Error, PBasisSet_dd '" + name + "' not found"
            exit()
        
        # use this to avoid allocating memory each time something is evaluated
        self.tval = ctypes.c_double()
        self.tint = ctypes.c_int()
    
    def delete(self):
        lib.PBasisSet_dd_delete(ctypes.byref(self.ptr))
    
    def name(self):
        str = ctypes.c_char_p()
        lib.PBasisSet_dd_name(self.ptr, ctypes.byref(str))
        return str.value
    
    def description(self):
        str = ctypes.c_char_p()
        lib.PBasisSet_dd_description(self.ptr, ctypes.byref(str))
        return str.value

    def size(self):
        lib.PBasisSet_dd_size(self.ptr, ctypes.byref(self.tint))
        return self.tint.value

    def resize(self, N):
        lib.PBasisSet_dd_resize(self.ptr, ctypes.c_int(N))

    def max_size(self):
        lib.PBasisSet_dd_max_size(self.ptr, ctypes.byref(self.tint))
        return self.tint.value

    #void PBasisSet_dd_basis_function(PRISMS::PFuncBase<double*,double>* b, int term, PFuncBase<double,double>* &f);
    
    def calc(self, term, var):
        lib.PBasisSet_dd_calc(self.ptr, ctypes.c_int(term), ctypes.c_double(var), ctypes.byref(self.tval))
        return self.tval.value
    
    def calc_grad(self, term, var):
        lib.PBasisSet_dd_calc_grad(self.ptr, ctypes.c_int(term), ctypes.c_double(var), ctypes.byref(self.tval))
        return self.tval.value

    def calc_hess(self, term, var):
        lib.PBasisSet_dd_calc_hess(self.ptr, ctypes.c_int(term), ctypes.c_double(var), ctypes.byref(self.tval))
        return self.tval.value

    def eval(self, var):
        lib.PBasisSet_dd_eval(self.ptr, ctypes.c_double(var))
    
    def eval_grad(self, var):
        lib.PBasisSet_dd_eval_grad(self.ptr, ctypes.c_double(var))
    
    def eval_hess(self, var):
        lib.PBasisSet_dd_eval_hess(self.ptr, ctypes.c_double(var))
    
    def get(self, term):
        lib.PBasisSet_dd_get(self.ptr, ctypes.c_int(term), ctypes.byref(self.tval))
        return self.tval.value
    
    def get_grad(self, term):
        lib.PBasisSet_dd_get_grad(self.ptr, ctypes.c_int(term), ctypes.byref(self.tval))
        return self.tval.value

    def get_hess(self, term):
        lib.PBasisSet_dd_get_hess(self.ptr, ctypes.c_int(term), ctypes.byref(self.tval))
        return self.tval.value
    
    #void PBasisSet_dd_getall(PRISMS::PBasisSetBase<double,double>* b, const double* &val);
    #void PBasisSet_dd_getall_grad(PRISMS::PBasisSetBase<double,double>* b, const double* &val);
    #void PBasisSet_dd_getall_hess(PRISMS::PBasisSetBase<double,double>* b, const double* &val);   

