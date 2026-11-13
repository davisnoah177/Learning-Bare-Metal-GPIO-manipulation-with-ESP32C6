CC = /home/noahdavis/Documents/toolchains/riscv32-esp-elf-16.1.0_20260609-x86_64-linux-gnu/riscv32-esp-elf/bin/riscv32-esp-elf-gcc
CFLAGS = -march=rv32imac -mabi=ilp32 -Os -Wall -Werror -nostdlib

target: main.o gpio.o
	echo "Linking object files"
	$(CC) $(CFLAGS) -o target main.o gpio.o

main.o : main.c 
	echo "Compiling main.c"
	$(CC) $(CFLAGS) -c main.c

gpio.o : gpio.c gpio.h
	echo "Compiling gpio.c"
	$(CC) $(CFLAGS) -c gpio.c

clean:
	echo "Cleaning up"
	rm -f *.o target

