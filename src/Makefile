# make PFunction src

CSRC = c
LWSRC = lw
PYTHONSRC = python

all:
	@cd $(LWSRC); make
	@cd $(PYTHONSRC); make

install:
	@cd $(LWSRC) && make install
	@cd $(PYTHONSRC) && make install

uninstall:
	@cd $(LWSRC) && make uninstall
	@#cd $(PYTHONSRC) && make uninstall
	@echo "python module 'pfunction' must be uninstalled manually"

clean:
	@cd $(LWSRC); make clean
	@cd $(PYTHONSRC); make clean

