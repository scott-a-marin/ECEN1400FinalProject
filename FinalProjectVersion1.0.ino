#include <Servo.h> //servo library
#include <Wire.h> // Must include Wire library for I2C
#include <SparkFun_MMA8452Q.h> // accelerometer library

  Servo Xservo;  // sets up servo as a servo
  Servo Yservo;  // same thing but  for another servo

  MMA8452Q accel; // names this accelerometer accel

  float x = 0;  
  float y = 0;
  float z = 0; //variables for accelerometer axises
  float xadjusted = 0;
  float yadjusted = 0;
  float xcompare = 0;
  float ycompare = 0;

void setup() {
  Serial.begin(9600); 
  
  Xservo.attach(13);  // X Servo on pin 13
  Yservo.attach(12);  // Y Servo on pin 12

  accel.init(); // Sets up 
}


void loop() {
  accel.read();
  AccelValues();
  
  xadjusted = (x*90)+90; // scale it to use it with the servo (value between 0 and 180)
  if((abs(xadjusted - xcompare)) > 2.5){
    xcompare = xadjusted;
  Serial.println(xadjusted);
 if((xadjusted < 180) && (xadjusted > 0)){
  Xservo.write(xadjusted);  // sets the servo position according to the scaled value
  }
}
  
  delay(100);                            // waits for the servo to get there

yadjusted = (y*90)+90; // scale it to use it with the servo (value between 0 and 180)
if((abs(yadjusted - ycompare)) > 2.5){
  ycompare = yadjusted;
  Serial.println(yadjusted);
 if((yadjusted < 180) && (yadjusted > 0)){
   Yservo.write(yadjusted);     // sets the servo position according to the scaled value
 }
}
//analogWrite(A0, 512);
//analogWrite(A1, 512);
//analogWrite(A2, 512);

}


 void AccelValues()
{
  x = accel.cx;
  y = accel.cy;
  z = accel.cz;
 // Serial.print(accel.cx, 2);
 // Serial.print("\t");
 // Serial.print(accel.cy, 2);
 // Serial.print("\t");
 // Serial.print(accel.cz, 2);
//  Serial.print("\t");
  Serial.println();
}
