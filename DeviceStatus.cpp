#include "DeviceStatus.hpp"

namespace DeviceStatus 
{

    const uint8_t PIN_LED_STATUS = 2;
    bool ledState = false;
    unsigned long lastMillis = 0;
   
    volatile State gState = State::INITIALIZING;
    
    void blink(int interval);


    void setState(State state) 
    {
        gState = state;
    }

    State getCurrentState() 
    {
        return gState;
    }
    
    void reportStatus(Level level, Module module, const char* message)
    {
        if (level != Level::ERROR) {
            
            if (module == Module::M_WIFI) {
                
            } else if (module == Module::M_DISPLAY) {
                Display::print("[LEDM] ");    
            } else if (module == Module::M_NTP) {
                Display::print("[NTP] ");    
            } else if (module == Module::M_OTA) {
                Display::print("[OTA] ");    
            }

            Display::println(message);
        }
    }

    
    void setup() 
    {
        pinMode(PIN_LED_STATUS, OUTPUT);
    }
    
    
    void loop() 
    {
        if (gState == State::INITIALIZING) {
            blink(100);
        } else if (gState == State::RUNNING) {
            blink(1000);
        }        
    }

    void blink(int interval) 
    {
        if (millis() - lastMillis > interval) {
            digitalWrite(PIN_LED_STATUS, ledState ? HIGH : LOW);
            ledState = !ledState;  

            lastMillis = millis();
        }  
    }
}