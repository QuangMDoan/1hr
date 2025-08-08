#include "controller.h" 

Controller controller(0x50);
void setup() {
  controller.start();
}

void loop() {
  controller.update(); 
  controller.print();
  delay(50);
}

