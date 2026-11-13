#include "gpio.h"

int main() {

    int pin = 7;

    // Configure GPIO pin 7 as output
    gpio_config_output(pin);


    // Set GPIO pin 7 HIGH
    gpio_set_pin(pin);

    // Read the value of GPIO pin 7
    int value;
    gpio_read_pin(pin, &value);
    returns 0;
}