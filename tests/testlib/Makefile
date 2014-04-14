# make pextern.dylib

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

PLibrary.cc: CLI

PLibrary.hh: CLI

PLibrary.o: PLibrary.cc PLibrary.hh CLI
	g++ -c PLibrary.cc $(CPPFLAGS)

CLI: FORCE
	cd ../commandline; make

FORCE:

clean: 
	rm -f *.o *.so
