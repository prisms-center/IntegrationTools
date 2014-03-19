# make PFunction src

HOME = ..
H = $(HOME)/include/PFunction
INCLUDE = $(H) .

INSTALL = /usr/local/bin
VERS = "develop"
ID=$$(git rev-parse HEAD)
URL=$$(git config --get remote.origin.url)

CXX      = g++
CPPFLAGS += $(foreach i,$(INCLUDE),-I$(i))
CPPFLAGS += -O3 
LDFLAGS  = -lcln -lginac -lboost_program_options -lboost_filesystem -lboost_system



all : fw bsw lw

install: all setup.py
	install fw $(INSTALL)
	install bsw $(INSTALL)
	install lw $(INSTALL)
	sudo python setup.py install

uninstall:
	rm $(INSTALL)/fw
	rm $(INSTALL)/bsw
	rm $(INSTALL)/lw
	@echo "python module PFunction must be uninstalled manually, trying running 'python setup.py install' to see where it is located."
	

test : test_fw test_bsw test_lw test_py FORCE

test_fw : fw FORCE
	./fw -n "MyFunc" -v "x" "y" -d "x variable" "y variable"  --sym "x^3 + x^2*y + x*y^2 + y^3" --grad --hess

test_bsw : test_bsw_mono test_bsw_cheb FORCE

test_bsw_mono : bsw FORCE
	./bsw -n "Monomial" -d "Monomials up to 30" -v "x" --index "i" -e "x^i" -m 30 --grad --hess

test_bsw_cheb : bsw FORCE
	./bsw -n "Chebyshev" -d "Chebyshev Polynomials up to term 30"  -v "x" -e "2*x*phi1 - phi0" --init "1.0" "x" --sym "phi0" "phi1" -m 30 --grad --hess

test_lw : lw FORCE
	./lw -h -d "." -v "std::vector<double>" "double*";./lw -c -d "." -v "std::vector<double>" "double*"
	
test_py : test_lw extern FORCE
	python py_test.py
	
PFunctionWriter.o : PFunctionWriter.cc $(H)/*
	$(CXX) -c PFunctionWriter.cc $(CPPFLAGS)

PBasisSetWriter.o : PBasisSetWriter.cc $(H)/*
	$(CXX) -c PBasisSetWriter.cc $(CPPFLAGS)

version.cc: #FORCE
	@sed "s/VERSION_ID/$(VERS)/" version.template.cc > version.tmp.0
	@sed "s/COMMIT_ID/$(ID)/" version.tmp.0 > version.tmp.1; rm version.tmp.0
	@sed "s|REPO_URL|$(URL)|" version.tmp.1 > version.cc; rm version.tmp.1

setup.py: #FORCE
	@sed "s/VERSION_ID/$(VERS)/" PFunction/__init__.template.py > PFunction/__init__.tmp.0
	@sed "s/COMMIT_ID/$(ID)/" PFunction/__init__.tmp.0 > PFunction/__init__.py; rm PFunction/__init__.tmp.0 
	@sed "s/VERSION_ID/$(VERS)/" setup.template.py > setup.tmp.0
	@sed "s/COMMIT_ID/$(ID)/" setup.tmp.0 > setup.tmp.1; rm setup.tmp.0
	@sed "s|REPO_URL|$(URL)|" setup.tmp.1 > setup.py; rm setup.tmp.1	

version.o: version.cc $(H)/version.hh
	$(CXX) -c version.cc $(CPPFLAGS)

fw: fw.cpp $(H)/* PFunctionWriter.o version.o
	$(CXX) PFunctionWriter.o version.o -o fw fw.cpp $(CPPFLAGS) $(LDFLAGS)

bsw: bsw.cpp $(H)/* PBasisSetWriter.o PFunctionWriter.o version.o
	$(CXX) PBasisSetWriter.o PFunctionWriter.o version.o -o bsw bsw.cpp $(CPPFLAGS) $(LDFLAGS)

lw: lw.cpp version.o
	$(CXX) version.o -o lw lw.cpp $(CPPFLAGS) -lboost_filesystem -lboost_system -lboost_program_options -lboost_regex

extern: $(H)/PExtern.hh PExtern.cc PLibrary.o
	$(CXX) -o libpextern.dylib PExtern.cc PLibrary.o -dynamiclib $(CPPFLAGS)

PLibrary.o: PLibrary.cc FORCE
	g++ -c PLibrary.cc $(CPPFLAGS)

PLibrary.cc: Chebyshev.hh test_lw

Chebyshev.hh: test_bsw_cheb
	

FORCE:
	

clean: 
	rm -f *.o bsw fw lw Monomial.hh Chebyshev.hh MyFunc.hh PLibrary.hh PLibrary.cc *.dylib version.cc setup.py PFunction/__init__.py
	sudo rm -rf build
