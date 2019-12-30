#include <Sonar_hc_sr04.h>

Sonar_hc_sr04 Sonar_Front(16, 17);
int distance;

void setup() {
  Serial.begin(115200);
}

void loop() {
  distance = Sonar_Front.Read();
  
  Serial.print("Distance in [cm]: ");
  Serial.println(distance);
  delay(500);
}

