/*
  ************************************************************************************
  * MIT License
  *
  * Copyright (c) 2023 Crunchlabs LLC (Domino Robot Code)

  * Permission is hereby granted, free of charge, to any person obtaining a copy
  * of this software and associated documentation files (the "Software"), to deal
  * in the Software without restriction, including without limitation the rights
  * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  * copies of the Software, and to permit persons to whom the Software is furnished
  * to do so, subject to the following conditions:
  *
  * The above copyright notice and this permission notice shall be included in all
  * copies or substantial portions of the Software.
  *
  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
  * INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
  * PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
  * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF
  * CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE
  * OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
  *
  ************************************************************************************
*/

//motor driver library
#include <SparkFun_TB6612.h>            

//servo controller library
#include <Servo.h>                                   

//button handling library
#include <OneButton.h>                                      

//P term for the PID controller
#define KP                0.4        

//D term for the PID controller
#define KD                0.8        

//PWM value to make the servo move right
#define SERVO_RIGHT       20                   
            
//PWM value to make the servo move left.
#define SERVO_LEFT        180                     

// Pin 13 for domino dispensing servo
#define SERVO_PIN         13             

// Pin 9 is for motor A driver input 1 
#define AIN1              9                                 

// Pin 7 is for motor B driver input 1
#define BIN1              7                               

// Pin 10 is for motor A driver input 2
#define AIN2              10                            

// Pin 6 is for motor B driver input 2
#define BIN2              6                                 

// Pin 11 is for Motor a driver, PWM 
#define PWMA              11                                

// Pin5 is for Motor b driver, PWM
#define PWMB              5                                 

// Pin8 is for standby
#define STBY              8                                 

// Offset for Motor A Switch to -1 if the motor is running backwards
#define OFFSET_A          1                                 

// Offset for Motor B Set to -1 if the motor is running backwards
#define OFFSET_B          1                                 

// Pin 12 is the switch for detecting domino outage
#define BUTTON_PIN        12                                

// Left line sensor pin
#define LEFT_SENSOR_PIN   A1                                

// Right sensor pin
#define RIGHT_SENSOR_PIN  A0                                

// PWM value for max speed of motors
#define TOP_SPEED         90                                

// value combined motor speed  needs to reach to drop a domino.
// Decrasing this puts dominoes closer together.
#define DISPENSE_DISTANCE 500000                            

//Create an instance of servo motor object      
Servo servoMotor;                                         

// set up the drive motors
Motor motor1 = Motor(AIN1, AIN2, PWMA, OFFSET_A, STBY);
Motor motor2 = Motor(BIN1, BIN2, PWMB, OFFSET_B, STBY);

//initialize all speed variables to 0
int combinedmotorspeed, leftMotorSpeed, rightMotorSpeed;    

// set all pid variables to 0
float lastError, derivative, controlSignal;                
int error;

//set the values for the Line sensor variables to 0
int leftSensorValue, rightSensorValue;                      

//Out of dominoes switch setup //Active high, no internal pullup resistor
OneButton stopButton = OneButton(BUTTON_PIN, false, false); 
bool stopButtonPressed = false;                             //Boolean for tracking the state of the button

//Distance based domino dropping variables
unsigned long distanceSinceLastDrop = DISPENSE_DISTANCE;    //Starting with this as DISPENSE_DISTANCE makes the vehicle drop a domino immediately.
bool dominoDropped = false;

void setup()
{
  // Enable the motor driver
  digitalWrite(STBY, HIGH);                  

  // attach the servo to the specified pin
  servoMotor.attach(SERVO_PIN);          

   //Set initial servo position to the left to pick up a domino for immediate dispensing    
  servoMotor.write(SERVO_LEFT);             
  
  //Set up the button handler to detect long press of limit switch. 
  
  stopButton.setPressMs(200);                

  //Have to use longPress because switch is pressed and held, not pressed and release as a single click.
  stopButton.attachLongPressStart(
      //Lambda function that sets stopButtonPressed flag to true when the switch is pressed.
    []() {      
    stopButtonPressed = true;                
  });
  //wait most of a second just to be sure that the domino is picked up.
  delay(800);                                
}

void loop() {
  //First, take care of the line following functions. We want to follow the line regardless of whether or not we're out of dominoes.
  //Even when the vehicle runs out of dominoes, it should follow the line to the next point where a domino needs to be, then stop.
  
  //Read the line sensors and calculate control signal.
  leftSensorValue = analogRead(LEFT_SENSOR_PIN);                
  rightSensorValue = analogRead(RIGHT_SENSOR_PIN);

  //Calculate the error (difference between the two sensor values)
  error = leftSensorValue - rightSensorValue;                 

  //Calculate the derivative term, which is how fast the error is changing  
  derivative = error - lastError;               

  //Calculate the control signal                
  controlSignal = (KP * error) + (KD * derivative);     

  //Store the current error for the next iteration        
  lastError = error;                                            

  // Calculate motor speeds based on the control signal
  //If the error is positive, this slows down the motor on the left
  leftMotorSpeed = TOP_SPEED - controlSignal;    

  //and speeds up the motor on the right. Vice versa if the error is negative.               
  rightMotorSpeed = TOP_SPEED + controlSignal;                 

  // Ensure motor speeds are within the valid range
  //This makes the speed be somewhere between 0 and TOP_SPEED
  leftMotorSpeed = constrain(leftMotorSpeed, 0, TOP_SPEED);     
  rightMotorSpeed = constrain(rightMotorSpeed, 0, TOP_SPEED);
  
  // Apply motor speeds
  motor1.drive(leftMotorSpeed);
  motor2.drive(rightMotorSpeed);
  combinedmotorspeed = leftMotorSpeed + rightMotorSpeed;
  distanceSinceLastDrop += combinedmotorspeed;

  //That's it for the line following functions, now move on to dispensing dominoes at the appropriate time.

  stopButton.tick();                    //Check the switch to see if we're out of dominoes or not. This has to be called every time through the loop()
  
  //If the limit switch is not pressed, this is true and the domino dispensing code executes
  if (!stopButtonPressed) {             
    //figure out when to dispense a domino based on how far the robot has travelled.
    //if we've travelled far enough and a domino hasn't been dropped yet
    if ((distanceSinceLastDrop >= DISPENSE_DISTANCE) && !dominoDropped) {           
      servoMotor.write(SERVO_RIGHT);
      distanceSinceLastDrop = 0;                                                       //reset the distance count to 0 because we just dropped a domino
      dominoDropped = true;                                                            //domino has been dropped
    } else if ((distanceSinceLastDrop >= 0.7 * DISPENSE_DISTANCE) && dominoDropped) {  //if a domino was dropped and we're far enough away to close the domino gate without jamming
      servoMotor.write(SERVO_LEFT);                                                    //pick up a new domino for dropping
      dominoDropped = false;                                                           //we haven't dropped the new domino, so now this is false
    }
  }
  else {                                                //This code executes if the limit switch is pressed (vehicle is out of dominoes)
    if (!dominoDropped) {                               //Check if a domino has been dropped
      servoMotor.write(SERVO_RIGHT);                    //If a domino is still in the magazine, drop the domino
      distanceSinceLastDrop = 0;                        //Reset the distanceSinceLastDrop
      dominoDropped = true;
    }
    if (distanceSinceLastDrop >= DISPENSE_DISTANCE) {   //Drive to the next point where a domino needs to be dropped.
      motor1.brake();                                   //Stop both motors.
      motor2.brake();
      
      //Stay in this position forever. This loop just repeats endlessly, or at least until the physical reset button is pressed.
      while(true);                                      
    }
  }
}
