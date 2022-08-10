import date_time
import fileManagement

#Mask constants
INFO = 0x01
DEBUG = 0x02
WARNING = 0x04
SAFETY_WARNING = 0x08
ALARM = 0x10
SAFETY_ALARM = 0x20
COMMUNICATION_SEND = 0x40
COMMUNICATION_REC = 0x80
ERROR = 0x100

global listOfLogs
listOfLogs = []

def addEntry (mask, message):
    line = calculateString (message, mask)

    for log in listOfLogs:
        if (log.mask & mask) != 0x0:
            log.filePointer.addLine (line)
            log.entriesOnFile = log.entriesOnFile + 1
            if log.entriesOnFile >= log.entryLimit:
                log.entriesOnFile = 0
                log.closeLogFile()
                log.filePointer = log.openLogFile()

def closeAllLogs ():
    listOfLogsCopy = listOfLogs.copy()
    for log in listOfLogsCopy:
        log.closeLog()

def getMaskName (mask):
    if mask == INFO:
        return "INFO"
    if mask == DEBUG:
        return "DEBUG"
    if mask == WARNING:
        return "WARNING"
    if mask == SAFETY_WARNING:
        return "SAFETY_WARNING"
    if mask == ALARM:
        return "ALARM"
    if mask == SAFETY_ALARM:
        return "SAFETY_ALARM"
    if mask == COMMUNICATION_SEND:
        return "COMMUNICATION_SEND"
    if mask == COMMUNICATION_REC:
        return "COMMUNICATION_REC"
    if mask == ERROR:
        return "ERROR"

def calculateString (Message, mask):
    date = date_time.datetime()
    date.now()
    result1 = date.createString()
    result2 = " - " + getMaskName (mask) + " - "
    return result1 + result2 + Message

class log:
#Public methods
    def __init__ (self, name, path, mask, entries):
        self.name = name
        self.directoryPath = path
        self.mask = mask
        self.entriesOnFile = 0
        self.entryLimit = entries
        self.filePointer = self.openLogFile ()
        
        listOfLogs.append (self)

    def closeLog (self):
        self.closeLogFile()
        listOfLogs.remove(self)
        del self

    def addMask (self, mask):
        self.mask = self.mask | mask

    def delMask (self, mask):
        self.mask = self.mask | (~mask)

#Private methods
    def openLogFile (self):
        path1 = self.directoryPath + "/" + self.name + "_"
        now = date_time.now()
        path2 = now.year_s + now.month_s + now.day_s + "_"
        path3 = now.hour_s + now.minute_s + now.second_s + ".log"
        path = path1 + path2 + path3

        fileManagement.createDir(self.directoryPath)
        file = fileManagement.fileIO()

        if fileManagement.checkExistsFile(path) == False:
            file.openFile2Write(path)
            file.addLine(self.name)
        else:
            file.openFile2Append(path)
        
        return file

    def closeLogFile (self):
        self.filePointer.closeFile()
