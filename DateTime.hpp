#pragma once

#include <Arduino.h>

#include <NTPClient.h>
#include <TimeLib.h>
#include <WiFi.h>
#include <DeviceStatus.hpp>


namespace DateTime
{   
    void setup();
    void updateNTP();

    String getFormattedTime();
    char* getHour(const char *format);
    char* getMinute(const char *format);
    char* getSecond(const char *format);
    const char* getWeekdayName();
    int getHour();
    int getMinute();
    int getSecond();
    int getWeekday();
    int getDay();
    int getMonth();
}
