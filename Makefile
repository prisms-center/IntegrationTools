# make IntegrationTools lw and pfunction python module

SRC = src
TEST = tests

prefix = /usr/local
includedir = $(prefix)/include

all: 
	@cd $(SRC) && $(MAKE)

install: 
	@cd $(SRC) && $(MAKE) install
	@cp -r include/IntegrationTools $(includedir)

uninstall:
	@cd $(SRC) && $(MAKE) uninstall
	@rm -r $(includedir)/IntegrationTools

test: 
	@cd $(TEST) && $(MAKE)

clean: 
	@cd $(SRC) && $(MAKE) clean
	@cd $(TEST) && $(MAKE) clean
	rm -rf .cache .matplotlib
	
