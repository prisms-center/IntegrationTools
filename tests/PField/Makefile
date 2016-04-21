# make PFunction src

HOME = ../..
SRC = $(HOME)/src/c++
INCLUDE = . $(HOME)/include

CXX      = g++
CPPFLAGS += $(foreach i,$(INCLUDE),-I$(i))
CPPFLAGS += -O3 

all: test test3d
	./test
	./test3d

test: test.cpp FORCE
	$(CXX) -o test test.cpp $(CPPFLAGS)

test3d: test3d.cpp FORCE
	$(CXX) -o test3d test3d.cpp $(CPPFLAGS)


FORCE:
	

clean:
	rm -f test test3d