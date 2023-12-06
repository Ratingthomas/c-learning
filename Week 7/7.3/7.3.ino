// C++ code
const int LED1 = 13;
const int LED2 = 12;
const int LED3 = 11;
const int LED4 = 10;
const int LED5 = 9;
const int LED6 = 8;
const int BTN = 7;

int pos = 0;
int countvalue = 1;
bool up = true;

void setup()
{
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  pinMode(LED6, OUTPUT);
  pinMode(BTN, INPUT_PULLUP);
}

void loop()
{
  int LEDS[] = {LED1, LED2, LED3, LED4, LED5, LED6};
  
  print_pattern(LEDS);
  
  delay(200);
}

void disableleds(){
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);
  digitalWrite(LED4, LOW);
  digitalWrite(LED5, LOW);
  digitalWrite(LED6, LOW);
}

void print_pattern(int LEDS[]){
    if (digitalRead(BTN) != LOW){
		  disableleds();
      
      digitalWrite(LEDS[pos], HIGH);

      if(pos != 5 && pos != 0){
      	digitalWrite(LEDS[pos+countvalue], HIGH);
      }

      if(pos == 5){
         countvalue = -1;
         up = false;
      }
      else if(pos == 0){
         countvalue = 1;
         up = true;
      }

      if(up == true){
         pos++;
      }
      else {
         pos--;
      }
    }
}	