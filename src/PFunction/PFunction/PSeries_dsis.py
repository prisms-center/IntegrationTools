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

    def clear(self):
        config.lib.PSeriesFunction_dsis_clear(self.ptr)

    # basis is a list of PBasisSet_dd objects
    def set(self,basis):
        basis_set_array = ctypes.c_void_p * len(basis)
        basis_sets = basis_set_array()
        for i in range(len(basis)):
            basis_sets[i] = basis[i].ptr
        config.lib.PSeriesFunction_dsis_set(self.ptr,basis_sets,ctypes.c_int(len(basis)))

    def order(self):
        config.lib.PSeriesFunction_dsis_order(self.ptr, ctypes.byref(self.tint))
        return self.tint.value
    
    def volume(self):
        config.lib.PSeriesFunction_dsis_volume(self.ptr, ctypes.byref(self.tint))
        return self.tint.value
    
    def dim(self, i):
        config.lib.PSeriesFunction_dsis_dim(self.ptr, ctypes.c_int(i), ctypes.byref(self.tint))
        return self.tint.value
    
    def linear_coeff(self, linear_index):
        config.lib.PSeriesFunction_dsis_linear_coeff(self.ptr, ctypes.c_int(linear_index), ctypes.byref(self.tval))
        return self.tval.value
    
    #tensor_indices is a c_int_array
    def tensor_coeff(self, tensor_indices):
        config.lib.PSeriesFunction_dsis_linear_coeff(self.ptr, tensor_indices, ctypes.byref(self.tval))
        return self.tval.value
    
    #tensor_indices is a c_int_array
    def linear_index(self, tensor_indices):
        config.lib.PSeriesFunction_dsis_linear_coeff(self.ptr, tensor_indices, ctypes.byref(self.tint))
        return self.tint.value
    
    #returns a c_int_array
    def tensor_indices(self, linear_index):
        term = c_int_array( [0]*self.order())
        config.lib.PSeriesFunction_dsis_tensor_indices(self.ptr, config.c_int(linear_index), ctypes.byref(term))
        return term
    
    # ----------------------------------------------------------
    # Use these functions if you want to evaluate a single value
    
    def calc(self, var):
        config.lib.PSeriesFunction_dsis_calc(self.ptr, var, ctypes.byref(self.tval))
        return self.tval.value
    
    def calc_grad(self, var, di):
        config.lib.PSeriesFunction_dsis_calc_grad(self.ptr, var, ctypes.c_int(di), ctypes.byref(self.tval))
        return self.tval.value
    
    def calc_hess(self, var, di, dj):
        config.lib.PSeriesFunction_dsis_calc_hess(self.ptr, var, ctypes.c_int(di), ctypes.c_int(dj), ctypes.byref(self.tval))
        return self.tval.value
    
    # ----------------------------------------------------------
    # Use these functions to evaluate several values, then use 'get' methods to access results
    
    
    def eval(self, var):
        config.lib.PSeriesFunction_dsis_eval(self.ptr, var)
    
    def eval_grad(self, var):
        config.lib.PSeriesFunction_dsis_eval_grad(self.ptr, var)
    
    def eval_hess(self, var):
        config.lib.PSeriesFunction_dsis_eval_hess(self.ptr, var)
    
    def get(self, var):
        config.lib.PSeriesFunction_dsis_eval(self.ptr, ctypes.byref(self.tval))
        return self.tval.value
    
    def get_grad(self, var, di):
        config.lib.PSeriesFunction_dsis_eval_grad(self.ptr, ctypes.c_int(di), ctypes.byref(self.tval))
        return self.tval.value
        
    def get_hess(self, var, di, dj):
        config.lib.PSeriesFunction_dsis_eval_hess(self.ptr, ctypes.c_int(di), ctypes.c_int(dj), ctypes.byref(self.tval))
        return self.tval.value
    
    # ----------------------------------------------------------
    # Functions for evaluating basis functions & their derivatives:

    # Use these functions if you want to evaluate a single value

    #   use basis index and term index for individual basis function
    
    def calc_basis(self, bindex, term, var):
        config.lib.PSeriesFunction_dsis_calc_basis(self.ptr, ctypes.c_int(bindex), cytpes.c_int(term), var, ctypes.byref(self.tval))
        return self.tval.value
    
    def calc_basis_grad(self, bindex, term, var):
        config.lib.PSeriesFunction_dsis_calc_basis_grad(self.ptr, ctypes.c_int(bindex), cytpes.c_int(term), var, ctypes.byref(self.tval))
        return self.tval.value
    
    def calc_basis_hess(self, bindex, term, var):
        config.lib.PSeriesFunction_dsis_calc_basis_hess(self.ptr, ctypes.c_int(bindex), cytpes.c_int(term), var, ctypes.byref(self.tval))
        return self.tval.value
    
    #   or use tensor indices to evaluate basis function product
    #   tensor_indices is a c_int_array
    def calc_tensor_basis(self, tensor_indices, var):
        config.lib.PSeriesFunction_dsis_calc_tensor_basis(self.ptr, tensor_indices, var, ctypes.byref(self.tval))
        return self.tval.value
    
    def calc_tensor_basis_grad(self, tensor_indices, var):
        config.lib.PSeriesFunction_dsis_calc_tensor_basis_grad(self.ptr, tensor_indices, var, ctypes.byref(self.tval))
        return self.tval.value
    
    def calc_tensor_basis_hess(self, bindex, tensor_indices, var):
        config.lib.PSeriesFunction_dsis_calc_tensor_basis_hess(self.ptr, tensor_indices, var, ctypes.byref(self.tval))
        return self.tval.value
    
    # ----------------------------------------------------------
    # Use these functions to evaluate all basis functions,
    #   then use following methods to access results.
    
    def eval_basis_all(self, var):
        config.lib.PSeriesFunction_dsis_eval_basis_all(self.ptr, var)
    
    def eval_basis(self, var, i):
        config.lib.PSeriesFunction_dsis_eval_basis(self.ptr, var, ctypes.c_int(i))
    
    def eval_basis_grad_all(self, var):
        config.lib.PSeriesFunction_dsis_eval_basis_grad_all(self.ptr, var)
    
    def eval_basis_grad(self, var, i):
        config.lib.PSeriesFunction_dsis_eval_basis_grad(self.ptr, var, ctypes.c_int(i))
    
    def eval_basis_hess_all(self, var):
        config.lib.PSeriesFunction_dsis_eval_basis_hess_all(self.ptr, var)
    
    def eval_basis_hess(self, var, i):
        config.lib.PSeriesFunction_dsis_eval_basis_hess(self.ptr, var, ctypes.c_int(i))

    #   use basis index and term index for individual basis function
    def get_basis(self, bindex, term):
        config.lib.PSeriesFunction_dsis_get_basis(self.ptr, ctypes.c_int(bindex), cytpes.c_int(term), ctypes.byref(self.tval))
        return self.tval.value
    
    def get_basis_grad(self, bindex, term):
        config.lib.PSeriesFunction_dsis_get_basis_grad(self.ptr, ctypes.c_int(bindex), cytpes.c_int(term), ctypes.byref(self.tval))
        return self.tval.value
    
    def get_basis_hess(self, bindex, term):
        config.lib.PSeriesFunction_dsis_get_basis_hess(self.ptr, ctypes.c_int(bindex), cytpes.c_int(term), ctypes.byref(self.tval))
        return self.tval.value
    
    #   or use tensor indices to evaluate basis function product
    #   tensor_indices is a c_int_array
    def get_tensor_basis(self, tensor_indices):
        config.lib.PSeriesFunction_dsis_get_tensor_basis(self.ptr, tensor_indices, ctypes.byref(self.tval))
        return self.tval.value
    
    def get_tensor_basis_grad(self, tensor_indices):
        config.lib.PSeriesFunction_dsis_get_tensor_basis_grad(self.ptr, tensor_indices, ctypes.byref(self.tval))
        return self.tval.value
    
    def get_tensor_basis_hess(self, bindex, tensor_indices):
        config.lib.PSeriesFunction_dsis_get_tensor_basis_hess(self.ptr, tensor_indices, ctypes.byref(self.tval))
        return self.tval.value

