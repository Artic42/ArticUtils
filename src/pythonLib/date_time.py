from datetime import datetime

class createDate:
    def __init__ (self):
        pass

    def now (self):
        date = datetime.now()
        self.year = int(date.strftime("%Y"))
        self.month = int(date.strftime("%m"))
        self.day = int(date.strftime("%d"))
        self.hour = int(date.strftime("%H"))
        self.minute = int(date.strftime("%M"))
        self.second = int(date.strftime("%S"))

        self.year_s = date.strftime("%Y")
        self.month_s = date.strftime("%m")
        self.day_s = date.strftime("%d")
        self.hour_s = date.strftime("%H")
        self.minute_s = date.strftime("%M")
        self.second_s = date.strftime("%S")
    
    def createString (self):
        result1 = self.year_s + "/" + self.month_s + "/" + self.day_s + " "
        result2 = self.hour_s + ":" + self.minute_s + ":" + self.second_s
        return result1 + result2

    def readString (self, string):
        date = string.split(" ")[0]
        time = string.split(" ")[1]
        splittedDate = date.split("/")
        splittedTime = time.split(":")

        self.year_s = splittedDate[0]
        self.month_s = splittedDate[1]
        self.day_s = splittedDate[2]
        self.hour_s = splittedTime[0]
        self.minute_s = splittedTime[1]
        self.second_s = splittedTime [2]

        self.year = int(self.year_s)
        self.month = int(self.month_s)
        self.day = int(self.day_s)
        self.hour = int(self.hour_s)
        self.minute = int(self.minute_s)
        self.second = int(self.second_s)
