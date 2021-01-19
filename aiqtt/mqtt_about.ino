#include "mqtt_about.h"
#include "info.h"

static DynamicJsonDocument aboutJson(128);

void mqttAboutInit(void) {
  aboutJson["codename"] = F(__CODENAME);
  aboutJson["id"]       = F(__ID);
  aboutJson["version"]  = F(__VERSION);
}

void mqttPubAbout(void) {
  // FIXME
  serializeJson(aboutJson, Serial);
  Serial.println();
}