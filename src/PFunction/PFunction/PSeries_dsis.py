import ctypes
import config

# expects a PFunction.c_dbl_array for input (var), returns a number for output
# expects a PFunction.c_int_array for tensor indices
class PSeries_dsis(object):

    # basis is a list of PBasisSet_dd objects
    def __init__(self,basis=[]):
        self.ptr = ctypes.c_void_p(None)
        if basis is []:
            config.lib.PSeriesFunction_dsis_new(ctypes.byref(self.ptr))
            if( self.ptr.value == None):
                print "Error, PSeries_dsis not created"
                exit()
        else:
            # PRISMS::PBasisSetBase<double,double>** basis_set
            basis_set_array = ctypes.c_void_p * len(basis)
            basis_sets = basis_set_array()
            for i in range(len(basis)):
                basis_sets[i] = basis[i].ptr
            config.lib.PSeriesFunction_dsis_setnew(ctypes.byref(self.ptr),basis_sets,ctypes.c_int(len(basis)))
            if( self.ptr.value == None):
                print "Error, PSeries_dsis with basis not created"
                exit()
        
        # use this to avoid allocating memory each time something is evaluated
        self.tval = ctypes.c_double()
        self.tint = ctypes.c_int()
    
    def delete(self):
        config.lib.PSeriesFunction_dsis_delete(ctypes.byref(self.ptr))
    

