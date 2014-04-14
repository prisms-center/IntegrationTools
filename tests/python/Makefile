# make PFunction src

HOME = ../..
PLIB = $(HOME)/tests/testlib

test: $(PLIB)/libpextern.so
	python py_test.py

$(PLIB)/libpextern.so:
	cd $(PLIB); make

clean:
	rm -rf *.eps