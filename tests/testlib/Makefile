# make pextern.dylib

HOME = ../..
H = $(HOME)/include/c
SRC = $(HOME)/src/c
PFUNC = $(HOME)/include/c++/pfunction
DATASTRUC = $(HOME)/include/c++/datastruc
INCLUDE = . $(H) $(PFUNC) $(DATASTRUC)

INSTALL = /usr/local/bin

CXX      = g++
CPPFLAGS += $(foreach i,$(INCLUDE),-I$(i))
CPPFLAGS += -O3 


extern: $(H)/PExtern.hh $(SRC)/PExtern.cc PLibrary.o
	$(CXX) -o libpextern.dylib $(SRC)/PExtern.cc PLibrary.o -dynamiclib $(CPPFLAGS)

PLibrary.o: PLibrary.cc PLibrary.hh CLI
	g++ -c PLibrary.cc $(CPPFLAGS)

CLI: FORCE
	cd ../commandline; make

FORCE:

clean: 
	rm -f *.o *.dylib
