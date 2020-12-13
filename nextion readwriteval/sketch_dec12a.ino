int screenval[7];
int i = 0;
const int trigPin = 9;
const int echoPin = 10;
// defines variables
long duration;
int distance;
void setup()
{
  Serial.begin(9600);
 pinMode(13,OUTPUT);
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT); 
}

void loop() 
{
 if(Serial.available()>0){
  int x;
  x = Serial.read();
  Serial.println(x);
  screenval[i] = x;
  i++;
  if(i == 7){
    i = 0;
    if(screenval[2] == 1){
      digitalWrite(13,HIGH);
    }
    if(screenval[2] == 2){
      digitalWrite(13,LOW);
    }
  }
 }// end of if condition

 digitalWrite(trigPin, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);
// Calculating the distance
distance= duration*0.034/2;
// Prints the distance on the Serial Monitor
/*Serial.print("Distance: ");
Serial.println(distance);*/

Serial.print("n0.val=");
Serial.print(distance);
Serial.write(0xff);
Serial.write(0xff);
Serial.write(0xff);
delay(100);
}
