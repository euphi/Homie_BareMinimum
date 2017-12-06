#include <Arduino.h>
#include <Homie.h>

void setup() {
  Homie_setFirmware("bare-minimum", "1.0.0");
  Serial.begin(74880);
  Serial.println("Start");
  Serial.flush();
  Homie.disableLedFeedback();
  Homie.disableResetTrigger();
  Homie.setLoggingPrinter(&Serial);
  Serial.println("Setup");
  Homie.setup();
}

void loop() {
  Homie.loop();
  static int last = 0;

  if (millis()-last > 500) {
    Serial.print('.');
    last = millis();
 }
}
