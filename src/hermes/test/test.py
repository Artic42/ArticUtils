import testEngine
import hermes
import os

def main ():
    global testPath
    testPath = "/tmp/testHermes"
    if testEngine.env.isPassed():
        print ("Testing Hermes")
        os.system ("make hermesTest")
        if hermes.file2string ("src/hermes/test/result.txt") == "TEST OK":
            testEngine.env.passTest ()
        else:
            testEngine.env.failTest ()
    else:
        testEngine.env.skipTest ()
    
    if testEngine.env.isPassed ():
        if testBool () == True:
            testEngine.env.passTest ()
        else:
            testEngine.env.failTest ()
    else:
        testEngine.env.skipTest ()
    
    if testEngine.env.isPassed ():
        if integerTest () == True:
            testEngine.env.passTest ()
        else:
            testEngine.env.failTest ()
    else:
        testEngine.env.skipTest ()
    
    if testEngine.env.isPassed ():
        if floatTest () == True:
            testEngine.env.passTest ()
        else:
            testEngine.env.failTest ()
    else:
        testEngine.env.skipTest ()
    
    if testEngine.env.isPassed ():
        if charTest () == True:
            testEngine.env.passTest ()
        else:
            testEngine.env.failTest ()
    else:
        testEngine.env.skipTest ()
    
    if testEngine.env.isPassed ():
        if stringTest () == True:
            testEngine.env.passTest ()
        else:
            testEngine.env.failTest ()
    else:
        testEngine.env.skipTest ()

    if testEngine.env.isPassed ():
        print ("Test Hermes OK")

def testBool ():
    hermes.bool2file (testPath, True)
    if hermes.file2bool(testPath) != True:
        return False

    hermes.bool2file (testPath, False)
    if hermes.file2bool (testPath) != False:
        return False
    return True

def integerTest ():
    testInteger = 493
    hermes.int2file (testPath, testInteger)
    if hermes.file2int(testPath) != testInteger:
        return False

    testInteger = -589
    hermes.int2file (testPath, testInteger)
    if hermes.file2int(testPath) != testInteger:
        return False
    return True

def floatTest ():
    testFloat = 50.1
    hermes.float2file (testPath, testFloat)
    if hermes.file2float (testPath) != testFloat:
        return False
    
    testFloat = -589.76
    hermes.float2file (testPath, testFloat)
    if hermes.file2float (testPath) != testFloat:
        return False
    return True

def charTest ():
    testChar = "B"
    hermes.char2file (testPath, testChar)
    if hermes.file2char (testPath, 0) != testChar:
        return False
    return True

def stringTest ():
    hermes.string2file (testPath, testPath)
    if hermes.file2string (testPath) != testPath:
        return False
    return True


if __name__ == "__main__":
    testEngine.startTest()
    main ()
    testEngine.env.printResults()