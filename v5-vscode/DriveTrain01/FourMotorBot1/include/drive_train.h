#ifndef ___DRIVE_TRAIN____
#define ___DRIVE_TRAIN____
#define INCH2METERS 25.4/1000
#include "vex.h"

using namespace vex;

brain Brain;

class MecanumDriveTrain {
public:  
  const double WheelDiameter = 2 * INCH2METERS; 
  const double TrackWidth = 14.0 * INCH2METERS;
  const double WheelBase = 40 * 0.001;

  double getForwardDistanceMeters(){
    double meters = 0;

    double flr = frontLeft.position(turns);
    double flDist = flr * WheelDiameter * M_PI;
    double blr = backLeft.position(turns);
    double blDist = blr * WheelDiameter * M_PI;

    Brain.Screen.printAt(5, 30, "FL rotations : %.4f, FL dist: %.4f", flr, flDist);
    Brain.Screen.printAt(5, 60, "BL rotations : %.4f, BL dist: %.4f", blr, blDist);
        
    double frr = frontRight.position(turns);
    double frDist = frr * WheelDiameter * M_PI;

    double brr = backRight.position(turns);
    double brDist = brr * WheelDiameter * M_PI;
    Brain.Screen.printAt(5, 90, "FR rotations : %.4f, FR dist: %.4f", frr, frDist);
    Brain.Screen.printAt(5, 120, "BR rotations : %.4f, BR dist: %.4f", brr, brDist);

    double leftRot = (flr + blr)/2;
    double leftDist = (flDist + blDist)/2;

    double rightRot = (frr + brr)/2;
    double rightDist = (frDist + brDist)/2;

    Brain.Screen.printAt(5, 150, "Left rotations : %.4f, Left dist: %.4f", leftRot, leftDist);
    Brain.Screen.printAt(5, 180, "right rotations : %.4f, Right dist: %.4f", rightRot, rightDist);

    double frontRot = (flr + frr)/2;
    double frontDist = (flDist + frDist)/2;

    double backRot = (blr + brr)/2;
    double backDist = (blDist + brDist)/2;

    Brain.Screen.printAt(5, 210, "front rotations : %.4f, front dist: %.4f", frontRot, frontDist);
    Brain.Screen.printAt(5, 240, "back rotations : %.4f, back dist: %.4f", backRot, backDist);

    // meters = (flDist + frDist + blDist + brDist)/4;
    meters = ((leftDist + rightDist )/2 + (frontDist + backDist)/2)/2;
    return meters;
  }

  void resetMotors() {
    frontLeft.setPosition(0, turns);
    frontRight.setPosition(0, turns);
    backLeft.setPosition(0, turns); 
    backRight.setPosition(0, turns);
  }

  void stopMotors() {
    frontLeft.stop();
    frontRight.stop();
    backLeft.stop(); 
    backRight.stop();
  }
  void driveForMeters(double x){
    Brain.Screen.clearScreen();
    resetMotors();
    while(getForwardDistanceMeters() < x) {
      arcadeDrive(0, 25, 0);
    }
    stopMotors();
  }

  // Drive the chassis using controller 
  void arcadeDrive(double a1, double a3, double a4) {
    double frontLeftSpeed  = (a1 + a3 + a4) / 2;
    double backLeftSpeed   = (a1 + a3 - a4) / 2;
    double frontRightSpeed = (a3 - a1 - a4) / 2;
    double backRightSpeed  = (a3 - a1 + a4) / 2;
    
    frontLeft.spin(forward, frontLeftSpeed, velocityUnits::pct);
    backLeft.spin(forward, backLeftSpeed, velocityUnits::pct);
    frontRight.spin(forward, frontRightSpeed, velocityUnits::pct);
    backRight.spin(forward, backRightSpeed, velocityUnits::pct);
  }

  /**
   * Turn the chassis by any degree. 
   * Positive degrees means turn right. 
   * Neg degrees means turn left.
   */
  void turn(double turnDegrees) {
    resetMotors();
    Brain.Screen.clearScreen();
    double turns = turnDegrees/360;
    double c = WheelDiameter*M_PI; 
    double b = WheelBase; 
    double t = TrackWidth;
    double wheel_revs = turns * (t*t+b*b)  * M_PI / (c*t);
    arcadeDrive(25, 0, 0);
    stopMotors();
  }

private:
  motor frontLeft = motor(PORT1, ratio18_1, false);
  motor backLeft = motor(PORT2, ratio18_1, false);
  motor frontRight = motor(PORT10, ratio18_1, true);
  motor backRight = motor(PORT9, ratio18_1, true);
};

#endif