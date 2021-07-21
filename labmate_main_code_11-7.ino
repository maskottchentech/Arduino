#include <Adafruit_MAX31865.h>

// Use software SPI: CS, DI, DO, CLK
Adafruit_MAX31865 thermo = Adafruit_MAX31865(8, 11, 12, 13);
// use hardware SPI, just pass in the CS pin
//Adafruit_MAX31865 thermo = Adafruit_MAX31865(10);

// The value of the Rref resistor. Use 430.0 for PT100 and 4300.0 for PT1000
#define RREF      430.0
// The 'nominal' 0-degrees-C resistance of the sensor
// 100.0 for PT100, 1000.0 for PT1000
#define RNOMINAL  100.0

#include <EEPROM.h>
#include <avr/eeprom.h>
#include <Wire.h>//-
#include <RTClib.h>//-
#include <LiquidCrystal_I2C.h>
#include <RBDdimmer.h>
dimmerLamp dimmer4(9);
LiquidCrystal_I2C lcd(0x27, 16, 2);  //I2C address 0x27, 16 column and 2 rows
RTC_DS1307 RTC;//-
int count = 0;//-
//pt100 start
float in[] = {  100.00, 100.39, 100.78, 101.17, 101.56, 101.95, 102.34, 102.73, 103.12, 103.51,
                103.90, 104.29, 104.68, 105.07, 105.46, 105.85, 106.24, 106.63, 107.02, 107.40,
                107.79, 108.18, 108.57, 108.96, 109.35, 109.73, 110.12, 110.51, 110.90, 111.29,
                111.67, 112.06, 112.45, 112.83, 113.22, 113.61, 114.00, 114.38, 114.77, 115.15,
                115.54, 115.93, 116.31, 116.70, 117.08, 117.47, 117.86, 118.24, 118.63, 119.01,
                119.40, 119.78, 120.17, 120.55, 120.94, 121.32, 121.71, 122.09, 122.47, 122.86,
                123.24, 123.63, 124.01, 124.39, 124.78, 125.16, 125.54, 125.93, 126.31, 126.69,
                127.08, 127.46, 127.84, 128.22, 128.61, 128.99, 129.37, 129.75, 130.13, 130.52,
                130.90, 131.28, 131.66, 132.04, 132.42, 132.80, 133.18, 133.57, 133.95, 134.33,
                134.71, 135.09, 135.47, 135.85, 136.23, 136.61, 136.99, 137.37, 137.75, 138.13,
                138.51, 138.88, 139.26, 139.64, 140.02, 140.40, 140.78, 141.16, 141.54, 141.91,
                142.29, 142.67, 143.05, 143.43, 143.80, 144.18, 144.56, 144.94, 145.31, 145.69,
                146.07, 146.44, 146.82, 147.20, 147.57, 147.95, 148.33, 148.70, 149.08, 149.46,
                149.83, 150.21, 150.58, 150.96, 151.33, 151.71, 152.08, 152.46, 152.83, 153.21,
                153.58, 153.96, 154.33, 154.71, 155.08, 155.46, 155.83, 156.20, 156.58, 156.95,
                157.33, 157.70, 158.07, 158.45, 158.82, 159.19, 159.56, 159.94, 160.31, 160.68,
                161.05, 161.43, 161.80, 162.17, 162.54, 162.91, 163.29, 163.66, 164.03, 164.40, 164.77
             };
float in2[] =  { 165.14, 165.51, 165.89, 166.26, 166.63, 167.00, 167.37, 167.74, 168.11,
                 168.48, 168.85, 169.22, 169.59, 169.96, 170.33, 170.70, 171.07, 171.43, 171.80,
                 172.17, 172.54, 172.91, 173.28, 173.65, 174.02, 174.38, 174.75, 175.12, 175.49,
                 175.86, 176.22, 176.59, 176.96, 177.33, 177.69, 178.06, 178.43, 178.79, 179.16,
                 179.53, 179.89, 180.26, 180.63, 180.99, 181.36, 181.72, 182.09, 182.46, 182.82,
                 183.19, 183.55, 183.92, 184.28, 184.65, 185.01, 185.38, 185.74, 186.11, 186.47,
                 186.84, 187.20, 187.56, 187.93, 188.29, 188.66, 189.02, 189.38, 189.75, 190.11,
                 190.47, 190.84, 191.20, 191.56, 191.92, 192.29, 192.65, 193.01, 193.37, 193.74,
                 194.10, 194.46, 194.82, 195.18, 195.55, 195.91, 196.27, 196.63, 196.99, 197.35,
                 197.71, 198.07, 198.43, 198.79, 199.15, 199.51, 199.87, 200.23, 200.59, 200.95,
                 201.31, 201.67, 202.03, 202.39, 202.75, 203.11, 203.47, 203.83, 204.19, 204.55,
                 204.90, 205.26, 205.62, 205.98, 206.34, 206.70, 207.05, 207.41, 207.77, 208.13,
                 208.48, 208.84, 209.20, 209.56, 209.91, 210.27, 210.63, 210.98, 211.34, 211.70,
                 212.05, 212.41, 212.76, 213.12, 213.48, 213.83, 214.19, 214.54, 214.90, 215.25,
                 215.61, 215.96, 216.32, 216.67, 217.03, 217.38, 217.74, 218.09, 218.44, 218.80,
                 219.15, 219.51, 219.86, 220.21, 220.57, 220.92, 221.27, 221.63, 221.98, 222.33,
                 222.68, 223.04, 223.39, 223.74, 224.09, 224.45, 224.80, 225.15, 225.50, 225.85,
                 226.21, 226.56, 226.91, 227.26, 227.61, 227.96, 228.31, 228.66, 229.02, 229.37,
                 229.72, 230.07, 230.42, 230.77, 231.12, 231.47, 231.82, 232.17, 232.52, 232.87,
                 233.21, 233.56, 233.91, 234.26, 234.61, 234.96, 235.31, 235.66, 236.00, 236.35,
                 236.70, 237.05, 237.40, 237.74, 238.09, 238.44, 238.79, 239.13, 239.48, 239.83,
                 240.18, 240.52, 240.87, 241.22, 241.56, 241.91, 242.26, 242.60, 242.95, 243.29,
                 243.64, 243.99, 244.33, 244.68, 245.02, 245.37, 245.71, 246.06, 246.40, 246.75,
                 247.09
               };

