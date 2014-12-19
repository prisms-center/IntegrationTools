IntegrationTools
================

IntegrationTools specifies an interface for easily passing functions and fields, referred to as ‘PFunctions’ and ‘PFields’, to a computer program. It mainly consists of a header file library written in C++, and the Library Writer program 'lw'. It also provides a C interface so that functions can be used across coding languages, and a Python package 'pfunction' that uses the C interface to allow access to your functions in Python.

PFunctions:

- May be templated by input and return type, so many-to-many explicit relationships may expressed using containers or structures
- Can be defined piece-wise
- Can be series functions of some basis set, called a PBasisSet, or a series function of the tensor product of multiple PBasisSets
- The API includes methods for evaluating the function, the first derivatives, and the second derivatives

PFields:

- Implement the same API as PFunctions for evaluating the value of a finite element field, its first derivatives, and it's second derivatives
- Currently support exists for reading fields from .vtk files using "Quad" elements in 2D and "Hexahedron" elements in 3D


Dependencies
============

IntegrationTools is a header only library with no dependencies besides the C++ standard library.

[Boost](http://www.boost.org/) is used by the Library Writer program, ``lw``, for the program_options, filesystem, and regex libraries.

Python module ``pfunction`` has been tested using Python v2.7.5. The Python example script py_test.py uses [matplotlib](http://matplotlib.org/).


Installation
============

1. Clone the repository.
2. From the root directory of the repository, run ``make install``. You might need to set the following environment variables:
    	
    - BIN: This specifies where ``lw`` will be installed. If not set, the default location is ``/usr/local/bin``
    	
    - BOOST: This specifies where the Boost libraries are located. If not set, the default compiler search path is used.
    	
    - PYINSTALL: This specifies where to install the Python module ``pfunction``. If not set, it uses the default distutils location.

3. The directory ``include/IntegrationTools`` contains all the header files necessary. You can copy it somewhere in your default header search path, often:

```
cp -r include/IntegrationTools /usr/local/include
```


Usage
=====

## As a user who want to pass a function into a program that supports PFunctions ##

1. Write a PFunction for the function you wish to input to the program. This can be done most easily using the code generation tools in the [IntegrationToolsWriter](https://github.com/prisms-center/IntegrationToolsWriter) software package. This describes what the code generator is doing:
	
    1. Write classes, such as ``MyFunc_X``, for each of the individual expressions needed to evaluate the function and its first and second derivatives which inherit from [``PSimpleBase<VarContainer, OutType>``](https://github.com/prisms-center/IntegrationTools/blob/develop/include/IntegrationTools/pfunction/PSimpleBase.hh). By convention we use ``MyFunc_f`` for evaluating the function itself, ``MyFunc_0``, ``MyFunc_1``, ... for first derivatives, and ``MyFunc_0_0``, ``MyFunc_0_1``, ... for second derivatives. Each of these derived classes should implement the virtual members in ``PSimpleBase`` that specify how to evaluate function, or return strings expressing the function in as a symbolic expression, in latex form, and as C source code.
    
    2.  Write a class, ``MyFunc``, that inherits from [``PFuncBase<VarContainer, OutType>``](https://github.com/prisms-center/IntegrationTools/blob/develop/include/IntegrationTools/pfunction/PFuncBase.hh), and implements the virtual methods. The virtual methods define how to evaluate the function and its derivatives, usually using the code written in the previous step.

2. Use the Library Writer, 'lw', to collect all the PFunctions you want to use in a compiled library and 

## As a developer who wants to allow users to pass functions into their program ##

Suppose you are writing a program that evaluates functions that have a known signature (input type and output type), but unknown form, and you wish for users to be able to specify the form of the equation without having to recompile your code (runtime polymorphism). To proceed you:

1. Write an template PFunction with the desired signature using the PFunction interface. For instance, if the desired signature is ``double = MyFunc(double)``:
	
    1. Write classes, such as ``MyFunc_X``, for each of the individual expressions needed to evaluate the function and its first and second derivatives which inherit from [``PSimpleBase<VarContainer, OutType>``](https://github.com/prisms-center/IntegrationTools/blob/develop/include/IntegrationTools/pfunction/PSimpleBase.hh). By convention we use ``MyFunc_f`` for evaluating the function itself, ``MyFunc_0``, ``MyFunc_1``, ... for first derivatives, and ``MyFunc_0_0``, ``MyFunc_0_1``, ... for second derivatives. Each of these derived classes should implement the virtual members in ``PSimpleBase`` that specify how to evaluate function, or return strings expressing the function in as a symbolic expression, in latex form, and as C source code.
    
    2.  Write a class, ``MyFunc``, that inherits from [``PFuncBase<VarContainer, OutType>``](https://github.com/prisms-center/IntegrationTools/blob/develop/include/IntegrationTools/pfunction/PFuncBase.hh), and implements the virtual methods. The virtual methods define how to evaluate the function and its derivatives, usually using the code written in the previous step.
    
    	- The derived classes ``MyFunc_X`` and ``MyFunc`` can either specify the ``VarContainer`` template parameters or themselves be template classes of ``VarContainer``. Currently, they must specify the ``OutType``.
    	
2. 
    

2. You write a program that you wish to pass functions into without knowing their specific form ahead of time, just the required inputs and outputs. This can be done with:

```
#include "IntegrationTools/PFunction.hh"
#include "PLibrary.hh"
```

2) You write the code for the functions themselves, either by hand or using code generation tool (See [IntegrationToolsWriter](https://github.com/prisms-center/IntegrationToolsWriter)).

3) You compile the functions into a library and link it with your code.

4) Run it!


Boost is used for program_options, filesystem, and regex: http://www.boost.org/

The python example script py_test.py uses matplotlib: http://matplotlib.org/


Usage
=======================

Integration Tools specifies an interface for easily passing functions to a computer program. It is written in C++, but also provides a C interface so that functions can be used across coding languages.  It includes a Python package 'pfunction' that uses the C interface to allow access to your functions in Python. 

The intended usage is something like this:

1) You write a program that you wish to pass functions into without knowing their form ahead of time.

2) You write the code for the functions themselves, either by hand or code generation tool (See IntegrationToolsWriter).

3) You compile the functions into a library and link it with your code.

4) Run it!


Installation
=======================

See 'INSTALL.txt' file.


Release Notes
=======================

Release 0.2.0 will include:
- PSimpleFunction, PFunction, and PBasisSet
- PSeriesFunction
    - with tensor product output and coefficient input
- Piecewise functions
- The library writer: lw
- PExtern for calls from C, Fortran, etc.
- IntegrationTools wrapper for Python, 'pfunction'
- The code writers: fw, and bsw have been moved to a separate project: IntegrationToolsWriter


Release 0.1.0 will include:
- PSimpleFunction, PFunction, and PBasisSet
- PSeriesFunction
    - with tensor product output and coefficient input
- code writers: fw, bsw, lw
    - with input and output as 'double' only
- PExtern for calls from C, Fortran, etc.
- PFunction wrapper for Python (later renamed 'pfunction')

