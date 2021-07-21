void dimmer1()
{
  unsigned long cutoff_var = 0;
  bool cut_flag = true;
  buzzerTime = EEPROM.read(200);                                      //read previous buzzerTime from memory
  cuttOffTime = EEPROM.read(201);                                     //read previous cuttOffTime from memory
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Set Temp");
  lcd.setCursor(13, 0);
  lcd.print(temp);
  lcd.setCursor(0, 1);
  lcd.print("Curr Temp");
  lcd.setCursor(12, 1);
  lcd.print(thermo.temperature(RNOMINAL, RREF) + float_val);
  delay(150);
  int dim;
  // normal heat selection
  if (normal_heat_flag == true) {
    if (temp >= 1 && temp <= 50) {
      dim = EEPROM.read(1);
    }
    if (temp >= 51 && temp <= 75) {
      dim = EEPROM.read(2);
    }
    if (temp >= 76 && temp <= 100) {
      dim = EEPROM.read(3);
    }
    if (temp >= 101 && temp <= 125) {
      dim = EEPROM.read(4);
    }
    if (temp >= 126 && temp <= 150) {
      dim = EEPROM.read(5);
    }
    if (temp >= 151 && temp <= 175) {
      dim = EEPROM.read(6);
    }
    if (temp >= 176 && temp <= 200) {
      dim = EEPROM.read(7);
    }
    if (temp >= 201 && temp <= 225) {
      dim = EEPROM.read(8);
    }
    if (temp >= 226 && temp <= 250) {
      dim = EEPROM.read(9);
    }
    if (temp >= 251 && temp <= 275) {
      dim = EEPROM.read(10);
    }
    if (temp >= 276 && temp <= 300) {
      dim = EEPROM.read(11);
    }
    if (temp >= 301 && temp <= 325) {
      dim = EEPROM.read(12);
    }
    if (temp >= 326 && temp <= 350) {
      dim = EEPROM.read(13);
    }
    if (temp >= 351 && temp <= 375) {
      dim = EEPROM.read(14);
    }
    if (temp >= 376 && temp <= 400) {
      dim = EEPROM.read(15);
    }
  }
  // medium heat selection
  if (medium_heat_flag == true) {
    if (temp >= 1 && temp <= 50) {
      dim = EEPROM.read(16);
    }
    if (temp >= 51 && temp <= 75) {
      dim = EEPROM.read(17);
    }
    if (temp >= 76 && temp <= 100) {
      dim = EEPROM.read(18);
    }
    if (temp >= 101 && temp <= 125) {
      dim = EEPROM.read(19);
    }
    if (temp >= 126 && temp <= 150) {
      dim = EEPROM.read(20);
    }
    if (temp >= 151 && temp <= 175) {
      dim = EEPROM.read(21);
    }
    if (temp >= 176 && temp <= 200) {
      dim = EEPROM.read(22);
    }
    if (temp >= 201 && temp <= 225) {
      dim = EEPROM.read(23);
    }
    if (temp >= 226 && temp <= 250) {
      dim = EEPROM.read(24);
    }
    if (temp >= 251 && temp <= 275) {
      dim = EEPROM.read(25);
    }
    if (temp >= 276 && temp <= 300) {
      dim = EEPROM.read(26);
    }
    if (temp >= 301 && temp <= 325) {
      dim = EEPROM.read(27);
    }
    if (temp >= 326 && temp <= 350) {
      dim = EEPROM.read(28);
    }
    if (temp >= 351 && temp <= 375) {
      dim = EEPROM.read(29);
    }
    if (temp >= 376 && temp <= 400) {
      dim = EEPROM.read(30);
    }
  }
  // fast heat selection
  if (fast_heat_flag == true) {

    if (temp >= 1 && temp <= 50) {
      dim = EEPROM.read(31);
    }
    if (temp >= 51 && temp <= 75) {
      dim = EEPROM.read(32);
    }
    if (temp >= 76 && temp <= 100) {
      dim = EEPROM.read(33);
    }
    if (temp >= 101 && temp <= 125) {
      dim = EEPROM.read(34);
    }
    if (temp >= 126 && temp <= 150) {
      dim = EEPROM.read(35);
    }
    if (temp >= 151 && temp <= 175) {
      dim = EEPROM.read(36);
    }
    if (temp >= 176 && temp <= 200) {
      dim = EEPROM.read(37);
    }
    if (temp >= 201 && temp <= 225) {
      dim = EEPROM.read(38);
    }
    if (temp >= 226 && temp <= 250) {
      dim = EEPROM.read(39);
    }
    if (temp >= 251 && temp <= 275) {
      dim = EEPROM.read(40);
    }
    if (temp >= 276 && temp <= 300) {
      dim = EEPROM.read(41);
    }
    if (temp >= 301 && temp <= 325) {
      dim = EEPROM.read(42);
    }
    if (temp >= 326 && temp <= 350) {
      dim = EEPROM.read(43);
    }
    if (temp >= 351 && temp <= 375) {
      dim = EEPROM.read(44);
    }
    if (temp >= 376 && temp <= 400) {
      dim = EEPROM.read(45);
    }
  }
  float curr_temp = thermo.temperature(RNOMINAL, RREF);
  dimmer4.begin(NORMAL_MODE, ON);
  while (dimmer_flag == true ) {
    dimmer4.setPower(dim);
    curr_temp = thermo.temperature(RNOMINAL, RREF) + float_val;
    lcd.setCursor(12, 1);
    lcd.print(thermo.temperature(RNOMINAL, RREF) + float_val);
    if (curr_temp >= temp - buzzerTime && curr_temp <= temp - buzzerTime + 1) {
      digitalWrite(buzzerpin, HIGH);
      delay(100);
      digitalWrite(buzzerpin, LOW);
    }
    if (curr_temp >= temp - 1 && curr_temp <= temp + 1) {
      if (cut_flag) {
        cutoff_var = millis();
        digitalWrite(buzzerpin, HIGH);
        delay(100);
        digitalWrite(buzzerpin, LOW);
        cut_flag = false;
      }
    }
    if (cut_flag == false) {
      if (millis() >= cutoff_var + (cuttOffTime * 60000)) {
        dimmer_flag = false;
        main_menu_flag = true;
        dimmer4.begin(NORMAL_MODE, OFF);
        digitalWrite(buzzerpin, HIGH);
        delay(200);
        digitalWrite(buzzerpin, LOW);
        main_menu();
      }
    }

    int start = digitalRead(start_parameter_button);
    if (start == 1) {
      digitalWrite(buzzerpin, HIGH);
      delay(20);
      digitalWrite(buzzerpin, LOW);
      delay(50);
      storage();
    }
  }
}
