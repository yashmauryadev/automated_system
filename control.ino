/*
  Arduino Bluetooth LED Control
  
  Description: This sketch controls an LED connected to an Arduino pin
  using commands sent from a smartphone via an HC-05 Bluetooth module.
  - Send '1' to turn the LED ON.
  - Send '0' to turn the LED OFF.
  
  Created by: [Your Name]
  Date: [Current Date]
*/

// Include the SoftwareSerial library to allow for serial communication on digital pins
#include <SoftwareSerial.h>

// --- Pin Definitions ---
// Define the digital pins used for the SoftwareSerial port (for Bluetooth)
// Arduino's RX pin should be connected to the HC-05's TX pin.
// Arduino's TX pin should be connected to the HC-05's RX pin.
const int BLUETOOTH_RX_PIN = 10;
const int BLUETOOTH_TX_PIN = 11;

// Define the digital pin the LED is connected to
const int LED_PIN = 13;


// --- Global Variables ---
// Initialize a SoftwareSerial object for our Bluetooth module
SoftwareSerial btSerial(BLUETOOTH_RX_PIN, BLUETOOTH_TX_PIN);

// A variable to store the character received from the Bluetooth module
char receivedChar;


// --- Setup Function ---
// This function runs once when the Arduino is powered on or reset.
void setup() {
  // Start the standard hardware serial port at 9600 baud for debugging.
  // You can view these messages in the Arduino IDE's Serial Monitor.
  Serial.begin(9600);
  Serial.println("Arduino is ready. Open Serial Monitor to see received data.");

  // Start the software serial port for the HC-05 module.
  // 9600 is the default baud rate for most HC-05 modules.
  btSerial.begin(9600);
  
  // Set the LED pin as an output pin.
  pinMode(LED_PIN, OUTPUT);
  
  // Ensure the LED is off when the program starts.
  digitalWrite(LED_PIN, LOW);
}


// --- Loop Function ---
// This function runs over and over again.
void loop() {
  // Check if there is any data available to read from the Bluetooth module.
  if (btSerial.available() > 0) {
    // Read the incoming character from the Bluetooth serial port.
    receivedChar = btSerial.read();

    // Print the received character to the Serial Monitor for debugging.
    Serial.print("Character Received: ");
    Serial.println(receivedChar);

    // --- Control Logic ---
    // If the received character is '1', turn the LED on.
    if (receivedChar == '1') {
      digitalWrite(LED_PIN, HIGH);
      btSerial.println("LED has been turned ON");
    }
    // If the received character is '0', turn the LED off.
    else if (receivedChar == '0') {
      digitalWrite(LED_PIN, LOW);
      btSerial.println("LED has been turned OFF");
    }
  }
}