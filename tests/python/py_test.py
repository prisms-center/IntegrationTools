#!/usr/bin/env python
from mpl_toolkits.mplot3d import Axes3D
from pylab import *

import pfunction
import ctypes
import random
import os, sys

rc('font',**{'family':'serif','sans-serif':['Times']})
pfunction.set_lib("../testlib/libpextern.dylib")

max = 1

# test PSimple_dd
print "test PSimple_dd"
f = pfunction.PSimple_dd("Chebyshev_2")
print "  created"
print "  evaluate", max, "times"
for i in range(0,max):
    f.calc(0.2)
print "  result:", f.get()
f.delete()
print "  deleted\n"


a = np.array([2.0, 3.0]);
b = pfunction.c_dbl_array(a)


# test Python
print "test Python code"
v = 0
print "  var:", a
print "  evaluate", max, "times"
for i in range(0,max):
    v = b[0]*(b[1]*b[1])+(b[0]*b[0]*b[0])+(b[1]*b[1]*b[1])+(b[0]*b[0])*b[1]
print "  result:", v
print "  done\n"


# test PSimple_dsd
print "test PSimple_dsd"
f = pfunction.PSimple_dsd("MyFunc_f")
print "  created"
print "  var:", a
print "  evaluate", max, "times"
for i in range(0,max):
    v = f.calc(b)
print "  result:", f.get()
f.delete()
print "  deleted\n"

# test PFunc_dsd
print "test PFunc_dsd"
f = pfunction.PFunc_dsd("MyFunc")
print "  created"
print "  var:", a
print "  evaluate", max, "times"
for i in range(0,max):
    v = f.calc(b)
print "  result:", f.get()
f.delete()
print "  deleted\n"

# test PBasisSet_dd
print "test PBasisSet_dd"
f = pfunction.PBasisSet_dd("Chebyshev", 30)
print "  created"
print "  var:", 0.2
print "  evaluate", max, "times"
for i in range(0,max):
    f.eval(0.2)
print "  result:"
for i in range(0,30):
    print "  i:", i, "  val:", f.get(i)

# test plotting basis functions
fig = plt.figure(1, figsize=(8,7))
a = np.arange(-1,1, 0.001)
for i in range(0,10):
    bf = np.zeros( (a.size))
    for j in range(0,a.size):
        bf[j] = f.calc(i,a[j])
    p = plot( a, bf)
#show()
f.delete()
print "  deleted\n"


a = np.array([0.2, 0.3]);
b = pfunction.c_dbl_array(a)
Nf = 4

# test PSeries_dsis
print "test PSeries_dsis"
cheby = pfunction.PBasisSet_dd("Chebyshev", Nf)
f = pfunction.PSeries_dsis([cheby,cheby])
print "  created"
print "  var:", a
print "  evaluate", max, "times"
for i in range(0,max):
    f.eval(b)
print "  result:", f.get()
#for i in range(0,15):
#    print "  i:", i, "  val0:", f.calc_basis(0, i, b), "  val1:", f.calc_basis(1,i,b)
#for i in range(0,30):
#    print "  i:", i, "  val0:", f.get_basis(0, i), "  val1:", f.get_basis(1,i)

X = np.arange(-1, 1.0001, 0.1)
Y = np.arange(-1, 1.0001, 0.1)
X, Y = np.meshgrid(X, Y)
Z = 0.0*X
s = X.shape

fig = plt.figure(2, figsize=(8,8))
index=1
for t in range(0,Nf):
    for u in range(0,Nf):
        for i in range(0,s[0]):
            for j in range(0,s[1]):
                Z[i,j] = f.calc_tensor_basis(pfunction.c_int_array([t,u]),pfunction.c_dbl_array([X[i,j],Y[i,j]]))
        ax = fig.add_subplot(Nf,Nf,index, projection='3d')
        ax.plot_surface(X, Y, Z, rstride=1, cstride=1, cmap=cm.coolwarm, linewidth=0, antialiased=False)
        ax.set_xticklabels([])
        ax.set_yticklabels([])
        ax.set_zticklabels([])
        index = index+1
#show()
f.delete()

Nf = 8
X = np.arange(-1, 1.0001, 0.05)
Y = np.arange(-1, 1.0001, 0.05)
X, Y = np.meshgrid(X, Y)
Z = 0.0*X
s = X.shape

# test PSeries_dsis
cheby = pfunction.PBasisSet_dd("Chebyshev", Nf)
f = pfunction.PSeries_dsis([cheby,cheby])

coeff = [1,0.4,0.1,0.05]
tindex = [[0,1],[1,1],[0,3],[6,3]]
for i in range(len(coeff)):
    f.set_tensor_coeff(pfunction.c_int_array(tindex[i]),coeff[i])
f.set_tensor_coeff(pfunction.c_int_array([0,0]),-1.0*sum(coeff))

fig = plt.figure(3, figsize=(8,8))
ax = fig.gca(projection='3d')
for i in range(0,s[0]):
    for j in range(0,s[1]):
        Z[i,j] = f.calc(pfunction.c_dbl_array([X[i,j],Y[i,j]]))
ax.plot_surface(X, Y, Z, rstride=1, cstride=1, cmap=cm.coolwarm, linewidth=0, antialiased=False)
#ax.set_xticklabels([])
#ax.set_yticklabels([])
#ax.set_zticklabels([])

print "write 'coeff.txt'\n"
coeff_file = open('coeff.txt','w')
f.print_coeff(coeff_file)
coeff_file.close()

print "clear coeffs:"
for i in range(0,f.volume()):
    f.set_linear_coeff(i,0.0)
f.print_coeff(sys.stdout)
print ""

print "read 'coeff.txt'"
coeff_file = open('coeff.txt','r')
f.read_coeff(coeff_file)
coeff_file.close()
f.print_coeff(sys.stdout)

os.remove('coeff.txt')


f.delete()
print "  deleted\n"


# test PieceWise PFunc_dsd
print "test PFunc_dsd"
f = pfunction.PFunc_dsd("MyPieceWiseFunc")
print "  created"
print "  var:", a
print "  evaluate", max, "times"
for i in range(0,max):
    v = f.calc(b)
print "  result:", f.get()

fig = plt.figure(4, figsize=(8,8))
ax = fig.gca(projection='3d')
for i in range(0,s[0]):
    for j in range(0,s[1]):
        Z[i,j] = f.calc(pfunction.c_dbl_array([X[i,j],Y[i,j]]))
ax.plot_surface(X, Y, Z, rstride=1, cstride=1, cmap=cm.coolwarm, linewidth=0, antialiased=False)

f.delete()
print "  deleted\n"

show()





