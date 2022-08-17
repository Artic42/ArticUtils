# Herald

herald: lib/python/sendEmail.py bin/sendEmail.app bin/herald.app

lib/python/sendEmail.py: src/herald/sendEmail.py
	@cp -f src/herald/sendEmail.py lib/python/sendEmail.py

bin/sendEmail.app: src/herald/sendEmail.py
	@cat pythonInterpreter src/herald/sendEmail.py > bin/sendEmail.app

bin/herald.app: src/herald/herald.py
	@cat pythonInterpreter src/herald/herald.py > bin/herald.app
