#include "battery.h"

Batterylevel bt(A0,1000,100);
void setup() {
 bt.begin();
 Serial.begin(9600);

}

void loop() {
  int x = bt.calculatelevel();
  Serial.print(x);

}
