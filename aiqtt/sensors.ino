#include "sensors.h"

DHT dht(D5, DHT11);

Adafruit_ADS1015 ads;
MQ2   mq2  (ads, 2);
MQ4   mq4  (ads, 0);
MQ5   mq5  (ads, 1);
MQ135 mq135(ads, 3);

void initializeSensors(void) {
  dht.begin();

  ads.begin();
  mq4.calibrate();
  mq2.calibrate();
  mq5.calibrate();
  mq135.calibrate();
}

float readCO2(void) {
  return mq135.readCO2();
}

float readLPG(void) {
  float mq2lpg = mq2.readLPG();
  float mq5lpg = mq5.readLPG();

  return (mq2lpg + mq5lpg) / 2;
}

float readMethane(void) {
  float mq2methane = mq2.readMethane();
  float mq4methane = mq2.readMethane();
  float mq5methane = mq2.readMethane();

  return (mq2methane + mq4methane + mq5methane) / 3;
}

float readSmoke(void) {
  return mq2.readSmoke();
}

float readHumidity(void) {
  return dht.readHumidity();
}

float readTemperature(void) {
  return dht.readTemperature();
}
