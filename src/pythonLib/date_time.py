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

        self.calculateString ()
    
    def createString (self):
        result1 = f"{self.year_s}/{self.month_s}/{self.day_s}"
        result2 = f"{self.hour_s}:{self.minute_s}:{self.second_s}"
        return f"{result1} {result2}"

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

        self.calculateIntegers ()


    def isEarlierThan (self, date2):
        if self.year < date2.year:
            return True
        elif self.year > date2.year:
            return False
        if self.month < date2.month:
            return True
        elif self.month > date2.month:
            return False
        if self.day < date2.day:
            return True
        elif self.day > date2.day:
            return False
        if self.hour < date2.hour:
            return True
        elif self.hour > date2.hour:
            return False
        if self.minute < date2.minute:
            return True
        elif self.minute > date2.minute:
            return False
        if self.second < date2.second:
            return True
        elif self.second > date2.second:
            return False
        return True
    
    def isEqual (self, date2):
        if (self.second == date2.second and
            self.minute == date2.minute and
            self.hour == date2.hour and
            self.day == date2.day and
            self.month == date2.month and
            self.year == date2.year):
            return True
        else:
            return False        

    def simplify (self):
        daysInMonth = self.getDaysInMonth ()
        while self.second > 59:
            self.second = self.second - 60
            self.minute = self.minute + 1
        while self.minute > 59:
            self.minute = self.minute - 60
            self.hour = self.hour + 1
        while self.hour > 23:
            self.hour = self.hour - 24
            self.day = self.day + 1
        while self.day > daysInMonth[self.month-1]:
            self.day = self.day - daysInMonth[self.month-1]
            self.month = self.month + 1
        while self.month > 12:
            self.month = self.month - 12
            self.year = self.year + 1

    def calculateIntegers (self):
        self.year = int(self.year_s)
        self.month = int(self.month_s)
        self.day = int(self.day_s)
        self.hour = int(self.hour_s)
        self.minute = int(self.minute_s)
        self.second = int(self.second_s)

    def calculateString (self):
        self.year_s = f"{self.year:04}"
        self.month_s = f"{self.month:02}"
        self.day_s = f"{self.day:02}"
        self.hour_s = f"{self.hour:02}"
        self.minute_s = f"{self.minute:02}"
        self.second_s = f"{self.second:02}"

    def getDaysInMonth (self):
        if self.isLeapYear():
            return [31,28,31,30,31,30,31,31,30,31,30,31]
        else:
            return [31,29,31,30,31,30,31,31,30,31,30,31]

    def isLeapYear (self):
        if self.year % 4 == 0 and self.year % 100 != 0:
            return True
        if self.year % 400 == 0:
            return True
        return False
    
    def addSeconds (self, seconds):
        self.second = self.second + seconds
        self.simplify ()
        self.calculateString ()
    
    def addMinutes (self, minutes):
        self.minute = self.minute + minutes
        self.simplify ()
        self.calculateString ()
    
    def addHours (self, hours):
        self.hour = self.hour + hours
        self.simplify ()
        self.calculateString ()

    def addDays (self, days):
        self.day = self.day + days
        self.simplify ()
        self.calculateString ()

    def addMonths (self, months):
        self.addDays (months * 30)
    
    def addYears (self, years):
        self.year = self.year + years
        self.calculateString ()



def isEarliest (date1, date2):
    print ("isEarliest SHOLUD NOT BE USED")
    if date1.year < date2.year:
        return True
    elif date1.year > date2.year:
        return False
    if date1.month < date2.month:
        return True
    elif date1.month > date2.month:
        return False
    if date1.day < date2.day:
        return True
    elif date1.day > date2.day:
        return False
    if date1.hour < date2.hour:
        return True
    elif date1.hour > date2.hour:
        return False
    if date1.minute < date2.minute:
        return True
    elif date1.minute > date2.minute:
        return False
    if date1.second < date2.second:
        return True
    elif date1.second > date2.second:
        return False
    return True
