import ctypes
import config
        
# expects a PFunction.c_dbl_array for input (var), returns a number for output
class PSimple_dsd(object):
    def __init__(self,name):
        self.ptr = ctypes.c_void_p(None)
        config.lib.PSimpleFunction_dsd_new(name,ctypes.byref(self.ptr))
        if( self.ptr.value == None):
            print "Error, PSimple_dsd '" + name + "' not found"
            exit()
        
        # use this to avoid allocating memory each time something is evaluated
        self.tval = ctypes.c_double()
        
    
    def delete(self):
        config.lib.PSimpleFunction_dsd_delete(ctypes.byref(self.ptr))
    
    def name(self):
        str = ctypes.c_char_p()
        config.lib.PSimpleFunction_dsd_name(self.ptr, ctypes.byref(str))
        return str.value
    
    def calc(self, var):
        config.lib.PSimpleFunction_dsd_calc(self.ptr, var, ctypes.byref(self.tval))
        return self.tval.value;
    
    def get(self):
        config.lib.PSimpleFunction_dsd_get(self.ptr, ctypes.byref(self.tval))
        return self.tval.value;

