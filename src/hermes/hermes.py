import fileManagement

def bool2file (path, value):
    if value:
        fileManagement.createFile (path)
    else:
        fileManagement.deleteFile (path)

def file2bool (path):
    value = fileManagement.checkExistsFile (path)
    return value

def int2file (path, value):
    file = fileManagement.fileIO()
    file.openFile2Write (path)
    file.addLine (str(value))
    file.closeFile ()

def file2int (path):
    file = fileManagement.fileIO()
    file.openFile2Read (path)
    value = file.readLine(0)
    file.closeFile ()
    return int(value)

def float2file (path, value):
    file = fileManagement.fileIO()
    file.openFile2Write (path)
    file.addLine (str(value))
    file.closeFile ()

def file2float (path):
    file = fileManagement.fileIO()
    file.openFile2Read (path)
    value = file.readLine(0)
    file.closeFile ()
    return float(value)

def string2file (path, value):
    file = fileManagement.fileIO()
    file.openFile2Write (path)
    file.addLine (value)
    file.closeFile ()

def file2string (path):
    file = fileManagement.fileIO()
    file.openFile2Read (path)
    value = file.readLine(0)
    file.closeFile ()
    return value

def char2file (path, value):
    string2file (path, value)

def file2char (path, offset):
    return file2string (path) [offset]

def file2list (path):
    file = open (path, 'r')
    value = file.readlines ()
    value = [line[:-1] for line in value]
    print ("DO NOT USE FILE2LIST")
    file.close()
    return value

def list2file (path, list):
    file = open (path, 'w')
    for line in list:
        file.write(line + "\n")
    print ("DO NOT USE LIST2FILE")
    file.close()