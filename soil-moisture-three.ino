#include <Adafruit_LiquidCrystal.h>
Adafruit_LiquidCrystal lcd(0);
int sensorPin = A0;
int sensorValue=0;
int limit = 400;
int maxHumidity = 600;
int outputPin = 3;
void setup() {
  Serial.begin(9600);
  pinMode(outputPin, OUTPUT); //output pin for relay board
  Serial.begin(9600);
  lcd.begin(16,2);
}

void loop() {
  sensorValue = analogRead(sensorPin);
  Serial.println("Analog Value : ");
  Serial.println(sensorValue);

  if (sensorValue < limit) {
    digitalWrite(outputPin, LOW);
    lcd.setCursor(0, 0);
    lcd.print("Pump : OFF");

  }
  else if (sensorValue >= maxHumidity) {
    digitalWrite(outputPin, HIGH);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Pump : ON");
   
  }
  lcd.setCursor(0, 1);
  lcd.print("Mois : ");
  long val =sensorValue;
  Serial.println((val * 100));
  float mois = (val * 100) / 1023;
  Serial.print("MOIS : ");
  Serial.println(mois);
  lcd.print(mois);
  lcd.print(" %");

  delay(1000);
}