#include "display.h"

void Display::clear(void) {
    disp.clearDisplay();
}

void Display::show(String text, int xPos, int yPos, int size) {
    disp.setTextSize(size);
    disp.setCursor(xPos, yPos);
    disp.print(text);
    disp.setTextSize(1);
}

void Display::display() {
    disp.display();
}

void Display::show(String text, int xPos, int yPos) {
    disp.setCursor(xPos, yPos);
    disp.print(text);
}
