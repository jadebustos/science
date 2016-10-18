#!/usr/bin/python

# get bin representation from ascii text
def getBinFromASCII(textString):
	binaryChunk = ""
	textStringBinary = ""
	textBinary = ""
	for i in range(0,len(textString)):
        	binaryChunk=bin(ord(textString[i]))[2:].zfill(8)
        	textBinary += binaryChunk
	return textBinary

# get bin representation fron hex string, two chars define an 8-bit ascii char
def getBinFromHexString(hexString):
	hexChunk = ""
	binaryChunk = ""
	hexBinary = ""
	for i in range (0,len(hexString),2):
        	hexChunk=hexString[i]+hexString[i+1]
        	binaryChunk=bin(int(hexChunk,16))[2:].zfill(8)
        	hexBinary += binaryChunk
	return hexBinary

# xor to binary strings (same length)
def xorBinStrings(str1, str2):
	xorString = ""
	for i in range(0,len(str1)):
        	if str1[i] == str2[i]:
                	xorString += '0'
        	else:
                	xorString +=  '1'
	return xorString

# get hex string from bin string
def getHexStringFromBin(binString):
	hexString = ""
	for i in range(0, len(binString), 8):
		binChunk = ""
		for j in range(0,8):
			binChunk += binString[i+j]
		hexString += hex(int(binChunk,2))[2:].zfill(2)
	return hexString

# non used functions

# get ascii char from binary string, 8 elements -> 1 char
def getStringFromBin(binString):
	asciiString = ""
	for i in range (0,len(binString),8):
		binChunk = ""
		for j in range (i, i+8):
			binChunk += binString[i]
		asciiChar = chr(int(binChunk,2)) 
		asciiString += asciiChar
	return asciiString

#
def getAsciiFromHexString(hexString):
        hexChunk = ""
        asciiChar = ""
        asciiString = ""
        for i in range(0, len(hexString),2):
                hexChunk = hexString[i] + hexString[i+1]
                asciiChar = chr(int(hexChunk,16))
                asciiString += asciiChar
        return asciiString

#
def getHexFromAsciiString(asciiString):
	hexString = ""
	for i in range(0, len(asciiString)):
		hexString += hex(ord(asciiString[i]))[2:].zfill(2)
	return hexString

pt="attack at dawn"
#ct="6c73d5240a948c86981bc294814d"
ct="09e1c5f70a65ac519458e7e53f36"

newPt = "attack at dusk"
newCt = ""

# pt -> bin
ptBinary = getBinFromASCII(pt)

# ct -> bin 
ctBinary = getBinFromHexString(ct)

# otpKey
otpKey = xorBinStrings(ptBinary, ctBinary)

# newPt -> bin
newPtBinary = getBinFromASCII(newPt)
newCt = getHexStringFromBin(xorBinStrings(newPtBinary, otpKey))

print ct
print newCt
print "---"
print getHexStringFromBin(xorBinStrings(ptBinary, otpKey))
