#include "HX711.h"
#include <WiFi.h>
#include <WebServer.h>                                // Make sure tools -> board is set to ESP32, otherwise you will get a "WebServer.h: No such file or directory" error


// HX711 circuit wiring
const int LOADCELL_DOUT_PIN = 12;
const int LOADCELL_SCK_PIN = 13;

HX711 scale;

void setup() {
  Serial.begin(57600);
  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
  scale.set_gain(128);
}

void loop() {

  if (scale.is_ready()) {
    long reading = scale.read();
    Serial.print("HX711 reading: ");
    Serial.println(abs(reading-12500)/20);
  } else {
    Serial.println("HX711 not found.");
  }

  delay(1000);
  
}
