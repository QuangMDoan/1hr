#include "controller.h" 
void bButtonHandler() {
  Serial.println("B button pressed");
}

Controller controller(0x50, bButtonHandler);
void setup() {
  controller.start();
}

void loop() {
  controller.update(); 
  controller.print();
  delay(50);
}