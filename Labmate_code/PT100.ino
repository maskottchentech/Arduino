float pt100_function() {
  // put your main code here, to run repeatedly:
  int pt100 = analogRead(A0);
  float Vout = pt100 * (5.0 / 1023.0);
  float R2 = R1 * 1 / (5.0 / Vout - 1);

  if (R2 > 165) {
    c =  MultiMap2(R2, in2);
  }

  else {
    c =  MultiMap(R2, in);
  }

  Serial.print("Resistance: ");
  Serial.print(R2);
  Serial.println(" Ohm");
  return c;
}
