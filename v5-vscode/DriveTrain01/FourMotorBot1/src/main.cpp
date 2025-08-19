#include <stdbool.h>
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

void vexcodeInit() {
  initializeRandomSeed(); 
}
  
int main() {
  vexcodeInit();
  MyDriveTrain driveTrain;
  driveTrain.setup();
  driveTrain.setSpeed(25);

  driveTrain.turnForDegrees(180);
  wait(1, seconds);

  driveTrain.turnForDegrees(90);
  wait(1, seconds);

  driveTrain.turnForDegrees(90);
  wait(60, seconds);

  driveTrain.turnForDegrees(720);
  wait(1, seconds);
}