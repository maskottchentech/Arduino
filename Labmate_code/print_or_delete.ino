void print1()
{
  delay(100);
  printflag = true;
  bool upflag = false;
  bool downflag = false;
  upflag = true;
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("*");
  lcd.setCursor(2, 0);
  lcd.print("Print");
  lcd.setCursor(2, 1);
  lcd.print("Delete");
  while (printflag == true) {
    delay(150);
    int enter = digitalRead(enter_button);
    int up = digitalRead(up_buttonPin);
    int down = digitalRead(down_buttonPin);

    if (up == 1 ) {
      digitalWrite(buzzerpin, HIGH);
      delay(20);
      digitalWrite(buzzerpin, LOW);
      upflag = true;
      downflag = false;
      lcd.setCursor(0, 1);
      lcd.print(" ");
      lcd.setCursor(0, 0);
      lcd.print("*");

    }
    if (down == 1) {
      digitalWrite(buzzerpin, HIGH);
      delay(20);
      digitalWrite(buzzerpin, LOW);
      upflag = false;
      downflag = true;
      lcd.setCursor(0, 0);
      lcd.print(" ");
      lcd.setCursor(0, 1);
      lcd.print("*");
    }

    if (enter == 1) {
      digitalWrite(buzzerpin, HIGH);
      delay(20);
      digitalWrite(buzzerpin, LOW);
      if (upflag == true) {
        printflag = false;
        printing();
      }
      if (downflag == true) {
        digitalWrite(buzzerpin, HIGH);
        delay(20);
        digitalWrite(buzzerpin, LOW);
        printflag = false;
        deleting();
      }
    }
    if (digitalRead(back_button) == 1) {
      digitalWrite(buzzerpin, HIGH);
      delay(20);
      digitalWrite(buzzerpin, LOW);
      printflag = false;
      secondscreenflag3 = true;
      secondscreen3();
    }
  }
}
