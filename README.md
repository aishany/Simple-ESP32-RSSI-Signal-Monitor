# Simple ESP32 RSSI Monitor

# Project Overview
This project uses an **ESP32 microcontroller** to actively monitor the **Received Signal Strength Indicator (RSSI)** of a local Wi-Fi connection. The code samples the wireless signal strength in real-time and acts as an automated threshold monitor, triggering a physical alert via GPIO 19 (driving a connected LED) whenever the signal strength falls below -50 dBm. It also handles automatic network re-connection if the link state drops.

# Prerequisites
* ESP32 Development Board
* Arduino IDE 
* 1x LED and a 220Ω resistor connected to GPIO pin 19

# Configuration
1. Clone this repository.
2. Open `src/esp32_rssi_monitor.ino` in your Arduino IDE.
3. Update the `ssid` and `password` variables to match your local sandbox testing environment.
4. Flash the code to your microcontroller.
5. Open your Serial Monitor at `115200` baud. Move away from your hotspot (or shield the antenna) to watch the threshold pass -50 dBm and trigger the LED.


