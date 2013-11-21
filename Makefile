# make PFunction

SRC = src/PFunction

all : 
	cd $(SRC); make all

install: 
	cd $(SRC); make install

uninstall:
	cd $(SRC); make uninstall
	

test : 
	cd $(SRC); make test

clean: 
	cd $(SRC); make clean
