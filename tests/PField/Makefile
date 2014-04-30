# make PFunction src

HOME = ../..
SRC = $(HOME)/src/c++
CPLIB = Library
INCLUDE = . $(HOME)/include

CXX      = g++
CPPFLAGS += $(foreach i,$(INCLUDE),-I$(i))
CPPFLAGS += -O3 

test: test.cpp
	$(CXX) -o test test.cpp $(CPPFLAGS)

clean:
	rm -f test