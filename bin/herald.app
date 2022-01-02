#!/usr/bin/python3

import readExcel
import modifyFile
import sys
import time
import sendEmail



def main (excelFilePath):
    emailConfigPath = "/tmp/emailConfig"
    emailFilePath = "/tmp/emails"
    sys.system ("mkdir -p" + emailConfigPath)
    sys.system ("mkdir -p" + emailFilePath)
    #Read excel file
    excel = readExcel.readExcelFile (excelFilePath)

    #Get config values
    server = readExcel.getValueCell(excel, 1, 2)
    sender = readExcel.getValueCell(excel, 2, 2)
    subject = readExcel.getValueCell(excel, 3, 2)
    user = readExcel.getValueCell(excel, 4, 2)
    passwd = input ("Give email password?")

    sendEmail.createEmailConfig (emailConfigPath, server, user, passwd)

    #Create a list of all variables to change in body
    titleRow = readExcel.getRowValues(excel,6,6) [0] [2:]
 
    #Create list of data for every email
    recipients = readExcel.getRowValues (excel,7, None)
    
    #For all items in list
        #Make the changes to the body, and create .email
    paths = []    
    for recipient in recipients:
        bodyPath = "/tmp/body"
        modifyFile.copyFile ('body.html', bodyPath)
        variables = recipient[2:]
        for i in range(len(variables)):
            modifyFile.replaceString (bodyPath, titleRow[i], str(variables[i]))
        
        #Create .email file
        tmpPath = emailFilePath + "/" + recipient[1] + ".email"
        sendEmail.createEmailFile (tmpPath, bodyPath, subject, sender, recipient[0])

        #Put path on list
        paths.append (tmpPath)

    #For item in path send email and wait 6 seconds
    for path in paths:
        sendEmail.send (path, emailConfigPath)
        print ("Email send!")
        time.sleep (6)
    
    return



if __name__ == "__main__":
    if len (sys.argv) < 2:
        main ("HeraldConfig.xlsx")
    else:
        main (sys.argv [1])