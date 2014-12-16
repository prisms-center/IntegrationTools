#ifndef Chebyshev_HH
#define Chebyshev_HH

#include <cmath>
#include <cstdlib>
#include "IntegrationTools/PFunction.hh"

namespace PRISMS
{
    class Chebyshev_0 : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return 1.0000000000000000e+00;
        }

    public:
        std::string csrc() const
        {
            return "1.0000000000000000e+00";
        }

        std::string sym() const
        {
            return "1.0";
        }

        std::string latex() const
        {
            return "1.0";
        }

        Chebyshev_0* clone() const
        {
            return new Chebyshev_0(*this);
        }
    };

    class Chebyshev_1 : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return var;
        }

    public:
        std::string csrc() const
        {
            return "var";
        }

        std::string sym() const
        {
            return "x";
        }

        std::string latex() const
        {
            return "x";
        }

        Chebyshev_1* clone() const
        {
            return new Chebyshev_1(*this);
        }
    };

    class Chebyshev_2 : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return  2.0*(var*var)-1.0000000000000000e+00;
        }

    public:
        std::string csrc() const
        {
            return " 2.0*(var*var)-1.0000000000000000e+00";
        }

        std::string sym() const
        {
            return "-1.0+2*x^2";
        }

        std::string latex() const
        {
            return "-1.0+2 x^{2}";
        }

        Chebyshev_2* clone() const
        {
            return new Chebyshev_2(*this);
        }
    };

    class Chebyshev_3 : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return  -3.0000000000000000e+00*var+4.0*(var*var*var);
        }

    public:
        std::string csrc() const
        {
            return " -3.0000000000000000e+00*var+4.0*(var*var*var)";
        }

        std::string sym() const
        {
            return "4*x^3-(3.0)*x";
        }

        std::string latex() const
        {
            return "4 x^{3}-{(3.0)} x";
        }

        Chebyshev_3* clone() const
        {
            return new Chebyshev_3(*this);
        }
    };

    class Chebyshev_4 : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return  8.0*((var*var)*(var*var))+-8.0000000000000000e+00*(var*var)+1.0000000000000000e+00;
        }

    public:
        std::string csrc() const
        {
            return " 8.0*((var*var)*(var*var))+-8.0000000000000000e+00*(var*var)+1.0000000000000000e+00";
        }

        std::string sym() const
        {
            return "1.0-(8.0)*x^2+8*x^4";
        }

        std::string latex() const
        {
            return "1.0-{(8.0)} x^{2}+8 x^{4}";
        }

        Chebyshev_4* clone() const
        {
            return new Chebyshev_4(*this);
        }
    };

    class Chebyshev_5 : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return  5.0000000000000000e+00*var+16.0*(var*(var*var)*(var*var))+-2.0000000000000000e+01*(var*var*var);
        }

    public:
        std::string csrc() const
        {
            return " 5.0000000000000000e+00*var+16.0*(var*(var*var)*(var*var))+-2.0000000000000000e+01*(var*var*var)";
        }

        std::string sym() const
        {
            return "-(20.0)*x^3+(5.0)*x+16*x^5";
        }

        std::string latex() const
        {
            return "-{(20.0)} x^{3}+{(5.0)} x+16 x^{5}";
        }

        Chebyshev_5* clone() const
        {
            return new Chebyshev_5(*this);
        }
    };

    class Chebyshev_6 : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return  32.0*((var*var*var)*(var*var*var))+-4.8000000000000000e+01*((var*var)*(var*var))+1.8000000000000000e+01*(var*var)-1.0000000000000000e+00;
        }

    public:
        std::string csrc() const
        {
            return " 32.0*((var*var*var)*(var*var*var))+-4.8000000000000000e+01*((var*var)*(var*var))+1.8000000000000000e+01*(var*var)-1.0000000000000000e+00";
        }

        std::string sym() const
        {
            return "-1.0+(18.0)*x^2+32*x^6-(48.0)*x^4";
        }

        std::string latex() const
        {
            return "-1.0+{(18.0)} x^{2}+32 x^{6}-{(48.0)} x^{4}";
        }

        Chebyshev_6* clone() const
        {
            return new Chebyshev_6(*this);
        }
    };

    class Chebyshev_7 : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return  -7.0000000000000000e+00*var+64.0*(var*(var*var*var)*(var*var*var))+-1.1200000000000000e+02*(var*(var*var)*(var*var))+5.6000000000000000e+01*(var*var*var);
        }

    public:
        std::string csrc() const
        {
            return " -7.0000000000000000e+00*var+64.0*(var*(var*var*var)*(var*var*var))+-1.1200000000000000e+02*(var*(var*var)*(var*var))+5.6000000000000000e+01*(var*var*var)";
        }

        std::string sym() const
        {
            return "(56.0)*x^3-(7.0)*x+64*x^7-(112.0)*x^5";
        }

        std::string latex() const
        {
            return "{(56.0)} x^{3}-{(7.0)} x+64 x^{7}-{(112.0)} x^{5}";
        }

        Chebyshev_7* clone() const
        {
            return new Chebyshev_7(*this);
        }
    };

    class Chebyshev_8 : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return  -2.5600000000000000e+02*((var*var*var)*(var*var*var))+1.6000000000000000e+02*((var*var)*(var*var))+-3.2000000000000000e+01*(var*var)+128.0*(((var*var)*(var*var))*((var*var)*(var*var)))+1.0000000000000000e+00;
        }

    public:
        std::string csrc() const
        {
            return " -2.5600000000000000e+02*((var*var*var)*(var*var*var))+1.6000000000000000e+02*((var*var)*(var*var))+-3.2000000000000000e+01*(var*var)+128.0*(((var*var)*(var*var))*((var*var)*(var*var)))+1.0000000000000000e+00";
        }

        std::string sym() const
        {
            return "1.0-(32.0)*x^2+128*x^8-(256.0)*x^6+(160.0)*x^4";
        }

        std::string latex() const
        {
            return "1.0-{(32.0)} x^{2}+128 x^{8}-{(256.0)} x^{6}+{(160.0)} x^{4}";
        }

        Chebyshev_8* clone() const
        {
            return new Chebyshev_8(*this);
        }
    };

    class Chebyshev_9 : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return  9.0000000000000000e+00*var+-5.7600000000000000e+02*(var*(var*var*var)*(var*var*var))+4.3200000000000000e+02*(var*(var*var)*(var*var))+-1.2000000000000000e+02*(var*var*var)+256.0*(var*((var*var)*(var*var))*((var*var)*(var*var)));
        }

    public:
        std::string csrc() const
        {
            return " 9.0000000000000000e+00*var+-5.7600000000000000e+02*(var*(var*var*var)*(var*var*var))+4.3200000000000000e+02*(var*(var*var)*(var*var))+-1.2000000000000000e+02*(var*var*var)+256.0*(var*((var*var)*(var*var))*((var*var)*(var*var)))";
        }

        std::string sym() const
        {
            return "-(120.0)*x^3+256*x^9+(9.0)*x-(576.0)*x^7+(432.0)*x^5";
        }

        std::string latex() const
        {
            return "-{(120.0)} x^{3}+256 x^{9}+{(9.0)} x-{(576.0)} x^{7}+{(432.0)} x^{5}";
        }

        Chebyshev_9* clone() const
        {
            return new Chebyshev_9(*this);
        }
    };

    class Chebyshev_10 : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return  512.0*((var*(var*var)*(var*var))*(var*(var*var)*(var*var)))+1.1200000000000000e+03*((var*var*var)*(var*var*var))+-4.0000000000000000e+02*((var*var)*(var*var))+5.0000000000000000e+01*(var*var)+-1.2800000000000000e+03*(((var*var)*(var*var))*((var*var)*(var*var)))-1.0000000000000000e+00;
        }

    public:
        std::string csrc() const
        {
            return " 512.0*((var*(var*var)*(var*var))*(var*(var*var)*(var*var)))+1.1200000000000000e+03*((var*var*var)*(var*var*var))+-4.0000000000000000e+02*((var*var)*(var*var))+5.0000000000000000e+01*(var*var)+-1.2800000000000000e+03*(((var*var)*(var*var))*((var*var)*(var*var)))-1.0000000000000000e+00";
        }

        std::string sym() const
        {
            return "-1.0+(50.0)*x^2-(1280.0)*x^8+512*x^10+(1120.0)*x^6-(400.0)*x^4";
        }

        std::string latex() const
        {
            return "-1.0+{(50.0)} x^{2}-{(1280.0)} x^{8}+512 x^{10}+{(1120.0)} x^{6}-{(400.0)} x^{4}";
        }

        Chebyshev_10* clone() const
        {
            return new Chebyshev_10(*this);
        }
    };

    class Chebyshev_11 : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return  -1.1000000000000000e+01*var+2.8160000000000000e+03*(var*(var*var*var)*(var*var*var))+-1.2320000000000000e+03*(var*(var*var)*(var*var))+2.2000000000000000e+02*(var*var*var)+-2.8160000000000000e+03*(var*((var*var)*(var*var))*((var*var)*(var*var)))+1024.0*(var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var)));
        }

    public:
        std::string csrc() const
        {
            return " -1.1000000000000000e+01*var+2.8160000000000000e+03*(var*(var*var*var)*(var*var*var))+-1.2320000000000000e+03*(var*(var*var)*(var*var))+2.2000000000000000e+02*(var*var*var)+-2.8160000000000000e+03*(var*((var*var)*(var*var))*((var*var)*(var*var)))+1024.0*(var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var)))";
        }

        std::string sym() const
        {
            return "(220.0)*x^3+1024*x^11-(2816.0)*x^9-(11.0)*x+(2816.0)*x^7-(1232.0)*x^5";
        }

        std::string latex() const
        {
            return "{(220.0)} x^{3}+1024 x^{11}-{(2816.0)} x^{9}-{(11.0)} x+{(2816.0)} x^{7}-{(1232.0)} x^{5}";
        }

        Chebyshev_11* clone() const
        {
            return new Chebyshev_11(*this);
        }
    };

    class Chebyshev_12 : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return  -6.1440000000000000e+03*((var*(var*var)*(var*var))*(var*(var*var)*(var*var)))+2048.0*(((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))+-3.5840000000000000e+03*((var*var*var)*(var*var*var))+8.4000000000000000e+02*((var*var)*(var*var))+-7.2000000000000000e+01*(var*var)+6.9120000000000000e+03*(((var*var)*(var*var))*((var*var)*(var*var)))+1.0000000000000000e+00;
        }

    public:
        std::string csrc() const
        {
            return " -6.1440000000000000e+03*((var*(var*var)*(var*var))*(var*(var*var)*(var*var)))+2048.0*(((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))+-3.5840000000000000e+03*((var*var*var)*(var*var*var))+8.4000000000000000e+02*((var*var)*(var*var))+-7.2000000000000000e+01*(var*var)+6.9120000000000000e+03*(((var*var)*(var*var))*((var*var)*(var*var)))+1.0000000000000000e+00";
        }

        std::string sym() const
        {
            return "1.0-(72.0)*x^2+(6912.0)*x^8+2048*x^12-(6144.0)*x^10-(3584.0)*x^6+(840.0)*x^4";
        }

        std::string latex() const
        {
            return "1.0-{(72.0)} x^{2}+{(6912.0)} x^{8}+2048 x^{12}-{(6144.0)} x^{10}-{(3584.0)} x^{6}+{(840.0)} x^{4}";
        }

        Chebyshev_12* clone() const
        {
            return new Chebyshev_12(*this);
        }
    };

    class Chebyshev_13 : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return  1.3000000000000000e+01*var+-9.9840000000000000e+03*(var*(var*var*var)*(var*var*var))+2.9120000000000000e+03*(var*(var*var)*(var*var))+4096.0*(var*((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))+-3.6400000000000000e+02*(var*var*var)+1.6640000000000000e+04*(var*((var*var)*(var*var))*((var*var)*(var*var)))+-1.3312000000000000e+04*(var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var)));
        }

    public:
        std::string csrc() const
        {
            return " 1.3000000000000000e+01*var+-9.9840000000000000e+03*(var*(var*var*var)*(var*var*var))+2.9120000000000000e+03*(var*(var*var)*(var*var))+4096.0*(var*((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))+-3.6400000000000000e+02*(var*var*var)+1.6640000000000000e+04*(var*((var*var)*(var*var))*((var*var)*(var*var)))+-1.3312000000000000e+04*(var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var)))";
        }

        std::string sym() const
        {
            return "-(364.0)*x^3+4096*x^13-(13312.0)*x^11+(16640.0)*x^9+(13.0)*x-(9984.0)*x^7+(2912.0)*x^5";
        }

        std::string latex() const
        {
            return "-{(364.0)} x^{3}+4096 x^{13}-{(13312.0)} x^{11}+{(16640.0)} x^{9}+{(13.0)} x-{(9984.0)} x^{7}+{(2912.0)} x^{5}";
        }

        Chebyshev_13* clone() const
        {
            return new Chebyshev_13(*this);
        }
    };

    class Chebyshev_14 : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return  8192.0*((var*(var*var*var)*(var*var*var))*(var*(var*var*var)*(var*var*var)))+3.9424000000000000e+04*((var*(var*var)*(var*var))*(var*(var*var)*(var*var)))+-2.8672000000000000e+04*(((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))+9.4080000000000000e+03*((var*var*var)*(var*var*var))+-1.5680000000000000e+03*((var*var)*(var*var))+9.8000000000000000e+01*(var*var)+-2.6880000000000000e+04*(((var*var)*(var*var))*((var*var)*(var*var)))-1.0000000000000000e+00;
        }

    public:
        std::string csrc() const
        {
            return " 8192.0*((var*(var*var*var)*(var*var*var))*(var*(var*var*var)*(var*var*var)))+3.9424000000000000e+04*((var*(var*var)*(var*var))*(var*(var*var)*(var*var)))+-2.8672000000000000e+04*(((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))+9.4080000000000000e+03*((var*var*var)*(var*var*var))+-1.5680000000000000e+03*((var*var)*(var*var))+9.8000000000000000e+01*(var*var)+-2.6880000000000000e+04*(((var*var)*(var*var))*((var*var)*(var*var)))-1.0000000000000000e+00";
        }

        std::string sym() const
        {
            return "-1.0+(98.0)*x^2-(26880.0)*x^8+8192*x^14-(28672.0)*x^12+(39424.0)*x^10+(9408.0)*x^6-(1568.0)*x^4";
        }

        std::string latex() const
        {
            return "-1.0+{(98.0)} x^{2}-{(26880.0)} x^{8}+8192 x^{14}-{(28672.0)} x^{12}+{(39424.0)} x^{10}+{(9408.0)} x^{6}-{(1568.0)} x^{4}";
        }

        Chebyshev_14* clone() const
        {
            return new Chebyshev_14(*this);
        }
    };

    class Chebyshev_15 : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return  -1.5000000000000000e+01*var+2.8800000000000000e+04*(var*(var*var*var)*(var*var*var))+-6.0480000000000000e+03*(var*(var*var)*(var*var))+16384.0*(var*(var*(var*var*var)*(var*var*var))*(var*(var*var*var)*(var*var*var)))+-6.1440000000000000e+04*(var*((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))+5.6000000000000000e+02*(var*var*var)+-7.0400000000000000e+04*(var*((var*var)*(var*var))*((var*var)*(var*var)))+9.2160000000000000e+04*(var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var)));
        }

    public:
        std::string csrc() const
        {
            return " -1.5000000000000000e+01*var+2.8800000000000000e+04*(var*(var*var*var)*(var*var*var))+-6.0480000000000000e+03*(var*(var*var)*(var*var))+16384.0*(var*(var*(var*var*var)*(var*var*var))*(var*(var*var*var)*(var*var*var)))+-6.1440000000000000e+04*(var*((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))+5.6000000000000000e+02*(var*var*var)+-7.0400000000000000e+04*(var*((var*var)*(var*var))*((var*var)*(var*var)))+9.2160000000000000e+04*(var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var)))";
        }

        std::string sym() const
        {
            return "(560.0)*x^3+16384*x^15-(61440.0)*x^13+(92160.0)*x^11-(70400.0)*x^9-(15.0)*x+(28800.0)*x^7-(6048.0)*x^5";
        }

        std::string latex() const
        {
            return "{(560.0)} x^{3}+16384 x^{15}-{(61440.0)} x^{13}+{(92160.0)} x^{11}-{(70400.0)} x^{9}-{(15.0)} x+{(28800.0)} x^{7}-{(6048.0)} x^{5}";
        }

        Chebyshev_15* clone() const
        {
            return new Chebyshev_15(*this);
        }
    };

    class Chebyshev_16 : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return  -1.3107200000000000e+05*((var*(var*var*var)*(var*var*var))*(var*(var*var*var)*(var*var*var)))+-1.8022400000000000e+05*((var*(var*var)*(var*var))*(var*(var*var)*(var*var)))+2.1299200000000000e+05*(((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))+-2.1504000000000000e+04*((var*var*var)*(var*var*var))+2.6880000000000000e+03*((var*var)*(var*var))+32768.0*((((var*var)*(var*var))*((var*var)*(var*var)))*(((var*var)*(var*var))*((var*var)*(var*var))))+-1.2800000000000000e+02*(var*var)+8.4480000000000000e+04*(((var*var)*(var*var))*((var*var)*(var*var)))+1.0000000000000000e+00;
        }

    public:
        std::string csrc() const
        {
            return " -1.3107200000000000e+05*((var*(var*var*var)*(var*var*var))*(var*(var*var*var)*(var*var*var)))+-1.8022400000000000e+05*((var*(var*var)*(var*var))*(var*(var*var)*(var*var)))+2.1299200000000000e+05*(((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))+-2.1504000000000000e+04*((var*var*var)*(var*var*var))+2.6880000000000000e+03*((var*var)*(var*var))+32768.0*((((var*var)*(var*var))*((var*var)*(var*var)))*(((var*var)*(var*var))*((var*var)*(var*var))))+-1.2800000000000000e+02*(var*var)+8.4480000000000000e+04*(((var*var)*(var*var))*((var*var)*(var*var)))+1.0000000000000000e+00";
        }

        std::string sym() const
        {
            return "1.0+32768*x^16-(128.0)*x^2+(84480.0)*x^8-(131072.0)*x^14+(212992.0)*x^12-(180224.0)*x^10-(21504.0)*x^6+(2688.0)*x^4";
        }

        std::string latex() const
        {
            return "1.0+32768 x^{16}-{(128.0)} x^{2}+{(84480.0)} x^{8}-{(131072.0)} x^{14}+{(212992.0)} x^{12}-{(180224.0)} x^{10}-{(21504.0)} x^{6}+{(2688.0)} x^{4}";
        }

        Chebyshev_16* clone() const
        {
            return new Chebyshev_16(*this);
        }
    };

    class Chebyshev_17 : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return  1.7000000000000000e+01*var+-7.1808000000000000e+04*(var*(var*var*var)*(var*var*var))+65536.0*(var*(((var*var)*(var*var))*((var*var)*(var*var)))*(((var*var)*(var*var))*((var*var)*(var*var))))+1.1424000000000000e+04*(var*(var*var)*(var*var))+-2.7852800000000000e+05*(var*(var*(var*var*var)*(var*var*var))*(var*(var*var*var)*(var*var*var)))+4.8742400000000000e+05*(var*((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))+-8.1600000000000000e+02*(var*var*var)+2.3936000000000000e+05*(var*((var*var)*(var*var))*((var*var)*(var*var)))+-4.5260800000000000e+05*(var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var)));
        }

    public:
        std::string csrc() const
        {
            return " 1.7000000000000000e+01*var+-7.1808000000000000e+04*(var*(var*var*var)*(var*var*var))+65536.0*(var*(((var*var)*(var*var))*((var*var)*(var*var)))*(((var*var)*(var*var))*((var*var)*(var*var))))+1.1424000000000000e+04*(var*(var*var)*(var*var))+-2.7852800000000000e+05*(var*(var*(var*var*var)*(var*var*var))*(var*(var*var*var)*(var*var*var)))+4.8742400000000000e+05*(var*((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))+-8.1600000000000000e+02*(var*var*var)+2.3936000000000000e+05*(var*((var*var)*(var*var))*((var*var)*(var*var)))+-4.5260800000000000e+05*(var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var)))";
        }

        std::string sym() const
        {
            return "-(816.0)*x^3-(278528.0)*x^15+(487424.0)*x^13-(452608.0)*x^11+(239360.0)*x^9+(17.0)*x-(71808.0)*x^7+65536*x^17+(11424.0)*x^5";
        }

        std::string latex() const
        {
            return "-{(816.0)} x^{3}-{(278528.0)} x^{15}+{(487424.0)} x^{13}-{(452608.0)} x^{11}+{(239360.0)} x^{9}+{(17.0)} x-{(71808.0)} x^{7}+65536 x^{17}+{(11424.0)} x^{5}";
        }

        Chebyshev_17* clone() const
        {
            return new Chebyshev_17(*this);
        }
    };

    class Chebyshev_18 : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return  1.1059200000000000e+06*((var*(var*var*var)*(var*var*var))*(var*(var*var*var)*(var*var*var)))+131072.0*((var*((var*var)*(var*var))*((var*var)*(var*var)))*(var*((var*var)*(var*var))*((var*var)*(var*var))))+6.5894400000000000e+05*((var*(var*var)*(var*var))*(var*(var*var)*(var*var)))+-1.1182080000000000e+06*(((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))+4.4352000000000000e+04*((var*var*var)*(var*var*var))+-4.3200000000000000e+03*((var*var)*(var*var))+-5.8982400000000000e+05*((((var*var)*(var*var))*((var*var)*(var*var)))*(((var*var)*(var*var))*((var*var)*(var*var))))+1.6200000000000000e+02*(var*var)+-2.2809600000000000e+05*(((var*var)*(var*var))*((var*var)*(var*var)))-1.0000000000000000e+00;
        }

    public:
        std::string csrc() const
        {
            return " 1.1059200000000000e+06*((var*(var*var*var)*(var*var*var))*(var*(var*var*var)*(var*var*var)))+131072.0*((var*((var*var)*(var*var))*((var*var)*(var*var)))*(var*((var*var)*(var*var))*((var*var)*(var*var))))+6.5894400000000000e+05*((var*(var*var)*(var*var))*(var*(var*var)*(var*var)))+-1.1182080000000000e+06*(((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))+4.4352000000000000e+04*((var*var*var)*(var*var*var))+-4.3200000000000000e+03*((var*var)*(var*var))+-5.8982400000000000e+05*((((var*var)*(var*var))*((var*var)*(var*var)))*(((var*var)*(var*var))*((var*var)*(var*var))))+1.6200000000000000e+02*(var*var)+-2.2809600000000000e+05*(((var*var)*(var*var))*((var*var)*(var*var)))-1.0000000000000000e+00";
        }

        std::string sym() const
        {
            return "-1.0-(589824.0)*x^16+(162.0)*x^2-(228096.0)*x^8+131072*x^18+(1105920.0)*x^14-(1118208.0)*x^12+(658944.0)*x^10+(44352.0)*x^6-(4320.0)*x^4";
        }

        std::string latex() const
        {
            return "-1.0-{(589824.0)} x^{16}+{(162.0)} x^{2}-{(228096.0)} x^{8}+131072 x^{18}+{(1105920.0)} x^{14}-{(1118208.0)} x^{12}+{(658944.0)} x^{10}+{(44352.0)} x^{6}-{(4320.0)} x^{4}";
        }

        Chebyshev_18* clone() const
        {
            return new Chebyshev_18(*this);
        }
    };

    class Chebyshev_19 : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return  -1.9000000000000000e+01*var+1.6051200000000000e+05*(var*(var*var*var)*(var*var*var))+-1.2451840000000000e+06*(var*(((var*var)*(var*var))*((var*var)*(var*var)))*(((var*var)*(var*var))*((var*var)*(var*var))))+-2.0064000000000000e+04*(var*(var*var)*(var*var))+2.4903680000000000e+06*(var*(var*(var*var*var)*(var*var*var))*(var*(var*var*var)*(var*var*var)))+-2.7238400000000000e+06*(var*((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))+1.1400000000000000e+03*(var*var*var)+-6.9555200000000000e+05*(var*((var*var)*(var*var))*((var*var)*(var*var)))+1.7704960000000000e+06*(var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var)))+262144.0*(var*(var*((var*var)*(var*var))*((var*var)*(var*var)))*(var*((var*var)*(var*var))*((var*var)*(var*var))));
        }

    public:
        std::string csrc() const
        {
            return " -1.9000000000000000e+01*var+1.6051200000000000e+05*(var*(var*var*var)*(var*var*var))+-1.2451840000000000e+06*(var*(((var*var)*(var*var))*((var*var)*(var*var)))*(((var*var)*(var*var))*((var*var)*(var*var))))+-2.0064000000000000e+04*(var*(var*var)*(var*var))+2.4903680000000000e+06*(var*(var*(var*var*var)*(var*var*var))*(var*(var*var*var)*(var*var*var)))+-2.7238400000000000e+06*(var*((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))+1.1400000000000000e+03*(var*var*var)+-6.9555200000000000e+05*(var*((var*var)*(var*var))*((var*var)*(var*var)))+1.7704960000000000e+06*(var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var)))+262144.0*(var*(var*((var*var)*(var*var))*((var*var)*(var*var)))*(var*((var*var)*(var*var))*((var*var)*(var*var))))";
        }

        std::string sym() const
        {
            return "(1140.0)*x^3+(2490368.0)*x^15-(2723840.0)*x^13+(1770496.0)*x^11-(695552.0)*x^9+262144*x^19-(19.0)*x+(160512.0)*x^7-(1245184.0)*x^17-(20064.0)*x^5";
        }

        std::string latex() const
        {
            return "{(1140.0)} x^{3}+{(2490368.0)} x^{15}-{(2723840.0)} x^{13}+{(1770496.0)} x^{11}-{(695552.0)} x^{9}+262144 x^{19}-{(19.0)} x+{(160512.0)} x^{7}-{(1245184.0)} x^{17}-{(20064.0)} x^{5}";
        }

        Chebyshev_19* clone() const
        {
            return new Chebyshev_19(*this);
        }
    };

    class Chebyshev_20 : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return  -6.5536000000000000e+06*((var*(var*var*var)*(var*var*var))*(var*(var*var*var)*(var*var*var)))+-2.6214400000000000e+06*((var*((var*var)*(var*var))*((var*var)*(var*var)))*(var*((var*var)*(var*var))*((var*var)*(var*var))))+-2.0500480000000000e+06*((var*(var*var)*(var*var))*(var*(var*var)*(var*var)))+4.6592000000000000e+06*(((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))+-8.4480000000000000e+04*((var*var*var)*(var*var*var))+6.6000000000000000e+03*((var*var)*(var*var))+5.5705600000000000e+06*((((var*var)*(var*var))*((var*var)*(var*var)))*(((var*var)*(var*var))*((var*var)*(var*var))))+524288.0*(((var*(var*var)*(var*var))*(var*(var*var)*(var*var)))*((var*(var*var)*(var*var))*(var*(var*var)*(var*var))))+-2.0000000000000000e+02*(var*var)+5.4912000000000000e+05*(((var*var)*(var*var))*((var*var)*(var*var)))+1.0000000000000000e+00;
        }

    public:
        std::string csrc() const
        {
            return " -6.5536000000000000e+06*((var*(var*var*var)*(var*var*var))*(var*(var*var*var)*(var*var*var)))+-2.6214400000000000e+06*((var*((var*var)*(var*var))*((var*var)*(var*var)))*(var*((var*var)*(var*var))*((var*var)*(var*var))))+-2.0500480000000000e+06*((var*(var*var)*(var*var))*(var*(var*var)*(var*var)))+4.6592000000000000e+06*(((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))+-8.4480000000000000e+04*((var*var*var)*(var*var*var))+6.6000000000000000e+03*((var*var)*(var*var))+5.5705600000000000e+06*((((var*var)*(var*var))*((var*var)*(var*var)))*(((var*var)*(var*var))*((var*var)*(var*var))))+524288.0*(((var*(var*var)*(var*var))*(var*(var*var)*(var*var)))*((var*(var*var)*(var*var))*(var*(var*var)*(var*var))))+-2.0000000000000000e+02*(var*var)+5.4912000000000000e+05*(((var*var)*(var*var))*((var*var)*(var*var)))+1.0000000000000000e+00";
        }

        std::string sym() const
        {
            return "1.0+524288*x^20+(5570560.0)*x^16-(200.0)*x^2+(549120.0)*x^8-(2621440.0)*x^18-(6553600.0)*x^14+(4659200.0)*x^12-(2050048.0)*x^10-(84480.0)*x^6+(6600.0)*x^4";
        }

        std::string latex() const
        {
            return "1.0+524288 x^{20}+{(5570560.0)} x^{16}-{(200.0)} x^{2}+{(549120.0)} x^{8}-{(2621440.0)} x^{18}-{(6553600.0)} x^{14}+{(4659200.0)} x^{12}-{(2050048.0)} x^{10}-{(84480.0)} x^{6}+{(6600.0)} x^{4}";
        }

        Chebyshev_20* clone() const
        {
            return new Chebyshev_20(*this);
        }
    };

    class Chebyshev_21 : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return  2.1000000000000000e+01*var+1048576.0*(var*((var*(var*var)*(var*var))*(var*(var*var)*(var*var)))*((var*(var*var)*(var*var))*(var*(var*var)*(var*var))))+-3.2947200000000000e+05*(var*(var*var*var)*(var*var*var))+1.2386304000000000e+07*(var*(((var*var)*(var*var))*((var*var)*(var*var)))*(((var*var)*(var*var))*((var*var)*(var*var))))+3.3264000000000000e+04*(var*(var*var)*(var*var))+-1.5597568000000000e+07*(var*(var*(var*var*var)*(var*var*var))*(var*(var*var*var)*(var*var*var)))+1.2042240000000000e+07*(var*((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))+-1.5400000000000000e+03*(var*var*var)+1.7937920000000000e+06*(var*((var*var)*(var*var))*((var*var)*(var*var)))+-5.8705920000000000e+06*(var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var)))+-5.5050240000000000e+06*(var*(var*((var*var)*(var*var))*((var*var)*(var*var)))*(var*((var*var)*(var*var))*((var*var)*(var*var))));
        }

    public:
        std::string csrc() const
        {
            return " 2.1000000000000000e+01*var+1048576.0*(var*((var*(var*var)*(var*var))*(var*(var*var)*(var*var)))*((var*(var*var)*(var*var))*(var*(var*var)*(var*var))))+-3.2947200000000000e+05*(var*(var*var*var)*(var*var*var))+1.2386304000000000e+07*(var*(((var*var)*(var*var))*((var*var)*(var*var)))*(((var*var)*(var*var))*((var*var)*(var*var))))+3.3264000000000000e+04*(var*(var*var)*(var*var))+-1.5597568000000000e+07*(var*(var*(var*var*var)*(var*var*var))*(var*(var*var*var)*(var*var*var)))+1.2042240000000000e+07*(var*((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))+-1.5400000000000000e+03*(var*var*var)+1.7937920000000000e+06*(var*((var*var)*(var*var))*((var*var)*(var*var)))+-5.8705920000000000e+06*(var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var)))+-5.5050240000000000e+06*(var*(var*((var*var)*(var*var))*((var*var)*(var*var)))*(var*((var*var)*(var*var))*((var*var)*(var*var))))";
        }

        std::string sym() const
        {
            return "-(1540.0)*x^3-(1.5597568E7)*x^15+(1.204224E7)*x^13-(5870592.0)*x^11+(1793792.0)*x^9-(5505024.0)*x^19+1048576*x^21+(21.0)*x-(329472.0)*x^7+(1.2386304E7)*x^17+(33264.0)*x^5";
        }

        std::string latex() const
        {
            return "-{(1540.0)} x^{3}-{(1.5597568E7)} x^{15}+{(1.204224E7)} x^{13}-{(5870592.0)} x^{11}+{(1793792.0)} x^{9}-{(5505024.0)} x^{19}+1048576 x^{21}+{(21.0)} x-{(329472.0)} x^{7}+{(1.2386304E7)} x^{17}+{(33264.0)} x^{5}";
        }

        Chebyshev_21* clone() const
        {
            return new Chebyshev_21(*this);
        }
    };

    class Chebyshev_22 : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return  3.0638080000000000e+07*((var*(var*var*var)*(var*var*var))*(var*(var*var*var)*(var*var*var)))+2.7394048000000000e+07*((var*((var*var)*(var*var))*((var*var)*(var*var)))*(var*((var*var)*(var*var))*((var*var)*(var*var))))+5.6376320000000000e+06*((var*(var*var)*(var*var))*(var*(var*var)*(var*var)))+-1.6400384000000000e+07*(((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))+1.5100800000000000e+05*((var*var*var)*(var*var*var))+-9.6800000000000000e+03*((var*var)*(var*var))+2097152.0*((var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var)))*(var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var))))+-3.6765696000000000e+07*((((var*var)*(var*var))*((var*var)*(var*var)))*(((var*var)*(var*var))*((var*var)*(var*var))))+-1.1534336000000000e+07*(((var*(var*var)*(var*var))*(var*(var*var)*(var*var)))*((var*(var*var)*(var*var))*(var*(var*var)*(var*var))))+2.4200000000000000e+02*(var*var)+-1.2080640000000000e+06*(((var*var)*(var*var))*((var*var)*(var*var)))-1.0000000000000000e+00;
        }

    public:
        std::string csrc() const
        {
            return " 3.0638080000000000e+07*((var*(var*var*var)*(var*var*var))*(var*(var*var*var)*(var*var*var)))+2.7394048000000000e+07*((var*((var*var)*(var*var))*((var*var)*(var*var)))*(var*((var*var)*(var*var))*((var*var)*(var*var))))+5.6376320000000000e+06*((var*(var*var)*(var*var))*(var*(var*var)*(var*var)))+-1.6400384000000000e+07*(((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))+1.5100800000000000e+05*((var*var*var)*(var*var*var))+-9.6800000000000000e+03*((var*var)*(var*var))+2097152.0*((var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var)))*(var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var))))+-3.6765696000000000e+07*((((var*var)*(var*var))*((var*var)*(var*var)))*(((var*var)*(var*var))*((var*var)*(var*var))))+-1.1534336000000000e+07*(((var*(var*var)*(var*var))*(var*(var*var)*(var*var)))*((var*(var*var)*(var*var))*(var*(var*var)*(var*var))))+2.4200000000000000e+02*(var*var)+-1.2080640000000000e+06*(((var*var)*(var*var))*((var*var)*(var*var)))-1.0000000000000000e+00";
        }

        std::string sym() const
        {
            return "-1.0-(1.1534336E7)*x^20-(3.6765696E7)*x^16+(242.0)*x^2-(1208064.0)*x^8+(2.7394048E7)*x^18+(3.063808E7)*x^14-(1.6400384E7)*x^12+(5637632.0)*x^10+(151008.0)*x^6-(9680.0)*x^4+2097152*x^22";
        }

        std::string latex() const
        {
            return "-1.0-{(1.1534336E7)} x^{20}-{(3.6765696E7)} x^{16}+{(242.0)} x^{2}-{(1208064.0)} x^{8}+{(2.7394048E7)} x^{18}+{(3.063808E7)} x^{14}-{(1.6400384E7)} x^{12}+{(5637632.0)} x^{10}+{(151008.0)} x^{6}-{(9680.0)} x^{4}+2097152 x^{22}";
        }

        Chebyshev_22* clone() const
        {
            return new Chebyshev_22(*this);
        }
    };

    class Chebyshev_23 : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return  -2.3000000000000000e+01*var+4194304.0*(var*(var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var)))*(var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var))))+-2.4117248000000000e+07*(var*((var*(var*var)*(var*var))*(var*(var*var)*(var*var)))*((var*(var*var)*(var*var))*(var*(var*var)*(var*var))))+6.3148800000000000e+05*(var*(var*var*var)*(var*var*var))+-8.5917696000000000e+07*(var*(((var*var)*(var*var))*((var*var)*(var*var)))*(((var*var)*(var*var))*((var*var)*(var*var))))+-5.2624000000000000e+04*(var*(var*var)*(var*var))+7.6873728000000000e+07*(var*(var*(var*var*var)*(var*var*var))*(var*(var*var*var)*(var*var*var)))+-4.4843008000000000e+07*(var*((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))+2.0240000000000000e+03*(var*var*var)+-4.2099200000000000e+06*(var*((var*var)*(var*var))*((var*var)*(var*var)))+1.7145856000000000e+07*(var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var)))+6.0293120000000000e+07*(var*(var*((var*var)*(var*var))*((var*var)*(var*var)))*(var*((var*var)*(var*var))*((var*var)*(var*var))));
        }

    public:
        std::string csrc() const
        {
            return " -2.3000000000000000e+01*var+4194304.0*(var*(var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var)))*(var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var))))+-2.4117248000000000e+07*(var*((var*(var*var)*(var*var))*(var*(var*var)*(var*var)))*((var*(var*var)*(var*var))*(var*(var*var)*(var*var))))+6.3148800000000000e+05*(var*(var*var*var)*(var*var*var))+-8.5917696000000000e+07*(var*(((var*var)*(var*var))*((var*var)*(var*var)))*(((var*var)*(var*var))*((var*var)*(var*var))))+-5.2624000000000000e+04*(var*(var*var)*(var*var))+7.6873728000000000e+07*(var*(var*(var*var*var)*(var*var*var))*(var*(var*var*var)*(var*var*var)))+-4.4843008000000000e+07*(var*((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))+2.0240000000000000e+03*(var*var*var)+-4.2099200000000000e+06*(var*((var*var)*(var*var))*((var*var)*(var*var)))+1.7145856000000000e+07*(var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var)))+6.0293120000000000e+07*(var*(var*((var*var)*(var*var))*((var*var)*(var*var)))*(var*((var*var)*(var*var))*((var*var)*(var*var))))";
        }

        std::string sym() const
        {
            return "(2024.0)*x^3+(7.6873728E7)*x^15-(4.4843008E7)*x^13+(1.7145856E7)*x^11-(4209920.0)*x^9+(6.029312E7)*x^19+4194304*x^23-(2.4117248E7)*x^21-(23.0)*x+(631488.0)*x^7-(8.5917696E7)*x^17-(52624.0)*x^5";
        }

        std::string latex() const
        {
            return "{(2024.0)} x^{3}+{(7.6873728E7)} x^{15}-{(4.4843008E7)} x^{13}+{(1.7145856E7)} x^{11}-{(4209920.0)} x^{9}+{(6.029312E7)} x^{19}+4194304 x^{23}-{(2.4117248E7)} x^{21}-{(23.0)} x+{(631488.0)} x^{7}-{(8.5917696E7)} x^{17}-{(52624.0)} x^{5}";
        }

        Chebyshev_23* clone() const
        {
            return new Chebyshev_23(*this);
        }
    };

    class Chebyshev_24 : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return  -1.2032409600000000e+08*((var*(var*var*var)*(var*var*var))*(var*(var*var*var)*(var*var*var)))+-1.9922944000000000e+08*((var*((var*var)*(var*var))*((var*var)*(var*var)))*(var*((var*var)*(var*var))*((var*var)*(var*var))))+-1.4057472000000000e+07*((var*(var*var)*(var*var))*(var*(var*var)*(var*var)))+5.0692096000000000e+07*(((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))+-2.5625600000000000e+05*((var*var*var)*(var*var*var))+1.3728000000000000e+04*((var*var)*(var*var))+-5.0331648000000000e+07*((var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var)))*(var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var))))+1.9051315200000000e+08*((((var*var)*(var*var))*((var*var)*(var*var)))*(((var*var)*(var*var))*((var*var)*(var*var))))+1.3212057600000000e+08*(((var*(var*var)*(var*var))*(var*(var*var)*(var*var)))*((var*(var*var)*(var*var))*(var*(var*var)*(var*var))))+-2.8800000000000000e+02*(var*var)+2.4710400000000000e+06*(((var*var)*(var*var))*((var*var)*(var*var)))+8388608.0*((((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))*(((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var))))+1.0000000000000000e+00;
        }

    public:
        std::string csrc() const
        {
            return " -1.2032409600000000e+08*((var*(var*var*var)*(var*var*var))*(var*(var*var*var)*(var*var*var)))+-1.9922944000000000e+08*((var*((var*var)*(var*var))*((var*var)*(var*var)))*(var*((var*var)*(var*var))*((var*var)*(var*var))))+-1.4057472000000000e+07*((var*(var*var)*(var*var))*(var*(var*var)*(var*var)))+5.0692096000000000e+07*(((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))+-2.5625600000000000e+05*((var*var*var)*(var*var*var))+1.3728000000000000e+04*((var*var)*(var*var))+-5.0331648000000000e+07*((var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var)))*(var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var))))+1.9051315200000000e+08*((((var*var)*(var*var))*((var*var)*(var*var)))*(((var*var)*(var*var))*((var*var)*(var*var))))+1.3212057600000000e+08*(((var*(var*var)*(var*var))*(var*(var*var)*(var*var)))*((var*(var*var)*(var*var))*(var*(var*var)*(var*var))))+-2.8800000000000000e+02*(var*var)+2.4710400000000000e+06*(((var*var)*(var*var))*((var*var)*(var*var)))+8388608.0*((((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))*(((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var))))+1.0000000000000000e+00";
        }

        std::string sym() const
        {
            return "1.0+(1.32120576E8)*x^20+(1.90513152E8)*x^16-(288.0)*x^2+(2471040.0)*x^8+8388608*x^24-(1.9922944E8)*x^18-(1.20324096E8)*x^14+(5.0692096E7)*x^12-(1.4057472E7)*x^10-(256256.0)*x^6+(13728.0)*x^4-(5.0331648E7)*x^22";
        }

        std::string latex() const
        {
            return "1.0+{(1.32120576E8)} x^{20}+{(1.90513152E8)} x^{16}-{(288.0)} x^{2}+{(2471040.0)} x^{8}+8388608 x^{24}-{(1.9922944E8)} x^{18}-{(1.20324096E8)} x^{14}+{(5.0692096E7)} x^{12}-{(1.4057472E7)} x^{10}-{(256256.0)} x^{6}+{(13728.0)} x^{4}-{(5.0331648E7)} x^{22}";
        }

        Chebyshev_24* clone() const
        {
            return new Chebyshev_24(*this);
        }
    };

    class Chebyshev_25 : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return  2.5000000000000000e+01*var+-1.0485760000000000e+08*(var*(var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var)))*(var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var))))+2.8835840000000000e+08*(var*((var*(var*var)*(var*var))*(var*(var*var)*(var*var)))*((var*(var*var)*(var*var))*(var*(var*var)*(var*var))))+-1.1440000000000000e+06*(var*(var*var*var)*(var*var*var))+4.6694400000000000e+08*(var*(((var*var)*(var*var))*((var*var)*(var*var)))*(((var*var)*(var*var))*((var*var)*(var*var))))+8.0080000000000000e+04*(var*(var*var)*(var*var))+-3.1752192000000000e+08*(var*(var*(var*var*var)*(var*var*var))*(var*(var*var*var)*(var*var*var)))+1.4622720000000000e+08*(var*((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))+-2.6000000000000000e+03*(var*var*var)+16777216.0*(var*(((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))*(((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var))))+9.1520000000000000e+06*(var*((var*var)*(var*var))*((var*var)*(var*var)))+-4.5260800000000000e+07*(var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var)))+-4.5875200000000000e+08*(var*(var*((var*var)*(var*var))*((var*var)*(var*var)))*(var*((var*var)*(var*var))*((var*var)*(var*var))));
        }

    public:
        std::string csrc() const
        {
            return " 2.5000000000000000e+01*var+-1.0485760000000000e+08*(var*(var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var)))*(var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var))))+2.8835840000000000e+08*(var*((var*(var*var)*(var*var))*(var*(var*var)*(var*var)))*((var*(var*var)*(var*var))*(var*(var*var)*(var*var))))+-1.1440000000000000e+06*(var*(var*var*var)*(var*var*var))+4.6694400000000000e+08*(var*(((var*var)*(var*var))*((var*var)*(var*var)))*(((var*var)*(var*var))*((var*var)*(var*var))))+8.0080000000000000e+04*(var*(var*var)*(var*var))+-3.1752192000000000e+08*(var*(var*(var*var*var)*(var*var*var))*(var*(var*var*var)*(var*var*var)))+1.4622720000000000e+08*(var*((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))+-2.6000000000000000e+03*(var*var*var)+16777216.0*(var*(((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))*(((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var))))+9.1520000000000000e+06*(var*((var*var)*(var*var))*((var*var)*(var*var)))+-4.5260800000000000e+07*(var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var)))+-4.5875200000000000e+08*(var*(var*((var*var)*(var*var))*((var*var)*(var*var)))*(var*((var*var)*(var*var))*((var*var)*(var*var))))";
        }

        std::string sym() const
        {
            return "-(2600.0)*x^3-(3.1752192E8)*x^15+(1.462272E8)*x^13-(4.52608E7)*x^11+16777216*x^25+(9152000.0)*x^9-(4.58752E8)*x^19-(1.048576E8)*x^23+(2.883584E8)*x^21+(25.0)*x-(1144000.0)*x^7+(4.66944E8)*x^17+(80080.0)*x^5";
        }

        std::string latex() const
        {
            return "-{(2600.0)} x^{3}-{(3.1752192E8)} x^{15}+{(1.462272E8)} x^{13}-{(4.52608E7)} x^{11}+16777216 x^{25}+{(9152000.0)} x^{9}-{(4.58752E8)} x^{19}-{(1.048576E8)} x^{23}+{(2.883584E8)} x^{21}+{(25.0)} x-{(1144000.0)} x^{7}+{(4.66944E8)} x^{17}+{(80080.0)} x^{5}";
        }

        Chebyshev_25* clone() const
        {
            return new Chebyshev_25(*this);
        }
    };

    class Chebyshev_26 : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return  4.1277849600000000e+08*((var*(var*var*var)*(var*var*var))*(var*(var*var*var)*(var*var*var)))+1.1331174400000000e+09*((var*((var*var)*(var*var))*((var*var)*(var*var)))*(var*((var*var)*(var*var))*((var*var)*(var*var))))+3.2361472000000000e+07*((var*(var*var)*(var*var))*(var*(var*var)*(var*var)))+-1.4121369600000000e+08*(((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))+4.1641600000000000e+05*((var*var*var)*(var*var*var))+-1.8928000000000000e+04*((var*var)*(var*var))+6.2704844800000000e+08*((var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var)))*(var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var))))+33554432.0*((var*((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))*(var*((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var))))+-8.2555699200000000e+08*((((var*var)*(var*var))*((var*var)*(var*var)))*(((var*var)*(var*var))*((var*var)*(var*var))))+-1.0496245760000000e+09*(((var*(var*var)*(var*var))*(var*(var*var)*(var*var)))*((var*(var*var)*(var*var))*(var*(var*var)*(var*var))))+3.3800000000000000e+02*(var*var)+-4.7590400000000000e+06*(((var*var)*(var*var))*((var*var)*(var*var)))+-2.1810380800000000e+08*((((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))*(((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var))))-1.0000000000000000e+00;
        }

    public:
        std::string csrc() const
        {
            return " 4.1277849600000000e+08*((var*(var*var*var)*(var*var*var))*(var*(var*var*var)*(var*var*var)))+1.1331174400000000e+09*((var*((var*var)*(var*var))*((var*var)*(var*var)))*(var*((var*var)*(var*var))*((var*var)*(var*var))))+3.2361472000000000e+07*((var*(var*var)*(var*var))*(var*(var*var)*(var*var)))+-1.4121369600000000e+08*(((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))+4.1641600000000000e+05*((var*var*var)*(var*var*var))+-1.8928000000000000e+04*((var*var)*(var*var))+6.2704844800000000e+08*((var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var)))*(var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var))))+33554432.0*((var*((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))*(var*((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var))))+-8.2555699200000000e+08*((((var*var)*(var*var))*((var*var)*(var*var)))*(((var*var)*(var*var))*((var*var)*(var*var))))+-1.0496245760000000e+09*(((var*(var*var)*(var*var))*(var*(var*var)*(var*var)))*((var*(var*var)*(var*var))*(var*(var*var)*(var*var))))+3.3800000000000000e+02*(var*var)+-4.7590400000000000e+06*(((var*var)*(var*var))*((var*var)*(var*var)))+-2.1810380800000000e+08*((((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))*(((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var))))-1.0000000000000000e+00";
        }

        std::string sym() const
        {
            return "-1.0-(1.049624576E9)*x^20-(8.25556992E8)*x^16+(338.0)*x^2-(4759040.0)*x^8-(2.18103808E8)*x^24+(1.13311744E9)*x^18+(4.12778496E8)*x^14-(1.41213696E8)*x^12+(3.2361472E7)*x^10+(416416.0)*x^6+33554432*x^26-(18928.0)*x^4+(6.27048448E8)*x^22";
        }

        std::string latex() const
        {
            return "-1.0-{(1.049624576E9)} x^{20}-{(8.25556992E8)} x^{16}+{(338.0)} x^{2}-{(4759040.0)} x^{8}-{(2.18103808E8)} x^{24}+{(1.13311744E9)} x^{18}+{(4.12778496E8)} x^{14}-{(1.41213696E8)} x^{12}+{(3.2361472E7)} x^{10}+{(416416.0)} x^{6}+33554432 x^{26}-{(18928.0)} x^{4}+{(6.27048448E8)} x^{22}";
        }

        Chebyshev_26* clone() const
        {
            return new Chebyshev_26(*this);
        }
    };

    class Chebyshev_27 : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return  -2.7000000000000000e+01*var+1.3589544960000000e+09*(var*(var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var)))*(var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var))))+67108864.0*(var*(var*((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))*(var*((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var))))+-2.3876075520000000e+09*(var*((var*(var*var)*(var*var))*(var*(var*var)*(var*var)))*((var*(var*var)*(var*var))*(var*(var*var)*(var*var))))+1.9768320000000000e+06*(var*(var*var*var)*(var*var*var))+-2.1180579840000000e+09*(var*(((var*var)*(var*var))*((var*var)*(var*var)))*(((var*var)*(var*var))*((var*var)*(var*var))))+-1.1793600000000000e+05*(var*(var*var)*(var*var))+1.1430789120000000e+09*(var*(var*(var*var*var)*(var*var*var))*(var*(var*var*var)*(var*var*var)))+-4.2865459200000000e+08*(var*((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))+3.2760000000000000e+03*(var*var*var)+-4.5298483200000000e+08*(var*(((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))*(((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var))))+-1.8670080000000000e+07*(var*((var*var)*(var*var))*((var*var)*(var*var)))+1.0998374400000000e+08*(var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var)))+2.7249868800000000e+09*(var*(var*((var*var)*(var*var))*((var*var)*(var*var)))*(var*((var*var)*(var*var))*((var*var)*(var*var))));
        }

    public:
        std::string csrc() const
        {
            return " -2.7000000000000000e+01*var+1.3589544960000000e+09*(var*(var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var)))*(var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var))))+67108864.0*(var*(var*((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))*(var*((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var))))+-2.3876075520000000e+09*(var*((var*(var*var)*(var*var))*(var*(var*var)*(var*var)))*((var*(var*var)*(var*var))*(var*(var*var)*(var*var))))+1.9768320000000000e+06*(var*(var*var*var)*(var*var*var))+-2.1180579840000000e+09*(var*(((var*var)*(var*var))*((var*var)*(var*var)))*(((var*var)*(var*var))*((var*var)*(var*var))))+-1.1793600000000000e+05*(var*(var*var)*(var*var))+1.1430789120000000e+09*(var*(var*(var*var*var)*(var*var*var))*(var*(var*var*var)*(var*var*var)))+-4.2865459200000000e+08*(var*((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))+3.2760000000000000e+03*(var*var*var)+-4.5298483200000000e+08*(var*(((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))*(((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var))))+-1.8670080000000000e+07*(var*((var*var)*(var*var))*((var*var)*(var*var)))+1.0998374400000000e+08*(var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var)))+2.7249868800000000e+09*(var*(var*((var*var)*(var*var))*((var*var)*(var*var)))*(var*((var*var)*(var*var))*((var*var)*(var*var))))";
        }

        std::string sym() const
        {
            return "(3276.0)*x^3+(1.143078912E9)*x^15-(4.28654592E8)*x^13+(1.09983744E8)*x^11-(4.52984832E8)*x^25-(1.867008E7)*x^9+(2.72498688E9)*x^19+67108864*x^27+(1.358954496E9)*x^23-(2.387607552E9)*x^21-(27.0)*x+(1976832.0)*x^7-(2.118057984E9)*x^17-(117936.0)*x^5";
        }

        std::string latex() const
        {
            return "{(3276.0)} x^{3}+{(1.143078912E9)} x^{15}-{(4.28654592E8)} x^{13}+{(1.09983744E8)} x^{11}-{(4.52984832E8)} x^{25}-{(1.867008E7)} x^{9}+{(2.72498688E9)} x^{19}+67108864 x^{27}+{(1.358954496E9)} x^{23}-{(2.387607552E9)} x^{21}-{(27.0)} x+{(1976832.0)} x^{7}-{(2.118057984E9)} x^{17}-{(117936.0)} x^{5}";
        }

        Chebyshev_27* clone() const
        {
            return new Chebyshev_27(*this);
        }
    };

    class Chebyshev_28 : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return  -1.2700876800000000e+09*((var*(var*var*var)*(var*var*var))*(var*(var*var*var)*(var*var*var)))+-5.3692334080000000e+09*((var*((var*var)*(var*var))*((var*var)*(var*var)))*(var*((var*var)*(var*var))*((var*var)*(var*var))))+-6.9701632000000000e+07*((var*(var*var)*(var*var))*(var*(var*var)*(var*var)))+3.6118118400000000e+08*(((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))+-6.5228800000000000e+05*((var*var*var)*(var*var*var))+2.5480000000000000e+04*((var*var)*(var*var))+-5.4022635520000000e+09*((var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var)))*(var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var))))+-9.3952409600000000e+08*((var*((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))*(var*((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var))))+3.1117148160000000e+09*((((var*var)*(var*var))*((var*var)*(var*var)))*(((var*var)*(var*var))*((var*var)*(var*var))))+6.4995983360000000e+09*(((var*(var*var)*(var*var))*(var*(var*var)*(var*var)))*((var*(var*var)*(var*var))*(var*(var*var)*(var*var))))+-3.9200000000000000e+02*(var*var)+8.7127040000000000e+06*(((var*var)*(var*var))*((var*var)*(var*var)))+2.9360128000000000e+09*((((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))*(((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var))))+134217728.0*(((var*(var*var*var)*(var*var*var))*(var*(var*var*var)*(var*var*var)))*((var*(var*var*var)*(var*var*var))*(var*(var*var*var)*(var*var*var))))+1.0000000000000000e+00;
        }

    public:
        std::string csrc() const
        {
            return " -1.2700876800000000e+09*((var*(var*var*var)*(var*var*var))*(var*(var*var*var)*(var*var*var)))+-5.3692334080000000e+09*((var*((var*var)*(var*var))*((var*var)*(var*var)))*(var*((var*var)*(var*var))*((var*var)*(var*var))))+-6.9701632000000000e+07*((var*(var*var)*(var*var))*(var*(var*var)*(var*var)))+3.6118118400000000e+08*(((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))+-6.5228800000000000e+05*((var*var*var)*(var*var*var))+2.5480000000000000e+04*((var*var)*(var*var))+-5.4022635520000000e+09*((var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var)))*(var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var))))+-9.3952409600000000e+08*((var*((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))*(var*((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var))))+3.1117148160000000e+09*((((var*var)*(var*var))*((var*var)*(var*var)))*(((var*var)*(var*var))*((var*var)*(var*var))))+6.4995983360000000e+09*(((var*(var*var)*(var*var))*(var*(var*var)*(var*var)))*((var*(var*var)*(var*var))*(var*(var*var)*(var*var))))+-3.9200000000000000e+02*(var*var)+8.7127040000000000e+06*(((var*var)*(var*var))*((var*var)*(var*var)))+2.9360128000000000e+09*((((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))*(((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var))))+134217728.0*(((var*(var*var*var)*(var*var*var))*(var*(var*var*var)*(var*var*var)))*((var*(var*var*var)*(var*var*var))*(var*(var*var*var)*(var*var*var))))+1.0000000000000000e+00";
        }

        std::string sym() const
        {
            return "1.0+(6.499598336E9)*x^20+(3.111714816E9)*x^16-(392.0)*x^2+(8712704.0)*x^8+134217728*x^28+(2.9360128E9)*x^24-(5.369233408E9)*x^18-(1.27008768E9)*x^14+(3.61181184E8)*x^12-(6.9701632E7)*x^10-(652288.0)*x^6-(9.39524096E8)*x^26+(25480.0)*x^4-(5.402263552E9)*x^22";
        }

        std::string latex() const
        {
            return "1.0+{(6.499598336E9)} x^{20}+{(3.111714816E9)} x^{16}-{(392.0)} x^{2}+{(8712704.0)} x^{8}+134217728 x^{28}+{(2.9360128E9)} x^{24}-{(5.369233408E9)} x^{18}-{(1.27008768E9)} x^{14}+{(3.61181184E8)} x^{12}-{(6.9701632E7)} x^{10}-{(652288.0)} x^{6}-{(9.39524096E8)} x^{26}+{(25480.0)} x^{4}-{(5.402263552E9)} x^{22}";
        }

        Chebyshev_28* clone() const
        {
            return new Chebyshev_28(*this);
        }
    };

    class Chebyshev_29 : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return  2.9000000000000000e+01*var+-1.2163481600000000e+10*(var*(var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var)))*(var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var))))+-1.9461570560000000e+09*(var*(var*((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))*(var*((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var))))+1.5386804224000000e+10*(var*((var*(var*var)*(var*var))*(var*(var*var)*(var*var)))*((var*(var*var)*(var*var))*(var*(var*var)*(var*var))))+-3.2814080000000000e+06*(var*(var*var*var)*(var*var*var))+8.3414876160000000e+09*(var*(((var*var)*(var*var))*((var*var)*(var*var)))*(((var*var)*(var*var))*((var*var)*(var*var))))+1.6889600000000000e+05*(var*(var*var)*(var*var))+-3.6832542720000000e+09*(var*(var*(var*var*var)*(var*var*var))*(var*(var*var*var)*(var*var*var)))+1.1510169600000000e+09*(var*((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))+-4.0600000000000000e+03*(var*var*var)+6.3250104320000000e+09*(var*(((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))*(((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var))))+3.6095488000000000e+07*(var*((var*var)*(var*var))*((var*var)*(var*var)))+268435456.0*(var*((var*(var*var*var)*(var*var*var))*(var*(var*var*var)*(var*var*var)))*((var*(var*var*var)*(var*var*var))*(var*(var*var*var)*(var*var*var))))+-2.4938700800000000e+08*(var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var)))+-1.3463453696000000e+10*(var*(var*((var*var)*(var*var))*((var*var)*(var*var)))*(var*((var*var)*(var*var))*((var*var)*(var*var))));
        }

    public:
        std::string csrc() const
        {
            return " 2.9000000000000000e+01*var+-1.2163481600000000e+10*(var*(var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var)))*(var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var))))+-1.9461570560000000e+09*(var*(var*((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))*(var*((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var))))+1.5386804224000000e+10*(var*((var*(var*var)*(var*var))*(var*(var*var)*(var*var)))*((var*(var*var)*(var*var))*(var*(var*var)*(var*var))))+-3.2814080000000000e+06*(var*(var*var*var)*(var*var*var))+8.3414876160000000e+09*(var*(((var*var)*(var*var))*((var*var)*(var*var)))*(((var*var)*(var*var))*((var*var)*(var*var))))+1.6889600000000000e+05*(var*(var*var)*(var*var))+-3.6832542720000000e+09*(var*(var*(var*var*var)*(var*var*var))*(var*(var*var*var)*(var*var*var)))+1.1510169600000000e+09*(var*((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))+-4.0600000000000000e+03*(var*var*var)+6.3250104320000000e+09*(var*(((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))*(((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var))))+3.6095488000000000e+07*(var*((var*var)*(var*var))*((var*var)*(var*var)))+268435456.0*(var*((var*(var*var*var)*(var*var*var))*(var*(var*var*var)*(var*var*var)))*((var*(var*var*var)*(var*var*var))*(var*(var*var*var)*(var*var*var))))+-2.4938700800000000e+08*(var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var)))+-1.3463453696000000e+10*(var*(var*((var*var)*(var*var))*((var*var)*(var*var)))*(var*((var*var)*(var*var))*((var*var)*(var*var))))";
        }

        std::string sym() const
        {
            return "-(4060.0)*x^3-(3.683254272E9)*x^15+(1.15101696E9)*x^13+268435456*x^29-(2.49387008E8)*x^11+(6.325010432E9)*x^25+(3.6095488E7)*x^9-(1.3463453696E10)*x^19-(1.946157056E9)*x^27-(1.21634816E10)*x^23+(1.5386804224E10)*x^21+(29.0)*x-(3281408.0)*x^7+(8.341487616E9)*x^17+(168896.0)*x^5";
        }

        std::string latex() const
        {
            return "-{(4060.0)} x^{3}-{(3.683254272E9)} x^{15}+{(1.15101696E9)} x^{13}+268435456 x^{29}-{(2.49387008E8)} x^{11}+{(6.325010432E9)} x^{25}+{(3.6095488E7)} x^{9}-{(1.3463453696E10)} x^{19}-{(1.946157056E9)} x^{27}-{(1.21634816E10)} x^{23}+{(1.5386804224E10)} x^{21}+{(29.0)} x-{(3281408.0)} x^{7}+{(8.341487616E9)} x^{17}+{(168896.0)} x^{5}";
        }

        Chebyshev_29* clone() const
        {
            return new Chebyshev_29(*this);
        }
    };

    class Chebyshev_0_grad : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return 0.0;
        }

    public:
        std::string csrc() const
        {
            return "0.0";
        }

        std::string sym() const
        {
            return "0";
        }

        std::string latex() const
        {
            return "0";
        }

        Chebyshev_0_grad* clone() const
        {
            return new Chebyshev_0_grad(*this);
        }
    };

    class Chebyshev_1_grad : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return 1.0;
        }

    public:
        std::string csrc() const
        {
            return "1.0";
        }

        std::string sym() const
        {
            return "1";
        }

        std::string latex() const
        {
            return "1";
        }

        Chebyshev_1_grad* clone() const
        {
            return new Chebyshev_1_grad(*this);
        }
    };

    class Chebyshev_2_grad : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return 4.0*var;
        }

    public:
        std::string csrc() const
        {
            return "4.0*var";
        }

        std::string sym() const
        {
            return "4*x";
        }

        std::string latex() const
        {
            return "4  x";
        }

        Chebyshev_2_grad* clone() const
        {
            return new Chebyshev_2_grad(*this);
        }
    };

    class Chebyshev_3_grad : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return  12.0*(var*var)-3.0000000000000000e+00;
        }

    public:
        std::string csrc() const
        {
            return " 12.0*(var*var)-3.0000000000000000e+00";
        }

        std::string sym() const
        {
            return "-3.0+12*x^2";
        }

        std::string latex() const
        {
            return "-3.0+12 x^{2}";
        }

        Chebyshev_3_grad* clone() const
        {
            return new Chebyshev_3_grad(*this);
        }
    };

    class Chebyshev_4_grad : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return  -1.6000000000000000e+01*var+32.0*(var*var*var);
        }

    public:
        std::string csrc() const
        {
            return " -1.6000000000000000e+01*var+32.0*(var*var*var)";
        }

        std::string sym() const
        {
            return "32*x^3-(16.0)*x";
        }

        std::string latex() const
        {
            return "32 x^{3}-{(16.0)} x";
        }

        Chebyshev_4_grad* clone() const
        {
            return new Chebyshev_4_grad(*this);
        }
    };

    class Chebyshev_5_grad : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return  80.0*((var*var)*(var*var))+-6.0000000000000000e+01*(var*var)+5.0000000000000000e+00;
        }

    public:
        std::string csrc() const
        {
            return " 80.0*((var*var)*(var*var))+-6.0000000000000000e+01*(var*var)+5.0000000000000000e+00";
        }

        std::string sym() const
        {
            return "5.0-(60.0)*x^2+80*x^4";
        }

        std::string latex() const
        {
            return "5.0-{(60.0)} x^{2}+80 x^{4}";
        }

        Chebyshev_5_grad* clone() const
        {
            return new Chebyshev_5_grad(*this);
        }
    };

    class Chebyshev_6_grad : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return  3.6000000000000000e+01*var+192.0*(var*(var*var)*(var*var))+-1.9200000000000000e+02*(var*var*var);
        }

    public:
        std::string csrc() const
        {
            return " 3.6000000000000000e+01*var+192.0*(var*(var*var)*(var*var))+-1.9200000000000000e+02*(var*var*var)";
        }

        std::string sym() const
        {
            return "-(192.0)*x^3+(36.0)*x+192*x^5";
        }

        std::string latex() const
        {
            return "-{(192.0)} x^{3}+{(36.0)} x+192 x^{5}";
        }

        Chebyshev_6_grad* clone() const
        {
            return new Chebyshev_6_grad(*this);
        }
    };

    class Chebyshev_7_grad : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return  448.0*((var*var*var)*(var*var*var))+-5.6000000000000000e+02*((var*var)*(var*var))+1.6800000000000000e+02*(var*var)-7.0000000000000000e+00;
        }

    public:
        std::string csrc() const
        {
            return " 448.0*((var*var*var)*(var*var*var))+-5.6000000000000000e+02*((var*var)*(var*var))+1.6800000000000000e+02*(var*var)-7.0000000000000000e+00";
        }

        std::string sym() const
        {
            return "-7.0+(168.0)*x^2+448*x^6-(560.0)*x^4";
        }

        std::string latex() const
        {
            return "-7.0+{(168.0)} x^{2}+448 x^{6}-{(560.0)} x^{4}";
        }

        Chebyshev_7_grad* clone() const
        {
            return new Chebyshev_7_grad(*this);
        }
    };

    class Chebyshev_8_grad : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return  -6.4000000000000000e+01*var+1024.0*(var*(var*var*var)*(var*var*var))+-1.5360000000000000e+03*(var*(var*var)*(var*var))+6.4000000000000000e+02*(var*var*var);
        }

    public:
        std::string csrc() const
        {
            return " -6.4000000000000000e+01*var+1024.0*(var*(var*var*var)*(var*var*var))+-1.5360000000000000e+03*(var*(var*var)*(var*var))+6.4000000000000000e+02*(var*var*var)";
        }

        std::string sym() const
        {
            return "(640.0)*x^3-(64.0)*x+1024*x^7-(1536.0)*x^5";
        }

        std::string latex() const
        {
            return "{(640.0)} x^{3}-{(64.0)} x+1024 x^{7}-{(1536.0)} x^{5}";
        }

        Chebyshev_8_grad* clone() const
        {
            return new Chebyshev_8_grad(*this);
        }
    };

    class Chebyshev_9_grad : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return  -4.0320000000000000e+03*((var*var*var)*(var*var*var))+2.1600000000000000e+03*((var*var)*(var*var))+-3.6000000000000000e+02*(var*var)+2304.0*(((var*var)*(var*var))*((var*var)*(var*var)))+9.0000000000000000e+00;
        }

    public:
        std::string csrc() const
        {
            return " -4.0320000000000000e+03*((var*var*var)*(var*var*var))+2.1600000000000000e+03*((var*var)*(var*var))+-3.6000000000000000e+02*(var*var)+2304.0*(((var*var)*(var*var))*((var*var)*(var*var)))+9.0000000000000000e+00";
        }

        std::string sym() const
        {
            return "9.0-(360.0)*x^2+2304*x^8-(4032.0)*x^6+(2160.0)*x^4";
        }

        std::string latex() const
        {
            return "9.0-{(360.0)} x^{2}+2304 x^{8}-{(4032.0)} x^{6}+{(2160.0)} x^{4}";
        }

        Chebyshev_9_grad* clone() const
        {
            return new Chebyshev_9_grad(*this);
        }
    };

    class Chebyshev_10_grad : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return  1.0000000000000000e+02*var+-1.0240000000000000e+04*(var*(var*var*var)*(var*var*var))+6.7200000000000000e+03*(var*(var*var)*(var*var))+-1.6000000000000000e+03*(var*var*var)+5120.0*(var*((var*var)*(var*var))*((var*var)*(var*var)));
        }

    public:
        std::string csrc() const
        {
            return " 1.0000000000000000e+02*var+-1.0240000000000000e+04*(var*(var*var*var)*(var*var*var))+6.7200000000000000e+03*(var*(var*var)*(var*var))+-1.6000000000000000e+03*(var*var*var)+5120.0*(var*((var*var)*(var*var))*((var*var)*(var*var)))";
        }

        std::string sym() const
        {
            return "-(1600.0)*x^3+5120*x^9+(100.0)*x-(10240.0)*x^7+(6720.0)*x^5";
        }

        std::string latex() const
        {
            return "-{(1600.0)} x^{3}+5120 x^{9}+{(100.0)} x-{(10240.0)} x^{7}+{(6720.0)} x^{5}";
        }

        Chebyshev_10_grad* clone() const
        {
            return new Chebyshev_10_grad(*this);
        }
    };

    class Chebyshev_11_grad : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return  11264.0*((var*(var*var)*(var*var))*(var*(var*var)*(var*var)))+1.9712000000000000e+04*((var*var*var)*(var*var*var))+-6.1600000000000000e+03*((var*var)*(var*var))+6.6000000000000000e+02*(var*var)+-2.5344000000000000e+04*(((var*var)*(var*var))*((var*var)*(var*var)))-1.1000000000000000e+01;
        }

    public:
        std::string csrc() const
        {
            return " 11264.0*((var*(var*var)*(var*var))*(var*(var*var)*(var*var)))+1.9712000000000000e+04*((var*var*var)*(var*var*var))+-6.1600000000000000e+03*((var*var)*(var*var))+6.6000000000000000e+02*(var*var)+-2.5344000000000000e+04*(((var*var)*(var*var))*((var*var)*(var*var)))-1.1000000000000000e+01";
        }

        std::string sym() const
        {
            return "-11.0+(660.0)*x^2-(25344.0)*x^8+11264*x^10+(19712.0)*x^6-(6160.0)*x^4";
        }

        std::string latex() const
        {
            return "-11.0+{(660.0)} x^{2}-{(25344.0)} x^{8}+11264 x^{10}+{(19712.0)} x^{6}-{(6160.0)} x^{4}";
        }

        Chebyshev_11_grad* clone() const
        {
            return new Chebyshev_11_grad(*this);
        }
    };

    class Chebyshev_12_grad : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return  -1.4400000000000000e+02*var+5.5296000000000000e+04*(var*(var*var*var)*(var*var*var))+-2.1504000000000000e+04*(var*(var*var)*(var*var))+3.3600000000000000e+03*(var*var*var)+-6.1440000000000000e+04*(var*((var*var)*(var*var))*((var*var)*(var*var)))+24576.0*(var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var)));
        }

    public:
        std::string csrc() const
        {
            return " -1.4400000000000000e+02*var+5.5296000000000000e+04*(var*(var*var*var)*(var*var*var))+-2.1504000000000000e+04*(var*(var*var)*(var*var))+3.3600000000000000e+03*(var*var*var)+-6.1440000000000000e+04*(var*((var*var)*(var*var))*((var*var)*(var*var)))+24576.0*(var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var)))";
        }

        std::string sym() const
        {
            return "(3360.0)*x^3+24576*x^11-(61440.0)*x^9-(144.0)*x+(55296.0)*x^7-(21504.0)*x^5";
        }

        std::string latex() const
        {
            return "{(3360.0)} x^{3}+24576 x^{11}-{(61440.0)} x^{9}-{(144.0)} x+{(55296.0)} x^{7}-{(21504.0)} x^{5}";
        }

        Chebyshev_12_grad* clone() const
        {
            return new Chebyshev_12_grad(*this);
        }
    };

    class Chebyshev_13_grad : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return  -1.4643200000000000e+05*((var*(var*var)*(var*var))*(var*(var*var)*(var*var)))+53248.0*(((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))+-6.9888000000000000e+04*((var*var*var)*(var*var*var))+1.4560000000000000e+04*((var*var)*(var*var))+-1.0920000000000000e+03*(var*var)+1.4976000000000000e+05*(((var*var)*(var*var))*((var*var)*(var*var)))+1.3000000000000000e+01;
        }

    public:
        std::string csrc() const
        {
            return " -1.4643200000000000e+05*((var*(var*var)*(var*var))*(var*(var*var)*(var*var)))+53248.0*(((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))+-6.9888000000000000e+04*((var*var*var)*(var*var*var))+1.4560000000000000e+04*((var*var)*(var*var))+-1.0920000000000000e+03*(var*var)+1.4976000000000000e+05*(((var*var)*(var*var))*((var*var)*(var*var)))+1.3000000000000000e+01";
        }

        std::string sym() const
        {
            return "13.0-(1092.0)*x^2+(149760.0)*x^8+53248*x^12-(146432.0)*x^10-(69888.0)*x^6+(14560.0)*x^4";
        }

        std::string latex() const
        {
            return "13.0-{(1092.0)} x^{2}+{(149760.0)} x^{8}+53248 x^{12}-{(146432.0)} x^{10}-{(69888.0)} x^{6}+{(14560.0)} x^{4}";
        }

        Chebyshev_13_grad* clone() const
        {
            return new Chebyshev_13_grad(*this);
        }
    };

    class Chebyshev_14_grad : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return  1.9600000000000000e+02*var+-2.1504000000000000e+05*(var*(var*var*var)*(var*var*var))+5.6448000000000000e+04*(var*(var*var)*(var*var))+114688.0*(var*((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))+-6.2720000000000000e+03*(var*var*var)+3.9424000000000000e+05*(var*((var*var)*(var*var))*((var*var)*(var*var)))+-3.4406400000000000e+05*(var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var)));
        }

    public:
        std::string csrc() const
        {
            return " 1.9600000000000000e+02*var+-2.1504000000000000e+05*(var*(var*var*var)*(var*var*var))+5.6448000000000000e+04*(var*(var*var)*(var*var))+114688.0*(var*((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))+-6.2720000000000000e+03*(var*var*var)+3.9424000000000000e+05*(var*((var*var)*(var*var))*((var*var)*(var*var)))+-3.4406400000000000e+05*(var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var)))";
        }

        std::string sym() const
        {
            return "-(6272.0)*x^3+114688*x^13-(344064.0)*x^11+(394240.0)*x^9+(196.0)*x-(215040.0)*x^7+(56448.0)*x^5";
        }

        std::string latex() const
        {
            return "-{(6272.0)} x^{3}+114688 x^{13}-{(344064.0)} x^{11}+{(394240.0)} x^{9}+{(196.0)} x-{(215040.0)} x^{7}+{(56448.0)} x^{5}";
        }

        Chebyshev_14_grad* clone() const
        {
            return new Chebyshev_14_grad(*this);
        }
    };

    class Chebyshev_15_grad : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return  245760.0*((var*(var*var*var)*(var*var*var))*(var*(var*var*var)*(var*var*var)))+1.0137600000000000e+06*((var*(var*var)*(var*var))*(var*(var*var)*(var*var)))+-7.9872000000000000e+05*(((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))+2.0160000000000000e+05*((var*var*var)*(var*var*var))+-3.0240000000000000e+04*((var*var)*(var*var))+1.6800000000000000e+03*(var*var)+-6.3360000000000000e+05*(((var*var)*(var*var))*((var*var)*(var*var)))-1.5000000000000000e+01;
        }

    public:
        std::string csrc() const
        {
            return " 245760.0*((var*(var*var*var)*(var*var*var))*(var*(var*var*var)*(var*var*var)))+1.0137600000000000e+06*((var*(var*var)*(var*var))*(var*(var*var)*(var*var)))+-7.9872000000000000e+05*(((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))+2.0160000000000000e+05*((var*var*var)*(var*var*var))+-3.0240000000000000e+04*((var*var)*(var*var))+1.6800000000000000e+03*(var*var)+-6.3360000000000000e+05*(((var*var)*(var*var))*((var*var)*(var*var)))-1.5000000000000000e+01";
        }

        std::string sym() const
        {
            return "-15.0+(1680.0)*x^2-(633600.0)*x^8+245760*x^14-(798720.0)*x^12+(1013760.0)*x^10+(201600.0)*x^6-(30240.0)*x^4";
        }

        std::string latex() const
        {
            return "-15.0+{(1680.0)} x^{2}-{(633600.0)} x^{8}+245760 x^{14}-{(798720.0)} x^{12}+{(1013760.0)} x^{10}+{(201600.0)} x^{6}-{(30240.0)} x^{4}";
        }

        Chebyshev_15_grad* clone() const
        {
            return new Chebyshev_15_grad(*this);
        }
    };

    class Chebyshev_16_grad : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return  -2.5600000000000000e+02*var+6.7584000000000000e+05*(var*(var*var*var)*(var*var*var))+-1.2902400000000000e+05*(var*(var*var)*(var*var))+524288.0*(var*(var*(var*var*var)*(var*var*var))*(var*(var*var*var)*(var*var*var)))+-1.8350080000000000e+06*(var*((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))+1.0752000000000000e+04*(var*var*var)+-1.8022400000000000e+06*(var*((var*var)*(var*var))*((var*var)*(var*var)))+2.5559040000000000e+06*(var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var)));
        }

    public:
        std::string csrc() const
        {
            return " -2.5600000000000000e+02*var+6.7584000000000000e+05*(var*(var*var*var)*(var*var*var))+-1.2902400000000000e+05*(var*(var*var)*(var*var))+524288.0*(var*(var*(var*var*var)*(var*var*var))*(var*(var*var*var)*(var*var*var)))+-1.8350080000000000e+06*(var*((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))+1.0752000000000000e+04*(var*var*var)+-1.8022400000000000e+06*(var*((var*var)*(var*var))*((var*var)*(var*var)))+2.5559040000000000e+06*(var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var)))";
        }

        std::string sym() const
        {
            return "(10752.0)*x^3+524288*x^15-(1835008.0)*x^13+(2555904.0)*x^11-(1802240.0)*x^9-(256.0)*x+(675840.0)*x^7-(129024.0)*x^5";
        }

        std::string latex() const
        {
            return "{(10752.0)} x^{3}+524288 x^{15}-{(1835008.0)} x^{13}+{(2555904.0)} x^{11}-{(1802240.0)} x^{9}-{(256.0)} x+{(675840.0)} x^{7}-{(129024.0)} x^{5}";
        }

        Chebyshev_16_grad* clone() const
        {
            return new Chebyshev_16_grad(*this);
        }
    };

    class Chebyshev_17_grad : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return  -4.1779200000000000e+06*((var*(var*var*var)*(var*var*var))*(var*(var*var*var)*(var*var*var)))+-4.9786880000000000e+06*((var*(var*var)*(var*var))*(var*(var*var)*(var*var)))+6.3365120000000000e+06*(((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))+-5.0265600000000000e+05*((var*var*var)*(var*var*var))+5.7120000000000000e+04*((var*var)*(var*var))+1114112.0*((((var*var)*(var*var))*((var*var)*(var*var)))*(((var*var)*(var*var))*((var*var)*(var*var))))+-2.4480000000000000e+03*(var*var)+2.1542400000000000e+06*(((var*var)*(var*var))*((var*var)*(var*var)))+1.7000000000000000e+01;
        }

    public:
        std::string csrc() const
        {
            return " -4.1779200000000000e+06*((var*(var*var*var)*(var*var*var))*(var*(var*var*var)*(var*var*var)))+-4.9786880000000000e+06*((var*(var*var)*(var*var))*(var*(var*var)*(var*var)))+6.3365120000000000e+06*(((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))+-5.0265600000000000e+05*((var*var*var)*(var*var*var))+5.7120000000000000e+04*((var*var)*(var*var))+1114112.0*((((var*var)*(var*var))*((var*var)*(var*var)))*(((var*var)*(var*var))*((var*var)*(var*var))))+-2.4480000000000000e+03*(var*var)+2.1542400000000000e+06*(((var*var)*(var*var))*((var*var)*(var*var)))+1.7000000000000000e+01";
        }

        std::string sym() const
        {
            return "17.0+1114112*x^16-(2448.0)*x^2+(2154240.0)*x^8-(4177920.0)*x^14+(6336512.0)*x^12-(4978688.0)*x^10-(502656.0)*x^6+(57120.0)*x^4";
        }

        std::string latex() const
        {
            return "17.0+1114112 x^{16}-{(2448.0)} x^{2}+{(2154240.0)} x^{8}-{(4177920.0)} x^{14}+{(6336512.0)} x^{12}-{(4978688.0)} x^{10}-{(502656.0)} x^{6}+{(57120.0)} x^{4}";
        }

        Chebyshev_17_grad* clone() const
        {
            return new Chebyshev_17_grad(*this);
        }
    };

    class Chebyshev_18_grad : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return  3.2400000000000000e+02*var+-1.8247680000000000e+06*(var*(var*var*var)*(var*var*var))+2359296.0*(var*(((var*var)*(var*var))*((var*var)*(var*var)))*(((var*var)*(var*var))*((var*var)*(var*var))))+2.6611200000000000e+05*(var*(var*var)*(var*var))+-9.4371840000000000e+06*(var*(var*(var*var*var)*(var*var*var))*(var*(var*var*var)*(var*var*var)))+1.5482880000000000e+07*(var*((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))+-1.7280000000000000e+04*(var*var*var)+6.5894400000000000e+06*(var*((var*var)*(var*var))*((var*var)*(var*var)))+-1.3418496000000000e+07*(var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var)));
        }

    public:
        std::string csrc() const
        {
            return " 3.2400000000000000e+02*var+-1.8247680000000000e+06*(var*(var*var*var)*(var*var*var))+2359296.0*(var*(((var*var)*(var*var))*((var*var)*(var*var)))*(((var*var)*(var*var))*((var*var)*(var*var))))+2.6611200000000000e+05*(var*(var*var)*(var*var))+-9.4371840000000000e+06*(var*(var*(var*var*var)*(var*var*var))*(var*(var*var*var)*(var*var*var)))+1.5482880000000000e+07*(var*((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))+-1.7280000000000000e+04*(var*var*var)+6.5894400000000000e+06*(var*((var*var)*(var*var))*((var*var)*(var*var)))+-1.3418496000000000e+07*(var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var)))";
        }

        std::string sym() const
        {
            return "-(17280.0)*x^3-(9437184.0)*x^15+(1.548288E7)*x^13-(1.3418496E7)*x^11+(6589440.0)*x^9+(324.0)*x-(1824768.0)*x^7+2359296*x^17+(266112.0)*x^5";
        }

        std::string latex() const
        {
            return "-{(17280.0)} x^{3}-{(9437184.0)} x^{15}+{(1.548288E7)} x^{13}-{(1.3418496E7)} x^{11}+{(6589440.0)} x^{9}+{(324.0)} x-{(1824768.0)} x^{7}+2359296 x^{17}+{(266112.0)} x^{5}";
        }

        Chebyshev_18_grad* clone() const
        {
            return new Chebyshev_18_grad(*this);
        }
    };

    class Chebyshev_19_grad : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return  3.7355520000000000e+07*((var*(var*var*var)*(var*var*var))*(var*(var*var*var)*(var*var*var)))+4980736.0*((var*((var*var)*(var*var))*((var*var)*(var*var)))*(var*((var*var)*(var*var))*((var*var)*(var*var))))+1.9475456000000000e+07*((var*(var*var)*(var*var))*(var*(var*var)*(var*var)))+-3.5409920000000000e+07*(((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))+1.1235840000000000e+06*((var*var*var)*(var*var*var))+-1.0032000000000000e+05*((var*var)*(var*var))+-2.1168128000000000e+07*((((var*var)*(var*var))*((var*var)*(var*var)))*(((var*var)*(var*var))*((var*var)*(var*var))))+3.4200000000000000e+03*(var*var)+-6.2599680000000000e+06*(((var*var)*(var*var))*((var*var)*(var*var)))-1.9000000000000000e+01;
        }

    public:
        std::string csrc() const
        {
            return " 3.7355520000000000e+07*((var*(var*var*var)*(var*var*var))*(var*(var*var*var)*(var*var*var)))+4980736.0*((var*((var*var)*(var*var))*((var*var)*(var*var)))*(var*((var*var)*(var*var))*((var*var)*(var*var))))+1.9475456000000000e+07*((var*(var*var)*(var*var))*(var*(var*var)*(var*var)))+-3.5409920000000000e+07*(((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))+1.1235840000000000e+06*((var*var*var)*(var*var*var))+-1.0032000000000000e+05*((var*var)*(var*var))+-2.1168128000000000e+07*((((var*var)*(var*var))*((var*var)*(var*var)))*(((var*var)*(var*var))*((var*var)*(var*var))))+3.4200000000000000e+03*(var*var)+-6.2599680000000000e+06*(((var*var)*(var*var))*((var*var)*(var*var)))-1.9000000000000000e+01";
        }

        std::string sym() const
        {
            return "-19.0-(2.1168128E7)*x^16+(3420.0)*x^2-(6259968.0)*x^8+4980736*x^18+(3.735552E7)*x^14-(3.540992E7)*x^12+(1.9475456E7)*x^10+(1123584.0)*x^6-(100320.0)*x^4";
        }

        std::string latex() const
        {
            return "-19.0-{(2.1168128E7)} x^{16}+{(3420.0)} x^{2}-{(6259968.0)} x^{8}+4980736 x^{18}+{(3.735552E7)} x^{14}-{(3.540992E7)} x^{12}+{(1.9475456E7)} x^{10}+{(1123584.0)} x^{6}-{(100320.0)} x^{4}";
        }

        Chebyshev_19_grad* clone() const
        {
            return new Chebyshev_19_grad(*this);
        }
    };

    class Chebyshev_20_grad : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return  -4.0000000000000000e+02*var+4.3929600000000000e+06*(var*(var*var*var)*(var*var*var))+-4.7185920000000000e+07*(var*(((var*var)*(var*var))*((var*var)*(var*var)))*(((var*var)*(var*var))*((var*var)*(var*var))))+-5.0688000000000000e+05*(var*(var*var)*(var*var))+8.9128960000000000e+07*(var*(var*(var*var*var)*(var*var*var))*(var*(var*var*var)*(var*var*var)))+-9.1750400000000000e+07*(var*((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))+2.6400000000000000e+04*(var*var*var)+-2.0500480000000000e+07*(var*((var*var)*(var*var))*((var*var)*(var*var)))+5.5910400000000000e+07*(var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var)))+10485760.0*(var*(var*((var*var)*(var*var))*((var*var)*(var*var)))*(var*((var*var)*(var*var))*((var*var)*(var*var))));
        }

    public:
        std::string csrc() const
        {
            return " -4.0000000000000000e+02*var+4.3929600000000000e+06*(var*(var*var*var)*(var*var*var))+-4.7185920000000000e+07*(var*(((var*var)*(var*var))*((var*var)*(var*var)))*(((var*var)*(var*var))*((var*var)*(var*var))))+-5.0688000000000000e+05*(var*(var*var)*(var*var))+8.9128960000000000e+07*(var*(var*(var*var*var)*(var*var*var))*(var*(var*var*var)*(var*var*var)))+-9.1750400000000000e+07*(var*((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))+2.6400000000000000e+04*(var*var*var)+-2.0500480000000000e+07*(var*((var*var)*(var*var))*((var*var)*(var*var)))+5.5910400000000000e+07*(var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var)))+10485760.0*(var*(var*((var*var)*(var*var))*((var*var)*(var*var)))*(var*((var*var)*(var*var))*((var*var)*(var*var))))";
        }

        std::string sym() const
        {
            return "(26400.0)*x^3+(8.912896E7)*x^15-(9.17504E7)*x^13+(5.59104E7)*x^11-(2.050048E7)*x^9+10485760*x^19-(400.0)*x+(4392960.0)*x^7-(4.718592E7)*x^17-(506880.0)*x^5";
        }

        std::string latex() const
        {
            return "{(26400.0)} x^{3}+{(8.912896E7)} x^{15}-{(9.17504E7)} x^{13}+{(5.59104E7)} x^{11}-{(2.050048E7)} x^{9}+10485760 x^{19}-{(400.0)} x+{(4392960.0)} x^{7}-{(4.718592E7)} x^{17}-{(506880.0)} x^{5}";
        }

        Chebyshev_20_grad* clone() const
        {
            return new Chebyshev_20_grad(*this);
        }
    };

    class Chebyshev_21_grad : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return  -2.3396352000000000e+08*((var*(var*var*var)*(var*var*var))*(var*(var*var*var)*(var*var*var)))+-1.0459545600000000e+08*((var*((var*var)*(var*var))*((var*var)*(var*var)))*(var*((var*var)*(var*var))*((var*var)*(var*var))))+-6.4576512000000000e+07*((var*(var*var)*(var*var))*(var*(var*var)*(var*var)))+1.5654912000000000e+08*(((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))+-2.3063040000000000e+06*((var*var*var)*(var*var*var))+1.6632000000000000e+05*((var*var)*(var*var))+2.1056716800000000e+08*((((var*var)*(var*var))*((var*var)*(var*var)))*(((var*var)*(var*var))*((var*var)*(var*var))))+22020096.0*(((var*(var*var)*(var*var))*(var*(var*var)*(var*var)))*((var*(var*var)*(var*var))*(var*(var*var)*(var*var))))+-4.6200000000000000e+03*(var*var)+1.6144128000000000e+07*(((var*var)*(var*var))*((var*var)*(var*var)))+2.1000000000000000e+01;
        }

    public:
        std::string csrc() const
        {
            return " -2.3396352000000000e+08*((var*(var*var*var)*(var*var*var))*(var*(var*var*var)*(var*var*var)))+-1.0459545600000000e+08*((var*((var*var)*(var*var))*((var*var)*(var*var)))*(var*((var*var)*(var*var))*((var*var)*(var*var))))+-6.4576512000000000e+07*((var*(var*var)*(var*var))*(var*(var*var)*(var*var)))+1.5654912000000000e+08*(((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))+-2.3063040000000000e+06*((var*var*var)*(var*var*var))+1.6632000000000000e+05*((var*var)*(var*var))+2.1056716800000000e+08*((((var*var)*(var*var))*((var*var)*(var*var)))*(((var*var)*(var*var))*((var*var)*(var*var))))+22020096.0*(((var*(var*var)*(var*var))*(var*(var*var)*(var*var)))*((var*(var*var)*(var*var))*(var*(var*var)*(var*var))))+-4.6200000000000000e+03*(var*var)+1.6144128000000000e+07*(((var*var)*(var*var))*((var*var)*(var*var)))+2.1000000000000000e+01";
        }

        std::string sym() const
        {
            return "21.0+22020096*x^20+(2.10567168E8)*x^16-(4620.0)*x^2+(1.6144128E7)*x^8-(1.04595456E8)*x^18-(2.3396352E8)*x^14+(1.5654912E8)*x^12-(6.4576512E7)*x^10-(2306304.0)*x^6+(166320.0)*x^4";
        }

        std::string latex() const
        {
            return "21.0+22020096 x^{20}+{(2.10567168E8)} x^{16}-{(4620.0)} x^{2}+{(1.6144128E7)} x^{8}-{(1.04595456E8)} x^{18}-{(2.3396352E8)} x^{14}+{(1.5654912E8)} x^{12}-{(6.4576512E7)} x^{10}-{(2306304.0)} x^{6}+{(166320.0)} x^{4}";
        }

        Chebyshev_21_grad* clone() const
        {
            return new Chebyshev_21_grad(*this);
        }
    };

    class Chebyshev_22_grad : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return  4.8400000000000000e+02*var+46137344.0*(var*((var*(var*var)*(var*var))*(var*(var*var)*(var*var)))*((var*(var*var)*(var*var))*(var*(var*var)*(var*var))))+-9.6645120000000000e+06*(var*(var*var*var)*(var*var*var))+4.9309286400000000e+08*(var*(((var*var)*(var*var))*((var*var)*(var*var)))*(((var*var)*(var*var))*((var*var)*(var*var))))+9.0604800000000000e+05*(var*(var*var)*(var*var))+-5.8825113600000000e+08*(var*(var*(var*var*var)*(var*var*var))*(var*(var*var*var)*(var*var*var)))+4.2893312000000000e+08*(var*((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))+-3.8720000000000000e+04*(var*var*var)+5.6376320000000000e+07*(var*((var*var)*(var*var))*((var*var)*(var*var)))+-1.9680460800000000e+08*(var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var)))+-2.3068672000000000e+08*(var*(var*((var*var)*(var*var))*((var*var)*(var*var)))*(var*((var*var)*(var*var))*((var*var)*(var*var))));
        }

    public:
        std::string csrc() const
        {
            return " 4.8400000000000000e+02*var+46137344.0*(var*((var*(var*var)*(var*var))*(var*(var*var)*(var*var)))*((var*(var*var)*(var*var))*(var*(var*var)*(var*var))))+-9.6645120000000000e+06*(var*(var*var*var)*(var*var*var))+4.9309286400000000e+08*(var*(((var*var)*(var*var))*((var*var)*(var*var)))*(((var*var)*(var*var))*((var*var)*(var*var))))+9.0604800000000000e+05*(var*(var*var)*(var*var))+-5.8825113600000000e+08*(var*(var*(var*var*var)*(var*var*var))*(var*(var*var*var)*(var*var*var)))+4.2893312000000000e+08*(var*((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))+-3.8720000000000000e+04*(var*var*var)+5.6376320000000000e+07*(var*((var*var)*(var*var))*((var*var)*(var*var)))+-1.9680460800000000e+08*(var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var)))+-2.3068672000000000e+08*(var*(var*((var*var)*(var*var))*((var*var)*(var*var)))*(var*((var*var)*(var*var))*((var*var)*(var*var))))";
        }

        std::string sym() const
        {
            return "-(38720.0)*x^3-(5.88251136E8)*x^15+(4.2893312E8)*x^13-(1.96804608E8)*x^11+(5.637632E7)*x^9-(2.3068672E8)*x^19+46137344*x^21+(484.0)*x-(9664512.0)*x^7+(4.93092864E8)*x^17+(906048.0)*x^5";
        }

        std::string latex() const
        {
            return "-{(38720.0)} x^{3}-{(5.88251136E8)} x^{15}+{(4.2893312E8)} x^{13}-{(1.96804608E8)} x^{11}+{(5.637632E7)} x^{9}-{(2.3068672E8)} x^{19}+46137344 x^{21}+{(484.0)} x-{(9664512.0)} x^{7}+{(4.93092864E8)} x^{17}+{(906048.0)} x^{5}";
        }

        Chebyshev_22_grad* clone() const
        {
            return new Chebyshev_22_grad(*this);
        }
    };

    class Chebyshev_23_grad : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return  1.1531059200000000e+09*((var*(var*var*var)*(var*var*var))*(var*(var*var*var)*(var*var*var)))+1.1455692800000000e+09*((var*((var*var)*(var*var))*((var*var)*(var*var)))*(var*((var*var)*(var*var))*((var*var)*(var*var))))+1.8860441600000000e+08*((var*(var*var)*(var*var))*(var*(var*var)*(var*var)))+-5.8295910400000000e+08*(((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))+4.4204160000000000e+06*((var*var*var)*(var*var*var))+-2.6312000000000000e+05*((var*var)*(var*var))+96468992.0*((var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var)))*(var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var))))+-1.4606008320000000e+09*((((var*var)*(var*var))*((var*var)*(var*var)))*(((var*var)*(var*var))*((var*var)*(var*var))))+-5.0646220800000000e+08*(((var*(var*var)*(var*var))*(var*(var*var)*(var*var)))*((var*(var*var)*(var*var))*(var*(var*var)*(var*var))))+6.0720000000000000e+03*(var*var)+-3.7889280000000000e+07*(((var*var)*(var*var))*((var*var)*(var*var)))-2.3000000000000000e+01;
        }

    public:
        std::string csrc() const
        {
            return " 1.1531059200000000e+09*((var*(var*var*var)*(var*var*var))*(var*(var*var*var)*(var*var*var)))+1.1455692800000000e+09*((var*((var*var)*(var*var))*((var*var)*(var*var)))*(var*((var*var)*(var*var))*((var*var)*(var*var))))+1.8860441600000000e+08*((var*(var*var)*(var*var))*(var*(var*var)*(var*var)))+-5.8295910400000000e+08*(((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))+4.4204160000000000e+06*((var*var*var)*(var*var*var))+-2.6312000000000000e+05*((var*var)*(var*var))+96468992.0*((var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var)))*(var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var))))+-1.4606008320000000e+09*((((var*var)*(var*var))*((var*var)*(var*var)))*(((var*var)*(var*var))*((var*var)*(var*var))))+-5.0646220800000000e+08*(((var*(var*var)*(var*var))*(var*(var*var)*(var*var)))*((var*(var*var)*(var*var))*(var*(var*var)*(var*var))))+6.0720000000000000e+03*(var*var)+-3.7889280000000000e+07*(((var*var)*(var*var))*((var*var)*(var*var)))-2.3000000000000000e+01";
        }

        std::string sym() const
        {
            return "-23.0-(5.06462208E8)*x^20-(1.460600832E9)*x^16+(6072.0)*x^2-(3.788928E7)*x^8+(1.14556928E9)*x^18+(1.15310592E9)*x^14-(5.82959104E8)*x^12+(1.88604416E8)*x^10+(4420416.0)*x^6-(263120.0)*x^4+96468992*x^22";
        }

        std::string latex() const
        {
            return "-23.0-{(5.06462208E8)} x^{20}-{(1.460600832E9)} x^{16}+{(6072.0)} x^{2}-{(3.788928E7)} x^{8}+{(1.14556928E9)} x^{18}+{(1.15310592E9)} x^{14}-{(5.82959104E8)} x^{12}+{(1.88604416E8)} x^{10}+{(4420416.0)} x^{6}-{(263120.0)} x^{4}+96468992 x^{22}";
        }

        Chebyshev_23_grad* clone() const
        {
            return new Chebyshev_23_grad(*this);
        }
    };

    class Chebyshev_24_grad : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return  -5.7600000000000000e+02*var+201326592.0*(var*(var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var)))*(var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var))))+-1.1072962560000000e+09*(var*((var*(var*var)*(var*var))*(var*(var*var)*(var*var)))*((var*(var*var)*(var*var))*(var*(var*var)*(var*var))))+1.9768320000000000e+07*(var*(var*var*var)*(var*var*var))+-3.5861299200000000e+09*(var*(((var*var)*(var*var))*((var*var)*(var*var)))*(((var*var)*(var*var))*((var*var)*(var*var))))+-1.5375360000000000e+06*(var*(var*var)*(var*var))+3.0482104320000000e+09*(var*(var*(var*var*var)*(var*var*var))*(var*(var*var*var)*(var*var*var)))+-1.6845373440000000e+09*(var*((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))+5.4912000000000000e+04*(var*var*var)+-1.4057472000000000e+08*(var*((var*var)*(var*var))*((var*var)*(var*var)))+6.0830515200000000e+08*(var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var)))+2.6424115200000000e+09*(var*(var*((var*var)*(var*var))*((var*var)*(var*var)))*(var*((var*var)*(var*var))*((var*var)*(var*var))));
        }

    public:
        std::string csrc() const
        {
            return " -5.7600000000000000e+02*var+201326592.0*(var*(var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var)))*(var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var))))+-1.1072962560000000e+09*(var*((var*(var*var)*(var*var))*(var*(var*var)*(var*var)))*((var*(var*var)*(var*var))*(var*(var*var)*(var*var))))+1.9768320000000000e+07*(var*(var*var*var)*(var*var*var))+-3.5861299200000000e+09*(var*(((var*var)*(var*var))*((var*var)*(var*var)))*(((var*var)*(var*var))*((var*var)*(var*var))))+-1.5375360000000000e+06*(var*(var*var)*(var*var))+3.0482104320000000e+09*(var*(var*(var*var*var)*(var*var*var))*(var*(var*var*var)*(var*var*var)))+-1.6845373440000000e+09*(var*((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))+5.4912000000000000e+04*(var*var*var)+-1.4057472000000000e+08*(var*((var*var)*(var*var))*((var*var)*(var*var)))+6.0830515200000000e+08*(var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var)))+2.6424115200000000e+09*(var*(var*((var*var)*(var*var))*((var*var)*(var*var)))*(var*((var*var)*(var*var))*((var*var)*(var*var))))";
        }

        std::string sym() const
        {
            return "(54912.0)*x^3+(3.048210432E9)*x^15-(1.684537344E9)*x^13+(6.08305152E8)*x^11-(1.4057472E8)*x^9+(2.64241152E9)*x^19+201326592*x^23-(1.107296256E9)*x^21-(576.0)*x+(1.976832E7)*x^7-(3.58612992E9)*x^17-(1537536.0)*x^5";
        }

        std::string latex() const
        {
            return "{(54912.0)} x^{3}+{(3.048210432E9)} x^{15}-{(1.684537344E9)} x^{13}+{(6.08305152E8)} x^{11}-{(1.4057472E8)} x^{9}+{(2.64241152E9)} x^{19}+201326592 x^{23}-{(1.107296256E9)} x^{21}-{(576.0)} x+{(1.976832E7)} x^{7}-{(3.58612992E9)} x^{17}-{(1537536.0)} x^{5}";
        }

        Chebyshev_24_grad* clone() const
        {
            return new Chebyshev_24_grad(*this);
        }
    };

    class Chebyshev_25_grad : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return  -4.7628288000000000e+09*((var*(var*var*var)*(var*var*var))*(var*(var*var*var)*(var*var*var)))+-8.7162880000000000e+09*((var*((var*var)*(var*var))*((var*var)*(var*var)))*(var*((var*var)*(var*var))*((var*var)*(var*var))))+-4.9786880000000000e+08*((var*(var*var)*(var*var))*(var*(var*var)*(var*var)))+1.9009536000000000e+09*(((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))+-8.0080000000000000e+06*((var*var*var)*(var*var*var))+4.0040000000000000e+05*((var*var)*(var*var))+-2.4117248000000000e+09*((var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var)))*(var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var))))+7.9380480000000000e+09*((((var*var)*(var*var))*((var*var)*(var*var)))*(((var*var)*(var*var))*((var*var)*(var*var))))+6.0555264000000000e+09*(((var*(var*var)*(var*var))*(var*(var*var)*(var*var)))*((var*(var*var)*(var*var))*(var*(var*var)*(var*var))))+-7.8000000000000000e+03*(var*var)+8.2368000000000000e+07*(((var*var)*(var*var))*((var*var)*(var*var)))+419430400.0*((((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))*(((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var))))+2.5000000000000000e+01;
        }

    public:
        std::string csrc() const
        {
            return " -4.7628288000000000e+09*((var*(var*var*var)*(var*var*var))*(var*(var*var*var)*(var*var*var)))+-8.7162880000000000e+09*((var*((var*var)*(var*var))*((var*var)*(var*var)))*(var*((var*var)*(var*var))*((var*var)*(var*var))))+-4.9786880000000000e+08*((var*(var*var)*(var*var))*(var*(var*var)*(var*var)))+1.9009536000000000e+09*(((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))+-8.0080000000000000e+06*((var*var*var)*(var*var*var))+4.0040000000000000e+05*((var*var)*(var*var))+-2.4117248000000000e+09*((var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var)))*(var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var))))+7.9380480000000000e+09*((((var*var)*(var*var))*((var*var)*(var*var)))*(((var*var)*(var*var))*((var*var)*(var*var))))+6.0555264000000000e+09*(((var*(var*var)*(var*var))*(var*(var*var)*(var*var)))*((var*(var*var)*(var*var))*(var*(var*var)*(var*var))))+-7.8000000000000000e+03*(var*var)+8.2368000000000000e+07*(((var*var)*(var*var))*((var*var)*(var*var)))+419430400.0*((((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))*(((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var))))+2.5000000000000000e+01";
        }

        std::string sym() const
        {
            return "25.0+(6.0555264E9)*x^20+(7.938048E9)*x^16-(7800.0)*x^2+(8.2368E7)*x^8+419430400*x^24-(8.716288E9)*x^18-(4.7628288E9)*x^14+(1.9009536E9)*x^12-(4.978688E8)*x^10-(8008000.0)*x^6+(400400.0)*x^4-(2.4117248E9)*x^22";
        }

        std::string latex() const
        {
            return "25.0+{(6.0555264E9)} x^{20}+{(7.938048E9)} x^{16}-{(7800.0)} x^{2}+{(8.2368E7)} x^{8}+419430400 x^{24}-{(8.716288E9)} x^{18}-{(4.7628288E9)} x^{14}+{(1.9009536E9)} x^{12}-{(4.978688E8)} x^{10}-{(8008000.0)} x^{6}+{(400400.0)} x^{4}-{(2.4117248E9)} x^{22}";
        }

        Chebyshev_25_grad* clone() const
        {
            return new Chebyshev_25_grad(*this);
        }
    };

    class Chebyshev_26_grad : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return  6.7600000000000000e+02*var+-5.2344913920000000e+09*(var*(var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var)))*(var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var))))+1.3795065856000000e+10*(var*((var*(var*var)*(var*var))*(var*(var*var)*(var*var)))*((var*(var*var)*(var*var))*(var*(var*var)*(var*var))))+-3.8072320000000000e+07*(var*(var*var*var)*(var*var*var))+2.0396113920000000e+10*(var*(((var*var)*(var*var))*((var*var)*(var*var)))*(((var*var)*(var*var))*((var*var)*(var*var))))+2.4984960000000000e+06*(var*(var*var)*(var*var))+-1.3208911872000000e+10*(var*(var*(var*var*var)*(var*var*var))*(var*(var*var*var)*(var*var*var)))+5.7788989440000000e+09*(var*((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))+-7.5712000000000000e+04*(var*var*var)+8.7241523200000000e+08*(var*(((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))*(((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var))))+3.2361472000000000e+08*(var*((var*var)*(var*var))*((var*var)*(var*var)))+-1.6945643520000000e+09*(var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var)))+-2.0992491520000000e+10*(var*(var*((var*var)*(var*var))*((var*var)*(var*var)))*(var*((var*var)*(var*var))*((var*var)*(var*var))));
        }

    public:
        std::string csrc() const
        {
            return " 6.7600000000000000e+02*var+-5.2344913920000000e+09*(var*(var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var)))*(var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var))))+1.3795065856000000e+10*(var*((var*(var*var)*(var*var))*(var*(var*var)*(var*var)))*((var*(var*var)*(var*var))*(var*(var*var)*(var*var))))+-3.8072320000000000e+07*(var*(var*var*var)*(var*var*var))+2.0396113920000000e+10*(var*(((var*var)*(var*var))*((var*var)*(var*var)))*(((var*var)*(var*var))*((var*var)*(var*var))))+2.4984960000000000e+06*(var*(var*var)*(var*var))+-1.3208911872000000e+10*(var*(var*(var*var*var)*(var*var*var))*(var*(var*var*var)*(var*var*var)))+5.7788989440000000e+09*(var*((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))+-7.5712000000000000e+04*(var*var*var)+8.7241523200000000e+08*(var*(((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))*(((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var))))+3.2361472000000000e+08*(var*((var*var)*(var*var))*((var*var)*(var*var)))+-1.6945643520000000e+09*(var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var)))+-2.0992491520000000e+10*(var*(var*((var*var)*(var*var))*((var*var)*(var*var)))*(var*((var*var)*(var*var))*((var*var)*(var*var))))";
        }

        std::string sym() const
        {
            return "-(75712.0)*x^3-(1.3208911872E10)*x^15+(5.778898944E9)*x^13-(1.694564352E9)*x^11+872415232*x^25+(3.2361472E8)*x^9-(2.099249152E10)*x^19-(5.234491392E9)*x^23+(1.3795065856E10)*x^21+(676.0)*x-(3.807232E7)*x^7+(2.039611392E10)*x^17+(2498496.0)*x^5";
        }

        std::string latex() const
        {
            return "-{(75712.0)} x^{3}-{(1.3208911872E10)} x^{15}+{(5.778898944E9)} x^{13}-{(1.694564352E9)} x^{11}+872415232 x^{25}+{(3.2361472E8)} x^{9}-{(2.099249152E10)} x^{19}-{(5.234491392E9)} x^{23}+{(1.3795065856E10)} x^{21}+{(676.0)} x-{(3.807232E7)} x^{7}+{(2.039611392E10)} x^{17}+{(2498496.0)} x^{5}";
        }

        Chebyshev_26_grad* clone() const
        {
            return new Chebyshev_26_grad(*this);
        }
    };

    class Chebyshev_27_grad : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return  1.7146183680000000e+10*((var*(var*var*var)*(var*var*var))*(var*(var*var*var)*(var*var*var)))+5.1774750720000000e+10*((var*((var*var)*(var*var))*((var*var)*(var*var)))*(var*((var*var)*(var*var))*((var*var)*(var*var))))+1.2098211840000000e+09*((var*(var*var)*(var*var))*(var*(var*var)*(var*var)))+-5.5725096960000000e+09*(((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))+1.3837824000000000e+07*((var*var*var)*(var*var*var))+-5.8968000000000000e+05*((var*var)*(var*var))+3.1255953408000000e+10*((var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var)))*(var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var))))+1.8119393280000000e+09*((var*((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))*(var*((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var))))+-3.6006985728000000e+10*((((var*var)*(var*var))*((var*var)*(var*var)))*(((var*var)*(var*var))*((var*var)*(var*var))))+-5.0139758592000000e+10*(((var*(var*var)*(var*var))*(var*(var*var)*(var*var)))*((var*(var*var)*(var*var))*(var*(var*var)*(var*var))))+9.8280000000000000e+03*(var*var)+-1.6803072000000000e+08*(((var*var)*(var*var))*((var*var)*(var*var)))+-1.1324620800000000e+10*((((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))*(((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var))))-2.7000000000000000e+01;
        }

    public:
        std::string csrc() const
        {
            return " 1.7146183680000000e+10*((var*(var*var*var)*(var*var*var))*(var*(var*var*var)*(var*var*var)))+5.1774750720000000e+10*((var*((var*var)*(var*var))*((var*var)*(var*var)))*(var*((var*var)*(var*var))*((var*var)*(var*var))))+1.2098211840000000e+09*((var*(var*var)*(var*var))*(var*(var*var)*(var*var)))+-5.5725096960000000e+09*(((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))+1.3837824000000000e+07*((var*var*var)*(var*var*var))+-5.8968000000000000e+05*((var*var)*(var*var))+3.1255953408000000e+10*((var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var)))*(var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var))))+1.8119393280000000e+09*((var*((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))*(var*((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var))))+-3.6006985728000000e+10*((((var*var)*(var*var))*((var*var)*(var*var)))*(((var*var)*(var*var))*((var*var)*(var*var))))+-5.0139758592000000e+10*(((var*(var*var)*(var*var))*(var*(var*var)*(var*var)))*((var*(var*var)*(var*var))*(var*(var*var)*(var*var))))+9.8280000000000000e+03*(var*var)+-1.6803072000000000e+08*(((var*var)*(var*var))*((var*var)*(var*var)))+-1.1324620800000000e+10*((((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))*(((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var))))-2.7000000000000000e+01";
        }

        std::string sym() const
        {
            return "-27.0-(5.0139758592E10)*x^20-(3.6006985728E10)*x^16+(9828.0)*x^2-(1.6803072E8)*x^8-(1.13246208E10)*x^24+(5.177475072E10)*x^18+(1.714618368E10)*x^14-(5.572509696E9)*x^12+(1.209821184E9)*x^10+(1.3837824E7)*x^6+1811939328*x^26-(589680.0)*x^4+(3.1255953408E10)*x^22";
        }

        std::string latex() const
        {
            return "-27.0-{(5.0139758592E10)} x^{20}-{(3.6006985728E10)} x^{16}+{(9828.0)} x^{2}-{(1.6803072E8)} x^{8}-{(1.13246208E10)} x^{24}+{(5.177475072E10)} x^{18}+{(1.714618368E10)} x^{14}-{(5.572509696E9)} x^{12}+{(1.209821184E9)} x^{10}+{(1.3837824E7)} x^{6}+1811939328 x^{26}-{(589680.0)} x^{4}+{(3.1255953408E10)} x^{22}";
        }

        Chebyshev_27_grad* clone() const
        {
            return new Chebyshev_27_grad(*this);
        }
    };

    class Chebyshev_28_grad : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return  -7.8400000000000000e+02*var+7.0464307200000000e+10*(var*(var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var)))*(var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var))))+3.7580963840000000e+09*(var*(var*((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))*(var*((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var))))+-1.1884979814400000e+11*(var*((var*(var*var)*(var*var))*(var*(var*var)*(var*var)))*((var*(var*var)*(var*var))*(var*(var*var)*(var*var))))+6.9701632000000000e+07*(var*(var*var*var)*(var*var*var))+-9.6646201344000000e+10*(var*(((var*var)*(var*var))*((var*var)*(var*var)))*(((var*var)*(var*var))*((var*var)*(var*var))))+-3.9137280000000000e+06*(var*(var*var)*(var*var))+4.9787437056000000e+10*(var*(var*(var*var*var)*(var*var*var))*(var*(var*var*var)*(var*var*var)))+-1.7781227520000000e+10*(var*((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))+1.0192000000000000e+05*(var*var*var)+-2.4427626496000000e+10*(var*(((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))*(((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var))))+-6.9701632000000000e+08*(var*((var*var)*(var*var))*((var*var)*(var*var)))+4.3341742080000000e+09*(var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var)))+1.2999196672000000e+11*(var*(var*((var*var)*(var*var))*((var*var)*(var*var)))*(var*((var*var)*(var*var))*((var*var)*(var*var))));
        }

    public:
        std::string csrc() const
        {
            return " -7.8400000000000000e+02*var+7.0464307200000000e+10*(var*(var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var)))*(var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var))))+3.7580963840000000e+09*(var*(var*((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))*(var*((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var))))+-1.1884979814400000e+11*(var*((var*(var*var)*(var*var))*(var*(var*var)*(var*var)))*((var*(var*var)*(var*var))*(var*(var*var)*(var*var))))+6.9701632000000000e+07*(var*(var*var*var)*(var*var*var))+-9.6646201344000000e+10*(var*(((var*var)*(var*var))*((var*var)*(var*var)))*(((var*var)*(var*var))*((var*var)*(var*var))))+-3.9137280000000000e+06*(var*(var*var)*(var*var))+4.9787437056000000e+10*(var*(var*(var*var*var)*(var*var*var))*(var*(var*var*var)*(var*var*var)))+-1.7781227520000000e+10*(var*((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))+1.0192000000000000e+05*(var*var*var)+-2.4427626496000000e+10*(var*(((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))*(((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var))))+-6.9701632000000000e+08*(var*((var*var)*(var*var))*((var*var)*(var*var)))+4.3341742080000000e+09*(var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var)))+1.2999196672000000e+11*(var*(var*((var*var)*(var*var))*((var*var)*(var*var)))*(var*((var*var)*(var*var))*((var*var)*(var*var))))";
        }

        std::string sym() const
        {
            return "(101920.0)*x^3+(4.9787437056E10)*x^15-(1.778122752E10)*x^13+(4.334174208E9)*x^11-(2.4427626496E10)*x^25-(6.9701632E8)*x^9+(1.2999196672E11)*x^19+3758096384*x^27+(7.04643072E10)*x^23-(1.18849798144E11)*x^21-(784.0)*x+(6.9701632E7)*x^7-(9.6646201344E10)*x^17-(3913728.0)*x^5";
        }

        std::string latex() const
        {
            return "{(101920.0)} x^{3}+{(4.9787437056E10)} x^{15}-{(1.778122752E10)} x^{13}+{(4.334174208E9)} x^{11}-{(2.4427626496E10)} x^{25}-{(6.9701632E8)} x^{9}+{(1.2999196672E11)} x^{19}+3758096384 x^{27}+{(7.04643072E10)} x^{23}-{(1.18849798144E11)} x^{21}-{(784.0)} x+{(6.9701632E7)} x^{7}-{(9.6646201344E10)} x^{17}-{(3913728.0)} x^{5}";
        }

        Chebyshev_28_grad* clone() const
        {
            return new Chebyshev_28_grad(*this);
        }
    };

    class Chebyshev_29_grad : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return  -5.5248814080000000e+10*((var*(var*var*var)*(var*var*var))*(var*(var*var*var)*(var*var*var)))+-2.5580562022400000e+11*((var*((var*var)*(var*var))*((var*var)*(var*var)))*(var*((var*var)*(var*var))*((var*var)*(var*var))))+-2.7432570880000000e+09*((var*(var*var)*(var*var))*(var*(var*var)*(var*var)))+1.4963220480000000e+10*(((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))+-2.2969856000000000e+07*((var*var*var)*(var*var*var))+8.4448000000000000e+05*((var*var)*(var*var))+-2.7976007680000000e+11*((var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var)))*(var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var))))+-5.2546240512000000e+10*((var*((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))*(var*((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var))))+1.4180528947200000e+11*((((var*var)*(var*var))*((var*var)*(var*var)))*(((var*var)*(var*var))*((var*var)*(var*var))))+3.2312288870400000e+11*(((var*(var*var)*(var*var))*(var*(var*var)*(var*var)))*((var*(var*var)*(var*var))*(var*(var*var)*(var*var))))+-1.2180000000000000e+04*(var*var)+3.2485939200000000e+08*(((var*var)*(var*var))*((var*var)*(var*var)))+1.5812526080000000e+11*((((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))*(((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var))))+7.7846282240000000e+09*(((var*(var*var*var)*(var*var*var))*(var*(var*var*var)*(var*var*var)))*((var*(var*var*var)*(var*var*var))*(var*(var*var*var)*(var*var*var))))+2.9000000000000000e+01;
        }

    public:
        std::string csrc() const
        {
            return " -5.5248814080000000e+10*((var*(var*var*var)*(var*var*var))*(var*(var*var*var)*(var*var*var)))+-2.5580562022400000e+11*((var*((var*var)*(var*var))*((var*var)*(var*var)))*(var*((var*var)*(var*var))*((var*var)*(var*var))))+-2.7432570880000000e+09*((var*(var*var)*(var*var))*(var*(var*var)*(var*var)))+1.4963220480000000e+10*(((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))+-2.2969856000000000e+07*((var*var*var)*(var*var*var))+8.4448000000000000e+05*((var*var)*(var*var))+-2.7976007680000000e+11*((var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var)))*(var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var))))+-5.2546240512000000e+10*((var*((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))*(var*((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var))))+1.4180528947200000e+11*((((var*var)*(var*var))*((var*var)*(var*var)))*(((var*var)*(var*var))*((var*var)*(var*var))))+3.2312288870400000e+11*(((var*(var*var)*(var*var))*(var*(var*var)*(var*var)))*((var*(var*var)*(var*var))*(var*(var*var)*(var*var))))+-1.2180000000000000e+04*(var*var)+3.2485939200000000e+08*(((var*var)*(var*var))*((var*var)*(var*var)))+1.5812526080000000e+11*((((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))*(((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var))))+7.7846282240000000e+09*(((var*(var*var*var)*(var*var*var))*(var*(var*var*var)*(var*var*var)))*((var*(var*var*var)*(var*var*var))*(var*(var*var*var)*(var*var*var))))+2.9000000000000000e+01";
        }

        std::string sym() const
        {
            return "29.0+(3.23122888704E11)*x^20+(1.41805289472E11)*x^16-(12180.0)*x^2+(3.24859392E8)*x^8+7784628224*x^28+(1.581252608E11)*x^24-(2.55805620224E11)*x^18-(5.524881408E10)*x^14+(1.496322048E10)*x^12-(2.743257088E9)*x^10-(2.2969856E7)*x^6-(5.2546240512E10)*x^26+(844480.0)*x^4-(2.797600768E11)*x^22";
        }

        std::string latex() const
        {
            return "29.0+{(3.23122888704E11)} x^{20}+{(1.41805289472E11)} x^{16}-{(12180.0)} x^{2}+{(3.24859392E8)} x^{8}+7784628224 x^{28}+{(1.581252608E11)} x^{24}-{(2.55805620224E11)} x^{18}-{(5.524881408E10)} x^{14}+{(1.496322048E10)} x^{12}-{(2.743257088E9)} x^{10}-{(2.2969856E7)} x^{6}-{(5.2546240512E10)} x^{26}+{(844480.0)} x^{4}-{(2.797600768E11)} x^{22}";
        }

        Chebyshev_29_grad* clone() const
        {
            return new Chebyshev_29_grad(*this);
        }
    };

    class Chebyshev_0_hess : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return 0.0;
        }

    public:
        std::string csrc() const
        {
            return "0.0";
        }

        std::string sym() const
        {
            return "0";
        }

        std::string latex() const
        {
            return "0";
        }

        Chebyshev_0_hess* clone() const
        {
            return new Chebyshev_0_hess(*this);
        }
    };

    class Chebyshev_1_hess : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return 0.0;
        }

    public:
        std::string csrc() const
        {
            return "0.0";
        }

        std::string sym() const
        {
            return "0";
        }

        std::string latex() const
        {
            return "0";
        }

        Chebyshev_1_hess* clone() const
        {
            return new Chebyshev_1_hess(*this);
        }
    };

    class Chebyshev_2_hess : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return 4.0;
        }

    public:
        std::string csrc() const
        {
            return "4.0";
        }

        std::string sym() const
        {
            return "4";
        }

        std::string latex() const
        {
            return "4";
        }

        Chebyshev_2_hess* clone() const
        {
            return new Chebyshev_2_hess(*this);
        }
    };

    class Chebyshev_3_hess : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return 24.0*var;
        }

    public:
        std::string csrc() const
        {
            return "24.0*var";
        }

        std::string sym() const
        {
            return "24*x";
        }

        std::string latex() const
        {
            return "24  x";
        }

        Chebyshev_3_hess* clone() const
        {
            return new Chebyshev_3_hess(*this);
        }
    };

    class Chebyshev_4_hess : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return  96.0*(var*var)-1.6000000000000000e+01;
        }

    public:
        std::string csrc() const
        {
            return " 96.0*(var*var)-1.6000000000000000e+01";
        }

        std::string sym() const
        {
            return "-16.0+96*x^2";
        }

        std::string latex() const
        {
            return "-16.0+96 x^{2}";
        }

        Chebyshev_4_hess* clone() const
        {
            return new Chebyshev_4_hess(*this);
        }
    };

    class Chebyshev_5_hess : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return  -1.2000000000000000e+02*var+320.0*(var*var*var);
        }

    public:
        std::string csrc() const
        {
            return " -1.2000000000000000e+02*var+320.0*(var*var*var)";
        }

        std::string sym() const
        {
            return "320*x^3-(120.0)*x";
        }

        std::string latex() const
        {
            return "320 x^{3}-{(120.0)} x";
        }

        Chebyshev_5_hess* clone() const
        {
            return new Chebyshev_5_hess(*this);
        }
    };

    class Chebyshev_6_hess : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return  960.0*((var*var)*(var*var))+-5.7600000000000000e+02*(var*var)+3.6000000000000000e+01;
        }

    public:
        std::string csrc() const
        {
            return " 960.0*((var*var)*(var*var))+-5.7600000000000000e+02*(var*var)+3.6000000000000000e+01";
        }

        std::string sym() const
        {
            return "36.0-(576.0)*x^2+960*x^4";
        }

        std::string latex() const
        {
            return "36.0-{(576.0)} x^{2}+960 x^{4}";
        }

        Chebyshev_6_hess* clone() const
        {
            return new Chebyshev_6_hess(*this);
        }
    };

    class Chebyshev_7_hess : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return  3.3600000000000000e+02*var+2688.0*(var*(var*var)*(var*var))+-2.2400000000000000e+03*(var*var*var);
        }

    public:
        std::string csrc() const
        {
            return " 3.3600000000000000e+02*var+2688.0*(var*(var*var)*(var*var))+-2.2400000000000000e+03*(var*var*var)";
        }

        std::string sym() const
        {
            return "-(2240.0)*x^3+(336.0)*x+2688*x^5";
        }

        std::string latex() const
        {
            return "-{(2240.0)} x^{3}+{(336.0)} x+2688 x^{5}";
        }

        Chebyshev_7_hess* clone() const
        {
            return new Chebyshev_7_hess(*this);
        }
    };

    class Chebyshev_8_hess : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return  7168.0*((var*var*var)*(var*var*var))+-7.6800000000000000e+03*((var*var)*(var*var))+1.9200000000000000e+03*(var*var)-6.4000000000000000e+01;
        }

    public:
        std::string csrc() const
        {
            return " 7168.0*((var*var*var)*(var*var*var))+-7.6800000000000000e+03*((var*var)*(var*var))+1.9200000000000000e+03*(var*var)-6.4000000000000000e+01";
        }

        std::string sym() const
        {
            return "-64.0+(1920.0)*x^2+7168*x^6-(7680.0)*x^4";
        }

        std::string latex() const
        {
            return "-64.0+{(1920.0)} x^{2}+7168 x^{6}-{(7680.0)} x^{4}";
        }

        Chebyshev_8_hess* clone() const
        {
            return new Chebyshev_8_hess(*this);
        }
    };

    class Chebyshev_9_hess : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return  -7.2000000000000000e+02*var+18432.0*(var*(var*var*var)*(var*var*var))+-2.4192000000000000e+04*(var*(var*var)*(var*var))+8.6400000000000000e+03*(var*var*var);
        }

    public:
        std::string csrc() const
        {
            return " -7.2000000000000000e+02*var+18432.0*(var*(var*var*var)*(var*var*var))+-2.4192000000000000e+04*(var*(var*var)*(var*var))+8.6400000000000000e+03*(var*var*var)";
        }

        std::string sym() const
        {
            return "(8640.0)*x^3-(720.0)*x+18432*x^7-(24192.0)*x^5";
        }

        std::string latex() const
        {
            return "{(8640.0)} x^{3}-{(720.0)} x+18432 x^{7}-{(24192.0)} x^{5}";
        }

        Chebyshev_9_hess* clone() const
        {
            return new Chebyshev_9_hess(*this);
        }
    };

    class Chebyshev_10_hess : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return  -7.1680000000000000e+04*((var*var*var)*(var*var*var))+3.3600000000000000e+04*((var*var)*(var*var))+-4.8000000000000000e+03*(var*var)+46080.0*(((var*var)*(var*var))*((var*var)*(var*var)))+1.0000000000000000e+02;
        }

    public:
        std::string csrc() const
        {
            return " -7.1680000000000000e+04*((var*var*var)*(var*var*var))+3.3600000000000000e+04*((var*var)*(var*var))+-4.8000000000000000e+03*(var*var)+46080.0*(((var*var)*(var*var))*((var*var)*(var*var)))+1.0000000000000000e+02";
        }

        std::string sym() const
        {
            return "100.0-(4800.0)*x^2+46080*x^8-(71680.0)*x^6+(33600.0)*x^4";
        }

        std::string latex() const
        {
            return "100.0-{(4800.0)} x^{2}+46080 x^{8}-{(71680.0)} x^{6}+{(33600.0)} x^{4}";
        }

        Chebyshev_10_hess* clone() const
        {
            return new Chebyshev_10_hess(*this);
        }
    };

    class Chebyshev_11_hess : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return  1.3200000000000000e+03*var+-2.0275200000000000e+05*(var*(var*var*var)*(var*var*var))+1.1827200000000000e+05*(var*(var*var)*(var*var))+-2.4640000000000000e+04*(var*var*var)+112640.0*(var*((var*var)*(var*var))*((var*var)*(var*var)));
        }

    public:
        std::string csrc() const
        {
            return " 1.3200000000000000e+03*var+-2.0275200000000000e+05*(var*(var*var*var)*(var*var*var))+1.1827200000000000e+05*(var*(var*var)*(var*var))+-2.4640000000000000e+04*(var*var*var)+112640.0*(var*((var*var)*(var*var))*((var*var)*(var*var)))";
        }

        std::string sym() const
        {
            return "-(24640.0)*x^3+112640*x^9+(1320.0)*x-(202752.0)*x^7+(118272.0)*x^5";
        }

        std::string latex() const
        {
            return "-{(24640.0)} x^{3}+112640 x^{9}+{(1320.0)} x-{(202752.0)} x^{7}+{(118272.0)} x^{5}";
        }

        Chebyshev_11_hess* clone() const
        {
            return new Chebyshev_11_hess(*this);
        }
    };

    class Chebyshev_12_hess : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return  270336.0*((var*(var*var)*(var*var))*(var*(var*var)*(var*var)))+3.8707200000000000e+05*((var*var*var)*(var*var*var))+-1.0752000000000000e+05*((var*var)*(var*var))+1.0080000000000000e+04*(var*var)+-5.5296000000000000e+05*(((var*var)*(var*var))*((var*var)*(var*var)))-1.4400000000000000e+02;
        }

    public:
        std::string csrc() const
        {
            return " 270336.0*((var*(var*var)*(var*var))*(var*(var*var)*(var*var)))+3.8707200000000000e+05*((var*var*var)*(var*var*var))+-1.0752000000000000e+05*((var*var)*(var*var))+1.0080000000000000e+04*(var*var)+-5.5296000000000000e+05*(((var*var)*(var*var))*((var*var)*(var*var)))-1.4400000000000000e+02";
        }

        std::string sym() const
        {
            return "-144.0+(10080.0)*x^2-(552960.0)*x^8+270336*x^10+(387072.0)*x^6-(107520.0)*x^4";
        }

        std::string latex() const
        {
            return "-144.0+{(10080.0)} x^{2}-{(552960.0)} x^{8}+270336 x^{10}+{(387072.0)} x^{6}-{(107520.0)} x^{4}";
        }

        Chebyshev_12_hess* clone() const
        {
            return new Chebyshev_12_hess(*this);
        }
    };

    class Chebyshev_13_hess : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return  -2.1840000000000000e+03*var+1.1980800000000000e+06*(var*(var*var*var)*(var*var*var))+-4.1932800000000000e+05*(var*(var*var)*(var*var))+5.8240000000000000e+04*(var*var*var)+-1.4643200000000000e+06*(var*((var*var)*(var*var))*((var*var)*(var*var)))+638976.0*(var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var)));
        }

    public:
        std::string csrc() const
        {
            return " -2.1840000000000000e+03*var+1.1980800000000000e+06*(var*(var*var*var)*(var*var*var))+-4.1932800000000000e+05*(var*(var*var)*(var*var))+5.8240000000000000e+04*(var*var*var)+-1.4643200000000000e+06*(var*((var*var)*(var*var))*((var*var)*(var*var)))+638976.0*(var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var)))";
        }

        std::string sym() const
        {
            return "(58240.0)*x^3+638976*x^11-(1464320.0)*x^9-(2184.0)*x+(1198080.0)*x^7-(419328.0)*x^5";
        }

        std::string latex() const
        {
            return "{(58240.0)} x^{3}+638976 x^{11}-{(1464320.0)} x^{9}-{(2184.0)} x+{(1198080.0)} x^{7}-{(419328.0)} x^{5}";
        }

        Chebyshev_13_hess* clone() const
        {
            return new Chebyshev_13_hess(*this);
        }
    };

    class Chebyshev_14_hess : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return  -3.7847040000000000e+06*((var*(var*var)*(var*var))*(var*(var*var)*(var*var)))+1490944.0*(((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))+-1.5052800000000000e+06*((var*var*var)*(var*var*var))+2.8224000000000000e+05*((var*var)*(var*var))+-1.8816000000000000e+04*(var*var)+3.5481600000000000e+06*(((var*var)*(var*var))*((var*var)*(var*var)))+1.9600000000000000e+02;
        }

    public:
        std::string csrc() const
        {
            return " -3.7847040000000000e+06*((var*(var*var)*(var*var))*(var*(var*var)*(var*var)))+1490944.0*(((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))+-1.5052800000000000e+06*((var*var*var)*(var*var*var))+2.8224000000000000e+05*((var*var)*(var*var))+-1.8816000000000000e+04*(var*var)+3.5481600000000000e+06*(((var*var)*(var*var))*((var*var)*(var*var)))+1.9600000000000000e+02";
        }

        std::string sym() const
        {
            return "196.0-(18816.0)*x^2+(3548160.0)*x^8+1490944*x^12-(3784704.0)*x^10-(1505280.0)*x^6+(282240.0)*x^4";
        }

        std::string latex() const
        {
            return "196.0-{(18816.0)} x^{2}+{(3548160.0)} x^{8}+1490944 x^{12}-{(3784704.0)} x^{10}-{(1505280.0)} x^{6}+{(282240.0)} x^{4}";
        }

        Chebyshev_14_hess* clone() const
        {
            return new Chebyshev_14_hess(*this);
        }
    };

    class Chebyshev_15_hess : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return  3.3600000000000000e+03*var+-5.0688000000000000e+06*(var*(var*var*var)*(var*var*var))+1.2096000000000000e+06*(var*(var*var)*(var*var))+3440640.0*(var*((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))+-1.2096000000000000e+05*(var*var*var)+1.0137600000000000e+07*(var*((var*var)*(var*var))*((var*var)*(var*var)))+-9.5846400000000000e+06*(var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var)));
        }

    public:
        std::string csrc() const
        {
            return " 3.3600000000000000e+03*var+-5.0688000000000000e+06*(var*(var*var*var)*(var*var*var))+1.2096000000000000e+06*(var*(var*var)*(var*var))+3440640.0*(var*((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))+-1.2096000000000000e+05*(var*var*var)+1.0137600000000000e+07*(var*((var*var)*(var*var))*((var*var)*(var*var)))+-9.5846400000000000e+06*(var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var)))";
        }

        std::string sym() const
        {
            return "-(120960.0)*x^3+3440640*x^13-(9584640.0)*x^11+(1.01376E7)*x^9+(3360.0)*x-(5068800.0)*x^7+(1209600.0)*x^5";
        }

        std::string latex() const
        {
            return "-{(120960.0)} x^{3}+3440640 x^{13}-{(9584640.0)} x^{11}+{(1.01376E7)} x^{9}+{(3360.0)} x-{(5068800.0)} x^{7}+{(1209600.0)} x^{5}";
        }

        Chebyshev_15_hess* clone() const
        {
            return new Chebyshev_15_hess(*this);
        }
    };

    class Chebyshev_16_hess : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return  7864320.0*((var*(var*var*var)*(var*var*var))*(var*(var*var*var)*(var*var*var)))+2.8114944000000000e+07*((var*(var*var)*(var*var))*(var*(var*var)*(var*var)))+-2.3855104000000000e+07*(((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))+4.7308800000000000e+06*((var*var*var)*(var*var*var))+-6.4512000000000000e+05*((var*var)*(var*var))+3.2256000000000000e+04*(var*var)+-1.6220160000000000e+07*(((var*var)*(var*var))*((var*var)*(var*var)))-2.5600000000000000e+02;
        }

    public:
        std::string csrc() const
        {
            return " 7864320.0*((var*(var*var*var)*(var*var*var))*(var*(var*var*var)*(var*var*var)))+2.8114944000000000e+07*((var*(var*var)*(var*var))*(var*(var*var)*(var*var)))+-2.3855104000000000e+07*(((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))+4.7308800000000000e+06*((var*var*var)*(var*var*var))+-6.4512000000000000e+05*((var*var)*(var*var))+3.2256000000000000e+04*(var*var)+-1.6220160000000000e+07*(((var*var)*(var*var))*((var*var)*(var*var)))-2.5600000000000000e+02";
        }

        std::string sym() const
        {
            return "-256.0+(32256.0)*x^2-(1.622016E7)*x^8+7864320*x^14-(2.3855104E7)*x^12+(2.8114944E7)*x^10+(4730880.0)*x^6-(645120.0)*x^4";
        }

        std::string latex() const
        {
            return "-256.0+{(32256.0)} x^{2}-{(1.622016E7)} x^{8}+7864320 x^{14}-{(2.3855104E7)} x^{12}+{(2.8114944E7)} x^{10}+{(4730880.0)} x^{6}-{(645120.0)} x^{4}";
        }

        Chebyshev_16_hess* clone() const
        {
            return new Chebyshev_16_hess(*this);
        }
    };

    class Chebyshev_17_hess : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return  -4.8960000000000000e+03*var+1.7233920000000000e+07*(var*(var*var*var)*(var*var*var))+-3.0159360000000000e+06*(var*(var*var)*(var*var))+17825792.0*(var*(var*(var*var*var)*(var*var*var))*(var*(var*var*var)*(var*var*var)))+-5.8490880000000000e+07*(var*((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))+2.2848000000000000e+05*(var*var*var)+-4.9786880000000000e+07*(var*((var*var)*(var*var))*((var*var)*(var*var)))+7.6038144000000000e+07*(var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var)));
        }

    public:
        std::string csrc() const
        {
            return " -4.8960000000000000e+03*var+1.7233920000000000e+07*(var*(var*var*var)*(var*var*var))+-3.0159360000000000e+06*(var*(var*var)*(var*var))+17825792.0*(var*(var*(var*var*var)*(var*var*var))*(var*(var*var*var)*(var*var*var)))+-5.8490880000000000e+07*(var*((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))+2.2848000000000000e+05*(var*var*var)+-4.9786880000000000e+07*(var*((var*var)*(var*var))*((var*var)*(var*var)))+7.6038144000000000e+07*(var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var)))";
        }

        std::string sym() const
        {
            return "(228480.0)*x^3+17825792*x^15-(5.849088E7)*x^13+(7.6038144E7)*x^11-(4.978688E7)*x^9-(4896.0)*x+(1.723392E7)*x^7-(3015936.0)*x^5";
        }

        std::string latex() const
        {
            return "{(228480.0)} x^{3}+17825792 x^{15}-{(5.849088E7)} x^{13}+{(7.6038144E7)} x^{11}-{(4.978688E7)} x^{9}-{(4896.0)} x+{(1.723392E7)} x^{7}-{(3015936.0)} x^{5}";
        }

        Chebyshev_17_hess* clone() const
        {
            return new Chebyshev_17_hess(*this);
        }
    };

    class Chebyshev_18_hess : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return  -1.4155776000000000e+08*((var*(var*var*var)*(var*var*var))*(var*(var*var*var)*(var*var*var)))+-1.4760345600000000e+08*((var*(var*var)*(var*var))*(var*(var*var)*(var*var)))+2.0127744000000000e+08*(((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))+-1.2773376000000000e+07*((var*var*var)*(var*var*var))+1.3305600000000000e+06*((var*var)*(var*var))+40108032.0*((((var*var)*(var*var))*((var*var)*(var*var)))*(((var*var)*(var*var))*((var*var)*(var*var))))+-5.1840000000000000e+04*(var*var)+5.9304960000000000e+07*(((var*var)*(var*var))*((var*var)*(var*var)))+3.2400000000000000e+02;
        }

    public:
        std::string csrc() const
        {
            return " -1.4155776000000000e+08*((var*(var*var*var)*(var*var*var))*(var*(var*var*var)*(var*var*var)))+-1.4760345600000000e+08*((var*(var*var)*(var*var))*(var*(var*var)*(var*var)))+2.0127744000000000e+08*(((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))+-1.2773376000000000e+07*((var*var*var)*(var*var*var))+1.3305600000000000e+06*((var*var)*(var*var))+40108032.0*((((var*var)*(var*var))*((var*var)*(var*var)))*(((var*var)*(var*var))*((var*var)*(var*var))))+-5.1840000000000000e+04*(var*var)+5.9304960000000000e+07*(((var*var)*(var*var))*((var*var)*(var*var)))+3.2400000000000000e+02";
        }

        std::string sym() const
        {
            return "324.0+40108032*x^16-(51840.0)*x^2+(5.930496E7)*x^8-(1.4155776E8)*x^14+(2.0127744E8)*x^12-(1.47603456E8)*x^10-(1.2773376E7)*x^6+(1330560.0)*x^4";
        }

        std::string latex() const
        {
            return "324.0+40108032 x^{16}-{(51840.0)} x^{2}+{(5.930496E7)} x^{8}-{(1.4155776E8)} x^{14}+{(2.0127744E8)} x^{12}-{(1.47603456E8)} x^{10}-{(1.2773376E7)} x^{6}+{(1330560.0)} x^{4}";
        }

        Chebyshev_18_hess* clone() const
        {
            return new Chebyshev_18_hess(*this);
        }
    };

    class Chebyshev_19_hess : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return  6.8400000000000000e+03*var+-5.0079744000000000e+07*(var*(var*var*var)*(var*var*var))+89653248.0*(var*(((var*var)*(var*var))*((var*var)*(var*var)))*(((var*var)*(var*var))*((var*var)*(var*var))))+6.7415040000000000e+06*(var*(var*var)*(var*var))+-3.3869004800000000e+08*(var*(var*(var*var*var)*(var*var*var))*(var*(var*var*var)*(var*var*var)))+5.2297728000000000e+08*(var*((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))+-4.0128000000000000e+05*(var*var*var)+1.9475456000000000e+08*(var*((var*var)*(var*var))*((var*var)*(var*var)))+-4.2491904000000000e+08*(var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var)));
        }

    public:
        std::string csrc() const
        {
            return " 6.8400000000000000e+03*var+-5.0079744000000000e+07*(var*(var*var*var)*(var*var*var))+89653248.0*(var*(((var*var)*(var*var))*((var*var)*(var*var)))*(((var*var)*(var*var))*((var*var)*(var*var))))+6.7415040000000000e+06*(var*(var*var)*(var*var))+-3.3869004800000000e+08*(var*(var*(var*var*var)*(var*var*var))*(var*(var*var*var)*(var*var*var)))+5.2297728000000000e+08*(var*((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))+-4.0128000000000000e+05*(var*var*var)+1.9475456000000000e+08*(var*((var*var)*(var*var))*((var*var)*(var*var)))+-4.2491904000000000e+08*(var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var)))";
        }

        std::string sym() const
        {
            return "-(401280.0)*x^3-(3.38690048E8)*x^15+(5.2297728E8)*x^13-(4.2491904E8)*x^11+(1.9475456E8)*x^9+(6840.0)*x-(5.0079744E7)*x^7+89653248*x^17+(6741504.0)*x^5";
        }

        std::string latex() const
        {
            return "-{(401280.0)} x^{3}-{(3.38690048E8)} x^{15}+{(5.2297728E8)} x^{13}-{(4.2491904E8)} x^{11}+{(1.9475456E8)} x^{9}+{(6840.0)} x-{(5.0079744E7)} x^{7}+89653248 x^{17}+{(6741504.0)} x^{5}";
        }

        Chebyshev_19_hess* clone() const
        {
            return new Chebyshev_19_hess(*this);
        }
    };

    class Chebyshev_20_hess : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return  1.3369344000000000e+09*((var*(var*var*var)*(var*var*var))*(var*(var*var*var)*(var*var*var)))+199229440.0*((var*((var*var)*(var*var))*((var*var)*(var*var)))*(var*((var*var)*(var*var))*((var*var)*(var*var))))+6.1501440000000000e+08*((var*(var*var)*(var*var))*(var*(var*var)*(var*var)))+-1.1927552000000000e+09*(((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))+3.0750720000000000e+07*((var*var*var)*(var*var*var))+-2.5344000000000000e+06*((var*var)*(var*var))+-8.0216064000000000e+08*((((var*var)*(var*var))*((var*var)*(var*var)))*(((var*var)*(var*var))*((var*var)*(var*var))))+7.9200000000000000e+04*(var*var)+-1.8450432000000000e+08*(((var*var)*(var*var))*((var*var)*(var*var)))-4.0000000000000000e+02;
        }

    public:
        std::string csrc() const
        {
            return " 1.3369344000000000e+09*((var*(var*var*var)*(var*var*var))*(var*(var*var*var)*(var*var*var)))+199229440.0*((var*((var*var)*(var*var))*((var*var)*(var*var)))*(var*((var*var)*(var*var))*((var*var)*(var*var))))+6.1501440000000000e+08*((var*(var*var)*(var*var))*(var*(var*var)*(var*var)))+-1.1927552000000000e+09*(((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))+3.0750720000000000e+07*((var*var*var)*(var*var*var))+-2.5344000000000000e+06*((var*var)*(var*var))+-8.0216064000000000e+08*((((var*var)*(var*var))*((var*var)*(var*var)))*(((var*var)*(var*var))*((var*var)*(var*var))))+7.9200000000000000e+04*(var*var)+-1.8450432000000000e+08*(((var*var)*(var*var))*((var*var)*(var*var)))-4.0000000000000000e+02";
        }

        std::string sym() const
        {
            return "-400.0-(8.0216064E8)*x^16+(79200.0)*x^2-(1.8450432E8)*x^8+199229440*x^18+(1.3369344E9)*x^14-(1.1927552E9)*x^12+(6.150144E8)*x^10+(3.075072E7)*x^6-(2534400.0)*x^4";
        }

        std::string latex() const
        {
            return "-400.0-{(8.0216064E8)} x^{16}+{(79200.0)} x^{2}-{(1.8450432E8)} x^{8}+199229440 x^{18}+{(1.3369344E9)} x^{14}-{(1.1927552E9)} x^{12}+{(6.150144E8)} x^{10}+{(3.075072E7)} x^{6}-{(2534400.0)} x^{4}";
        }

        Chebyshev_20_hess* clone() const
        {
            return new Chebyshev_20_hess(*this);
        }
    };

    class Chebyshev_21_hess : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return  -9.2400000000000000e+03*var+1.2915302400000000e+08*(var*(var*var*var)*(var*var*var))+-1.8827182080000000e+09*(var*(((var*var)*(var*var))*((var*var)*(var*var)))*(((var*var)*(var*var))*((var*var)*(var*var))))+-1.3837824000000000e+07*(var*(var*var)*(var*var))+3.3690746880000000e+09*(var*(var*(var*var*var)*(var*var*var))*(var*(var*var*var)*(var*var*var)))+-3.2754892800000000e+09*(var*((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))+6.6528000000000000e+05*(var*var*var)+-6.4576512000000000e+08*(var*((var*var)*(var*var))*((var*var)*(var*var)))+1.8785894400000000e+09*(var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var)))+440401920.0*(var*(var*((var*var)*(var*var))*((var*var)*(var*var)))*(var*((var*var)*(var*var))*((var*var)*(var*var))));
        }

    public:
        std::string csrc() const
        {
            return " -9.2400000000000000e+03*var+1.2915302400000000e+08*(var*(var*var*var)*(var*var*var))+-1.8827182080000000e+09*(var*(((var*var)*(var*var))*((var*var)*(var*var)))*(((var*var)*(var*var))*((var*var)*(var*var))))+-1.3837824000000000e+07*(var*(var*var)*(var*var))+3.3690746880000000e+09*(var*(var*(var*var*var)*(var*var*var))*(var*(var*var*var)*(var*var*var)))+-3.2754892800000000e+09*(var*((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))+6.6528000000000000e+05*(var*var*var)+-6.4576512000000000e+08*(var*((var*var)*(var*var))*((var*var)*(var*var)))+1.8785894400000000e+09*(var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var)))+440401920.0*(var*(var*((var*var)*(var*var))*((var*var)*(var*var)))*(var*((var*var)*(var*var))*((var*var)*(var*var))))";
        }

        std::string sym() const
        {
            return "(665280.0)*x^3+(3.369074688E9)*x^15-(3.27548928E9)*x^13+(1.87858944E9)*x^11-(6.4576512E8)*x^9+440401920*x^19-(9240.0)*x+(1.29153024E8)*x^7-(1.882718208E9)*x^17-(1.3837824E7)*x^5";
        }

        std::string latex() const
        {
            return "{(665280.0)} x^{3}+{(3.369074688E9)} x^{15}-{(3.27548928E9)} x^{13}+{(1.87858944E9)} x^{11}-{(6.4576512E8)} x^{9}+440401920 x^{19}-{(9240.0)} x+{(1.29153024E8)} x^{7}-{(1.882718208E9)} x^{17}-{(1.3837824E7)} x^{5}";
        }

        Chebyshev_21_hess* clone() const
        {
            return new Chebyshev_21_hess(*this);
        }
    };

    class Chebyshev_22_hess : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return  -8.8237670400000000e+09*((var*(var*var*var)*(var*var*var))*(var*(var*var*var)*(var*var*var)))+-4.3830476800000000e+09*((var*((var*var)*(var*var))*((var*var)*(var*var)))*(var*((var*var)*(var*var))*((var*var)*(var*var))))+-2.1648506880000000e+09*((var*(var*var)*(var*var))*(var*(var*var)*(var*var)))+5.5761305600000000e+09*(((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))+-6.7651584000000000e+07*((var*var*var)*(var*var*var))+4.5302400000000000e+06*((var*var)*(var*var))+8.3825786880000000e+09*((((var*var)*(var*var))*((var*var)*(var*var)))*(((var*var)*(var*var))*((var*var)*(var*var))))+9.6888422400000000e+08*(((var*(var*var)*(var*var))*(var*(var*var)*(var*var)))*((var*(var*var)*(var*var))*(var*(var*var)*(var*var))))+-1.1616000000000000e+05*(var*var)+5.0738688000000000e+08*(((var*var)*(var*var))*((var*var)*(var*var)))+4.8400000000000000e+02;
        }

    public:
        std::string csrc() const
        {
            return " -8.8237670400000000e+09*((var*(var*var*var)*(var*var*var))*(var*(var*var*var)*(var*var*var)))+-4.3830476800000000e+09*((var*((var*var)*(var*var))*((var*var)*(var*var)))*(var*((var*var)*(var*var))*((var*var)*(var*var))))+-2.1648506880000000e+09*((var*(var*var)*(var*var))*(var*(var*var)*(var*var)))+5.5761305600000000e+09*(((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))+-6.7651584000000000e+07*((var*var*var)*(var*var*var))+4.5302400000000000e+06*((var*var)*(var*var))+8.3825786880000000e+09*((((var*var)*(var*var))*((var*var)*(var*var)))*(((var*var)*(var*var))*((var*var)*(var*var))))+9.6888422400000000e+08*(((var*(var*var)*(var*var))*(var*(var*var)*(var*var)))*((var*(var*var)*(var*var))*(var*(var*var)*(var*var))))+-1.1616000000000000e+05*(var*var)+5.0738688000000000e+08*(((var*var)*(var*var))*((var*var)*(var*var)))+4.8400000000000000e+02";
        }

        std::string sym() const
        {
            return "484.0+968884224*x^20+(8.382578688E9)*x^16-(116160.0)*x^2+(5.0738688E8)*x^8-(4.38304768E9)*x^18-(8.82376704E9)*x^14+(5.57613056E9)*x^12-(2.164850688E9)*x^10-(6.7651584E7)*x^6+(4530240.0)*x^4";
        }

        std::string latex() const
        {
            return "484.0+968884224 x^{20}+{(8.382578688E9)} x^{16}-{(116160.0)} x^{2}+{(5.0738688E8)} x^{8}-{(4.38304768E9)} x^{18}-{(8.82376704E9)} x^{14}+{(5.57613056E9)} x^{12}-{(2.164850688E9)} x^{10}-{(6.7651584E7)} x^{6}+{(4530240.0)} x^{4}";
        }

        Chebyshev_22_hess* clone() const
        {
            return new Chebyshev_22_hess(*this);
        }
    };

    class Chebyshev_23_hess : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return  1.2144000000000000e+04*var+2.1223178240000000e+09*(var*((var*(var*var)*(var*var))*(var*(var*var)*(var*var)))*((var*(var*var)*(var*var))*(var*(var*var)*(var*var))))+-3.0311424000000000e+08*(var*(var*var*var)*(var*var*var))+2.0620247040000000e+10*(var*(((var*var)*(var*var))*((var*var)*(var*var)))*(((var*var)*(var*var))*((var*var)*(var*var))))+2.6522496000000000e+07*(var*(var*var)*(var*var))+-2.3369613312000000e+10*(var*(var*(var*var*var)*(var*var*var))*(var*(var*var*var)*(var*var*var)))+1.6143482880000000e+10*(var*((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))+-1.0524800000000000e+06*(var*var*var)+1.8860441600000000e+09*(var*((var*var)*(var*var))*((var*var)*(var*var)))+-6.9955092480000000e+09*(var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var)))+-1.0129244160000000e+10*(var*(var*((var*var)*(var*var))*((var*var)*(var*var)))*(var*((var*var)*(var*var))*((var*var)*(var*var))));
        }

    public:
        std::string csrc() const
        {
            return " 1.2144000000000000e+04*var+2.1223178240000000e+09*(var*((var*(var*var)*(var*var))*(var*(var*var)*(var*var)))*((var*(var*var)*(var*var))*(var*(var*var)*(var*var))))+-3.0311424000000000e+08*(var*(var*var*var)*(var*var*var))+2.0620247040000000e+10*(var*(((var*var)*(var*var))*((var*var)*(var*var)))*(((var*var)*(var*var))*((var*var)*(var*var))))+2.6522496000000000e+07*(var*(var*var)*(var*var))+-2.3369613312000000e+10*(var*(var*(var*var*var)*(var*var*var))*(var*(var*var*var)*(var*var*var)))+1.6143482880000000e+10*(var*((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))+-1.0524800000000000e+06*(var*var*var)+1.8860441600000000e+09*(var*((var*var)*(var*var))*((var*var)*(var*var)))+-6.9955092480000000e+09*(var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var)))+-1.0129244160000000e+10*(var*(var*((var*var)*(var*var))*((var*var)*(var*var)))*(var*((var*var)*(var*var))*((var*var)*(var*var))))";
        }

        std::string sym() const
        {
            return "-(1052480.0)*x^3-(2.3369613312E10)*x^15+(1.614348288E10)*x^13-(6.995509248E9)*x^11+(1.88604416E9)*x^9-(1.012924416E10)*x^19+2122317824*x^21+(12144.0)*x-(3.0311424E8)*x^7+(2.062024704E10)*x^17+(2.6522496E7)*x^5";
        }

        std::string latex() const
        {
            return "-{(1052480.0)} x^{3}-{(2.3369613312E10)} x^{15}+{(1.614348288E10)} x^{13}-{(6.995509248E9)} x^{11}+{(1.88604416E9)} x^{9}-{(1.012924416E10)} x^{19}+2122317824 x^{21}+{(12144.0)} x-{(3.0311424E8)} x^{7}+{(2.062024704E10)} x^{17}+{(2.6522496E7)} x^{5}";
        }

        Chebyshev_23_hess* clone() const
        {
            return new Chebyshev_23_hess(*this);
        }
    };

    class Chebyshev_24_hess : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return  4.5723156480000000e+10*((var*(var*var*var)*(var*var*var))*(var*(var*var*var)*(var*var*var)))+5.0205818880000000e+10*((var*((var*var)*(var*var))*((var*var)*(var*var)))*(var*((var*var)*(var*var))*((var*var)*(var*var))))+6.6913566720000000e+09*((var*(var*var)*(var*var))*(var*(var*var)*(var*var)))+-2.1898985472000000e+10*(((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))+1.3837824000000000e+08*((var*var*var)*(var*var*var))+-7.6876800000000000e+06*((var*var)*(var*var))+4.6305116160000000e+09*((var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var)))*(var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var))))+-6.0964208640000000e+10*((((var*var)*(var*var))*((var*var)*(var*var)))*(((var*var)*(var*var))*((var*var)*(var*var))))+-2.3253221376000000e+10*(((var*(var*var)*(var*var))*(var*(var*var)*(var*var)))*((var*(var*var)*(var*var))*(var*(var*var)*(var*var))))+1.6473600000000000e+05*(var*var)+-1.2651724800000000e+09*(((var*var)*(var*var))*((var*var)*(var*var)))-5.7600000000000000e+02;
        }

    public:
        std::string csrc() const
        {
            return " 4.5723156480000000e+10*((var*(var*var*var)*(var*var*var))*(var*(var*var*var)*(var*var*var)))+5.0205818880000000e+10*((var*((var*var)*(var*var))*((var*var)*(var*var)))*(var*((var*var)*(var*var))*((var*var)*(var*var))))+6.6913566720000000e+09*((var*(var*var)*(var*var))*(var*(var*var)*(var*var)))+-2.1898985472000000e+10*(((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))+1.3837824000000000e+08*((var*var*var)*(var*var*var))+-7.6876800000000000e+06*((var*var)*(var*var))+4.6305116160000000e+09*((var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var)))*(var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var))))+-6.0964208640000000e+10*((((var*var)*(var*var))*((var*var)*(var*var)))*(((var*var)*(var*var))*((var*var)*(var*var))))+-2.3253221376000000e+10*(((var*(var*var)*(var*var))*(var*(var*var)*(var*var)))*((var*(var*var)*(var*var))*(var*(var*var)*(var*var))))+1.6473600000000000e+05*(var*var)+-1.2651724800000000e+09*(((var*var)*(var*var))*((var*var)*(var*var)))-5.7600000000000000e+02";
        }

        std::string sym() const
        {
            return "-576.0-(2.3253221376E10)*x^20-(6.096420864E10)*x^16+(164736.0)*x^2-(1.26517248E9)*x^8+(5.020581888E10)*x^18+(4.572315648E10)*x^14-(2.1898985472E10)*x^12+(6.691356672E9)*x^10+(1.3837824E8)*x^6-(7687680.0)*x^4+4630511616*x^22";
        }

        std::string latex() const
        {
            return "-576.0-{(2.3253221376E10)} x^{20}-{(6.096420864E10)} x^{16}+{(164736.0)} x^{2}-{(1.26517248E9)} x^{8}+{(5.020581888E10)} x^{18}+{(4.572315648E10)} x^{14}-{(2.1898985472E10)} x^{12}+{(6.691356672E9)} x^{10}+{(1.3837824E8)} x^{6}-{(7687680.0)} x^{4}+4630511616 x^{22}";
        }

        Chebyshev_24_hess* clone() const
        {
            return new Chebyshev_24_hess(*this);
        }
    };

    class Chebyshev_25_hess : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return  -1.5600000000000000e+04*var+1.0066329600000000e+10*(var*(var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var)))*(var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var))))+-5.3057945600000000e+10*(var*((var*(var*var)*(var*var))*(var*(var*var)*(var*var)))*((var*(var*var)*(var*var))*(var*(var*var)*(var*var))))+6.5894400000000000e+08*(var*(var*var*var)*(var*var*var))+-1.5689318400000000e+11*(var*(((var*var)*(var*var))*((var*var)*(var*var)))*(((var*var)*(var*var))*((var*var)*(var*var))))+-4.8048000000000000e+07*(var*(var*var)*(var*var))+1.2700876800000000e+11*(var*(var*(var*var*var)*(var*var*var))*(var*(var*var*var)*(var*var*var)))+-6.6679603200000000e+10*(var*((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))+1.6016000000000000e+06*(var*var*var)+-4.9786880000000000e+09*(var*((var*var)*(var*var))*((var*var)*(var*var)))+2.2811443200000000e+10*(var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var)))+1.2111052800000000e+11*(var*(var*((var*var)*(var*var))*((var*var)*(var*var)))*(var*((var*var)*(var*var))*((var*var)*(var*var))));
        }

    public:
        std::string csrc() const
        {
            return " -1.5600000000000000e+04*var+1.0066329600000000e+10*(var*(var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var)))*(var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var))))+-5.3057945600000000e+10*(var*((var*(var*var)*(var*var))*(var*(var*var)*(var*var)))*((var*(var*var)*(var*var))*(var*(var*var)*(var*var))))+6.5894400000000000e+08*(var*(var*var*var)*(var*var*var))+-1.5689318400000000e+11*(var*(((var*var)*(var*var))*((var*var)*(var*var)))*(((var*var)*(var*var))*((var*var)*(var*var))))+-4.8048000000000000e+07*(var*(var*var)*(var*var))+1.2700876800000000e+11*(var*(var*(var*var*var)*(var*var*var))*(var*(var*var*var)*(var*var*var)))+-6.6679603200000000e+10*(var*((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))+1.6016000000000000e+06*(var*var*var)+-4.9786880000000000e+09*(var*((var*var)*(var*var))*((var*var)*(var*var)))+2.2811443200000000e+10*(var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var)))+1.2111052800000000e+11*(var*(var*((var*var)*(var*var))*((var*var)*(var*var)))*(var*((var*var)*(var*var))*((var*var)*(var*var))))";
        }

        std::string sym() const
        {
            return "(1601600.0)*x^3+(1.27008768E11)*x^15-(6.66796032E10)*x^13+(2.28114432E10)*x^11-(4.978688E9)*x^9+(1.21110528E11)*x^19+10066329600*x^23-(5.30579456E10)*x^21-(15600.0)*x+(6.58944E8)*x^7-(1.56893184E11)*x^17-(4.8048E7)*x^5";
        }

        std::string latex() const
        {
            return "{(1601600.0)} x^{3}+{(1.27008768E11)} x^{15}-{(6.66796032E10)} x^{13}+{(2.28114432E10)} x^{11}-{(4.978688E9)} x^{9}+{(1.21110528E11)} x^{19}+10066329600 x^{23}-{(5.30579456E10)} x^{21}-{(15600.0)} x+{(6.58944E8)} x^{7}-{(1.56893184E11)} x^{17}-{(4.8048E7)} x^{5}";
        }

        Chebyshev_25_hess* clone() const
        {
            return new Chebyshev_25_hess(*this);
        }
    };

    class Chebyshev_26_hess : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return  -1.9813367808000000e+11*((var*(var*var*var)*(var*var*var))*(var*(var*var*var)*(var*var*var)))+-3.9885733888000000e+11*((var*((var*var)*(var*var))*((var*var)*(var*var)))*(var*((var*var)*(var*var))*((var*var)*(var*var))))+-1.8640207872000000e+10*((var*(var*var)*(var*var))*(var*(var*var)*(var*var)))+7.5125686272000000e+10*(((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))+-2.6650624000000000e+08*((var*var*var)*(var*var*var))+1.2492480000000000e+07*((var*var)*(var*var))+-1.2039330201600000e+11*((var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var)))*(var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var))))+3.4673393664000000e+11*((((var*var)*(var*var))*((var*var)*(var*var)))*(((var*var)*(var*var))*((var*var)*(var*var))))+2.8969638297600000e+11*(((var*(var*var)*(var*var))*(var*(var*var)*(var*var)))*((var*(var*var)*(var*var))*(var*(var*var)*(var*var))))+-2.2713600000000000e+05*(var*var)+2.9125324800000000e+09*(((var*var)*(var*var))*((var*var)*(var*var)))+2.1810380800000000e+10*((((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))*(((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var))))+6.7600000000000000e+02;
        }

    public:
        std::string csrc() const
        {
            return " -1.9813367808000000e+11*((var*(var*var*var)*(var*var*var))*(var*(var*var*var)*(var*var*var)))+-3.9885733888000000e+11*((var*((var*var)*(var*var))*((var*var)*(var*var)))*(var*((var*var)*(var*var))*((var*var)*(var*var))))+-1.8640207872000000e+10*((var*(var*var)*(var*var))*(var*(var*var)*(var*var)))+7.5125686272000000e+10*(((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))+-2.6650624000000000e+08*((var*var*var)*(var*var*var))+1.2492480000000000e+07*((var*var)*(var*var))+-1.2039330201600000e+11*((var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var)))*(var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var))))+3.4673393664000000e+11*((((var*var)*(var*var))*((var*var)*(var*var)))*(((var*var)*(var*var))*((var*var)*(var*var))))+2.8969638297600000e+11*(((var*(var*var)*(var*var))*(var*(var*var)*(var*var)))*((var*(var*var)*(var*var))*(var*(var*var)*(var*var))))+-2.2713600000000000e+05*(var*var)+2.9125324800000000e+09*(((var*var)*(var*var))*((var*var)*(var*var)))+2.1810380800000000e+10*((((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))*(((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var))))+6.7600000000000000e+02";
        }

        std::string sym() const
        {
            return "676.0+(2.89696382976E11)*x^20+(3.4673393664E11)*x^16-(227136.0)*x^2+(2.91253248E9)*x^8+21810380800*x^24-(3.9885733888E11)*x^18-(1.9813367808E11)*x^14+(7.5125686272E10)*x^12-(1.8640207872E10)*x^10-(2.6650624E8)*x^6+(1.249248E7)*x^4-(1.20393302016E11)*x^22";
        }

        std::string latex() const
        {
            return "676.0+{(2.89696382976E11)} x^{20}+{(3.4673393664E11)} x^{16}-{(227136.0)} x^{2}+{(2.91253248E9)} x^{8}+21810380800 x^{24}-{(3.9885733888E11)} x^{18}-{(1.9813367808E11)} x^{14}+{(7.5125686272E10)} x^{12}-{(1.8640207872E10)} x^{10}-{(2.6650624E8)} x^{6}+{(1.249248E7)} x^{4}-{(1.20393302016E11)} x^{22}";
        }

        Chebyshev_26_hess* clone() const
        {
            return new Chebyshev_26_hess(*this);
        }
    };

    class Chebyshev_27_hess : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return  1.9656000000000000e+04*var+-2.7179089920000000e+11*(var*(var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var)))*(var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var))))+6.8763097497600000e+11*(var*((var*(var*var)*(var*var))*(var*(var*var)*(var*var)))*((var*(var*var)*(var*var))*(var*(var*var)*(var*var))))+-1.3442457600000000e+09*(var*(var*var*var)*(var*var*var))+9.3194551296000000e+11*(var*(((var*var)*(var*var))*((var*var)*(var*var)))*(((var*var)*(var*var))*((var*var)*(var*var))))+8.3026944000000000e+07*(var*(var*var)*(var*var))+-5.7611177164800000e+11*(var*(var*(var*var*var)*(var*var*var))*(var*(var*var*var)*(var*var*var)))+2.4004657152000000e+11*(var*((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))+-2.3587200000000000e+06*(var*var*var)+4.7110422528000000e+10*(var*(((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))*(((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var))))+1.2098211840000000e+10*(var*((var*var)*(var*var))*((var*var)*(var*var)))+-6.6870116352000000e+10*(var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var)))+-1.0027951718400000e+12*(var*(var*((var*var)*(var*var))*((var*var)*(var*var)))*(var*((var*var)*(var*var))*((var*var)*(var*var))));
        }

    public:
        std::string csrc() const
        {
            return " 1.9656000000000000e+04*var+-2.7179089920000000e+11*(var*(var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var)))*(var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var))))+6.8763097497600000e+11*(var*((var*(var*var)*(var*var))*(var*(var*var)*(var*var)))*((var*(var*var)*(var*var))*(var*(var*var)*(var*var))))+-1.3442457600000000e+09*(var*(var*var*var)*(var*var*var))+9.3194551296000000e+11*(var*(((var*var)*(var*var))*((var*var)*(var*var)))*(((var*var)*(var*var))*((var*var)*(var*var))))+8.3026944000000000e+07*(var*(var*var)*(var*var))+-5.7611177164800000e+11*(var*(var*(var*var*var)*(var*var*var))*(var*(var*var*var)*(var*var*var)))+2.4004657152000000e+11*(var*((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))+-2.3587200000000000e+06*(var*var*var)+4.7110422528000000e+10*(var*(((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))*(((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var))))+1.2098211840000000e+10*(var*((var*var)*(var*var))*((var*var)*(var*var)))+-6.6870116352000000e+10*(var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var)))+-1.0027951718400000e+12*(var*(var*((var*var)*(var*var))*((var*var)*(var*var)))*(var*((var*var)*(var*var))*((var*var)*(var*var))))";
        }

        std::string sym() const
        {
            return "-(2358720.0)*x^3-(5.76111771648E11)*x^15+(2.4004657152E11)*x^13-(6.6870116352E10)*x^11+47110422528*x^25+(1.209821184E10)*x^9-(1.00279517184E12)*x^19-(2.717908992E11)*x^23+(6.87630974976E11)*x^21+(19656.0)*x-(1.34424576E9)*x^7+(9.3194551296E11)*x^17+(8.3026944E7)*x^5";
        }

        std::string latex() const
        {
            return "-{(2358720.0)} x^{3}-{(5.76111771648E11)} x^{15}+{(2.4004657152E11)} x^{13}-{(6.6870116352E10)} x^{11}+47110422528 x^{25}+{(1.209821184E10)} x^{9}-{(1.00279517184E12)} x^{19}-{(2.717908992E11)} x^{23}+{(6.87630974976E11)} x^{21}+{(19656.0)} x-{(1.34424576E9)} x^{7}+{(9.3194551296E11)} x^{17}+{(8.3026944E7)} x^{5}";
        }

        Chebyshev_27_hess* clone() const
        {
            return new Chebyshev_27_hess(*this);
        }
    };

    class Chebyshev_28_hess : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return  7.4681155584000000e+11*((var*(var*var*var)*(var*var*var))*(var*(var*var*var)*(var*var*var)))+2.4698473676800000e+12*((var*((var*var)*(var*var))*((var*var)*(var*var)))*(var*((var*var)*(var*var))*((var*var)*(var*var))))+4.7675916288000000e+10*((var*(var*var)*(var*var))*(var*(var*var)*(var*var)))+-2.3115595776000000e+11*(((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))+4.8791142400000000e+08*((var*var*var)*(var*var*var))+-1.9568640000000000e+07*((var*var)*(var*var))+1.6206790656000000e+12*((var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var)))*(var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var))))+1.0146860236800000e+11*((var*((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))*(var*((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var))))+-1.6429854228480000e+12*((((var*var)*(var*var))*((var*var)*(var*var)))*(((var*var)*(var*var))*((var*var)*(var*var))))+-2.4958457610240000e+12*(((var*(var*var)*(var*var))*(var*(var*var)*(var*var)))*((var*(var*var)*(var*var))*(var*(var*var)*(var*var))))+3.0576000000000000e+05*(var*var)+-6.2731468800000000e+09*(((var*var)*(var*var))*((var*var)*(var*var)))+-6.1069066240000000e+11*((((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))*(((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var))))-7.8400000000000000e+02;
        }

    public:
        std::string csrc() const
        {
            return " 7.4681155584000000e+11*((var*(var*var*var)*(var*var*var))*(var*(var*var*var)*(var*var*var)))+2.4698473676800000e+12*((var*((var*var)*(var*var))*((var*var)*(var*var)))*(var*((var*var)*(var*var))*((var*var)*(var*var))))+4.7675916288000000e+10*((var*(var*var)*(var*var))*(var*(var*var)*(var*var)))+-2.3115595776000000e+11*(((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))+4.8791142400000000e+08*((var*var*var)*(var*var*var))+-1.9568640000000000e+07*((var*var)*(var*var))+1.6206790656000000e+12*((var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var)))*(var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var))))+1.0146860236800000e+11*((var*((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))*(var*((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var))))+-1.6429854228480000e+12*((((var*var)*(var*var))*((var*var)*(var*var)))*(((var*var)*(var*var))*((var*var)*(var*var))))+-2.4958457610240000e+12*(((var*(var*var)*(var*var))*(var*(var*var)*(var*var)))*((var*(var*var)*(var*var))*(var*(var*var)*(var*var))))+3.0576000000000000e+05*(var*var)+-6.2731468800000000e+09*(((var*var)*(var*var))*((var*var)*(var*var)))+-6.1069066240000000e+11*((((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))*(((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var))))-7.8400000000000000e+02";
        }

        std::string sym() const
        {
            return "-784.0-(2.495845761024E12)*x^20-(1.642985422848E12)*x^16+(305760.0)*x^2-(6.27314688E9)*x^8-(6.106906624E11)*x^24+(2.46984736768E12)*x^18+(7.4681155584E11)*x^14-(2.3115595776E11)*x^12+(4.7675916288E10)*x^10+(4.87911424E8)*x^6+101468602368*x^26-(1.956864E7)*x^4+(1.6206790656E12)*x^22";
        }

        std::string latex() const
        {
            return "-784.0-{(2.495845761024E12)} x^{20}-{(1.642985422848E12)} x^{16}+{(305760.0)} x^{2}-{(6.27314688E9)} x^{8}-{(6.106906624E11)} x^{24}+{(2.46984736768E12)} x^{18}+{(7.4681155584E11)} x^{14}-{(2.3115595776E11)} x^{12}+{(4.7675916288E10)} x^{10}+{(4.87911424E8)} x^{6}+101468602368 x^{26}-{(1.956864E7)} x^{4}+{(1.6206790656E12)} x^{22}";
        }

        Chebyshev_28_hess* clone() const
        {
            return new Chebyshev_28_hess(*this);
        }
    };

    class Chebyshev_29_hess : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return  -2.4360000000000000e+04*var+3.7950062592000000e+12*(var*(var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var)))*(var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var))))+2.1796959027200000e+11*(var*(var*((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))*(var*((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var))))+-6.1547216896000000e+12*(var*((var*(var*var)*(var*var))*(var*(var*var)*(var*var)))*((var*(var*var)*(var*var))*(var*(var*var)*(var*var))))+2.5988751360000000e+09*(var*(var*var*var)*(var*var*var))+-4.6045011640320000e+12*(var*(((var*var)*(var*var))*((var*var)*(var*var)))*(((var*var)*(var*var))*((var*var)*(var*var))))+-1.3781913600000000e+08*(var*(var*var)*(var*var))+2.2688846315520000e+12*(var*(var*(var*var*var)*(var*var*var))*(var*(var*var*var)*(var*var*var)))+-7.7348339712000000e+11*(var*((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))+3.3779200000000000e+06*(var*var*var)+-1.3662022533120000e+12*(var*(((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))*(((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var))))+-2.7432570880000000e+10*(var*((var*var)*(var*var))*((var*var)*(var*var)))+1.7955864576000000e+11*(var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var)))+6.4624577740800000e+12*(var*(var*((var*var)*(var*var))*((var*var)*(var*var)))*(var*((var*var)*(var*var))*((var*var)*(var*var))));
        }

    public:
        std::string csrc() const
        {
            return " -2.4360000000000000e+04*var+3.7950062592000000e+12*(var*(var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var)))*(var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var))))+2.1796959027200000e+11*(var*(var*((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))*(var*((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var))))+-6.1547216896000000e+12*(var*((var*(var*var)*(var*var))*(var*(var*var)*(var*var)))*((var*(var*var)*(var*var))*(var*(var*var)*(var*var))))+2.5988751360000000e+09*(var*(var*var*var)*(var*var*var))+-4.6045011640320000e+12*(var*(((var*var)*(var*var))*((var*var)*(var*var)))*(((var*var)*(var*var))*((var*var)*(var*var))))+-1.3781913600000000e+08*(var*(var*var)*(var*var))+2.2688846315520000e+12*(var*(var*(var*var*var)*(var*var*var))*(var*(var*var*var)*(var*var*var)))+-7.7348339712000000e+11*(var*((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))+3.3779200000000000e+06*(var*var*var)+-1.3662022533120000e+12*(var*(((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))*(((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var))))+-2.7432570880000000e+10*(var*((var*var)*(var*var))*((var*var)*(var*var)))+1.7955864576000000e+11*(var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var)))+6.4624577740800000e+12*(var*(var*((var*var)*(var*var))*((var*var)*(var*var)))*(var*((var*var)*(var*var))*((var*var)*(var*var))))";
        }

        std::string sym() const
        {
            return "(3377920.0)*x^3+(2.268884631552E12)*x^15-(7.7348339712E11)*x^13+(1.7955864576E11)*x^11-(1.366202253312E12)*x^25-(2.743257088E10)*x^9+(6.46245777408E12)*x^19+217969590272*x^27+(3.7950062592E12)*x^23-(6.1547216896E12)*x^21-(24360.0)*x+(2.598875136E9)*x^7-(4.604501164032E12)*x^17-(1.37819136E8)*x^5";
        }

        std::string latex() const
        {
            return "{(3377920.0)} x^{3}+{(2.268884631552E12)} x^{15}-{(7.7348339712E11)} x^{13}+{(1.7955864576E11)} x^{11}-{(1.366202253312E12)} x^{25}-{(2.743257088E10)} x^{9}+{(6.46245777408E12)} x^{19}+217969590272 x^{27}+{(3.7950062592E12)} x^{23}-{(6.1547216896E12)} x^{21}-{(24360.0)} x+{(2.598875136E9)} x^{7}-{(4.604501164032E12)} x^{17}-{(1.37819136E8)} x^{5}";
        }

        Chebyshev_29_hess* clone() const
        {
            return new Chebyshev_29_hess(*this);
        }
    };

    class Chebyshev : public PBasisSetBase<double, double>
    {
    public:
        
        typedef PBasisSetBase<double, double>::size_type size_type;
        
        std::vector< PFunction< double, double> > _basis_function;
        
        Chebyshev(size_type N) : PBasisSetBase<double, double>(N)
        {
            construct(N);
        }

        Chebyshev(const Chebyshev &RHS ) : PBasisSetBase<double, double>(RHS.size())
        {
            construct(RHS.size());
            copy(RHS);
        }

        Chebyshev& operator=(const Chebyshev &RHS )
        {
            if( this == &RHS) return *this;
            construct(RHS.size());
            copy(RHS);
            return *this;
        }

        ~Chebyshev()
        {
        }

        Chebyshev* clone() const
        {
            return new Chebyshev(*this);
        }

        PFunction< double, double> basis_function( size_type term) const
        {
            if(term >= max_size()){ std::cout << "Error in Chebyshev::basis_function( size_type term). term >= max_size()." << std::endl; exit(1);}

            std::string name;
            std::vector< std::string> var_name(1, "x");
            std::vector< std::string> var_description(1, "x");

            typedef PSimpleFunction< double, double> psf;

            psf simplef;
            std::vector< psf > grad_simplef;
            std::vector< std::vector< psf > > hess_simplef;
            hess_simplef.resize(1);
            switch( term )
            {
                case 0:
                    name = "Chebyshev_0";
                    simplef = Chebyshev_0();
                    grad_simplef.push_back( psf( Chebyshev_0_grad() ) );
                    hess_simplef[0].push_back( psf( Chebyshev_0_hess() ) );
                    break;
                case 1:
                    name = "Chebyshev_1";
                    simplef = Chebyshev_1();
                    grad_simplef.push_back( psf( Chebyshev_1_grad() ) );
                    hess_simplef[0].push_back( psf( Chebyshev_1_hess() ) );
                    break;
                case 2:
                    name = "Chebyshev_2";
                    simplef = Chebyshev_2();
                    grad_simplef.push_back( psf( Chebyshev_2_grad() ) );
                    hess_simplef[0].push_back( psf( Chebyshev_2_hess() ) );
                    break;
                case 3:
                    name = "Chebyshev_3";
                    simplef = Chebyshev_3();
                    grad_simplef.push_back( psf( Chebyshev_3_grad() ) );
                    hess_simplef[0].push_back( psf( Chebyshev_3_hess() ) );
                    break;
                case 4:
                    name = "Chebyshev_4";
                    simplef = Chebyshev_4();
                    grad_simplef.push_back( psf( Chebyshev_4_grad() ) );
                    hess_simplef[0].push_back( psf( Chebyshev_4_hess() ) );
                    break;
                case 5:
                    name = "Chebyshev_5";
                    simplef = Chebyshev_5();
                    grad_simplef.push_back( psf( Chebyshev_5_grad() ) );
                    hess_simplef[0].push_back( psf( Chebyshev_5_hess() ) );
                    break;
                case 6:
                    name = "Chebyshev_6";
                    simplef = Chebyshev_6();
                    grad_simplef.push_back( psf( Chebyshev_6_grad() ) );
                    hess_simplef[0].push_back( psf( Chebyshev_6_hess() ) );
                    break;
                case 7:
                    name = "Chebyshev_7";
                    simplef = Chebyshev_7();
                    grad_simplef.push_back( psf( Chebyshev_7_grad() ) );
                    hess_simplef[0].push_back( psf( Chebyshev_7_hess() ) );
                    break;
                case 8:
                    name = "Chebyshev_8";
                    simplef = Chebyshev_8();
                    grad_simplef.push_back( psf( Chebyshev_8_grad() ) );
                    hess_simplef[0].push_back( psf( Chebyshev_8_hess() ) );
                    break;
                case 9:
                    name = "Chebyshev_9";
                    simplef = Chebyshev_9();
                    grad_simplef.push_back( psf( Chebyshev_9_grad() ) );
                    hess_simplef[0].push_back( psf( Chebyshev_9_hess() ) );
                    break;
                case 10:
                    name = "Chebyshev_10";
                    simplef = Chebyshev_10();
                    grad_simplef.push_back( psf( Chebyshev_10_grad() ) );
                    hess_simplef[0].push_back( psf( Chebyshev_10_hess() ) );
                    break;
                case 11:
                    name = "Chebyshev_11";
                    simplef = Chebyshev_11();
                    grad_simplef.push_back( psf( Chebyshev_11_grad() ) );
                    hess_simplef[0].push_back( psf( Chebyshev_11_hess() ) );
                    break;
                case 12:
                    name = "Chebyshev_12";
                    simplef = Chebyshev_12();
                    grad_simplef.push_back( psf( Chebyshev_12_grad() ) );
                    hess_simplef[0].push_back( psf( Chebyshev_12_hess() ) );
                    break;
                case 13:
                    name = "Chebyshev_13";
                    simplef = Chebyshev_13();
                    grad_simplef.push_back( psf( Chebyshev_13_grad() ) );
                    hess_simplef[0].push_back( psf( Chebyshev_13_hess() ) );
                    break;
                case 14:
                    name = "Chebyshev_14";
                    simplef = Chebyshev_14();
                    grad_simplef.push_back( psf( Chebyshev_14_grad() ) );
                    hess_simplef[0].push_back( psf( Chebyshev_14_hess() ) );
                    break;
                case 15:
                    name = "Chebyshev_15";
                    simplef = Chebyshev_15();
                    grad_simplef.push_back( psf( Chebyshev_15_grad() ) );
                    hess_simplef[0].push_back( psf( Chebyshev_15_hess() ) );
                    break;
                case 16:
                    name = "Chebyshev_16";
                    simplef = Chebyshev_16();
                    grad_simplef.push_back( psf( Chebyshev_16_grad() ) );
                    hess_simplef[0].push_back( psf( Chebyshev_16_hess() ) );
                    break;
                case 17:
                    name = "Chebyshev_17";
                    simplef = Chebyshev_17();
                    grad_simplef.push_back( psf( Chebyshev_17_grad() ) );
                    hess_simplef[0].push_back( psf( Chebyshev_17_hess() ) );
                    break;
                case 18:
                    name = "Chebyshev_18";
                    simplef = Chebyshev_18();
                    grad_simplef.push_back( psf( Chebyshev_18_grad() ) );
                    hess_simplef[0].push_back( psf( Chebyshev_18_hess() ) );
                    break;
                case 19:
                    name = "Chebyshev_19";
                    simplef = Chebyshev_19();
                    grad_simplef.push_back( psf( Chebyshev_19_grad() ) );
                    hess_simplef[0].push_back( psf( Chebyshev_19_hess() ) );
                    break;
                case 20:
                    name = "Chebyshev_20";
                    simplef = Chebyshev_20();
                    grad_simplef.push_back( psf( Chebyshev_20_grad() ) );
                    hess_simplef[0].push_back( psf( Chebyshev_20_hess() ) );
                    break;
                case 21:
                    name = "Chebyshev_21";
                    simplef = Chebyshev_21();
                    grad_simplef.push_back( psf( Chebyshev_21_grad() ) );
                    hess_simplef[0].push_back( psf( Chebyshev_21_hess() ) );
                    break;
                case 22:
                    name = "Chebyshev_22";
                    simplef = Chebyshev_22();
                    grad_simplef.push_back( psf( Chebyshev_22_grad() ) );
                    hess_simplef[0].push_back( psf( Chebyshev_22_hess() ) );
                    break;
                case 23:
                    name = "Chebyshev_23";
                    simplef = Chebyshev_23();
                    grad_simplef.push_back( psf( Chebyshev_23_grad() ) );
                    hess_simplef[0].push_back( psf( Chebyshev_23_hess() ) );
                    break;
                case 24:
                    name = "Chebyshev_24";
                    simplef = Chebyshev_24();
                    grad_simplef.push_back( psf( Chebyshev_24_grad() ) );
                    hess_simplef[0].push_back( psf( Chebyshev_24_hess() ) );
                    break;
                case 25:
                    name = "Chebyshev_25";
                    simplef = Chebyshev_25();
                    grad_simplef.push_back( psf( Chebyshev_25_grad() ) );
                    hess_simplef[0].push_back( psf( Chebyshev_25_hess() ) );
                    break;
                case 26:
                    name = "Chebyshev_26";
                    simplef = Chebyshev_26();
                    grad_simplef.push_back( psf( Chebyshev_26_grad() ) );
                    hess_simplef[0].push_back( psf( Chebyshev_26_hess() ) );
                    break;
                case 27:
                    name = "Chebyshev_27";
                    simplef = Chebyshev_27();
                    grad_simplef.push_back( psf( Chebyshev_27_grad() ) );
                    hess_simplef[0].push_back( psf( Chebyshev_27_hess() ) );
                    break;
                case 28:
                    name = "Chebyshev_28";
                    simplef = Chebyshev_28();
                    grad_simplef.push_back( psf( Chebyshev_28_grad() ) );
                    hess_simplef[0].push_back( psf( Chebyshev_28_hess() ) );
                    break;
                case 29:
                    name = "Chebyshev_29";
                    simplef = Chebyshev_29();
                    grad_simplef.push_back( psf( Chebyshev_29_grad() ) );
                    hess_simplef[0].push_back( psf( Chebyshev_29_hess() ) );
                    break;
            }
            PFlexFunction< double, double > tmp( name, var_name, var_description, simplef, grad_simplef, hess_simplef);
            return PFunction< double, double>( tmp );
        }

        size_type max_size() const
        {
            return 30;
        }

        void resize(size_type N) 
        {
            Chebyshev tmp(*this);
            construct(N);
            copy(tmp);
        }

    private:
        double eval(size_type term, const double &var)
        {
            return _basis_function[term](var);
        }

        double eval_grad(size_type term, const double &var)
        {
            return _basis_function[term].grad(var, 0);
        }

        double eval_hess(size_type term, const double &var)
        {
            return _basis_function[term].hess(var, 0, 0);
        }

        void construct(size_type N)
        {
            if( N > max_size() ){ std::cout << "Error in Chebyshev. Requested size " << N << ". Max size is" << max_size() << "."; exit(1);}
            this->_name = "Chebyshev";
            this->_description = "Chebyshev Polynomials up to term 30";
            this->_val.resize(N);
            this->_grad_val.resize(N);
            this->_hess_val.resize(N);
            _basis_function.resize(N);
            for( size_type i=0; i<size(); i++)
            {
                _basis_function[i] = basis_function(i);
            }
        }

        void copy(const Chebyshev &RHS )
        {
            this->_name = RHS._name;
            this->_description = RHS._description;
            size_type lim = RHS.size() < this->size() ? RHS.size() : this->size();
            for( size_type i=0; i<lim; i++)
            {
                this->_val[i] = RHS._val[i];
                this->_grad_val[i] = RHS._grad_val[i];
                this->_hess_val[i] = RHS._hess_val[i];
                _basis_function[i] = RHS._basis_function[i];
            }
        }

    };
}
#endif
