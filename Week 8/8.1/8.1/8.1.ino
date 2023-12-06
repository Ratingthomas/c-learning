// C++ code
//

const int LED1 = 13;
const int ON_BTN = 12;
const int OFF_BTN = 11;

const int DEBOUNCE_TIME = 50;

void setup()
{
  pinMode(LED1, OUTPUT);
  pinMode(ON_BTN, INPUT_PULLUP);
  pinMode(OFF_BTN, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop()
{
  static bool led_on = false;
  
  bool on_btn_pressed = on_button_pressed();
  bool off_btn_pressed = off_button_pressed();
  
  if(on_btn_pressed){
 	  led_on = true;
  }
  else if(off_btn_pressed == true){
 	  led_on = false;
  }
  
  
  if(led_on == false){
  	digitalWrite(LED1, LOW);
  }
  else{
  	digitalWrite(LED1, HIGH);
  }

  // Serial.println(new_time);
  // Serial.println(new_time);
}

/// Stateful function to detect whether the ON button was pressed.
/// Returns true once for each time the button was pressed, false otherwise.
/// @return true if a new button press was detected since the last call to this function, false otherwise
bool on_button_pressed(){
  static bool old_state;
  static unsigned long prev_time;
  const char value = digitalRead(ON_BTN);
  unsigned long current_time = millis(); // save current time in time
  
  if (value != old_state && current_time - prev_time > DEBOUNCE_TIME){
    old_state = value;
    prev_time = current_time;

    if(value == true){
      return true;
    }
  }
  else{
  	return false;
  }
}

/// Stateful function to detect whether the OFF button was pressed.
/// Returns true once for each time the button was pressed, false otherwise.
/// @return true if a new button press was detected since the last call to this function, false otherwise
bool off_button_pressed(){
  static bool old_state;
  static unsigned long prev_time;
  const char value = digitalRead(OFF_BTN);
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