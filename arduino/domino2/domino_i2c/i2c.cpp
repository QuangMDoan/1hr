#include <Adafruit_I2CDevice.h>
#include <Wire.h>

#include "i2c.h"

Adafruit_I2CDevice *i2c_dev;

bool i2c_begin(uint8_t addr) {
  i2c_dev = new Adafruit_I2CDevice(addr, &Wire);

  bool found = false;
  for (int retries = 0; retries < 10; retries++) {
    if (i2c_dev->begin()) {
      found = true;
      break;
    }
    delay(10);
  }

  if (!found) {
    return false;
  }

  return found;
}

bool i2c_read(uint8_t regHigh, uint8_t regLow, uint8_t *buf, uint8_t num, uint16_t delay) {
  uint8_t pos = 0;
  uint8_t prefix[2];
  prefix[0] = (uint8_t)regHigh;
  prefix[1] = (uint8_t)regLow;

  // on arduino we need to read in 32 byte chunks
  while (pos < num) {
    uint8_t read_now = min(32, num - pos);

    if (!i2c_dev->write(prefix, 2)) {
      return false;
    }

    // TODO: tune this
    delayMicroseconds(delay);

    if (!i2c_dev->read(buf + pos, read_now)) {
      return false;
    }
    pos += read_now;
  }
  return true;
}

bool i2c_write(uint8_t regHigh, uint8_t regLow, uint8_t *buf = NULL, uint8_t num = 0) {
  uint8_t prefix[2];
  prefix[0] = (uint8_t)regHigh;
  prefix[1] = (uint8_t)regLow;

  if (!i2c_dev->write(buf, num, true, prefix, 2)) {
    return false;
  }

  return true;
}