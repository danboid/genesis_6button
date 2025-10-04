#!/bin/bash
# You need avr-gcc v8 or later and avr-libc to build for the attiny404
 
avr-gcc -mmcu=attiny404 -O3 -Wall -Wextra main.c -o main.elf
avr-objcopy -O ihex -R .eeprom main.elf main.hex
