// Define the sensor pin
#define SENSOR_PIN 0  // A0 is pin 0 in direct register access

// Define UART pins (TX/RX)
#define TX_PIN 1  // Pin 1 (TX) for UART communication

void setup() {
  // Start serial communication (9600 baud rate)
  Serial.begin(9600);
}

void loop() {
  // Read the soil moisture sensor value
  int sensorValue = analogRead(SENSOR_PIN);  // Read the sensor

  // Send the value over UART to B2
  Serial.println(sensorValue);
  
  // Delay before the next reading
  delay(1000);
}