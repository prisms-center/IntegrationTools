#ifndef PLIBRARY_CC
#define PLIBRARY_CC

#include<cstring>
#include<vector>
#include "Chebyshev.hh"
#include "Monomial.hh"
#include "MyFunc.hh"
#include "MyPieceWiseFunc.hh"
#include "Quadratic.hh"
#include "PLibrary.hh"

namespace PRISMS
{

        void PLibrary::checkout( std::string name, PSimpleFunction< double, double > &simplefunc)
        {
            typedef PSimpleFunction< double, double > psf;
            if( name == "Chebyshev_0") simplefunc = psf( Chebyshev_0() );
            if( name == "Chebyshev_1") simplefunc = psf( Chebyshev_1() );
            if( name == "Chebyshev_2") simplefunc = psf( Chebyshev_2() );
            if( name == "Chebyshev_3") simplefunc = psf( Chebyshev_3() );
            if( name == "Chebyshev_4") simplefunc = psf( Chebyshev_4() );
            if( name == "Chebyshev_5") simplefunc = psf( Chebyshev_5() );
            if( name == "Chebyshev_6") simplefunc = psf( Chebyshev_6() );
            if( name == "Chebyshev_7") simplefunc = psf( Chebyshev_7() );
            if( name == "Chebyshev_8") simplefunc = psf( Chebyshev_8() );
            if( name == "Chebyshev_9") simplefunc = psf( Chebyshev_9() );
            if( name == "Chebyshev_10") simplefunc = psf( Chebyshev_10() );
            if( name == "Chebyshev_11") simplefunc = psf( Chebyshev_11() );
            if( name == "Chebyshev_12") simplefunc = psf( Chebyshev_12() );
            if( name == "Chebyshev_13") simplefunc = psf( Chebyshev_13() );
            if( name == "Chebyshev_14") simplefunc = psf( Chebyshev_14() );
            if( name == "Chebyshev_15") simplefunc = psf( Chebyshev_15() );
            if( name == "Chebyshev_16") simplefunc = psf( Chebyshev_16() );
            if( name == "Chebyshev_17") simplefunc = psf( Chebyshev_17() );
            if( name == "Chebyshev_18") simplefunc = psf( Chebyshev_18() );
            if( name == "Chebyshev_19") simplefunc = psf( Chebyshev_19() );
            if( name == "Chebyshev_20") simplefunc = psf( Chebyshev_20() );
            if( name == "Chebyshev_21") simplefunc = psf( Chebyshev_21() );
            if( name == "Chebyshev_22") simplefunc = psf( Chebyshev_22() );
            if( name == "Chebyshev_23") simplefunc = psf( Chebyshev_23() );
            if( name == "Chebyshev_24") simplefunc = psf( Chebyshev_24() );
            if( name == "Chebyshev_25") simplefunc = psf( Chebyshev_25() );
            if( name == "Chebyshev_26") simplefunc = psf( Chebyshev_26() );
            if( name == "Chebyshev_27") simplefunc = psf( Chebyshev_27() );
            if( name == "Chebyshev_28") simplefunc = psf( Chebyshev_28() );
            if( name == "Chebyshev_29") simplefunc = psf( Chebyshev_29() );
            if( name == "Chebyshev_0_grad") simplefunc = psf( Chebyshev_0_grad() );
            if( name == "Chebyshev_1_grad") simplefunc = psf( Chebyshev_1_grad() );
            if( name == "Chebyshev_2_grad") simplefunc = psf( Chebyshev_2_grad() );
            if( name == "Chebyshev_3_grad") simplefunc = psf( Chebyshev_3_grad() );
            if( name == "Chebyshev_4_grad") simplefunc = psf( Chebyshev_4_grad() );
            if( name == "Chebyshev_5_grad") simplefunc = psf( Chebyshev_5_grad() );
            if( name == "Chebyshev_6_grad") simplefunc = psf( Chebyshev_6_grad() );
            if( name == "Chebyshev_7_grad") simplefunc = psf( Chebyshev_7_grad() );
            if( name == "Chebyshev_8_grad") simplefunc = psf( Chebyshev_8_grad() );
            if( name == "Chebyshev_9_grad") simplefunc = psf( Chebyshev_9_grad() );
            if( name == "Chebyshev_10_grad") simplefunc = psf( Chebyshev_10_grad() );
            if( name == "Chebyshev_11_grad") simplefunc = psf( Chebyshev_11_grad() );
            if( name == "Chebyshev_12_grad") simplefunc = psf( Chebyshev_12_grad() );
            if( name == "Chebyshev_13_grad") simplefunc = psf( Chebyshev_13_grad() );
            if( name == "Chebyshev_14_grad") simplefunc = psf( Chebyshev_14_grad() );
            if( name == "Chebyshev_15_grad") simplefunc = psf( Chebyshev_15_grad() );
            if( name == "Chebyshev_16_grad") simplefunc = psf( Chebyshev_16_grad() );
            if( name == "Chebyshev_17_grad") simplefunc = psf( Chebyshev_17_grad() );
            if( name == "Chebyshev_18_grad") simplefunc = psf( Chebyshev_18_grad() );
            if( name == "Chebyshev_19_grad") simplefunc = psf( Chebyshev_19_grad() );
            if( name == "Chebyshev_20_grad") simplefunc = psf( Chebyshev_20_grad() );
            if( name == "Chebyshev_21_grad") simplefunc = psf( Chebyshev_21_grad() );
            if( name == "Chebyshev_22_grad") simplefunc = psf( Chebyshev_22_grad() );
            if( name == "Chebyshev_23_grad") simplefunc = psf( Chebyshev_23_grad() );
            if( name == "Chebyshev_24_grad") simplefunc = psf( Chebyshev_24_grad() );
            if( name == "Chebyshev_25_grad") simplefunc = psf( Chebyshev_25_grad() );
            if( name == "Chebyshev_26_grad") simplefunc = psf( Chebyshev_26_grad() );
            if( name == "Chebyshev_27_grad") simplefunc = psf( Chebyshev_27_grad() );
            if( name == "Chebyshev_28_grad") simplefunc = psf( Chebyshev_28_grad() );
            if( name == "Chebyshev_29_grad") simplefunc = psf( Chebyshev_29_grad() );
            if( name == "Chebyshev_0_hess") simplefunc = psf( Chebyshev_0_hess() );
            if( name == "Chebyshev_1_hess") simplefunc = psf( Chebyshev_1_hess() );
            if( name == "Chebyshev_2_hess") simplefunc = psf( Chebyshev_2_hess() );
            if( name == "Chebyshev_3_hess") simplefunc = psf( Chebyshev_3_hess() );
            if( name == "Chebyshev_4_hess") simplefunc = psf( Chebyshev_4_hess() );
            if( name == "Chebyshev_5_hess") simplefunc = psf( Chebyshev_5_hess() );
            if( name == "Chebyshev_6_hess") simplefunc = psf( Chebyshev_6_hess() );
            if( name == "Chebyshev_7_hess") simplefunc = psf( Chebyshev_7_hess() );
            if( name == "Chebyshev_8_hess") simplefunc = psf( Chebyshev_8_hess() );
            if( name == "Chebyshev_9_hess") simplefunc = psf( Chebyshev_9_hess() );
            if( name == "Chebyshev_10_hess") simplefunc = psf( Chebyshev_10_hess() );
            if( name == "Chebyshev_11_hess") simplefunc = psf( Chebyshev_11_hess() );
            if( name == "Chebyshev_12_hess") simplefunc = psf( Chebyshev_12_hess() );
            if( name == "Chebyshev_13_hess") simplefunc = psf( Chebyshev_13_hess() );
            if( name == "Chebyshev_14_hess") simplefunc = psf( Chebyshev_14_hess() );
            if( name == "Chebyshev_15_hess") simplefunc = psf( Chebyshev_15_hess() );
            if( name == "Chebyshev_16_hess") simplefunc = psf( Chebyshev_16_hess() );
            if( name == "Chebyshev_17_hess") simplefunc = psf( Chebyshev_17_hess() );
            if( name == "Chebyshev_18_hess") simplefunc = psf( Chebyshev_18_hess() );
            if( name == "Chebyshev_19_hess") simplefunc = psf( Chebyshev_19_hess() );
            if( name == "Chebyshev_20_hess") simplefunc = psf( Chebyshev_20_hess() );
            if( name == "Chebyshev_21_hess") simplefunc = psf( Chebyshev_21_hess() );
            if( name == "Chebyshev_22_hess") simplefunc = psf( Chebyshev_22_hess() );
            if( name == "Chebyshev_23_hess") simplefunc = psf( Chebyshev_23_hess() );
            if( name == "Chebyshev_24_hess") simplefunc = psf( Chebyshev_24_hess() );
            if( name == "Chebyshev_25_hess") simplefunc = psf( Chebyshev_25_hess() );
            if( name == "Chebyshev_26_hess") simplefunc = psf( Chebyshev_26_hess() );
            if( name == "Chebyshev_27_hess") simplefunc = psf( Chebyshev_27_hess() );
            if( name == "Chebyshev_28_hess") simplefunc = psf( Chebyshev_28_hess() );
            if( name == "Chebyshev_29_hess") simplefunc = psf( Chebyshev_29_hess() );
            if( name == "Monomial_0") simplefunc = psf( Monomial_0() );
            if( name == "Monomial_1") simplefunc = psf( Monomial_1() );
            if( name == "Monomial_2") simplefunc = psf( Monomial_2() );
            if( name == "Monomial_3") simplefunc = psf( Monomial_3() );
            if( name == "Monomial_4") simplefunc = psf( Monomial_4() );
            if( name == "Monomial_5") simplefunc = psf( Monomial_5() );
            if( name == "Monomial_6") simplefunc = psf( Monomial_6() );
            if( name == "Monomial_7") simplefunc = psf( Monomial_7() );
            if( name == "Monomial_8") simplefunc = psf( Monomial_8() );
            if( name == "Monomial_9") simplefunc = psf( Monomial_9() );
            if( name == "Monomial_10") simplefunc = psf( Monomial_10() );
            if( name == "Monomial_11") simplefunc = psf( Monomial_11() );
            if( name == "Monomial_12") simplefunc = psf( Monomial_12() );
            if( name == "Monomial_13") simplefunc = psf( Monomial_13() );
            if( name == "Monomial_14") simplefunc = psf( Monomial_14() );
            if( name == "Monomial_15") simplefunc = psf( Monomial_15() );
            if( name == "Monomial_16") simplefunc = psf( Monomial_16() );
            if( name == "Monomial_17") simplefunc = psf( Monomial_17() );
            if( name == "Monomial_18") simplefunc = psf( Monomial_18() );
            if( name == "Monomial_19") simplefunc = psf( Monomial_19() );
            if( name == "Monomial_20") simplefunc = psf( Monomial_20() );
            if( name == "Monomial_21") simplefunc = psf( Monomial_21() );
            if( name == "Monomial_22") simplefunc = psf( Monomial_22() );
            if( name == "Monomial_23") simplefunc = psf( Monomial_23() );
            if( name == "Monomial_24") simplefunc = psf( Monomial_24() );
            if( name == "Monomial_25") simplefunc = psf( Monomial_25() );
            if( name == "Monomial_26") simplefunc = psf( Monomial_26() );
            if( name == "Monomial_27") simplefunc = psf( Monomial_27() );
            if( name == "Monomial_28") simplefunc = psf( Monomial_28() );
            if( name == "Monomial_29") simplefunc = psf( Monomial_29() );
            if( name == "Monomial_0_grad") simplefunc = psf( Monomial_0_grad() );
            if( name == "Monomial_1_grad") simplefunc = psf( Monomial_1_grad() );
            if( name == "Monomial_2_grad") simplefunc = psf( Monomial_2_grad() );
            if( name == "Monomial_3_grad") simplefunc = psf( Monomial_3_grad() );
            if( name == "Monomial_4_grad") simplefunc = psf( Monomial_4_grad() );
            if( name == "Monomial_5_grad") simplefunc = psf( Monomial_5_grad() );
            if( name == "Monomial_6_grad") simplefunc = psf( Monomial_6_grad() );
            if( name == "Monomial_7_grad") simplefunc = psf( Monomial_7_grad() );
            if( name == "Monomial_8_grad") simplefunc = psf( Monomial_8_grad() );
            if( name == "Monomial_9_grad") simplefunc = psf( Monomial_9_grad() );
            if( name == "Monomial_10_grad") simplefunc = psf( Monomial_10_grad() );
            if( name == "Monomial_11_grad") simplefunc = psf( Monomial_11_grad() );
            if( name == "Monomial_12_grad") simplefunc = psf( Monomial_12_grad() );
            if( name == "Monomial_13_grad") simplefunc = psf( Monomial_13_grad() );
            if( name == "Monomial_14_grad") simplefunc = psf( Monomial_14_grad() );
            if( name == "Monomial_15_grad") simplefunc = psf( Monomial_15_grad() );
            if( name == "Monomial_16_grad") simplefunc = psf( Monomial_16_grad() );
            if( name == "Monomial_17_grad") simplefunc = psf( Monomial_17_grad() );
            if( name == "Monomial_18_grad") simplefunc = psf( Monomial_18_grad() );
            if( name == "Monomial_19_grad") simplefunc = psf( Monomial_19_grad() );
            if( name == "Monomial_20_grad") simplefunc = psf( Monomial_20_grad() );
            if( name == "Monomial_21_grad") simplefunc = psf( Monomial_21_grad() );
            if( name == "Monomial_22_grad") simplefunc = psf( Monomial_22_grad() );
            if( name == "Monomial_23_grad") simplefunc = psf( Monomial_23_grad() );
            if( name == "Monomial_24_grad") simplefunc = psf( Monomial_24_grad() );
            if( name == "Monomial_25_grad") simplefunc = psf( Monomial_25_grad() );
            if( name == "Monomial_26_grad") simplefunc = psf( Monomial_26_grad() );
            if( name == "Monomial_27_grad") simplefunc = psf( Monomial_27_grad() );
            if( name == "Monomial_28_grad") simplefunc = psf( Monomial_28_grad() );
            if( name == "Monomial_29_grad") simplefunc = psf( Monomial_29_grad() );
            if( name == "Monomial_0_hess") simplefunc = psf( Monomial_0_hess() );
            if( name == "Monomial_1_hess") simplefunc = psf( Monomial_1_hess() );
            if( name == "Monomial_2_hess") simplefunc = psf( Monomial_2_hess() );
            if( name == "Monomial_3_hess") simplefunc = psf( Monomial_3_hess() );
            if( name == "Monomial_4_hess") simplefunc = psf( Monomial_4_hess() );
            if( name == "Monomial_5_hess") simplefunc = psf( Monomial_5_hess() );
            if( name == "Monomial_6_hess") simplefunc = psf( Monomial_6_hess() );
            if( name == "Monomial_7_hess") simplefunc = psf( Monomial_7_hess() );
            if( name == "Monomial_8_hess") simplefunc = psf( Monomial_8_hess() );
            if( name == "Monomial_9_hess") simplefunc = psf( Monomial_9_hess() );
            if( name == "Monomial_10_hess") simplefunc = psf( Monomial_10_hess() );
            if( name == "Monomial_11_hess") simplefunc = psf( Monomial_11_hess() );
            if( name == "Monomial_12_hess") simplefunc = psf( Monomial_12_hess() );
            if( name == "Monomial_13_hess") simplefunc = psf( Monomial_13_hess() );
            if( name == "Monomial_14_hess") simplefunc = psf( Monomial_14_hess() );
            if( name == "Monomial_15_hess") simplefunc = psf( Monomial_15_hess() );
            if( name == "Monomial_16_hess") simplefunc = psf( Monomial_16_hess() );
            if( name == "Monomial_17_hess") simplefunc = psf( Monomial_17_hess() );
            if( name == "Monomial_18_hess") simplefunc = psf( Monomial_18_hess() );
            if( name == "Monomial_19_hess") simplefunc = psf( Monomial_19_hess() );
            if( name == "Monomial_20_hess") simplefunc = psf( Monomial_20_hess() );
            if( name == "Monomial_21_hess") simplefunc = psf( Monomial_21_hess() );
            if( name == "Monomial_22_hess") simplefunc = psf( Monomial_22_hess() );
            if( name == "Monomial_23_hess") simplefunc = psf( Monomial_23_hess() );
            if( name == "Monomial_24_hess") simplefunc = psf( Monomial_24_hess() );
            if( name == "Monomial_25_hess") simplefunc = psf( Monomial_25_hess() );
            if( name == "Monomial_26_hess") simplefunc = psf( Monomial_26_hess() );
            if( name == "Monomial_27_hess") simplefunc = psf( Monomial_27_hess() );
            if( name == "Monomial_28_hess") simplefunc = psf( Monomial_28_hess() );
            if( name == "Monomial_29_hess") simplefunc = psf( Monomial_29_hess() );
        }
        void PLibrary::checkout( std::string name, PSimpleFunction< std::vector<double>, double > &simplefunc)
        {
            typedef PSimpleFunction< std::vector<double>, double > psf;
            if( name == "MyFunc_f") simplefunc = psf( MyFunc_f< std::vector<double> >() );
            if( name == "MyFunc_grad_0") simplefunc = psf( MyFunc_grad_0< std::vector<double> >() );
            if( name == "MyFunc_grad_1") simplefunc = psf( MyFunc_grad_1< std::vector<double> >() );
            if( name == "MyFunc_hess_0_0") simplefunc = psf( MyFunc_hess_0_0< std::vector<double> >() );
            if( name == "MyFunc_hess_0_1") simplefunc = psf( MyFunc_hess_0_1< std::vector<double> >() );
            if( name == "MyFunc_hess_1_0") simplefunc = psf( MyFunc_hess_1_0< std::vector<double> >() );
            if( name == "MyFunc_hess_1_1") simplefunc = psf( MyFunc_hess_1_1< std::vector<double> >() );
            if( name == "MyPieceWiseFunc_piece0_f") simplefunc = psf( MyPieceWiseFunc_piece0_f< std::vector<double> >() );
            if( name == "MyPieceWiseFunc_piece0_grad_0") simplefunc = psf( MyPieceWiseFunc_piece0_grad_0< std::vector<double> >() );
            if( name == "MyPieceWiseFunc_piece0_grad_1") simplefunc = psf( MyPieceWiseFunc_piece0_grad_1< std::vector<double> >() );
            if( name == "MyPieceWiseFunc_piece0_hess_0_0") simplefunc = psf( MyPieceWiseFunc_piece0_hess_0_0< std::vector<double> >() );
            if( name == "MyPieceWiseFunc_piece0_hess_0_1") simplefunc = psf( MyPieceWiseFunc_piece0_hess_0_1< std::vector<double> >() );
            if( name == "MyPieceWiseFunc_piece0_hess_1_0") simplefunc = psf( MyPieceWiseFunc_piece0_hess_1_0< std::vector<double> >() );
            if( name == "MyPieceWiseFunc_piece0_hess_1_1") simplefunc = psf( MyPieceWiseFunc_piece0_hess_1_1< std::vector<double> >() );
            if( name == "MyPieceWiseFunc_piece1_f") simplefunc = psf( MyPieceWiseFunc_piece1_f< std::vector<double> >() );
            if( name == "MyPieceWiseFunc_piece1_grad_0") simplefunc = psf( MyPieceWiseFunc_piece1_grad_0< std::vector<double> >() );
            if( name == "MyPieceWiseFunc_piece1_grad_1") simplefunc = psf( MyPieceWiseFunc_piece1_grad_1< std::vector<double> >() );
            if( name == "MyPieceWiseFunc_piece1_hess_0_0") simplefunc = psf( MyPieceWiseFunc_piece1_hess_0_0< std::vector<double> >() );
            if( name == "MyPieceWiseFunc_piece1_hess_0_1") simplefunc = psf( MyPieceWiseFunc_piece1_hess_0_1< std::vector<double> >() );
            if( name == "MyPieceWiseFunc_piece1_hess_1_0") simplefunc = psf( MyPieceWiseFunc_piece1_hess_1_0< std::vector<double> >() );
            if( name == "MyPieceWiseFunc_piece1_hess_1_1") simplefunc = psf( MyPieceWiseFunc_piece1_hess_1_1< std::vector<double> >() );
            if( name == "MyPieceWiseFunc_piece2_f") simplefunc = psf( MyPieceWiseFunc_piece2_f< std::vector<double> >() );
            if( name == "MyPieceWiseFunc_piece2_grad_0") simplefunc = psf( MyPieceWiseFunc_piece2_grad_0< std::vector<double> >() );
            if( name == "MyPieceWiseFunc_piece2_grad_1") simplefunc = psf( MyPieceWiseFunc_piece2_grad_1< std::vector<double> >() );
            if( name == "MyPieceWiseFunc_piece2_hess_0_0") simplefunc = psf( MyPieceWiseFunc_piece2_hess_0_0< std::vector<double> >() );
            if( name == "MyPieceWiseFunc_piece2_hess_0_1") simplefunc = psf( MyPieceWiseFunc_piece2_hess_0_1< std::vector<double> >() );
            if( name == "MyPieceWiseFunc_piece2_hess_1_0") simplefunc = psf( MyPieceWiseFunc_piece2_hess_1_0< std::vector<double> >() );
            if( name == "MyPieceWiseFunc_piece2_hess_1_1") simplefunc = psf( MyPieceWiseFunc_piece2_hess_1_1< std::vector<double> >() );
            if( name == "Quadratic_f") simplefunc = psf( Quadratic_f< std::vector<double> >() );
            if( name == "Quadratic_grad_0") simplefunc = psf( Quadratic_grad_0< std::vector<double> >() );
            if( name == "Quadratic_hess_0_0") simplefunc = psf( Quadratic_hess_0_0< std::vector<double> >() );
        }
        void PLibrary::checkout( std::string name, PSimpleFunction< double*, double > &simplefunc)
        {
            typedef PSimpleFunction< double*, double > psf;
            if( name == "MyFunc_f") simplefunc = psf( MyFunc_f< double* >() );
            if( name == "MyFunc_grad_0") simplefunc = psf( MyFunc_grad_0< double* >() );
            if( name == "MyFunc_grad_1") simplefunc = psf( MyFunc_grad_1< double* >() );
            if( name == "MyFunc_hess_0_0") simplefunc = psf( MyFunc_hess_0_0< double* >() );
            if( name == "MyFunc_hess_0_1") simplefunc = psf( MyFunc_hess_0_1< double* >() );
            if( name == "MyFunc_hess_1_0") simplefunc = psf( MyFunc_hess_1_0< double* >() );
            if( name == "MyFunc_hess_1_1") simplefunc = psf( MyFunc_hess_1_1< double* >() );
            if( name == "MyPieceWiseFunc_piece0_f") simplefunc = psf( MyPieceWiseFunc_piece0_f< double* >() );
            if( name == "MyPieceWiseFunc_piece0_grad_0") simplefunc = psf( MyPieceWiseFunc_piece0_grad_0< double* >() );
            if( name == "MyPieceWiseFunc_piece0_grad_1") simplefunc = psf( MyPieceWiseFunc_piece0_grad_1< double* >() );
            if( name == "MyPieceWiseFunc_piece0_hess_0_0") simplefunc = psf( MyPieceWiseFunc_piece0_hess_0_0< double* >() );
            if( name == "MyPieceWiseFunc_piece0_hess_0_1") simplefunc = psf( MyPieceWiseFunc_piece0_hess_0_1< double* >() );
            if( name == "MyPieceWiseFunc_piece0_hess_1_0") simplefunc = psf( MyPieceWiseFunc_piece0_hess_1_0< double* >() );
            if( name == "MyPieceWiseFunc_piece0_hess_1_1") simplefunc = psf( MyPieceWiseFunc_piece0_hess_1_1< double* >() );
            if( name == "MyPieceWiseFunc_piece1_f") simplefunc = psf( MyPieceWiseFunc_piece1_f< double* >() );
            if( name == "MyPieceWiseFunc_piece1_grad_0") simplefunc = psf( MyPieceWiseFunc_piece1_grad_0< double* >() );
            if( name == "MyPieceWiseFunc_piece1_grad_1") simplefunc = psf( MyPieceWiseFunc_piece1_grad_1< double* >() );
            if( name == "MyPieceWiseFunc_piece1_hess_0_0") simplefunc = psf( MyPieceWiseFunc_piece1_hess_0_0< double* >() );
            if( name == "MyPieceWiseFunc_piece1_hess_0_1") simplefunc = psf( MyPieceWiseFunc_piece1_hess_0_1< double* >() );
            if( name == "MyPieceWiseFunc_piece1_hess_1_0") simplefunc = psf( MyPieceWiseFunc_piece1_hess_1_0< double* >() );
            if( name == "MyPieceWiseFunc_piece1_hess_1_1") simplefunc = psf( MyPieceWiseFunc_piece1_hess_1_1< double* >() );
            if( name == "MyPieceWiseFunc_piece2_f") simplefunc = psf( MyPieceWiseFunc_piece2_f< double* >() );
            if( name == "MyPieceWiseFunc_piece2_grad_0") simplefunc = psf( MyPieceWiseFunc_piece2_grad_0< double* >() );
            if( name == "MyPieceWiseFunc_piece2_grad_1") simplefunc = psf( MyPieceWiseFunc_piece2_grad_1< double* >() );
            if( name == "MyPieceWiseFunc_piece2_hess_0_0") simplefunc = psf( MyPieceWiseFunc_piece2_hess_0_0< double* >() );
            if( name == "MyPieceWiseFunc_piece2_hess_0_1") simplefunc = psf( MyPieceWiseFunc_piece2_hess_0_1< double* >() );
            if( name == "MyPieceWiseFunc_piece2_hess_1_0") simplefunc = psf( MyPieceWiseFunc_piece2_hess_1_0< double* >() );
            if( name == "MyPieceWiseFunc_piece2_hess_1_1") simplefunc = psf( MyPieceWiseFunc_piece2_hess_1_1< double* >() );
            if( name == "Quadratic_f") simplefunc = psf( Quadratic_f< double* >() );
            if( name == "Quadratic_grad_0") simplefunc = psf( Quadratic_grad_0< double* >() );
            if( name == "Quadratic_hess_0_0") simplefunc = psf( Quadratic_hess_0_0< double* >() );
        }
        void PLibrary::checkout( std::string name, PSimpleFunction< std::vector<double>, bool > &simplefunc)
        {
            typedef PSimpleFunction< std::vector<double>, bool > psf;
            if( name == "MyPieceWiseFunc_piece0_cond0") simplefunc = psf( MyPieceWiseFunc_piece0_cond0< std::vector<double> >() );
            if( name == "MyPieceWiseFunc_piece1_cond0") simplefunc = psf( MyPieceWiseFunc_piece1_cond0< std::vector<double> >() );
            if( name == "MyPieceWiseFunc_piece1_cond1") simplefunc = psf( MyPieceWiseFunc_piece1_cond1< std::vector<double> >() );
            if( name == "MyPieceWiseFunc_piece2_cond0") simplefunc = psf( MyPieceWiseFunc_piece2_cond0< std::vector<double> >() );
            if( name == "MyPieceWiseFunc_piece2_cond1") simplefunc = psf( MyPieceWiseFunc_piece2_cond1< std::vector<double> >() );
        }
        void PLibrary::checkout( std::string name, PSimpleFunction< double*, bool > &simplefunc)
        {
            typedef PSimpleFunction< double*, bool > psf;
            if( name == "MyPieceWiseFunc_piece0_cond0") simplefunc = psf( MyPieceWiseFunc_piece0_cond0< double* >() );
            if( name == "MyPieceWiseFunc_piece1_cond0") simplefunc = psf( MyPieceWiseFunc_piece1_cond0< double* >() );
            if( name == "MyPieceWiseFunc_piece1_cond1") simplefunc = psf( MyPieceWiseFunc_piece1_cond1< double* >() );
            if( name == "MyPieceWiseFunc_piece2_cond0") simplefunc = psf( MyPieceWiseFunc_piece2_cond0< double* >() );
            if( name == "MyPieceWiseFunc_piece2_cond1") simplefunc = psf( MyPieceWiseFunc_piece2_cond1< double* >() );
        }

