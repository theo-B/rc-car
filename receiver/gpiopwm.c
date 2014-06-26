#include <stdio.h>
#include <pigpio.h>
#include "pwm-receive.h"

// gpiopwm ver 2.0
// For use with serial-receive-to-pwm.py
// Sets GPIO PWM pulses received from serial port

int main() {
    // Create structures for GPIO pins
    Pinval mpin, spin;
    // Set up the motor pin
    mpin.pin = 4;
    mpin.range = 2000;
    mpin.freq = 500;
    mpin.neutral = 1500;

    // Set up the servo pin
    spin.pin = 17;
    spin.range = 2500;
    spin.freq = 50;
    spin.neutral = 1500;

    gpioInitialise();
    boot(mpin, spin);// Sets up gpio pins for PWM

    char input[16]="m1500\n";
    char *numbers="2000\n";

    printf("Ready to run\n");

    char* fd = fgets(input,sizeof(input),stdin); // Read from stdin
    while (fd != NULL) {
        // Remove index char from start of input
        printf("Received %s\n",input);
        char first = input[0];
        numbers = input+1;
        // Process input
        if (first=='m') {
            mpin.pwm = atoi(numbers);
            printf("Motor set to %s\n",numbers);
            gpioPWM(mpin.pin,mpin.pwm);
        }
        if (first=='s') {
            spin.pwm = atoi(numbers);
            printf("Servo set to %s\n",numbers);
            gpioServo(spin.pin,spin.pwm);
        }
    // Reread from stdin
    fd = fgets(input,sizeof(input),stdin);
    }
    return 0;
}
