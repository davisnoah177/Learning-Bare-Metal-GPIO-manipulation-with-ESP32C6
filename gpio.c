#include "gpio.h"

/* GPIO Driver for ESP32C6-WROOM1 DevKit. Intended for self study of bare-metal programming */

#define GPIO_REG_BASE_ADDR          0x60091000
#define GPIO_REG_OFFSET            0x0554
#define GPIO_FUNCn_OUT_SEL_CFG(pin) (*(volatile uint32_t *)(GPIO_REG_BASE_ADDR + GPIO_REG_OFFSET + (pin * 4)))
#define GPIO_OUT_SEL_MASK           (0xFF << 0)   /* Bits 7:0 */
#define GPIO_OUT_INV_SEL            (1 << 8)      /* Bit 8 */
#define GPIO_OEN_SEL                (1 << 9)      /* Bit 9 */
#define GPIO_OEN_INV_SEL            (1 << 10)     /* Bit 10 */

/* IO MUX Configuration */
#define IO_MUX_BASE_ADDR               0x60090000
#define IO_MUX_OFFSET                     0x0004
#define IO_MUX_GPIOn_REG(pin) (*(volatile uint32_t *)(IO_MUX_BASE_ADDR + IO_MUX_OFFSET + (pin * 4)))
#define IO_MUX_MCU_SEL_MASK             (0b111 << 12)   /* Bits 12:14 */

void gpio_config_output(int pin) {
    // Initialize GPIO pin as output
    GPIO_FUNCn_OUT_SEL_CFG(pin) = (GPIO_FUNCn_OUT_SEL_CFG(pin) & ~GPIO_OUT_SEL_MASK) | 0x80; // Set output function to GPIO
    GPIO_FUNCn_OUT_SEL_CFG(pin) = (GPIO_FUNCn_OUT_SEL_CFG(pin) | GPIO_OEN_SEL); // Set output enable

    IO_MUX_GPIOn_REG(pin) = (IO_MUX_GPIOn_REG(pin) & ~IO_MUX_MCU_SEL_MASK) | (0x1 << 12); // Set IO MUX to GPIO function

    GPIO_ENABLE_W1TS_REG = (1 << pin); // Enable GPIO output
}

void gpio_set_pin(int pin) {
    // Set the specified GPIO pin HIGH
    GPIO_OUT_W1TS_REG = (1 << pin);
}

void gpio_clear_pin(int pin) {
    // Clear the specified GPIO pin LOW
    GPIO_OUT_W1TC_REG = (1 << pin);
}

void gpio_read_pin(int pin, int *value) {
    // Read the specified GPIO pin value
    *value = (GPIO_IN_REG >> pin) & 0x1;
}