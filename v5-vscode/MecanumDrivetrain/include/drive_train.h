#ifndef ___DRIVE_TRAIN____
#define ___DRIVE_TRAIN____

#include "vex.h"

#define INCH2METERS 25.4/1000.0 
#define ROTPERDEG 9.05/360.0

using namespace vex;

class MecanumDriveTrain {
public:  
  // wheel revs = turns * (t^2 + b^2) * pi / (c * t)

  const double WheelDiameter = 2 * INCH2METERS; 
  const double TrackWidth = 14.0 * INCH2METERS;
  const double WheelBase = 40 * 0.001;

  MecanumDriveTrain(): frontLeft_(PORT1, ratio18_1, false),
                       backLeft_(PORT2, ratio18_1, false),
                       frontRight_(PORT10, ratio18_1, true),
                       backRight_(PORT9, ratio18_1, true)   {};

  void setSpeed(double x) {
    frontLeft_.setVelocity(x, pct);
    backLeft_.setVelocity(x, pct);
    frontRight_.setVelocity(x, pct);
    backRight_.setVelocity(x, pct);
  }

  void turnLeftForDeg(double deg) {
    turnForRotations(deg * ROTPERDEG, true);
  }

  void turnRightForDeg(double deg) {
    turnForRotations(deg * ROTPERDEG, false);
  }

  void turnForRotations(double rot, bool turnLeft) {
    resetAllMotors();

    directionType leftDir = turnLeft ? forward : reverse;
    directionType rightDir = turnLeft ? reverse : forward;

    while(abs(frontLeft_.position(rev)) < rot) {
        brain_.Screen.printAt(5, 160, "target revs: %.4f, current revs: %.4f", rot, abs(frontLeft_.position(rev)));
        spinMotors(leftDir, leftDir, rightDir, rightDir);
    }

    stopAllMotors();
  }

private:
  motor frontLeft_;
  motor backLeft_;
  motor frontRight_;
  motor backRight_;
  brain brain_;

  void resetAllMotors() {
    frontLeft_.resetPosition();
    backLeft_.resetPosition();
    frontRight_.resetPosition();
    backRight_.resetPosition();
  }

  void stopAllMotors() {
    frontLeft_.stop();
    backLeft_.stop();
    frontRight_.stop();
    backRight_.stop();
  }

  void spinMotors(vex::directionType flDir, vex::directionType blDir,
                  vex::directionType frDir, vex::directionType brDir) {
    frontLeft_.spin(flDir);
    backLeft_.spin(blDir);
    frontRight_.spin(frDir);
    backRight_.spin(brDir);
  }

  
};

#endif