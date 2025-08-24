#ifndef ___DRIVE_TRAIN____
#define ___DRIVE_TRAIN____
#define INCH2METERS 25.4/1000
#include "vex.h"

using namespace vex;

brain Brain;

double ZERO_ = 0.0;

class MecanumDriveTrain {
public: 
  double WheelDiameter = 2.0* INCH2METERS; 
  double WheelTrack = 0.34; 
  double WheelBase = 0.21;

  double distanceInMeters(double& FLR = ZERO_, double& BLR = ZERO_, double& FRR = ZERO_, double& BRR = ZERO_) {
    FLR = frontLeft.position(turns);
    double FLDist = fabs(FLR * WheelDiameter * M_PI);

    BLR = backLeft.position(turns);
    double BLDist = fabs(BLR * WheelDiameter * M_PI);

    Brain.Screen.printAt(5, 30, "FL rotations: %.3f FL distance; %.3f", FLR, FLDist);
    Brain.Screen.printAt(5, 60, "BL rotations: %.3f BL distance; %.3f", BLR, BLDist);
    
    FRR = frontLeft.position(turns);
    double FRDist = fabs(FRR * WheelDiameter * M_PI);

    BRR = backLeft.position(turns);
    double BRDist = fabs(BRR * WheelDiameter * M_PI);

    Brain.Screen.printAt(5, 90, "FR rotations: %.3f FR distance; %.3f", FRR, FRDist);
    Brain.Screen.printAt(5, 120, "BR rotations: %.3f BR distance; %.3f", BRR, BRDist);

    double meters = (FLDist + BLDist + FRDist + BRDist) / 4;
    return meters; 
  }

  void resetMotors() {
    frontLeft.setPosition(0, turns);
    backLeft.setPosition(0, turns);
    frontRight.setPosition(0, turns);
    backRight.setPosition(0, turns);
  }

  void stopMotors() {
    frontLeft.stop();
    backLeft.stop();
    frontRight.stop();
    backRight.stop();
  }

  void arcadeDrive(double a3, double a1, double a4) {
    double FrontLeftVelocity  = (a3 + a1 + a4) / 2;
    double backLeftVelocity   = (a3 + a1 - a4) / 2; 
    double FrontRightVelocity = (a3 - a1 - a4) / 2; 
    double backRightVelocity  = (a3 - a1 + a4) / 2;

    frontLeft.spin(forward, FrontLeftVelocity, percentUnits::pct);
    backLeft.spin(forward, backLeftVelocity, percentUnits::pct);
    frontRight.spin(forward, FrontRightVelocity, percentUnits::pct);
    backRight.spin(forward, backRightVelocity, percentUnits::pct);
  }

  void driveForwardMeters(double x) {
    resetMotors();
    Brain.Screen.clearScreen();
    while(distanceInMeters() < x) {
      arcadeDrive(40, 0, 0);
    }
    stopMotors();
  }

  void DriveSidewayMeters(double x) {
    resetMotors();
    Brain.Screen.clearScreen();
    while(distanceInMeters() < x) {
      arcadeDrive(0, 0, -40);
    }
    stopMotors();
  }

  void turn(double deg) {
    Brain.Screen.clearScreen();
    resetMotors();
    double turns = deg/360; 
    double t = WheelTrack;
    double b = WheelBase;
    double c = WheelDiameter * M_PI;
    double wheelRevs = turns * (t*t + b*b) * M_PI / (t*c);
    double FLR, BLR, FRR, BRR; 
    for(double y = distanceInMeters(FLR, BLR, FRR, BRR); FLR < wheelRevs; y = distanceInMeters(FLR, BLR, FRR, BRR)) {
      Brain.Screen.printAt(5, 150, "rots: %.3f, desired rots: %.3f", FLR, wheelRevs);
      arcadeDrive(0, 25, 0); 
    }
    stopMotors();
  }

private: 
  motor frontLeft = motor(PORT1, ratio18_1, false);
  motor backLeft = motor(PORT2, ratio18_1, false);
  motor frontRight = motor(PORT10, ratio18_1, true);
  motor backRight = motor(PORT9, ratio18_1, true);
};
#endif