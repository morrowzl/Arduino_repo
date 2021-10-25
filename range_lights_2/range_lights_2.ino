/* use ultrasonic sensor to illuminate different LEDs 
for when an object is sensed at different ranges)
UNO LED_BUILTIN
UNO RX LED
UNO TX LED
UNO ON (power)
Elegoo shield LED_BUILTIN
Elegoo shield Infrared Sensor LED
Elegoo shield ON
*/

// use one light blinking at different frquencies
// next: make the range directly related to blinking frequency

const int Echo = A4;  
const int Trig = A5;

int range = 0;
int ledState = LOW;

unsigned long previousMillis = 0;

void standby() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(100);
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000);
  Serial.println("standby");
}

//void slow() {
//
//}

//void medium() {
//
//}

void rapid() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(100);
  digitalWrite(LED_BUILTIN, LOW);
  delay(100);
  Serial.println("rapid");
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
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(Echo, INPUT);    
  pinMode(Trig, OUTPUT);
}

void loop() {
  range = Distance_test();

  if (range <= 40) {
    rapid();
  }

  else {
    standby();
  }
  //sense for objects in range
  // distance test
    //if no object is in range, then do standby blinking
    //if object is in range 200-400 cm, then do low blinking
    //if object is in range 100-200 cm, then do medium blinking
    //if object is in range 2-100 cm, then do rapid blinking
}
