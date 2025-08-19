#ifndef ___DRIVE_TRAIN____
#define ___DRIVE_TRAIN____

#include "vex.h"
#include "motor_group.h"

using namespace vex;

class MyDriveTrain {
public:  
  // wheel revs = turns * (t^2 + b^2) * pi / (c * t)
  // t: track width 
  // b: wheel base
  // c: wheel circumference

  const double WheelDiameter = 4 * INCH2METERS; 
  const double TrackWidth = 14.0 * INCH2METERS;
  const double WheelBase = 40 * 0.001;

  void setup(){
    rightMotorGroup.addMotor(motor(PORT2, ratio18_1, true));
    rightMotorGroup.addMotor(motor(PORT10, ratio18_1, true));
    leftMotorGroup.addMotor(motor(PORT9, ratio18_1, false));
    leftMotorGroup.addMotor(motor(PORT1, ratio18_1, false));
  }

  void setSpeed(double x) {
    rightMotorGroup.setSpeed(x);
    leftMotorGroup.setSpeed(x);
  }

  double getLeftWheelRevolutions(){
    double leftRotations = leftMotorGroup.getRotations();
    // Brain.Screen.printAt(5, 40, "left rotations: %.3f ", leftRotations);
    return leftMotorGroup.getRotations();
  }

  double getLeftDistanceMeters(){
    double leftRotations = leftMotorGroup.getRotations();
    double leftMeters = WheelDiameter * M_PI * leftRotations; 
    Brain.Screen.printAt(5, 40, "left rotations: %.4f, meters: %.4f", leftRotations, leftMeters);
    return leftMeters;
  }

  double getRightDistanceMeters(){
    double rightRotations = rightMotorGroup.getRotations();
    double rightMeters = WheelDiameter * M_PI * rightRotations; 
    Brain.Screen.printAt(5, 80, "right rotations: %.4f, meters: %.4f", rightRotations, rightMeters);
    return rightMeters;
  }

  double getDistanceMeters(){
    return (getLeftDistanceMeters() + getRightDistanceMeters()) / 2;
  }

  void driveForMeters(double x){
    leftMotorGroup.resetMeters();
    rightMotorGroup.resetMeters();
    Brain.Screen.clearScreen();

    while(getDistanceMeters() < x) {
      leftMotorGroup.drive();
      rightMotorGroup.drive();
    }
    leftMotorGroup.stopMotors();
    rightMotorGroup.stopMotors();
  }

  void turnForDegrees(double x) {
    rightMotorGroup.resetMeters();
    leftMotorGroup.resetMeters();
    Brain.Screen.clearScreen();
    
    double turns = x / 360;    
    double c = WheelDiameter * M_PI;
    double b = WheelBase;
    double t = TrackWidth;

    // double arcLength = turns * t * M_PI;
    // while (getLeftDistanceMeters() < arcLength) {
    //   rightMotorGroup.drive(false);
    //   leftMotorGroup.drive();
    // }

    // wheel revs = turns * (t^2 + b^2) * pi / (c * t)
    double wheel_revs = turns * (t*t + b*b) * M_PI / (c * t);
    Brain.Screen.printAt(5, 120, "Target %.4f (%.4f revs)", x, turns);

    for (double revs = getLeftWheelRevolutions(); revs < wheel_revs; revs = getLeftWheelRevolutions()) {
      rightMotorGroup.drive(false);
      leftMotorGroup.drive();
      Brain.Screen.printAt(5, 160, "target wheel revs: %.4f, current revs: %.4f", wheel_revs, revs);
    }

    leftMotorGroup.stopMotors();
    rightMotorGroup.stopMotors();
  }

private:
  MotorGroup rightMotorGroup;
  MotorGroup leftMotorGroup;
};

#endif