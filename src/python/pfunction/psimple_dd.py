import ctypes
import config

# expects a number for input (var), returns a number for output
class PSimple_dd(object):
    def __init__(self,name):
        self.ptr = ctypes.c_void_p(None)
        config.lib.PSimpleFunction_dd_new(name,ctypes.byref(self.ptr))
        if( self.ptr.value == None):
            print "Error, PSimple_dd '" + name + "' not found"
            exit()
        
        # use this to avoid allocating memory each time something is evaluated
        self.tval = ctypes.c_double()
    
    def delete(self):
        config.lib.PSimpleFunction_dd_delete(ctypes.byref(self.ptr))
    
    def name(self):
        str = ctypes.c_char_p()
        config.lib.PSimpleFunction_dd_name(self.ptr, ctypes.byref(str))
        return str.value
    
    def calc(self, var):
        config.lib.PSimpleFunction_dd_calc(self.ptr, ctypes.c_double(var), ctypes.byref(self.tval))
        return self.tval.value;
    
    def get(self):
        config.lib.PSimpleFunction_dd_get(self.ptr, ctypes.byref(self.tval))
        return self.tval.value;
        
