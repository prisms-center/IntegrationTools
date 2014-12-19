
HOME = ../..
H = $(HOME)/include
PLIB = $(HOME)/tests/testlib
INCLUDE = $(H) $(PLIB) 

export LD_LIBRARY_PATH:=$(PLIB):$(LD_LIBRARY_PATH) 
export DYLD_LIBRARY_PATH:=$(PLIB):$(DYLD_LIBRARY_PATH)

CXX      = g++
CPPFLAGS += $(foreach i,$(INCLUDE),-I$(i))
CPPFLAGS += -O3
LDFLAGS  = 


all: test_nolib test_lib test_MyFunc test_PFunction test_PBasisSet
	

test_nolib: test_nolib.cpp 
	$(CXX) -o test_nolib test_nolib.cpp $(CPPFLAGS) $(LDFLAGS)
	./test_nolib

test_lib: test_lib.cpp 
	cd $(PLIB) && $(MAKE)
	$(CXX) -c test_lib.cpp $(CPPFLAGS)
	$(CXX) test_lib.o $(PLIB)/libpextern.so -o test_lib $(LDFLAGS)
	./test_lib

test_MyFunc: test_MyFunc.cpp 
	$(CXX) -o test_MyFunc test_MyFunc.cpp $(CPPFLAGS) $(LDFLAGS)
	./test_MyFunc

test_PFunction: test_PFunction.cpp 
	cd $(PLIB) && $(MAKE)
	$(CXX) -c test_PFunction.cpp $(CPPFLAGS)
	$(CXX) test_PFunction.o $(PLIB)/libpextern.so -o test_PFunction $(LDFLAGS)
	./test_PFunction

test_PBasisSet: test_PBasisSet.cpp 
	cd $(PLIB) && $(MAKE)
	$(CXX) -c test_PBasisSet.cpp $(CPPFLAGS)
	$(CXX) test_PBasisSet.o $(PLIB)/libpextern.so -o test_PBasisSet $(LDFLAGS)
	./test_PBasisSet
	
clean: 
	rm -f test_nolib test_lib test_MyFunc test_lib.o test_PFunction test_PBasisSet
