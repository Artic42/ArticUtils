import os

class command:
    def __init__ (self, command):
        result = os.system (command)
        self.signalNum = result & 0x00FF
        self.ExitCode = (result & 0xFF00) >> 8