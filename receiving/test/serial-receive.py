#!/usr/bin/env python

# # #
# Receives data from the serial port
# # # by theoB610

from serial import Serial

# Defines port
ser = Serial("/dev/ttyAMA0",9600,timeout=2)

while True:
        if ser.inWaiting()!=0:
		print ser.read(7)
