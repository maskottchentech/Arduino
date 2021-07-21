void timeupdate() {
  delay(200);
  int menu = 0;
  while (secondscreenflag6 == true) {
    // check if you press the SET button and increase the menu index

    if (digitalRead(enter_button))
    { digitalWrite(buzzerpin, HIGH);
      delay(20);
      digitalWrite(buzzerpin, LOW);
      menu = menu + 1;
    }
    // in which subroutine should we go?
    if (menu == 0)
    {
      DisplayDateTime(); // void DisplayDateTime

    }
    if (menu == 1)
    {
      DisplaySetHour();
    }
    if (menu == 2)
    {
      DisplaySetMinute();
    }
    if (menu == 3)
    {
      DisplaySetYear();
    }
    if (menu == 4)
    {
      DisplaySetMonth();
    }
    if (menu == 5)
    {
      DisplaySetDay();
    }
    if (menu == 6)
    {
      StoreAgg();
      delay(500);
      menu = 0;
    }
    if (digitalRead(start_parameter_button)) {
      digitalWrite(buzzerpin, HIGH);
      delay(20);
      digitalWrite(buzzerpin, LOW);
      firstscreenflag = true;
      secondscreenflag6 = false;
    }
    if (digitalRead(7) == 1) {
      secondscreenflag6 = false;
      firstscreenflag = true;
      digitalWrite(buzzerpin, HIGH);
      delay(20);
      digitalWrite(buzzerpin, LOW);
      firstscreen();
    }
    delay(100);
  }
}
void DisplayDateTime ()
{
  // We show the current date and time
  DateTime now = RTC.now();

  lcd.setCursor(0, 1);
  lcd.print("Hour:");
  if (now.hour() <= 9)
  {
    lcd.print("0");
  }
  lcd.print(now.hour(), DEC);
  hourupg = now.hour();
  lcd.print(":");
  if (now.minute() <= 9)
  {
    lcd.print("0");
  }
  lcd.print(now.minute(), DEC);
  minupg = now.minute();
  lcd.print(":");
  if (now.second() <= 9)
  {
    lcd.print("0");
  }
  lcd.print(now.second(), DEC);

  lcd.setCursor(0, 0);
  lcd.print("Date: ");
  if (now.day() <= 9)
  {
    lcd.print("0");
  }
  lcd.print(now.day(), DEC);
  dayupg = now.day();
  lcd.print("/");
  if (now.month() <= 9)
  {
    lcd.print("0");
  }
  lcd.print(now.month(), DEC);
  monthupg = now.month();
  lcd.print("/");
  lcd.print(now.year(), DEC);
  yearupg = now.year();
}

void DisplaySetHour()
{
  // time setting
  lcd.clear();
  DateTime now = RTC.now();
  if (digitalRead(up_buttonPin) == HIGH)
  {
    digitalWrite(buzzerpin, HIGH);
    delay(20);
    digitalWrite(buzzerpin, LOW);
    if (hourupg == 23)
    {
      hourupg = 0;
    }
    else
    {
      hourupg = hourupg + 1;
    }
  }
  if (digitalRead(down_buttonPin) == HIGH)
  {
    digitalWrite(buzzerpin, HIGH);
    delay(20);
    digitalWrite(buzzerpin, LOW);
    if (hourupg == 0)
    {
      hourupg = 23;
    }
    else
    {
      hourupg = hourupg - 1;
    }
  }
  lcd.setCursor(0, 0);
  lcd.print("Set hour:");
  lcd.setCursor(0, 1);
  lcd.print(hourupg, DEC);
  delay(10);
}

void DisplaySetMinute()
{
  // Setting the minutes
  lcd.clear();
  if (digitalRead(up_buttonPin) == HIGH)
  {
    digitalWrite(buzzerpin, HIGH);
    delay(20);
    digitalWrite(buzzerpin, LOW);
    if (minupg == 59)
    {
      minupg = 0;
    }
    else
    {
      minupg = minupg + 1;
    }
  }
  if (digitalRead(down_buttonPin) == HIGH)
  {
    digitalWrite(buzzerpin, HIGH);
    delay(20);
    digitalWrite(buzzerpin, LOW);
    if (minupg == 0)
    {
      minupg = 59;
    }
    else
    {
      minupg = minupg - 1;
    }
  }
  lcd.setCursor(0, 0);
  lcd.print("Set Minutes:");
  lcd.setCursor(0, 1);
  lcd.print(minupg, DEC);
  delay(10);
}

void DisplaySetYear()
{
  // setting the year
  lcd.clear();
  if (digitalRead(up_buttonPin) == HIGH)
  {
    digitalWrite(buzzerpin, HIGH);
    delay(20);
    digitalWrite(buzzerpin, LOW);
    yearupg = yearupg + 1;
  }
  if (digitalRead(down_buttonPin) == HIGH)
  {
    digitalWrite(buzzerpin, HIGH);
    delay(20);
    digitalWrite(buzzerpin, LOW);
    yearupg = yearupg - 1;
  }
  lcd.setCursor(0, 0);
  lcd.print("Set Year:");
  lcd.setCursor(0, 1);
  lcd.print(yearupg, DEC);
  delay(100);
}

void DisplaySetMonth()
{
  // Setting the month
  lcd.clear();
  if (digitalRead(up_buttonPin) == HIGH)
  {
    digitalWrite(buzzerpin, HIGH);
    delay(20);
    digitalWrite(buzzerpin, LOW);
    if (monthupg == 12)
    {
      monthupg = 1;
    }
    else
    {
      monthupg = monthupg + 1;
    }
  }
  if (digitalRead(down_buttonPin) == HIGH)
  {
    digitalWrite(buzzerpin, HIGH);
    delay(20);
    digitalWrite(buzzerpin, LOW);
    if (monthupg == 1)
    {
      monthupg = 12;
    }
    else
    {
      monthupg = monthupg - 1;
    }
  }
  lcd.setCursor(0, 0);
  lcd.print("Set Month:");
  lcd.setCursor(0, 1);
  lcd.print(monthupg, DEC);
  delay(10);
}

void DisplaySetDay()
{
  // Setting the day
  lcd.clear();
  if (digitalRead(up_buttonPin) == HIGH)
  {
    digitalWrite(buzzerpin, HIGH);
    delay(20);
    digitalWrite(buzzerpin, LOW);
    if (dayupg == 31)
    {
      dayupg = 1;
    }
    else
    {
      dayupg = dayupg + 1;
    }
  }
  if (digitalRead(down_buttonPin) == HIGH)
  {
    digitalWrite(buzzerpin, HIGH);
    delay(20);
    digitalWrite(buzzerpin, LOW);
    if (dayupg == 1)
    {
      dayupg = 31;
    }
    else
    {
      dayupg = dayupg - 1;
    }
  }
  lcd.setCursor(0, 0);
  lcd.print("Set Day:");
  lcd.setCursor(0, 1);
  lcd.print(dayupg, DEC);
  delay(10);
}

void StoreAgg()
{
  // Variable saving
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("SAVING IN");
  lcd.setCursor(0, 1);
  lcd.print("PROGRESS");
  RTC.adjust(DateTime(yearupg, monthupg, dayupg, hourupg, minupg, 0));
  delay(10);
}
