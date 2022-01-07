#Constant definitions

CC = gcc
CFLAGSR = -Wall
CFLAGSD = -g $(CFLAGSR)
OFLAGSR = -c $(CFLAGSR)
OFLAGSD = -c $(CFLAGSD)
IPATH = -Iinclude

# All

all: Artic42 hermes herald pythonLib

# Artic42

Artic42_R: lib/c-cpp/Artic42.lib
Artic42_D: lib/c-cpp/Artic42_D.lib
Artic42: Artic42_R Artic42_D
	cp src/Artic42/Artic42.h include/Artic42.h

bin/CharacterFunctions.o: src/Artic42/CharacterFunctions.c
	$(CC) $(OFLAGSR) $(IPATH) src/Artic42/CharacterFunctions.c -o bin/CharacterFunctions.o

bin/IntegerFunctions.o: src/Artic42/IntegerFunctions.c
	$(CC) $(OFLAGSR) $(IPATH) src/Artic42/IntegerFunctions.c -o bin/IntegerFunctions.o

lib/c-cpp/Artic42.lib: bin/CharacterFunctions.o bin/IntegerFunctions.o
	ar cr lib/c-cpp/Artic42.lib bin/CharacterFunctions.o bin/IntegerFunctions.o
	rm -f bin/CharacterFunctions.o bin/IntegerFunctions.o

bin/CharacterFunctions_D.o: src/Artic42/CharacterFunctions.c
	$(CC) $(OFLAGSD) $(IPATH) src/Artic42/CharacterFunctions.c -o bin/CharacterFunctions_D.o

bin/IntegerFunctions_D.o: src/Artic42/IntegerFunctions.c
	$(CC) $(OFLAGSD) $(IPATH) src/Artic42/IntegerFunctions.c -o bin/IntegerFunctions_D.o

lib/c-cpp/Artic42_D.lib: bin/CharacterFunctions_D.o bin/IntegerFunctions_D.o
	ar cr lib/c-cpp/Artic42_D.lib bin/CharacterFunctions_D.o bin/IntegerFunctions_D.o
	rm -f bin/CharacterFunctions_D.o bin/IntegerFunctions_D.o

# Herald

herald: lib/python/sendEmail.py bin/sendEmail.app bin/herald.app

lib/python/sendEmail.py: src/herald/sendEmail.py
	cp -f src/herald/sendEmail.py lib/python/sendEmail.py

bin/sendEmail.app: src/herald/sendEmail.py
	cat pythonInterpreter src/herald/sendEmail.py > bin/sendEmail.app

bin/herald.app: src/herald/herald.py
	cat pythonInterpreter src/herald/herald.py > bin/herald.app

# Hermes

hermes_R: lib/c-cpp/hermes.lib
hermes_D: lib/c-cpp/hermes_D.lib
hermes_py: lib/python/hermes.py
hermes: hermes_D hermes_R hermes_py
	cp src/hermes/hermes.h include/hermes.h
hermesTest: src/hermes/bin/hermesTest.app


lib/c-cpp/hermes.lib: src/hermes/hermes.c
	$(CC) $(OFLAGSR) $(IPATH) src/hermes/hermes.c -o lib/c-cpp/hermes.lib

lib/c-cpp/hermes_D.lib: src/hermes/hermes.c
	$(CC) $(OFLAGSD) $(IPATH) src/hermes/hermes.c -o lib/c-cpp/hermes_D.lib

src/hermes/bin/hermesTest.app: lib/c-cpp/hermes_D.lib src/hermes/test.c
	$(CC) $(CFLAGSD) $(IPATH) lib/c-cpp/hermes_D.lib src/hermes/test.c -o src/hermes/hermesTest.app
	./src/hermes/hermesTest.app
	rm -f src/hermes/hermesTest.app

lib/python/hermes.py: src/hermes/hermes.py
	cp src/hermes/hermes.py lib/python/hermes.py
# Python Library

pythonLib: lib/python/modifyFile.py lib/python/readExcel.py

lib/python/modifyFile.py: src/pythonLib/modifyFile.py
	cp src/pythonLib/modifyFile.py lib/python/modifyFile.py

lib/python/readExcel.py: src/pythonLib/readExcel.py
	cp src/pythonLib/readExcel.py lib/python/readExcel.py

# General

install: all
	cp -rf bin/* ~/.bin/
	cp -rf include ~/.include
	cp -rf lib ~/.lib/

clean:
	rm -f bin/*.app
	rm -f lib/c-cpp/*.lib
	rm -f lib/python/*.py