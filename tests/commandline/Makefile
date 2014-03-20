# make PFunction src

HOME = ../..
SRC = $(HOME)/src/c++
PLIB = $(HOME)/tests/testlib

test : $(PLIB)/MyFunc.hh $(PLIB)/Monomial.hh $(PLIB)/Chebyshev.hh $(PLIB)/Library.hh $(PLIB)/Library.cc

$(PLIB)/MyFunc.hh: 
	fw -n "MyFunc" -v "x" "y" -d "x variable" "y variable"  --sym "x^3 + x^2*y + x*y^2 + y^3" --grad --hess -l $(PLIB)

$(PLIB)/Monomial.hh:
	bsw -n "Monomial" -d "Monomials up to 30" -v "x" --index "i" -e "x^i" -m 30 --grad --hess -l $(PLIB)

$(PLIB)/Chebyshev.hh:
	bsw -n "Chebyshev" -d "Chebyshev Polynomials up to term 30"  -v "x" -e "2*x*phi1 - phi0" --init "1.0" "x" --sym "phi0" "phi1" -m 30 --grad --hess -l $(PLIB)

$(PLIB)/Library.hh:
	lw -h -d $(PLIB) -v "std::vector<double>" "double*" -l $(PLIB)

$(PLIB)/Library.cc:
	lw -c -d $(PLIB) -v "std::vector<double>" "double*" -l $(PLIB)

FORCE:

clean: 
	rm -f $(PLIB)/MyFunc.hh $(PLIB)/Monomial.hh $(PLIB)/Chebyshev.hh $(PLIB)/Library.hh $(PLIB)/Library.cc
