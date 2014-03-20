# make command line interface programs: fs, bsw, lw

HOME = ../..
H = $(HOME)/include/c++
PFUNC = $(H)/pfunction
WRITER = $(H)/writer
INCLUDE = . $(H) $(PFUNC) $(WRITER)

INSTALL = /usr/local/bin
VERS = "develop"
ID=$$(git rev-parse HEAD)
URL=$$(git config --get remote.origin.url)

CXX      = g++
CPPFLAGS += $(foreach i,$(INCLUDE),-I$(i))
CPPFLAGS += -O3 
LDFLAGS  = -lcln -lginac -lboost_program_options -lboost_filesystem -lboost_system



all : fw bsw lw

install: all
	install fw $(INSTALL)
	install bsw $(INSTALL)
	install lw $(INSTALL)

uninstall:
	rm $(INSTALL)/fw
	rm $(INSTALL)/bsw
	rm $(INSTALL)/lw

PFunctionWriter.o: PFunctionWriter.cc $(H)/version.hh $(WRITER)/PFunctionWriter.hh 
	$(CXX) -c PFunctionWriter.cc $(CPPFLAGS)

PBasisSetWriter.o: PBasisSetWriter.cc $(PFUNC)/PRealSymBasisFunction.hh $(PFUNC)/PRealSymBasisSet.hh $(PFUNC)/PRealSymRecursBasisSet.hh $(H)/version.hh $(WRITER)/*
	$(CXX) -c PBasisSetWriter.cc $(CPPFLAGS)

version.cc: #FORCE
	@sed "s/VERSION_ID/$(VERS)/" version.template.cc > version.tmp.0
	@sed "s/COMMIT_ID/$(ID)/" version.tmp.0 > version.tmp.1; rm version.tmp.0
	@sed "s|REPO_URL|$(URL)|" version.tmp.1 > version.cc; rm version.tmp.1

version.o: version.cc $(H)/version.hh
	$(CXX) -c version.cc $(CPPFLAGS)

fw: fw.cpp PFunctionWriter.o version.o
	$(CXX) PFunctionWriter.o version.o -o fw fw.cpp $(CPPFLAGS) $(LDFLAGS)

bsw: bsw.cpp PBasisSetWriter.o PFunctionWriter.o version.o
	$(CXX) PBasisSetWriter.o PFunctionWriter.o version.o -o bsw bsw.cpp $(CPPFLAGS) $(LDFLAGS)

lw: lw.cpp version.o
	$(CXX) version.o -o lw lw.cpp $(CPPFLAGS) -lboost_filesystem -lboost_system -lboost_program_options -lboost_regex

clean: 
	rm -f *.o bsw fw lw version.cc

