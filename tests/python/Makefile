# make PFunction src

HOME = ../..
PLIB = $(HOME)/tests/testlib

test: $(PLIB)/libpextern.dylib
	python py_test.py

$(PLIB)/libpextern.dylib:
	cd $(PLIB); make

