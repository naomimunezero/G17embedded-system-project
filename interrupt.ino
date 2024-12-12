// Define the RX and TX pins for UART
#define RX_PIN 0  // RX pin to receive data from B2
#define TX_PIN 1  // TX pin to send data to B4

// Define the interrupt pin (e.g., button press)
#define INTERRUPT_PIN 2  // Pin 2 as an interrupt pin

void setup() {
  // Set up interrupt pin as input (no pinMode)
  // Attach interrupt to the pin (falling edge)
  EICRA |= (1 << ISC01);  // Trigger interrupt on falling edge
  EIMSK |= (1 << INT0);   // Enable interrupt for INT0 (pin 2)

  // Start serial communication with B4
  Serial.begin(9600);
}

void loop() {
  // Data handling (receiving from B2, sending to B4)
  if (Serial.available() > 0) {
    int data = Serial.parseInt();  // Read data from B2
    Serial.println(data);          // Forward data to B4
  }
  
  // Other tasks (e.g., monitor button press)
  delay(1000);  // Delay before next loop
}

// Interrupt service routine (ISR) for the button press
ISR(INT0_vect) {
  // Handle the interrupt (for example, reset or alert)
  // (You can add any specific behavior needed during interrupt)
  Serial.println("Interrupt triggered!");
}
