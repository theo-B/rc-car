#include <stdio.h>
#include <pigpio.h>

// pwm.h ver 2.1
// Optimised for use with serial-receive-to-pwm.py
// Using received data from the serial port

// Structure for pin values
struct pinvals {
        int pin;     // Which GPIO to use
        int range;   // PWM range of pin
        int freq;    // PWM frequency
        int neutral; // Neutral position
        int pwm;     // Current pwm setting
        int change;  // Value to change pwm by
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

