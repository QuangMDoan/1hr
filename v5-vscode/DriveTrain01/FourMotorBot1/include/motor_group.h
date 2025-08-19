#ifndef ___MOTOR_GROUP____
#define ___MOTOR_GROUP____

#include <vector>
#include "vex.h"

#define INCH2METERS 25.4/1000.0 

vex::brain Brain;

struct MotorGroup {
  std::vector<vex::motor> motors;

  void addMotor(vex::motor m){
    motors.push_back(m);
  }

  void setSpeed(double x){
    for(vex::motor m: motors){
      m.setVelocity(x, vex::percent);
    }
  }

  void resetMeters(){
    for(vex::motor m: motors){
      m.setPosition(0, vex::turns);
    }
  }

  double getRotations() {
    int n = motors.size();
    double rotations = 0; 
    for(vex::motor m : motors){
      rotations += m.position(vex::turns);
    }
    return fabs(rotations/n);
  }   

  void drive(bool driveForward=true){
    for(vex::motor m: motors){
      m.spin(driveForward ? vex::forward: vex::reverse);
    }
  }

  void stopMotors() {
    for(vex::motor m: motors){
      m.setStopping(vex::brake);
      m.stop();
    }
  }
};

#endif
