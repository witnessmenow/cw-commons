
#include "DateTime.h"

//const char* weekDayWords[] = {"DOM", "SEG", "TER", "QUA", "QUI", "SEX", "SAB"};
const char *weekDayWords[] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};

DateTime::DateTime()
{
}

void DateTime::begin(const char *timeZone)
{
  myTZ.setLocation(timeZone);
  waitForSync();
}

void DateTime::update()
{
}

String DateTime::getFormattedTime()
{
  return myTZ.dateTime();
}

char *DateTime::getHour(const char *format)
{
  static char buffer[3] = {'\0'};
  snprintf(buffer, sizeof(buffer), format, myTZ.dateTime("H"));
  return buffer;
}

char *DateTime::getMinute(const char *format)
{
  static char buffer[3] = {'\0'};
  //Serial.println(myTZ.dateTime("i").c_str()); // Is correct
  //snprintf(buffer, sizeof(buffer), format, myTZ.dateTime("i").c_str());
  //Serial.println(buffer); //Always returns 10!?
  strncpy(buffer, myTZ.dateTime("i").c_str(), sizeof(buffer));
  return buffer;
}

char *DateTime::getSecond(const char *format)
{
  static char buffer[3] = {'\0'};
  snprintf(buffer, sizeof(buffer), format, myTZ.dateTime("s"));
  return buffer;
}

const char *DateTime::getWeekdayName()
{
  return weekDayWords[myTZ.dateTime("N").toInt() - 1];
}

int DateTime::getHour()
{
  return myTZ.dateTime("H").toInt();
}

int DateTime::getMinute()
{
  return myTZ.dateTime("i").toInt();
}

int DateTime::getSecond()
{
  return myTZ.dateTime("s").toInt();
}

int DateTime::getWeekday()
{
  return myTZ.dateTime("N").toInt() - 1;
}

int DateTime::getDay()
{
  return myTZ.dateTime("j").toInt();
}

int DateTime::getMonth()
{
  return myTZ.dateTime("n").toInt();
}