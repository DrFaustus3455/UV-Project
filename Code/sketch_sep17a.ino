int sensorPinIn = 2;    // Water flow sensor input
int sensorPinOut = 13;   // Output pin to control relay
volatile unsigned long pulse = 0; // Counts pulses from the water flow sensor

void setup() {
  pinMode(sensorPinOut, OUTPUT); // Relay pin
  pinMode(sensorPinIn, INPUT);   // Water flow sensor pin
  Serial.begin(9600);

  // Attach interrupt to the input pin
  attachInterrupt(digitalPinToInterrupt(sensorPinIn), increase, RISING);
}

void loop() {
  static unsigned long lastPulseCount = 0;

  // Compare current pulse count to previous
  if (pulse > lastPulseCount) {
    digitalWrite(sensorPinOut, LOW); // Turn on relay (LOW LEVEL Trigger)
    lastPulseCount = pulse;
  } else {
    digitalWrite(sensorPinOut, HIGH); // Turn off relay if no new pulses
  }

  // Print current pulse count
  Serial.println(pulse);
  delay(50);
}

void increase() {
  pulse++;
}
