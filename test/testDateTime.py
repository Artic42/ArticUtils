import testEngine
import date_time

def main():
    print ("Testing date_time")
    date1 = date_time.createDate ()
    date2 = date_time.createDate ()
    if testEngine.env.isPassed ():
        date1.now ()
        date2.readString ("1989/09/05 23:45:34")
        if date2.isEarlierThan(date1):
            testEngine.env.passTest()
        else:
            testEngine.env.failTest()
    else:
        testEngine.env.skipTest ()
    
    if testEngine.env.isPassed ():
        if date2.createString () == "1989/09/05 23:45:34":
            testEngine.env.passTest()
        else:
            testEngine.env.failTest()
    else:
        testEngine.env.skipTest ()

    if testEngine.env.isPassed ():
        date2.addSeconds (30)
        if date2.createString () == "1989/09/05 23:46:04":
            testEngine.env.passTest()
        else:
            testEngine.env.failTest()
    else:
        testEngine.env.skipTest ()

    if testEngine.env.isPassed ():
        date2.addMinutes (60)
        if date2.createString () == "1989/09/06 00:46:04":
            testEngine.env.passTest()
        else:
            testEngine.env.failTest()
    else:
        testEngine.env.skipTest ()
    
    if testEngine.env.isPassed ():
        date2.addHours (1)
        if date2.createString () == "1989/09/06 01:46:04":
            testEngine.env.passTest()
        else:
            testEngine.env.failTest()
    else:
        testEngine.env.skipTest ()

    if testEngine.env.isPassed ():
        date2.addDays (4)
        if date2.createString () == "1989/09/10 01:46:04":
            testEngine.env.passTest()
        else:
            testEngine.env.failTest()
    else:
        testEngine.env.skipTest ()

    if testEngine.env.isPassed ():
        date2.addMonths (2)
        if date2.createString () == "1989/11/09 01:46:04":
            testEngine.env.passTest()
        else:
            testEngine.env.failTest()
    else:
        testEngine.env.skipTest ()

    if testEngine.env.isPassed ():
        date2.addYears (1)
        if date2.createString () == "1990/11/09 01:46:04":
            testEngine.env.passTest()
        else:
            testEngine.env.failTest()
    else:
        testEngine.env.skipTest ()

    if testEngine.env.isPassed ():
        date2 = date1
        if date2.isEqual (date1):
            testEngine.env.passTest()
        else:
            testEngine.env.failTest()
    else:
        testEngine.env.skipTest ()
    print ("Date_time test finnished")

if __name__ == "__main__":
    testEngine.startTest()
    main ()
    testEngine.env.printResults()