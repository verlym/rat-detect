#ifndef main
#define main

// Pin Definitions
#define HCSR04_1_PIN_TRIG	11
#define HCSR04_1_PIN_ECHO	12
#define HCSR04_2_PIN_TRIG	5
#define HCSR04_2_PIN_ECHO	4
#define PIR_PIN_SIG	2



// Global variables and defines
// There are several different versions of the LCD I2C adapter, each might have a different address.
// Try the given addresses by Un/commenting the following rows until LCD works follow the serial monitor prints. 
// To find your LCD address go to: http://playground.arduino.cc/Main/I2cScanner and run example.
#define LCD_ADDRESS 0x27
//#define LCD_ADDRESS 0x27
// Define LCD characteristics
#define LCD_ROWS 16
#define LCD_COLUMNS 4
#define SCROLL_DELAY 150
#define BACKLIGHT 255

#endif