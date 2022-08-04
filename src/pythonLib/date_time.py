from datetime import datetime

class now:
    def __init__ (self):
        self.now()

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