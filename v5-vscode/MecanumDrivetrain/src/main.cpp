/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       qd                                                        */
/*    Created:      8/22/2025, 12:19:52 PM                                    */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#include "vex.h"
#include "drive_train.h"

using namespace vex;

// A global instance of vex::brain used for printing to the V5 brain screen
vex::brain       Brain;

// define your global instances of motors and other devices here
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
    driveTrain.setSpeed(30);
    driveTrain.turnLeftForDeg(180.0);
    wait(1, sec);
    driveTrain.turnRightForDeg(180.0);
    wait(1, sec);
    driveTrain.turnLeftForDeg(90.0);
    wait(1, sec);
    driveTrain.turnRightForDeg(90.0);
}
