void update_eeprom(int eeprom_add) {
  while (eeprom_add < 127) {
    EEPROM.update(eeprom_add, EEPROM.read(eeprom_add + 9));
    eeprom_add++;
  }
  while (eeprom_add < 136) {
    EEPROM.update(eeprom_add, 0);
    eeprom_add++;
  }
  secondscreenflag3 = true;
  secondscreen3();
}
