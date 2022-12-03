/*
    Thermometer using Arduino, LM35 sensor and 16x2 LCD display.

    This code prints real-time temperature in celsius with
    2 seconds delay to the LCD display using Arduino and LM35 sensor.

*/


#include <LiquidCrystal.h>

const int LM35 = A12;
float temperature = 0;
float tension = 0;
float analog_value_lm35 = 0;


// initialize the LiquidCrystal library with the numbers of the interface pins
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

void setup() {
    Serial.begin(9600);
    lcd.begin(16, 2);

    lcd.setCursor(0, 0);
    lcd.print("Temperature:");
}

void loop() {
    // recive analog read from LM35 sensor (values between 0 and 1023)
    analog_value_lm35 = float(analogRead(LM35));

    // convert this value to electrical voltage
    tension = (analog_value_lm35 * 5) / 1023;
    temperature = tension / 0.010;
    
    lcd.setCursor(0, 1);
    lcd.print(temperature);

    // 2000 milliseconds delay
    delay(2000);
}
