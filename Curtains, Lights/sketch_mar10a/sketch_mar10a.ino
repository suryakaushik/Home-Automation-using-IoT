#include <Stepper.h>

const int stepsPerRevolution = 200; // change this to fit the number of steps per revolution for your motor 
Stepper myStepper(stepsPerRevolution, D1,D2,D3,D4);  


int enA = D5;
int enB = D6;

int stepCount = 0;         // number of steps the motor has taken


void setup() {
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  
  myStepper.setSpeed(60);// set speed to 60rpm
  Serial.begin(115200);
}

void loop() {
  value = analogRead(A0);

  Serial.print("steps:");
  Serial.println(stepCount);
  stepCount++;
  
  if(value<=600)//opening curtains(more light outside and ldr res. is less)
  {
  analogWrite(enA, 700);
  analogWrite(enB, 700);
  
  Serial.println("clockwise");  
  myStepper.step(stepsPerRevolution); //number of steps taken by motor per revolution
  delay(500);
  }
  if(value>600)//closing curtains(less light outside and ldr res. is more)
  {
  analogWrite(enA, 700);
  analogWrite(enB, 700);
  
  Serial.println("counterclockwise");
  myStepper.step(-stepsPerRevolution);
  delay(500); 
  }

  
if( stepCount > 500)//by changing this 500,we can control time for which motor stays on
{    
      stepCount = 0;                  
      analogWrite(enA, 0);
      analogWrite(enB, 0);
      
}
 delayMicroseconds(50);
}
