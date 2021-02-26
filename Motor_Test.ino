const int in1=10, in2=11, opticalPin=2;
const int enA1=14, enA2=15;
//enA1=A0
//enA2=A1
const int motorSpeed = 1 ;
int counter=0;
volatile boolean isClockwise=false;
volatile int currentPos=0;

void setup() {
  pinMode(enA1, OUTPUT);
  pinMode(enA2, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(opticalPin, INPUT_PULLUP);
  Serial.begin(115200);
  attachInterrupt(digitalPinToInterrupt(opticalPin), opticalSensor_ISRb, RISING);
}

void loop() {
  Serial.println(currentPos);
}

void opticalSensor_ISRb() {
  if (isClockwise) currentPos++;
  else currentPos--;
}

void turnCW() {
  enable();
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  isClockwise=true;
}

void turnCCW() {
  enable();
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  isClockwise=false;
}

void enable() {
  digitalWrite(enA1, HIGH);
  digitalWrite(enA2, HIGH);
}

void brake() {
  digitalWrite(enA1, LOW);
  digitalWrite(enA2, LOW);
}
