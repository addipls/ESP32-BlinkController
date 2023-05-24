#include <Arduino.h>

class Delay {
    public:
        void init();
        void setDelay(int delay);
        bool isDelayOver();
        void update();
    private:
        int _delay;
        int _startTime;
};

void Delay::init() {
    _delay = 0;
    _startTime = 0;
}

void Delay::setDelay(int delay) {
    _delay = delay;
    _startTime = millis();
}

bool Delay::isDelayOver() {
    if (_startTime + _delay < millis()) {
        return false;
    }


    _startTime = millis();
    return true;
}




