import os
import json


def replaceString (path, old, new):
    command = 'sed -i "s/' + old + '/' + new + '/" ' + path
    os.system (command)

def copyFile (referencePath, destPath):
    command = "cp -f " + referencePath + " " + destPath
    os.system (command)

def moveFile (referencePath, destPath):
    command = "mv -f " + referencePath + " " + destPath
    os.system (command)

def createFile (path):
    os.system (f"touch {path}")

def checkExistsFile(filePath):
    return os.path.isfile (filePath)

def checkFileEmpty (filePath):
    return os.path.getsize (filePath) == 0

def checkFileNotEmpty (filePath):
    return not checkFileEmpty (filePath)

def filesSizeInLines (filePath):
    file = fileIO
    file.openFile2Read (filePath)
    result = len(file.readAllLines())
    file.closeFile()
    return result

def deleteFile (filePath):
    if checkExistsFile(filePath):
        os.remove(filePath)

def copyDir (referencePath, destPath):
    command = "cp -rf " + referencePath + " " + destPath
    os.system (command)

def moveDir (referencePath, destPath):
    command = "mv -rf " + referencePath + " " + destPath
    os.system (command)

def checkExistsDir (path):
    return os.path.isdir (path)

def cleanDir (dirPath):
    files = getFilesInDir (dirPath)
    for file in files:
        deleteFile (dirPath + "/" + file)

def createDir (dirPath):
    if os.path.isdir(dirPath)==False:
        os.mkdir (dirPath)

        

def deleteDir (path):
    command = "rm -rf " + path
    os.system (command)

def getFilesInDir (path):
    result = [f for f in os.listdir(path) if os.path.isfile(os.path.join(path, f))]
    return result

def filesInDirAreEqual (path1, path2):
    files1 = getFilesInDir (path1)
    files2 = getFilesInDir (path2)
    if files1 != files2:
        return False
    for file in files1:
        os.system (f"diff {path1}/{file} {path2}/{file} | tee diff")
        if checkFileNotEmpty ("diff"):
            deleteFile ("diff")
            return False
    deleteFile ("diff")
    return True

class fileIO:
    
    
    

    def updateFile (self)
        writeList(self.list)

    def writeLine (self, line):
        self.FP.write (line + "\n")
        self.FP.flush()

    def writeList (self, list):
        for item in list:
            self.FP.write (item + "\n")
        self.FP.flush()

    def writeJson (self, path, jsonContent):
        self.openFile2Write(path)
        json.dump(jsonContent, self.FP)
        self.closeFile
        
    def readAllLines (self):
        self.lines = self.FP.readlines()
        self.lines = [line[:-1] for line in lines]
        return self.lines
    
    def readLine (self, lineNumber):
        return self.FP.readlines()[lineNumber][:-1]

    def addLine (self, line)
        self.lines.append(line)
        
    def setCursor (self, cursorPos)
        self.cursor = cursorPos
        
    def addLineToCursor (self, line)
        self.lines.insert(self.cursor, line)
        self.cursor += 1

    def replaceLineInCursor (self, line)
        self.lines[self.cursor] = line
        self.cursor += 1


    def readJson (self, path):
        self.openFile2Read(path)
        result = json.load(self.FP)
        self.closeFile
        return result
    
    def getLine(self, lineNumber):
        return self.lines[lineNumber]
    
    def setLine(self, lineNumber, line):
        self.lines[lineNumber] = line
    
    def howManyLines (self):
        return length(self.lines)


