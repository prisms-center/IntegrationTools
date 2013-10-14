# make PFunction src

HOME = ../..
H = $(HOME)/include/PFunction
INCLUDE = $(H) 

CXX      = g++
CPPFLAGS += $(foreach i,$(INCLUDE),-I$(i))
CPPFLAGS += -O3 
LDFLAGS  = -lcln -lginac -lboost_program_options -lboost_filesystem -lboost_system


CCFILES = $(wildcard ./*.cc)
OBJECTS=$(CCFILES:.cc=.o)

all : $(OBJECTS) fw bsw

test : all
	./fw -n "MyFunc" -v "x" "y" -d "x variable" "y variable"  --sym "x^3 + x^2*y + x*y^2 + y^3" --grad --hess
	./bsw -n "Chebyshev" -d "Chebyshev Polynomials up to term 30"  -v "x" -e "2*x*phi1 - phi0" --init "1.0" "x" --sym "phi0" "phi1" -m 30 --grad --hess

%.o : %.cc $(H)/*
	$(CXX) -c $< $(CPPFLAGS)

fw: fw.o $(H)/*
	$(CXX) fw.o PFunctionWriter.o -o fw $(CPPFLAGS) $(LDFLAGS)
	

fw.o : fw.cpp $(OBJECTS)
	$(CXX) -c fw.cpp $(CPPFLAGS)

bsw: bsw.o $(H)/*
	$(CXX) bsw.o PBasisSetWriter.o PFunctionWriter.o -o bsw $(CPPFLAGS) $(LDFLAGS)

bsw.o : bsw.cpp $(OBJECTS)
	$(CXX) -c bsw.cpp $(CPPFLAGS)

clean: 
	rm *.o bsw fw Chebyshev.hh MyFunc.hh
