#include <SoftwareSerial.h>

#define RED_LED 0
#define GREEN_LED 1
#define BLUE_LED 2

void setup() {
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);
  Serial.begin(9600);
  Serial.println("GitHub Notification Device Initialized");
}

void loop() {
  if (Serial.available()) {
    char notification = Serial.read();
    handleNotification(notification);
  }
}

void handleNotification(char notification) {
  switch (notification) {
    case 'P': // Push event
      setLEDColor(0, 255, 0); // Green for new push
      break;
    case 'I': // Issue opened
      setLEDColor(255, 165, 0); // Orange for new issue
      break;
    case 'S': // Starred
      setLEDColor(255, 255, 0); // Yellow for new star
      break;
    default: // Unknown event
      setLEDColor(255, 0, 0); // Red for error/unknown
      break;
  }
  delay(2000); // Hold the color for visibility
  setLEDColor(0, 0, 0); // Turn off LED
}

void setLEDColor(int red, int green, int blue) {
  analogWrite(RED_LED, red);
  analogWrite(GREEN_LED, green);
  analogWrite(BLUE_LED, blue);
}
