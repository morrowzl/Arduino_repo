/* use ultrasonic sensor to illuminate an LED at different 
frequencies when an object is sensed at different ranges)
- uses one light blinking at different frquencies
- next: make the range directly related to blinking frequency
*/

int Echo = A4;  
int Trig = A5;
int range = 0;

void standby() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000);
}

void medium() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(500);
  digitalWrite(LED_BUILTIN, LOW);
  delay(500);
}

void fast() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(100);
  digitalWrite(LED_BUILTIN, LOW);
  delay(100);
}

void fastest() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(50);
  digitalWrite(LED_BUILTIN, LOW);
  delay(50);
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

  if (range <= 20) {
    fastest();
  }

  else if (range <= 40) {
    fast();
  }

  else if (range <= 80) {
    medium();
  }

  else {
    standby();
  }
}
