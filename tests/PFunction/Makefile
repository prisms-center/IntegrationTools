
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


all: test_nolib test_lib test_MyFunc
	

test_nolib: test_nolib.cpp 
	$(CXX) -o test_nolib test_nolib.cpp $(CPPFLAGS) $(LDFLAGS)
	./test_nolib

test_lib: test_lib.cpp 
	cd $(PLIB) && $(MAKE)
	$(CXX) -c test_lib.cpp $(CPPFLAGS)
	$(CXX) test_lib.o $(PLIB)/libpextern.so -o test_lib $(LDFLAGS)
	./test_lib
	$(CXX) test_lib.o $(PLIB)/PLibrary.o -o test_lib $(LDFLAGS)
	./test_lib

test_MyFunc: test_MyFunc.cpp 
	$(CXX) -o test_MyFunc test_MyFunc.cpp $(CPPFLAGS) $(LDFLAGS)
	./test_MyFunc
	
clean: 
	rm -f test_nolib test_lib test_MyFunc test_lib.o
