# make libpextern.so from the included PFunction src files

HOME = ../..
INCLUDE = . $(HOME)/include
LW = $(HOME)/src/lw/lw

CXX      = g++
CPPFLAGS += $(foreach i,$(INCLUDE),-I$(i))
CPPFLAGS += -O3 -fPIC


libpextern.so:
	cd $(HOME) && $(MAKE)
	$(LW) -d . -v "std::vector<double>" -l . -c --cflags "-O3 -fPIC -I../../include" --include "<vector>"

FORCE:

clean: 
	rm -f *.o *.so PLibrary.hh PLibrary.cc PExtern.cc
