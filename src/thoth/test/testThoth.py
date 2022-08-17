import thoth
import time

def test():
    log1 = thoth.log ("Log1", "src/thoth/test/py_logs", thoth.INFO, 3)
    log2 = thoth.log ("Log2", "src/thoth/test/py_logs", thoth.DEBUG, 3)
    log3 = thoth.log ("Log3", "src/thoth/test/py_logs", thoth.INFO | thoth.DEBUG, 3)
    # Send a message that should appear in 2
    thoth.addEntry (thoth.DEBUG, "This message should appear on 2 and 3")
    time.sleep (1)
    thoth.addEntry (thoth.INFO, "This message should appear on 1 and 3")
    time.sleep (1)
    thoth.addEntry (thoth.SAFETY_ALARM, "This message should not appear")
    #Add a mask and eliminate a mask
    log1.addMask (thoth.DEBUG)
    log3.delMask (thoth.DEBUG)
    time.sleep (1)
    #Send a message with the mask you elimiante and create it
    thoth.addEntry (thoth.DEBUG, "This message should appear on 2 and 1")
    time.sleep (1)
    thoth.addEntry (thoth.INFO, "This message should appear on 1 and 3")
    time.sleep (1)
    thoth.addEntry (thoth.SAFETY_ALARM, "This message should not appear")
    time.sleep (1)
    #Close the middle log
    log2.closeLog ()
    #Send a message for both logs
    thoth.addEntry (thoth.DEBUG, "This message should appear on 1")
    time.sleep (1)
    #Eliminate last
    log3.closeLog ()
    #Send a message for last log
    thoth.addEntry (thoth.INFO, "This message should appear on 1")
    time.sleep (1)
    #Eliminate first 
    log1.closeLog ()
    #Send a message and check that it doesn crash
    thoth.addEntry (thoth.SAFETY_ALARM, "This message should not appear")

if __name__ == "__main__":
    test()


