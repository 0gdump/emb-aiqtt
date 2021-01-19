#include "mqtt_snapshot.h"

static DynamicJsonDocument snapshotJson(512);

static struct {
  u32 timestamp;

  float gpsLongitude;
  float gpsLatitude;
  float gpsHeight;

  float co2;
  float lpg;
  float methane;
  float smoke;

  float humidity;
  float temperature;
} actualDataSnapshot;

static void takeInternalDataSnapshot() {
  actualDataSnapshot.timestamp = (u32)(millis() / 1000);

  // TODO
  actualDataSnapshot.gpsLongitude = 0.0;
  actualDataSnapshot.gpsLatitude  = 0.0;
  actualDataSnapshot.gpsHeight    = 0.0;

  actualDataSnapshot.co2     = readCO2();
  actualDataSnapshot.lpg     = readLPG();
  actualDataSnapshot.methane = readMethane();
  actualDataSnapshot.smoke   = readSmoke();

  actualDataSnapshot.humidity    = readHumidity();
  actualDataSnapshot.temperature = readTemperature();
}

void mqttPubDataSnapshot(void) {
  
  // FIXME
  takeInternalDataSnapshot();

  snapshotJson["timestamp"] = actualDataSnapshot.timestamp;

  snapshotJson["gps_longitude"] = actualDataSnapshot.gpsLongitude;
  snapshotJson["gps_latitude"]  = actualDataSnapshot.gpsLatitude;
  snapshotJson["gps_height"]    = actualDataSnapshot.gpsHeight;

  snapshotJson["co2"]     = actualDataSnapshot.co2;
  snapshotJson["lpg"]     = actualDataSnapshot.lpg;
  snapshotJson["methane"] = actualDataSnapshot.methane;
  snapshotJson["smoke"]   = actualDataSnapshot.smoke;

  snapshotJson["humidity"]    = actualDataSnapshot.humidity;
  snapshotJson["temperature"] = actualDataSnapshot.temperature;

  // FIXME
  serializeJson(snapshotJson, Serial);
  Serial.println();
}