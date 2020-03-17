

#ifndef battery_h
#define battery_h

#include "Arduino.h"

class Batterylevel{
	private:
		int voltagepin;
		float vout;
        float vin;
        float R1;
        float R2;
        int btvalue;
	public:
		Batterylevel(int pinread, float r1,float r2,float Vout = 0,float Vin = 0,int BTVAL=0);
		void begin();
		int calculatelevel();
};
#endif
