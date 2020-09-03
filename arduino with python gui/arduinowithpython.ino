int x=0,i=0;

void setup()
{
Serial.begin(9600);
//Serial.print("Hello World");

}

void loop() {
 
    Serial.println(i);
    delay(200);
    i++;
    Serial.println(x);
    delay(200);
    x--;
  

}
