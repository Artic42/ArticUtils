# Hermes

hermes_R: lib/c-cpp/hermes.lib
hermes_D: lib/c-cpp/hermes_D.lib
hermes_py: lib/python/hermes.py
hermes: hermes_D hermes_R hermes_py
hermesTest: src/hermes/hermesTest.app


lib/c-cpp/hermes.lib: src/hermes/hermes.c
	@$(CC) $(OFLAGSR) $(IPATH) src/hermes/hermes.c -o lib/c-cpp/hermes.lib

lib/c-cpp/hermes_D.lib: src/hermes/hermes.c
	@$(CC) $(OFLAGSD) $(IPATH) src/hermes/hermes.c -o lib/c-cpp/hermes_D.lib

src/hermes/hermesTest.app: lib/c-cpp/hermes_D.lib src/hermes/test.c
	@$(CC) $(CFLAGSD) $(IPATH) lib/c-cpp/hermes_D.lib src/hermes/test.c -o src/hermes/hermesTest.app
	@./src/hermes/hermesTest.app
	@rm -f src/hermes/hermesTest.app

lib/python/hermes.py: src/hermes/hermes.py
	@cp src/hermes/hermes.py lib/python/hermes.py
