void Buzzer() {                   //Set buzzer value
  buzzerTime = EEPROM.read(200);                                      //read previous buzzerTime from memory
  cuttOffTime = EEPROM.read(201);                                     //read previous cuttOffTime from memory
  while (SetBuzzer == true) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("*");
    lcd.setCursor(1, 0);
    lcd.print("-Set Buzzer");
    lcd.setCursor(14, 0);
    lcd.print(buzzerTime);
    lcd.setCursor(2, 1);
    lcd.print("Cut time");
    lcd.setCursor(14, 1);
    lcd.print(cuttOffTime);
    delay(100);
    int enter = digitalRead(enter_button);                             // enter key
    int up = digitalRead(up_buttonPin);                             // down_buttonPin key
    int down = digitalRead(down_buttonPin);                           // down key

    if (up == 1) {
      digitalWrite(buzzerpin, HIGH);
      delay(20);
      digitalWrite(buzzerpin, LOW);
      buzzerTime++;
      if (buzzerTime >= 20) {
        buzzerTime = 20;
      }
    }
    if (down == 1) {
      digitalWrite(buzzerpin, HIGH);
      delay(20);
      digitalWrite(buzzerpin, LOW);
      buzzerTime--;
      if (buzzerTime < 0) {
        buzzerTime = 0;
      }
    }
    if (enter == 1) {
      EEPROM.update(200, buzzerTime);
      SetBuzzer = false;
      SetCuttOffHeat = true;
      digitalWrite(buzzerpin, HIGH);
      delay(20);
      digitalWrite(buzzerpin, LOW);
      cutOff();
    }
    if (digitalRead(7) == 1) {
      firstscreenflag = true;
      digitalWrite(buzzerpin, HIGH);
      delay(20);
      digitalWrite(buzzerpin, LOW);
      firstscreen();
    }
  }
}

void cutOff() {                   //Set cut off value
  while (SetCuttOffHeat == true) {
    lcd.clear();
    lcd.setCursor(0, 1);
    lcd.print("*");
    lcd.setCursor(2, 0);
    lcd.print("Set Buzzer");
    lcd.setCursor(14, 0);
    lcd.print(buzzerTime);
    lcd.setCursor(1, 1);
    lcd.print("-Cut time");
    lcd.setCursor(14, 1);
    lcd.print(cuttOffTime);
    delay(100);
    int enter = digitalRead(enter_button);                             // enter key
    int up = digitalRead(up_buttonPin);                             // down_buttonPin key
    int down = digitalRead(down_buttonPin);                           // down key

    if (up == 1) {
      digitalWrite(buzzerpin, HIGH);
      delay(20);
      digitalWrite(buzzerpin, LOW);

      cuttOffTime++;
    }
    if (down == 1) {
      digitalWrite(buzzerpin, HIGH);
      delay(20);
      digitalWrite(buzzerpin, LOW);

      cuttOffTime--;
      if (cuttOffTime < 0) {
        cuttOffTime = 0;
      }
    }
    if (enter == 1) {
      EEPROM.update(201, cuttOffTime);
      SetCuttOffHeat = false;
      firstscreenflag = true;
      digitalWrite(buzzerpin, HIGH);
      delay(20);
      digitalWrite(buzzerpin, LOW);
      firstscreen();
    }
    if (digitalRead(7) == 1) {
      firstscreenflag = true;
      digitalWrite(buzzerpin, HIGH);
      delay(20);
      digitalWrite(buzzerpin, LOW);
      firstscreen();
    }
  }
}