// known resistance in voltage divider
int R1 = 920;//-
float c;//-
float MultiMap(float val, float* _in)
{
  uint8_t pos = 0;
  while (val > _in[pos]) pos++;
  // handles the 'rare' equality case
  if (val == _in[pos]) return pos;
  float r1 = _in[pos - 1];
  float r2 = _in[pos];
  int c1 = pos - 1;
  int c2 = pos;
  return c1 + (val - r1) / (r2 - r1) * (c2 - c1);
}
float MultiMap2(float val, float* _in2)
{
  uint8_t pos = 0;
  while (val > _in2[pos]) pos++;
  if (val == _in2[pos]) return pos;
  float r1 = _in2[pos - 1];
  float r2 = _in2[pos];
  int c1 = pos - 1;
  int c2 = pos;
  return (c1 + (val - r1) / (r2 - r1) * (c2 - c1)) + 170;
}
//pt100 end
//variables for down_buttonPindating date time
int hourupg;//-
int minupg;//-
int yearupg;//-
int monthupg;//-
int dayupg;//-
int start_eeprom_address;//-
int last_eeprom_address;//-
int lastAddress;//-
/** the current address in the EEPROM (i.e. which byte we're going to write to next) **/
//address increment variable
int page_counter = 1 ;//-     //To move beetwen pages
int page_counter_heat_screen = 1 ; //-    //To move beetwen pages
int setTempAddr = 1;//-
int dateTimeAddr[6] = {2, 3, 4, 5, 6, 7}; //-                    //date time array
float calibration_value;
int calibration_address = 500;
float float_val;
//int Address = 46;                   //-                      // current temp address
//int dateTimearray[6];//-
int hours, minutes, seconds, days, months, years;//-

#define DS3231_I2C_ADDRESS 0x68//-
// Convert normal decimal numbers to binary coded decimal
byte decToBcd(byte val) {
  return ( (val / 10 * 16) + (val % 10) );
}
// Convert binary coded decimal to normal decimal numbers
byte bcdToDec(byte val) {
  return ( (val / 16 * 10) + (val % 16) );
}

//LiquidCrystal_I2C lcd(0x3F, 16, 2);                // set the LCD address to 0x3F for a 16 chars and 2 line display
const int enter_button = 3;   //-                       //the number of the pushbutton pin
const int up_buttonPin = 4;//-
const int down_buttonPin = 5;//-
const int start_parameter_button = 6;//-
const int back_button = 7;//-

int buzzerpin = 10;
int temp = 0;          //-                           //starting temp value
int tempcount = 0;      //-                          //down_buttonPindated temp value
int downCount = 0;//-
int upCount = 0;//-
int password = 0;//-
int password1 = 0;  //-                              //first integer of password
int password2 = 0;  //-                              //second integer of password
int password3 = 0;  //-                              //third integer of password
int normal_heat_percentage;//-
bool firstscreenflag = true; //-                     // first screen flag
bool secondscreenflag1 = true;//-
bool secondscreenflag2 = true;//-
bool secondscreenflag3 = false;//-
bool secondscreenflag4 = false;//-
bool secondscreenflag5 = false;//-
bool secondscreenflag6 = false;//-
bool set_heat_percentage_flag = false;//-
bool password2flag = false;//-
bool password3flag = false;//-
bool correctPasswordflag = false;//-
bool WrongPasswordflag = false;//-
bool normal_heat_flag = false;//-
bool medium_heat_flag = false;//-
bool fast_heat_flag = false;//-
bool normal_heat_flag_service = false;//-
bool medium_heat_flag_service = false;//-
bool fast_heat_flag_service = false;//-
bool service_flag = false;//-
bool upflag  = false;//-
bool dwnflag = false;//-
bool entryflag1 = false;
bool entryflag2 = false;
bool entryflag3 = false;
bool entryflag4 = false;
bool entryflag5 = false;
bool entryflag6 = false;
bool entryflag7 = false;
bool entryflag8 = false;
bool entryflag9 = false;
bool entryflag10 = false;
bool dimmer_flag = false;
bool printflag = false;
bool main_menu_flag = false;
bool calibration_flag = false;
//int led = 13;
int buzzer = 7;//-
int store;//-

