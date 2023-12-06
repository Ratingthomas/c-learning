// C++ code
//
const int POT_PIN = A0;
const int PIN_A = 3;
const int PIN_B = 2;
const int PIN_C = 9;
const int PIN_D = 7;
const int PIN_E = 6;
const int PIN_F = 4;
const int PIN_G = 5;

void setup()
{
  	pinMode(LED_BUILTIN, OUTPUT);
  	Serial.begin(9600);
}

void loop()
{
  	int value = analogRead(POT_PIN);
  
  	const int pins[] = {PIN_A, PIN_B, PIN_C, PIN_D, PIN_E, PIN_F, PIN_G};
  	int last_pin = 0;
  
    last_pin = map(value, 0, 1024, 0, 7);
  
	Serial.print(last_pin);
    Serial.print(" -> ");
    Serial.println(pins[last_pin]);
  	print(pins, last_pin);
}

void print(const int pins[], int index){
  	for (int i = 0; i < 7; ++i){
  		digitalWrite(pins[i], LOW);
  	}
  	
  	digitalWrite(pins[index], HIGH);
}
