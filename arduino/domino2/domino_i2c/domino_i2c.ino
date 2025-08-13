#include "spark_fun.h"                                     //motor driver library
#include "controller.h"

#define AIN1              9                                 //motor driver
#define BIN1              7                                 //motor driver
#define AIN2              10                                //motor driver
#define BIN2              6                                 //motor driver
#define PWMA              11                                //motor driver
#define PWMB              5                                 //motor driver
#define STBY              8                                 //motor driver
#define OFFSET_A          1                                 //Switch to -1 if the motor is running backwards
#define OFFSET_B          1                                 //Switch to -1 if the motor is running backwards
#define BUTTON_PIN        12                                //The pin the switch for detecting domino outage is connected to.
#define TOP_SPEED         90                                //PWM value for max speed of motors

Motor motor1 = Motor(AIN1, AIN2, PWMA, OFFSET_A, STBY);
Motor motor2 = Motor(BIN1, BIN2, PWMB, OFFSET_B, STBY);
int combinedmotorspeed, leftMotorSpeed, rightMotorSpeed;    //creating variables like this initializes all their values to 0.

Controller controller(0x50);

double inOutRatio = TOP_SPEED/511.0;

void setup()
{
  digitalWrite(STBY, HIGH);                  //Enable the motor driver  
  controller.start();
  Serial.begin(9600);
  delay(500);                                
}

void loop() {
  controller.update();
  int16_t xAxis = controller.getState().x_Axis * inOutRatio;
  int16_t yAxis = controller.getState().y_Axis * inOutRatio;  
  
  leftMotorSpeed = xAxis  + yAxis;
  rightMotorSpeed = xAxis - yAxis;

  motor1.drive(leftMotorSpeed);
  motor2.drive(rightMotorSpeed);  
}