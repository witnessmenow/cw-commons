#ifndef DateTimeCf_h
#define DateTimeCf_h

#include <Arduino.h>

#include <ezTime.h>
#include <WiFi.h>

class DateTime
{
private:
  Timezone myTZ;

public:
  DateTime();
  void begin(const char *timeZone);
  void update();
  String getFormattedTime();

  char *getHour(const char *format);
  char *getMinute(const char *format);
  char *getSecond(const char *format);
  const char *getWeekdayName();
  int getHour();
  int getMinute();
  int getSecond();
  int getWeekday();
  int getDay();
  int getMonth();
};
#endif