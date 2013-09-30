
H = /Users/bpuchala/Work/codes/CASM/h
EXT = /Users/bpuchala/Work/codes/CASM/external
INCLUDE = $(H) $(EXT) $(EXT)/MersenneTwister $(H)/BP_C++

CXX      = g++
CPPFLAGS += $(foreach i,$(INCLUDE),-I$(i))
CPPFLAGS += -O3 
LDFLAGS  = -lcln -lginac

all: test test_sym

test_sym: test_sym.cpp PFunction.hh Poly.hh BP_C++
	$(CXX) -o test_sym test_sym.cpp $(CPPFLAGS) $(LDFLAGS)

test: test.cpp PFunction.hh Poly.hh BP_C++
	$(CXX) -o test test.cpp $(CPPFLAGS)
	
BP_C++: FORCE
	cd $(H)/BP_C++ && $(MAKE)

FORCE:

clean: 
	rm test
