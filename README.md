IntegrationTools
================

Anything used by PRISMS to help integrate models

The function and basis set writers require GiNaC: http://www.ginac.de/

Boost is used for program_options, filesystem, and regex: http://www.boost.org/

The python example script py_test.py uses matplotlib: http://matplotlib.org/

Release 0.1.0 will include:
- PSimpleFunction, PFunction, and PBasisSet
- PSeriesFunction
    - with tensor product output and coefficient input
- code writers: fw, bsw, lw
    - with input and output as 'double' only
- PExtern for calls from C, Fortran, etc.
- PFunction wrapper for Python and Excel

