# make PFunction src

CSRC = c
CPPSRC = c++
PYTHONSRC = python

all:
	@cd $(CPPSRC); make
	@cd $(PYTHONSRC); make

install:
	@cd $(CPPSRC); make install
	@cd $(PYTHONSRC); make install

uninstall:
	@cd $(CPPSRC); make uninstall
	@cd $(PYTHONSRC); make uninstall

clean:
	@cd $(CPPSRC); make clean
	@cd $(PYTHONSRC); make clean

