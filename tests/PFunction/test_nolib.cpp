#include<cstring>
#include<vector>

#include "Quadratic.hh"
#include "MyFunc.hh"
#include "MyPieceWiseFunc.hh"
#include "Monomial.hh"
#include "Chebyshev.hh"

using namespace PRISMS;

template<typename T>
std::ostream& operator<<(std::ostream &sout, const std::vector<T> &v)
{
    sout << "[";
    for( int i=0; i<v.size(); i++)
    {
        sout << v[i];
        if( i!=v.size()-1)
            sout << ", ";
        else
            sout << "]";
    }
    return sout;
}


template< class VarContainer, class OutType>
void test(std::string funcvarname, PFuncBase<VarContainer, OutType> &func, std::string varcontainername, std::string varname, VarContainer &var, std::string outtypename)
{
    std::cout << "// ----------------------------------------------------------------------\n";
    std::cout << "// " << func.name() << ", a class that inherits from                     \n";
    std::cout << "//    PFuncBase<" << varcontainername << ", " << outtypename << ">:\n\n";
    
    // Construct a Quadratic function, that accepts vector<double> input
    std::cout << "// Construct the " << func.name() << " function object:\n";
    std::cout << func.name() << "<" << varcontainername << " > " << funcvarname << ";\n";
    std::cout << "\n";
    
    // function:
    // write variables, and formula:
    std::cout << "// " << func.name() << "::operator()(" << func.var_name() << ") = " << func.simplefunction().sym() << "\n";
    // evaluate:
    std::cout << funcvarname << "(" << var << ") = " << func(var) << "\n\n";
    
    // 1st derivative:
    int di = 0; // derivative with respect to first variable
    // write variables, and formula:
    std::cout << "// " << func.name() << "::grad(" << func.var_name() << ", " << func.var_name(di) << ") = " << func.grad_simplefunction(di).sym() << "\n";
    std::cout << funcvarname << ".grad(" << var << ", " << di << ") = " << func.grad(var, di) << "\n\n";
    
    // 2nd derivative:
    int dj = 0; // derivative with respect to second variable
    // write variables, and formula:
    std::cout << "// " << func.name() << "::hess(" << func.var_name() << ", " << func.var_name(di) << ", " << func.var_name(dj) << ") = " << func.hess_simplefunction(di,dj).sym() << "\n";
    std::cout << funcvarname << ".hess(" << var << ", " << di << ", " << dj << ") = " << func.hess(var, di, dj) << "\n\n";
    
    std::cout << "// After evaluation, the latest result is stored and can be accessed multiple times without recalculation:\n";
    std::cout << funcvarname << "() = " << func() << "\n";
    std::cout << funcvarname << ".grad(" << di << ") = " << func.grad(di) << "\n";
    std::cout << funcvarname << ".hess(" << di << ", " << func.var_name(di) << ") = " << func.hess(di, dj) << "\n\n";
    std::cout << std::endl;
    
    std::cout << "// Use eval_grad(" << varname << ") or eval_hess(" << varname << ") to evaluate \n";
    std::cout << "// the entire gradient vector or hessian matrix.                                \n";
    std::cout << funcvarname << ".eval_grad(" << var << ");\n";
    func.eval_grad(var);
    
    for( int i=0; i<func.var_name().size(); i++)
    {
        std::cout << funcvarname << ".grad(" << i << ") = " << func.grad(i) << "\n";
    }
    std::cout << "\n";
    
    std::cout << funcvarname << ".eval_hess(" << var << ");\n";
    func.eval_hess(var);
    for( int i=0; i<func.var_name().size(); i++)
    {
        for( int j=0; j<func.var_name().size(); j++)
        {
            std::cout << funcvarname << ".hess(" << i << ", " << j << ") = " << func.hess(i, j) << "\n";
        }
    }
    
    return;
}


int main(int argc, char *argv[])
{
  std::cout << "using namespace PRISMS;\n";
  
  std::cout << "// ----------------------------------------------------------------------\n";
  std::cout << "// Create an input variable vector, for a function of a single variable. \n";
  std::cout << "// PFunctions evalualte with [], so even a function of a single variable \n";
  std::cout << "// takes a container as input.                                           \n";
  std::cout << "std::vector<double> var(1, 2.1);\n";
  std::vector<double> var(1, 2.1);
  std::cout << "\n";
  
  Quadratic<std::vector<double> > quad;
  test("quad", quad, "std::vector<double>", "var", var, "double");
  std::cout << "\n";
  
  std::cout << "// ----------------------------------------------------------------------\n";
  std::cout << "// Add another variable for a function of two variables. \n";
  std::cout << "var.push_back(3.5);\n";
  var.push_back(3.5);
  std::cout << "\n";
  
  MyFunc<std::vector<double> > myfunc;
  test("myfunc", myfunc, "std::vector<double>", "var", var, "double");
  std::cout << "\n";
  
  
  std::cout << "// ----------------------------------------------------------------------\n";
  std::cout << "// Use PFunction to hold any function. A PFunction contains a PFuncBase* \n";
  std::cout << "// which it deletes upon destruction so you don't have to work with      \n";
  std::cout << "// pointers. It has the same interface as PFuncBase.                     \n";
  std::cout << "PFunction<std::vector<double>, double> pfunc = MyFunc<std::vector<double> >();\n";
  PFunction<std::vector<double>, double> pfunc = MyFunc<std::vector<double> >();
  std::cout << "pfunc(" << var << ") = " << pfunc(var) << "\n";
  std::cout << "pfunc.grad(" << var << ", 0) = " << pfunc.grad(var, 0) << "\n\n";
  
  std::cout << "// In this case, only the first element of the input container is used.\n";
  std::cout << "pfunc = Quadratic<std::vector<double> >();\n";
  pfunc = Quadratic<std::vector<double> >();
  std::cout << "pfunc(" << var << ") = " << pfunc(var) << "\n";
  std::cout << "pfunc.grad(" << var << ", 0) = " << pfunc.grad(var, 0) << "\n\n";
  
  std::cout << "// Assign any type that inherits from PFuncBase to a PFunction.\n";
  std::cout << "pfunc = myfunc;\n";
  pfunc = myfunc;
  std::cout << "pfunc() = " << pfunc() << "\n";
  std::cout << "pfunc.grad(0) = " << pfunc.grad(0) << "\n\n";
  
  std::cout << "// Assign any type that inherits from PFuncBase to a PFunction.\n";
  std::cout << "pfunc = quad;\n";
  pfunc = quad;
  std::cout << "pfunc() = " << pfunc() << "\n";
  std::cout << "pfunc.grad(0) = " << pfunc.grad(0) << "\n\n";
  
  std::cout << "finish" << std::endl;
  
  return 0;
}