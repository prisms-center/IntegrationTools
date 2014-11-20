# make IntegrationTools lw and pfunction python module

SRC = src
TEST = tests

all: 
	@cd $(SRC) && $(MAKE)

install: 
	@cd $(SRC) && $(MAKE) install

uninstall:
	@cd $(SRC) && $(MAKE) uninstall
	@echo "The IntegrationTools header files directory must be removed manually if you copied it somewhere"

test: 
	@cd $(TEST) && $(MAKE)

clean: 
	@cd $(SRC) && $(MAKE) clean
	@cd $(TEST) && $(MAKE) clean
	rm -rf .cache .matplotlib
	
