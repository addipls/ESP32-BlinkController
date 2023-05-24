#include <Arduino.h>
#include "led.h"
#include <WiFi.h>

// Define the GPIO pin for the onboard LED
LED led;
int counter = 0;

void setup() {
  pinMode(LED_PIN, OUTPUT); // Initialize the LED pin as an output
  led.init();
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

  led.update();
  delay(1000);
}
