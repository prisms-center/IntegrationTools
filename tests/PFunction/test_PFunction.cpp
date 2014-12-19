#include "PLibrary.hh"
#include <vector>
#include <cstring>

int main(int argc, char *argv[]) {
  
  using namespace PRISMS;
  
  std::cout << "#include \"PLibrary.hh\"\n";
  std::cout << "#include <vector>\n";
  std::cout << "#include <cstring>\n\n";
  std::cout << "int main(int argc, char *argv[]) {\n\n";
  std::cout << "  using namespace PRISMS;\n\n";
  std::cout << "  // ----------------------------------------------------------------------\n";
  std::cout << "  // Create an input variable vector, for a function of a single variable.\n";
  std::cout << "  // PFunctions typically evalulate with [], so even a function of a single\n";
  std::cout << "  // variable takes a container as input.\n";
  std::vector<double> var(1, 2.1);
  std::cout << "\n  std::vector<double> var(1, 2.1);\n";
  
  double result;
  std::cout << "\n  double result;\n";

  std::cout << "\n  // ----------------------------------------------------------------------\n";
  std::cout << "  // Construct a PFunction that takes input of type std::vector<double>\n";
  std::cout << "  // and returns output of type double.\n";
  PFunction<std::vector<double>, double> func;       
  std::cout << "  PFunction<std::vector<double>, double> func;\n";
  
  std::cout << "\n  // Checkout the Quadratic function.\n";
  PLibrary::checkout("Quadratic", func);                            
  std::cout << "  PLibrary::checkout(\"Quadratic\", func);\n";
  
  std::cout << "\n  // PFunction::operator()([x]) = 1+x+x^2\n";
  result = func(var); // = 7.51
  std::cout << "  result = func(var); // = " << result << "\n";
  
  std::cout << "\n  // PFunction::grad([x], x); //  = 1+2*x\n";
  result = func.grad(var, 0); //  = 5.2
  std::cout << "  result = func.grad(var, 0); //  = " << result << "\n";
  
  std::cout <<"\n  // PFunction::hess([x], x, x); //  = 2 \n";
  result = func.hess(var, 0, 0); //  = 2
  std::cout << "  result = func.hess(var, 0, 0); //  = " << result << "\n";
  
  std::cout << "\n  // After evaluation, the latest result is stored and can be accessed\n";
  std::cout << "  // multiple times without recalculation:\n";
  result = func(); //  = 7.51
  std::cout << "  result = func(); //  = " << result << "\n";
  result = func.grad(0); //  = 5.2
  std::cout << "  result = func.grad(0); //  = " << result << "\n";
  result = func.hess(0, 0); //  = 2
  std::cout << "  result = func.hess(0, 0); //  = " << result << "\n";
  

  std::cout << "\n  // Use eval_grad(var) or eval_hess(var) to evaluate \n";
  std::cout << "  // the entire gradient vector or hessian matrix.\n";
  func.eval_grad(var);
  std::cout << "\n  func.eval_grad(var);\n";
  result = func.grad(0); //  = 5.2
  std::cout << "  result = func.grad(0); //  = " << result << "\n";
  
  func.eval_hess(var);
  std::cout << "\n  func.eval_hess(var);\n";
  result = func.hess(0, 0); //  = 2
  std::cout << "  result = func.hess(0, 0); //  = " << result << "\n";
  
  std::cout << "\n  // ----------------------------------------------------------------------\n";
  std::cout << "  // Add another variable for a function of two variables. \n";
  var.push_back(3.5);
  std::cout << "  var.push_back(3.5);\n";
  
  std::cout << "\n  // Checkout the MyFunc function.\n";
  PLibrary::checkout("MyFunc", func);                            
  std::cout << "  PLibrary::checkout(\"MyFunc\", func);\n";
  
  std::cout << "\n  // PFunction::operator()([x, y]) = x*y^2+y^3+x^2*y+x^3\n";
  result = func(var); //  = 93.296
  std::cout << "  result = func(var); //  = " << result << "\n";
  
  std::cout << "\n  // PFunction::grad([x, y], x); //  = y^2+2*x*y+3*x^2\n";
  result = func.grad(var, 0); //  = 40.18
  std::cout << "  result = func.grad(var, 0); //  = " << result << "\n";
  
  std::cout << "\n  // PFunction::hess([x, y], x, x); //  = 2*y+6*x\n";
  result = func.hess(var, 0, 0); //  = 19.6
  std::cout << "  result = func.hess(var, 0, 0); //  = " << result << "\n";
  
  std::cout << "\n  // After evaluation, the latest result is stored and can be accessed \n";
  std::cout << "  // multiple times without recalculation:\n";
  result = func(); //  = 93.296;
  std::cout << "\n  result = func(); //  = " << result << "\n";
  result = func.grad(0); //  = 40.18
  std::cout << "  result = func.grad(0); //  = " << result << "\n";
  result = func.hess(0, 1); //  = 19.6
  std::cout << "  result = func.hess(0, 1); //  = " << result << "\n";
  

  std::cout << "\n  // Use eval_grad(var) or eval_hess(var) to evaluate\n"; 
  std::cout << "  // the entire gradient vector or hessian matrix.\n";                         
  func.eval_grad(var);
  std::cout << "  func.eval_grad(var);\n";
  result = func.grad(0); //  = 40.18
  std::cout << "  result = func.grad(0); //  = " << result << "\n";
  result = func.grad(1); //  = 55.86
  std::cout << "  result = func.grad(1); //  = " << result << "\n";
  
  func.eval_hess(var);
  std::cout << "\n  func.eval_hess(var);\n";
  result = func.hess(0, 0); // = 19.6
  std::cout << "  result = func.hess(0, 0); //  = " << result << "\n";
  result = func.hess(0, 1); //  = 11.2
  std::cout << "  result = func.hess(0, 1); //  = " << result << "\n";
  result = func.hess(1, 0); //  = 11.2
  std::cout << "  result = func.hess(1, 0); //  = " << result << "\n";
  result = func.hess(1, 1); //  = 25.2
  std::cout << "  result = func.hess(1, 1); //  = " << result << "\n";
  
  std::cout << "\n  return 0;\n}\n";
  return 0;
}
