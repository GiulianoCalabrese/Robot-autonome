/******************************************************************************************
  3 LEDs sont reliées à l'Arduino (aux pins 2, 3 et 4).  Les LEDs s'allument et s'éteignent
  en fonction du message recu.
******************************************************************************************/

#define LED1 2
#define LED2 3
#define LED3 4

int message = 0;


void setup()
{
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);

  Serial.begin(9600);
}
void loop()
{
  if (Serial.available())  {
    message = Serial.read() - '0'; // on soustrait le caractère 0, qui vaut 48 en ASCII
    Serial.println(message);
    switch (message) {
      case 1:
        digitalWrite(LED1, HIGH);
        break;
      case 2:
        digitalWrite(LED2, HIGH);
        break;
      case 3:
        digitalWrite(LED3, HIGH);
        break;
      case 4:
        digitalWrite(LED1, LOW);
        break;
      case 5:
        digitalWrite(LED2, LOW);
        break;
      case 6:
        digitalWrite(LED3, LOW);
        break;
    }
  }
}
