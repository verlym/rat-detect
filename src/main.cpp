#include <Arduino.h>

#include "main.h"
#include <NewPing.h>
#include "../lib/PIR/src/PIR.h"
#include <LiquidCrystal_I2C.h>

// object initialization
NewPing hcsr04_1(HCSR04_1_PIN_TRIG, HCSR04_1_PIN_ECHO);
NewPing hcsr04_2(HCSR04_2_PIN_TRIG, HCSR04_2_PIN_ECHO);
LiquidCrystal_I2C lcd(LCD_ADDRESS, LCD_ROWS, LCD_COLUMNS);
;
PIR pir(PIR_PIN_SIG);

void setup()
{
  // Setup Serial which is useful for debugging
  // Use the Serial Monitor to view printed messages
  Serial.begin(9600);
  while (!Serial)
    ; // wait for serial port to connect. Needed for native USB
  Serial.println("start");

  // initialize the lcd
  lcd.init();
  lcd.backlight();
}

void loop()
{
  // Infrared PIR Motion Sensor Module - Test Code
  bool pirVal = pir.read();
  Serial.print(F("Val: "));
  Serial.println(pirVal);

  // Ultrasonic Sensor - HC-SR04 #1 - Test Code
  // Read distance measurment from UltraSonic sensor
  int hcsr04_1Dist = hcsr04_1.ping_cm();
  Serial.print(F("Distance: "));
  Serial.print(hcsr04_1Dist);
  Serial.println(F("[cm]"));

  lcd.clear();
  printTeam();
  delay(1500);
}

void printTeam()
{
  lcd.setCursor(5, 0);     // move cursor to   (0, 0)
  lcd.print("EIC");        // print message at (0, 0)
  lcd.setCursor(2, 1);     // move cursor to   (2, 1)
  lcd.print("Technology"); // print message at (2, 1)
}