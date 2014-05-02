#!/usr/bin/env python
import os, sys
import matplotlib

if not "DISPLAY" in os.environ:
    matplotlib.use('Agg')

from mpl_toolkits.mplot3d import Axes3D
from pylab import *

import pfunction
import ctypes
import random


rc('font',**{'family':'serif','sans-serif':['Times']})
pfunction.set_lib("../testlib/libpextern.so")

max = 1
fignum = 0
allfig = []


#### Test PField
print "Opening vtk file"

body2d = pfunction.Body2D("2D.vtk")

X = np.arange(0.0, 1.0, 0.01)
Y = np.arange(0.0, 1.0, 0.01)
X, Y = np.meshgrid(X, Y)
Z = 0.0*X
s = X.shape

f = pfunction.PFunc_dsd("c", body2d=body2d)



####

fig = plt.figure(fignum, figsize=(8,8))
allfig.append(fig)
fignum += 1
fig.suptitle('Concentration Field', fontsize=12)
ax = fig.gca(projection='3d')

print "Evaluating field..."

for i in range(0,s[0]):
    for j in range(0,s[1]):
        Z[i,j] = f.calc(pfunction.c_dbl_array([X[i,j],Y[i,j]]))

print "Plotting..."

ax.plot_surface(X, Y, Z, rstride=1, cstride=1, cmap=cm.coolwarm, linewidth=0, antialiased=False)

#

fig = plt.figure(fignum, figsize=(8,7))
allfig.append(fig)
fignum += 1
fig.suptitle('Field', fontsize=12)
x = np.arange(0.0,1.0, 0.00001)
y = np.arange(0.0,1.0, 0.1)
for i in range(0,y.size):
    field = np.zeros( (x.size))
    for j in range(0,x.size):
        field[j] = f.calc(pfunction.c_dbl_array([x[j],y[i]]))
    p = plot( x, field)


#####

fig = plt.figure(fignum, figsize=(8,8))
allfig.append(fig)
fignum += 1
fig.suptitle('Concentration Field', fontsize=12)
ax = fig.gca(projection='3d')

print "Evaluating grad field..."

for i in range(0,s[0]):
    for j in range(0,s[1]):
        Z[i,j] = f.calc_grad(pfunction.c_dbl_array([X[i,j],Y[i,j]]),0)

print "Plotting..."

ax.plot_surface(X, Y, Z, rstride=1, cstride=1, cmap=cm.coolwarm, linewidth=0, antialiased=False)

#

fig = plt.figure(fignum, figsize=(8,7))
allfig.append(fig)
fignum += 1
fig.suptitle('Field', fontsize=12)
x = np.arange(0.0,1.0, 0.00001)
y = np.arange(0.0,1.0, 0.1)
for i in range(0,y.size):
    field = np.zeros( (x.size))
    for j in range(0,x.size):
        field[j] = f.calc_grad(pfunction.c_dbl_array([x[j],y[i]]),0)
    p = plot( x, field)


#####

fig = plt.figure(fignum, figsize=(8,8))
allfig.append(fig)
fignum += 1
fig.suptitle('Concentration Field', fontsize=12)
ax = fig.gca(projection='3d')

print "Evaluating hess field..."

for i in range(0,s[0]):
    for j in range(0,s[1]):
        Z[i,j] = f.calc_hess(pfunction.c_dbl_array([X[i,j],Y[i,j]]),0,1)

print "Plotting..."

ax.plot_surface(X, Y, Z, rstride=1, cstride=1, cmap=cm.coolwarm, linewidth=0, antialiased=False)

#

fig = plt.figure(fignum, figsize=(8,7))
allfig.append(fig)
fignum += 1
fig.suptitle('Field', fontsize=12)
x = np.arange(0.0,1.0, 0.00001)
y = np.arange(0.0,1.0, 0.1)
for i in range(0,y.size):
    field = np.zeros( (x.size))
    for j in range(0,x.size):
        field[j] = f.calc_hess(pfunction.c_dbl_array([x[j],y[i]]),0,1)
    p = plot( x, field)


body2d.delete()


#### Displaying/Writing Figures

for i in range(0,fignum):
    plt.figure(i)
    savefig("fig_" + str(i) + ".eps")

if "DISPLAY" in os.environ:
    show()





