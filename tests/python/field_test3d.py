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


######## Test 3D  ##############

#### Test PField
print "Opening vtk file"

body3d = pfunction.Body3D("3D.vtk")

X = np.arange(0.0, 1.0, 0.001)
Y = np.arange(0.0, 1.0, 0.001)
X, Y = np.meshgrid(X, Y)
Z = 0.0*X
s = X.shape

f = pfunction.PFunc_dsd("c", body3d=body3d)

for i in range(0,s[0]):
    for j in range(0,s[1]):
        Z[i,j] = f.calc(pfunction.c_dbl_array([X[i,j],Y[i,j],0.2]))

fig = plt.figure(fignum, figsize=(8,7))
allfig.append(fig)
fignum += 1
fig.suptitle('3D Field Z=0.2', fontsize=12)
p = contour(X, Y, Z, [0.15, 0.5, 0.85])


for i in range(0,s[0]):
    for j in range(0,s[1]):
        Z[i,j] = f.calc(pfunction.c_dbl_array([X[i,j],Y[i,j],0.7]))

fig = plt.figure(fignum, figsize=(8,7))
allfig.append(fig)
fignum += 1
fig.suptitle('3D Field Z=0.7', fontsize=12)
p = contour(X, Y, Z, [0.15, 0.5, 0.85])

body3d.delete()

#### Displaying/Writing Figures

for i in range(0,fignum):
    plt.figure(i)
    savefig("fig_" + str(i) + ".eps")

if "DISPLAY" in os.environ:
    show()





