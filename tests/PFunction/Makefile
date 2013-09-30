
HOME = ../..
H = $(HOME)/include/PFunction
PLIB = $(HOME)/lib/PFunction
INCLUDE = $(H) $(PLIB)

CXX      = g++
CPPFLAGS += $(foreach i,$(INCLUDE),-I$(i))
CPPFLAGS += -O3 
LDFLAGS  = -lcln -lginac


all: test test_sym

test_sym: test_sym.cpp $(H)/* 
	$(CXX) -o test_sym test_sym.cpp $(CPPFLAGS) $(LDFLAGS)

test: test.cpp $(H)/* $(PLIB)/*
	$(CXX) -o test test.cpp $(CPPFLAGS)
	
clean: 
	rm test test_sym
