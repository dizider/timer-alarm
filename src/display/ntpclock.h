//#ifndef DISPLAY_LOOPER_H
//#define DISPLAY_LOOPER_H

#pragma once

#include <Arduino.h>
#include <WiFiUdp.h>
#include <NTPClient.h>

const char daysOfTheWeek[7][12] = {"Nedele", "Pondeli", "Utery", "Streda", "Ctvrtek", "Patek", "Sobota"};
const long utcOffsetInSeconds = 2 * 3600;


static WiFiUDP ntpUDP;

struct TTime {

    TTime(int h, int m, int s) : hours(h), minutes(m), seconds(s) {}
    int hours = INT_MAX;
    int minutes = INT_MAX;
    int seconds = INT_MAX;

    String getTime() {
        String time;
        (hours < 10) ? time += "0" : "";
        time += hours;
        time += ":";
        (minutes < 10) ? time += "0" : "";
        time += minutes;
        time += ":";
        (seconds < 10) ? time += "0" : "";
        time += seconds;
        return time;
    }

    int timeInSec(){
        return (hours * 3600) + (minutes * 60) + seconds;
    }
};

class NTPClock {
public:
    NTPClock() : timeClient(NTPClient(ntpUDP, "pool.ntp.org", utcOffsetInSeconds)) {
        timeClient.begin();
    }

    void updateTime();

    String getTime();

    TTime remainingTime(TTime time);

private:
    NTPClient timeClient;
    String dayOfWeek = "N/A";
    int hours = INT_MAX;
    int minutes = INT_MAX;
    int seconds = INT_MAX;
    unsigned long lastSync;
};

//#endif