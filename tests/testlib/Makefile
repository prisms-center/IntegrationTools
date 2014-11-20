# make pextern.dylib from the included PFunction src files

HOME = ../..
EXTERN = $(HOME)/include/IntegrationTools/extern
SRC = $(HOME)/src/c
INCLUDE = . $(HOME)/include

INSTALL = /usr/local/bin

CXX      = g++
CPPFLAGS += $(foreach i,$(INCLUDE),-I$(i))
CPPFLAGS += -O3 -fPIC


libpextern.so: PExtern.o PLibrary.o
	@#$(CXX) -o libpextern.dylib $(SRC)/PExtern.cc PLibrary.o -dynamiclib $(CPPFLAGS)
	$(CXX) -shared -o libpextern.so PExtern.o PLibrary.o 

PExtern.o: $(SRC)/PExtern.cc
	$(CXX) -c $(SRC)/PExtern.cc $(CPPFLAGS)

PLibrary.cc:
	lw -c -d . -v "std::vector<double>" "double*" -l .

PLibrary.hh: 
	lw -h -d . -v "std::vector<double>" "double*" -l .

PLibrary.o: PLibrary.cc PLibrary.hh
	g++ -c PLibrary.cc $(CPPFLAGS)

FORCE:

clean: 
	rm -f *.o *.so PLibrary.hh PLibrary.cc
