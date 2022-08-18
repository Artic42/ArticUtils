#Constant definitions
CC = gcc
CFLAGSR = -Wall
CFLAGSD = -g $(CFLAGSR)
OFLAGSR = -c $(CFLAGSR)
OFLAGSD = -c $(CFLAGSD)
IPATH = -Iinclude

include make/pythonLib.make
include make/thoth.make
include make/hermes.make
include make/herald.make
include make/artic42.make

# All

all: Artic42 hermes herald pythonLib thoth

# General

test: install
	@echo Test of articUtils library test initiated
	@python3 test/testArticUtils.py

install: all
	@mkdir -p ~/.bin/ ~/.include ~/.lib/ ~/Templates/tex/ ~/.test/
	@cp -rf bin/* ~/.bin/
	@cp -rf include/* ~/.include/
	@cp -rf lib/* ~/.lib/
	@cp -rf test/* ~/.test/
	@cp -rf src/texTemplate/* ~/Templates/tex/

clean:
	@rm -f bin/*.app
	@rm -f lib/c-cpp/*.lib
	@rm -f lib/python/*.py
	@rm -rf src/thoth/test/logs src/thoth/test/py_logs
	@rm -f src/thoth/test/mergedLog.log
	@rm -f src/thoth/test/filteredMask.log
	@rm -f src/thoth/test/filteredName.log
	@rm -f src/hermes/test/result.txt