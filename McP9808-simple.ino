#include <Wire.h>
#include "Adafruit_MCP9808.h"
int led = 4;
Adafruit_MCP9808 tempsensor = Adafruit_MCP9808();

void setup() {
  Serial.begin(9600);
  pinMode(4, OUTPUT);

  if (!tempsensor.begin()) {
    Serial.println("Couldn't find MCP9808!");
    while (1);
  }
}


void loop() {
tempsensor.wake();

//float tempC = tempsensor.readTempC();
//float tempF = tempC * 9.0 / 5.0 + 32;
//Serial.print("Temp: "); Serial.print(tempC); Serial.print("*C\t");
//Serial.print(tempF); Serial.println("*F");

  float tempF = tempsensor.readTempC();
  float tempC = (tempF - 32) * (5/9);
  Serial.print("Temp: "); Serial.print(tempC); Serial.print("*C\t");
  Serial.print(tempF); Serial.println("*F");




  

  if (tempC >  26.25) {
    digitalWrite(led, HIGH);
  }
  else {
    digitalWrite (led, LOW);
  }



  //  Serial.println("Shutdown MCP9808.... ");
  //  tempsensor.shutdown();

  delay(1000);
}
