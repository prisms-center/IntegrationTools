import ctypes
import config

# expects a number for input (var), returns a number for output
class PBasisSet_dd(object):
    def __init__(self,name,N):
        self.ptr = ctypes.c_void_p(None)
        config.lib.PBasisSet_dd_new(name,ctypes.byref(self.ptr),ctypes.c_int(N))
        if( self.ptr.value == None):
            print "Error, PBasisSet_dd '" + name + "' not found"
            exit()
        
        # use this to avoid allocating memory each time something is evaluated
        self.tval = ctypes.c_double()
        self.tint = ctypes.c_int()
    
    def delete(self):
        config.lib.PBasisSet_dd_delete(ctypes.byref(self.ptr))
    
    def name(self):
        str = ctypes.c_char_p()
        config.lib.PBasisSet_dd_name(self.ptr, ctypes.byref(str))
        return str.value
    
    def description(self):
        str = ctypes.c_char_p()
        config.lib.PBasisSet_dd_description(self.ptr, ctypes.byref(str))
        return str.value

    def size(self):
        config.lib.PBasisSet_dd_size(self.ptr, ctypes.byref(self.tint))
        return self.tint.value

    def resize(self, N):
        config.lib.PBasisSet_dd_resize(self.ptr, ctypes.c_int(N))

    def max_size(self):
        config.lib.PBasisSet_dd_max_size(self.ptr, ctypes.byref(self.tint))
        return self.tint.value

    #void PBasisSet_dd_basis_function(PRISMS::PFuncBase<double*,double>* b, int term, PFuncBase<double,double>* &f);
    
    def calc(self, term, var):
        config.lib.PBasisSet_dd_calc(self.ptr, ctypes.c_int(term), ctypes.c_double(var), ctypes.byref(self.tval))
        return self.tval.value
    
    def calc_grad(self, term, var):
        config.lib.PBasisSet_dd_calc_grad(self.ptr, ctypes.c_int(term), ctypes.c_double(var), ctypes.byref(self.tval))
        return self.tval.value

    def calc_hess(self, term, var):
        config.lib.PBasisSet_dd_calc_hess(self.ptr, ctypes.c_int(term), ctypes.c_double(var), ctypes.byref(self.tval))
        return self.tval.value

    def eval(self, var):
        config.lib.PBasisSet_dd_eval(self.ptr, ctypes.c_double(var))
    
    def eval_grad(self, var):
        config.lib.PBasisSet_dd_eval_grad(self.ptr, ctypes.c_double(var))
    
    def eval_hess(self, var):
        config.lib.PBasisSet_dd_eval_hess(self.ptr, ctypes.c_double(var))
    
    def get(self, term):
        config.lib.PBasisSet_dd_get(self.ptr, ctypes.c_int(term), ctypes.byref(self.tval))
        return self.tval.value
    
    def get_grad(self, term):
        config.lib.PBasisSet_dd_get_grad(self.ptr, ctypes.c_int(term), ctypes.byref(self.tval))
        return self.tval.value

    def get_hess(self, term):
        config.lib.PBasisSet_dd_get_hess(self.ptr, ctypes.c_int(term), ctypes.byref(self.tval))
        return self.tval.value
    
    #void PBasisSet_dd_getall(PRISMS::PBasisSetBase<double,double>* b, const double* &val);
    #void PBasisSet_dd_getall_grad(PRISMS::PBasisSetBase<double,double>* b, const double* &val);
    #void PBasisSet_dd_getall_hess(PRISMS::PBasisSetBase<double,double>* b, const double* &val);   

