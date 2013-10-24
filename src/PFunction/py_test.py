#!/usr/bin/env python

from pylab import *

import PFunction
import ctypes

# test PSimple_dd
print "test PSimple_dd"
f = PFunction.PSimple_dd("Chebyshev_2")
print "  created"
print "  evaluate 1000000 times"
for i in range(0,1000000):
    f.calc(0.2)
print "  result:", f.get()
f.delete()
print "  deleted\n"


a = np.array([2.0, 3.0]);
b = PFunction.c_dbl_array(a)


# test Python
print "test Python code"
v = 0
print "  var:", a
print "  evaluate 1000000 times"
for i in range(0,1000000):
    v = b[0]*(b[1]*b[1])+(b[0]*b[0]*b[0])+(b[1]*b[1]*b[1])+(b[0]*b[0])*b[1]
print "  result:", v
print "  done\n"


# test PSimple_dsd
print "test PSimple_dsd"
f = PFunction.PSimple_dsd("MyFunc_f")
print "  created"
print "  var:", a
print "  evaluate 1000000 times"
for i in range(0,1000000):
    v = f.calc(b)
print "  result:", f.get()
f.delete()
print "  deleted\n"

# test PFunc_dsd
print "test PFunc_dsd"
f = PFunction.PFunc_dsd("MyFunc")
print "  created"
print "  var:", a
print "  evaluate 1000000 times"
for i in range(0,1000000):
    v = f.calc(b)
print "  result:", f.get()
f.delete()
print "  deleted\n"

# test PBasisSet_dd
print "test PBasisSet_dd"
f = PFunction.PBasisSet_dd("Chebyshev", 30)
print "  created"
print "  var:", 0.2
print "  evaluate 1000000 times"
for i in range(0,1000000):
    f.eval(0.2)
print "  result:"
for i in range(0,30):
    print "  i:", i, "  val:", f.get(i)
f.delete()
print "  deleted\n"









