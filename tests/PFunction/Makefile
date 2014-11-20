
HOME = ../..
H = $(HOME)/include/PFunction
PLIB = $(HOME)/tests/testlib
INCLUDE = $(H) $(PLIB)

CXX      = g++
CPPFLAGS += $(foreach i,$(INCLUDE),-I$(i))
CPPFLAGS += -O3
LDFLAGS  = 


all: test_nolib
	

test_nolib: test_nolib.cpp 
	$(CXX) -o test_nolib test_nolib.cpp $(CPPFLAGS) $(LDFLAGS)
	./test_nolib
	
clean: 
	rm -f test_nolib
