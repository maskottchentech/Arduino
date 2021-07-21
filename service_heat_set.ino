void service() {
  int heat_percentage_location[15];
  if (normal_heat_flag_service == true) {
    heat_percentage_location[0] = 1;
    heat_percentage_location[1] = 2;
    heat_percentage_location[2] = 3;
    heat_percentage_location[3] = 4;
    heat_percentage_location[4] = 5;
    heat_percentage_location[5] = 6;
    heat_percentage_location[6] = 7;
    heat_percentage_location[7] = 8;
    heat_percentage_location[8] = 9;
    heat_percentage_location[9] = 10;
    heat_percentage_location[10] = 11;
    heat_percentage_location[11] = 12;
    heat_percentage_location[12] = 13;
    heat_percentage_location[13] = 14;
    heat_percentage_location[14] = 15;
  }
  if (medium_heat_flag_service == true) {
    heat_percentage_location[0] = 16;
    heat_percentage_location[1] = 17;
    heat_percentage_location[2] = 18;
    heat_percentage_location[3] = 19;
    heat_percentage_location[4] = 20;
    heat_percentage_location[5] = 21;
    heat_percentage_location[6] = 22;
    heat_percentage_location[7] = 23;
    heat_percentage_location[8] = 24;
    heat_percentage_location[9] = 25;
    heat_percentage_location[10] = 26;
    heat_percentage_location[11] = 27;
    heat_percentage_location[12] = 28;
    heat_percentage_location[13] = 29;
    heat_percentage_location[14] = 30;
  }
  if (fast_heat_flag_service == true) {
    heat_percentage_location[0] = 31;
    heat_percentage_location[1] = 32;
    heat_percentage_location[2] = 33;
    heat_percentage_location[3] = 34;
    heat_percentage_location[4] = 35;
    heat_percentage_location[5] = 36;
    heat_percentage_location[6] = 37;
    heat_percentage_location[7] = 38;
    heat_percentage_location[8] = 39;
    heat_percentage_location[9] = 40;
    heat_percentage_location[10] = 41;
    heat_percentage_location[11] = 42;
    heat_percentage_location[12] = 43;
    heat_percentage_location[13] = 44;
    heat_percentage_location[14] = 45;
  }
  while (service_flag == true) {
    boolean current_up = debounce(last_up, up);         //Debounce for down_buttonPin button
    current_down = debounce(last_down, down);   //Debounce for Down button

    //----Page counter function to move pages----//

    //Page down_buttonPin
    if (last_up == LOW && current_up == HIGH) { //When down_buttonPin button is pressed
      digitalWrite(buzzerpin, HIGH);
      delay(20);
      digitalWrite(buzzerpin, LOW);
      lcd.clear();                     //When page is changed, lcd clear to print new page
      if (page_counter_heat_screen < 15) {           //Page counter never higher than 3(total of pages)
        page_counter_heat_screen = page_counter_heat_screen + 1; //Page down_buttonPin

      }
      else {
        page_counter_heat_screen = 15;
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
    delay(150);
    switch (page_counter_heat_screen) {

      case 1: {    //Design of home page 1
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("*");
          lcd.setCursor(2, 0);
          lcd.print("1-50");
          lcd.setCursor(2, 1);
          lcd.print("51-75");
          normal_heat_percentage = heat_percentage_location[0];
        }
        break;
      case 2: {    //Design of home page 2
          lcd.clear();
          lcd.setCursor(0, 1);
          lcd.print("*");
          lcd.setCursor(2, 0);
          lcd.print("1-50");
          lcd.setCursor(2, 1);
          lcd.print("51-75");
          normal_heat_percentage = heat_percentage_location[1];
        }
        break;
      case 3: {    //Design of home page 3
          lcd.clear();
          lcd.setCursor(0, 1);
          lcd.print("*");
          lcd.setCursor(2, 0);
          lcd.print("51-75");
          lcd.setCursor(2, 1);
          lcd.print("76-100");
          normal_heat_percentage = heat_percentage_location[2];
        }
        break;
      case 4: {    //Design of home page 3
          lcd.clear();
          lcd.setCursor(0, 1);
          lcd.print("*");
          lcd.setCursor(2, 0);
          lcd.print("76-100");
          lcd.setCursor(2, 1);
          lcd.print("101-125");
          normal_heat_percentage = heat_percentage_location[3];
        }
        break;
      case 5: {    //Design of home page 3
          lcd.clear();
          lcd.setCursor(0, 1);
          lcd.print("*");
          lcd.setCursor(2, 0);
          lcd.print("101-125");
          lcd.setCursor(2, 1);
          lcd.print("126-150");
          normal_heat_percentage = heat_percentage_location[4];
        }
        break;
      case 6: {    //Design of home page 3
          lcd.clear();
          lcd.setCursor(0, 1);
          lcd.print("*");
          lcd.setCursor(2, 0);
          lcd.print("126-150");
          lcd.setCursor(2, 1);
          lcd.print("151-175");
          normal_heat_percentage = heat_percentage_location[5];
        }
        break;
      case 7: {    //Design of home page 3
          lcd.clear();
          lcd.setCursor(0, 1);
          lcd.print("*");
          lcd.setCursor(2, 0);
          lcd.print("151-175");
          lcd.setCursor(2, 1);
          lcd.print("176-200");
          normal_heat_percentage = heat_percentage_location[6];
        }
        break;
      case 8: {    //Design of home page 3
          lcd.clear();
          lcd.setCursor(0, 1);
          lcd.print("*");
          lcd.setCursor(2, 0);
          lcd.print("176-200");
          lcd.setCursor(2, 1);
          lcd.print("201-225");
          normal_heat_percentage = heat_percentage_location[7];
        }
        break;
      case 9: {    //Design of home page 3
          lcd.clear();
          lcd.setCursor(0, 1);
          lcd.print("*");
          lcd.setCursor(2, 0);
          lcd.print("201-225");
          lcd.setCursor(2, 1);
          lcd.print("226-250");
          normal_heat_percentage = heat_percentage_location[8];
        }
        break;
      case 10: {    //Design of home page 3
          lcd.clear();
          lcd.setCursor(0, 1);
          lcd.print("*");
          lcd.setCursor(2, 0);
          lcd.print("226-250");
          lcd.setCursor(2, 1);
          lcd.print("251-275");
          normal_heat_percentage = heat_percentage_location[9];
        }
        break;
      case 11: {    //Design of home page 3
          lcd.clear();
          lcd.setCursor(0, 1);
          lcd.print("*");
          lcd.setCursor(2, 0);
          lcd.print("251-275");
          lcd.setCursor(2, 1);
          lcd.print("276-300");
          normal_heat_percentage = heat_percentage_location[10];
        }
        break;
      case 12: {    //Design of home page 3
          lcd.clear();
          lcd.setCursor(0, 1);
          lcd.print("*");
          lcd.setCursor(2, 0);
          lcd.print("276-300");
          lcd.setCursor(2, 1);
          lcd.print("301-325");
          normal_heat_percentage = heat_percentage_location[11];
        }
        break;
      case 13: {    //Design of home page 3
          lcd.clear();
          lcd.setCursor(0, 1);
          lcd.print("*");
          lcd.setCursor(2, 0);
          lcd.print("301-325");
          lcd.setCursor(2, 1);
          lcd.print("326-350");
          normal_heat_percentage = heat_percentage_location[12];
        }
        break;
      case 14: {    //Design of home page 3
          lcd.clear();
          lcd.setCursor(0, 1);
          lcd.print("*");
          lcd.setCursor(2, 0);
          lcd.print("326-350");
          lcd.setCursor(2, 1);
          lcd.print("351-375");
          normal_heat_percentage = heat_percentage_location[13];
        }
        break;
      case 15: {    //Design of home page 3
          lcd.clear();
          lcd.setCursor(0, 1);
          lcd.print("*");
          lcd.setCursor(2, 0);
          lcd.print("351-375");
          lcd.setCursor(2, 1);
          lcd.print("376-400");
          normal_heat_percentage = heat_percentage_location[14];
        }
        break;

    }
    int enter = digitalRead(enter_button);
    int up = digitalRead(up_buttonPin);                             // down_buttonPin key
    int down = digitalRead(down_buttonPin);                           // down key
    if (enter == 1) {
      digitalWrite(buzzerpin, HIGH);
      delay(20);
      digitalWrite(buzzerpin, LOW);
      set_heat_percentage_flag = true;
      service_flag = false;
      set_heat_percentage(normal_heat_percentage);
    }
    if (digitalRead(7) == 1) {
      service_flag = false;
      correctPasswordflag = true;
      digitalWrite(buzzerpin, HIGH);
      delay(20);
      digitalWrite(buzzerpin, LOW);
      correctPassword();
    }
  }
}
