import os


def replaceString (path, old, new):
    command = 'sed -i "s/' + old + '/' + new + '/" ' + path
    os.system (command)

def copyFile (referencePath, destPath):
    command = "cp -f " + referencePath + " " + destPath
    os.system (command)

def moveFile (referencePath, destPath):
    command = "mv -f " + referencePath + " " + destPath
    os.system (command)

def checkExistsFile(filePath):
    return os.path.isfile (filePath)

def deleteFile (filePath):
    if checkExistsFile(filePath):
        os.remove(filePath)

def copyDir (referencePath, destPath):
    command = "cp -rf " + referencePath + " " + destPath
    os.system (command)

def moveDir (referencePath, destPath):
    command = "mv -rf " + referencePath + " " + destPath
    os.system (command)

def createDir (dirPath):
    if os.path.isdir(dirPath)==False:
        os.mkdir (dirPath)

def deleteDir (path):
    command = "rm -rf " + path
    os.system (command)

def getFilesInDir (path):
    result = [f for f in os.listdir(path) if os.path.isfile(os.path.join(path, f))]
    return result

class fileIO:
    def __init__ (self):
        pass
    
    def openFile2Write (self,path):
        self.FP = open (path, 'w')

    def openFile2Read (self,path):
        self.FP = open (path, 'r')

    def openFile2Append (self,path):
        self.FP = open (path, 'a')

    def addLine (self, line):
        self.FP.write (line + "\n")
        self.FP.flush()
    
    def readAllLines (self):
        return self.FP.readlines()
    
    def readLine (self, lineNumber):
        return self.FP.readlines()[lineNumber]

    def closeFile (self):
        self.FP.close