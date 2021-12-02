/* FSR testing sketch. 

Connect one end of FSR to 5V, the other end to Analog 0.
Then connect one end of a 10K resistor from Analog 0 to ground
Connect LED from pin 11 through a resistor to ground 
 
For more information see www.ladyada.net/learn/sensors/fsr.html */

/*#include <Adafruit_NeoPixel.h>*/
#include <Adafruit_CircuitPlayground.h>
#include <math.h>

//pressure sensor variables
int fsrAnalogPin = 0; // FSR is connected to analog 0, Resistive measurement
int fsrAnalogPin2 = 3;
int LEDpin = 11;      // connect LED to pin 11 (PWM pin) //
int fsrReading;      // the analog reading from the FSR resistor divider //value output
int fsrReading2;
int LEDbrightness; //value output converted to scale of 0-255

//ultrasonic sensor variables
int trigPin=2; //Sets value of where the treshhold is triggered
int echoPin=1; //Sets the return value of where threshold is triggered//a1
int pingTravelTime; //Value telling whether or not a ball has scored
int LEDPin_Ultra=7; //Don't know
int maxPing = 500; //Comparative threshold to deteremine a score or not
int LEDTime = 5000; //Not used
 
void setup() {
  CircuitPlayground.begin();
  pinMode(LEDpin, OUTPUT);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  pinMode(LEDPin_Ultra,OUTPUT);
  
  Serial.begin(9600);   // We'll send debugging information via the Serial monitor

  
}
 
void loop() {
  //Next 3 lines for debugging
  fsrReading = analogRead(fsrAnalogPin);
  fsrReading2 = analogRead(fsrAnalogPin2);
  //Serial.print("Analog reading = ");
  //Serial.println(fsrReading);

  //Serial.print("Analog reading 2 = ");
  //Serial.println(fsrReading2);

  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);

  pingTravelTime = pulseIn(echoPin, HIGH);
  delay(25);



  //This line for debugging ultrasonic sensor
  Serial.print("pingTravelTime");
  Serial.println(pingTravelTime);
   
  // we'll need to change the range from the analog reading (0-1023) down to the range
  // used by analogWrite (0-255) with map!
  LEDbrightness = map(fsrReading, 0, 1023, 0, 255);
  // LED gets brighter the harder you press
  analogWrite(LEDpin, LEDbrightness);
  //Serial.print("LEDbrightness = ");
  //Serial.println(LEDbrightness);

  //missed goal
  if (pingTravelTime > maxPing){
    CircuitPlayground.setPixelColor(0, 255, 0, 0);
    CircuitPlayground.setPixelColor(1, 255, 0, 0);
    CircuitPlayground.setPixelColor(2, 255, 0, 0);
    CircuitPlayground.setPixelColor(3, 255, 0, 0);
    CircuitPlayground.setPixelColor(4, 255, 0, 0);
    CircuitPlayground.setPixelColor(5, 255, 0, 0);
    CircuitPlayground.setPixelColor(6, 255, 0, 0);
    CircuitPlayground.setPixelColor(7, 255, 0, 0);
    CircuitPlayground.setPixelColor(8, 255, 0, 0);
    CircuitPlayground.setPixelColor(9, 255, 0, 0);
    
  }

  //In goal didn't register on pressure sensor
  if (LEDbrightness < 245 && pingTravelTime < maxPing ){
    CircuitPlayground.setPixelColor(0, 255, 0, 255);
    CircuitPlayground.setPixelColor(1, 255, 0, 255);
    CircuitPlayground.setPixelColor(2, 255, 0, 255);
    CircuitPlayground.setPixelColor(3, 255, 0, 255);
    CircuitPlayground.setPixelColor(4, 255, 0, 255);
    CircuitPlayground.setPixelColor(5, 255, 0, 255);
    CircuitPlayground.setPixelColor(6, 255, 0, 255);
    CircuitPlayground.setPixelColor(7, 255, 0, 255);
    CircuitPlayground.setPixelColor(8, 255, 0, 255);
    CircuitPlayground.setPixelColor(9, 255, 0, 255);
  
  }

  //In goal soft kick as register on pressure sensor
  if (LEDbrightness >= 245 && LEDbrightness < 250 && pingTravelTime < maxPing){
  
    CircuitPlayground.setPixelColor(0, 255, 255, 0);
    CircuitPlayground.setPixelColor(1, 255, 255, 0);
    CircuitPlayground.setPixelColor(2, 255, 255, 0);
    CircuitPlayground.setPixelColor(3, 255, 255, 0);
    CircuitPlayground.setPixelColor(4, 255, 255, 0);
    CircuitPlayground.setPixelColor(5, 255, 255, 0);
    CircuitPlayground.setPixelColor(6, 255, 255, 0);
    CircuitPlayground.setPixelColor(7, 255, 255, 0);
    CircuitPlayground.setPixelColor(8, 255, 255, 0);
    CircuitPlayground.setPixelColor(9, 255, 255, 0);
  }

  //In goal hard kick as register on pressure sensor
  if (LEDbrightness >= 250 && pingTravelTime < maxPing){
  
    CircuitPlayground.setPixelColor(0, 0, 255, 0);
    CircuitPlayground.setPixelColor(1, 0, 255, 0);
    CircuitPlayground.setPixelColor(2, 0, 255, 0);
    CircuitPlayground.setPixelColor(3, 0, 255, 0);
    CircuitPlayground.setPixelColor(4, 0, 255, 0);
    CircuitPlayground.setPixelColor(5, 0, 255, 0);
    CircuitPlayground.setPixelColor(6, 0, 255, 0);
    CircuitPlayground.setPixelColor(7, 0, 255, 0);
    CircuitPlayground.setPixelColor(8, 0, 255, 0);
    CircuitPlayground.setPixelColor(9, 0, 255, 0);
  }

  
  delay(10);
}
