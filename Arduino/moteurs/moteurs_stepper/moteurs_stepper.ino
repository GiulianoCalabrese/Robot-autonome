#include <Stepper.h>

const int stepsPerRevolution = 200; 
Stepper myStepper(stepsPerRevolution,5,8,11,12);
Stepper myStepper1(stepsPerRevolution,3,4,6,7);
// give the motor control pins names:
const int pwmA = 3;
const int pwmB = 6;
const int brakeA = 4;
const int brakeB = 7;

void setup () {
Serial.begin(9600);
pinMode(pwmA, OUTPUT);
pinMode(pwmB, OUTPUT);
pinMode(brakeA, OUTPUT);
pinMode(brakeB, OUTPUT);
digitalWrite(pwmA, HIGH);
digitalWrite(pwmB, HIGH);
digitalWrite(brakeA, LOW);
digitalWrite(brakeB, LOW);
myStepper.setSpeed(100);
myStepper1.setSpeed(100);
} 
void loop () {
myStepper.step(1);
myStepper1.step(1);
//myStepper.step(-200);
//delay(2000);
}
