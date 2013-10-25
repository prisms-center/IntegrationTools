
HOME = ../..
H = $(HOME)/include/PFunction
SRC = $(HOME)/src/PFunction
PLIB = $(HOME)/lib/PFunction
INCLUDE = $(H) $(PLIB) $(SRC)

CXX      = g++
CPPFLAGS += $(foreach i,$(INCLUDE),-I$(i))
CPPFLAGS += -O3
LDFLAGS  = -lcln -lginac


all: test test_sym test_funcderiv test_writer test_MyFunc test_basissetwriter test_MyBasisSet test_PExtern
	make clean

test_sym: test_sym.cpp $(H)/* 
	$(CXX) -o test_sym test_sym.cpp $(CPPFLAGS) $(LDFLAGS)
	./test_sym

test: test.cpp $(H)/* $(PLIB)/*
	$(CXX) -o test test.cpp $(CPPFLAGS)
	./test

test_funcderiv: test_funcderiv.cpp $(H)/* 
	$(CXX) -o test_funcderiv test_funcderiv.cpp $(CPPFLAGS) $(LDFLAGS)
	./test_funcderiv


test_writer: test_writer.cpp $(H)/* S
	$(CXX) -c test_writer.cpp $(CPPFLAGS)
	$(CXX) test_writer.o $(SRC)/PFunctionWriter.o -o test_writer $(CPPFLAGS) $(LDFLAGS)
	./test_writer	

test_basissetwriter: test_basissetwriter.cpp $(H)/* S
	$(CXX) -c test_basissetwriter.cpp $(CPPFLAGS)
	$(CXX) test_basissetwriter.o $(SRC)/PBasisSetWriter.o $(SRC)/PFunctionWriter.o -o test_basissetwriter $(CPPFLAGS) $(LDFLAGS)
	./test_basissetwriter

test_MyFunc: test_MyFunc.cpp $(H)/* test_writer
	$(CXX) -o test_MyFunc test_MyFunc.cpp $(CPPFLAGS)
	./test_MyFunc

test_MyBasisSet: test_MyBasisSet.cpp $(H)/* test_basissetwriter
	$(CXX) -o test_MyBasisSet test_MyBasisSet.cpp $(CPPFLAGS)
	./test_MyBasisSet

test_PExtern: test_PExtern.cpp EXT
	$(CXX) -c test_PExtern.cpp $(CPPFLAGS)
	$(CXX) -o test_PExtern test_PExtern.o $(SRC)/PLibrary.o $(CPPFLAGS) -lpextern -L$(SRC)
	export DYLD_LIBRARY_PATH=/usr/local/lib:/Users/bpuchala/Work/codes/IntegrationTools/src/PFunction; ./test_PExtern	

EXT: FORCE
	cd $(SRC); make extern


S: FORCE
	cd $(SRC); make PFunctionWriter.o; make PBasisSetWriter.o

FORCE:
	
	
clean: 
	rm -f test test_sym test_writer test_MyFunc test_funcderiv test_basissetwriter test_MyBasisSet test_PExtern MyFunc.hh MyBasisSet.hh *.o
