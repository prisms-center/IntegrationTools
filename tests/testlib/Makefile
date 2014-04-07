# make pextern.dylib

HOME = ../..
EXTERN = $(HOME)/include/IntegrationTools/extern
SRC = $(HOME)/src/c
INCLUDE = . $(HOME)/include

INSTALL = /usr/local/bin

CXX      = g++
CPPFLAGS += $(foreach i,$(INCLUDE),-I$(i))
CPPFLAGS += -O3 


extern: $(EXTERN)/PExtern.hh $(SRC)/PExtern.cc PLibrary.o
	$(CXX) -o libpextern.dylib $(SRC)/PExtern.cc PLibrary.o -dynamiclib $(CPPFLAGS)

PLibrary.cc: CLI

PLibrary.hh: CLI

PLibrary.o: PLibrary.cc PLibrary.hh CLI
	g++ -c PLibrary.cc $(CPPFLAGS)

CLI: FORCE
	cd ../commandline; make

FORCE:

clean: 
	rm -f *.o *.dylib
