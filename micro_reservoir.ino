#include <CircularBuffer.h>
int LIGHT_UNKNOWN_STATE = 0;
int LIGHT_ACTIVE_STATE = 1;
int LIGHT_INACTIVE_STATE = 2;
int WATER_DETECTION_MS_IN_UNKNOWN_STATE = 4000;
int WATER_DETECTION_MS_IN_INACTIVE_STATE = 4000;
int WATER_DETECTION_MS_IN_ACTIVE_STATE = 1000;
int LIGHT_LENGTH = 6;
CircularBuffer<int,LIGHT_LENGTH>lightList;
boolean isHigh = false;
int onlineTest= true;
int D3 = 3; 
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(D3, OUTPUT);
}

int averageLight(){
  int i;
  int out=0;
  for(i=0; i<LIGHT_LENGTH; i++){
    out = out + lightList[i];
  }
  return out/LIGHT_LENGTH;
}

void loop() {
  // put your main code here, to run repeatedly:
  // read the input on analog pin 0:
  int lightSensor = analogRead(A0);
  // print out the value you read:
  Serial.print("light sensor value=");
  Serial.print(lightSensor);
  Serial.print(",average light value=");
  int aveLight = averageLight();
  Serial.println(aveLight);
  lightList.push(lightSensor);
  int waterSensor = analogRead(A1);
   Serial.print("water sensor value=");
   Serial.println(waterSensor);
  //Serial.println("water sensor value=%d", waterSensor);
  if (isHigh){
    digitalWrite(D3, HIGH);
    isHigh = false;  
  } else {
    digitalWrite(D3, LOW);
    isHigh = true;  
  }
  delay(3000); 
}
