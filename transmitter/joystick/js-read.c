#include <stdio.h>
#include "js.h"

// js-read ver 3.0
// Read from joystick, optimised for sending over the serial port

int main() {
    Pinval mpin, spin;
    // Set up the motor variables
    mpin.range = 2000;
    mpin.freq = 500;
    mpin.neutral = 1500;

    // Set up the servo variables
    spin.range = 2000;
    spin.freq = 50;
    spin.neutral = 1500;

    int fd;
    struct js_event jse; // Creates joystick event structure

    // Open the device and print its information
    fd = open_joystick("/dev/input/js0");

    // Loop the event processing
    while (1) {
        while (read(fd, &jse, sizeof(jse)) > 0) {
            if ( jse.type == JS_EVENT_AXIS ) {
                 // Motor Control
                 if (jse.number == 1) {
                     mpin.change = jse.value / -65.534;
                     mpin.pwm = mpin.neutral + mpin.change;
                     printf("m%d\n",mpin.pwm);
                     fflush(stdout);
                 }
                 // Servo Control
                 if (jse.number == 3) {
                     spin.change = jse.value / 32.767;
                     spin.pwm = spin.neutral + spin.change;
                     printf("s%d\n", spin.pwm);
                     fflush(stdout);
                 }
		/*
		This returns the output as sXXXX or mXXXX
		where XXXX are relevant values for the pwm
		and s/m define whether it is servo or motor pulses
		*/
            }
        }
    }
    return 0;
}
