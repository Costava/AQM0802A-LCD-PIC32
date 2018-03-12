// https://github.com/Costava/AQM0802A-LCD-PIC32

// The wiring is the minimum recommended connections of the PIC32MX2XX and:
// LED connected from VDD to RB13 through a 220 ohm resistor
// AQM0802A-RN-GBW display connected to SDA2 and SCL2

// Tested on:
// PIC32MX270F256B
// MPLAB X IDE v4.15
// XC32 v2.05

#include "xc.h"
#include "p32xxxx.h"
#include "AQM0802A_LCD.h"

#pragma config FWDTEN   = OFF    // Turn off watchdog timer
#pragma config FNOSC    = FRCPLL // Select 8 MHz internal Fast RC (FRC) oscillator with PLL
#pragma config FPLLIDIV = DIV_2  // Divide PLL input (FRC) to get into required range [4 MHz, 5 MHz]
#pragma config FPLLMUL  = MUL_24 // PLL Multiplier
#pragma config FPLLODIV = DIV_2  // PLL Output Divider
#pragma config FPBDIV   = DIV_1  // Peripheral Clock divisor
#pragma config JTAGEN   = OFF    // IMPORTANT. Otherwise bus collision may occur.

void led_on() {
    LATBbits.LATB13 = 0;
}

void led_off() {
    LATBbits.LATB13 = 1;
}

void delay() {
    int i;
    for (i = 0; i < 2000000; i += 1);
}

int main() {
    // Configure unused I/O to output low as recommended
    TRISA = 0;
    TRISB = 0;
    LATA = 0;
    LATB = 0;
    
    // Configure LED blinking pin
    ANSELBbits.ANSB13 = 0;// RB13 is digital
    TRISBbits.TRISB13 = 0;// RB13 is output
    
    led_on();
    
    lcd_init();

    while (1) {
        led_off();
        lcd_set_cursor(0, 1);
        // lcd_print_str("off");// Equivalent to three character prints
        lcd_print_char('o');
        lcd_print_char('f');
        lcd_print_char('f');
        delay();
        
        led_on();
        lcd_set_cursor(0, 1);
        lcd_print_str("on ");
        delay();
    }
    
    return 0;
}
