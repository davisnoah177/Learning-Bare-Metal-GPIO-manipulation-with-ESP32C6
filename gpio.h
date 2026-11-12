#ifndef GPIO_H
#define GPIO_H

#define GPIO_REG_WRITE(reg, value) (*(volatile uint32_t *)(reg) = (value))

void gpio_config_output(int pin);
void gpio_config_input(int pin);
void gpio_set_pin(int pin);
void gpio_clear_pin(int pin);
void gpio_read_pin(int pin, int *value);

#endif /* GPIO_H */