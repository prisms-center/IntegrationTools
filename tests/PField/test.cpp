/*
 *  test.cpp
 */

#include<cstring>
#include<iomanip>
#include<vector>

#include "IntegrationTools/PField.hh"



int main(int argc, char *argv[])
{
    PRISMS::Coordinate<2> coord;
    PRISMS::Body<PRISMS::Coordinate<2> > body(coord);
    
    
    body.read_2d_vtk("2D.vtk");
    
    PRISMS::PField<PRISMS::Coordinate<2>, double> &conc = body.find_scalar_field("c");
    
    double incr = (body.mesh.max()[0] - body.mesh.min()[0])/100.0;
    coord[0] = body.mesh.min()[0];
    coord[1] = 0.24;
    
    for( int i=0; i<100; i++)
    {
        std::cout << "x: " << coord[0] << " y: " << coord[1] << "  c: " << conc( coord) << std::endl;
        coord[0] += incr;
    }
    
    return 0;
}
