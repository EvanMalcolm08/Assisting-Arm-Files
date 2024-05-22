// PROJECT   : Assisting Arm
// PURPOSE   : A Moving Robotic Arm Controlled with POTs and Switches
// COURSE    : ICD2O
// AUTHOR    : Evan M
// DATE      : 2024 04 12
// MCU       : 328P (Uno)
// STATUS    : Working
// REFERENCE : http://darcy.rsgc.on.ca/ 

#include <Servo.h>
// Pins for the inputs
#define basepin A5
#define shoulderpin A4
#define elbowpin A3
#define claw 8

#define servopin0 9
#define servopin1 10
#define servopin2 11
#define servopin3 12
#define servopin4 13

// Starting Positions for the Servos 
uint8_t servocount0 = 90;
uint8_t servocount1 = 90;
uint8_t servocount2 = 90;
uint8_t clawcount = 90;
uint8_t clawcount2 = 90;
uint8_t basevalue = 0;

//Attaching Servos
Servo servo0;
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;

void setup() {
Serial.begin(9600); // Serial Startup
//Attaching Servos
servo0.attach(servopin0);
servo1.attach(servopin1);
servo2.attach(servopin2);
servo3.attach(servopin3);
servo4.attach(servopin4);
//Attaching Inputs
pinMode(basepin, INPUT);
pinMode(shoulderpin, INPUT);
pinMode(elbowpin, INPUT);
pinMode(claw, INPUT);
}

void loop() {
//Inputs for the if loops
int base = analogRead(basepin);
int basevalue = map(base, 0, 1023, 0, 180);
int shoulder = analogRead(shoulderpin);
int shouldervalue = map(shoulder, 0, 1023, 0, 110);
int elbow = analogRead(elbowpin);
int elbowvalue = map(elbow, 0, 1023, 70, 180);
uint8_t cl = digitalRead(claw);

if (basevalue > 178){
  basevalue = basevalue - 1;
}
if (basevalue < 2){
  basevalue = basevalue + 1;
}

servo0.write(basevalue);
delay(1);

if (shouldervalue > 110){
  shouldervalue = shouldervalue - 1;
}
if (shouldervalue < 2){
  shouldervalue = shouldervalue + 1;
}

servo1.write(shouldervalue);
delay(1);

if (elbowvalue > 110){
  elbowvalue = elbowvalue - 1;
}
if (elbowvalue < 2){
  elbowvalue = elbowvalue + 1;
}
servo2.write(elbowvalue);
delay(1);

if (cl == 0){
  clawcount = 90;
  clawcount2 = 0;
  servo3.write(clawcount);
  servo4.write(clawcount2);
  delay(1);
}
if (cl == 1){
  clawcount = 0;
  clawcount2 = 90;
  servo3.write(clawcount);
  servo4.write(clawcount2);
  delay(1);
}
if (servocount0 > 170){
servocount0 = 170;
delay(1);
}
if (servocount1 > 90){
servocount1 = 90;
delay(1);
}
if (servocount2 > 90){
servocount2 = 90;
delay(1);
}
if (servocount0 < 10){
servocount0 = 10;
delay(1);
}
if (servocount1 < 10){
servocount1 = 10;
delay(1);
}
if (servocount2 < 10){
servocount2 = 10;
delay(1);
}
Serial.println(cl);

delay(1);
}
