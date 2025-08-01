#ifndef __I2C_H__ 
#define __I2C_H__ 
#include "Arduino.h"
bool i2c_begin(uint8_t addr);
bool i2c_read(uint8_t regHigh, uint8_t regLow, uint8_t *buf, uint8_t num, uint16_t delay);
bool i2c_write(uint8_t regHigh, uint8_t regLow, uint8_t *buf = NULL, uint8_t num = 0);
#endif 