# Python Library

pythonLib: lib/python/modifyFile.py lib/python/readExcel.py lib/python/fileManagement.py lib/python/sqliteEngine.py lib/python/date_time.py lib/python/testEngine.py

lib/python/modifyFile.py: src/pythonLib/modifyFile.py
	@cp src/pythonLib/modifyFile.py lib/python/modifyFile.py

lib/python/readExcel.py: src/pythonLib/readExcel.py
	@cp src/pythonLib/readExcel.py lib/python/readExcel.py

lib/python/fileManagement.py: src/pythonLib/fileManagement.py
	@cp src/pythonLib/fileManagement.py lib/python/fileManagement.py

lib/python/sqliteEngine.py: src/pythonLib/sqliteEngine.py
	@cp src/pythonLib/sqliteEngine.py lib/python/sqliteEngine.py

lib/python/date_time.py: src/pythonLib/date_time.py
	@cp src/pythonLib/date_time.py lib/python/date_time.py

lib/python/testEngine.py: src/pythonLib/testEngine.py
	@cp src/pythonLib/testEngine.py lib/python/testEngine.py