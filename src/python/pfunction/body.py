import ctypes
import config

# constructs a 2D Body from a vtk file with 'name'
class Body2D(object):
    def __init__(self,name):
        self.ptr = ctypes.c_void_p(None)
        config.lib.Body2D_new(name,ctypes.byref(self.ptr))
        if( self.ptr.value == None):
            print "Error, Body2D '" + name + "' not found"
            exit()
    
    def delete(self):
        config.lib.Body2D_delete(ctypes.byref(self.ptr))


# constructs a 3D Body from a vtk file with 'name'
class Body3D(object):
    def __init__(self,name):
        self.ptr = ctypes.c_void_p(None)
        config.lib.Body3D_new(name,ctypes.byref(self.ptr))
        if( self.ptr.value == None):
            print "Error, Body3D '" + name + "' not found"
            exit()
    
    def delete(self):
        config.lib.Body3D_delete(ctypes.byref(self.ptr))


