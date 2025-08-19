#include "vex.h"
#include "drive_train.h"

using namespace vex;

void initializeRandomSeed(){
  int systemTime = Brain.Timer.systemHighResolution();
  double batteryCurrent = Brain.Battery.current();
  double batteryVoltage = Brain.Battery.voltage(voltageUnits::mV);
  int seed = int(batteryVoltage + batteryCurrent * 100) + systemTime;
  srand(seed);
}

int main() {
  initializeRandomSeed();
  // create a driveTrain instance, call setup anf setSpeed

  driveTrain.turnForDegrees(180);
  wait(1, seconds);

  driveTrain.turnForDegrees(90);
  wait(1, seconds);

  driveTrain.turnForDegrees(90);
  wait(30, seconds);

  driveTrain.turnForDegrees(720);
  wait(1, seconds);
}