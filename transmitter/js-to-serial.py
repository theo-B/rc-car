#!usr/bin/python

# # #
# Reads lines from C joystick subprocess and writes to serial port
# # # 

import subprocess
from serial import Serial 

# Open joystick subprocess
process = subprocess.Popen("./joystick/js-read", stdout=subprocess.PIPE)

# Open serial port
ser = Serial("/dev/ttyAMA0",9600,timeout=2)

print "Transmitter ready."

while 1:
	# Send each line to serial port
	for line in iter(process.stdout.readline, ''):
		print "Sent " + line,
		ser.write(line,)
