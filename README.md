rc-car
======

Code for a Raspberry Pi Remote control car project, requiring two Raspberry Pis.

Transmitter:
Reads from a joystick (L stick Y-axis acceleration, R stick X-axis steering) and sends data over serial port.

Receiver:
Reads from serial port and writes PWM pulses to GPIO using pigpio module to control servo and ESC.
