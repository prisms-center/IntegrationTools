#include<cstring>
#include<vector>

#include "PLibrary.hh"

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
void test(std::string funcname, std::string varcontainername, std::string outtypename, std::string varname, VarContainer &var)
{
    std::cout << "// ----------------------------------------------------------------------\n";
    std::cout << "// Construct a PFunction that takes input of type " << varcontainername << "\n";
    std::cout << "// and returns output of type " << outtypename << ".                    \n";
    std::cout << "PFunction<" << varcontainername << ", " << outtypename << "> func;       \n\n";
    PFunction<VarContainer, OutType> func;
    
    // Checkout the 'funcname' function:
    std::cout << "// Checkout the " << funcname << " function.                             \n";
    std::cout << "PLibrary::checkout(\"" << funcname << "\", func);                            \n\n";
    PLibrary::checkout(funcname, func);
    
    // function:
    // write variables, and formula:
    std::cout << "// PFunction::operator()(" << func.var_name() << ") = " << func.simplefunction().sym() << "\n";
    // evaluate:
    std::cout << "func" << "(" << var << ") = " << func(var) << "\n\n";
    
    // 1st derivative:
    int di = 0; // derivative with respect to first variable
    // write variables, and formula:
    std::cout << "// PFunction::grad(" << func.var_name() << ", " << func.var_name(di) << ") = " << func.grad_simplefunction(di).sym() << "\n";
    std::cout << "func" << ".grad(" << var << ", " << di << ") = " << func.grad(var, di) << "\n\n";
    
    // 2nd derivative:
    int dj = 0; // derivative with respect to second variable
    // write variables, and formula:
    std::cout << "// PFunction::hess(" << func.var_name() << ", " << func.var_name(di) << ", " << func.var_name(dj) << ") = " << func.hess_simplefunction(di,dj).sym() << "\n";
    std::cout << "func" << ".hess(" << var << ", " << di << ", " << dj << ") = " << func.hess(var, di, dj) << "\n\n";
    
    std::cout << "// After evaluation, the latest result is stored and can be accessed multiple times without recalculation:\n";
    std::cout << "func" << "() = " << func() << "\n";
    std::cout << "func" << ".grad(" << di << ") = " << func.grad(di) << "\n";
    std::cout << "func" << ".hess(" << di << ", " << func.var_name(di) << ") = " << func.hess(di, dj) << "\n\n";
    std::cout << std::endl;
    
    std::cout << "// Use eval_grad(" << varname << ") or eval_hess(" << varname << ") to evaluate \n";
    std::cout << "// the entire gradient vector or hessian matrix.                                \n";
    std::cout << "func" << ".eval_grad(" << var << ");\n";
    func.eval_grad(var);
    
    for( int i=0; i<func.var_name().size(); i++)
    {
        std::cout << "func" << ".grad(" << i << ") = " << func.grad(i) << "\n";
    }
    std::cout << "\n";
    
    std::cout << "func" << ".eval_hess(" << var << ");\n";
    func.eval_hess(var);
    for( int i=0; i<func.var_name().size(); i++)
    {
        for( int j=0; j<func.var_name().size(); j++)
        {
            std::cout << "func" << ".hess(" << i << ", " << j << ") = " << func.hess(i, j) << "\n";
        }
    }
    
    return;
}


int main(int argc, char *argv[])
{
  std::cout << "using namespace PRISMS;\n";
  
  std::cout << "// ----------------------------------------------------------------------\n";
  std::cout << "// Create an input variable vector, for a function of a single variable. \n";
  std::cout << "// PFunctions evalulate with [], so even a function of a single variable \n";
  std::cout << "// takes a container as input.                                           \n";
  std::cout << "std::vector<double> var(1, 2.1);\n";
  std::vector<double> var(1, 2.1);
  std::cout << "\n";
  
  // Run the 'test' on the 'Quadratic' function (in tests/testlib/Quadratic.hh)
  test<std::vector<double>, double>("Quadratic", "std::vector<double>", "double", "var", var);
  std::cout << "\n";
  
  std::cout << "// ----------------------------------------------------------------------\n";
  std::cout << "// Add another variable for a function of two variables. \n";
  std::cout << "var.push_back(3.5);\n";
  var.push_back(3.5);
  std::cout << "\n";
  
  // Run the 'test' on the 'MyFunc' function (in tests/testlib/MyFunc.hh)
  test<std::vector<double>, double>("MyFunc", "std::vector<double>", "double", "var", var);
  std::cout << "\n";
  
  std::cout << "finish" << std::endl;
  
  return 0;
}