//define Pins
int led = 13;
int trigPin = 9;
int echoPin = 8;

// defines variables
long duration;
int distance;

void setup() 
{
pinMode(led, OUTPUT);
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
Serial.begin(9600); 
}
void loop() 
{
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance= duration*0.034/2;
Serial.print("Distance: ");
Serial.println(distance);
if ( distance >= 3) 
 {
digitalWrite (led , HIGH );
delay (1000);
 } 
else 
{
digitalWrite (led, LOW );
delay(1000);
 }

}

