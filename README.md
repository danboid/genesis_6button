# Six button Sega Mega Drive controller board

This repository contains a KiCad project for a six button Sega Mega Drive / Genesis controller board as well as ATTiny404 micro controller code to implement a replacement for the 6 button Sega Mega Drive controller's custom chip. This board should also work with the ZX Spectrum Next.

**Note: the `main` HEAD is not necessarily tested! Tested revisions of the board+firmware will be tagged**

You can order the original, tested version of this board pre-assembled [here.](https://oshpark.com/shared_projects/aK2wBkfg)

The original version of this board used a 14-pin dual row header for the buttons because I was unaware of the brook 20 pin header at the time. I might add that pinout to future boards.

## How do I program the controller?

The ATtiny404 uses UPDI (Unified Program and Debug Interface) for programming, not ISP like older AVR MCUs. 

UPDI has been supported by **avrdude** since v7. Check that your programmer supports UPDI and your programmer is supported by **avrdude**.

Under Linux, you would use a command like this to program the controller:

```
avrdude -c usbtiny -p t404 -U flash:w:main.hex:i
```

The -c parameter sets the programmer to use, see the [avrdude documention](https://avrdudes.github.io/avrdude/) for supported programmers.

## How do I wire the cable?

The cable is connected to the J2 header using this pinout:

![Mega Drive controller cable pinout](Mega-Drive-DB9-pinout.jpg)

Pin 1 on J2 and all of the chips is marked on the PCB silkscreen with a small white dot to the side of pin 1.
