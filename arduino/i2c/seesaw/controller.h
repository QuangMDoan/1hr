#ifndef __CONTROLLER_H__ 
#define __CONTROLLER_H__
#include "Arduino.h"

enum Button : uint8_t {
  A_BUTTON = 1,
  B_BUTTON = 2,
  X_BUTTON = 4,
  Y_BUTTON = 8,
  SELECT_BUTTON = 16,
  START_BUTTON = 32,
};

struct ControllerData {
  bool aButton; 
  bool bButton; 
  bool xButton; 
  bool yButton; 
  bool selectButton; 
  bool startButton;
  int16_t x_Axis;
  int16_t y_Axis; 
  uint8_t bits;

  void update_bits() {
    bits = 0x00;
    if (aButton)  bits |= 1;
    if (bButton)  bits |= 2;
    if (xButton)  bits |= 4;
    if (yButton)  bits |= 8;
    if (selectButton)  bits |= 16;
    if (startButton)  bits |= 32;
  }
};

class Controller {

public: 
  Controller(uint8_t addr): _addr(addr), _deadzone(0) {}
  void setDeadzone(uint8_t deadzone) {
    _deadzone = deadzone;
  }

  void update();
  void start();
  void printBin(uint8_t* buf, int numBytes);
  void print();

  ControllerData getState(){  return _state; }

private: 
  uint8_t _addr;
  uint8_t _deadzone;

  ControllerData _state;
  ControllerData _prevState;
};
#endif 