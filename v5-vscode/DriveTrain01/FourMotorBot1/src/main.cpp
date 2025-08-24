#include <stdbool.h>
#include "vex.h"
#include "drive_train.h"

using namespace vex;
controller Controller;

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
  MecanumDriveTrain autoDrive;
  wait(1, seconds);
  driveTrain.DriveSidewayMeters(1.6);

  wait(3, seconds);
  driveTrain.driveForwardMeters(2);

  wait(3, seconds);
  driveTrain.turn(180);

  wait(3, seconds);
  driveTrain.driveForwardMeters(2);

  wait(3,seconds);
  driveTrain.DriveSidewayMeters(1.6);

  wait(3, seconds);
  driveTrain.turn(180);

  while(true) {
    autoDrive.arcadeDrive(Controller.Axis3.value(), Controller.Axis1.value(), Controller.Axis4.value());
  }
}