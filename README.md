IntegrationTools
================

Function and field passing tools for PRISMS model integration

Boost is used for program_options, filesystem, and regex: http://www.boost.org/

The function and basis set writers require GiNaC: http://www.ginac.de/

The python example script py_test.py uses matplotlib: http://matplotlib.org/


Usage
=======================

Integration Tools specifies an interface for easily passing functions to a computer program. It is written in C++, but also provides a C interface so that functions can be used across coding languages.  It includes a Python package 'pfunction' that uses the C interface to allow access to your functions in Python. 

The intended usage is something like this:

1) You write a program that you wish to pass functions into without knowing their form ahead of time.

2) You write the code for the functions themselves, either by hand or using the Function or Basis Set Writers ('fw' and 'bsw') to generate code from symbolic mathematical expressions.

3) You compile the functions into a library and link it with your code.

4) Run it!


Installation
=======================

See 'INSTALL.txt' file.


Release Notes
=======================

Release 0.1.0 will include:
- PSimpleFunction, PFunction, and PBasisSet
- PSeriesFunction
    - with tensor product output and coefficient input
- code writers: fw, bsw, lw
    - with input and output as 'double' only
- PExtern for calls from C, Fortran, etc.
- PFunction wrapper for Python (later renamed 'pfunction')

