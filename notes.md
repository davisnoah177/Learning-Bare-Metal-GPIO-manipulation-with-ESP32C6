# Purpose

This file is for documenting learning outcomes and design decisions made during this project. Informtation documented here is purely my own understanding and may be flawed, incomplete or entirely incorrect. 

TLDR: this is a notebook, not a technical document.

## IO MUX and GPIO MUX 

The IO mux is used to directly connect GPIO signals to a pin.  GPIO MUX can be used to assign multiple peripheral to a single GPIO pin, or to reroute signals to different GPIO pins than their default. Use of the GPIO mux allows for flexibilty but adds latency so is not ideal for faster switching signals like SPI, UART, I2C or JTAG.


## Compiler

* Need to install the riscv32-esp-elf-gcc compiler to compile code for ESP32. 

* for RISC-V - stdlib includes may cause linking step to throw warnings. **-nostdlib** flag prevents the compiler from trying to link stdlib functions.

## Makefile

CC is a variable used to store the file path of the compiler. gcc and clang typically are stored globally to file path does not need to be explicitly specified. Specific compilers like the one listed above need to be installed somewhere and referenced explicitly.

## How to define registers

* Need to figure out more about how to define registers so the preprocessor can recognise them.

Register offsets are defined in the technical reference manual. Need to take the base address of the GPIO register and add the corresponding offset. 
Then need to define a pointer that references this address for each of the required registers.