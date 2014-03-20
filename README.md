IntegrationTools
================

Function and field passing tools for PRISMS model integration

The function and basis set writers require GiNaC: http://www.ginac.de/

Boost is used for program_options, filesystem, and regex: http://www.boost.org/

The python example script py_test.py uses matplotlib: http://matplotlib.org/

'make install' will make and install:
- 'fw': The Function Writer (/usr/local/bin)
- 'bsw': The Basis Set Writer (/usr/local/bin)
- 'lw': The Library Writer (/usr/local/bin)
- 'pfunction': Python package (default distutils install location)

Release 0.1.0 will include:
- PSimpleFunction, PFunction, and PBasisSet
- PSeriesFunction
    - with tensor product output and coefficient input
- code writers: fw, bsw, lw
    - with input and output as 'double' only
- PExtern for calls from C, Fortran, etc.
- PFunction wrapper for Python (later renamed 'pfunction')

