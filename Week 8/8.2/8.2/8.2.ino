const int LED1 = 13;
const int ON_BTN = 12;
const int DEBOUNCE_TIME = 50;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED1, OUTPUT);
  pinMode(ON_BTN, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  static bool led_on = false;
  
  static bool old_state;
  static unsigned long prev_time;
  unsigned long current_time = millis(); // save current time in time
  
  int value = button_pressed_time();

  if (value != old_state && current_time - prev_time > DEBOUNCE_TIME){
    

    if(value <= 1000 && led_on == false){
      led_on = true;
      digitalWrite(LED1, HIGH);
      Serial.println("Changing state to true");
    }
    else if(value >= 1000 && led_on == true){
      led_on = false;
      digitalWrite(LED1, LOW);
      Serial.println("Changing state to false");
    }

    value = 0;

    old_state = value;
    prev_time = current_time;
  }
  
}

/// Stateful function that returns the number of milliseconds the button was kept pressed
/// before it was released.
/// Returns a value once each time the button was released.
/// @return The time the button was kept pressed before it was released, in milliseconds, or -1 if no button release was detected since the last call to this function.
int button_pressed_time(){
  int value = digitalRead(ON_BTN);
  
  if(value == LOW){
    unsigned long time = millis();    

    while(value != HIGH){
      value = digitalRead(ON_BTN);
    }
    Serial.println(millis() - time);
      
    return millis() - time;
  }
  
  else{
    return 0;
  }
}