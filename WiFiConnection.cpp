#include "WiFiConnection.hpp"

namespace WiFiConnection
{
    const char* ssid = "NET_2GB7BCBA";
    const char* password =  "4AB7BCBA";

    void connect() 
    {
        delay(1000);
        WiFi.mode(WIFI_MODE_STA);
        WiFi.disconnect();

        WiFi.begin(ssid, password);
        
        while (WiFi.status() != WL_CONNECTED)
        {
            delay(500);
            //Display::print(".");
        }
        
        DeviceStatus::reportStatus(DeviceStatus::Level::INFO, DeviceStatus::Module::M_WIFI, "Connected");
                       
        // Serial.print("Connected to ");
        // Serial.println(ssid);
        // Serial.print("IP address: ");
        // Serial.println(WiFi.localIP());
    }

    boolean isConnected() 
    {
        return WiFi.status() == WL_CONNECTED;
    }

}

