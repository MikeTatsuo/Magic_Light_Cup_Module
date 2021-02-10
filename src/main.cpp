#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);

#define SENSOR_A 2
#define SENSOR_B 8
#define LED_A 3
#define LED_B 9

int switchStateA = 0;
int switchStateB = 0;

int brightness = 0;

void setup() {
  pinMode(SENSOR_A, INPUT);
  pinMode(SENSOR_B, INPUT);
  pinMode(LED_A, OUTPUT);
  pinMode(LED_B, OUTPUT);

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("**** Magic  Cup ****");

  lcd.setCursor(0, 2);
  lcd.print("Filling: None");
}

void loop() {
  switchStateA = digitalRead(SENSOR_A);
  if (switchStateA && brightness != 255) {
    brightness++;
    lcd.setCursor(9, 2);
    lcd.print("Right");
  }

  switchStateB = digitalRead(SENSOR_B);

  if (switchStateB && brightness != 0) {
    brightness--;
    lcd.setCursor(9, 2);
    lcd.print("Left ");
  }

  analogWrite(LED_A, brightness);
  analogWrite(LED_B, 255 - brightness);
  delay(5);
}