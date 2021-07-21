int set_heat_percentage(int percentage_eeprom_location) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("enter percentage");
  delay(100);
  int previous_percentage = EEPROM.read(percentage_eeprom_location);
  while (set_heat_percentage_flag == true) {
    lcd.setCursor(5, 1);
    lcd.print(previous_percentage);
    int enter = digitalRead(enter_button);
    int up = digitalRead(up_buttonPin);                             // down_buttonPin key
    int down = digitalRead(down_buttonPin);                           // down key
    if (up == 1) {
      digitalWrite(buzzerpin, HIGH);
      delay(20);
      digitalWrite(buzzerpin, LOW);
      previous_percentage++;
    }
    if (down == 1) {
      digitalWrite(buzzerpin, HIGH);
      delay(20);
      digitalWrite(buzzerpin, LOW);
      previous_percentage--;
      if (previous_percentage <= 0) {
        previous_percentage = 0;
      }
    }
    if (enter == 1) {
      digitalWrite(buzzerpin, HIGH);
      delay(20);
      digitalWrite(buzzerpin, LOW);
      EEPROM.update(percentage_eeprom_location, previous_percentage);
      set_heat_percentage_flag = false;
      firstscreenflag = true;
      firstscreen();
    }
    if (digitalRead(7) == 1) {
      service_flag = true;
      set_heat_percentage_flag = false;
      digitalWrite(buzzerpin, HIGH);
      delay(20);
      digitalWrite(buzzerpin, LOW);
      service();
    }
    delay(150);
  }
}
