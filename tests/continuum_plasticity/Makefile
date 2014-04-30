# make PFunction src

HOME = ../..
SRC = $(HOME)/src/c++
CPLIB = Library
INCLUDE = . $(HOME)/include

CXX      = g++
CPPFLAGS += $(foreach i,$(INCLUDE),-I$(i))
CPPFLAGS += -O3 

test: test.cpp $(CPLIB)/PLibrary.o FORCE
	$(CXX) -o test $(CPLIB)/PLibrary.o test.cpp $(CPPFLAGS)
	./test

$(CPLIB)/PLibrary.o: $(CPLIB)/von_mises.hh $(CPLIB)/quadlog.hh $(CPLIB)/PLibrary.hh $(CPLIB)/PLibrary.cc 
	$(CXX) -c $(CPLIB)/PLibrary.cc -o $(CPLIB)/PLibrary.o $(CPPFLAGS)

$(CPLIB)/von_mises.hh: 
	fw --name von_mises -v beta1 beta2 beta3 tau_y K alpha -d "First principle stress" "Second principle stress" "Third principle stress" "Yield stress" "Strain hardening coefficient" "Equivalent plastic strain" --sym "sqrt(pow(2./3.*beta1 - 1./3.*beta2 - 1./3.*beta3,2.) + pow(-1./3.*beta1 + 2./3.*beta2 - 1./3.*beta3,2.) + pow(-1./3.*beta1 - 1./3.*beta2 + 2./3.*beta3,2.)) - sqrt(2./3.)*(tau_y + K*alpha)" --grad --hess -l $(CPLIB)

$(CPLIB)/quadlog.hh:
	fw --name quadlog -v lambda mu lambda1 lambda2 lambda3 K alpha -d "First Lame parameter" "Second Lame parameter" "First principle stretch" "Second principle stretch" "Third principle stretch" "Strain hardening coefficient" "Equivalent plastic strain" --sym "0.5*lambda*pow(log(lambda1)*log(lambda2)*log(lambda3),2.) + mu*(pow(log(lambda1),2.) + pow(log(lambda2),2.) + pow(log(lambda3),2.)) + 0.5*K*pow(alpha,2.)" --grad --hess -l $(CPLIB)

$(CPLIB)/PLibrary.hh:
	lw -h -d $(CPLIB) -v "std::vector<double>" "double*" -l $(CPLIB)

$(CPLIB)/PLibrary.cc:
	lw -c -d $(CPLIB) -v "std::vector<double>" "double*" -l $(CPLIB)

FORCE:

clean: 
	rm -f $(CPLIB)/* test
