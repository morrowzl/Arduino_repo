/* 
-uses ultrasonic sensor to illuminate an LED at different 
frequencies when an object is sensed at different ranges)
- uses one light blinking frquency is directly related to range
*/

int Echo = A4;  
int Trig = A5;
int range = 0;

void blink(int rate) {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(rate);
  digitalWrite(LED_BUILTIN, LOW);
  delay(rate);
}

//Ultrasonic distance measurement Sub function
//from Elegoo
int Distance_test() {
  digitalWrite(Trig, LOW);   
  delayMicroseconds(2);
  digitalWrite(Trig, HIGH);  
  delayMicroseconds(20);
  digitalWrite(Trig, LOW);   
  float Fdistance = pulseIn(Echo, HIGH, 500000);  
  Fdistance= Fdistance / 58;       
  return (int)Fdistance;
}

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(Echo, INPUT);    
  pinMode(Trig, OUTPUT);
}

void loop() {
  range = Distance_test();
  blink(range);
  }

