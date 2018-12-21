#include <ArduinoJson.h>

void setup() {
  Serial.begin(115200);
  delay(10);

}

int depth = 1;
void loop() {
//  JsonBuffer object is declared locally, because they're monotonic
// a llocators, can allocate memory but cannot release it.
  StaticJsonBuffer<200> jsonBuffer;
  JsonObject& root = jsonBuffer.createObject();
  JsonArray& data = root.createNestedArray("coordinates");
  
  root["sensor"] = "gps";
  root["timestamps"] = "somerandomnumber";
  root["depth"] =  depth;
  
  data.add(48.756080);
  data.add(2.302038);

  
  Serial.println("In loop, hello!");
  
  root.printTo(Serial);  
  
  Serial.println();
  delay(500);
  depth++;
}
