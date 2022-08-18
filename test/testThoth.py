import testEngine
import fileManagement
import os
import thothUtils
import thoth

def main():
    print ("Testing Thoth")
    global refPath
    refPath = "src/thoth/test/referenceLogs"
    cleanLogFolder()

    if testEngine.env.isPassed():
        runCLibrary()
        compareLogFileQuantity ("src/thoth/test/logs")
    else:
        testEngine.env.skipTest()
    
    if testEngine.env.isPassed():
        joinLogs("src/thoth/test/logs")
        compareJoinedLogs ("src/thoth/test/logs")
    else:
        testEngine.env.skipTest()

    if testEngine.env.isPassed():
        runPythonLibrary()
        compareLogFileQuantity ("src/thoth/test/py_logs")
    else:
        testEngine.env.skipTest()

    if testEngine.env.isPassed():
        joinLogs("src/thoth/test/py_logs")
        compareJoinedLogs ("src/thoth/test/py_logs")
    else:
        testEngine.env.skipTest()

    if testEngine.env.isPassed():
        thothUtils.mergeLog("src/thoth/test/referenceLogs", "mergedLog", "src/thoth/test/mergedLog.log")
        if thothUtils.logsAreEqual ("src/thoth/test/mergedLog.log", "src/thoth/test/mergedLogRef.log"):
            testEngine.env.passTest()
        else:
            testEngine.env.failTest()
    else:
        testEngine.env.skipTest

    if testEngine.env.isPassed():
        thothUtils.filterByMask("src/thoth/test/mergedLogRef.log", thoth.getMaskName(thoth.INFO), "src/thoth/test/filteredMask.log")
        if thothUtils.logsAreEqual ("src/thoth/test/filteredMask.log", "src/thoth/test/filteredMaskRef.log"):
            testEngine.env.passTest()
        else:
            testEngine.env.failTest()
    else:
        testEngine.env.skipTest

    if testEngine.env.isPassed():
        thothUtils.filterByName("src/thoth/test/mergedLogRef.log", "Log1", "src/thoth/test/filteredName.log")
        if thothUtils.logsAreEqual ("src/thoth/test/filteredName.log", "src/thoth/test/referenceLogs/Log1.log"):
            testEngine.env.passTest()
        else:
            testEngine.env.failTest()
    else:
        testEngine.env.skipTest
    print ("Thoth test finished")

def cleanLogFolder():
    fileManagement.createDir ("src/thoth/test/logs")
    fileManagement.cleanDir ("src/thoth/test/logs")
    fileManagement.createDir ("src/thoth/test/py_logs")
    fileManagement.cleanDir("src/thoth/test/py_logs")

def runCLibrary():
    os.system ("make thothTest")

def runPythonLibrary():
    os.system ("python3 src/thoth/test/testThoth.py")

def compareLogFileQuantity (dirPath):
    if len(fileManagement.getFilesInDir(dirPath)) == 5:
        testEngine.env.passTest()
    else:
        testEngine.env.failTest()

def joinLogs (dirPath):
    thothUtils.joinLog(dirPath, "Log1", f"{dirPath}/Log1.log")
    thothUtils.joinLog(dirPath, "Log2", f"{dirPath}/Log2.log")
    thothUtils.joinLog(dirPath, "Log3", f"{dirPath}/Log3.log")

def compareJoinedLogs (dirPath):
    if (thothUtils.logsAreEqual(os.path.join(dirPath,"Log1.log"), os.path.join(refPath,"Log1.log")) and
        thothUtils.logsAreEqual(os.path.join(dirPath,"Log2.log"), os.path.join(refPath,"Log2.log")) and
        thothUtils.logsAreEqual(os.path.join(dirPath,"Log3.log"), os.path.join(refPath,"Log3.log"))):
        testEngine.env.passTest()
    else:
        testEngine.env.failTest()

if __name__ == "__main__":
    testEngine.startTest ()
    main()
    testEngine.env.printResults()