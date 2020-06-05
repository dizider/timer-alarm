#include "ntpclock.h"

void NTPClock::updateTime(){
    if(millis() - lastSync < 1000)
        return;
    timeClient.update();
    lastSync = millis();
    dayOfWeek = daysOfTheWeek[timeClient.getDay()];
    hours = timeClient.getHours();
    minutes = timeClient.getMinutes();
    seconds = timeClient.getSeconds();
}

String NTPClock::getTime(){
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

TTime NTPClock::remainingTime(TTime time) {
    int remTime = (hours * 3600) + (minutes * 60) + seconds;
    remTime = time.timeInSec() - remTime;
    int h = remTime / 3600;
    int m = (remTime - (h * 3600)) / 60;
    int s = remTime - (h * 3600) - (m * 60);
    return TTime(h,m,s);
}
