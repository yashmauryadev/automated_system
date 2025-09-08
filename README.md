# Automated System

A flexible and extensible automated system designed for home/office automation and IoT applications.

## Features

- Remote monitoring and control of devices
- Sensor integration (temperature, humidity, etc.)
- Automated scheduling
- User-friendly interface

## Hardware Used

- Microcontroller: Arduino Uno (can be replaced with ESP32/Raspberry Pi)
- Sensors: DHT11 (Temperature & Humidity), PIR Sensor
- Actuators: Relay Module, LED, Buzzer
- Power Supply: 5V

## Circuit Diagram

```plaintext
         +-----------------------------+
         |         Arduino Uno         |
         +-----------------------------+
        [D2] ----> PIR Sensor Signal
        [D3] ----> Relay IN
        [D4] ----> LED (+)
        [D5] ----> Buzzer (+)
        [5V] ----> All VCCs
       [GND] ----> All Grounds
        [A0] <---- DHT11 Data

          +---[Relay]---[AC Device]
          +---[LED]
          +---[Buzzer]
          +---[PIR Sensor]
          +---[DHT11 Sensor]
```

## Getting Started

1. Connect the components as shown in the circuit diagram.
2. Clone this repository:
   ```bash
   git clone https://github.com/yashmauryadev/automated_system.git
   ```
3. Open the code in Arduino IDE or PlatformIO.
4. Install required libraries (e.g., DHT, Servo, etc.).
5. Upload the code to the microcontroller.

## Usage

- The system automatically turns on the connected device when motion is detected.
- Reads temperature and humidity and displays/logs the data.
- Can be controlled remotely (expandable with WiFi/Bluetooth).

## License

This project is licensed under the MIT License.
