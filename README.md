# Six button Sega Mega Drive controller PCB

This is a KiCad project for a six button Sega Mega Drive / Genesis controller board and ATTiny404 micro controller code to implement a replacement for the Sega controller's custom chip. It should also work with the ZX Spectrum Next.

**Note: the `main` HEAD is not necessarily tested! Tested revisions of the board+firmware will be tagged**

See a tested build [here.](https://oshpark.com/shared_projects/aK2wBkfg)

v1.0 uses a 14-pin dual row header used for the buttons because I was unaware of the brook 20 pin header at the time. I might add that pinout to future boards.

## How do I program the controller?

The ATtiny404 uses UPDI (Unified Program and Debug Interface) for programming, not ISP like older AVR MCUs. 

UPDI has been supported by **avrdude** since v7. Check that your programmer supports UPDI and your programmer is supported by **avrdude**.

Under Linux, you would use a command like this to program the controller:

```
avrdude -c jtag2updi -p t404 -P /dev/ttyUSB0 -U flash:w:main.hex:i
```

The -c parameter sets the programmer to use, see the [avrdude documention](https://avrdudes.github.io/avrdude/) for supported programmers.

## How do I wire the cable?

The cable is connected to the J2 header using this pinout:

![Mega Drive controller cable pinout](Mega-Drive-DB9-pinout.jpg)

Pin 1 is marked on the controller PCB with a square pad and a number 1 printed next to it on the silkscreen.
