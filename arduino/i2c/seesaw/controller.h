#ifndef __CONTROLLER_H__ 
#define __CONTROLLER_H__
#include "Arduino.h"
struct ControllerData {
  bool aButton; 
  bool bButton; 
  bool xButton; 
  bool yButton; 
  bool selectButton; 
  bool startButton;
  int16_t x_Axis;
  int16_t y_Axis; 
};

class Controller {

public: 
  Controller(uint8_t addr, void (*callback_fn)() ): _addr(addr), _deadzone(0), _callback_fn(callback_fn) {}
  void setDeadzone(uint8_t deadzone) {
    _deadzone = deadzone;
  }

  void update();
  void start();
  void printBin(uint8_t* buf, int numBytes);
  void print();

  ControllerData getData(){
    return _data;
  }
private: 
  uint8_t _addr;
  uint8_t _deadzone;
  ControllerData _data;

  void (*_callback_fn)();
};
#endif 