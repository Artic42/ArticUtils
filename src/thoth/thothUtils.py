import hermes
import fileManagement
import date_time
import os
import sys


if __name__ == "__main__":
    pass

def joinLog(dirPath, name, outputPath):
    logs = logList (dirPath)
    result = logs.filterAndJoinLog (name)
    result.writeLog(outputPath)

def mergeLog(dirPath, name, outputPath):
    logs = logList (dirPath)
    result = logs.mergeLog (name)
    result.writeLog(outputPath)

def filterByName (logPath, name, outputPath):
    newLog = log()
    newLog.readPath (logPath)
    newLog = newLog.filterEntryByName (name)
    newLog.writeLog (outputPath)

def filterByMask (logPath, mask, outputPath):
    newLog = log()
    newLog.readPath (logPath)
    newLog = newLog.filterEntryByMask (mask)
    newLog.writeLog (outputPath)

def logsAreEqual (log1Path, log2Path):
    log1 = log()
    log1.readPath (log1Path)
    log2 = log()
    log2.readPath (log2Path)
    if log1.name != log2.name:
        return False
    if len(log1.logEntries) != len(log2.logEntries):
        return False
    for i in range(len(log1.logEntries)):
        if not logEntriesAreEqual (log1.logEntries[i], log2.logEntries[i]):
            return False
    return True

def logEntriesAreEqual (Entry1, Entry2):
    if (Entry1.name == Entry2.name and
        Entry1.mask == Entry2.mask and
        Entry1.message == Entry2.message):
        return True
    else:
        return False

class logList:
    def __init__ (self, path):
        self.list = []
        self.dirPath = path
        logFiles = fileManagement.getFilesInDir(self.dirPath)
        for logFile in logFiles:
            newLog = log()
            newLog.readPath (os.path.join(self.dirPath, logFile))
            self.list.append(newLog)
    
    def filterLogByName (self, name):
        newList = [item for item in self.list if item.name == name]
        self.list = newList

    def sortByEarliest (self):
        newList = []
        while len(self.list) != 1:
            earliest = self.list[1]
            for item in self.list:
                if item.date.isEarlierThan(earliest.date):
                    earliest = item
            newList.append(earliest)
            self.list.remove(earliest)
        newList.append(self.list[0])
        self.list = newList

    def earliestDate (self):
        earliest = self.list[0].date
        for item in self.list:
            if item.date.isEarlierThan(earliest):
                earliest = item.date
        return earliest

    def filterAndJoinLog (self, name):
        self.filterLogByName (name)
        if len(self.list) == 0:
            print ("ERROR: No logs with selected name")
            sys.exit (-1)
        for item in self.list:
            if item.merged:
                print ("ERROr: Merged logs can't be joined")
                sys.exit (-2)
        self.sortByEarliest ()
        newLog = log()
        newLog.name = name
        newLog.date = self.list[0].date
        for item in self.list:
            newLog.logEntries = newLog.logEntries + item.logEntries
        return newLog

    def indexEarliestEntryLog (self):
        result = 0
        for i in range(len(self.list)):
            if self.list[i].earliestEntryDate().isEarlierThan(self.list[result].earliestEntryDate()):
                result = i
        return result

    def mergeLog (self, name):
        newLog = log()
        newLog.name = name
        newLog.date = self.earliestDate()
        newLog.merged = True
        while len(self.list) > 1:
            index = self.indexEarliestEntryLog()
            newLog.logEntries.append(self.list[index].readFirstEntry())
            self.list[index].removeFirstEntry()
            if self.list[index].logEntries == []:
                self.list.remove(self.list[index])
        newLog.logEntries = newLog.logEntries + self.list[0].logEntries
        return newLog

class log:
    def __init__ (self):
        self.name = ""
        self.date = ""
        self.merged = False
        self.logEntries = []
    
    def readPath (self, path):
        file = fileManagement.fileIO()
        file.openFile2Read (path)
        logLines = file.readAllLines ()
        firstLine = logLines[0]
        if len(logLines) > 1:
            secondLine = logLines[1]
            if len(secondLine.split(" - ")) > 3:
                self.merged = True
            else:
                self.merged = False
        messageLines = logLines[1:]
        splitLine = firstLine.split(" - ")
        self.name = splitLine[0]
        self.date = date_time.createDate()
        self.date.readString(splitLine[1])
        self.logEntries = []
        for line in messageLines:
            entry = logEntry(line, self.name)
            self.logEntries.append (entry)

    def writeLog (self, path):
        file = fileManagement.fileIO()
        file.openFile2Write(path)
        file.writeLine(f"{self.name} - {self.date.createString()}")
        for entry in self.logEntries:
            if self.merged:
                file.writeLine(entry.createLineMerged())
            else:
                file.writeLine(entry.createLineNormal())
    
    def earliestEntryDate (self):
        return self.logEntries[0].date

    def readFirstEntry (self):
        return self.logEntries[0]

    def removeFirstEntry (self):
        self.logEntries.remove(self.logEntries[0])

    def filterEntryByName (self, name):
        newLog = log()
        newLog.name = name
        newLog.date = self.date
        for entry in self.logEntries:
            if entry.name == name:
                newLog.logEntries.append(entry)
        return newLog

    def filterEntryByMask (self, mask):
        newLog = log()
        newLog.name = self.name
        newLog.date = self.date
        newLog.merged = self.merged
        for entry in self.logEntries:
            if entry.mask == mask:
                newLog.logEntries.append(entry)
        return newLog

    

class logEntry:
    def __init__ (self, line, logName):
        splitedLine = line.split (" - ")
        self.date = date_time.createDate()
        self.date.readString(splitedLine[0])
        if len(splitedLine) > 3:
            self.name = splitedLine [1]
            self.mask = splitedLine [2]
            self.message = splitedLine[3]
        else:
            self.name = logName
            self.mask = splitedLine [1]
            self.message = splitedLine[2]
    
    def createLineNormal (self):
        return f"{self.date.createString()} - {self.mask} - {self.message}"
    
    def createLineMerged (self):
        return f"{self.date.createString()} - {self.name} - {self.mask} - {self.message}"