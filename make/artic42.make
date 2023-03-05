# Artic42

Artic42_R: lib/c-cpp/Artic42.lib
Artic42_D: lib/c-cpp/Artic42_D.lib
Artic42: Artic42_R Artic42_D
	@cp src/Artic42/Artic42.h include/Artic42.h

bin/CharacterFunctions.o: src/Artic42/CharacterFunctions.c
	@$(CC) $(OFLAGSR) $(IPATH) src/Artic42/CharacterFunctions.c -o bin/CharacterFunctions.o

bin/IntegerFunctions.o: src/Artic42/IntegerFunctions.c
	@$(CC) $(OFLAGSR) $(IPATH) src/Artic42/IntegerFunctions.c -o bin/IntegerFunctions.o

bin/fileManipulation.o: src/Artic42/fileManipulation.c
	@$(CC) $(OFLAGSR) $(IPATH) src/Artic42/fileManipulation.c -o bin/fileManipulation.o

bin/dateTime.o: src/Artic42/dateTime.c
	@$(CC) $(OFLAGSR) $(IPATH) src/Artic42/dateTime.c -o bin/dateTime.o

bin/colorFunctions.o: src/Artic42/colorFunctions.c
	@$(CC) $(OFLAGSR) $(IPATH) src/Artic42/colorFunctions.c -o bin/colorFunctions.o

lib/c-cpp/Artic42.lib: bin/CharacterFunctions.o bin/IntegerFunctions.o bin/fileManipulation.o bin/dateTime.o bin/colorFunctions.o
	@ar cr lib/c-cpp/Artic42.lib bin/CharacterFunctions.o bin/IntegerFunctions.o bin/fileManipulation.o bin/dateTime.o bin/colorFunctions.o
	@rm -f bin/CharacterFunctions.o bin/IntegerFunctions.o bin/fileManipulation.o bin/dateTime.o bin/colorFunctions.o

bin/CharacterFunctions_D.o: src/Artic42/CharacterFunctions.c
	@$(CC) $(OFLAGSD) $(IPATH) src/Artic42/CharacterFunctions.c -o bin/CharacterFunctions_D.o

bin/IntegerFunctions_D.o: src/Artic42/IntegerFunctions.c
	@$(CC) $(OFLAGSD) $(IPATH) src/Artic42/IntegerFunctions.c -o bin/IntegerFunctions_D.o

bin/fileManipulation_D.o: src/Artic42/fileManipulation.c
	@$(CC) $(OFLAGSD) $(IPATH) src/Artic42/fileManipulation.c -o bin/fileManipulation_D.o
	
bin/dateTime_D.o: src/Artic42/dateTime.c
	@$(CC) $(OFLAGSD) $(IPATH) src/Artic42/dateTime.c -o bin/dateTime_D.o

bin/colorFunctions_D.o: src/Artic42/colorFunctions.c
	@$(CC) $(OFLAGSD) $(IPATH) src/Artic42/colorFunctions.c -o bin/colorFunctions_D.o

lib/c-cpp/Artic42_D.lib: bin/CharacterFunctions_D.o bin/IntegerFunctions_D.o bin/fileManipulation_D.o bin/dateTime_D.o bin/colorFunctions_D.o
	@ar cr lib/c-cpp/Artic42_D.lib bin/CharacterFunctions_D.o bin/IntegerFunctions_D.o bin/fileManipulation_D.o bin/dateTime_D.o bin/colorFunctions_D.o
	@rm -f bin/CharacterFunctions_D.o bin/IntegerFunctions_D.o bin/fileManipulation_D.o bin/dateTime_D.o bin/colorFunctions_D.o