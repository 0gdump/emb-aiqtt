#include <ArduinoJson.h>

#include "types.h"
#include "sensors.h"

#include "mqtt_about.h"
#include "mqtt_snapshot.h"

void setup(void) {
  Serial.begin(9600);

  initializeSensors();

  mqttAboutInit();
  mqttPubAbout();

  mqttPubDataSnapshot();
}

void loop(void) {
  delay(10000);
}
