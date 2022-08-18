#Thoth

thoth_R: lib/c-cpp/thoth.lib Artic42_R
thoth_D: lib/c-cpp/thoth_D.lib Artic42_D
thoth_py: lib/python/thoth.py
thoth_utils: lib/python/thothUtils.py
thoth: thoth_D thoth_R thoth_py thoth_utils
	@cp src/thoth/thoth.h include/thoth.h

thothTest: src/thoth/thothTest.app thoth_D

lib/c-cpp/thoth.lib: src/thoth/thoth.* Artic42_R
	@${CC} ${OFLAGSR} ${IPATH} src/thoth/thoth.c -o lib/c-cpp/thoth.lib

lib/c-cpp/thoth_D.lib: src/thoth/thoth.* Artic42_D
	@${CC} ${OFLAGSD} ${IPATH} src/thoth/thoth.c -o lib/c-cpp/thoth_D.lib

lib/python/thoth.py: src/thoth/thoth.py
	@cp src/thoth/thoth.py lib/python/thoth.py

lib/python/thothUtils.py: src/thoth/thothUtils.py
	@cp src/thoth/thothUtils.py lib/python/thothUtils.py

src/thoth/thothTest.app: lib/c-cpp/thoth_D.lib src/thoth/test/test.c Artic42_D
	@rm -rf logs
	@$(CC) $(CFLAGSD) $(IPATH) lib/c-cpp/thoth_D.lib lib/c-cpp/Artic42_D.lib src/thoth/test/test.c -o src/thoth/thothTest.app
	@./src/thoth/thothTest.app
	@rm -f src/thoth/thothTest.app