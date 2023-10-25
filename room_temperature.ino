#define temp_sensor A1
#define buzzer 4

//----Left 7-Segment pins
#define a1 9
#define b1 12
#define c1 11
#define d1 10

//---Right 7-Segment pins
#define a2 5
#define b2 8
#define c2 7
#define d2 6

#define HIGH_TEMPERATURE 1
#define LOW_TEMPERATURE 0


//Variables
unsigned int temperature;
unsigned int pins[9] = {a1, b1, c1, d1, a2, b2, c2, d2, buzzer};

//Functions
int temperature_calculation();
void segleft(uint8_t number);
void segright(uint8_t number);


void setup() {
  for (int i = 0 ; i < 9; i++) {
    pinMode(pins[i], OUTPUT);
  }
  pinMode(temp_sensor, INPUT);
}

void loop() {
  if (temperature_calculation()==HIGH_TEMPERATURE) {
    digitalWrite(buzzer, HIGH);
  }
  else {
    digitalWrite(buzzer, LOW);
  }
  //displaying Temperature on 7-segments
  segleft(temperature / 10);
  segright(temperature % 10);
  delay(200);
}

//----Calculating Room Temperature
int temperature_calculation() {
  float v = analogRead(temp_sensor) * (5.0 / 1024.0);
  temperature = v * 100;
  if (temperature >= 40) {
    return HIGH_TEMPERATURE;
  }
  else {
    return LOW_TEMPERATURE;
  }
}

//-----Left 7-Segment display
void segleft(uint8_t number) {
  digitalWrite(a1, (number >> 0) & 0x01);
  digitalWrite(b1, (number >> 1) & 0x01);
  digitalWrite(c1, (number >> 2) & 0x01);
  digitalWrite(d1, (number >> 3) & 0x01);
}

//------Right 7-Segment display
void segright(uint8_t number) {
  digitalWrite(a2, (number >> 0) & 0x01);
  digitalWrite(b2, (number >> 1) & 0x01);
  digitalWrite(c2, (number >> 2) & 0x01);
  digitalWrite(d2, (number >> 3) & 0x01);
}
