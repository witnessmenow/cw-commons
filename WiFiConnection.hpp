#pragma once

#include <Arduino.h>
#include <DeviceStatus.hpp>
#include <WiFi.h>

namespace WiFiConnection
{   
    void connect();
    boolean isConnected();
}

