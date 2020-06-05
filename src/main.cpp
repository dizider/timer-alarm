#include <Arduino.h>
#include "networking/WebServer.h"
#include "networking/WifiClient.h"
#include "display/display.h"
#include "display/ntpclock.h"
#include "led-ring/controller.h"

WebServer webServer;
static Display display;
static NTPClock ntpClock;
static LedRing ledRing;
static Looper looper;

TTime eventTime(22, 15, 15);

void setup() {

    Serial.begin(9600);
    Serial.println("...home information display...");

    FileSystem.begin();
    WifiClient::begin(WIFI_SSID, WIFI_PASSWORD);
    webServer.begin();

    ledRing.init();

    looper.add([] {
        if (ntpClock.remainingTime(eventTime).timeInSec() <= 0)
//            ledRing.fill(ledRing.magenta(), 255);
            ledRing.flash(100);
        else
            ledRing.forceClear();
    });
    looper.add([] {
        ntpClock.updateTime();
        display.clear();
        display.show(ntpClock.getTime(), 2, 0, 1);
        if (ntpClock.remainingTime(eventTime).timeInSec() > 0){
            display.show("Koupel za", 2, 10, 1);
            display.show(ntpClock.remainingTime(eventTime).getTime(), 2, 20);
        }
        else
            display.show("KOUPEL", 2, 20, 2);

        display.display();
    });
}

void loop() {
    looper.tick();
}