int buzzerTime = 0;//-
int cuttOffTime = 0;//-
//-------Pins-----//
int up = 5;            //-   //down_buttonPin button
int down = 4;       //-    //Down button
//---------Storage debounce function-----//
//boolean current_up = LOW;//-
boolean last_up = LOW;//-
boolean last_down = LOW;//-
boolean current_down = LOW;//-

boolean SetBuzzer = false;//-
boolean SetCuttOffHeat = false;//-

int up_State = 0, down_State = 0;
int count_value = 0;
int prestate = 0;

void setup() {

  dimmer4.begin(NORMAL_MODE, OFF);

  Serial.begin(115200);
  thermo.begin(MAX31865_3WIRE);  // set to 2WIRE or 4WIRE as necessary
  Wire.begin();
  lcd.init(); // initialize the lcd

  lcd.backlight();
  pinMode(A0, INPUT);

  //dimmer4.begin(NORMAL_MODE, ON); //dimmer initialisation: name.begin(MODE, STATE)
  //dimmer4.begin(NORMAL_MODE, OFF); //dimmer initialisation: name.begin(MODE, STATE)

  //pt100_function();

  //  pinMode(led, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(enter_button, INPUT);
  pinMode(up_buttonPin, INPUT);
  pinMode(down_buttonPin, INPUT);
  pinMode(start_parameter_button, INPUT);
  pinMode(buzzerpin, OUTPUT);
  pinMode(back_button, INPUT);
  RTC.begin();

  if (! RTC.isrunning()) {
    Serial.println("RTC is NOT running!");
    // Set the date and time at compile time
    RTC.adjust(DateTime(__DATE__, __TIME__));
  }

  int8_t calibration_value = EEPROM.read(calibration_address);          //calibration value
  float_val = calibration_value ;
  float_val = float_val / 10;
  //RTC.adjust(DateTime(__DATE__, __TIME__)); //removing "//" to adjust the time
  // The default display shows the date and time
  lcd.clear();
  lcd.setCursor(6, 0);
  lcd.print("SSS");
  lcd.setCursor(5, 1);
  lcd.print("MP BP");
  delay(2000);
}

//---- De-bouncing function for all buttons----//
boolean debounce(boolean last, int pin)
{
  boolean current = digitalRead(pin);
  if (last != current)
  {
    delay(20);
    current = digitalRead(pin);
  }
  return current;
}

void loop() {
  main_menu_flag = true;
  main_menu();
}                                              // end of void loop

void main_menu() {
  //Serial.println(calibration_value);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(" MP-BP Test App");
  lcd.setCursor(2, 1);
  lcd.print("Temp  ");
  lcd.setCursor(8, 1);
  int8_t calibration_value = EEPROM.read(calibration_address);          //calibration value
  float_val = calibration_value ;
  float_val = float_val / 10;
  lcd.print(thermo.temperature(RNOMINAL, RREF) + float_val);
  while (main_menu_flag == true) {
    //pt_100();
    //float curr_temp = pt100_function();
    lcd.setCursor(8, 1);
    lcd.print(thermo.temperature(RNOMINAL, RREF) + float_val);
    int enter = digitalRead(enter_button);
    if (enter == 1) {
      main_menu_flag = false;
      secondscreenflag1 = true;
      digitalWrite(buzzerpin, HIGH);
      delay(20);
      digitalWrite(buzzerpin, LOW);
      secondscreen1();
    }
    if (digitalRead(start_parameter_button) == 1) {
      main_menu_flag = false;
      firstscreenflag = true;
      digitalWrite(buzzerpin, HIGH);
      delay(20);
      digitalWrite(buzzerpin, LOW);
      firstscreen();
    }
  }

  delay(200);
}

