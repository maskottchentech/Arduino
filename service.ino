void secondscreen5() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Enter Password");
  while (secondscreenflag5 == true) {
    delay(180);
    int up = digitalRead(up_buttonPin);                             // down_buttonPin key
    int down = digitalRead(down_buttonPin);                           // down key
    lcd.setCursor(2, 1);
    lcd.print(password1);
    if (digitalRead(up_buttonPin) == 1) {
      password1++;
      digitalWrite(buzzerpin, HIGH);
      delay(20);
      digitalWrite(buzzerpin, LOW);
    }
    if (down == 1) {
      digitalWrite(buzzerpin, HIGH);
      delay(20);
      digitalWrite(buzzerpin, LOW);
      password1--;
      if (password1 <= 0) {
        password1 = 0;
      }
    }
    int enter = digitalRead(enter_button);                             // enter key
    if (enter == 1) {
      digitalWrite(buzzerpin, HIGH);
      delay(20);
      digitalWrite(buzzerpin, LOW);
      secondscreenflag5 = false;
      password2flag = true;
      password_2();
    }
    if (digitalRead(7) == 1) {
      secondscreenflag5 = false;
      firstscreenflag = true;
      digitalWrite(buzzerpin, HIGH);
      delay(20);
      digitalWrite(buzzerpin, LOW);
      firstscreen();
    }
  }                                                       //end of while loop
}                                                         //end of secondscreen5

void password_2() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Enter Password");
  lcd.setCursor(2, 1);
  lcd.print(password1);
  while (password2flag == true) {
    delay(180);
    lcd.setCursor(4, 1);
    lcd.print(password2);
    int enter = digitalRead(enter_button);                             // enter key
    int up = digitalRead(up_buttonPin);                             // down_buttonPin key
    int down = digitalRead(down_buttonPin);                           // down key
    if (up == 1) {
      digitalWrite(buzzerpin, HIGH);
      delay(20);
      digitalWrite(buzzerpin, LOW);
      password2++;
    }
    if (down == 1) {
      digitalWrite(buzzerpin, HIGH);
      delay(20);
      digitalWrite(buzzerpin, LOW);
      password2--;
      if (password2 <= 0) {
        password2 = 0;
      }
    }
    if (enter == 1) {
      digitalWrite(buzzerpin, HIGH);
      delay(20);
      digitalWrite(buzzerpin, LOW);
      password2flag = false;
      password3flag = true;
      password_3();
    }
    if (digitalRead(7) == 1) {
      password2flag = false;
      secondscreenflag5 = true;
      digitalWrite(buzzerpin, HIGH);
      delay(20);
      digitalWrite(buzzerpin, LOW);
      secondscreen5();
    }
  }
}

void password_3() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Enter Password");
  lcd.setCursor(2, 1);
  lcd.print(password1);
  lcd.setCursor(4, 1);
  lcd.print(password2);
  while (password3flag == true) {
    delay(150);
    lcd.setCursor(6, 1);
    lcd.print(password3);
    int enter = digitalRead(enter_button);                             // enter key
    int up = digitalRead(up_buttonPin);                             // down_buttonPin key
    int down = digitalRead(down_buttonPin);                           // down key
    if (up == 1) {
      digitalWrite(buzzerpin, HIGH);
      delay(20);
      digitalWrite(buzzerpin, LOW);
      password3++;
    }
    if (down == 1) {
      digitalWrite(buzzerpin, HIGH);
      delay(20);
      digitalWrite(buzzerpin, LOW);
      password3--;
      if (password3 <= 0) {
        password3 = 0;
      }
    }
    if (enter == 1) {
      digitalWrite(buzzerpin, HIGH);
      delay(20);
      digitalWrite(buzzerpin, LOW);

      if (password1 == 1 && password2 == 0 && password3 == 3) {
        password1 = 0; password2 = 0; password3 = 0;
        password3flag = false;
        correctPasswordflag = true;
        correctPassword();                                           //this function is in admin file
      }
      else {
        password1 = 0; password2 = 0; password3 = 0;
        WrongPasswordflag = true;
        password3flag = false;
        wrongPassword();
      }
    }
    if (digitalRead(7) == 1) {
      password3flag = false;
      password2flag = true;
      digitalWrite(buzzerpin, HIGH);
      delay(20);
      digitalWrite(buzzerpin, LOW);
      password_2();
    }
  }
}

void wrongPassword() {
  while (WrongPasswordflag == true) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Wrong Password");
    delay(2000);
    WrongPasswordflag = false;
    firstscreenflag = true;
    firstscreen();
  }
}
