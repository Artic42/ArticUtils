import sqlite3
import fileManagement

def checkDatabaseExist(dbPath):
    fileManagement.checkExistsFile(dbPath)

class sqliteConnection ():
    def __init__(self, dbPath):
        self.con = sqlite3.connect (dbPath)
        self.cursor = self.con.cursor()
    
    def executeCommand (self, command):
        self.cursor.execute (command)

    def commitClose(self):
        self.con.commit()
        self.con.close()

