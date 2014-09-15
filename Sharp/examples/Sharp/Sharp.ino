#include <Sharp.h>

Sharp Dist;
int distance;
int ir[2] = {17, 19};

void setup() {
  Serial.begin(115200);
  Dist.begin(ir[0],ir[1]);
}

void loop() {
  for (int i = 0; i < 2; i++) {
    distance = Dist.getDistance(ir[i]);
    Serial.print(distance);
    Serial.print("\t");
    delay(50);
  }
  Serial.println();
}


