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
    
    def readEntry (self, columns, table):
        self.cursor.execute (f"SELECT {columns} FROM {table};")
        return self.cursor.fetchall()

    def readEntryFiltered (self, columns, table, filter):
        self.cursor.execute (f"SELECT {columns} FROM {table} WHERE {filter};")
        return self.cursor.fetchall()

    def entryExistsOnTable (self, table, condition):
        entry = self.cursor.execute (f"SELECT TOP 1 * FROM {table} WHERE {condition};")
        if entry == []:
            return False
        else:
            return True
    
    def deleteEntryFromTable (self, table, condition):
        self.cursor.execute (f"DELETE FROM {table} WHERE {condition};")

    def commitClose(self):
        self.con.commit()
        self.con.close()

