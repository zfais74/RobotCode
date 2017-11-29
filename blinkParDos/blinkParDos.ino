/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://www.arduino.cc/en/Main/Products

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Blink
*/

#import <Servo.h>

Servo leftMotor;
Servo rightMotor;
Servo sensorMotor;
int LED_STATE = 0;
int timeInterval = 1000;
int previousMilli = 0;
int printWord = 0;
int leftMotorPin = 6;
int rightMotorPin = 5;
int leftBumperPin = A2;
int rightBumperPin = A1;
int leftBumper;
int rightBumper;
int sensorMotorPin = 3;
int state = 0;
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(leftMotorPin,OUTPUT);
  pinMode(rightMotorPin, OUTPUT);
  pinMode(sensorMotorPin, OUTPUT);
  pinMode(leftBumperPin, INPUT);
  leftMotor.attach(leftMotorPin);
  rightMotor.attach(rightMotorPin);
  sensorMotor.attach(sensorMotorPin);
  Serial.begin(9600);
}

// the loop function runs over and over again forever
void loop() {
  unsigned long currentMilli = millis();
  bumpers();
  search();
  motor();
  blink(currentMilli);
}

void motor() {
    switch(state) {
        case 0:
           Serial.println("Turn move forward");
           leftMotor.write(140);
           rightMotor.write(40);
         break;
        case 1:
            Serial.println("Turn move back");
            leftMotor.write(40);
            rightMotor.write(140);
          
          break;
        case 3:
          Serial.println("Bump");
          leftMotor.write(90);
          rightMotor.write(90);
          break;
      }
  }

void blink(long currentMilli) {
    switch(LED_STATE) {
      case 0:
        if(currentMilli - previousMilli >= timeInterval){
          previousMilli = currentMilli;
          Serial.println("Turn on");
          digitalWrite(LED_BUILTIN, HIGH);
          LED_STATE = 1;
       }

        break;
      case 1:
        if(currentMilli - previousMilli >= timeInterval){
          previousMilli = currentMilli;
          Serial.println("Turn off");
          digitalWrite(LED_BUILTIN, LOW);
          LED_STATE = 0;
        }
        break;   
    } 
  }
void bumpers(){
    leftBumper = digitalRead(leftBumperPin);
    rightBumper = digitalRead(rightBumperPin);
    Serial.println(rightBumper);
    if(leftBumper == HIGH || rightBumper == HIGH) {
        state = 3;
      }
      else state = 0;
 }

void search(){
  sensorMotor.write(45); 
 }
