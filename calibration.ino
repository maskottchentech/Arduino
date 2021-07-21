void calibration() {
  lcd.clear();
  lcd.setCursor(3, 0);
  lcd.print("enter value");
  int8_t calibration_value = EEPROM.read(calibration_address);          //calibration value
  float_val = calibration_value ;
  float_val = float_val / 10;
  float set_calibration = 0.0f;
  while (calibration_flag == true) {//int8_t data = EEPROM.read(600);
    lcd.setCursor(6, 1);
    lcd.print(float_val);
    lcd.setCursor(11, 1);
    lcd.print("    ");
    if (digitalRead(up_buttonPin) == 1) {
      digitalWrite(buzzerpin, HIGH);
      delay(20);
      digitalWrite(buzzerpin, LOW);
      float_val += 0.1;
      if (float_val > 3.0) {
        float_val = 3.0;
      }
    }
    if (digitalRead(down_buttonPin) == 1) {
      digitalWrite(buzzerpin, HIGH);
      delay(20);
      digitalWrite(buzzerpin, LOW);
      float_val -= 0.1;
      if (float_val < -3.0) {
        float_val = -3.0;
      }
    }
    delay(150);
    if (digitalRead(enter_button) == 1) {
      digitalWrite(buzzerpin, HIGH);
      delay(20);
      digitalWrite(buzzerpin, LOW);
      int val1 = float_val * 10;
      EEPROM.write(500, val1);
      calibration_flag = false;
      firstscreenflag = true;
      firstscreen();
    }
    if (digitalRead(7) == 1) {
      digitalWrite(buzzerpin, HIGH);
      delay(20);
      digitalWrite(buzzerpin, LOW);
      calibration_flag = false;
      firstscreenflag = true;
      firstscreen();
    }
  }
}
