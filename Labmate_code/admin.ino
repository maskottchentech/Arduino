void correctPassword() {
  long onDuration = 1000;//-
  onDuration = 0;
  int FaultyEnter = 0;
  delay(50);
  while (correctPasswordflag == true) {

    boolean current_up = debounce(last_up, up);         //Debounce for down_buttonPin button

    current_down = debounce(last_down, down);   //Debounce for Down button

    //----Page counter function to move pages----//

    //Page up
    if (last_up == LOW && current_up == HIGH) { //When down_buttonPin button is pressed
      digitalWrite(buzzerpin, HIGH);
      delay(20);
      digitalWrite(buzzerpin, LOW);
      lcd.clear();                     //When page is changed, lcd clear to print new page
      if (page_counter_heat_screen < 3) {           //Page counter never higher than 3(total of pages)
        page_counter_heat_screen = page_counter_heat_screen + 1; //Page down_buttonPin

      }
      else {
        page_counter_heat_screen = 3;
      }
    }

    last_up = current_up;

    //Page Down
    if (last_down == LOW && current_down == HIGH) { //When down button is pressed
      digitalWrite(buzzerpin, HIGH);
      delay(20);
      digitalWrite(buzzerpin, LOW);
      lcd.clear();                     //When page is changed, lcd clear to print new page
      if (page_counter_heat_screen > 1) {           //Page counter never lower than 1 (total of pages)
        page_counter_heat_screen = page_counter_heat_screen - 1; //Page down
      }
      else {
        page_counter_heat_screen = 1;
      }
    }

    last_down = current_down;
    delay(200);
    switch (page_counter_heat_screen) {

      case 1: {    //Design of home page 1
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("*");
          lcd.setCursor(2, 0);
          lcd.print("normal heat");
          lcd.setCursor(2, 1);
          lcd.print("medium heat");
          normal_heat_flag_service = true;
          medium_heat_flag_service = false;
          fast_heat_flag_service = false;
        }
        break;
      case 2: {    //Design of home page 2
          lcd.clear();
          lcd.setCursor(0, 1);
          lcd.print("*");
          lcd.setCursor(2, 0);
          lcd.print("normal heat");
          lcd.setCursor(2, 1);
          lcd.print("medium heat");
          normal_heat_flag_service = false;
          medium_heat_flag_service = true;
          fast_heat_flag_service = false;
        }
        break;
      case 3: {    //Design of home page 3
          lcd.clear();
          lcd.setCursor(0, 1);
          lcd.print("*");
          lcd.setCursor(2, 0);
          lcd.print("medium heat");
          lcd.setCursor(2, 1);
          lcd.print("fast heat");
          normal_heat_flag_service = false;
          medium_heat_flag_service = false;
          fast_heat_flag_service = true;

        }
        break;
    }
    int enter = digitalRead(enter_button);
    int up = digitalRead(up_buttonPin);                             // up key
    int down = digitalRead(down_buttonPin);                           // down key
    if (enter == 1) {
      digitalWrite(buzzerpin, HIGH);
      delay(20);
      digitalWrite(buzzerpin, LOW);
      correctPasswordflag = false;
      service_flag = true;
      service();

    }
    if (digitalRead(7) == 1) {
      correctPasswordflag = false;
      secondscreenflag5 = true;
      digitalWrite(buzzerpin, HIGH);
      delay(20);
      digitalWrite(buzzerpin, LOW);
      secondscreen5();
    }
    //    if (page_counter_heat_screen == 2) {
    //      if (enter == 1) {
    //        while (true) {
    //          lcd.clear();
    //          lcd.setCursor(0, 0);
    //          lcd.println("cal of medium");
    //        }
    //      }
    //    }
    //    if (page_counter_heat_screen == 3) {
    //      if (enter == 1) {
    //        while (true) {
    //          lcd.clear();
    //          lcd.setCursor(0, 0);
    //          lcd.println("cal of fast");
    //        }
    //      }
    //    }
    //    int down_buttonPin = digitalRead(up_buttonPin);                             // down_buttonPin key
    //    int down = digitalRead(down_buttonPin);                           // down key
    //    int enter = digitalRead(enter_button);                             // enter key
    //    lcd.clear();
    //    lcd.setCursor(0, 0);
    //    lcd.print("on time");
    //    lcd.setCursor(11, 0);
    //    lcd.print(ontime);
    //    lcd.print("sec");
    //    lcd.setCursor(0, 1);
    //    lcd.print("off time");
    //    if (down_buttonPin == 1) {
    //      ontime++;
    //      onDuration += 1000;
    //      Serial.println(ontime);
    //    }
    //
    //    if (down == 1) {
    //      ontime--;
    //      onDuration -= 1000;
    //      Serial.println(ontime);
    //      if (ontime <= 0) {
    //        ontime = 0;
    //      }
    //    }
    //    if (enter == 1) {
    //      offtimeflag = true;
    //      correctPasswordflag = false;
    //      offtimeduration();
    //    }

  }
}

//void offtimeduration() {
//  offDuration9000 = 0;
//  while (offtimeflag == true) {
//    if (temp >= 1 && temp <= 50) {
//      int enter;
//      int down_buttonPin = digitalRead(up_buttonPin);                             // down_buttonPin key
//      int down = digitalRead(down_buttonPin);                           // down key
//      lcd.clear();
//      lcd.setCursor(0, 0);
//      lcd.print("on time");
//      lcd.setCursor(11, 0);
//      lcd.print(ontime);
//      lcd.print("sec");
//      lcd.setCursor(0, 1);
//      lcd.print("off time");
//      lcd.setCursor(11, 1);
//      lcd.print(offtime);
//      lcd.print("sec");
//
//      if (down_buttonPin == 1) {
//        offtime++;
//        offDuration9000 += 1000;
//      }
//      if (down == 1) {
//        offtime--;
//        offDuration9000 -= 1000;
//        if (offtime <= 0) {
//          offtime = 0;
//        }
//      }
//      delay(200);
//      if (enter == 1) {
//        Serial.println("enter1");
//        offtimeflag = false;
//        normal_heat_flag = true;
//        normalHeat();
//      }
//      enter = digitalRead(enter_button);                             // enter key
//    }
//    if (temp >= 51 && temp <= 70) {
//      int enter;
//      int down_buttonPin = digitalRead(up_buttonPin);                             // down_buttonPin key
//      int down = digitalRead(down_buttonPin);                           // down key
//      lcd.clear();
//      lcd.setCursor(0, 0);
//      lcd.print("on time");
//      lcd.setCursor(11, 0);
//      lcd.print(ontime);
//      lcd.print("sec");
//      lcd.setCursor(0, 1);
//      lcd.print("off time");
//      lcd.setCursor(11, 1);
//      lcd.print(offtime);
//      lcd.print("sec");
//
//      if (down_buttonPin == 1) {
//        offtime++;
//        offDuration9000 += 1000;
//      }
//      if (down == 1) {
//        offtime--;
//        offDuration9000 -= 1000;
//
//        if (offtime <= 0) {
//          offtime = 0;
//        }
//      }
//      delay(200);
//      if (enter == 1) {
//        Serial.println("enter1");
//        offtimeflag = false;
//        normalHeat();
//      }
//      enter = digitalRead(enter_button);                             // enter key
//    }
//  }
//}
