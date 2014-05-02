# make PFunction src

HOME = ../..
SRC = $(HOME)/src/c++
CPLIB = Library
INCLUDE = . $(HOME)/include

CXX      = g++
CPPFLAGS += $(foreach i,$(INCLUDE),-I$(i))
CPPFLAGS += -O3 

test: test.cpp FORCE
	$(CXX) -o test test.cpp $(CPPFLAGS)

test3d: test3d.cpp FORCE
	$(CXX) -o test3d test3d.cpp $(CPPFLAGS)


FORCE:
	

clean:
	rm -f test test3d