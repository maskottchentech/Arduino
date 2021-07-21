void update_entry() {
  Serial.println("before update");
  int i = 46;
  while (i < 136) {
    Serial.print(i);
    Serial.print("   ");
    Serial.println(EEPROM.read(i));
    i++;
  }

  int a1 = EEPROM.read (50);
  int a2 = EEPROM.read(54);
  int b1 = EEPROM.read(59);
  int b2 = EEPROM.read(63);
  int c1 = EEPROM.read(68);
  int c2 = EEPROM.read(72);
  int d1 = EEPROM.read(77);
  int d2 = EEPROM.read(81);
  int e1 = EEPROM.read(86);
  int e2 = EEPROM.read(90);
  int f1 = EEPROM.read(95);
  int f2 = EEPROM.read(99);
  int g1 = EEPROM.read(104);
  int g2 = EEPROM.read(108);
  int h1 = EEPROM.read(113);
  int h2 = EEPROM.read(117);
  int i1 = EEPROM.read(122);
  int i2 = EEPROM.read(126);

  if (a1 == 0 && a2 == 0) {
    EEPROM.update(46, EEPROM.read(55));
    EEPROM.update(47,  EEPROM.read(56));
    EEPROM.update(48, EEPROM.read(57));
    EEPROM.update(49, EEPROM.read(58));
    EEPROM.update(50,  EEPROM.read(59));
    EEPROM.update(51, EEPROM.read(60));
    EEPROM.update(52, EEPROM.read(61));
    EEPROM.update(53,  EEPROM.read(62));
    EEPROM.update(54, EEPROM.read(63));
    EEPROM.update(59, 0);
    EEPROM.update(63, 0);
  }
  if (b1 == 0 && b2 == 0) {
    EEPROM.update(55, EEPROM.read(64));
    EEPROM.update(56, EEPROM.read(65));
    EEPROM.update(57, EEPROM.read(66));
    EEPROM.update(58, EEPROM.read(67));
    EEPROM.update(59, EEPROM.read(68));
    EEPROM.update(60, EEPROM.read(69));
    EEPROM.update(61, EEPROM.read(70));
    EEPROM.update(62, EEPROM.read(71));
    EEPROM.update(63, EEPROM.read(72));
    EEPROM.update(68, 0);
    EEPROM.update(72, 0);

  }
  if (c1 == 0 && c2 == 0) {
    EEPROM.update(64, EEPROM.read(73));
    EEPROM.update(65, EEPROM.read(74));
    EEPROM.update(66, EEPROM.read(75));
    EEPROM.update(67, EEPROM.read(76));
    EEPROM.update(68, EEPROM.read(77));
    EEPROM.update(69, EEPROM.read(78));
    EEPROM.update(70, EEPROM.read(79));
    EEPROM.update(71, EEPROM.read(80));
    EEPROM.update(72, EEPROM.read(81));
    EEPROM.update(77, 0);
    EEPROM.update(81, 0);

  }
  if (d1 == 0 && d2 == 0) {
    EEPROM.update(73, EEPROM.read(82));
    EEPROM.update(74, EEPROM.read(83));
    EEPROM.update(75, EEPROM.read(84));
    EEPROM.update(76, EEPROM.read(85));
    EEPROM.update(77, EEPROM.read(86));
    EEPROM.update(78, EEPROM.read(87));
    EEPROM.update(79, EEPROM.read(88));
    EEPROM.update(80, EEPROM.read(89));
    EEPROM.update(81, EEPROM.read(90));
    EEPROM.update(86, 0);
    EEPROM.update(90, 0);

  }
  if (e1 == 0 && e2 == 0) {
    EEPROM.update(82, EEPROM.read(91));
    EEPROM.update(83, EEPROM.read(92));
    EEPROM.update(84, EEPROM.read(93));
    EEPROM.update(85, EEPROM.read(94));
    EEPROM.update(86, EEPROM.read(95));
    EEPROM.update(87, EEPROM.read(96));
    EEPROM.update(88, EEPROM.read(97));
    EEPROM.update(89, EEPROM.read(98));
    EEPROM.update(90, EEPROM.read(99));
    EEPROM.update(95, 0);
    EEPROM.update(99, 0);

  }
  if (f1 == 0 && f2 == 0) {
    EEPROM.update(91, EEPROM.read(100));
    EEPROM.update(92, EEPROM.read(101));
    EEPROM.update(93, EEPROM.read(102));
    EEPROM.update(94, EEPROM.read(103));
    EEPROM.update(95, EEPROM.read(104));
    EEPROM.update(96, EEPROM.read(105));
    EEPROM.update(97, EEPROM.read(106));
    EEPROM.update(98, EEPROM.read(107));
    EEPROM.update(99, EEPROM.read(108));
    EEPROM.update(104, 0);
    EEPROM.update(108, 0);
  }
  if (g1 == 0 && g2 == 0) {
    EEPROM.update(100, EEPROM.read(109));
    EEPROM.update(101, EEPROM.read(110));
    EEPROM.update(102, EEPROM.read(111));
    EEPROM.update(103, EEPROM.read(112));
    EEPROM.update(104, EEPROM.read(113));
    EEPROM.update(105, EEPROM.read(114));
    EEPROM.update(106, EEPROM.read(115));
    EEPROM.update(107, EEPROM.read(116));
    EEPROM.update(108, EEPROM.read(117));
    EEPROM.update(113, 0);
    EEPROM.update(117, 0); 
  }
  if (h1 == 0 && h2 == 0) {
    EEPROM.update(109, EEPROM.read(118));
    EEPROM.update(110, EEPROM.read(119));
    EEPROM.update(111, EEPROM.read(120));
    EEPROM.update(112, EEPROM.read(121));
    EEPROM.update(113, EEPROM.read(122));
    EEPROM.update(114, EEPROM.read(123));
    EEPROM.update(115, EEPROM.read(124));
    EEPROM.update(116, EEPROM.read(125));
    EEPROM.update(117, EEPROM.read(126));
    EEPROM.update(122, 0);
    EEPROM.update(126, 0);
  }

  if (i1 == 0 && i2 == 0) {
    EEPROM.update(118, EEPROM.read(127));
    EEPROM.update(119, EEPROM.read(128));
    EEPROM.update(120, EEPROM.read(129));
    EEPROM.update(121, EEPROM.read(130));
    EEPROM.update(122, EEPROM.read(131));
    EEPROM.update(123, EEPROM.read(132));
    EEPROM.update(124, EEPROM.read(133));
    EEPROM.update(125, EEPROM.read(134));
    EEPROM.update(126, EEPROM.read(135));
    EEPROM.update(127, 0);
    EEPROM.update(128, 0);
    EEPROM.update(129, 0);
    EEPROM.update(130, 0);
    EEPROM.update(131, 0);
    EEPROM.update(132, 0);
    EEPROM.update(133, 0);
    EEPROM.update(134, 0);
    EEPROM.update(135, 0);

  }
  Serial.println("after update");
  int j = 46;
  while (j < 136) {
    Serial.print(j);
    Serial.print("   ");
    Serial.println(EEPROM.read(j));
    j++;
  }
  secondscreenflag3 = true;
  secondscreen3();
}
