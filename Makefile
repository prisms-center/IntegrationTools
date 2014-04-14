# make PFunction

SRC = src
TEST = tests

all: 
	cd $(SRC) && $(MAKE)

install: 
	cd $(SRC) && $(MAKE) install

uninstall:
	cd $(SRC) && $(MAKE) uninstall

test: 
	cd $(TEST) && $(MAKE)

clean: 
	cd $(SRC) && $(MAKE) clean
	cd $(TEST) && $(MAKE) clean
	rm -rf .cache .matplotlib
