# make command line interface programs: fs, bsw, lw

HOME = ../..
TOOLS = $(HOME)/include/IntegrationTools
PFUNC = $(TOOLS)/pfunction
PSYM = $(TOOLS)/psymfunction
WRITER = $(TOOLS)/writer
INCLUDE = . $(HOME)/include

ifeq "$(BIN)" ""
	INSTALL = /usr/local/bin
else
	INSTALL = $(BIN)
endif
VERS = "develop"
ID=$$(git rev-parse HEAD)
URL=$$(git config --get remote.origin.url)

ifeq "$(BOOST)" ""
	LFLAGS = -lcln -lginac -lboost_program_options -lboost_filesystem -lboost_system -lboost_regex
else
	BOOSTLIB = libboost_filesystem.so libboost_program_options.so libboost_regex.so libboost_system.so
	LFLAGS += $(foreach i, $(BOOSTLIB), $(BOOST)/lib/$(i))
	INCLUDE += $(BOOST)/include
endif

LFLAGS_G = $(LFLAGS)
ifeq "$(GINAC)" ""
	LFLAGS_G += -lcln -lginac
else
	INCLUDE += $(GINAC)/include
	LFLAGS_G += $(GINAC)/lib/libginac.so $(GINAC)/lib/libcln.so
endif
#LDFLAGS  = -lcln -lginac -lboost_program_options -lboost_filesystem -lboost_system -lboost_regex

CXX      = g++
CPPFLAGS += $(foreach i,$(INCLUDE),-I$(i))
CPPFLAGS += -O3 


all : fw bsw lw

install: all
	install fw $(INSTALL)
	install bsw $(INSTALL)
	install lw $(INSTALL)

uninstall:
	rm $(INSTALL)/fw
	rm $(INSTALL)/bsw
	rm $(INSTALL)/lw

PFunctionWriter.o: PFunctionWriter.cc $(TOOLS)/version.hh $(WRITER)/PFunctionWriter.hh 
	$(CXX) -c PFunctionWriter.cc $(CPPFLAGS)

PBasisSetWriter.o: PBasisSetWriter.cc $(PSYM)/PRealSymBasisFunction.hh $(PSYM)/PRealSymBasisSet.hh $(PSYM)/PRealSymRecursBasisSet.hh $(TOOLS)/version.hh $(WRITER)/*
	$(CXX) -c PBasisSetWriter.cc $(CPPFLAGS)

version.cc: #FORCE
	@sed "s/VERSION_ID/$(VERS)/" version.template.cc > version.tmp.0
	@sed "s/COMMIT_ID/$(ID)/" version.tmp.0 > version.tmp.1; rm version.tmp.0
	@sed "s|REPO_URL|$(URL)|" version.tmp.1 > version.cc; rm version.tmp.1

version.o: version.cc $(TOOLS)/version.hh
	$(CXX) -c version.cc $(CPPFLAGS)

fw: fw.cpp PFunctionWriter.o version.o
	$(CXX) PFunctionWriter.o version.o -o fw fw.cpp $(CPPFLAGS) $(LFLAGS_G)

bsw: bsw.cpp PBasisSetWriter.o PFunctionWriter.o version.o
	$(CXX) PBasisSetWriter.o PFunctionWriter.o version.o -o bsw bsw.cpp $(CPPFLAGS) $(LFLAGS_G)

lw: lw.cpp version.o
	$(CXX) version.o -o lw lw.cpp $(CPPFLAGS) $(LFLAGS)

clean: 
	rm -f *.o bsw fw lw version.cc

