#pragma once

#include <Arduino.h>
#include <DeviceStatus.hpp>
#include <WiFi.h>

namespace WiFiConnection
{   
    void setup();
    void connect();
    boolean isConnected();
}

