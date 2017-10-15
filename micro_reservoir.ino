#include <CircularBuffer.h>
int WATER_THRESHOlD = 1200;
int WATER_DETECTION_MS = 5000;
boolean enableRelay = false;
int D3 = 3;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(D3, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  // read the input on analog pin 0:
  //int lightSensor = analogRead(A0);
  int waterSensor = analogRead(A1);
   Serial.print("water sensor value=");
   Serial.println(waterSensor);
   if(waterSensor >= WATER_THRESHOlD){
     enableRelay= false;
   } else {
     enableRelay = true;
   }
  //Serial.println("water sensor value=%d", waterSensor);
  if (isHigh){
    digitalWrite(D3, HIGH);
    isHigh = false;
  } else {
    digitalWrite(D3, LOW);
    isHigh = true;
  }
  delay(WATER_DETECTION_MS);
}
