void deleting() {
  int update_eeprom_add;
  if (entryflag1 == true) {
    entryflag1 = false;
    int i = 46;
    update_eeprom_add = i;
    while (i < 55) {
      lcd.clear();
      lcd.print("deleting 1");
      EEPROM.update(i, 0);
      i++;
    }                               //end of delete while
  }
  if (entryflag2 == true) {
    entryflag2 = false;
    lcd.clear();
    lcd.print("deleting 2");
    int i = 55;
    update_eeprom_add = i;
    while (i < 64) {
      EEPROM.update(i, 0);
      i++;
    }//end of delete while

  }
  if (entryflag3 == true) {
    entryflag3 = false;
    lcd.clear();
    lcd.print("deleting 3");
    int i = 64;
    update_eeprom_add = i;
    while (i < 73) {
      EEPROM.update(i, 0);
      i++;
    }//end of delete while
  }
  if (entryflag4 == true) {
    entryflag4 = false;
    lcd.clear();
    lcd.print("deleting 4");
    int i = 73;
    update_eeprom_add = i;
    while (i < 82) {
      EEPROM.update(i, 0);
      i++;
    }//end of delete while
  }
  if (entryflag5 == true) {
    entryflag5 = false;
    lcd.clear();
    lcd.print("deleting 5");
    int i = 82;
    update_eeprom_add = i;
    while (i < 91) {
      EEPROM.write(i, 0);
      i++;
    }//end of delete while
  }
  if (entryflag6 == true) {
    entryflag6 = false;
    lcd.clear();
    lcd.print("deleting 6");
    int i = 91;
    update_eeprom_add = i;
    while (i < 100) {
      EEPROM.update(i, 0);
      i++;
    }//end of delete while
  }
  if (entryflag7 == true) {
    entryflag7 = false;
    lcd.clear();
    lcd.print("deleting 7");
    int i = 100;
    update_eeprom_add = i;
    while (i < 109) {
      EEPROM.write(i, 0);
      i++;
    }//end of delete while
  }
  if (entryflag8 == true) {
    entryflag8 = false;
    lcd.clear();
    lcd.print("deleting 8");
    int i = 109;
    update_eeprom_add = i;
    while (i < 118) {
      EEPROM.update(i, 0);
      i++;
    }//end of delete while
  }
  if (entryflag9 == true) {
    entryflag9 = false;
    lcd.clear();
    lcd.print("deleting 9");
    int i = 118;
    update_eeprom_add = i;
    while (i < 127) {
      EEPROM.update(i, 0);
      i++;
    }//end of delete while
  }
  if (entryflag10 == true) {
    entryflag10 = false;
    lcd.clear();
    lcd.print("deleting 10");
    int i = 127;
    update_eeprom_add = i;
    while (i < 136) {
      EEPROM.update(i, 0);
      i++;
    }                                                          //end of delete while
  }
  delay(1000);
  lcd.clear();
  int minus_nine = (EEPROM.read(250) - 9);
  EEPROM.update(250, minus_nine);
  //Serial.println(EEPROM.read(250));
  //secondscreenflag3 = true;
  //secondscreen3();
  //update_entry();
  update_eeprom(update_eeprom_add);
}
