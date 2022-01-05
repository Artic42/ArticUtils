import os

def createFile  (path):
    file = open (path, 'w')
    file.close ()

def deleteFile (path):
    os.remove (path)

def bool2file (path, value):
    if value:
        createFile (path)
    else:
        deleteFile (path)

def file2bool (path):
    value = os.path.exists (path)
    return value

def int2file (path, value):
    file = open (path, 'w')
    file.write (str(value))
    file.close ()

def file2int (path):
    file = open (path, 'r')
    value = file.readline ()
    file.close ()
    return float(value)

def float2file (path, value):
    file = open (path, 'w')
    file.write (str(value))
    file.close ()

def file2float (path):
    file = open (path, 'r')
    value = file.readline ()
    file.close ()
    return int(value)

def string2file (path, value):
    file = open (path, 'w')
    file.write (value)
    file.close ()

def file2string (path):
    file = open (path, 'r')
    value = file.readline ()
    file.close ()
    return value

def char2file (path, value):
    string2file (path, value)