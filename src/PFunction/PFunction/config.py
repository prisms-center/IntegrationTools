import ctypes

lib = None

# set lib, such as PFunction.set_lib("libpextern.dylib")
def set_lib(name):
    global lib
    lib = ctypes.cdll.LoadLibrary(name)

# use this data structure for passing double* input variables
# - input a list or numpy.array, and it will return a c_dbl_array
# - can not be resized
def c_dbl_array(var):
    return (ctypes.c_double * len(var))(*var)

# use this data structure for passing int* variables
# - input a list or numpy.array, and it will return a c_int_array
# - can not be resized
def c_int_array(var):
    return (ctypes.c_int * len(var))(*var)


