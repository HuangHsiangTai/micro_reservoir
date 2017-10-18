#include <CircularBuffer.h>
int WATER_THRESHOlD = 1200;
int WATER_STANDBY_DETECTION_MS = 3000;
int WATER_ACTIVE_DETECTION_MS = 500;
int MAX_ADD_WATER_TIME = 10000;
int STAND_BY_STATE = 0;
int ADD_WATER_STATE = 1;

boolean enableRelay = false;
int detectionTime = WATER_STANDBY_DETECTION_MS;
int D3 = 3;
int state = STAND_BY_STATE;
int addWaterTime = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(D3, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  // read the input on analog pin 0:
  //int lightSensor = analogRead(A0);
  //TODO: check time out
  int waterSensor = analogRead(A1);
   Serial.print("water sensor value=");
   Serial.println(waterSensor);
   if(waterSensor >= WATER_THRESHOlD){
     if(enableRelay){
       digitalWrite(D3, LOW);
       Serial.println("stop adding water");
       enableRelay= false;
     }
     Serial.println("water level>threshold");
     detectionTime = WATER_STANDBY_DETECTION_MS;
     addWaterTime = 0;
   } else {
     detectionTime = WATER_ACTIVE_DETECTION_MS;
     addWaterTime = addWaterTime + detectionTime;
     if(addWaterTime>=MAX_ADD_WATER_TIME) {
       enableRelay= false;
       digitalWrite(D3, LOW);
       Serial.println("add water too much. stop adding water");
     }else {
       if(!enableRelay){
         enableRelay= true;
         digitalWrite(D3, HIGH);
         Serial.println("start adding water");
       }

     }
   }
  delay(detectionTime);
}
