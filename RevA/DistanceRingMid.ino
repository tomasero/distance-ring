#include <Sharp.h>

Sharp Dist;
int distance;
int ir = 19;
int motors[3] = {21,22,23};
int power[3] = {0,0,0};
float vBat = 9;
float vMax;


void setup() {
  Serial.begin(115200);
  for(int i = 0; i< 3; i++){
    pinMode(motors[i],OUTPUT); 
  }
  Dist.begin(ir);
  vMax = 255 * 3.7 / vBat;
}

void loop() {
    distance = Dist.getDistance(ir);
    getPWM(distance);
    //Serial.print(distance);
    delay(10);
    for(int i = 0; i < 3; i++) {
        analogWrite(motors[i], power[i]);
        delay(100);
    }
    Serial.println();
}

void getPWM(int distance) {
  int value = map(distance, 10, 80, 0, 100);
  if (value < 50) {
    power[0] = 100 - value;
    power[1] = value;
    power[2] = 0;
  } else if(value == 50) {
    power[0] = 0;
    power[1] = 100;
    power[2] = 0;
  } else {
    value = value - 50;
    power[0] = 0;
    power[1] = 100 - value;
    power[2] = value;  
  }
}


