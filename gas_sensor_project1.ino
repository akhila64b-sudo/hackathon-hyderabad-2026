// Automated Fire and Smoke Detection Framework
const int gasPin = A0;   // Gas sensor module analog output
const int buzzerPin = 8; // Alarm piezo buzzer digital output
const int ledPin = 9;    // Red safety status LED indicator
int threshold = 350;     // Defined safe air threshold level
void setup() {
  pinMode(gasPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);    // Initialization for debug stream
}
void loop() {
  int gasValue = analogRead(gasPin);
  Serial.print("Current Gas/Smoke Density: ");
  Serial.println(gasValue);
  if (gasValue > threshold) {
    digitalWrite(ledPin, HIGH);   // Fire hazard indicator ON
    tone(buzzerPin, 1200);        // Sound active alert (1200Hz)
  } else {
    digitalWrite(ledPin, LOW);    // Status normal
    noTone(buzzerPin);            // Silence buzzer output
  }
  delay(150);                     // Sample polling stabilizer interval
}