        void PLibrary::checkout( std::string name, PFunction< std::vector<double>, double > &func)
        {
            typedef PFunction< std::vector<double>, double > pf;
            if( name == "MyFunc") func = pf( MyFunc< std::vector<double> >() );
            if( name == "MyPieceWiseFunc_piece0") func = pf( MyPieceWiseFunc_piece0< std::vector<double> >() );
            if( name == "MyPieceWiseFunc_piece1") func = pf( MyPieceWiseFunc_piece1< std::vector<double> >() );
            if( name == "MyPieceWiseFunc_piece2") func = pf( MyPieceWiseFunc_piece2< std::vector<double> >() );
            if( name == "MyPieceWiseFunc") func = pf( MyPieceWiseFunc< std::vector<double> >() );
            if( name == "Quadratic") func = pf( Quadratic< std::vector<double> >() );
        }
        void PLibrary::checkout( std::string name, PFunction< double*, double > &func)
        {
            typedef PFunction< double*, double > pf;
            if( name == "MyFunc") func = pf( MyFunc< double* >() );
            if( name == "MyPieceWiseFunc_piece0") func = pf( MyPieceWiseFunc_piece0< double* >() );
            if( name == "MyPieceWiseFunc_piece1") func = pf( MyPieceWiseFunc_piece1< double* >() );
            if( name == "MyPieceWiseFunc_piece2") func = pf( MyPieceWiseFunc_piece2< double* >() );
            if( name == "MyPieceWiseFunc") func = pf( MyPieceWiseFunc< double* >() );
            if( name == "Quadratic") func = pf( Quadratic< double* >() );
        }

