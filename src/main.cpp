#include <Arduino.h>
#include "led.h"
#include <WiFi.h>

const char* ssid = "";
const char* password = "";

// Define the GPIO pin for the onboard LED
LED led;
int counter = 0;

void setup() {
  pinMode(LED_PIN, OUTPUT); // Initialize the LED pin as an output
  led.init();
  led.update(true);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);

  }
}

void loop() {
  // update LED object

  if (counter == 0) {
    led.update(true);

    counter = 1;
  } else {
    led.update(false);
    counter = 0;
  }
  Serial.println("Connected to the WiFi network");
  led.update();
  delay(1000);
}
