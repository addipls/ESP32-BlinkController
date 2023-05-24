#ifndef LED_H
#define LED_H

#include <Arduino.h>

// Define the GPIO pin for the onboard LED
extern const int LED_PIN = 2;

class LED {
  public:
    void init();
    void update();
    void update(bool state);
    void set(bool state);
  private:
    bool _state;
};

#endif
