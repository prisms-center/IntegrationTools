/*
 *  test.cpp
 */

#include<cstring>
#include<iomanip>
#include<vector>

#include "IntegrationTools/PField.hh"



int main(int argc, char *argv[])
{
    const int DIM = 3;
    
    typedef PRISMS::PField<double*, double, DIM> ScalarField3D;
    typedef PRISMS::Body<double*, DIM> Body3D;
    
    double coord[DIM];
    double tmp[DIM];
    Body3D body;
    
    
    body.read_vtk("3D.vtk");
    
    ScalarField3D &conc = body.find_scalar_field("c");
    
    int i;
    std::cout << "pause: ";
    std::cin >> i;
    std::cout << std::endl;
    
    double incr[DIM];
    incr[0] = (body.mesh.max(0) - body.mesh.min(0))/10.0;
    incr[1] = (body.mesh.max(1) - body.mesh.min(1))/10.0;
    incr[2] = (body.mesh.max(2) - body.mesh.min(2))/10.0;
    
    std::cout << "\n--- Volume ----\n" << std::endl;
    
    for( int i=0; i<10; i++)
    for( int j=0; j<10; j++)
    for( int k=0; k<10; k++)
    {
        coord[0] = i*incr[0];
        coord[1] = j*incr[1];
        coord[2] = k*incr[2];
        
        std::cout << "Coord: ";
        for( int j=0; j<DIM; j++)
            std::cout << coord[j] << " ";
        std::cout << "  Conc: " << conc( coord) << std::endl;
        
    }
    
    std::cout << "\n--- Line ----\n" << std::endl;
    
    coord[0] = 0.7;
    coord[1] = 0.2;
    coord[2] = 0.7;
    
    incr[0] = (body.mesh.max(0) - body.mesh.min(0))/100.0;
    
    for( int i=0; i<100; i++)
    {
        coord[0] = i*incr[0];
        std::cout << "Coord: ";
        for( int j=0; j<DIM; j++)
            std::cout << coord[j] << " ";
        std::cout << "  Conc: " << conc( coord) << std::endl;
        std::cout << "  Grad: " << conc.grad(coord,0) << " " << conc.grad(coord,1) << " " << conc.grad(coord,2) << std::endl;
        std::cout << "  Hess: " << conc.hess(coord,0,0) << " " << conc.hess(coord,0,1) << " " << conc.hess(coord,0,2) << std::endl; 
        std::cout << "  Hess: " << conc.hess(coord,1,0) << " " << conc.hess(coord,1,1) << " " << conc.hess(coord,1,2) << std::endl;
        std::cout << "  Hess: " << conc.hess(coord,2,0) << " " << conc.hess(coord,2,1) << " " << conc.hess(coord,2,2) << std::endl << std::endl;
    }
    
    return 0;
}
