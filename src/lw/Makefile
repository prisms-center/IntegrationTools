# make command line interface program: lw

HOME = ../..
TOOLS = $(HOME)/include/IntegrationTools
PFUNC = $(TOOLS)/pfunction
PSYM = $(TOOLS)/psymfunction
INCLUDE = . $(HOME)/include

ifeq "$(INTEGRATIONTOOLS_PREFIX)" ""
	INSTALL = /usr/local/bin
else
	INSTALL = $(INTEGRATIONTOOLS_PREFIX)/bin
endif
VERS=$$(git rev-parse --abbrev-ref HEAD)
ID=$$(git rev-parse HEAD)
URL=$$(git config --get remote.origin.url)

ifeq "$(INTEGRATIONTOOLS_BOOST)" ""
	LFLAGS = -lboost_program_options -lboost_filesystem -lboost_system -lboost_regex
else
	BOOSTLIB = libboost_filesystem.so libboost_program_options.so libboost_regex.so libboost_system.so
	LFLAGS += $(foreach i, $(BOOSTLIB), $(INTEGRATIONTOOLS_BOOST)/lib/$(i))
	INCLUDE += $(INTEGRATIONTOOLS_BOOST)/include
endif


CXX      = g++
CPPFLAGS += $(foreach i,$(INCLUDE),-I$(i))
CPPFLAGS += -O3 


all : lw

install: all
	install lw $(INSTALL)

uninstall:
	rm -f $(INSTALL)/lw

version.cc: #FORCE
	@sed "s|VERSION_ID|$(VERS)|" version.template.cc > version.tmp.0
	@sed "s|COMMIT_ID|$(ID)|" version.tmp.0 > version.tmp.1; rm version.tmp.0
	@sed "s|REPO_URL|$(URL)|" version.tmp.1 > version.cc; rm version.tmp.1

version.o: version.cc version.hh
	$(CXX) -c version.cc $(CPPFLAGS)

lw: lw.cpp version.o
	$(CXX) version.o -o lw lw.cpp $(CPPFLAGS) $(LFLAGS)

clean: 
	rm -f *.o lw version.cc

