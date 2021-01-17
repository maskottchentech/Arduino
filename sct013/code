#include<Wire.h>
#include<Adafruit_ADS1015.h>

Adafruit_ADS1115 ads;

const float FACTOR =30;

const float multiplier = 0.0625F;

void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);

 ads.setGain(GAIN_TWO);
 ads.begin();
 
}

void printMeasure(String prefix, float value, String postfix)
{
  Serial.print(prefix);
  Serial.println(value, 3);
  Serial.println(postfix);
}

void loop() {
  // put your main code here, to run repeatedly:
float currentRMS = getCorriente();
float power = 230.0*currentRMS;
printMeasure("Irms:",currentRMS,"A");
printMeasure("potencia:",power,"H");
delay(1000);
}


float getCorriente()
{
  float voltage;
  float Corriente;
  float sum = 0;
  long tiempo = millis();
  int counter = 0;
  
  while (millis()-tiempo<1000)
  {
    voltage = ads.readADC_Differential_0_1()*multiplier;
    Corriente = voltage*FACTOR;
    Corriente /= 1000.0;
    sum += sq(Corriente);
    counter = counter + 1;
  }
  Corriente = sqrt(sum/counter);
  return(Corriente);
}
