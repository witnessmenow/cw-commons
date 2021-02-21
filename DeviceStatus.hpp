#pragma once

#include <Arduino.h>
#include <Display.hpp>

namespace DeviceStatus 
{
    enum class State : uint8_t {	
        INITIALIZING,
        UPDATING,
        RUNNING,
        FAILURE
    };

    enum class Level : uint8_t {	
        INFO,
        WARN,
        ERROR
    };

    enum class Module : uint8_t {	
        M_DISPLAY,
        M_WIFI,
        M_NTP,
        M_OTA,
        M_CLOCKFACE
    };

    void setup();
    void loop();
    State getCurrentState();
    void setState(State state);
    void reportStatus(Level level, Module module, const char* message);
    
};