#include <stdio.h>
#include <pigpio.h>

// pwm.h ver 2.0
// Optimised for use with serial-receive.py
// Using received data from the serial port

struct pinvals {
	int pin;
	int range;
	int freq;
	int neutral;
	int pwm;
	int change; // Value to change pwm by
};
typedef struct pinvals Pinval;

// Initialize PWM and settings
int boot(Pinval mpin, Pinval spin) {

    // Set motor PWM settings
    gpioSetPWMrange(mpin.pin, mpin.range);
    gpioSetPWMfrequency(mpin.pin, mpin.freq);

    // Set servo PWM settings
    gpioSetPWMrange(spin.pin, spin.range);
    gpioSetPWMfrequency(spin.pin, spin.freq);

    // Start up the pulses
    gpioPWM(mpin.pin, mpin.neutral); // set to neutral
    gpioPWM(spin.pin, spin.neutral);
    return 0;
}

