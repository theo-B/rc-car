#!usr/bin/python

# # #
# Reads lines from C joystick subprocess and writes to serial port
# # # 

import subprocess
from serial import Serial 

process = subprocess.Popen("./joystick/js-read", stdout=subprocess.PIPE)

ser = Serial("/dev/ttyAMA0",9600,timeout=2)

print "Subprocess opened."

while 1:
	for line in iter(process.stdout.readline, ''):
		print "sending " + line,
		ser.write(line,)
