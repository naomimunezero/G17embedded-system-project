// Define the RX pin to receive data from B3
#define RX_PIN 0  // Pin 0 for RX from B3

void setup() {
  // Start serial communication
  Serial.begin(9600);
}

void loop() {
  // Check if data is received from B3
  if (Serial.available() > 0) {
    int data = Serial.parseInt();  // Read data from B3
    Serial.println(data);          // Print data (for monitoring)

    
  }
  
  delay(1000);  // Delay before next loop
}