
//ultrasonic determines if object within maxPing range
//if object is less than maxPing distance away, LED lights up 

int trigPin=12;
int echoPin=11;
int pingTravelTime;
int LEDPin=7;
int maxPing = 500;


void setup() {
  // put your setup code here, to run once:

pinMode(trigPin,OUTPUT);
pinMode(echoPin,INPUT);
pinMode(LEDPin,OUTPUT);
Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

digitalWrite(trigPin,LOW);
delayMicroseconds(10);

digitalWrite(trigPin,HIGH);
delayMicroseconds(10);

digitalWrite(trigPin,LOW);

pingTravelTime = pulseIn(echoPin,HIGH);
delay(25);

Serial.println(pingTravelTime);


if(pingTravelTime < maxPing){
  digitalWrite(LEDPin, HIGH);
  delay(LEDTime);
  digitalWrite(LEDPin, LOW);
  }

}
