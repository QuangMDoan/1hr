#include "controller.h"

void aButtonPressed() {
  Serial.println("A pressed");
}

// FIX this to store the abobe call back function to the controller object
Controller controller(0x50, aButtonPressed);

void setup() {
  controller.start();
}

void loop() {
  controller.update(); 
  delay(50);
}

