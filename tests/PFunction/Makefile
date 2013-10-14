
HOME = ../..
H = $(HOME)/include/PFunction
SRC = $(HOME)/src/PFunction
PLIB = $(HOME)/lib/PFunction
INCLUDE = $(H) $(PLIB)

CXX      = g++
CPPFLAGS += $(foreach i,$(INCLUDE),-I$(i))
CPPFLAGS += -O3
LDFLAGS  = -lcln -lginac


all: test test_sym test_funcderiv test_writer test_MyFunc test_basissetwriter test_MyBasisSet

test_sym: test_sym.cpp $(H)/* 
	$(CXX) -o test_sym test_sym.cpp $(CPPFLAGS) $(LDFLAGS)
	./test_sym

test: test.cpp $(H)/* $(PLIB)/*
	$(CXX) -o test test.cpp $(CPPFLAGS)
	./test

test_funcderiv: test_funcderiv.cpp $(H)/* 
	$(CXX) -o test_funcderiv test_funcderiv.cpp $(CPPFLAGS) $(LDFLAGS)
	./test_funcderiv


test_writer: test_writer.o S $(SRC)/PFunctionWriter.o
	$(CXX) test_writer.o $(SRC)/PFunctionWriter.o -o test_writer $(CPPFLAGS) $(LDFLAGS)
	./test_writer
	
test_writer.o: test_writer.cpp $(H)/*
	$(CXX) -c test_writer.cpp $(CPPFLAGS)

test_basissetwriter: test_basissetwriter.o S $(SRC)/PBasisSetWriter.o $(SRC)/PFunctionWriter.o
	$(CXX) test_basissetwriter.o $(SRC)/PBasisSetWriter.o $(SRC)/PFunctionWriter.o -o test_basissetwriter $(CPPFLAGS) $(LDFLAGS)
	./test_basissetwriter
	
test_basissetwriter.o: test_basissetwriter.cpp $(H)/*
	$(CXX) -c test_basissetwriter.cpp $(CPPFLAGS)


test_MyFunc: test_MyFunc.cpp MyFunc.hh $(H)/* test_writer
	$(CXX) -o test_MyFunc test_MyFunc.cpp $(CPPFLAGS)
	./test_MyFunc

test_MyBasisSet: test_MyBasisSet.cpp MyBasisSet.hh $(H)/* test_basissetwriter
	$(CXX) -o test_MyBasisSet test_MyBasisSet.cpp $(CPPFLAGS)
	./test_MyBasisSet


S: FORCE
	cd $(SRC) && $(MAKE)

FORCE:
	
	
clean: 
	rm test test_sym test_writer test_MyFunc test_funcderiv test_basissetwriter test_MyBasisSet
