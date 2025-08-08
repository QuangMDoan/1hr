#include "controller.h" 

// Implement call back function tionn
void xButtonPressed() {
  Serial.println("X button pressed");
}

// FIX this to store the abobe call back function to the controller object
Controller controller(0x50);

void setup() {
  controller.start();
}

void loop() {
  controller.update(); 
  controller.print();
  delay(50);
}

