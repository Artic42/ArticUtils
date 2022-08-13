import thoth

class enviroment:
    def __init__ (self):
        self.passed = True
        self.failed = False
        self.testExecuted = 0
        self.testPassed = 0
        self.testSkipped = 0
        self.testFailed = 0

    def passTest (self):
        self.testExecuted = self.testExecuted + 1
        self.testPassed = self.testPassed + 1

    def skipTest (self):
        self.testExecuted = self.testExecuted + 1
        self.testSkipped = self.testSkipped + 1

    def failTest (self):
        self.testExecuted = self.testExecuted + 1
        self.testFailed = self.testFailed + 1
        self.passed = False
        self.failed = True

    def printResults (self):
        if self.passed == True:
            print ("The test have been SUCCESFULL")
        else:
            print ("The test has FAILED")
        print (f"{self.testExecuted} tests have been executed")
        print (f"{self.testPassed} tests have PASS")
        print (f"{self.testFailed} tests have FAILED")
        print (f"{self.testSkipped} tests have SKIPPED")
    
    def logResults (self):
        if self.passed == True:
            thoth.addEntry (thoth.INFO,"The test have been SUCCESFULL")
        else:
            thoth.addEntry (thoth.ERROR,"The test has FAILED")
        thoth.addEntry (thoth.INFO,f"{self.testExecuted} tests have been executed")
        thoth.addEntry (thoth.INFO,f"{self.testPassed} tests have PASS")
        thoth.addEntry (thoth.INFO,f"{self.testFailed} tests have FAILED")
        thoth.addEntry (thoth.INFO,f"{self.testSkipped} tests have SKIPPED")