// Pin Definitions
const int relayPin = 13;         // Relay control pin
const int flowSensorPin = 2;    // Water flow sensor pin (must be interrupt capable)

// Variables
volatile int flowPulseCount = 0;
unsigned long lastCheckTime = 0;
const unsigned long checkInterval = 1000; // 1 second

void setup() {
  pinMode(relayPin, OUTPUT);
  pinMode(flowSensorPin, INPUT_PULLUP);  // Ensure stable input

  digitalWrite(relayPin, HIGH);  // Relay initially OFF

  attachInterrupt(digitalPinToInterrupt(flowSensorPin), countPulse, RISING);

  Serial.begin(9600);
}

void loop() {
  unsigned long currentTime = millis();

  if (currentTime - lastCheckTime >= checkInterval) {
    lastCheckTime = currentTime;

    Serial.print("Flow Pulses: ");
    Serial.println(flowPulseCount);

    if (flowPulseCount > 0) {
      // Water flow detected, turn ON relay
      digitalWrite(relayPin, LOW);
      Serial.println("Water flow detected! Relay turned ON.");
    } else {
      // No water flow, turn OFF relay (optional)
      digitalWrite(relayPin, HIGH);
      Serial.println("No flow. Relay turned OFF.");
    }

    // Reset the pulse count for the next interval
    flowPulseCount = 0;
  }
}

void countPulse() {
  flowPulseCount++;
}
