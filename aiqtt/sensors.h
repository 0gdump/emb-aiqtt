#include <Adafruit_ADS1015.h>
#include <TroykaMQ.h>
#include <DHT.h>

#ifndef H_SENSORS
#define H_SENSORS

void initializeSensors(void);

float readCO2(void);
float readLPG(void);
float readMethane(void);
float readSmoke(void);

float readHumidity(void);
float readTemperature(void);

#endif