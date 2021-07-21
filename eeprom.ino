void storage() {
  delay(100);

  float CurrentTempvalue = thermo.temperature(RNOMINAL, RREF) + float_val;
  displayTime();

  int Address = EEPROM.read(250);
  if (Address == 136) {
    lcd.clear();
    lcd.setCursor(3, 0);
    lcd.print("Memory Full");
    lcd.setCursor(0, 1);
    lcd.print("Delete Some Items");
  }
  else {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("storing data");
    EEPROM.update(Address, CurrentTempvalue / 2);  //46                 //Store first half value of current temp
    Address = Address + 1;
    EEPROM.update(Address, CurrentTempvalue / 2);   //47                 //Store other half value of current temp
    Address = Address + 1;
    EEPROM.update(Address, temp / 2);               //48        //Store first half value of Set temp
    Address = Address + 1;
    EEPROM.update(Address, temp / 2);            //49         //Store other half value of Set temp
    Address = Address + 1;
    EEPROM.update(Address, hours);      //50
    Address = Address + 1;
    EEPROM.update(Address, minutes);    //51
    Address = Address + 1;
    EEPROM.update(Address, days);     //52
    Address = Address + 1;
    EEPROM.update(Address, months);//53
    Address = Address + 1;
    EEPROM.update(Address, years);//54
    Address = Address + 1;
    EEPROM.update(250, Address);
  }
  delay(500);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Set Temp");
  lcd.setCursor(13, 0);
  lcd.print(temp);
  lcd.setCursor(0, 1);
  lcd.print("Curr Temp");
}
