# pfunction python interface

VERS="develop"
ID=$$(git rev-parse HEAD)
URL=$$(git config --get remote.origin.url)


all: setup.py

install: setup.py
	sudo python setup.py install

uninstall:
	@sudo pip uninstall pfunction

clean:
	rm -f setup.py pfunction/__init__.py
	sudo rm -rf build

setup.py:
	@sed "s/VERSION_ID/$(VERS)/" pfunction/__init__.template.py > pfunction/__init__.tmp.0
	@sed "s/COMMIT_ID/$(ID)/" pfunction/__init__.tmp.0 > pfunction/__init__.py; rm pfunction/__init__.tmp.0 
	@sed "s/VERSION_ID/$(VERS)/" setup.template.py > setup.tmp.0
	@sed "s/COMMIT_ID/$(ID)/" setup.tmp.0 > setup.tmp.1; rm setup.tmp.0
	@sed "s|REPO_URL|$(URL)|" setup.tmp.1 > setup.py; rm setup.tmp.1	
