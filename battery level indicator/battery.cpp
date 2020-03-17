#include "Arduino.h"
#include "battery.h"

Batterylevel::Batterylevel(int pinread, float r1,float r2,float Vout,float Vin,int BTVAL){
	voltagepin = pinread;
	R1 = r1;
	R2 = r2;
	vout = Vout;
	vin = Vin;
  btvalue = BTVAL;
	
}

void Batterylevel::begin(){
  pinMode(voltagepin,INPUT);
}

int Batterylevel::calculatelevel(){
  btvalue = analogRead(voltagepin);
  vout = (btvalue * 5.0) / 1024;
  vin = vout / (R2/(R1+R2));
  return vin;
}
