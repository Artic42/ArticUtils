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

def deleteFile (filePath):
    if os.path.isfile (filePath):
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