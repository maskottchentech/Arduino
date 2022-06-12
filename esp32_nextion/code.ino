String x = "";
void setup() {
  Serial2.begin(9600);
  Serial.begin(9600);

}

void loop() {
 if(Serial2.available()>0){
  x = Serial2.readStringUntil('\n');
  Serial.print(x);
 }
 for(int i =0;i<5;i++){
  Serial2.print("n0.val=");
  Serial2.print(i);
  Serial2.write(0xff);
  Serial2.write(0xff);
  Serial2.write(0xff);
  delay(1500);
 }

}
