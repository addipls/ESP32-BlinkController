/*
 * LED FSM implemented as a class with init, update and set methods
*/

#include <Arduino.h>

#define CONNECTED_BLINK_PATTERN "--.-"
#define WAITING_FOR_CONNECTION_BLINK_PATTERN "-.-."
#define CONNECTING_BLINK_PATTERN "-.-"
// Define the GPIO pin for the onboard LED
const int LED_PIN = 2;

class LED {
  public:
    void init();
    void update();
    void update(bool state);
    void set(bool state);
  private:
    bool _state;
};

void LED::init() {
  pinMode(LED_PIN, OUTPUT); // Initialize the LED pin as an output
  _state = false;
}

void LED::update() {
  switch (_state) {
    case true:
      digitalWrite(LED_PIN, HIGH);
      break;
    case false:
      digitalWrite(LED_PIN, LOW);
      break;
  }
}

void LED::update(bool state) {
  _state = state;
  update();
}

void LED::set(bool state) {
  _state = state;
}