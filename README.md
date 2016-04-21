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

This code is developed by the PRedictive Integrated Structural Materials Science Center (PRISMS), at the University of Michigan, which is supported by the U.S. Department of Energy, Office of Basic Energy Sciences, Division of Materials Sciences and Engineering under Award #DE-SC0008637.

Dependencies
============

- IntegrationTools is a header only library with no dependencies besides the C++ standard library.
- [Boost](http://www.boost.org/) is used by the Library Writer program, ``lw``, for the program_options, filesystem, and regex libraries.
- The Python module ``pfunction`` has been tested using Python v2.7.5. The Python example script py_test.py uses [matplotlib](http://matplotlib.org/).


Installation
============

1. Clone the repository

        cd /path/to/
        git clone https://github.com/prisms-center/IntegrationTools.git
        cd IntegrationTools

2. Checkout the branch containing the version you wish to install. Latest is ``v1.0.0``:

        git checkout v1.0.0

3. From the root directory of the repository:

        make install

    You might need to set the following environment variables:
    	
    - INTEGRATIONTOOLS_PREFIX: This specifies where headers, the ``lw`` program, and the python module ``pfunction`` will be installed. If not set, the default location is ``/usr/local``. The headers are installed to $(INTEGRATIONTOOLS_PREFIX)/include/IntegrationTools. The ``lw`` program to $(INTEGRATIONTOOLS_PREFIX)/bin/lw. $(INTEGRATIONTOOLS_PREFIX) is passed to the ``--prefix`` option of the python ``setup.py`` installation script.
    	
    - INTEGRATIONTOOLS_BOOST: This specifies where the Boost libraries are located. If not set, the default compiler search path is used.



Usage
=====

## Writing and using PFunctions in a program ##

The program supporting PFunctions should be linked to a shared library, typically with the name ``libpextern.so``. To use your own custom functions in the program, they must be written as C++ code in the PFunction format and compiled into a library that replaces ``libpextern.so``, typically by using a symbolic link. To do this:

1. Write a PFunction for the function you wish to input to the program. This can be done most easily using the code generation tools in the [IntegrationToolsWriter](https://github.com/prisms-center/IntegrationToolsWriter) software package. This describes what the code generator is doing:
    - Write classes, such as ``MyFunc_X``, which inherit from ``PSimpleBase<VarContainer, OutType>`` for each of the individual expressions needed to evaluate the function and its first and second derivatives. By convention we use ``MyFunc_f`` for evaluating the function itself, ``MyFunc_0``, ``MyFunc_1``, ... for first derivatives, and ``MyFunc_0_0``, ``MyFunc_0_1``, ... for second derivatives. Each of these derived classes should implement the virtual members in ``PSimpleBase`` that specify how to evaluate function, or return strings expressing the function in as a symbolic expression, in latex form, and as C source code.
    -  Write a class, ``MyFunc``, that inherits from ``PFuncBase<VarContainer, OutType>``, and implements the virtual methods. The virtual methods define how to evaluate the function and its derivatives, usually using the code written in the previous step.
    - For an example, see ``tests/testlib/MyFunc.hh``3. 
2. Use the Library Writer, 'lw', to collect all the PFunctions you want to use and compile them into a shared library called, for example,``libpextern_custom.so``:

        lw -d /path/to/search -v "std::vector<double>" -l /path/to/write -c 
        mv /path/to/write/libpextern.so /path/to/write/libpextern_custom.so

   - ``-d`` Directories to check for ``*.hh`` files containing classes that inherit from ``PSimpleBase``, ``PFuncBase``, ``PBasisSet``, ``PPieceWiseSimpleBase``, or ``PPieceWiseFuncBase`` 
   - ``-v`` Types to use for ``VarContainer`` template parameter. What types to use should be documented by the program in which you are going to use the PFunctions.
   - ``-l`` Location to write library.
   - ``-c`` Compile library after writing.
   - Check ``lw -h`` help documentation to see how to set compiler options.
   - This also creates files named ``PLibrary.hh`` and ``PLibrary.cc`` which declare and define methods for "checking out" PFunctions from the PLibrary by name.

3. Replace ``libpextern.so`` with a symbolic link to ``libpextern_custom.so``: 
    - ``ln -s /path/to/write/libpextern_custom.so /path/to/libpextern.so``. 


## Writing piece-wise defined PFunctions ##

To write a piece-wise defined PFunction, you must:

1. Write a PFunction for each piece:
	- Follow the same steps as for ``MyFunc`` above.
2. Define the domain over which each piece should be evaluated:
 	- For each piece, you must write a set of PSimpleFunctions (classes inheriting from PSimpleBase, as ``MyFunc_X`` above) that all evaluate to true in the domain of the piece.
3. Write a class inheriting from ``PPieceWiseFuncBase<VarContainer, OutType>`` (which itself inherits from ``PFuncBase<VarContainer, OutType>``) that adds all the necessary Pieces when constructed.

For an example, see ``tests/testlib/MyPieceWiseFun.hh``.


## Writing a PBasisSet ##

To write a PBasisSet, you must:

1. Write a set of classes that inherit from ``PSimpleBase<InType, OutType>`` that evaluate the individual basis functions, and their first and second derivatives.
    - Typically ``InType`` and ``OutType`` are type ``double``
2. Write a class that inherits from ``PBasisSetBase<InType, OutType>`` implementing the PBasisSet
    - Typically this will contain the individual basis functions as a vector of PFunctions

For an example, see ``tests/testlib/Monomial.hh`` and ``tests/testlib/Chebyshev.hh``.


## Writing a program that can use PFunctions ##

Suppose you are writing a program that evaluates functions that have a known signature (input type and output type), but unknown form, and want users to be able to specify the form of the equation without having to recompile your code. 

1. Create a PFunction library (``PLibrary.hh`` and ``libpextern.so``) as in the previous section, using dummy PFunctions that implement the desired signatures.

2. Write a program that uses PFunctions that are checked out from the PLibrary by name. An example program using PFunctions is located at ``tests/PFunction/test_PFunction.cpp``. 

3. Include the dummy ``PLibrary.hh`` (which needs the ``IntegrationTools`` header file library in your search path) and link ``libpextern.so``.

4. Users can then update the available PFunctions using the steps in the previous section and re-run your program without re-compiling the entire thing. 

The example program at ``tests/PFunction/test_PFunction.cpp`` prints the following output documenting the use of PFunctions:

```
#include "PLibrary.hh"
#include <vector>
#include <cstring>

int main(int argc, char *argv[]) {

  using namespace PRISMS;

  // ----------------------------------------------------------------------
  // Create an input variable vector, for a function of a single variable.
  // PFunctions typically evalulate with [], so even a function of a single
  // variable takes a container as input.

  std::vector<double> var(1, 2.1);

  double result;

  // ----------------------------------------------------------------------
  // Construct a PFunction that takes input of type std::vector<double>
  // and returns output of type double.
  PFunction<std::vector<double>, double> func;

  // Checkout the Quadratic function.
  PLibrary::checkout("Quadratic", func);

  // PFunction::operator()([x]) = 1+x+x^2
  result = func(var); // = 7.51

  // PFunction::grad([x], x); //  = 1+2*x
  result = func.grad(var, 0); //  = 5.2

  // PFunction::hess([x], x, x); //  = 2 
  result = func.hess(var, 0, 0); //  = 2

  // After evaluation, the latest result is stored and can be accessed
  // multiple times without recalculation:
  result = func(); //  = 7.51
  result = func.grad(0); //  = 5.2
  result = func.hess(0, 0); //  = 2

  // Use eval_grad(var) or eval_hess(var) to evaluate 
  // the entire gradient vector or hessian matrix.

  func.eval_grad(var);
  result = func.grad(0); //  = 5.2

  func.eval_hess(var);
  result = func.hess(0, 0); //  = 2

  // ----------------------------------------------------------------------
  // Add another variable for a function of two variables. 
  var.push_back(3.5);

  // Checkout the MyFunc function.
  PLibrary::checkout("MyFunc", func);

  // PFunction::operator()([x, y]) = x*y^2+y^3+x^2*y+x^3
  result = func(var); //  = 93.296

  // PFunction::grad([x, y], x); //  = y^2+2*x*y+3*x^2
  result = func.grad(var, 0); //  = 40.18

  // PFunction::hess([x, y], x, x); //  = 2*y+6*x
  result = func.hess(var, 0, 0); //  = 19.6

  // After evaluation, the latest result is stored and can be accessed 
  // multiple times without recalculation:

  result = func(); //  = 93.296
  result = func.grad(0); //  = 40.18
  result = func.hess(0, 1); //  = 3.10504e+231

  // Use eval_grad(var) or eval_hess(var) to evaluate
  // the entire gradient vector or hessian matrix.
  func.eval_grad(var);
  result = func.grad(0); //  = 40.18
  result = func.grad(1); //  = 55.86

  func.eval_hess(var);
  result = func.hess(0, 0); //  = 19.6
  result = func.hess(0, 1); //  = 11.2
  result = func.hess(1, 0); //  = 11.2
  result = func.hess(1, 1); //  = 25.2

  return 0;
}
```


## Writing a program that can use PFields ##

See ``tests/PFields/test.cpp`` for an example. 

1. First construct an empty ``Body<Coordinate, DIM>``, which will contain the finite element mesh and all the fields.
    - A ``Body`` is templated by coordinate type (typename), and coordinate dimension (int).
    
2. Read the mesh and fields from a ``.vtk`` file into the ``Body``.

3. Checkout a ``PField<Coordinate, OutType, DIM>`` from the ``Body`` by name, and use it just like a ``PFunction``.
    - A ``PField`` is templated by coordinate type (typename), field type (typename), and coordinate dimension (int)


## Writing a program that uses PBasisSets and PSeriesFunctions ##

1. A PBasisSet can be checked out from a PLibrary just like a PFunction
2. The API is similar, but the index of the basis function to evaluate must be given along with the input value.

The example program at ``tests/PFunction/test_PBasisSet.cpp`` prints the following output documenting the use of PBasisSets and PSeriesFunctions:

```
#include "PLibrary.hh"
#include <vector>
#include <cstring>

int main(int argc, char *argv[]) {

  using namespace PRISMS;

  // ----------------------------------------------------------------------
  // Construct a PBasisSet of basis fucntions that takes input of type 
  // double and return output of type double.                    
  PBasisSet<double, double> bset;

  double var = 0.8;
  double result;
  std::vector<double> result_vec;

  // Checkout the Monomial PBasisSet, including 30 basis functions
  PLibrary::checkout("Monomial", bset, 30);

  // PBasisSet::operator()(i, x) = x^i
  result = bset(0, var); // = 1
  result = bset(1, var); // = 0.8
  result = bset(2, var); // = 0.64
  // ... up to i = 29

  // PBasisSet::grad(i, x) = i*x^(i-1)
  result = bset.grad(0, var); // = 0
  result = bset.grad(1, var); // = 1
  result = bset.grad(2, var); // = 1.6
  // ... up to i = 29

  // PBasisSet::hess(i, x) = i*(i-1)*x^(i-2)
  result = bset.hess(0, var); // = 0
  result = bset.hess(1, var); // = 0
  result = bset.hess(2, var); // = 2
  // ... up to i = 29


  // ----------------------------------------------------------------------
  // Construct a vector of PBasisSets to be used by the PSeriesFunction 
  std::vector<PBasisSet<double, double> > bsets;
  bsets.push_back(bset);
  bsets.push_back(bset);
  
  // Construct a vector of ints to index the tensor basis
  std::vector<int> indices(bsets.size(), 0);

  // Construct a vector of doubles giving the input variables
  std::vector<double> vars(bsets.size(), 0.0);

  // Construct a PSeriesFunction using the PBasisSets
  // Pass in 0.0 and 1.0 to set zero and identity
  typedef PSeriesFunction<double, double, std::vector<double>, std::vector<int> > Series;
  Series series(0.0, 1.0, bsets);

  // Set the coefficients

  // Set a constant term
  series.coeff()(indices) = 1.0;

  // Set a term linear in x, constant in y
  indices[0] = 1;
  indices[1] = 0;
  series.coeff()(indices) = 2.0;

  // Set a term linear in x, quadratic in y
  indices[0] = 1;
  indices[1] = 2;
  series.coeff()(indices) = 3.0;

  // Set a term quadratic in x, cubic in y
  indices[0] = 2;
  indices[1] = 3;
  series.coeff()(indices) = 4.0;

  // Evaluate the PSeriesFunction at (0.5, 0.7)
  vars[0] = 0.5;
  vars[1] = 0.7;
  result = series(vars); // = 1.0 + 2.0*x + 3.0*x*y*y + 4.0*x*x*y*y*y = 3.078

  // Evaluate the first derivative w/ x at (0.5, 0.7)
  result = series.grad(vars, 0); // = 2.0 + 3.0*y*y + 8.0*x*y*y*y = 4.842

  // Evaluate the second derivative w/ x, y at (0.5, 0.7)
  result = series.hess(vars, 0, 1); // = 6.0*y + 24.0*x*y*y = 10.08

  return 0;
}

```

License
=======================

This directory contains the IntegrationTools code developed by the PRISMS Center at the University of Michigan, Ann Arbor, USA.

(c) 2014 The Regents of the University of Michigan

PRISMS Center http://prisms.engin.umich.edu 

This code is a free software; you can use it, redistribute it,
and/or modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either version
2.1 of the License, or (at your option) any later version.

Please see the file LICENSE for details.


Release Notes
=======================

Release 1.0.0 will include:

- PSimpleFunction, PFunction, and PBasisSet
- PSeriesFunction, with tensor product output and coefficient input
- Piecewise functions: PPieceWise
- PFields, read from .vtk files, using Quad and Hexahedron elements
- The library writer: lw
- PExtern for calls from C, Fortran, etc.
- IntegrationTools wrapper for Python, 'pfunction'
