import ctypes
import config

# expects a PFunction.c_dbl_array for input (var), returns a number for output
class PFunc_dsd(object):
    def __init__(self,name, body2d=None, body3d=None):
        self.ptr = ctypes.c_void_p(None)
        if body2d == None and body3d == None:
            config.lib.PFunction_dsd_new(name,ctypes.byref(self.ptr))
            if( self.ptr.value == None):
                print "Error, PFunc_dsd '" + name + "' not found"
                exit()
        elif body2d != None:
            config.lib.ScalarField2D(name, body2d.ptr, ctypes.byref(self.ptr))
        elif body3d != None:
            config.lib.ScalarField3D(name, body3d.ptr, ctypes.byref(self.ptr))
        
        # use this to avoid allocating memory each time something is evaluated
        self.tval = ctypes.c_double()
        self.tint = ctypes.c_int()
    
    def delete(self):
        config.lib.PFunction_dsd_delete(ctypes.byref(self.ptr))
    
    def name(self):
        str = ctypes.c_char_p()
        config.lib.PFunction_dsd_name(self.ptr, ctypes.byref(str))
        return str.value
    
    def size(self):
        config.lib.PFunction_dsd_size(self.ptr, ctypes.byref(self.tint))
        return self.tint.value;
    
    def var_name(self, i):
        str = ctypes.c_char_p();
        config.lib.PFunction_dsd_var_name(self.ptr, ctypes.c_int(i), ctypes.byref(str))
        return str.value;
    
    def var_description(self, i):
        str = ctypes.c_char_p();
        config.lib.PFunction_dsd_var_description(self.ptr, ctypes.c_int(i), ctypes.byref(str))
        return str.value;
        
    #void PFunction_dsd_simplefunc(PRISMS::PFuncBase<double*,double>* f, PSimpleBase<double*, double>* &simplefunc);
    #void PFunction_dsd_grad_simplefunc(PRISMS::PFuncBase<double*,double>* f, int di, PSimpleBase<double*, double>* &simplefunc);
    #void PFunction_dsd_hess_simplefunc(PRISMS::PFuncBase<double*,double>* f, int di, int dj, PSimpleBase<double*, double>* &simplefunc);
    
    def calc(self, var):
        config.lib.PFunction_dsd_calc(self.ptr, var, ctypes.byref(self.tval))
        return self.tval.value;
    
    def calc_grad(self, var, di):
        config.lib.PFunction_dsd_calc_grad(self.ptr, var, ctypes.c_int(di), ctypes.byref(self.tval))
        return self.tval.value;
    
    def calc_hess(self, var, di, dj):
        config.lib.PFunction_dsd_calc_hess(self.ptr, var, ctypes.c_int(di), ctypes.c_int(dj), ctypes.byref(self.tval))
        return self.tval.value;
    
    def eval(self, var):
        config.lib.PFunction_dsd_eval(self.ptr, var)
    
    def eval_grad(self, var, di):
        config.lib.PFunction_dsd_eval_grad(self.ptr, var, ctypes.c_int(di))
    
    def eval_hess(self, var, di, dj):
        config.lib.PFunction_dsd_eval_hess(self.ptr, var, ctypes.c_int(di), ctypes.c_int(dj))
    
    def get(self):
        config.lib.PFunction_dsd_get(self.ptr, ctypes.byref(self.tval))
        return self.tval.value
    
    def get_grad(self, di):
        config.lib.PFunction_dsd_get(self.ptr, ctypes.c_int(di), ctypes.byref(self.tval))
        return self.tval.value
    
    def get_hess(self, di, dj):
        config.lib.PFunction_dsd_get(self.ptr, ctypes.c_int(di), ctypes.c_int(dj), ctypes.byref(self.tval))
        return self.tval.value


