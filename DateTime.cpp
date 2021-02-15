#include "DateTime.hpp"

namespace DateTime 
{
    const char* weekDayWords[] = {"DOM", "SEG", "TER", "QUA", "QUI", "SEX", "SAB"};

    WiFiUDP _udp;
    NTPClient* _ntp;

    void setup() 
    {
        _ntp = new NTPClient(_udp, "a.st1.ntp.br", -3 * 3600, 3600000);    
        setTime(_ntp->getEpochTime());

        _ntp->begin();
        _ntp->forceUpdate();       

        DeviceStatus::reportStatus(DeviceStatus::Level::INFO, DeviceStatus::Module::M_NTP, "OK");
    }

    void updateNTP()
    {
        _ntp->update();
    }

    String getFormattedTime()
    {
        return _ntp->getFormattedTime();
    }

    char* getHour(const char *format)
    {
        static char buffer[3] = {'\0'};
        snprintf(buffer, sizeof(buffer), format, _ntp->getHours());
        return buffer;
    }

    char* getMinute(const char *format)
    {
        static char buffer[3] = {'\0'};
        snprintf(buffer, sizeof(buffer), format, _ntp->getMinutes());
        return buffer;
    }

    char* getSecond(const char *format)
    {
        static char buffer[3] = {'\0'};
        snprintf(buffer, sizeof(buffer), format, _ntp->getSeconds());
        return buffer;
    }

    const char* getWeekdayName() {
        return weekDayWords[weekday(_ntp->getEpochTime())-1];
    }

    int getHour() {
        return _ntp->getHours();
    }

    int getMinute() {
        return _ntp->getMinutes();
    }

    int getSecond() {
        return _ntp->getSeconds();
    }

    int getWeekday() {
        return weekday(_ntp->getEpochTime())-1;
    }

    int getDay() {  
        return day(_ntp->getEpochTime());
    }

    int getMonth() {
        return month(_ntp->getEpochTime());
    }
}