        void PLibrary::checkout( std::string name, PBasisSet< double, double > &basis_set, int N)
        {
            typedef PBasisSet< double, double > pbs;
            if( name == "Chebyshev") basis_set = pbs( Chebyshev(N) );
            if( name == "Monomial") basis_set = pbs( Monomial(N) );
        }



        void PLibrary::checkout( std::string name, PSimpleBase< double, double > *&simplefunc)
        {
            if( name == "Chebyshev_0") simplefunc = new Chebyshev_0();
            if( name == "Chebyshev_1") simplefunc = new Chebyshev_1();
            if( name == "Chebyshev_2") simplefunc = new Chebyshev_2();
            if( name == "Chebyshev_3") simplefunc = new Chebyshev_3();
            if( name == "Chebyshev_4") simplefunc = new Chebyshev_4();
            if( name == "Chebyshev_5") simplefunc = new Chebyshev_5();
            if( name == "Chebyshev_6") simplefunc = new Chebyshev_6();
            if( name == "Chebyshev_7") simplefunc = new Chebyshev_7();
            if( name == "Chebyshev_8") simplefunc = new Chebyshev_8();
            if( name == "Chebyshev_9") simplefunc = new Chebyshev_9();
            if( name == "Chebyshev_10") simplefunc = new Chebyshev_10();
            if( name == "Chebyshev_11") simplefunc = new Chebyshev_11();
            if( name == "Chebyshev_12") simplefunc = new Chebyshev_12();
            if( name == "Chebyshev_13") simplefunc = new Chebyshev_13();
            if( name == "Chebyshev_14") simplefunc = new Chebyshev_14();
            if( name == "Chebyshev_15") simplefunc = new Chebyshev_15();
            if( name == "Chebyshev_16") simplefunc = new Chebyshev_16();
            if( name == "Chebyshev_17") simplefunc = new Chebyshev_17();
            if( name == "Chebyshev_18") simplefunc = new Chebyshev_18();
            if( name == "Chebyshev_19") simplefunc = new Chebyshev_19();
            if( name == "Chebyshev_20") simplefunc = new Chebyshev_20();
            if( name == "Chebyshev_21") simplefunc = new Chebyshev_21();
            if( name == "Chebyshev_22") simplefunc = new Chebyshev_22();
            if( name == "Chebyshev_23") simplefunc = new Chebyshev_23();
            if( name == "Chebyshev_24") simplefunc = new Chebyshev_24();
            if( name == "Chebyshev_25") simplefunc = new Chebyshev_25();
            if( name == "Chebyshev_26") simplefunc = new Chebyshev_26();
            if( name == "Chebyshev_27") simplefunc = new Chebyshev_27();
            if( name == "Chebyshev_28") simplefunc = new Chebyshev_28();
            if( name == "Chebyshev_29") simplefunc = new Chebyshev_29();
            if( name == "Chebyshev_0_grad") simplefunc = new Chebyshev_0_grad();
            if( name == "Chebyshev_1_grad") simplefunc = new Chebyshev_1_grad();
            if( name == "Chebyshev_2_grad") simplefunc = new Chebyshev_2_grad();
            if( name == "Chebyshev_3_grad") simplefunc = new Chebyshev_3_grad();
            if( name == "Chebyshev_4_grad") simplefunc = new Chebyshev_4_grad();
            if( name == "Chebyshev_5_grad") simplefunc = new Chebyshev_5_grad();
            if( name == "Chebyshev_6_grad") simplefunc = new Chebyshev_6_grad();
            if( name == "Chebyshev_7_grad") simplefunc = new Chebyshev_7_grad();
            if( name == "Chebyshev_8_grad") simplefunc = new Chebyshev_8_grad();
            if( name == "Chebyshev_9_grad") simplefunc = new Chebyshev_9_grad();
            if( name == "Chebyshev_10_grad") simplefunc = new Chebyshev_10_grad();
            if( name == "Chebyshev_11_grad") simplefunc = new Chebyshev_11_grad();
            if( name == "Chebyshev_12_grad") simplefunc = new Chebyshev_12_grad();
            if( name == "Chebyshev_13_grad") simplefunc = new Chebyshev_13_grad();
            if( name == "Chebyshev_14_grad") simplefunc = new Chebyshev_14_grad();
            if( name == "Chebyshev_15_grad") simplefunc = new Chebyshev_15_grad();
            if( name == "Chebyshev_16_grad") simplefunc = new Chebyshev_16_grad();
            if( name == "Chebyshev_17_grad") simplefunc = new Chebyshev_17_grad();
            if( name == "Chebyshev_18_grad") simplefunc = new Chebyshev_18_grad();
            if( name == "Chebyshev_19_grad") simplefunc = new Chebyshev_19_grad();
            if( name == "Chebyshev_20_grad") simplefunc = new Chebyshev_20_grad();
            if( name == "Chebyshev_21_grad") simplefunc = new Chebyshev_21_grad();
            if( name == "Chebyshev_22_grad") simplefunc = new Chebyshev_22_grad();
            if( name == "Chebyshev_23_grad") simplefunc = new Chebyshev_23_grad();
            if( name == "Chebyshev_24_grad") simplefunc = new Chebyshev_24_grad();
            if( name == "Chebyshev_25_grad") simplefunc = new Chebyshev_25_grad();
            if( name == "Chebyshev_26_grad") simplefunc = new Chebyshev_26_grad();
            if( name == "Chebyshev_27_grad") simplefunc = new Chebyshev_27_grad();
            if( name == "Chebyshev_28_grad") simplefunc = new Chebyshev_28_grad();
            if( name == "Chebyshev_29_grad") simplefunc = new Chebyshev_29_grad();
            if( name == "Chebyshev_0_hess") simplefunc = new Chebyshev_0_hess();
            if( name == "Chebyshev_1_hess") simplefunc = new Chebyshev_1_hess();
            if( name == "Chebyshev_2_hess") simplefunc = new Chebyshev_2_hess();
            if( name == "Chebyshev_3_hess") simplefunc = new Chebyshev_3_hess();
            if( name == "Chebyshev_4_hess") simplefunc = new Chebyshev_4_hess();
            if( name == "Chebyshev_5_hess") simplefunc = new Chebyshev_5_hess();
            if( name == "Chebyshev_6_hess") simplefunc = new Chebyshev_6_hess();
            if( name == "Chebyshev_7_hess") simplefunc = new Chebyshev_7_hess();
            if( name == "Chebyshev_8_hess") simplefunc = new Chebyshev_8_hess();
            if( name == "Chebyshev_9_hess") simplefunc = new Chebyshev_9_hess();
            if( name == "Chebyshev_10_hess") simplefunc = new Chebyshev_10_hess();
            if( name == "Chebyshev_11_hess") simplefunc = new Chebyshev_11_hess();
            if( name == "Chebyshev_12_hess") simplefunc = new Chebyshev_12_hess();
            if( name == "Chebyshev_13_hess") simplefunc = new Chebyshev_13_hess();
            if( name == "Chebyshev_14_hess") simplefunc = new Chebyshev_14_hess();
            if( name == "Chebyshev_15_hess") simplefunc = new Chebyshev_15_hess();
            if( name == "Chebyshev_16_hess") simplefunc = new Chebyshev_16_hess();
            if( name == "Chebyshev_17_hess") simplefunc = new Chebyshev_17_hess();
            if( name == "Chebyshev_18_hess") simplefunc = new Chebyshev_18_hess();
            if( name == "Chebyshev_19_hess") simplefunc = new Chebyshev_19_hess();
            if( name == "Chebyshev_20_hess") simplefunc = new Chebyshev_20_hess();
            if( name == "Chebyshev_21_hess") simplefunc = new Chebyshev_21_hess();
            if( name == "Chebyshev_22_hess") simplefunc = new Chebyshev_22_hess();
            if( name == "Chebyshev_23_hess") simplefunc = new Chebyshev_23_hess();
            if( name == "Chebyshev_24_hess") simplefunc = new Chebyshev_24_hess();
            if( name == "Chebyshev_25_hess") simplefunc = new Chebyshev_25_hess();
            if( name == "Chebyshev_26_hess") simplefunc = new Chebyshev_26_hess();
            if( name == "Chebyshev_27_hess") simplefunc = new Chebyshev_27_hess();
            if( name == "Chebyshev_28_hess") simplefunc = new Chebyshev_28_hess();
            if( name == "Chebyshev_29_hess") simplefunc = new Chebyshev_29_hess();
            if( name == "Monomial_0") simplefunc = new Monomial_0();
            if( name == "Monomial_1") simplefunc = new Monomial_1();
            if( name == "Monomial_2") simplefunc = new Monomial_2();
            if( name == "Monomial_3") simplefunc = new Monomial_3();
            if( name == "Monomial_4") simplefunc = new Monomial_4();
            if( name == "Monomial_5") simplefunc = new Monomial_5();
            if( name == "Monomial_6") simplefunc = new Monomial_6();
            if( name == "Monomial_7") simplefunc = new Monomial_7();
            if( name == "Monomial_8") simplefunc = new Monomial_8();
            if( name == "Monomial_9") simplefunc = new Monomial_9();
            if( name == "Monomial_10") simplefunc = new Monomial_10();
            if( name == "Monomial_11") simplefunc = new Monomial_11();
            if( name == "Monomial_12") simplefunc = new Monomial_12();
            if( name == "Monomial_13") simplefunc = new Monomial_13();
            if( name == "Monomial_14") simplefunc = new Monomial_14();
            if( name == "Monomial_15") simplefunc = new Monomial_15();
            if( name == "Monomial_16") simplefunc = new Monomial_16();
            if( name == "Monomial_17") simplefunc = new Monomial_17();
            if( name == "Monomial_18") simplefunc = new Monomial_18();
            if( name == "Monomial_19") simplefunc = new Monomial_19();
            if( name == "Monomial_20") simplefunc = new Monomial_20();
            if( name == "Monomial_21") simplefunc = new Monomial_21();
            if( name == "Monomial_22") simplefunc = new Monomial_22();
            if( name == "Monomial_23") simplefunc = new Monomial_23();
            if( name == "Monomial_24") simplefunc = new Monomial_24();
            if( name == "Monomial_25") simplefunc = new Monomial_25();
            if( name == "Monomial_26") simplefunc = new Monomial_26();
            if( name == "Monomial_27") simplefunc = new Monomial_27();
            if( name == "Monomial_28") simplefunc = new Monomial_28();
            if( name == "Monomial_29") simplefunc = new Monomial_29();
            if( name == "Monomial_0_grad") simplefunc = new Monomial_0_grad();
            if( name == "Monomial_1_grad") simplefunc = new Monomial_1_grad();
            if( name == "Monomial_2_grad") simplefunc = new Monomial_2_grad();
            if( name == "Monomial_3_grad") simplefunc = new Monomial_3_grad();
            if( name == "Monomial_4_grad") simplefunc = new Monomial_4_grad();
            if( name == "Monomial_5_grad") simplefunc = new Monomial_5_grad();
            if( name == "Monomial_6_grad") simplefunc = new Monomial_6_grad();
            if( name == "Monomial_7_grad") simplefunc = new Monomial_7_grad();
            if( name == "Monomial_8_grad") simplefunc = new Monomial_8_grad();
            if( name == "Monomial_9_grad") simplefunc = new Monomial_9_grad();
            if( name == "Monomial_10_grad") simplefunc = new Monomial_10_grad();
            if( name == "Monomial_11_grad") simplefunc = new Monomial_11_grad();
            if( name == "Monomial_12_grad") simplefunc = new Monomial_12_grad();
            if( name == "Monomial_13_grad") simplefunc = new Monomial_13_grad();
            if( name == "Monomial_14_grad") simplefunc = new Monomial_14_grad();
            if( name == "Monomial_15_grad") simplefunc = new Monomial_15_grad();
            if( name == "Monomial_16_grad") simplefunc = new Monomial_16_grad();
            if( name == "Monomial_17_grad") simplefunc = new Monomial_17_grad();
            if( name == "Monomial_18_grad") simplefunc = new Monomial_18_grad();
            if( name == "Monomial_19_grad") simplefunc = new Monomial_19_grad();
            if( name == "Monomial_20_grad") simplefunc = new Monomial_20_grad();
            if( name == "Monomial_21_grad") simplefunc = new Monomial_21_grad();
            if( name == "Monomial_22_grad") simplefunc = new Monomial_22_grad();
            if( name == "Monomial_23_grad") simplefunc = new Monomial_23_grad();
            if( name == "Monomial_24_grad") simplefunc = new Monomial_24_grad();
            if( name == "Monomial_25_grad") simplefunc = new Monomial_25_grad();
            if( name == "Monomial_26_grad") simplefunc = new Monomial_26_grad();
            if( name == "Monomial_27_grad") simplefunc = new Monomial_27_grad();
            if( name == "Monomial_28_grad") simplefunc = new Monomial_28_grad();
            if( name == "Monomial_29_grad") simplefunc = new Monomial_29_grad();
            if( name == "Monomial_0_hess") simplefunc = new Monomial_0_hess();
            if( name == "Monomial_1_hess") simplefunc = new Monomial_1_hess();
            if( name == "Monomial_2_hess") simplefunc = new Monomial_2_hess();
            if( name == "Monomial_3_hess") simplefunc = new Monomial_3_hess();
            if( name == "Monomial_4_hess") simplefunc = new Monomial_4_hess();
            if( name == "Monomial_5_hess") simplefunc = new Monomial_5_hess();
            if( name == "Monomial_6_hess") simplefunc = new Monomial_6_hess();
            if( name == "Monomial_7_hess") simplefunc = new Monomial_7_hess();
            if( name == "Monomial_8_hess") simplefunc = new Monomial_8_hess();
            if( name == "Monomial_9_hess") simplefunc = new Monomial_9_hess();
            if( name == "Monomial_10_hess") simplefunc = new Monomial_10_hess();
            if( name == "Monomial_11_hess") simplefunc = new Monomial_11_hess();
            if( name == "Monomial_12_hess") simplefunc = new Monomial_12_hess();
            if( name == "Monomial_13_hess") simplefunc = new Monomial_13_hess();
            if( name == "Monomial_14_hess") simplefunc = new Monomial_14_hess();
            if( name == "Monomial_15_hess") simplefunc = new Monomial_15_hess();
            if( name == "Monomial_16_hess") simplefunc = new Monomial_16_hess();
            if( name == "Monomial_17_hess") simplefunc = new Monomial_17_hess();
            if( name == "Monomial_18_hess") simplefunc = new Monomial_18_hess();
            if( name == "Monomial_19_hess") simplefunc = new Monomial_19_hess();
            if( name == "Monomial_20_hess") simplefunc = new Monomial_20_hess();
            if( name == "Monomial_21_hess") simplefunc = new Monomial_21_hess();
            if( name == "Monomial_22_hess") simplefunc = new Monomial_22_hess();
            if( name == "Monomial_23_hess") simplefunc = new Monomial_23_hess();
            if( name == "Monomial_24_hess") simplefunc = new Monomial_24_hess();
            if( name == "Monomial_25_hess") simplefunc = new Monomial_25_hess();
            if( name == "Monomial_26_hess") simplefunc = new Monomial_26_hess();
            if( name == "Monomial_27_hess") simplefunc = new Monomial_27_hess();
            if( name == "Monomial_28_hess") simplefunc = new Monomial_28_hess();
            if( name == "Monomial_29_hess") simplefunc = new Monomial_29_hess();
        }
        void PLibrary::checkout( std::string name, PSimpleBase< std::vector<double>, double > *&simplefunc)
        {
            if( name == "MyFunc_f") simplefunc = new MyFunc_f< std::vector<double> >();
            if( name == "MyFunc_grad_0") simplefunc = new MyFunc_grad_0< std::vector<double> >();
            if( name == "MyFunc_grad_1") simplefunc = new MyFunc_grad_1< std::vector<double> >();
            if( name == "MyFunc_hess_0_0") simplefunc = new MyFunc_hess_0_0< std::vector<double> >();
            if( name == "MyFunc_hess_0_1") simplefunc = new MyFunc_hess_0_1< std::vector<double> >();
            if( name == "MyFunc_hess_1_0") simplefunc = new MyFunc_hess_1_0< std::vector<double> >();
            if( name == "MyFunc_hess_1_1") simplefunc = new MyFunc_hess_1_1< std::vector<double> >();
            if( name == "MyPieceWiseFunc_piece0_f") simplefunc = new MyPieceWiseFunc_piece0_f< std::vector<double> >();
            if( name == "MyPieceWiseFunc_piece0_grad_0") simplefunc = new MyPieceWiseFunc_piece0_grad_0< std::vector<double> >();
            if( name == "MyPieceWiseFunc_piece0_grad_1") simplefunc = new MyPieceWiseFunc_piece0_grad_1< std::vector<double> >();
            if( name == "MyPieceWiseFunc_piece0_hess_0_0") simplefunc = new MyPieceWiseFunc_piece0_hess_0_0< std::vector<double> >();
            if( name == "MyPieceWiseFunc_piece0_hess_0_1") simplefunc = new MyPieceWiseFunc_piece0_hess_0_1< std::vector<double> >();
            if( name == "MyPieceWiseFunc_piece0_hess_1_0") simplefunc = new MyPieceWiseFunc_piece0_hess_1_0< std::vector<double> >();
            if( name == "MyPieceWiseFunc_piece0_hess_1_1") simplefunc = new MyPieceWiseFunc_piece0_hess_1_1< std::vector<double> >();
            if( name == "MyPieceWiseFunc_piece1_f") simplefunc = new MyPieceWiseFunc_piece1_f< std::vector<double> >();
            if( name == "MyPieceWiseFunc_piece1_grad_0") simplefunc = new MyPieceWiseFunc_piece1_grad_0< std::vector<double> >();
            if( name == "MyPieceWiseFunc_piece1_grad_1") simplefunc = new MyPieceWiseFunc_piece1_grad_1< std::vector<double> >();
            if( name == "MyPieceWiseFunc_piece1_hess_0_0") simplefunc = new MyPieceWiseFunc_piece1_hess_0_0< std::vector<double> >();
            if( name == "MyPieceWiseFunc_piece1_hess_0_1") simplefunc = new MyPieceWiseFunc_piece1_hess_0_1< std::vector<double> >();
            if( name == "MyPieceWiseFunc_piece1_hess_1_0") simplefunc = new MyPieceWiseFunc_piece1_hess_1_0< std::vector<double> >();
            if( name == "MyPieceWiseFunc_piece1_hess_1_1") simplefunc = new MyPieceWiseFunc_piece1_hess_1_1< std::vector<double> >();
            if( name == "MyPieceWiseFunc_piece2_f") simplefunc = new MyPieceWiseFunc_piece2_f< std::vector<double> >();
            if( name == "MyPieceWiseFunc_piece2_grad_0") simplefunc = new MyPieceWiseFunc_piece2_grad_0< std::vector<double> >();
            if( name == "MyPieceWiseFunc_piece2_grad_1") simplefunc = new MyPieceWiseFunc_piece2_grad_1< std::vector<double> >();
            if( name == "MyPieceWiseFunc_piece2_hess_0_0") simplefunc = new MyPieceWiseFunc_piece2_hess_0_0< std::vector<double> >();
            if( name == "MyPieceWiseFunc_piece2_hess_0_1") simplefunc = new MyPieceWiseFunc_piece2_hess_0_1< std::vector<double> >();
            if( name == "MyPieceWiseFunc_piece2_hess_1_0") simplefunc = new MyPieceWiseFunc_piece2_hess_1_0< std::vector<double> >();
            if( name == "MyPieceWiseFunc_piece2_hess_1_1") simplefunc = new MyPieceWiseFunc_piece2_hess_1_1< std::vector<double> >();
            if( name == "Quadratic_f") simplefunc = new Quadratic_f< std::vector<double> >();
            if( name == "Quadratic_grad_0") simplefunc = new Quadratic_grad_0< std::vector<double> >();
            if( name == "Quadratic_hess_0_0") simplefunc = new Quadratic_hess_0_0< std::vector<double> >();
        }
        void PLibrary::checkout( std::string name, PSimpleBase< double*, double > *&simplefunc)
        {
            if( name == "MyFunc_f") simplefunc = new MyFunc_f< double* >();
            if( name == "MyFunc_grad_0") simplefunc = new MyFunc_grad_0< double* >();
            if( name == "MyFunc_grad_1") simplefunc = new MyFunc_grad_1< double* >();
            if( name == "MyFunc_hess_0_0") simplefunc = new MyFunc_hess_0_0< double* >();
            if( name == "MyFunc_hess_0_1") simplefunc = new MyFunc_hess_0_1< double* >();
            if( name == "MyFunc_hess_1_0") simplefunc = new MyFunc_hess_1_0< double* >();
            if( name == "MyFunc_hess_1_1") simplefunc = new MyFunc_hess_1_1< double* >();
            if( name == "MyPieceWiseFunc_piece0_f") simplefunc = new MyPieceWiseFunc_piece0_f< double* >();
            if( name == "MyPieceWiseFunc_piece0_grad_0") simplefunc = new MyPieceWiseFunc_piece0_grad_0< double* >();
            if( name == "MyPieceWiseFunc_piece0_grad_1") simplefunc = new MyPieceWiseFunc_piece0_grad_1< double* >();
            if( name == "MyPieceWiseFunc_piece0_hess_0_0") simplefunc = new MyPieceWiseFunc_piece0_hess_0_0< double* >();
            if( name == "MyPieceWiseFunc_piece0_hess_0_1") simplefunc = new MyPieceWiseFunc_piece0_hess_0_1< double* >();
            if( name == "MyPieceWiseFunc_piece0_hess_1_0") simplefunc = new MyPieceWiseFunc_piece0_hess_1_0< double* >();
            if( name == "MyPieceWiseFunc_piece0_hess_1_1") simplefunc = new MyPieceWiseFunc_piece0_hess_1_1< double* >();
            if( name == "MyPieceWiseFunc_piece1_f") simplefunc = new MyPieceWiseFunc_piece1_f< double* >();
            if( name == "MyPieceWiseFunc_piece1_grad_0") simplefunc = new MyPieceWiseFunc_piece1_grad_0< double* >();
            if( name == "MyPieceWiseFunc_piece1_grad_1") simplefunc = new MyPieceWiseFunc_piece1_grad_1< double* >();
            if( name == "MyPieceWiseFunc_piece1_hess_0_0") simplefunc = new MyPieceWiseFunc_piece1_hess_0_0< double* >();
            if( name == "MyPieceWiseFunc_piece1_hess_0_1") simplefunc = new MyPieceWiseFunc_piece1_hess_0_1< double* >();
            if( name == "MyPieceWiseFunc_piece1_hess_1_0") simplefunc = new MyPieceWiseFunc_piece1_hess_1_0< double* >();
            if( name == "MyPieceWiseFunc_piece1_hess_1_1") simplefunc = new MyPieceWiseFunc_piece1_hess_1_1< double* >();
            if( name == "MyPieceWiseFunc_piece2_f") simplefunc = new MyPieceWiseFunc_piece2_f< double* >();
            if( name == "MyPieceWiseFunc_piece2_grad_0") simplefunc = new MyPieceWiseFunc_piece2_grad_0< double* >();
            if( name == "MyPieceWiseFunc_piece2_grad_1") simplefunc = new MyPieceWiseFunc_piece2_grad_1< double* >();
            if( name == "MyPieceWiseFunc_piece2_hess_0_0") simplefunc = new MyPieceWiseFunc_piece2_hess_0_0< double* >();
            if( name == "MyPieceWiseFunc_piece2_hess_0_1") simplefunc = new MyPieceWiseFunc_piece2_hess_0_1< double* >();
            if( name == "MyPieceWiseFunc_piece2_hess_1_0") simplefunc = new MyPieceWiseFunc_piece2_hess_1_0< double* >();
            if( name == "MyPieceWiseFunc_piece2_hess_1_1") simplefunc = new MyPieceWiseFunc_piece2_hess_1_1< double* >();
            if( name == "Quadratic_f") simplefunc = new Quadratic_f< double* >();
            if( name == "Quadratic_grad_0") simplefunc = new Quadratic_grad_0< double* >();
            if( name == "Quadratic_hess_0_0") simplefunc = new Quadratic_hess_0_0< double* >();
        }
        void PLibrary::checkout( std::string name, PSimpleBase< std::vector<double>, bool > *&simplefunc)
        {
            if( name == "MyPieceWiseFunc_piece0_cond0") simplefunc = new MyPieceWiseFunc_piece0_cond0< std::vector<double> >();
            if( name == "MyPieceWiseFunc_piece1_cond0") simplefunc = new MyPieceWiseFunc_piece1_cond0< std::vector<double> >();
            if( name == "MyPieceWiseFunc_piece1_cond1") simplefunc = new MyPieceWiseFunc_piece1_cond1< std::vector<double> >();
            if( name == "MyPieceWiseFunc_piece2_cond0") simplefunc = new MyPieceWiseFunc_piece2_cond0< std::vector<double> >();
            if( name == "MyPieceWiseFunc_piece2_cond1") simplefunc = new MyPieceWiseFunc_piece2_cond1< std::vector<double> >();
        }
        void PLibrary::checkout( std::string name, PSimpleBase< double*, bool > *&simplefunc)
        {
            if( name == "MyPieceWiseFunc_piece0_cond0") simplefunc = new MyPieceWiseFunc_piece0_cond0< double* >();
            if( name == "MyPieceWiseFunc_piece1_cond0") simplefunc = new MyPieceWiseFunc_piece1_cond0< double* >();
            if( name == "MyPieceWiseFunc_piece1_cond1") simplefunc = new MyPieceWiseFunc_piece1_cond1< double* >();
            if( name == "MyPieceWiseFunc_piece2_cond0") simplefunc = new MyPieceWiseFunc_piece2_cond0< double* >();
            if( name == "MyPieceWiseFunc_piece2_cond1") simplefunc = new MyPieceWiseFunc_piece2_cond1< double* >();
        }

