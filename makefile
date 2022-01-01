#Constant definitions

CC = gcc
CFLAGSR = -Wall -lncurses
CFLAGSD = -g $(CFLAGSR)
OFLAGSR = -c $(CFLAGSR)
OFLAGSD = -c $(CFLAGSD)
IPATH = -Iinclude

# All

all: Artic42 Hermes

# Artic42
Artic42_R: lib/Artic42.lib
Artic42_D: lib/Artic42_D.lib
Artic42: Artic42_R Artic42_D

Source/Artic42/bin/CharacterFunctions.o: Source/Artic42/CharacterFunctions.c
	$(CC) $(OFLAGSR) $(IPATH) Source/Artic42/CharacterFunctions.c -o Source/Artic42/bin/CharacterFunctions.o

Source/Artic42/bin/IntegerFunctions.o: Source/Artic42/IntegerFunctions.c
	$(CC) $(OFLAGSR) $(IPATH) Source/Artic42/IntegerFunctions.c -o Source/Artic42/bin/IntegerFunctions.o

lib/Artic42.lib: Source/Artic42/bin/CharacterFunctions.o Source/Artic42/bin/IntegerFunctions.o
	ar cr lib/Artic42.lib Source/Artic42/bin/CharacterFunctions.o Source/Artic42/bin/IntegerFunctions.o

Source/Artic42/bin/CharacterFunctions_D.o: Source/Artic42/CharacterFunctions.c
	$(CC) $(OFLAGSD) $(IPATH) Source/Artic42/CharacterFunctions.c -o Source/Artic42/bin/CharacterFunctions_D.o

Source/Artic42/bin/IntegerFunctions_D.o: Source/Artic42/IntegerFunctions.c
	$(CC) $(OFLAGSD) $(IPATH) Source/Artic42/IntegerFunctions.c -o Source/Artic42/bin/IntegerFunctions_D.o

lib/Artic42_D.lib: Source/Artic42/bin/CharacterFunctions_D.o Source/Artic42/bin/IntegerFunctions_D.o
	ar cr lib/Artic42_D.lib Source/Artic42/bin/CharacterFunctions_D.o Source/Artic42/bin/IntegerFunctions_D.o

# Hermes
Hermes_R: lib/Hermes.lib
Hermes_D: lib/Hermes_D.lib
Hermes: Hermes_D Hermes_R

lib/Hermes.lib: Source/Hermes/Hermes.c
	$(CC) $(OFLAGSR) $(IPATH) Source/Hermes/Hermes.c -o lib/Hermes.lib

lib/Hermes_D.lib: Source/Hermes/Hermes.c
	$(CC) $(OFLAGSD) $(IPATH) Source/Hermes/Hermes.c -o lib/Hermes_D.lib