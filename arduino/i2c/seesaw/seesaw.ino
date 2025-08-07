#include "controller.h" 

void btnPressed(uint8_t buttons) {
  if (buttons & A_BUTTON) Serial.println("A pressed");
  if (buttons & B_BUTTON) Serial.println("B pressed");
  if (buttons & X_BUTTON) Serial.println("X pressed");
  if (buttons & Y_BUTTON) Serial.println("Y pressed");
  if (buttons & SELECT_BUTTON) Serial.println("SELECT_BUTTON pressed");
  if (buttons & START_BUTTON) Serial.println("START_BUTTON pressed");
}

void btnReleased(uint8_t buttons) {
  if (buttons & A_BUTTON) Serial.println("A released");
  if (buttons & B_BUTTON) Serial.println("B released");
  if (buttons & X_BUTTON) Serial.println("X released");
  if (buttons & Y_BUTTON) Serial.println("Y released");
  if (buttons & SELECT_BUTTON) Serial.println("SELECT_BUTTON released");
  if (buttons & START_BUTTON) Serial.println("START_BUTTON released");
}

Controller controller(0x50);
void setup() {
  controller.start();
}

void loop() {
  controller.update(); 
  // controller.print();
  delay(50);
}