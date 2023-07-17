class FileInterface:
    def __init__ (self):
        pass
    
    def openFile2Write (self,path):
        self.FP = open (path, 'w')

    def openFile2Read (self,path):
        self.FP = open (path, 'r')

    def openFile2Append (self,path):
        self.FP = open (path, 'a')

    def readAllLines (self):
        lines = self.FP.readlines()
        lines = [line[:-1] for line in lines]
        return lines
    
    def readLine (self, lineNumber):
        return self.readAllLines [lineNumber]
    
    def writeLine (self, line):
        self.FP.write (line + "\n")
        self.FP.flush()

    def writeList (self, list):
        for item in list:
            self.FP.write (item + "\n")
        self.FP.flush()
        
    def closeFile (self):
        self.FP.close