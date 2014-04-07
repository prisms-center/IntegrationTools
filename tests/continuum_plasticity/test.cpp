/*
 *  test.cpp
 */

#include<cstring>
#include<iomanip>
#include<vector>

#include "Library/PLibrary.hh"
#include "IntegrationTools/PFunction.hh"

int main(int argc, char *argv[])
{
    
    
    // ///////////////////////////////
    // Checking out PFunctions
    PRISMS::PFunction< std::vector<double>, double> strain_energy;
    PRISMS::PFunction< std::vector<double>, double> yield;
    PRISMS::PLibrary::checkout("quadlog", strain_energy);
    PRISMS::PLibrary::checkout("von_mises", yield);
    
    
    
    // ///////////////////////////////
    // Checking variable order and type
    std::cout << "Yield function: " << yield.name() << std::endl;
    for( int i=0; i<yield.size(); i++)
    {
        std::cout << i << ": " << std::setw(20) << yield.var_name(i) << std::setw(40) <<  yield.var_description(i) << std::endl;
    }
    std::cout << std::endl;
    
    std::cout << "Strain energy function: " << strain_energy.name() << std::endl;
    for( int i=0; i<strain_energy.size(); i++)
    {
        std::cout << i << ": " << std::setw(20) << strain_energy.var_name(i) << std::setw(40) <<  strain_energy.var_description(i) << std::endl;
    }
    std::cout << std::endl;
    
    // ///////////////////////////////
    // Evaluating a PFunction
    
    std::vector<double> variables;
    /*strain energy function: quadlog
    0:               lambda                    First Lame parameter
    1:                   mu                   Second Lame parameter
    2:              lambda1                 First principle stretch
    3:              lambda2                Second principle stretch
    4:              lambda3                 Third principle stretch
    5:                    K            Strain hardening coefficient
    6:                alpha               Equivalent plastic strain
    */
    variables.push_back(9.15e10);
    variables.push_back(1.8e10);
    variables.push_back(1.2);
    variables.push_back(1.1);
    variables.push_back(1.1);
    variables.push_back(5e8);
    variables.push_back(1.001);
    
    std::cout << "Test evaluation:" << std::endl;
    for( int i=0; i<strain_energy.size(); i++)
    {
        std::cout << i << ": " << std::setw(20) << strain_energy.var_name(i) << std::setw(40) <<  variables[i] << std::endl;
    }
    
    std::cout << "strain energy (" << strain_energy.name() << "): " << strain_energy(variables) << std::endl;
    std::cout << "strain energy (" << strain_energy.name() << ") grad lambda1: " << strain_energy.grad(variables,2) << std::endl;
    std::cout << "strain energy (" << strain_energy.name() << ") hess lambda1, lambda2: " << strain_energy.hess(variables,2,3) << std::endl;
    std::cout << std::endl;
    
    
    return 0;
}
