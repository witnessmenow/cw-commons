#include <OTAUpdate.hpp>

namespace OTAUpdate
{   
    void setup()
    {
        ArduinoOTA.onStart([]() {
            String type;

            if (ArduinoOTA.getCommand() == U_FLASH) {
                type = "sketch";
            } else { // U_FS
                type = "filesystem";
            }

            // NOTE: if updating FS this would be the place to unmount FS using FS.end()
            Serial.println("Start updating " + type);
            
            DeviceStatus::setState(DeviceStatus::State::UPDATING);
        });

        ArduinoOTA.onEnd([]() {
            Serial.println("\nEnd");
            Display::println("\nEnd");
            delay(2000);
            ESP.restart();
        });

        ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) {

            Serial.printf("Progress: %d", progress);

            Display::fillRect(0, 0, Display::WIDTH, Display::HEIGHT, 0x0000);
            Display::setFont(&small4pt7b);

            Display::print("Progress: ");
            Display::print(String(progress / (total / 100)));
            Display::println("%");
        });

        ArduinoOTA.onError([](ota_error_t error) {

            char* e;            
            if (error == OTA_AUTH_ERROR) {
                e = "Auth Failed";
            } else if (error == OTA_BEGIN_ERROR) {
                e = "Begin Failed";
            } else if (error == OTA_CONNECT_ERROR) {
                e = "Connect Failed";
            } else if (error == OTA_RECEIVE_ERROR) {
                e = "Receive Failed";
            } else if (error == OTA_END_ERROR) {
                e = "End Failed";
            }

            Serial.printf("Error[%u]: ", error);
            Serial.println(e);
            
            Display::print("Error: ");
            Display::println(e); 
            Display::print("Please restart");

            DeviceStatus::setState(DeviceStatus::State::FAILURE);
        });


        ArduinoOTA.begin();
        
        DeviceStatus::reportStatus(DeviceStatus::Level::INFO, DeviceStatus::Module::M_OTA, "OK");
    }

    void loop()
    {
        ArduinoOTA.handle();
    }

};