void firstscreen() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("*");
  upflag = true;
  lcd.setCursor(1, 0);
  lcd.print("AT  D&T  Data");
  lcd.setCursor(1, 1);
  lcd.print("Cal  Service");
  SetBuzzer = true;
  delay(100);
  while (firstscreenflag == true) {
    boolean current_up = debounce(last_up, down_buttonPin);         //Debounce for down_buttonPin button
    current_down = debounce(last_down, down);   //Debounce for Down button

    //----Page counter function to move pages----//

    //Page down_buttonPin
    if (last_up == LOW && current_up == HIGH) { //When up button is pressed
      digitalWrite(buzzerpin, HIGH);
      delay(20);
      digitalWrite(buzzerpin, LOW);
      //When page is changed, lcd clear to print new page
      if (page_counter < 5) {           //Page counter never higher than 3(total of pages)
        page_counter = page_counter + 1; //Page up

      }
      else {
        page_counter = 5;
      }
    }

    last_up = current_up;

    //Page Down
    if (last_down == LOW && current_down == HIGH) { //When down button is pressed
      digitalWrite(buzzerpin, HIGH);
      delay(20);
      digitalWrite(buzzerpin, LOW);
      //When page is changed, lcd clear to print new page
      if (page_counter > 1) {           //Page counter never lower than 1 (total of pages)
        page_counter = page_counter - 1; //Page down

      }
      else {
        page_counter = 1;
      }
    }

    last_down = current_down;

    //------- Switch function to write and show what you want---//
    switch (page_counter) {

      case 1: {    //Design of home page 1
          //lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("*");
          lcd.setCursor(4, 0);
          lcd.print(" ");
          lcd.setCursor(9, 0);
          lcd.print(" ");
          lcd.setCursor(0, 1);
          lcd.print(" ");
          lcd.setCursor(5, 1);
          lcd.print(" ");
          SetBuzzer = true;
          secondscreenflag3 = false;
          secondscreenflag6 = false;
          calibration_flag = false;
          secondscreenflag5 = false;
        }
        break;

      case 2: { //Design of page 2
          //lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print(" ");
          lcd.setCursor(4, 0);
          lcd.print("*");
          lcd.setCursor(9, 0);
          lcd.print(" ");
          lcd.setCursor(0, 1);
          lcd.print(" ");
          lcd.setCursor(5, 1);
          lcd.print(" ");
          //delay(100);
          SetBuzzer = false;
          secondscreenflag6 = true;
          secondscreenflag3 = false;
          calibration_flag = false;
          secondscreenflag5 = false;
        }
        break;

      case 3: {   //Design of page 3
          //lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print(" ");
          lcd.setCursor(4, 0);
          lcd.print(" ");
          lcd.setCursor(9, 0);
          lcd.print("*");
          lcd.setCursor(0, 1);
          lcd.print(" ");
          lcd.setCursor(5, 1);
          lcd.print(" ");
          //delay(100);
          SetBuzzer = false;
          secondscreenflag3 = true;
          secondscreenflag6 = false;
          calibration_flag = false;
          secondscreenflag5 = false;
        }
        break;

      case 4: {   //Design of page 3
          lcd.setCursor(0, 0);
          lcd.print(" ");
          lcd.setCursor(4, 0);
          lcd.print(" ");
          lcd.setCursor(9, 0);
          lcd.print(" ");
          lcd.setCursor(0, 1);
          lcd.print("*");
          lcd.setCursor(5, 1);
          lcd.print(" ");
          //delay(100);
          SetBuzzer = false;
          secondscreenflag3 = false;
          secondscreenflag6 = false;
          calibration_flag = true;
          secondscreenflag5 = false;
        }
        break;

      case 5: {   //Design of page 3
          lcd.setCursor(0, 0);
          lcd.print(" ");
          lcd.setCursor(4, 0);
          lcd.print(" ");
          lcd.setCursor(9, 0);
          lcd.print(" ");
          lcd.setCursor(0, 1);
          lcd.print(" ");
          lcd.setCursor(5, 1);
          lcd.print("*");
          //delay(100);
          SetBuzzer = false;
          secondscreenflag3 = false;
          secondscreenflag6 = false;
          calibration_flag = false;
          secondscreenflag5 = true;
        }
        break;
    }                                                    //switch end
    int enter = digitalRead(enter_button);                             // enter key
    int start = digitalRead(start_parameter_button);                             // start
    if (enter == 1) {
      digitalWrite(buzzerpin, HIGH);
      delay(20);
      digitalWrite(buzzerpin, LOW);
      firstscreenflag = false;

      if (SetBuzzer == true) {
        Buzzer();
      }
      if (secondscreenflag3 == true) {
        secondscreen3();
      }
      if (secondscreenflag5 == true) {
        secondscreen5();
      }
      if (secondscreenflag6 == true) {
        timeupdate();
      }
      if (calibration_flag = true) {
        calibration();
      }
    }
    if (digitalRead(back_button) == 1) {
      firstscreenflag = false;
      main_menu_flag = true;
      main_menu();
    }
  }
}                                                         // end of while

// end of void firstscreen

void secondscreen1() {
  lcd.clear();
  lcd.setCursor(1, 0);
  lcd.print(" Expected Temp ");
  delay(100);
  while (secondscreenflag1 == true) {
    delay(100);
    int enter, back;
    lcd.setCursor(6, 1);
    lcd.print(temp);
    if (digitalRead(up_buttonPin) == 1) {
      temp++;
      digitalWrite(buzzerpin, HIGH);
      delay(20);
      digitalWrite(buzzerpin, LOW);
      if (temp >= 400) {
        temp = 400;
      }
    }
    else if (digitalRead(down_buttonPin) == 1) {
      temp--;
      digitalWrite(buzzerpin, HIGH);
      delay(20);
      digitalWrite(buzzerpin, LOW);
      if (temp <= 0)
        temp = 0;
    }
    enter = digitalRead(enter_button);
    if (enter == 1) {
      if (temp > 0 ) {
        digitalWrite(buzzerpin, HIGH);
        delay(20);
        digitalWrite(buzzerpin, LOW);
        //temp = tempcount;
        //tempcount = 0;
        lcd.clear();
        secondscreenflag2 = true;
        secondscreenflag1 = false;
        secondscreen2();
      }
    }
    back = digitalRead(back_button);
    if (back == 1) {
      digitalWrite(buzzerpin, HIGH);
      delay(20);
      digitalWrite(buzzerpin, LOW);
      secondscreenflag1 = false;
      main_menu_flag = true;
      main_menu();
    }


  }                                                           // end of while
}                                                             //end of secondscreen1

