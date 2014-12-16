#ifndef Monomial_HH
#define Monomial_HH

#include <cmath>
#include <cstdlib>
#include "IntegrationTools/PFunction.hh"

namespace PRISMS
{
    class Monomial_0 : public PSimpleBase< double, double>
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

        Monomial_0* clone() const
        {
            return new Monomial_0(*this);
        }
    };

    class Monomial_1 : public PSimpleBase< double, double>
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

        Monomial_1* clone() const
        {
            return new Monomial_1(*this);
        }
    };

    class Monomial_2 : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return (var*var);
        }

    public:
        std::string csrc() const
        {
            return "(var*var)";
        }

        std::string sym() const
        {
            return "x^2";
        }

        std::string latex() const
        {
            return "x^{2}";
        }

        Monomial_2* clone() const
        {
            return new Monomial_2(*this);
        }
    };

    class Monomial_3 : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return (var*var*var);
        }

    public:
        std::string csrc() const
        {
            return "(var*var*var)";
        }

        std::string sym() const
        {
            return "x^3";
        }

        std::string latex() const
        {
            return "x^{3}";
        }

        Monomial_3* clone() const
        {
            return new Monomial_3(*this);
        }
    };

    class Monomial_4 : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return ((var*var)*(var*var));
        }

    public:
        std::string csrc() const
        {
            return "((var*var)*(var*var))";
        }

        std::string sym() const
        {
            return "x^4";
        }

        std::string latex() const
        {
            return "x^{4}";
        }

        Monomial_4* clone() const
        {
            return new Monomial_4(*this);
        }
    };

    class Monomial_5 : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return (var*(var*var)*(var*var));
        }

    public:
        std::string csrc() const
        {
            return "(var*(var*var)*(var*var))";
        }

        std::string sym() const
        {
            return "x^5";
        }

        std::string latex() const
        {
            return "x^{5}";
        }

        Monomial_5* clone() const
        {
            return new Monomial_5(*this);
        }
    };

    class Monomial_6 : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return ((var*var*var)*(var*var*var));
        }

    public:
        std::string csrc() const
        {
            return "((var*var*var)*(var*var*var))";
        }

        std::string sym() const
        {
            return "x^6";
        }

        std::string latex() const
        {
            return "x^{6}";
        }

        Monomial_6* clone() const
        {
            return new Monomial_6(*this);
        }
    };

    class Monomial_7 : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return (var*(var*var*var)*(var*var*var));
        }

    public:
        std::string csrc() const
        {
            return "(var*(var*var*var)*(var*var*var))";
        }

        std::string sym() const
        {
            return "x^7";
        }

        std::string latex() const
        {
            return "x^{7}";
        }

        Monomial_7* clone() const
        {
            return new Monomial_7(*this);
        }
    };

    class Monomial_8 : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return (((var*var)*(var*var))*((var*var)*(var*var)));
        }

    public:
        std::string csrc() const
        {
            return "(((var*var)*(var*var))*((var*var)*(var*var)))";
        }

        std::string sym() const
        {
            return "x^8";
        }

        std::string latex() const
        {
            return "x^{8}";
        }

        Monomial_8* clone() const
        {
            return new Monomial_8(*this);
        }
    };

    class Monomial_9 : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return (var*((var*var)*(var*var))*((var*var)*(var*var)));
        }

    public:
        std::string csrc() const
        {
            return "(var*((var*var)*(var*var))*((var*var)*(var*var)))";
        }

        std::string sym() const
        {
            return "x^9";
        }

        std::string latex() const
        {
            return "x^{9}";
        }

        Monomial_9* clone() const
        {
            return new Monomial_9(*this);
        }
    };

    class Monomial_10 : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return ((var*(var*var)*(var*var))*(var*(var*var)*(var*var)));
        }

    public:
        std::string csrc() const
        {
            return "((var*(var*var)*(var*var))*(var*(var*var)*(var*var)))";
        }

        std::string sym() const
        {
            return "x^10";
        }

        std::string latex() const
        {
            return "x^{10}";
        }

        Monomial_10* clone() const
        {
            return new Monomial_10(*this);
        }
    };

    class Monomial_11 : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return (var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var)));
        }

    public:
        std::string csrc() const
        {
            return "(var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var)))";
        }

        std::string sym() const
        {
            return "x^11";
        }

        std::string latex() const
        {
            return "x^{11}";
        }

        Monomial_11* clone() const
        {
            return new Monomial_11(*this);
        }
    };

    class Monomial_12 : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return (((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)));
        }

    public:
        std::string csrc() const
        {
            return "(((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))";
        }

        std::string sym() const
        {
            return "x^12";
        }

        std::string latex() const
        {
            return "x^{12}";
        }

        Monomial_12* clone() const
        {
            return new Monomial_12(*this);
        }
    };

    class Monomial_13 : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return (var*((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)));
        }

    public:
        std::string csrc() const
        {
            return "(var*((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))";
        }

        std::string sym() const
        {
            return "x^13";
        }

        std::string latex() const
        {
            return "x^{13}";
        }

        Monomial_13* clone() const
        {
            return new Monomial_13(*this);
        }
    };

    class Monomial_14 : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return ((var*(var*var*var)*(var*var*var))*(var*(var*var*var)*(var*var*var)));
        }

    public:
        std::string csrc() const
        {
            return "((var*(var*var*var)*(var*var*var))*(var*(var*var*var)*(var*var*var)))";
        }

        std::string sym() const
        {
            return "x^14";
        }

        std::string latex() const
        {
            return "x^{14}";
        }

        Monomial_14* clone() const
        {
            return new Monomial_14(*this);
        }
    };

    class Monomial_15 : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return (var*(var*(var*var*var)*(var*var*var))*(var*(var*var*var)*(var*var*var)));
        }

    public:
        std::string csrc() const
        {
            return "(var*(var*(var*var*var)*(var*var*var))*(var*(var*var*var)*(var*var*var)))";
        }

        std::string sym() const
        {
            return "x^15";
        }

        std::string latex() const
        {
            return "x^{15}";
        }

        Monomial_15* clone() const
        {
            return new Monomial_15(*this);
        }
    };

    class Monomial_16 : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return ((((var*var)*(var*var))*((var*var)*(var*var)))*(((var*var)*(var*var))*((var*var)*(var*var))));
        }

    public:
        std::string csrc() const
        {
            return "((((var*var)*(var*var))*((var*var)*(var*var)))*(((var*var)*(var*var))*((var*var)*(var*var))))";
        }

        std::string sym() const
        {
            return "x^16";
        }

        std::string latex() const
        {
            return "x^{16}";
        }

        Monomial_16* clone() const
        {
            return new Monomial_16(*this);
        }
    };

    class Monomial_17 : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return (var*(((var*var)*(var*var))*((var*var)*(var*var)))*(((var*var)*(var*var))*((var*var)*(var*var))));
        }

    public:
        std::string csrc() const
        {
            return "(var*(((var*var)*(var*var))*((var*var)*(var*var)))*(((var*var)*(var*var))*((var*var)*(var*var))))";
        }

        std::string sym() const
        {
            return "x^17";
        }

        std::string latex() const
        {
            return "x^{17}";
        }

        Monomial_17* clone() const
        {
            return new Monomial_17(*this);
        }
    };

    class Monomial_18 : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return ((var*((var*var)*(var*var))*((var*var)*(var*var)))*(var*((var*var)*(var*var))*((var*var)*(var*var))));
        }

    public:
        std::string csrc() const
        {
            return "((var*((var*var)*(var*var))*((var*var)*(var*var)))*(var*((var*var)*(var*var))*((var*var)*(var*var))))";
        }

        std::string sym() const
        {
            return "x^18";
        }

        std::string latex() const
        {
            return "x^{18}";
        }

        Monomial_18* clone() const
        {
            return new Monomial_18(*this);
        }
    };

    class Monomial_19 : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return (var*(var*((var*var)*(var*var))*((var*var)*(var*var)))*(var*((var*var)*(var*var))*((var*var)*(var*var))));
        }

    public:
        std::string csrc() const
        {
            return "(var*(var*((var*var)*(var*var))*((var*var)*(var*var)))*(var*((var*var)*(var*var))*((var*var)*(var*var))))";
        }

        std::string sym() const
        {
            return "x^19";
        }

        std::string latex() const
        {
            return "x^{19}";
        }

        Monomial_19* clone() const
        {
            return new Monomial_19(*this);
        }
    };

    class Monomial_20 : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return (((var*(var*var)*(var*var))*(var*(var*var)*(var*var)))*((var*(var*var)*(var*var))*(var*(var*var)*(var*var))));
        }

    public:
        std::string csrc() const
        {
            return "(((var*(var*var)*(var*var))*(var*(var*var)*(var*var)))*((var*(var*var)*(var*var))*(var*(var*var)*(var*var))))";
        }

        std::string sym() const
        {
            return "x^20";
        }

        std::string latex() const
        {
            return "x^{20}";
        }

        Monomial_20* clone() const
        {
            return new Monomial_20(*this);
        }
    };

    class Monomial_21 : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return (var*((var*(var*var)*(var*var))*(var*(var*var)*(var*var)))*((var*(var*var)*(var*var))*(var*(var*var)*(var*var))));
        }

    public:
        std::string csrc() const
        {
            return "(var*((var*(var*var)*(var*var))*(var*(var*var)*(var*var)))*((var*(var*var)*(var*var))*(var*(var*var)*(var*var))))";
        }

        std::string sym() const
        {
            return "x^21";
        }

        std::string latex() const
        {
            return "x^{21}";
        }

        Monomial_21* clone() const
        {
            return new Monomial_21(*this);
        }
    };

    class Monomial_22 : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return ((var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var)))*(var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var))));
        }

    public:
        std::string csrc() const
        {
            return "((var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var)))*(var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var))))";
        }

        std::string sym() const
        {
            return "x^22";
        }

        std::string latex() const
        {
            return "x^{22}";
        }

        Monomial_22* clone() const
        {
            return new Monomial_22(*this);
        }
    };

    class Monomial_23 : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return (var*(var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var)))*(var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var))));
        }

    public:
        std::string csrc() const
        {
            return "(var*(var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var)))*(var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var))))";
        }

        std::string sym() const
        {
            return "x^23";
        }

        std::string latex() const
        {
            return "x^{23}";
        }

        Monomial_23* clone() const
        {
            return new Monomial_23(*this);
        }
    };

    class Monomial_24 : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return ((((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))*(((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var))));
        }

    public:
        std::string csrc() const
        {
            return "((((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))*(((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var))))";
        }

        std::string sym() const
        {
            return "x^24";
        }

        std::string latex() const
        {
            return "x^{24}";
        }

        Monomial_24* clone() const
        {
            return new Monomial_24(*this);
        }
    };

    class Monomial_25 : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return (var*(((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))*(((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var))));
        }

    public:
        std::string csrc() const
        {
            return "(var*(((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))*(((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var))))";
        }

        std::string sym() const
        {
            return "x^25";
        }

        std::string latex() const
        {
            return "x^{25}";
        }

        Monomial_25* clone() const
        {
            return new Monomial_25(*this);
        }
    };

    class Monomial_26 : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return ((var*((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))*(var*((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var))));
        }

    public:
        std::string csrc() const
        {
            return "((var*((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))*(var*((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var))))";
        }

        std::string sym() const
        {
            return "x^26";
        }

        std::string latex() const
        {
            return "x^{26}";
        }

        Monomial_26* clone() const
        {
            return new Monomial_26(*this);
        }
    };

    class Monomial_27 : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return (var*(var*((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))*(var*((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var))));
        }

    public:
        std::string csrc() const
        {
            return "(var*(var*((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))*(var*((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var))))";
        }

        std::string sym() const
        {
            return "x^27";
        }

        std::string latex() const
        {
            return "x^{27}";
        }

        Monomial_27* clone() const
        {
            return new Monomial_27(*this);
        }
    };

    class Monomial_28 : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return (((var*(var*var*var)*(var*var*var))*(var*(var*var*var)*(var*var*var)))*((var*(var*var*var)*(var*var*var))*(var*(var*var*var)*(var*var*var))));
        }

    public:
        std::string csrc() const
        {
            return "(((var*(var*var*var)*(var*var*var))*(var*(var*var*var)*(var*var*var)))*((var*(var*var*var)*(var*var*var))*(var*(var*var*var)*(var*var*var))))";
        }

        std::string sym() const
        {
            return "x^28";
        }

        std::string latex() const
        {
            return "x^{28}";
        }

        Monomial_28* clone() const
        {
            return new Monomial_28(*this);
        }
    };

    class Monomial_29 : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return (var*((var*(var*var*var)*(var*var*var))*(var*(var*var*var)*(var*var*var)))*((var*(var*var*var)*(var*var*var))*(var*(var*var*var)*(var*var*var))));
        }

    public:
        std::string csrc() const
        {
            return "(var*((var*(var*var*var)*(var*var*var))*(var*(var*var*var)*(var*var*var)))*((var*(var*var*var)*(var*var*var))*(var*(var*var*var)*(var*var*var))))";
        }

        std::string sym() const
        {
            return "x^29";
        }

        std::string latex() const
        {
            return "x^{29}";
        }

        Monomial_29* clone() const
        {
            return new Monomial_29(*this);
        }
    };

    class Monomial_0_grad : public PSimpleBase< double, double>
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

        Monomial_0_grad* clone() const
        {
            return new Monomial_0_grad(*this);
        }
    };

    class Monomial_1_grad : public PSimpleBase< double, double>
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

        Monomial_1_grad* clone() const
        {
            return new Monomial_1_grad(*this);
        }
    };

    class Monomial_2_grad : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return 2.0*var;
        }

    public:
        std::string csrc() const
        {
            return "2.0*var";
        }

        std::string sym() const
        {
            return "2*x";
        }

        std::string latex() const
        {
            return "2  x";
        }

        Monomial_2_grad* clone() const
        {
            return new Monomial_2_grad(*this);
        }
    };

    class Monomial_3_grad : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return 3.0*(var*var);
        }

    public:
        std::string csrc() const
        {
            return "3.0*(var*var)";
        }

        std::string sym() const
        {
            return "3*x^2";
        }

        std::string latex() const
        {
            return "3  x^{2}";
        }

        Monomial_3_grad* clone() const
        {
            return new Monomial_3_grad(*this);
        }
    };

    class Monomial_4_grad : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return 4.0*(var*var*var);
        }

    public:
        std::string csrc() const
        {
            return "4.0*(var*var*var)";
        }

        std::string sym() const
        {
            return "4*x^3";
        }

        std::string latex() const
        {
            return "4  x^{3}";
        }

        Monomial_4_grad* clone() const
        {
            return new Monomial_4_grad(*this);
        }
    };

    class Monomial_5_grad : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return 5.0*((var*var)*(var*var));
        }

    public:
        std::string csrc() const
        {
            return "5.0*((var*var)*(var*var))";
        }

        std::string sym() const
        {
            return "5*x^4";
        }

        std::string latex() const
        {
            return "5  x^{4}";
        }

        Monomial_5_grad* clone() const
        {
            return new Monomial_5_grad(*this);
        }
    };

    class Monomial_6_grad : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return 6.0*(var*(var*var)*(var*var));
        }

    public:
        std::string csrc() const
        {
            return "6.0*(var*(var*var)*(var*var))";
        }

        std::string sym() const
        {
            return "6*x^5";
        }

        std::string latex() const
        {
            return "6  x^{5}";
        }

        Monomial_6_grad* clone() const
        {
            return new Monomial_6_grad(*this);
        }
    };

    class Monomial_7_grad : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return 7.0*((var*var*var)*(var*var*var));
        }

    public:
        std::string csrc() const
        {
            return "7.0*((var*var*var)*(var*var*var))";
        }

        std::string sym() const
        {
            return "7*x^6";
        }

        std::string latex() const
        {
            return "7  x^{6}";
        }

        Monomial_7_grad* clone() const
        {
            return new Monomial_7_grad(*this);
        }
    };

    class Monomial_8_grad : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return 8.0*(var*(var*var*var)*(var*var*var));
        }

    public:
        std::string csrc() const
        {
            return "8.0*(var*(var*var*var)*(var*var*var))";
        }

        std::string sym() const
        {
            return "8*x^7";
        }

        std::string latex() const
        {
            return "8  x^{7}";
        }

        Monomial_8_grad* clone() const
        {
            return new Monomial_8_grad(*this);
        }
    };

    class Monomial_9_grad : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return 9.0*(((var*var)*(var*var))*((var*var)*(var*var)));
        }

    public:
        std::string csrc() const
        {
            return "9.0*(((var*var)*(var*var))*((var*var)*(var*var)))";
        }

        std::string sym() const
        {
            return "9*x^8";
        }

        std::string latex() const
        {
            return "9  x^{8}";
        }

        Monomial_9_grad* clone() const
        {
            return new Monomial_9_grad(*this);
        }
    };

    class Monomial_10_grad : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return 10.0*(var*((var*var)*(var*var))*((var*var)*(var*var)));
        }

    public:
        std::string csrc() const
        {
            return "10.0*(var*((var*var)*(var*var))*((var*var)*(var*var)))";
        }

        std::string sym() const
        {
            return "10*x^9";
        }

        std::string latex() const
        {
            return "10  x^{9}";
        }

        Monomial_10_grad* clone() const
        {
            return new Monomial_10_grad(*this);
        }
    };

    class Monomial_11_grad : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return 11.0*((var*(var*var)*(var*var))*(var*(var*var)*(var*var)));
        }

    public:
        std::string csrc() const
        {
            return "11.0*((var*(var*var)*(var*var))*(var*(var*var)*(var*var)))";
        }

        std::string sym() const
        {
            return "11*x^10";
        }

        std::string latex() const
        {
            return "11  x^{10}";
        }

        Monomial_11_grad* clone() const
        {
            return new Monomial_11_grad(*this);
        }
    };

    class Monomial_12_grad : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return 12.0*(var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var)));
        }

    public:
        std::string csrc() const
        {
            return "12.0*(var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var)))";
        }

        std::string sym() const
        {
            return "12*x^11";
        }

        std::string latex() const
        {
            return "12  x^{11}";
        }

        Monomial_12_grad* clone() const
        {
            return new Monomial_12_grad(*this);
        }
    };

    class Monomial_13_grad : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return 13.0*(((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)));
        }

    public:
        std::string csrc() const
        {
            return "13.0*(((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))";
        }

        std::string sym() const
        {
            return "13*x^12";
        }

        std::string latex() const
        {
            return "13  x^{12}";
        }

        Monomial_13_grad* clone() const
        {
            return new Monomial_13_grad(*this);
        }
    };

    class Monomial_14_grad : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return 14.0*(var*((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)));
        }

    public:
        std::string csrc() const
        {
            return "14.0*(var*((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))";
        }

        std::string sym() const
        {
            return "14*x^13";
        }

        std::string latex() const
        {
            return "14  x^{13}";
        }

        Monomial_14_grad* clone() const
        {
            return new Monomial_14_grad(*this);
        }
    };

    class Monomial_15_grad : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return 15.0*((var*(var*var*var)*(var*var*var))*(var*(var*var*var)*(var*var*var)));
        }

    public:
        std::string csrc() const
        {
            return "15.0*((var*(var*var*var)*(var*var*var))*(var*(var*var*var)*(var*var*var)))";
        }

        std::string sym() const
        {
            return "15*x^14";
        }

        std::string latex() const
        {
            return "15  x^{14}";
        }

        Monomial_15_grad* clone() const
        {
            return new Monomial_15_grad(*this);
        }
    };

    class Monomial_16_grad : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return 16.0*(var*(var*(var*var*var)*(var*var*var))*(var*(var*var*var)*(var*var*var)));
        }

    public:
        std::string csrc() const
        {
            return "16.0*(var*(var*(var*var*var)*(var*var*var))*(var*(var*var*var)*(var*var*var)))";
        }

        std::string sym() const
        {
            return "16*x^15";
        }

        std::string latex() const
        {
            return "16  x^{15}";
        }

        Monomial_16_grad* clone() const
        {
            return new Monomial_16_grad(*this);
        }
    };

    class Monomial_17_grad : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return 17.0*((((var*var)*(var*var))*((var*var)*(var*var)))*(((var*var)*(var*var))*((var*var)*(var*var))));
        }

    public:
        std::string csrc() const
        {
            return "17.0*((((var*var)*(var*var))*((var*var)*(var*var)))*(((var*var)*(var*var))*((var*var)*(var*var))))";
        }

        std::string sym() const
        {
            return "17*x^16";
        }

        std::string latex() const
        {
            return "17  x^{16}";
        }

        Monomial_17_grad* clone() const
        {
            return new Monomial_17_grad(*this);
        }
    };

    class Monomial_18_grad : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return 18.0*(var*(((var*var)*(var*var))*((var*var)*(var*var)))*(((var*var)*(var*var))*((var*var)*(var*var))));
        }

    public:
        std::string csrc() const
        {
            return "18.0*(var*(((var*var)*(var*var))*((var*var)*(var*var)))*(((var*var)*(var*var))*((var*var)*(var*var))))";
        }

        std::string sym() const
        {
            return "18*x^17";
        }

        std::string latex() const
        {
            return "18  x^{17}";
        }

        Monomial_18_grad* clone() const
        {
            return new Monomial_18_grad(*this);
        }
    };

    class Monomial_19_grad : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return 19.0*((var*((var*var)*(var*var))*((var*var)*(var*var)))*(var*((var*var)*(var*var))*((var*var)*(var*var))));
        }

    public:
        std::string csrc() const
        {
            return "19.0*((var*((var*var)*(var*var))*((var*var)*(var*var)))*(var*((var*var)*(var*var))*((var*var)*(var*var))))";
        }

        std::string sym() const
        {
            return "19*x^18";
        }

        std::string latex() const
        {
            return "19  x^{18}";
        }

        Monomial_19_grad* clone() const
        {
            return new Monomial_19_grad(*this);
        }
    };

    class Monomial_20_grad : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return 20.0*(var*(var*((var*var)*(var*var))*((var*var)*(var*var)))*(var*((var*var)*(var*var))*((var*var)*(var*var))));
        }

    public:
        std::string csrc() const
        {
            return "20.0*(var*(var*((var*var)*(var*var))*((var*var)*(var*var)))*(var*((var*var)*(var*var))*((var*var)*(var*var))))";
        }

        std::string sym() const
        {
            return "20*x^19";
        }

        std::string latex() const
        {
            return "20  x^{19}";
        }

        Monomial_20_grad* clone() const
        {
            return new Monomial_20_grad(*this);
        }
    };

    class Monomial_21_grad : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return 21.0*(((var*(var*var)*(var*var))*(var*(var*var)*(var*var)))*((var*(var*var)*(var*var))*(var*(var*var)*(var*var))));
        }

    public:
        std::string csrc() const
        {
            return "21.0*(((var*(var*var)*(var*var))*(var*(var*var)*(var*var)))*((var*(var*var)*(var*var))*(var*(var*var)*(var*var))))";
        }

        std::string sym() const
        {
            return "21*x^20";
        }

        std::string latex() const
        {
            return "21  x^{20}";
        }

        Monomial_21_grad* clone() const
        {
            return new Monomial_21_grad(*this);
        }
    };

    class Monomial_22_grad : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return 22.0*(var*((var*(var*var)*(var*var))*(var*(var*var)*(var*var)))*((var*(var*var)*(var*var))*(var*(var*var)*(var*var))));
        }

    public:
        std::string csrc() const
        {
            return "22.0*(var*((var*(var*var)*(var*var))*(var*(var*var)*(var*var)))*((var*(var*var)*(var*var))*(var*(var*var)*(var*var))))";
        }

        std::string sym() const
        {
            return "22*x^21";
        }

        std::string latex() const
        {
            return "22  x^{21}";
        }

        Monomial_22_grad* clone() const
        {
            return new Monomial_22_grad(*this);
        }
    };

    class Monomial_23_grad : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return 23.0*((var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var)))*(var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var))));
        }

    public:
        std::string csrc() const
        {
            return "23.0*((var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var)))*(var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var))))";
        }

        std::string sym() const
        {
            return "23*x^22";
        }

        std::string latex() const
        {
            return "23  x^{22}";
        }

        Monomial_23_grad* clone() const
        {
            return new Monomial_23_grad(*this);
        }
    };

    class Monomial_24_grad : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return 24.0*(var*(var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var)))*(var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var))));
        }

    public:
        std::string csrc() const
        {
            return "24.0*(var*(var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var)))*(var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var))))";
        }

        std::string sym() const
        {
            return "24*x^23";
        }

        std::string latex() const
        {
            return "24  x^{23}";
        }

        Monomial_24_grad* clone() const
        {
            return new Monomial_24_grad(*this);
        }
    };

    class Monomial_25_grad : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return 25.0*((((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))*(((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var))));
        }

    public:
        std::string csrc() const
        {
            return "25.0*((((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))*(((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var))))";
        }

        std::string sym() const
        {
            return "25*x^24";
        }

        std::string latex() const
        {
            return "25  x^{24}";
        }

        Monomial_25_grad* clone() const
        {
            return new Monomial_25_grad(*this);
        }
    };

    class Monomial_26_grad : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return 26.0*(var*(((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))*(((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var))));
        }

    public:
        std::string csrc() const
        {
            return "26.0*(var*(((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))*(((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var))))";
        }

        std::string sym() const
        {
            return "26*x^25";
        }

        std::string latex() const
        {
            return "26  x^{25}";
        }

        Monomial_26_grad* clone() const
        {
            return new Monomial_26_grad(*this);
        }
    };

    class Monomial_27_grad : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return 27.0*((var*((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))*(var*((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var))));
        }

    public:
        std::string csrc() const
        {
            return "27.0*((var*((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))*(var*((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var))))";
        }

        std::string sym() const
        {
            return "27*x^26";
        }

        std::string latex() const
        {
            return "27  x^{26}";
        }

        Monomial_27_grad* clone() const
        {
            return new Monomial_27_grad(*this);
        }
    };

    class Monomial_28_grad : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return 28.0*(var*(var*((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))*(var*((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var))));
        }

    public:
        std::string csrc() const
        {
            return "28.0*(var*(var*((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))*(var*((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var))))";
        }

        std::string sym() const
        {
            return "28*x^27";
        }

        std::string latex() const
        {
            return "28  x^{27}";
        }

        Monomial_28_grad* clone() const
        {
            return new Monomial_28_grad(*this);
        }
    };

    class Monomial_29_grad : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return 29.0*(((var*(var*var*var)*(var*var*var))*(var*(var*var*var)*(var*var*var)))*((var*(var*var*var)*(var*var*var))*(var*(var*var*var)*(var*var*var))));
        }

    public:
        std::string csrc() const
        {
            return "29.0*(((var*(var*var*var)*(var*var*var))*(var*(var*var*var)*(var*var*var)))*((var*(var*var*var)*(var*var*var))*(var*(var*var*var)*(var*var*var))))";
        }

        std::string sym() const
        {
            return "29*x^28";
        }

        std::string latex() const
        {
            return "29  x^{28}";
        }

        Monomial_29_grad* clone() const
        {
            return new Monomial_29_grad(*this);
        }
    };

    class Monomial_0_hess : public PSimpleBase< double, double>
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

        Monomial_0_hess* clone() const
        {
            return new Monomial_0_hess(*this);
        }
    };

    class Monomial_1_hess : public PSimpleBase< double, double>
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

        Monomial_1_hess* clone() const
        {
            return new Monomial_1_hess(*this);
        }
    };

    class Monomial_2_hess : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return 2.0;
        }

    public:
        std::string csrc() const
        {
            return "2.0";
        }

        std::string sym() const
        {
            return "2";
        }

        std::string latex() const
        {
            return "2";
        }

        Monomial_2_hess* clone() const
        {
            return new Monomial_2_hess(*this);
        }
    };

    class Monomial_3_hess : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return 6.0*var;
        }

    public:
        std::string csrc() const
        {
            return "6.0*var";
        }

        std::string sym() const
        {
            return "6*x";
        }

        std::string latex() const
        {
            return "6  x";
        }

        Monomial_3_hess* clone() const
        {
            return new Monomial_3_hess(*this);
        }
    };

    class Monomial_4_hess : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return 12.0*(var*var);
        }

    public:
        std::string csrc() const
        {
            return "12.0*(var*var)";
        }

        std::string sym() const
        {
            return "12*x^2";
        }

        std::string latex() const
        {
            return "12  x^{2}";
        }

        Monomial_4_hess* clone() const
        {
            return new Monomial_4_hess(*this);
        }
    };

    class Monomial_5_hess : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return 20.0*(var*var*var);
        }

    public:
        std::string csrc() const
        {
            return "20.0*(var*var*var)";
        }

        std::string sym() const
        {
            return "20*x^3";
        }

        std::string latex() const
        {
            return "20  x^{3}";
        }

        Monomial_5_hess* clone() const
        {
            return new Monomial_5_hess(*this);
        }
    };

    class Monomial_6_hess : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return 30.0*((var*var)*(var*var));
        }

    public:
        std::string csrc() const
        {
            return "30.0*((var*var)*(var*var))";
        }

        std::string sym() const
        {
            return "30*x^4";
        }

        std::string latex() const
        {
            return "30  x^{4}";
        }

        Monomial_6_hess* clone() const
        {
            return new Monomial_6_hess(*this);
        }
    };

    class Monomial_7_hess : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return 42.0*(var*(var*var)*(var*var));
        }

    public:
        std::string csrc() const
        {
            return "42.0*(var*(var*var)*(var*var))";
        }

        std::string sym() const
        {
            return "42*x^5";
        }

        std::string latex() const
        {
            return "42  x^{5}";
        }

        Monomial_7_hess* clone() const
        {
            return new Monomial_7_hess(*this);
        }
    };

    class Monomial_8_hess : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return 56.0*((var*var*var)*(var*var*var));
        }

    public:
        std::string csrc() const
        {
            return "56.0*((var*var*var)*(var*var*var))";
        }

        std::string sym() const
        {
            return "56*x^6";
        }

        std::string latex() const
        {
            return "56  x^{6}";
        }

        Monomial_8_hess* clone() const
        {
            return new Monomial_8_hess(*this);
        }
    };

    class Monomial_9_hess : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return 72.0*(var*(var*var*var)*(var*var*var));
        }

    public:
        std::string csrc() const
        {
            return "72.0*(var*(var*var*var)*(var*var*var))";
        }

        std::string sym() const
        {
            return "72*x^7";
        }

        std::string latex() const
        {
            return "72  x^{7}";
        }

        Monomial_9_hess* clone() const
        {
            return new Monomial_9_hess(*this);
        }
    };

    class Monomial_10_hess : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return 90.0*(((var*var)*(var*var))*((var*var)*(var*var)));
        }

    public:
        std::string csrc() const
        {
            return "90.0*(((var*var)*(var*var))*((var*var)*(var*var)))";
        }

        std::string sym() const
        {
            return "90*x^8";
        }

        std::string latex() const
        {
            return "90  x^{8}";
        }

        Monomial_10_hess* clone() const
        {
            return new Monomial_10_hess(*this);
        }
    };

    class Monomial_11_hess : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return 110.0*(var*((var*var)*(var*var))*((var*var)*(var*var)));
        }

    public:
        std::string csrc() const
        {
            return "110.0*(var*((var*var)*(var*var))*((var*var)*(var*var)))";
        }

        std::string sym() const
        {
            return "110*x^9";
        }

        std::string latex() const
        {
            return "110  x^{9}";
        }

        Monomial_11_hess* clone() const
        {
            return new Monomial_11_hess(*this);
        }
    };

    class Monomial_12_hess : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return 132.0*((var*(var*var)*(var*var))*(var*(var*var)*(var*var)));
        }

    public:
        std::string csrc() const
        {
            return "132.0*((var*(var*var)*(var*var))*(var*(var*var)*(var*var)))";
        }

        std::string sym() const
        {
            return "132*x^10";
        }

        std::string latex() const
        {
            return "132  x^{10}";
        }

        Monomial_12_hess* clone() const
        {
            return new Monomial_12_hess(*this);
        }
    };

    class Monomial_13_hess : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return 156.0*(var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var)));
        }

    public:
        std::string csrc() const
        {
            return "156.0*(var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var)))";
        }

        std::string sym() const
        {
            return "156*x^11";
        }

        std::string latex() const
        {
            return "156  x^{11}";
        }

        Monomial_13_hess* clone() const
        {
            return new Monomial_13_hess(*this);
        }
    };

    class Monomial_14_hess : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return 182.0*(((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)));
        }

    public:
        std::string csrc() const
        {
            return "182.0*(((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))";
        }

        std::string sym() const
        {
            return "182*x^12";
        }

        std::string latex() const
        {
            return "182  x^{12}";
        }

        Monomial_14_hess* clone() const
        {
            return new Monomial_14_hess(*this);
        }
    };

    class Monomial_15_hess : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return 210.0*(var*((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)));
        }

    public:
        std::string csrc() const
        {
            return "210.0*(var*((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))";
        }

        std::string sym() const
        {
            return "210*x^13";
        }

        std::string latex() const
        {
            return "210  x^{13}";
        }

        Monomial_15_hess* clone() const
        {
            return new Monomial_15_hess(*this);
        }
    };

    class Monomial_16_hess : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return 240.0*((var*(var*var*var)*(var*var*var))*(var*(var*var*var)*(var*var*var)));
        }

    public:
        std::string csrc() const
        {
            return "240.0*((var*(var*var*var)*(var*var*var))*(var*(var*var*var)*(var*var*var)))";
        }

        std::string sym() const
        {
            return "240*x^14";
        }

        std::string latex() const
        {
            return "240  x^{14}";
        }

        Monomial_16_hess* clone() const
        {
            return new Monomial_16_hess(*this);
        }
    };

    class Monomial_17_hess : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return 272.0*(var*(var*(var*var*var)*(var*var*var))*(var*(var*var*var)*(var*var*var)));
        }

    public:
        std::string csrc() const
        {
            return "272.0*(var*(var*(var*var*var)*(var*var*var))*(var*(var*var*var)*(var*var*var)))";
        }

        std::string sym() const
        {
            return "272*x^15";
        }

        std::string latex() const
        {
            return "272  x^{15}";
        }

        Monomial_17_hess* clone() const
        {
            return new Monomial_17_hess(*this);
        }
    };

    class Monomial_18_hess : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return 306.0*((((var*var)*(var*var))*((var*var)*(var*var)))*(((var*var)*(var*var))*((var*var)*(var*var))));
        }

    public:
        std::string csrc() const
        {
            return "306.0*((((var*var)*(var*var))*((var*var)*(var*var)))*(((var*var)*(var*var))*((var*var)*(var*var))))";
        }

        std::string sym() const
        {
            return "306*x^16";
        }

        std::string latex() const
        {
            return "306  x^{16}";
        }

        Monomial_18_hess* clone() const
        {
            return new Monomial_18_hess(*this);
        }
    };

    class Monomial_19_hess : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return 342.0*(var*(((var*var)*(var*var))*((var*var)*(var*var)))*(((var*var)*(var*var))*((var*var)*(var*var))));
        }

    public:
        std::string csrc() const
        {
            return "342.0*(var*(((var*var)*(var*var))*((var*var)*(var*var)))*(((var*var)*(var*var))*((var*var)*(var*var))))";
        }

        std::string sym() const
        {
            return "342*x^17";
        }

        std::string latex() const
        {
            return "342  x^{17}";
        }

        Monomial_19_hess* clone() const
        {
            return new Monomial_19_hess(*this);
        }
    };

    class Monomial_20_hess : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return 380.0*((var*((var*var)*(var*var))*((var*var)*(var*var)))*(var*((var*var)*(var*var))*((var*var)*(var*var))));
        }

    public:
        std::string csrc() const
        {
            return "380.0*((var*((var*var)*(var*var))*((var*var)*(var*var)))*(var*((var*var)*(var*var))*((var*var)*(var*var))))";
        }

        std::string sym() const
        {
            return "380*x^18";
        }

        std::string latex() const
        {
            return "380  x^{18}";
        }

        Monomial_20_hess* clone() const
        {
            return new Monomial_20_hess(*this);
        }
    };

    class Monomial_21_hess : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return 420.0*(var*(var*((var*var)*(var*var))*((var*var)*(var*var)))*(var*((var*var)*(var*var))*((var*var)*(var*var))));
        }

    public:
        std::string csrc() const
        {
            return "420.0*(var*(var*((var*var)*(var*var))*((var*var)*(var*var)))*(var*((var*var)*(var*var))*((var*var)*(var*var))))";
        }

        std::string sym() const
        {
            return "420*x^19";
        }

        std::string latex() const
        {
            return "420  x^{19}";
        }

        Monomial_21_hess* clone() const
        {
            return new Monomial_21_hess(*this);
        }
    };

    class Monomial_22_hess : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return 462.0*(((var*(var*var)*(var*var))*(var*(var*var)*(var*var)))*((var*(var*var)*(var*var))*(var*(var*var)*(var*var))));
        }

    public:
        std::string csrc() const
        {
            return "462.0*(((var*(var*var)*(var*var))*(var*(var*var)*(var*var)))*((var*(var*var)*(var*var))*(var*(var*var)*(var*var))))";
        }

        std::string sym() const
        {
            return "462*x^20";
        }

        std::string latex() const
        {
            return "462  x^{20}";
        }

        Monomial_22_hess* clone() const
        {
            return new Monomial_22_hess(*this);
        }
    };

    class Monomial_23_hess : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return 506.0*(var*((var*(var*var)*(var*var))*(var*(var*var)*(var*var)))*((var*(var*var)*(var*var))*(var*(var*var)*(var*var))));
        }

    public:
        std::string csrc() const
        {
            return "506.0*(var*((var*(var*var)*(var*var))*(var*(var*var)*(var*var)))*((var*(var*var)*(var*var))*(var*(var*var)*(var*var))))";
        }

        std::string sym() const
        {
            return "506*x^21";
        }

        std::string latex() const
        {
            return "506  x^{21}";
        }

        Monomial_23_hess* clone() const
        {
            return new Monomial_23_hess(*this);
        }
    };

    class Monomial_24_hess : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return 552.0*((var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var)))*(var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var))));
        }

    public:
        std::string csrc() const
        {
            return "552.0*((var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var)))*(var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var))))";
        }

        std::string sym() const
        {
            return "552*x^22";
        }

        std::string latex() const
        {
            return "552  x^{22}";
        }

        Monomial_24_hess* clone() const
        {
            return new Monomial_24_hess(*this);
        }
    };

    class Monomial_25_hess : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return 600.0*(var*(var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var)))*(var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var))));
        }

    public:
        std::string csrc() const
        {
            return "600.0*(var*(var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var)))*(var*(var*(var*var)*(var*var))*(var*(var*var)*(var*var))))";
        }

        std::string sym() const
        {
            return "600*x^23";
        }

        std::string latex() const
        {
            return "600  x^{23}";
        }

        Monomial_25_hess* clone() const
        {
            return new Monomial_25_hess(*this);
        }
    };

    class Monomial_26_hess : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return 650.0*((((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))*(((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var))));
        }

    public:
        std::string csrc() const
        {
            return "650.0*((((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))*(((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var))))";
        }

        std::string sym() const
        {
            return "650*x^24";
        }

        std::string latex() const
        {
            return "650  x^{24}";
        }

        Monomial_26_hess* clone() const
        {
            return new Monomial_26_hess(*this);
        }
    };

    class Monomial_27_hess : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return 702.0*(var*(((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))*(((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var))));
        }

    public:
        std::string csrc() const
        {
            return "702.0*(var*(((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))*(((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var))))";
        }

        std::string sym() const
        {
            return "702*x^25";
        }

        std::string latex() const
        {
            return "702  x^{25}";
        }

        Monomial_27_hess* clone() const
        {
            return new Monomial_27_hess(*this);
        }
    };

    class Monomial_28_hess : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return 756.0*((var*((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))*(var*((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var))));
        }

    public:
        std::string csrc() const
        {
            return "756.0*((var*((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))*(var*((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var))))";
        }

        std::string sym() const
        {
            return "756*x^26";
        }

        std::string latex() const
        {
            return "756  x^{26}";
        }

        Monomial_28_hess* clone() const
        {
            return new Monomial_28_hess(*this);
        }
    };

    class Monomial_29_hess : public PSimpleBase< double, double>
    {
        double eval( const double &var) const
        {
            return 812.0*(var*(var*((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))*(var*((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var))));
        }

    public:
        std::string csrc() const
        {
            return "812.0*(var*(var*((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var)))*(var*((var*var*var)*(var*var*var))*((var*var*var)*(var*var*var))))";
        }

        std::string sym() const
        {
            return "812*x^27";
        }

        std::string latex() const
        {
            return "812  x^{27}";
        }

        Monomial_29_hess* clone() const
        {
            return new Monomial_29_hess(*this);
        }
    };

    class Monomial : public PBasisSetBase<double, double>
    {
    public:
        
        typedef PBasisSetBase<double, double>::size_type size_type;
        
        std::vector< PFunction< double, double> > _basis_function;
        
        Monomial(size_type N) : PBasisSetBase<double, double>(N)
        {
            construct(N);
        }

        Monomial(const Monomial &RHS ) : PBasisSetBase<double, double>(RHS.size())
        {
            construct(RHS.size());
            copy(RHS);
        }

        Monomial& operator=(const Monomial &RHS )
        {
            if( this == &RHS) return *this;
            construct(RHS.size());
            copy(RHS);
            return *this;
        }

        ~Monomial()
        {
        }

        Monomial* clone() const
        {
            return new Monomial(*this);
        }

        PFunction< double, double> basis_function( size_type term) const
        {
            if(term >= max_size()){ std::cout << "Error in Monomial::basis_function( size_type term). term >= max_size()." << std::endl; exit(1);}

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
                    name = "Monomial_0";
                    simplef = Monomial_0();
                    grad_simplef.push_back( psf( Monomial_0_grad() ) );
                    hess_simplef[0].push_back( psf( Monomial_0_hess() ) );
                    break;
                case 1:
                    name = "Monomial_1";
                    simplef = Monomial_1();
                    grad_simplef.push_back( psf( Monomial_1_grad() ) );
                    hess_simplef[0].push_back( psf( Monomial_1_hess() ) );
                    break;
                case 2:
                    name = "Monomial_2";
                    simplef = Monomial_2();
                    grad_simplef.push_back( psf( Monomial_2_grad() ) );
                    hess_simplef[0].push_back( psf( Monomial_2_hess() ) );
                    break;
                case 3:
                    name = "Monomial_3";
                    simplef = Monomial_3();
                    grad_simplef.push_back( psf( Monomial_3_grad() ) );
                    hess_simplef[0].push_back( psf( Monomial_3_hess() ) );
                    break;
                case 4:
                    name = "Monomial_4";
                    simplef = Monomial_4();
                    grad_simplef.push_back( psf( Monomial_4_grad() ) );
                    hess_simplef[0].push_back( psf( Monomial_4_hess() ) );
                    break;
                case 5:
                    name = "Monomial_5";
                    simplef = Monomial_5();
                    grad_simplef.push_back( psf( Monomial_5_grad() ) );
                    hess_simplef[0].push_back( psf( Monomial_5_hess() ) );
                    break;
                case 6:
                    name = "Monomial_6";
                    simplef = Monomial_6();
                    grad_simplef.push_back( psf( Monomial_6_grad() ) );
                    hess_simplef[0].push_back( psf( Monomial_6_hess() ) );
                    break;
                case 7:
                    name = "Monomial_7";
                    simplef = Monomial_7();
                    grad_simplef.push_back( psf( Monomial_7_grad() ) );
                    hess_simplef[0].push_back( psf( Monomial_7_hess() ) );
                    break;
                case 8:
                    name = "Monomial_8";
                    simplef = Monomial_8();
                    grad_simplef.push_back( psf( Monomial_8_grad() ) );
                    hess_simplef[0].push_back( psf( Monomial_8_hess() ) );
                    break;
                case 9:
                    name = "Monomial_9";
                    simplef = Monomial_9();
                    grad_simplef.push_back( psf( Monomial_9_grad() ) );
                    hess_simplef[0].push_back( psf( Monomial_9_hess() ) );
                    break;
                case 10:
                    name = "Monomial_10";
                    simplef = Monomial_10();
                    grad_simplef.push_back( psf( Monomial_10_grad() ) );
                    hess_simplef[0].push_back( psf( Monomial_10_hess() ) );
                    break;
                case 11:
                    name = "Monomial_11";
                    simplef = Monomial_11();
                    grad_simplef.push_back( psf( Monomial_11_grad() ) );
                    hess_simplef[0].push_back( psf( Monomial_11_hess() ) );
                    break;
                case 12:
                    name = "Monomial_12";
                    simplef = Monomial_12();
                    grad_simplef.push_back( psf( Monomial_12_grad() ) );
                    hess_simplef[0].push_back( psf( Monomial_12_hess() ) );
                    break;
                case 13:
                    name = "Monomial_13";
                    simplef = Monomial_13();
                    grad_simplef.push_back( psf( Monomial_13_grad() ) );
                    hess_simplef[0].push_back( psf( Monomial_13_hess() ) );
                    break;
                case 14:
                    name = "Monomial_14";
                    simplef = Monomial_14();
                    grad_simplef.push_back( psf( Monomial_14_grad() ) );
                    hess_simplef[0].push_back( psf( Monomial_14_hess() ) );
                    break;
                case 15:
                    name = "Monomial_15";
                    simplef = Monomial_15();
                    grad_simplef.push_back( psf( Monomial_15_grad() ) );
                    hess_simplef[0].push_back( psf( Monomial_15_hess() ) );
                    break;
                case 16:
                    name = "Monomial_16";
                    simplef = Monomial_16();
                    grad_simplef.push_back( psf( Monomial_16_grad() ) );
                    hess_simplef[0].push_back( psf( Monomial_16_hess() ) );
                    break;
                case 17:
                    name = "Monomial_17";
                    simplef = Monomial_17();
                    grad_simplef.push_back( psf( Monomial_17_grad() ) );
                    hess_simplef[0].push_back( psf( Monomial_17_hess() ) );
                    break;
                case 18:
                    name = "Monomial_18";
                    simplef = Monomial_18();
                    grad_simplef.push_back( psf( Monomial_18_grad() ) );
                    hess_simplef[0].push_back( psf( Monomial_18_hess() ) );
                    break;
                case 19:
                    name = "Monomial_19";
                    simplef = Monomial_19();
                    grad_simplef.push_back( psf( Monomial_19_grad() ) );
                    hess_simplef[0].push_back( psf( Monomial_19_hess() ) );
                    break;
                case 20:
                    name = "Monomial_20";
                    simplef = Monomial_20();
                    grad_simplef.push_back( psf( Monomial_20_grad() ) );
                    hess_simplef[0].push_back( psf( Monomial_20_hess() ) );
                    break;
                case 21:
                    name = "Monomial_21";
                    simplef = Monomial_21();
                    grad_simplef.push_back( psf( Monomial_21_grad() ) );
                    hess_simplef[0].push_back( psf( Monomial_21_hess() ) );
                    break;
                case 22:
                    name = "Monomial_22";
                    simplef = Monomial_22();
                    grad_simplef.push_back( psf( Monomial_22_grad() ) );
                    hess_simplef[0].push_back( psf( Monomial_22_hess() ) );
                    break;
                case 23:
                    name = "Monomial_23";
                    simplef = Monomial_23();
                    grad_simplef.push_back( psf( Monomial_23_grad() ) );
                    hess_simplef[0].push_back( psf( Monomial_23_hess() ) );
                    break;
                case 24:
                    name = "Monomial_24";
                    simplef = Monomial_24();
                    grad_simplef.push_back( psf( Monomial_24_grad() ) );
                    hess_simplef[0].push_back( psf( Monomial_24_hess() ) );
                    break;
                case 25:
                    name = "Monomial_25";
                    simplef = Monomial_25();
                    grad_simplef.push_back( psf( Monomial_25_grad() ) );
                    hess_simplef[0].push_back( psf( Monomial_25_hess() ) );
                    break;
                case 26:
                    name = "Monomial_26";
                    simplef = Monomial_26();
                    grad_simplef.push_back( psf( Monomial_26_grad() ) );
                    hess_simplef[0].push_back( psf( Monomial_26_hess() ) );
                    break;
                case 27:
                    name = "Monomial_27";
                    simplef = Monomial_27();
                    grad_simplef.push_back( psf( Monomial_27_grad() ) );
                    hess_simplef[0].push_back( psf( Monomial_27_hess() ) );
                    break;
                case 28:
                    name = "Monomial_28";
                    simplef = Monomial_28();
                    grad_simplef.push_back( psf( Monomial_28_grad() ) );
                    hess_simplef[0].push_back( psf( Monomial_28_hess() ) );
                    break;
                case 29:
                    name = "Monomial_29";
                    simplef = Monomial_29();
                    grad_simplef.push_back( psf( Monomial_29_grad() ) );
                    hess_simplef[0].push_back( psf( Monomial_29_hess() ) );
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
            Monomial tmp(*this);
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
            if( N > max_size() ){ std::cout << "Error in Monomial. Requested size " << N << ". Max size is" << max_size() << "."; exit(1);}
            this->_name = "Monomial";
            this->_description = "Monomials up to 30";
            this->_val.resize(N);
            this->_grad_val.resize(N);
            this->_hess_val.resize(N);
            _basis_function.resize(N);
            for( size_type i=0; i<size(); i++)
            {
                _basis_function[i] = basis_function(i);
            }
        }

        void copy(const Monomial &RHS )
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
