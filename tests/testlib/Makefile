# make libpextern.so from the included PFunction src files

HOME = ../..
EXTERN = $(HOME)/include/IntegrationTools/extern
SRC = $(HOME)/src/c
INCLUDE = . $(HOME)/include

INSTALL = /usr/local/bin

CXX      = g++
CPPFLAGS += $(foreach i,$(INCLUDE),-I$(i))
CPPFLAGS += -O3 -fPIC


libpextern.so:
	lw -d . -v "std::vector<double>" -l . -c --cflags "-O3 -fPIC -I../../include"

FORCE:

clean: 
	rm -f *.o *.so PLibrary.hh PLibrary.cc PExtern.cc
