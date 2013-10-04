# make PFunction src

HOME = ../..
H = $(HOME)/include/PFunction
INCLUDE = $(H) 

CXX      = g++
CPPFLAGS += $(foreach i,$(INCLUDE),-I$(i))
CPPFLAGS += -O3 
LDFLAGS  = -lcln -lginac


CCFILES = $(wildcard ./*.cc)
OBJECTS=$(CCFILES:.cc=.o)

all : $(OBJECTS)

%.o : %.cc $(H)/*
	$(CXX) -c $< $(CPPFLAGS)

clean: 
	rm *.o
