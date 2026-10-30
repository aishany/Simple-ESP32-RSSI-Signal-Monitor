#include <Arduino.h>
#include <WiFi.h>

// Replace placeholders with your actual network credentials locally
const char *ssid = "YOUR_WIFI_NAME";
const char *password = "YOUR_WIFI_PASSWORD";

void setup() {
  Serial.begin(115200);
  pinMode(19, OUTPUT);

  delay(10);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("Connected.");
}

int averageRSSI() {
    int total = 0;

    for (int i=0; i<5; i++) {
      total = total + WiFi.RSSI();
      delay(100);
    }
    return total/5;
  }

void loop() {

  if (WiFi.status() == WL_CONNECTED){
    int rssi = WiFi.RSSI();
    int sRssi = averageRSSI();
    
    Serial.print("Raw Signal Strength(RSSI): ");
    Serial.println(rssi);
    
    Serial.print("Smoothed out Signal Strength(RSSI): ");
    Serial.println(sRssi);

    if (sRssi < -50) {
      digitalWrite(19, HIGH);
    } else {
      digitalWrite(19, LOW);
    }
  } else {
    WiFi.reconnect();
  }
  delay(1000);

}
