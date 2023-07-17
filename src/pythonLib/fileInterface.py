class FileInterface:
    def __init__ (self):
        pass
    
    def openFile2Write (self,path):
        self.FP = open (path, 'w')

    def openFile2Read (self,path):
        self.FP = open (path, 'r')
        readAllLines()

    def openFile2Append (self,path):
        self.FP = open (path, 'a')
        
    def readAllLines (self):
        self.lines = self.FP.readlines()
        self.lines = [line[:-1] for line in lines]
        return self.lines
    
    def readLine (self, lineNumber):
        return readAllLines[lineNumber]
    
    def writeLine (self, line):
        self.FP.write (line + "\n")
        self.FP.flush()

    def writeList (self, list):
        for item in list:
            self.FP.write (item + "\n")
        self.FP.flush()
        
    def closeFile (self):
        self.FP.close