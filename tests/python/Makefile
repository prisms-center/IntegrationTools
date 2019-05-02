# make PFunction src

HOME = ../..
PLIB = $(HOME)/tests/testlib

ifeq "$(INTEGRATIONTOOLS_PYTHON)" ""
	PYTHON = python
else
	PYTHON = $(INTEGRATIONTOOLS_PYTHON)
endif

test: $(PLIB)/libpextern.so
	$(PYTHON) py_test.py

$(PLIB)/libpextern.so:
	cd $(PLIB); make

clean:
	rm -rf *.eps
