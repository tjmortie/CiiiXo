#ifndef MQTTSINK_H
#define MQTTSINK_H

#include <Arduino.h>
#include "Sink.h"
#include <PubSubClient.h>
#include <WiFi.h>

class MqttSink: public Sink {
    public:
        void setup();
        void loop();
        void sendMessage(String);
        void sendInputsData(uint8_t, uint8_t);
        void setServer(char*);
    protected:
        char* mqtt_server = (char*) "192.168.1.142";      
        WiFiClient espClient;
        PubSubClient clientMQTT = PubSubClient(espClient);

        void reconnect();
        static void callback(char* topic, byte* payload, unsigned int length); 
};

#endif