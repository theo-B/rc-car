#!/usr/include/env python

# # #
# Writes and reads from the serial port
# # # by theoB610

from serial import Serial
from time import sleep

def portwrite(port,output):
	port.write(output)

def portread (port):
	print "Output = " + str(port.read(6))
 

ser = Serial("/dev/ttyAMA0",9600,timeout=2)
while True:
	#portwrite(ser,"m2000\n")
        #sleep(1)
	portread(ser)
	
