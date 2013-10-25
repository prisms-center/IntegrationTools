# make PFunction src

HOME = ../..
H = $(HOME)/include/PFunction
INCLUDE = $(H) .

CXX      = g++
CPPFLAGS += $(foreach i,$(INCLUDE),-I$(i))
CPPFLAGS += -O3 
LDFLAGS  = -lcln -lginac -lboost_program_options -lboost_filesystem -lboost_system



all : PBasisSetWriter.o PFunctionWriter.o fw bsw lw extern

test : fw bsw
	./fw -n "MyFunc" -v "x" "y" -d "x variable" "y variable"  --sym "x^3 + x^2*y + x*y^2 + y^3" --grad --hess
	./bsw -n "Monomial" -d "Monomials up to 30" -v "x" --index "i" -e "x^i" -m 30 --grad --hess
	./bsw -n "Chebyshev" -d "Chebyshev Polynomials up to term 30"  -v "x" -e "2*x*phi1 - phi0" --init "1.0" "x" --sym "phi0" "phi1" -m 30 --grad --hess
	
PFunctionWriter.o : PFunctionWriter.cc $(H)/*
	$(CXX) -c PFunctionWriter.cc $(CPPFLAGS)

PBasisSetWriter.o : PBasisSetWriter.cc $(H)/*
	$(CXX) -c PBasisSetWriter.cc $(CPPFLAGS)

fw: fw.cpp $(H)/* PFunctionWriter.o
	$(CXX) -c fw.cpp $(CPPFLAGS)
	$(CXX) fw.o PFunctionWriter.o -o fw $(CPPFLAGS) $(LDFLAGS)

bsw: bsw.cpp $(H)/* PBasisSetWriter.o PFunctionWriter.o
	$(CXX) -c bsw.cpp $(CPPFLAGS)
	$(CXX) bsw.o PBasisSetWriter.o PFunctionWriter.o -o bsw $(CPPFLAGS) $(LDFLAGS)

lw: lw.cpp
	$(CXX) -o lw lw.cpp $(CPPFLAGS) -lboost_filesystem -lboost_system -lboost_program_options -lboost_regex

extern: PExtern_Example.hh PExtern_Example.cc PLibrary.o
	$(CXX) -o libpextern.dylib PExtern_Example.cc PLibrary.o -dynamiclib $(CPPFLAGS)

PLibrary.o: lw test
	./lw -h -d "." -v "std::vector<double>" "double*";./lw -c -d "." -v "std::vector<double>" "double*"
	g++ -c PLibrary.cc $(CPPFLAGS)

clean: 
	rm -f *.o bsw fw lw Chebyshev.hh MyFunc.hh PLibrary.hh PLibrary.cc *.dylib