void secondscreen2() {
  lcd.clear();
  lcd.setCursor(3, 0);
  lcd.print("Set Heating");
  lcd.setCursor(0, 1);
  lcd.print("*");
  delay(100);
  // normal_heat_flag = true;
  fast_heat_flag = false;
  medium_heat_flag = false;
  normal_heat_flag = false;
  while (secondscreenflag2 == true) {
    boolean current_up = debounce(last_up, up);         //Debounce for Up button
    current_down = debounce(last_down, down);   //Debounce for Down button

    //----Page counter function to move pages----//

    //Page Up
    if (last_up == LOW && current_up == HIGH) { //When up button is pressed
      digitalWrite(buzzerpin, HIGH);
      delay(20);
      digitalWrite(buzzerpin, LOW);
      //lcd.clear();                     //When page is changed, lcd clear to print new page
      if (page_counter_heat_screen < 3) {           //Page counter never higher than 3(total of pages)
        page_counter_heat_screen = page_counter_heat_screen + 1; //Page up

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
      //lcd.clear();                     //When page is changed, lcd clear to print new page
      if (page_counter_heat_screen > 1) {           //Page counter never lower than 1 (total of pages)
        page_counter_heat_screen = page_counter_heat_screen - 1; //Page down

      }
      else {
        page_counter_heat_screen = 1;
      }
    }

    last_down = current_down;

    switch (page_counter_heat_screen) {

      case 1: {    //Design of home page 1
          lcd.setCursor(0, 1);
          lcd.print("*");
          lcd.setCursor(2, 1);
          lcd.print("normal heat");
          delay(80);
          normal_heat_flag = true;
          medium_heat_flag = false;
          fast_heat_flag = false;
        }
        break;
      case 2: {
          lcd.setCursor(0, 1);
          lcd.print("*");
          lcd.setCursor(2, 1);
          lcd.print("medium heat");
          delay(80);
          normal_heat_flag = false;
          medium_heat_flag = true;
          fast_heat_flag = false;
        }
        break;
      case 3: {
          lcd.setCursor(0, 1);
          lcd.print("*");
          lcd.setCursor(2, 1);
          lcd.print("fast heat    ");
          delay(80);
          normal_heat_flag = false;
          medium_heat_flag = false;
          fast_heat_flag = true;
        }
        break;
    }
    int enter = digitalRead(enter_button);                             // enter key
    if (enter == 1) {
      digitalWrite(buzzerpin, HIGH);
      delay(20);
      digitalWrite(buzzerpin, LOW);
      dimmer_flag = true;
      secondscreenflag2 = false;
      dimmer1();
    }
    int back = digitalRead(back_button);                             // enter key
    if (back == 1) {
      secondscreenflag2 = false;
      secondscreenflag1 = true;
      secondscreen1();
    }
    delay(50);
  }                                                       //end of while loop
}                                                         //end of secondscreen2

void secondscreen3() {
  lcd.clear();
  lcd.setCursor(2, 0);
  lcd.print(" Time   Date");
  delay(150);
  boolean current_up = LOW;
  last_up = LOW;
  last_down = LOW;
  current_down = LOW;
  int page_counter4 = 1 ;     //To move beetwen pages
  while (secondscreenflag3 == true) {
    delay(100);
    current_up = debounce(last_up, up);         //Debounce for Up button
    current_down = debounce(last_down, down);   //Debounce for Down button

    //----Page counter function to move pages----//

    //Page Up
    if (last_up == LOW && current_up == HIGH) { //When up button is pressed
      digitalWrite(buzzerpin, HIGH);
      delay(20);
      digitalWrite(buzzerpin, LOW);
      //lcd.clear();                     //When page is changed, lcd clear to print new page
      if (page_counter4 < 10) {           //Page counter never higher than 3(total of pages)
        page_counter4 = page_counter4 + 1; //Page up

      }
      else {
        page_counter4 = 10 ;
      }
    }

    last_up = current_up;

    //Page Down
    if (last_down == LOW && current_down == HIGH) { //When down button is pressed
      digitalWrite(buzzerpin, HIGH);
      delay(20);
      digitalWrite(buzzerpin, LOW);
      //lcd.clear();                     //When page is changed, lcd clear to print new page
      if (page_counter4 > 1) {           //Page counter never lower than 1 (total of pages)
        page_counter4 = page_counter4 - 1; //Page down

      }
      else {
        page_counter4 = 1;
      }
    }

    last_down = current_down;

    //------- Switch function to write and show what you want---//
    switch (page_counter4) {

      case 1: {    //Design of home page 1
          //          lcd.clear();
          lcd.setCursor(0, 1);
          lcd.print("1)");
          lcd.setCursor(2, 1);
          lcd.print("              ");
          //          lcd.setCursor(2, 0);
          //          lcd.print(" Time   Date");
          lcd.setCursor(3, 1);
          lcd.print(EEPROM.read(50));
          lcd.setCursor(5, 1);
          lcd.print(":");
          lcd.setCursor(6, 1);
          lcd.print(EEPROM.read(51));
          lcd.setCursor(9, 1);
          lcd.print(EEPROM.read(52));
          lcd.setCursor(11, 1);
          lcd.print(":");
          lcd.setCursor(12, 1);
          lcd.print(EEPROM.read(53));
          lcd.setCursor(13, 1);
          lcd.print(":");
          lcd.setCursor(14, 1);
          lcd.print(EEPROM.read(54));
          int enter = digitalRead(enter_button);
          entryflag1 = true;
          entryflag2 = false;
          entryflag3 = false;
          entryflag4 = false;
          entryflag5 = false;
          entryflag6 = false;
          entryflag7 = false;
          entryflag8 = false;
          entryflag9 = false;
          entryflag10 = false;
          //lcd.print(EEPROM.read(dateTimeAddr[1]));
        }
        break;

      case 2: { //Design of page 2
          //lcd.clear();
          lcd.setCursor(0, 1);
          lcd.print("2)");
          lcd.setCursor(2, 1);
          lcd.print("              ");
          lcd.setCursor(3, 1);
          lcd.print(EEPROM.read(59));
          lcd.setCursor(5, 1);
          lcd.print(":");
          lcd.setCursor(6, 1);
          lcd.print(EEPROM.read(60));
          lcd.setCursor(6, 1);
          lcd.setCursor(9, 1);
          lcd.print(EEPROM.read(61));
          lcd.setCursor(11, 1);
          lcd.print(":");
          lcd.setCursor(12, 1);
          lcd.print(EEPROM.read(62));
          lcd.setCursor(13, 1);
          lcd.print(":");
          lcd.setCursor(14, 1);
          lcd.print(EEPROM.read(63));
          int enter = digitalRead(enter_button);
          entryflag1 = false;
          entryflag2 = true;
          entryflag3 = false;
          entryflag4 = false;
          entryflag5 = false;
          entryflag6 = false;
          entryflag7 = false;
          entryflag8 = false;
          entryflag9 = false;
          entryflag10 = false;
        }
        break;

      case 3: { //Design of page 2
          lcd.setCursor(2, 1);
          lcd.print("              ");
          lcd.setCursor(0, 1);
          lcd.print("3)");
          //          lcd.setCursor(2, 0);
          //          lcd.print(" Time   Date");
          lcd.setCursor(3, 1);
          lcd.print(EEPROM.read(68));
          lcd.setCursor(5, 1);
          lcd.print(":");
          lcd.setCursor(6, 1);
          lcd.print(EEPROM.read(69));
          lcd.setCursor(9, 1);
          lcd.print(EEPROM.read(70));
          lcd.setCursor(11, 1);
          lcd.print(":");
          lcd.setCursor(12, 1);
          lcd.print(EEPROM.read(71));
          lcd.setCursor(13, 1);
          lcd.print(":");
          lcd.setCursor(14, 1);
          lcd.print(EEPROM.read(72));
          int enter = digitalRead(enter_button);
          entryflag1 = false;
          entryflag2 = false;
          entryflag3 = true;
          entryflag4 = false;
          entryflag5 = false;
          entryflag6 = false;
          entryflag7 = false;
          entryflag8 = false;
          entryflag9 = false;
          entryflag10 = false;
        }
        break;
      case 4: {    //Design of home page 1
          lcd.setCursor(2, 1);
          lcd.print("              ");
          lcd.setCursor(0, 1);
          lcd.print("4)");
          //          lcd.setCursor(2, 0);
          //          lcd.print(" Time   Date");
          lcd.setCursor(3, 1);
          lcd.print(EEPROM.read(77));
          lcd.setCursor(5, 1);
          lcd.print(":");
          lcd.setCursor(6, 1);
          lcd.print(EEPROM.read(78));

          lcd.setCursor(9, 1);
          lcd.print(EEPROM.read(79));
          lcd.setCursor(11, 1);
          lcd.print(":");
          lcd.setCursor(12, 1);
          lcd.print(EEPROM.read(80));
          lcd.setCursor(13, 1);
          lcd.print(":");
          lcd.setCursor(14, 1);
          lcd.print(EEPROM.read(81));
          //lcd.print(EEPROM.read(dateTimeAddr[1]));
          int enter = digitalRead(enter_button);
          entryflag1 = false;
          entryflag2 = false;
          entryflag3 = false;
          entryflag4 = true;
          entryflag5 = false;
          entryflag6 = false;
          entryflag7 = false;
          entryflag8 = false;
          entryflag9 = false;
          entryflag10 = false;
        }
        break;

      case 5: { //Design of page 2
          lcd.setCursor(2, 1);
          lcd.print("              ");
          lcd.setCursor(0, 1);
          lcd.print("5)");
          //          lcd.setCursor(2, 0);
          //          lcd.print(" Time   Date");
          lcd.setCursor(3, 1);
          lcd.print(EEPROM.read(86));
          lcd.setCursor(5, 1);
          lcd.print(":");
          lcd.setCursor(6, 1);
          lcd.print(EEPROM.read(87));

          lcd.setCursor(9, 1);
          lcd.print(EEPROM.read(88));
          lcd.setCursor(11, 1);
          lcd.print(":");
          lcd.setCursor(12, 1);
          lcd.print(EEPROM.read(89));
          lcd.setCursor(13, 1);
          lcd.print(":");
          lcd.setCursor(14, 1);
          lcd.print(EEPROM.read(90));
          int enter = digitalRead(enter_button);
          entryflag1 = false;
          entryflag2 = false;
          entryflag3 = false;
          entryflag4 = false;
          entryflag5 = true;
          entryflag6 = false;
          entryflag7 = false;
          entryflag8 = false;
          entryflag9 = false;
          entryflag10 = false;
        }
        break;

      case 6: { //Design of page 2
          lcd.setCursor(2, 1);
          lcd.print("              ");
          lcd.setCursor(0, 1);
          lcd.print("6)");
          //          lcd.setCursor(2, 0);
          //          lcd.print(" Time   Date");
          lcd.setCursor(3, 1);
          lcd.print(EEPROM.read(95));
          lcd.setCursor(5, 1);
          lcd.print(":");
          lcd.setCursor(6, 1);
          lcd.print(EEPROM.read(96));

          lcd.setCursor(9, 1);
          lcd.print(EEPROM.read(97));
          lcd.setCursor(11, 1);
          lcd.print(":");
          lcd.setCursor(12, 1);
          lcd.print(EEPROM.read(98));
          lcd.setCursor(13, 1);
          lcd.print(":");
          lcd.setCursor(14, 1);
          lcd.print(EEPROM.read(99));
          int enter = digitalRead(enter_button);
          entryflag1 = false;
          entryflag2 = false;
          entryflag3 = false;
          entryflag4 = false;
          entryflag5 = false;
          entryflag6 = true;
          entryflag7 = false;
          entryflag8 = false;
          entryflag9 = false;
          entryflag10 = false;
        }
        break;
      case 7: {    //Design of home page 1
          lcd.setCursor(2, 1);
          lcd.print("              ");
          lcd.setCursor(0, 1);
          lcd.print("7)");
          //          lcd.setCursor(2, 0);
          //          lcd.print(" Time   Date");
          lcd.setCursor(3, 1);
          lcd.print(EEPROM.read(104));
          lcd.setCursor(5, 1);
          lcd.print(":");
          lcd.setCursor(6, 1);
          lcd.print(EEPROM.read(105));

          lcd.setCursor(9, 1);
          lcd.print(EEPROM.read(106));
          lcd.setCursor(11, 1);
          lcd.print(":");
          lcd.setCursor(12, 1);
          lcd.print(EEPROM.read(107));
          lcd.setCursor(13, 1);
          lcd.print(":");
          lcd.setCursor(14, 1);
          lcd.print(EEPROM.read(108));
          //lcd.print(EEPROM.read(dateTimeAddr[1]));
          int enter = digitalRead(enter_button);
          entryflag1 = false;
          entryflag2 = false;
          entryflag3 = false;
          entryflag4 = false;
          entryflag5 = false;
          entryflag6 = false;
          entryflag7 = true;
          entryflag8 = false;
          entryflag9 = false;
          entryflag10 = false;
        }
        break;

      case 8: { //Design of page 2
          lcd.setCursor(2, 1);
          lcd.print("              ");
          lcd.setCursor(0, 1);
          lcd.print("8)");
          //          lcd.setCursor(2, 0);
          //          lcd.print(" Time   Date");
          lcd.setCursor(3, 1);
          lcd.print(EEPROM.read(113));
          lcd.setCursor(5, 1);
          lcd.print(":");
          lcd.setCursor(6, 1);
          lcd.print(EEPROM.read(114));

          lcd.setCursor(9, 1);
          lcd.print(EEPROM.read(115));
          lcd.setCursor(11, 1);
          lcd.print(":");
          lcd.setCursor(12, 1);
          lcd.print(EEPROM.read(116));
          lcd.setCursor(13, 1);
          lcd.print(":");
          lcd.setCursor(14, 1);
          lcd.print(EEPROM.read(117));
          int enter = digitalRead(enter_button);
          entryflag1 = false;
          entryflag2 = false;
          entryflag3 = false;
          entryflag4 = false;
          entryflag5 = false;
          entryflag6 = false;
          entryflag7 = false;
          entryflag8 = true;
          entryflag9 = false;
          entryflag10 = false;
        }
        break;

      case 9: { //Design of page 2
          lcd.setCursor(2, 1);
          lcd.print("              ");
          lcd.setCursor(0, 1);
          lcd.print("9)");
          //          lcd.setCursor(2, 0);
          //          lcd.print(" Time   Date");
          lcd.setCursor(3, 1);
          lcd.print(EEPROM.read(122));
          lcd.setCursor(5, 1);
          lcd.print(":");
          lcd.setCursor(6, 1);
          lcd.print(EEPROM.read(123));

          lcd.setCursor(9, 1);
          lcd.print(EEPROM.read(124));
          lcd.setCursor(11, 1);
          lcd.print(":");
          lcd.setCursor(12, 1);
          lcd.print(EEPROM.read(125));
          lcd.setCursor(13, 1);
          lcd.print(":");
          lcd.setCursor(14, 1);
          lcd.print(EEPROM.read(126));
          int enter = digitalRead(enter_button);
          entryflag1 = false;
          entryflag2 = false;
          entryflag3 = false;
          entryflag4 = false;
          entryflag5 = false;
          entryflag6 = false;
          entryflag7 = false;
          entryflag8 = false;
          entryflag9 = true;
          entryflag10 = false;
        }
        break;
      case 10: { //Design of page 2
          lcd.setCursor(2, 1);
          lcd.print("              ");
          lcd.setCursor(0, 1);
          lcd.print("10)");
          //          lcd.setCursor(2, 0);
          //          lcd.print(" Time   Date");
          lcd.setCursor(3, 1);
          lcd.print(EEPROM.read(131));
          lcd.setCursor(5, 1);
          lcd.print(":");
          lcd.setCursor(6, 1);
          lcd.print(EEPROM.read(132));

          lcd.setCursor(9, 1);
          lcd.print(EEPROM.read(133));
          lcd.setCursor(11, 1);
          lcd.print(":");
          lcd.setCursor(12, 1);
          lcd.print(EEPROM.read(134));
          lcd.setCursor(13, 1);
          lcd.print(":");
          lcd.setCursor(14, 1);
          lcd.print(EEPROM.read(135));
          int enter = digitalRead(enter_button);
          entryflag1 = false;
          entryflag2 = false;
          entryflag3 = false;
          entryflag4 = false;
          entryflag5 = false;
          entryflag6 = false;
          entryflag7 = false;
          entryflag8 = false;
          entryflag9 = false;
          entryflag10 = true;
        }
        break;
    }

    int back = digitalRead(back_button);
    if (back == 1) {
      digitalWrite(buzzerpin, HIGH);
      delay(20);
      digitalWrite(buzzerpin, LOW);
      secondscreenflag3 = false;
      firstscreenflag = true;
      firstscreen();
    }

    if (digitalRead(enter_button) == 1) {
      digitalWrite(buzzerpin, HIGH);
      delay(20);
      digitalWrite(buzzerpin, LOW);
      secondscreenflag3 = false;
      print1();
    }

  }                                                       //end of while loop
}                                                         //end of secondscreen3

void secondscreen4() {
  boolean current_up = LOW;
  last_up = LOW;
  last_down = LOW;
  current_down = LOW;
  int page_counter4 = 1 ;     //To move beetwen pages
  buzzerTime = EEPROM.read(200);                          //read previous buzzerTime from memory
  cuttOffTime = EEPROM.read(201);                         //read previous cuttOffTime from memory
  while (secondscreenflag4 == true) {

    current_up = debounce(last_up, up);         //Debounce for Up button
    current_down = debounce(last_down, down);   //Debounce for Down button

    //----Page counter function to move pages----//

    //Page Up
    if (last_up == LOW && current_up == HIGH) { //When up button is pressed
      digitalWrite(buzzerpin, HIGH);
      delay(20);
      digitalWrite(buzzerpin, LOW);
      lcd.clear();                     //When page is changed, lcd clear to print new page
      if (page_counter4 < 2) {           //Page counter never higher than 3(total of pages)
        page_counter4 = page_counter4 + 1; //Page up

      }
      else {
        page_counter4 = 2;
      }
    }

    last_up = current_up;

    //Page Down
    if (last_down == LOW && current_down == HIGH) { //When down button is pressed
      digitalWrite(buzzerpin, HIGH);
      delay(20);
      digitalWrite(buzzerpin, LOW);
      lcd.clear();                     //When page is changed, lcd clear to print new page
      if (page_counter4 > 1) {           //Page counter never lower than 1 (total of pages)
        page_counter4 = page_counter4 - 1; //Page down

      }
      else {
        page_counter4 = 1;
      }
    }

    last_down = current_down;

    //------- Switch function to write and show what you want---//
    switch (page_counter4) {

      case 1: {    //Design of home page 1
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("*");
          lcd.setCursor(2, 0);
          lcd.print("Set Buzzer");
          lcd.setCursor(14, 0);
          lcd.print(buzzerTime);
          lcd.setCursor(2, 1);
          lcd.print("Cut temp");
          lcd.setCursor(14, 1);
          lcd.print(cuttOffTime);
          delay(200);
          SetBuzzer = true;
          SetCuttOffHeat = false;
        }
        break;

      case 2: { //Design of page 2
          lcd.clear();
          lcd.setCursor(0, 1);
          lcd.print("*");
          lcd.setCursor(2, 0);
          lcd.print("Set Buzzer");
          lcd.setCursor(14, 0);
          lcd.print(buzzerTime);
          lcd.setCursor(2, 1);
          lcd.print("Cut temp");
          lcd.setCursor(14, 1);
          lcd.print(cuttOffTime);
          delay(200);
          SetCuttOffHeat = true;
          SetBuzzer = false;
        }
        break;
    }
    int    enter = digitalRead(enter_button);                             // enter key
    if (enter == 1) {
      if (SetBuzzer = true) {
        digitalWrite(buzzerpin, HIGH);
        delay(20);
        digitalWrite(buzzerpin, LOW);

        Buzzer();
      }
      if (SetCuttOffHeat = true) {

        cutOff();
      }
    }
  }                                                       //end of while loop
}
//end of secondscreen4
