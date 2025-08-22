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
  MecanumDriveTrain driveTrain; 
  driveTrain.driveForMeters(2);
}