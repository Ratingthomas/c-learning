const int TOGGLE_BTN = 11;
const int SELECT_BTN = 12;
const int DEBOUNCE_TIME = 50;

const int PIN_LCD_1 = 2;
const int PIN_LCD_2 = 3;
const int PIN_LCD_3 = 4;
const int PIN_LCD_4 = 5;
const int PIN_LCD_5 = 6;
const int PIN_LCD_6 = 7;
const int PIN_LCD_7 = 8;
const int PIN_LCD_8 = 9;

const int PINS[8] = {PIN_LCD_1, PIN_LCD_2, PIN_LCD_3, PIN_LCD_4, PIN_LCD_5, PIN_LCD_6, PIN_LCD_7, PIN_LCD_8};

const bool options[6][8] = {
    {1, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 0, 1, 1, 1, 0, 0},
    {1, 0, 0, 1, 0, 1, 0, 1},
    {0, 0, 0, 1, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 0, 0, 0},
    {1, 0, 0, 0, 0, 0, 0, 0},
 };

void setup() {
  // put your setup code here, to run once:
  pinMode(TOGGLE_BTN, INPUT_PULLUP);
  pinMode(SELECT_BTN, INPUT_PULLUP);
  Serial.begin(9600);

  digitalWrite(PIN_LCD_1, HIGH);
  digitalWrite(PIN_LCD_2, LOW);
  digitalWrite(PIN_LCD_3, LOW);
  digitalWrite(PIN_LCD_4, LOW);
  digitalWrite(PIN_LCD_5, LOW);
  digitalWrite(PIN_LCD_6, LOW);
  digitalWrite(PIN_LCD_7, LOW);
  digitalWrite(PIN_LCD_8, HIGH);
}

void loop() {
  static int segment = 0;
  Serial.println("New loop");

  if(toggle_button_pressed()){
    Serial.println("Toggle");
  }
  else if(select_button_pressed()){
    Serial.println("Select");
    if(segment == 5){
      segment = 0;
    }
    else{
      segment = segment + 1;
    }
  }
  else{
    blink_segment(segment, 1000);
  }

  //
}

/// Stateful function to detect whether the TOGGLE button was pressed.
/// Returns true once for each time the button was pressed, false otherwise.
/// @return true if a new button press was detected since the last call to this function, false otherwise
bool toggle_button_pressed(){
    static bool old_state;
    static unsigned long prev_time;
    const char value = digitalRead(TOGGLE_BTN);
    unsigned long current_time = millis(); // save current time in time
    
    if (value != old_state && current_time - prev_time > DEBOUNCE_TIME){
      old_state = value;
      prev_time = current_time;

      if(value == HIGH){
        return true;
      }
    }
    else{
      return false;
    }
}

/// Stateful function to detect whether the SELECT button was pressed.
/// Returns true once for each time the button was pressed, false otherwise.
/// @return true if a new button press was detected since the last call to this function, false otherwise
bool select_button_pressed(){
  static bool old_state;
  static unsigned long prev_time;
  const char value = digitalRead(SELECT_BTN);
  unsigned long current_time = millis(); // save current time in time
    
  if (value != old_state && current_time - prev_time > DEBOUNCE_TIME){
    old_state = value;
    prev_time = current_time;

    if(value == HIGH){
      return true;
    }
  }
  else{
    return false;
  }
}

void blink_segment(int segment, int duration){
  unsigned long time = millis();

  while((millis() - time) <= duration){
    for (int i = 0; i < 8; ++i){
      // digitalWrite(PINS[i], HIGH);
      change_pin_status(PINS[i], i, segment);
    }   
  }

  time = millis();
  while((millis() - time) <= duration){
    for (int i = 0; i < 8; ++i){
      digitalWrite(PINS[i], LOW);
    }   
  }



  // for (int i = 0; i < 8; ++i){
  //   change_pin_status(PINS[i], i, segment);
  // }

  Serial.print("Blink");
  Serial.println(segment);
}

void change_pin_status(int pin, int option, int segment){
  if(options[segment][option] == true){
    digitalWrite(pin, HIGH);
  }
  else{
    digitalWrite(pin, LOW);
  }
}