        void PLibrary::checkout( std::string name, PFuncBase< std::vector<double>, double > *&func)
        {
            if( name == "MyFunc") func = new MyFunc< std::vector<double> >();
            if( name == "MyPieceWiseFunc_piece0") func = new MyPieceWiseFunc_piece0< std::vector<double> >();
            if( name == "MyPieceWiseFunc_piece1") func = new MyPieceWiseFunc_piece1< std::vector<double> >();
            if( name == "MyPieceWiseFunc_piece2") func = new MyPieceWiseFunc_piece2< std::vector<double> >();
            if( name == "MyPieceWiseFunc") func = new MyPieceWiseFunc< std::vector<double> >();
            if( name == "Quadratic") func = new Quadratic< std::vector<double> >();
        }
        void PLibrary::checkout( std::string name, PFuncBase< double*, double > *&func)
        {
            if( name == "MyFunc") func = new MyFunc< double* >();
            if( name == "MyPieceWiseFunc_piece0") func = new MyPieceWiseFunc_piece0< double* >();
            if( name == "MyPieceWiseFunc_piece1") func = new MyPieceWiseFunc_piece1< double* >();
            if( name == "MyPieceWiseFunc_piece2") func = new MyPieceWiseFunc_piece2< double* >();
            if( name == "MyPieceWiseFunc") func = new MyPieceWiseFunc< double* >();
            if( name == "Quadratic") func = new Quadratic< double* >();
        }


        void PLibrary::checkout( std::string name, PPieceWiseFuncBase< std::vector<double>, double > *&func)
        {
            if( name == "MyPieceWiseFunc") func = new MyPieceWiseFunc< std::vector<double> >();
        }
        void PLibrary::checkout( std::string name, PPieceWiseFuncBase< double*, double > *&func)
        {
            if( name == "MyPieceWiseFunc") func = new MyPieceWiseFunc< double* >();
        }

        void PLibrary::checkout( std::string name, PBasisSetBase< double, double > *&basis_set, int N)
        {
            if( name == "Chebyshev") basis_set = new Chebyshev(N);
            if( name == "Monomial") basis_set = new Monomial(N);
        }

}


#endif
