# AQM0802A-LCD-PIC32

PIC32 library for the AQM0802A-RN-GBW 8x2 character LCD display. The LCD uses I2C.

[AQM0802A-RN-GBW datasheet](http://akizukidenshi.com/download/ds/xiamen/AQM0802.pdf)

`main.c` is a demo using the library. It toggles an LED and displays 'on' or 'off' accordingly on the second line of the display. The wiring is the minimum recommended connections of the PIC32MX2XX and:
- LED connected from VDD to RB13 through a 220 ohm resistor
- AQM0802A-RN-GBW display connected to SDA2 and SCL2

Tested on:
- PIC32MX270F256B
- MPLAB X IDE v4.15
- XC32 v2.05

Feel free to create an issue and ask a question.
