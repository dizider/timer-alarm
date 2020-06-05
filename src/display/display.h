//#ifndef DISPLAY_DISPLAY_H
//#define DISPLAY_DISPLAY_H
#pragma once

#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>
#include "Constants.h"

class Display {
public:
    Display() : disp(Adafruit_PCD8544(CLK_PIN, DIN_PIN, DC_PIN, CE_PIN, RST_PIN)) {
        disp.begin();
        disp.setContrast(60);
        disp.clearDisplay();
        disp.display();
        // turn on backlight
        pinMode(BL_PIN, OUTPUT);
        digitalWrite(BL_PIN, HIGH);
    }

    /**
     * Print text to display. Start on position [xPos, yPos].
     * @param[in] text - text to display
     * @param[in] xPos - x coordinate of text
     * @param[in] yPos - y coordanete of text
     */
    void show(String text, int xPos, int yPos, int size);
    void show(String text, int xPos, int yPos);

    /**
     * Clear display.
     */
    void clear(void);

    void display();

private:
    Adafruit_PCD8544 disp;
};

//#endif