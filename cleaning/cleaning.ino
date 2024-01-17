const int m1 = 9;
const int m2 = 10;
const int m3 = 12;
const int m4 = 13;


int motorSpeed = 100;
void setup() {
  pinMode(m1, OUTPUT);
  pinMode(m2, OUTPUT);
  pinMode(m3, OUTPUT);
  pinMode(m4, OUTPUT);
}


void forward() {
  digitalWrite(m1, LOW);
  digitalWrite(m2, HIGH);
  digitalWrite(m3, HIGH);
  digitalWrite(m4, LOW);
  delay(1500); // Go forward for 2 seconds
}


void reverse() {
  digitalWrite(m1, HIGH);
  digitalWrite(m2, LOW);
  digitalWrite(m3, LOW);
  digitalWrite(m4, HIGH);
  delay(1500); // Go backward for 2 seconds
}


void stop() {
  digitalWrite(m1, LOW);
  digitalWrite(m2, LOW);
  digitalWrite(m3, LOW);
  digitalWrite(m4, LOW);
}


void loop() {
  stop();
  forward();
  stop();
  reverse();
  stop();
  stop();
}


