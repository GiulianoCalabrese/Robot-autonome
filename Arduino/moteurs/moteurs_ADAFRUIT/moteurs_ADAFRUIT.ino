
#include <AFMotor.h>
AF_Stepper stepper1(200, 1);
AF_Stepper stepper2(200, 2);


void setup()
{  
    stepper1.setSpeed(200);  
    stepper2.setSpeed(200); 
}
void loop()
{
    stepper1.step(0, BACKWARD, INTERLEAVE);
    stepper2.step(0, FORWARD, INTERLEAVE);
}
