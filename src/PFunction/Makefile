# make PFunction src

HOME = ../..
H = $(HOME)/include/PFunction
INCLUDE = $(H) 

CXX      = g++
CPPFLAGS += $(foreach i,$(INCLUDE),-I$(i))
CPPFLAGS += -O3 
LDFLAGS  = -lcln -lginac -lboost_program_options -lboost_filesystem -lboost_system


CCFILES = $(wildcard ./*.cc)
OBJECTS=$(CCFILES:.cc=.o)

all : $(OBJECTS) fw

%.o : %.cc $(H)/*
	$(CXX) -c $< $(CPPFLAGS)

fw: fw.o $(H)/*
	$(CXX) fw.o PFunctionWriter.o -o fw $(CPPFLAGS) $(LDFLAGS)

fw.o : fw.cpp $(OBJECTS)
	$(CXX) -c fw.cpp $(CPPFLAGS)

clean: 
	rm *.o
