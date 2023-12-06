const int LED2 = 2;
const int LED3 = 3;
const int LED4 = 4;
const int LED5 = 5;

void setup()
{
  Serial.begin(9600);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
}

void loop()
{
  int value = analogRead(0);
  Serial.println(value);
  
  int values[] = {0, 0, 0, 0};
  
  //values[0] = constrain(map(value, 256, 512, 0, 255), 0, 255);
  
  for (int i = 0; i < 4; ++i){
    if(value > 255){
    	value = value - 255;
      values[i] = 255;
    }
    else{
      values[i] = value;
    	value = 0;
    }
  }
  
  analogWrite(LED2, values[0]);
  analogWrite(LED3, values[1]);
  analogWrite(LED4, values[2]);
  analogWrite(LED5, values[3]);
  
  delay(5);
}