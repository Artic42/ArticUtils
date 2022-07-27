import os

def replaceString (path, old, new):
    command = 'sed -i "s/' + old + '/' + new + '/" ' + path
    os.system (command)

def copyFile (referencePath, destPath):
    command = "cp -f " + referencePath + " " + destPath
    os.system (command)

def createDirectory (dirPath):
    if os.path.isdir(dirPath)==False:
        os.mkdir (dirPath)

def deleteFile (filePath):
    if os.path.isfile (filePath):
        os.remove(filePath)