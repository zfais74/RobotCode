#import <Servo.h>
Servo servo;
Servo leftMotor;
Servo rightMotor;

#define FORWARD 0
#define BACKWARD 1
#define F_LEFT 2
#define F_RIGHT 3
#define STOP 4

int leftBumperPin = A2;
int rightBumperPin = A1;
int TrigPin = A4;
int EchoPin = A5;
int servoPin = 3;
int leftMotorPin = 6;
int rightMotorPin = 5;
int position = 90;
unsigned long farThreshold = 2000;
unsigned long nearThreshold = 800;
int initialThresholds = true;
int leftBumper;
int rightBumper;
unsigned long duration;
unsigned long array[5];
int maxTime=8000;
int positionIndex;
unsigned long x;
int rangerVal;
const int ledPin = LED_BUILTIN;
long previousMillis = 0;
long timeInterval = 5000;
int LED_STATE = 0;

void setup(){
pinMode(leftBumperPin,INPUT);
pinMode(rightBumperPin,INPUT);
pinMode(TrigPin,OUTPUT);
pinMode(EchoPin,INPUT);
pinMode(leftMotorPin,OUTPUT);
pinMode(rightMotorPin,OUTPUT);
pinMode(ledPin, OUTPUT);
servo.attach(servoPin);
leftMotor.attach(leftMotorPin);
rightMotor.attach(rightMotorPin);
Serial.begin(9600);
}

void loop(){
  Serial.print("start");
  unsigned long currentMillis = millis();
  switch(LED_STATE) {
      case 0:
        Serial.print("case 0");
        if(currentMillis - previousMillis >= timeInterval) {
          Serial.print("0 true");
          previousMillis = currentMillis;
          digitalWrite(ledPin, HIGH);
          LED_STATE = 1;
        }
          break;
      case 1:
        Serial.print("case 1");
         previousMillis = currentMillis;
          digitalWrite(ledPin, LOW);
          LED_STATE = 0;
          break;
      }

}


