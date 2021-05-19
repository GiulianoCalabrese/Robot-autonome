#include <TimerOne.h> 
#define ENCODEURA 4
#define ENCODEURB 5
#define ENCODEURC 8
#define ENCODEURD 9
#define A 2 // ContrÃ´le vitesse moteur 1
#define B 3 //controle direction moteur 1
#define C 6 // ContrÃ´le vitesse moteur 2
#define D 7 //controle direction moteur 2
#define trigPin 11
#define echoPin 12
#define PoluluCapteur A0
long duration = 0; float distance = 0;
int message = 0;
void stop() //Stop
{
digitalWrite(A,LOW);
digitalWrite(B,LOW);
digitalWrite(C,LOW);
digitalWrite(D,LOW);
}

void advance(char a) // En avant
{
analogWrite (A,0); // ContrÃ´le de vitesse en PWM
digitalWrite(B,HIGH);
analogWrite (C,255); // ContrÃ´le de vitesse en PWM
digitalWrite(D,LOW);
}

void back_off (char a) // En arriÃ¨re
{
analogWrite (A,255);
digitalWrite(B,LOW);
analogWrite (C,0);
digitalWrite(D,HIGH);
}

void adv_R (char a) // En arriÃ¨re
{
analogWrite (A,0);
digitalWrite(B,HIGH);
digitalWrite(C,LOW);
digitalWrite(D,LOW);
}

void adv_G (char a) // En arriÃ¨re
{
digitalWrite(A,LOW);
digitalWrite(B,LOW);
analogWrite (C,255); // ContrÃ´le de vitesse en PWM
digitalWrite(D,LOW);
}
void back_R (char a) // En arriÃ¨re
{
analogWrite (A,255);
digitalWrite(B,LOW);
digitalWrite(C,LOW);
digitalWrite(D,LOW);
}

void back_G (char a) // En arriÃ¨re
{
digitalWrite(A,LOW);
digitalWrite(B,LOW);
analogWrite (C,0); // ContrÃ´le de vitesse en PWM
digitalWrite(D,HIGH);
}

volatile int count =0; // comptage de tick d'encoder  qui sera incrÃ©mentÃ© sur interruption " On change " sur l'interruption matÃ©riel 0 qui se fait sur le pin 2
volatile double speed =0; // vitesse du moteur 
volatile byte laststate =0;  // etat prÃ©cÃ©dent de l'encodeur 


void setup() {
  Serial.begin(9600); // set up Serial library at 9600 bps
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
   pinMode(ENCODEURA, INPUT_PULLUP);
 pinMode(ENCODEURB, INPUT_PULLUP);
    pinMode(ENCODEURC, INPUT_PULLUP);
 pinMode(ENCODEURD, INPUT_PULLUP);
 pinMode(A, OUTPUT);
pinMode(B, OUTPUT);
 pinMode(C, OUTPUT);
pinMode(D, OUTPUT);
attachInterrupt(0,counter, CHANGE); // on crÃ©e l'interruption sur changement sur la pin 2 => interruption 0, la routine counter va se faire toute seule sans l'appeler Ã  chaque changement d'Ã©tat sur le pin 2
Timer1.initialize(100000); // On dÃ©fini le timeur : 100000 microseconds ( 0.1 sec - or 10Hz )
Timer1.attachInterrupt( timerIsr ); // attach the service routine here la fonction timerIsr est une routine qui va se faire automatiquement 10* par secondes sans l'appeler
digitalWrite(trigPin, LOW);
}

void loop() {
//  digitalWrite(trigPin, HIGH);
//  delayMicroseconds(10);
//  digitalWrite(trigPin, LOW);
//
//  // Réception de l'écho
//  duration = pulseIn(echoPin, HIGH);
//
//  // Calcul de la distance
//  distance = (duration / 2) / 29.1;
//Serial.println(distance);
int sensorValue = analogRead(PoluluCapteur);
double distance = 19841*pow(sensorValue, -1.309);
//Serial.println(distance);
if(distance > 15){
  //back_off (255); // en arriÃ¨re vitesse max
  if (Serial.available())  {
    message = Serial.read() - '0'; // on soustrait le caractère 0, qui vaut 48 en ASCII
    Serial.println(message);
    switch (message) {
      case 0:
        stop();
        break;
      case 1:
        advance (0);
        break;
    }
  }
 }
else stop();
}

// Encoder counter 0

void counter()
{
  byte state=PIND;
  
  state|=B11101011;  // mask pour ne regarder que les changements sur 2 et 4 
  // Modifier le MASK  B01111011 par BXXXXXXXX mettre des 0 lÃ  oÃ¹ sont les pins utilisÃ©s par l'encodeur
  if( state!=laststate)
  {
    (((state&(1<<ENCODEURA))>>ENCODEURA)^((state&(1<<ENCODEURB))>>ENCODEURB))?count--:count++;
    laststate=state;
  }
}


// Timer event to calculate speed from counters

void timerIsr()
{
    speed=count; // on a le nombre de tick ( signÃ© ) par unitÃ© de temps  = vitesse
    count=0; // On remet le compteur de tick Ã  0 
}

