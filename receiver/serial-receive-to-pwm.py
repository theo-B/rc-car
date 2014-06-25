#!/usr/bin/env python

# # #
# Receives data from the serial port and sends to a C program
# # # by theo-B

from serial import Serial
import subprocess

# Opens C program, with the input as a pipe
process = subprocess.Popen("./gpiopwm", stdin=subprocess.PIPE)

# Opens port
ser = Serial("/dev/ttyAMA0",9600,timeout=2)

while True:
        if ser.inWaiting()!=0:
		# Read from port, write to stdin of subprocess
                process.stdin.write(ser.read(6))
