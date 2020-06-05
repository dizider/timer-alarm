#ifndef LED_RING_CONTROLLER_H
#define LED_RING_CONTROLLER_H

#include <Adafruit_NeoPixel.h>

#include "constants.h"

class LedRing {
public:
    LedRing() : strip(Adafruit_NeoPixel(12, DATA_PIN, NEO_GRB + NEO_KHZ800)) {}

    void init();

    void rainbow(uint8_t wait);

    void rainbowCycle(uint8_t wait);

    void brightness(uint8_t b);

    void setLedColor(uint8_t ledNumber, int color);

    uint32_t magenta() {
        return strip.Color(255, 0, 255);
    }

    uint32_t yellow() {
        return strip.Color(255, 255, 0);
    }

    uint32_t cyan() {
        return strip.Color(0, 255, 255);
    }

    void clear() {
        strip.clear();
    };

    void forceClear() {
        strip.clear();
        strip.show();
    }

    void flash(int duration);

    void fill(uint32_t color, uint8_t brightness);

private:
    uint32_t Wheel(byte WheelPos);

    Adafruit_NeoPixel strip;
};


#endif //LED_RING_CONTROLLER_H
