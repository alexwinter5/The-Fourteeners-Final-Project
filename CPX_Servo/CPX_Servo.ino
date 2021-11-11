//William Cashen
//Iowa State University
//Servo Motor Control 
//AERE 361 Final Project


//Include the Library For Servo Functions
#include <Servo.h>

//Define the pin number the servo uses with a signal wire
int ServoPin = 1 ;

//Creating a Servo Object
Servo Servo1;

void setup() {
  // put your setup code here, to run once:
  
  //Attach the Servo to the used pin number
  Servo1.attach(ServoPin);
}

void loop() {
  // put your main code here, to run repeatedly:

  //Make servo go to 0 degrees
  Servo1.write(0);
  delay(1000);
  //Make servo go to 90 degrees
  Servo1.write(90);
  delay(1000);
  //Make servo go to 180 degrees
  Servo1.write(180);
  delay(1000);

  //ends the loop and then returns to the servo to 0 at the beginning
}
