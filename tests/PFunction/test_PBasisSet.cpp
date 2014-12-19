#include<cstring>
#include<vector>

#include "PLibrary.hh"

int main(int argc, char *argv[])
{

  using namespace PRISMS;

  std::cout << "#include \"PLibrary.hh\"\n";
  std::cout << "#include <vector>\n";
  std::cout << "#include <cstring>\n\n";
  std::cout << "int main(int argc, char *argv[]) {\n\n";
  std::cout << "  using namespace PRISMS;\n\n";
  std::cout << "  // ----------------------------------------------------------------------\n";
  std::cout << "  // Construct a PBasisSet of basis fucntions that takes input of type \n";
  std::cout << "  // double and return output of type double.                    \n";
  PBasisSet<double, double> bset;       
  std::cout << "  PBasisSet<double, double> bset;\n\n";
  
  double var = 0.8;
  std::cout << "  double var = 0.8;\n";
  double result;
  std::cout << "  double result;\n";
  std::vector<double> result_vec;
  std::cout << "  std::vector<double> result_vec;\n\n";
  
  std::cout << "  // Checkout the Monomial PBasisSet, including 30 basis functions\n";
  PLibrary::checkout("Monomial", bset, 30);                            
  std::cout << "  PLibrary::checkout(\"Monomial\", bset, 30);\n\n";
  
  std::cout << "  // PBasisSet::operator()(i, x) = x^i\n";
  result = bset(0, var); // = 1.0
  std::cout << "  result = bset(0, var); // = " << result << "\n";
  result = bset(1, var); // = 0.8
  std::cout << "  result = bset(1, var); // = " << result << "\n";
  result = bset(2, var); // = 0.64
  std::cout << "  result = bset(2, var); // = " << result << "\n";
  std::cout << "  // ... up to i = 29\n\n";


  std::cout << "  // PBasisSet::grad(i, x) = i*x^(i-1)\n";
  result = bset.grad(0, var); // = 0.0
  std::cout << "  result = bset.grad(0, var); // = " << result << "\n";
  result = bset.grad(1, var); // = 1.0
  std::cout << "  result = bset.grad(1, var); // = " << result << "\n";
  result = bset.grad(2, var); // = 1.6
  std::cout << "  result = bset.grad(2, var); // = " << result << "\n";
  std::cout << "  // ... up to i = 29\n\n";

  std::cout << "  // PBasisSet::hess(i, x) = i*(i-1)*x^(i-2)\n";
  result = bset.hess(0, var); // = 0.0
  std::cout << "  result = bset.hess(0, var); // = " << result << "\n";
  result = bset.hess(1, var); // = 0.0
  std::cout << "  result = bset.hess(1, var); // = " << result << "\n";
  result = bset.hess(2, var); // = 2.0
  std::cout << "  result = bset.hess(2, var); // = " << result << "\n";
  std::cout << "  // ... up to i = 29\n\n\n";


  std::cout << "  // ----------------------------------------------------------------------\n";
  std::cout << "  // Construct a vector of PBasisSets to be used by the PSeriesFunction \n";
  std::vector<PBasisSet<double, double> > bsets;
  std::cout << "  std::vector<PBasisSet<double, double> > bsets;\n";
  bsets.push_back(bset);
  std::cout << "  bsets.push_back(bset);\n";
  bsets.push_back(bset);
  std::cout << "  bsets.push_back(bset);\n\n";
  
  std::cout << "  // Construct a vector of ints to index the tensor basis\n";
  std::vector<int> indices(bsets.size(), 0);
  std::cout << "  std::vector<int> indices(bsets.size(), 0);\n\n";
  
  std::cout << "  // Construct a vector of doubles giving the input variables\n";
  std::vector<double> vars(bsets.size(), 0.0);
  std::cout << "  std::vector<double> vars(bsets.size(), 0.0);\n\n";
  
  std::cout << "  // Construct a PSeriesFunction using the PBasisSets\n";
  std::cout << "  // Pass in 0.0 and 1.0 to set zero and identity\n";
  typedef PSeriesFunction<double, double, std::vector<double>, std::vector<int> > Series;
  std::cout << "  typedef PSeriesFunction<double, double, std::vector<double>, std::vector<int> > Series;\n";
  Series series(0.0, 1.0, bsets);
  std::cout << "  Series series(0.0, 1.0, bsets);\n\n";
  
  std::cout << "  // Set the coefficients\n\n";

  std::cout << "  // Set a constant term\n";
  series.coeff()(indices) = 1.0;
  std::cout << "  series.coeff()(indices) = 1.0;\n\n";

  std::cout << "  // Set a term linear in x, constant in y\n";
  indices[0] = 1;
  std::cout << "  indices[0] = 1;\n";
  indices[1] = 0;
  std::cout << "  indices[1] = 0;\n";
  series.coeff()(indices) = 2.0;
  std::cout << "  series.coeff()(indices) = 2.0;\n\n";

  std::cout << "  // Set a term linear in x, quadratic in y\n";
  indices[0] = 1;
  std::cout << "  indices[0] = 1;\n";
  indices[1] = 2;
  std::cout << "  indices[1] = 2;\n";
  series.coeff()(indices) = 3.0;
  std::cout << "  series.coeff()(indices) = 3.0;\n\n";

  std::cout << "  // Set a term quadratic in x, cubic in y\n";
  indices[0] = 2;
  std::cout << "  indices[0] = 2;\n";
  indices[1] = 3;
  std::cout << "  indices[1] = 3;\n";
  series.coeff()(indices) = 4.0;
  std::cout << "  series.coeff()(indices) = 4.0;\n\n";

  std::cout << "  // Evaluate the PSeriesFunction at (0.5, 0.7)\n";
  vars[0] = 0.5;
  std::cout << "  vars[0] = 0.5;\n";
  vars[1] = 0.7;
  std::cout << "  vars[1] = 0.7;\n";
  result = series(vars); // = 1.0 + 2.0*x + 3.0*x*y*y + 4.0*x*x*y*y*y = 3.078
  std::cout << "  result = series(vars); // = 1.0 + 2.0*x + 3.0*x*y*y + 4.0*x*x*y*y*y = " << result << "\n\n";

  std::cout << "  // Evaluate the first derivative w/ x at (0.5, 0.7)\n";
  result = series.grad(vars, 0); // = 2.0 + 3.0*y*y + 8.0*x*y*y*y = 4.842
  std::cout << "  result = series.grad(vars, 0); // = 2.0 + 3.0*y*y + 8.0*x*y*y*y = " << result << "\n\n";

  std::cout << "  // Evaluate the second derivative w/ x, y at (0.5, 0.7)\n";
  result = series.hess(vars, 0, 1); // = 6.0*y + 24.0*x*y*y = 
  std::cout << "  result = series.hess(vars, 0, 1); // = 6.0*y + 24.0*x*y*y = " << result << "\n\n";

  std::cout << "  return 0;\n}\n";
  return 0;

}
