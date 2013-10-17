#ifndef PLIBRARY_HH
#define PLIBRARY_HH

#include<cstring>
#include<vector>

namespace PRISMS
{

    /// Library where you can find functions and basis sets
    ///
    class PLibrary
    {
        public:
        void checkout( std::string name, PSimpleFunction< double, double > &simplefunc);
        void checkout( std::string name, PSimpleFunction< std::vector<double>, double > &simplefunc);
        void checkout( std::string name, PSimpleFunction< double*, double > &simplefunc);

        void checkout( std::string name, PFunction< std::vector<double>, double > &simplefunc);
        void checkout( std::string name, PFunction< double*, double > &simplefunc);

        void checkout( std::string name, PBasisSet< double, double > &basis_set, int N);
    };

}


#endif
