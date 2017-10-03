int IDLE_STATE = 0;
int LIGHT_ON_STATE =1;
boolean isHigh = false;
int D3 = 3; 
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(D3, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  // read the input on analog pin 0:
  int lightSensor = analogRead(A0);
  // print out the value you read:
  Serial.print("light sensor value=");
  Serial.print(lightSensor);
  int waterSensor = analogRead(A1);
   Serial.print("\twater sensor value=");
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
