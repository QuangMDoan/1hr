#include "controller.h"
#include "i2c.h"
#include "Arduino.h"

#define STATUS 0x00
#define GPIO 0x01
#define ADC 0x09

uint8_t button_mask[4] = {0x00, 0x01, 0x00, 0x67};

void Controller::printBin(uint8_t* buf, int numBytes) {
  for (int i = 0; i < numBytes; i++) {
    for (int j = 7; j >= 0; j--){
      Serial.print(bitRead(buf[i], j));  
    }
    if (i < 3) Serial.print('.');
  }
  Serial.println();
}

void Controller::start(){
  Serial.begin(9600);
  i2c_begin(_addr);

  uint8_t x = 0x01;
  while(!(i2c_write(STATUS, 0x7F, &x, 1)));
  while(!(i2c_write(STATUS, 0x01, &x, 1)));
  
  // sets all of the pins in buttonmask to pullup
  i2c_write(GPIO, 0x0B, button_mask, 4);
  i2c_write(GPIO, 0x04, button_mask, 4);

  setDeadzone(20);
}

uint16_t swap_bytes(uint16_t a) {
  // from right to left we have a[0], a[1]
  // return right to left a[1], a[0]

  uint16_t left = a << 8;
  uint16_t right = a >> 8;

  uint16_t swapped = left | right;
  return swapped;
}

void Controller::update(){
  uint8_t buf[4] = {0x00, 0x01, 0x00, 0x67};

  // printBin(buf, 4);
  i2c_read(GPIO, 0x04, buf, 4, 0);
  // printBin(buf, 4);
  
  _data.aButton = !(buf[3] >> 5 & 1);
  _data.bButton = !(buf[3] >> 1 & 1);
  _data.xButton = !(buf[3] >> 6 & 1);
  _data.yButton = !(buf[3] >> 2 & 1);

  _data.startButton = !(buf[1] & 1);
  _data.selectButton = !(buf[3] & 1);

  uint16_t x;
  i2c_read(ADC, 0x15, (uint8_t*)&x, 2, 500);
  _data.x_Axis = 511 - swap_bytes(x);

  uint16_t y;
  i2c_read(ADC, 0x16, (uint8_t*)&y, 2, 500);
  _data.y_Axis = 511 - swap_bytes(y);

  if(abs(_data.x_Axis) < _deadzone){
    _data.x_Axis = 0;
  }
  if(abs(_data.y_Axis) < _deadzone){
    _data.y_Axis = 0;
  }

  if (_data.bButton) {
    _callback_fn();
  }
  
}

void Controller::print(){
  char buf[121];
  snprintf(buf, 121,
  "X axis: %4d | Y axis: %4d | "
  "A button: %u | B button: %u | X button: %u | Y button: %u | "
  "SELECT button: %u | START button: %u", 
  _data.x_Axis, _data.y_Axis,
  _data.aButton, _data.bButton, _data.xButton, _data.yButton,
  _data.selectButton, _data.startButton);
  Serial.println(buf);
}