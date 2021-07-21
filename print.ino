void printing() {
  if (entryflag1 == true) {
    lcd.clear();
    lcd.print("printing1");
    Serial.println("Current Temp.");
    Serial.println(EEPROM.read(46) + EEPROM.read(47));
    Serial.println("Temperature");
    Serial.println(EEPROM.read(48) + EEPROM.read(49));
    Serial.println("Time");
    Serial.print(EEPROM.read(50));
    Serial.print("-");
    Serial.println(EEPROM.read(51));
    Serial.println("Date");
    Serial.print(EEPROM.read(52));
    Serial.print("-");
    Serial.print(EEPROM.read(53));
    Serial.print("-");
    Serial.println(EEPROM.read(54));
    entryflag1 == false;
  }
  if (entryflag2 == true) {
    lcd.clear();
    lcd.print("printing2");
    Serial.println("Current Temp.");
    Serial.println(EEPROM.read(55) + EEPROM.read(56));
    Serial.println("Temperature");
    Serial.println(EEPROM.read(57) + EEPROM.read(58));
    Serial.println("Time");
    Serial.print(EEPROM.read(59));
    Serial.print("-");
    Serial.println(EEPROM.read(60));
    Serial.println("Date");
    Serial.print(EEPROM.read(61));
    Serial.print("-");
    Serial.print(EEPROM.read(62));
    Serial.print("-");
    Serial.println(EEPROM.read(63));
    entryflag2 == false;
  }
  if (entryflag3 == true) {
    lcd.clear();
    lcd.print("printing3");
    Serial.println("Current Temp.");
    Serial.println(EEPROM.read(64) + EEPROM.read(65));
    Serial.println("Temperature");
    Serial.println(EEPROM.read(66) + EEPROM.read(67));
    Serial.println("Time");
    Serial.print(EEPROM.read(68));
    Serial.print("-");
    Serial.println(EEPROM.read(69));
    Serial.println("Date");
    Serial.print(EEPROM.read(70));
    Serial.print("-");
    Serial.print(EEPROM.read(71));
    Serial.print("-");
    Serial.println(EEPROM.read(72));
    entryflag3 == false;
  }
  if (entryflag4 == true) {
    lcd.clear();
    lcd.print("printing4");
    Serial.println("Current Temp.");
    Serial.println(EEPROM.read(73) + EEPROM.read(74));
    Serial.println("Temperature");
    Serial.println(EEPROM.read(75) + EEPROM.read(76));
    Serial.println("Time");
    Serial.print(EEPROM.read(77));
    Serial.print("-");
    Serial.println(EEPROM.read(78));
    Serial.println("Date");
    Serial.print(EEPROM.read(79));
    Serial.print("-");
    Serial.print(EEPROM.read(80));
    Serial.print("-");
    Serial.println(EEPROM.read(81));
    entryflag4 == false;
  }
  if (entryflag5 == true) {
    lcd.clear();
    lcd.print("printing5");
    Serial.println("Current Temp.");
    Serial.println(EEPROM.read(82) + EEPROM.read(83));
    Serial.println("Temperature");
    Serial.println(EEPROM.read(84) + EEPROM.read(85));
    Serial.println("Time");
    Serial.print(EEPROM.read(86));
    Serial.print("-");
    Serial.println(EEPROM.read(87));
    Serial.println("Date");
    Serial.print(EEPROM.read(88));
    Serial.print("-");
    Serial.print(EEPROM.read(89));
    Serial.print("-");
    Serial.println(EEPROM.read(90));
    entryflag5 == false;
  }
  if (entryflag6 == true) {
    lcd.clear();
    lcd.print("printing6");
    Serial.println("Current Temp.");
    Serial.println(EEPROM.read(91) + EEPROM.read(92));
    Serial.println("Temperature");
    Serial.println(EEPROM.read(93) + EEPROM.read(94));
    Serial.println("Time");
    Serial.print(EEPROM.read(95));
    Serial.print("-");
    Serial.println(EEPROM.read(96));
    Serial.println("Date");
    Serial.print(EEPROM.read(97));
    Serial.print("-");
    Serial.print(EEPROM.read(98));
    Serial.print("-");
    Serial.println(EEPROM.read(99));
    entryflag6 == false;
  }
  if (entryflag7 == true) {
    lcd.clear();
    lcd.print("printing7");
    Serial.println("Current Temp.");
    Serial.println(EEPROM.read(100) + EEPROM.read(101));
    Serial.println("Temperature");
    Serial.println(EEPROM.read(102) + EEPROM.read(103));
    Serial.println("Time");
    Serial.print(EEPROM.read(104));
    Serial.print("-");
    Serial.println(EEPROM.read(105));
    Serial.println("Date");
    Serial.print(EEPROM.read(106));
    Serial.print("-");
    Serial.print(EEPROM.read(107));
    Serial.print("-");
    Serial.println(EEPROM.read(108));
    entryflag7 == false;
  }
  if (entryflag8 == true) {
    lcd.clear();
    lcd.print("printing8");
    Serial.println("Current Temp.");
    Serial.println(EEPROM.read(109) + EEPROM.read(110));
    Serial.println("Temperature");
    Serial.println(EEPROM.read(111) + EEPROM.read(112));
    Serial.println("Time");
    Serial.print(EEPROM.read(113));
    Serial.print("-");
    Serial.println(EEPROM.read(114));
    Serial.println("Date");
    Serial.print(EEPROM.read(115));
    Serial.print("-");
    Serial.print(EEPROM.read(116));
    Serial.print("-");
    Serial.println(EEPROM.read(117));
    entryflag8 == false;
  }
  if (entryflag9 == true) {
    lcd.clear();
    lcd.print("printing9");
    Serial.println("Current Temp.");
    Serial.println(EEPROM.read(118) + EEPROM.read(119));
    Serial.println("Temperature");
    Serial.println(EEPROM.read(120) + EEPROM.read(121));
    Serial.println("Time");
    Serial.print(EEPROM.read(122));
    Serial.print("-");
    Serial.println(EEPROM.read(123));
    Serial.println("Date");
    Serial.print(EEPROM.read(124));
    Serial.print("-");
    Serial.print(EEPROM.read(125));
    Serial.print("-");
    Serial.println(EEPROM.read(126));
    entryflag9 == false;
  }
  if (entryflag10 == true) {
    lcd.clear();
    lcd.print("printing10");
    Serial.println("Current Temp.");
    Serial.println(EEPROM.read(127) + EEPROM.read(128));
    Serial.println("Temperature");
    Serial.println(EEPROM.read(129) + EEPROM.read(130));
    Serial.println("Time");
    Serial.print(EEPROM.read(131));
    Serial.print("-");
    Serial.println(EEPROM.read(132));
    Serial.println("Date");
    Serial.print(EEPROM.read(133));
    Serial.print("-");
    Serial.print(EEPROM.read(134));
    Serial.print("-");
    Serial.println(EEPROM.read(135));
    entryflag10 == false;
  }

delay(1000);
lcd.clear();
printflag = false;
secondscreenflag3 = true;
secondscreen3();

}
