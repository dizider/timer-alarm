#include "controller.h"

uint32_t LedRing::Wheel(byte WheelPos) {
    WheelPos = 255 - WheelPos;
    if(WheelPos < 85) {
        return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
    }
    if(WheelPos < 170) {
        WheelPos -= 85;
        return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
    }
    WheelPos -= 170;
    return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}

void LedRing::rainbow(uint8_t wait) {
    uint16_t i, j;

    for (j = 0; j < 256; j++) {
        for (i = 0; i < strip.numPixels(); i++) {
            strip.setPixelColor(i, Wheel((i + j) & 255));
        }
        strip.show();
        delay(wait);
    }
}

void LedRing::rainbowCycle(uint8_t wait) {
    uint16_t i, j;

    for(j=0; j<256*5; j++) { // 5 cycles of all colors on wheel
        for(i=0; i< strip.numPixels(); i++) {
            strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
        }
        strip.show();
        delay(wait);
    }
}

void LedRing::init() {
    strip.begin();
    strip.show();
}

void LedRing::brightness(uint8_t b) {
    strip.setBrightness(b);
    strip.show();
}

void LedRing::setLedColor(uint8_t ledNumber, int color) {
    strip.setPixelColor(ledNumber, color);
    strip.show();
}

void LedRing::flash(int duration) {
    strip.clear();
    uint32_t  white = strip.Color(  255,   255,   255, 255);
    strip.fill(white, 0, 12);
    strip.show();
    delay(duration);
    strip.clear();
    strip.show();
}

void LedRing::fill(uint32_t color, uint8_t brightness = 255) {
    strip.clear();
    strip.fill(color, 0, 12);
    strip.setBrightness(brightness);
    strip.show();
}
