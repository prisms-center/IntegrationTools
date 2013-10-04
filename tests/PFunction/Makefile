
HOME = ../..
H = $(HOME)/include/PFunction
SRC = $(HOME)/src/PFunction
PLIB = $(HOME)/lib/PFunction
INCLUDE = $(H) $(PLIB)

CXX      = g++
CPPFLAGS += $(foreach i,$(INCLUDE),-I$(i))
CPPFLAGS += -O3 
LDFLAGS  = -lcln -lginac


all: test test_sym test_writer

test_sym: test_sym.cpp $(H)/* 
	$(CXX) -o test_sym test_sym.cpp $(CPPFLAGS) $(LDFLAGS)

test: test.cpp $(H)/* $(PLIB)/*
	$(CXX) -o test test.cpp $(CPPFLAGS)

test_writer: test_writer.o $(SRC)/PFunctionWriter.o
	$(CXX) test_writer.o $(SRC)/PFunctionWriter.o -o test_writer $(CPPFLAGS) $(LDFLAGS)

test_writer.o: test_writer.cpp $(H)/*
	$(CXX) -c test_writer.cpp $(CPPFLAGS)

S: FORCE
	cd $(SRC) && $(MAKE)

FORCE:
	
	
clean: 
	rm test test_sym
