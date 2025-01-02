// motor driver library
#include <SparkFun_TB6612.h>

// servo controller library
#include <Servo.h>          

// button handling library
#include <OneButton.h> 

// P term for the PID controller
#define KP                0.4   

// D term for the PID controller
#define KD                0.8 

// PWM value to make the servo move right
#define SERVO_RIGHT       20 
// PWM value to make the servo move left
#define SERVO_LEFT        180

// pin 13 for domino dispensing servo
#define SERVO_PIN         13

// pin 9 is for Motor A driver, input 1
#define AIN1              9 

// pin 7 is for Motor B driver, input 1 
#define BIN1              7  

// pin 10 is for Motor A driver, input 2
#define AIN2              10

// pin 6 is for Motor B driver, input 2
#define BIN2              6

// pin 11 is for Motor A driver, PWM 
#define PWMA              11 

// pin 5 is for Motor B driver, PWM 
#define PWMB              5

// pin 8 is for Standby driver
#define STBY              8

// Offset for Motor A. set to -1 if the motor is running backwards
#define OFFSET_A          1                                 

// Offset for Motor B. set to -1 if the motor is running backwards
#define OFFSET_B          1

// pin 12 is the the switch for detecting domino outage
#define BUTTON_PIN        12                                

// Left line sensor pin
#define LEFT_SENSOR_PIN   A1                                

// Right sensor pin
#define RIGHT_SENSOR_PIN  A0                                

#define TOP_SPEED         90                                // PWM value for max speed of motors

// Value combinedMotorSpeed needs to reach to drop a domino. 
// Decreasing this puts dominoes closer together.
#define DISPENSE_DISTANCE 500000                         

Servo servoMotor;   // create an instance of servo motor object 

Motor motor1 = Motor(AIN1, AIN2, PWMA, OFFSET_A, STBY); //set up the drive motors
Motor motor2 = Motor(BIN1, BIN2, PWMB, OFFSET_B, STBY);

int combinedmotorspeed, leftMotorSpeed, rightMotorSpeed; // Initializes all speed variables to 0 values
float lastError, derivative, controlSignal; // Define variables for PID control
int error; 

int leftSensorValue, rightSensorValue; // variables for storing the value of the line sensors

OneButton stopButton = OneButton(BUTTON_PIN, false, false); // Out of dominoes switch setup
bool stopButtonPressed = false;               // Bool variable for tracking the state of the button

// Distance based domino dropping variables
// Starting with this as DISPENSE_DISTANCE makes the vehicle drop a domino immediately.
unsigned long distanceSinceLastDrop = DISPENSE_DISTANCE;    
bool dominoDropped = false;

void setup()
{
  digitalWrite(STBY, HIGH);                  // Enable the motor driver
  servoMotor.attach(SERVO_PIN);              // Attach the servo to the specified pin
  servoMotor.write(SERVO_LEFT);              // Set initial servo position to the left to pick up a domino for immediate dispensing
  
  // Set up the button handler to detect long press of limit switch. 
  // Sets up the button handler to wait for 200ms before reporting the limit switch is pressed.
  stopButton.setPressMs(200);                
  
  // Have to use longPress because switch is pressed and held, not pressed and release as a single click.
  stopButton.attachLongPressStart(
    // This code not running when setup() is run
    []() { 
      //Lambda function that sets stopButtonPressed flag to true when the switch is pressed.
      stopButtonPressed = true; 
    }
  );
  
  // wait most of a second just to be sure that the domino is picked up.
  delay(800);
}

void loop() {
  // First, take care of the line following functions. 
  // We want to follow the line regardless of whether or not we're out of dominoes.
  // Even when the vehicle runs out of dominoes, it should follow the line to the next point
  // where a domino needs to be, then stop.

  leftSensorValue = analogRead(LEFT_SENSOR_PIN);                 // Read the line sensors and calculate control signal
  rightSensorValue = analogRead(RIGHT_SENSOR_PIN);

  error = leftSensorValue - rightSensorValue; // Calculate the error (difference between the two sensor values)
  
  derivative = error - lastError; // Calculate the derivative term, which is how fast the error is changing

  controlSignal = KP * error + KD * derivative; // Calculate the control signal

  lastError = error; // Store the current error for the next iteration

  // Calculate motor speeds based on the control signal
  // If the error is positive, this slows down the motor on the left
  // and speeds up the motor on the right. Vice versa if the error is negative.
  leftMotorSpeed = TOP_SPEED - controlSignal;
  rightMotorSpeed = TOP_SPEED + controlSignal;

  // Ensure motor speeds are within the valid range
  // This makes the speed be somewhere between 0 and TOP_SPEED
  leftMotorSpeed = constrain(leftMotorSpeed, 0, TOP_SPEED);     
  rightMotorSpeed = constrain(rightMotorSpeed, 0, TOP_SPEED);
  
  motor1.drive(leftMotorSpeed);   // Apply motor speeds
  motor2.drive(rightMotorSpeed);
  
  combinedmotorspeed = leftMotorSpeed + rightMotorSpeed;
  distanceSinceLastDrop += combinedmotorspeed;   // That's it for the line following functions

  // Move on to dispensing dominoes at the appropriate time 
  // Check the switch to see if we're out of dominoes or not
  // This has to be called every time through the loop()
  stopButton.tick();                   
  
  // If the limit switch is not pressed, this is true and the domino dispensing code executes
  if (!stopButtonPressed) {  // figure out when to dispense a domino based on how far the robot has traveled

    if ((distanceSinceLastDrop >= DISPENSE_DISTANCE) && !dominoDropped) { // if we've traveled far enough and a domino hasn't been dropped yet
      servoMotor.write(SERVO_RIGHT); 
      distanceSinceLastDrop = 0; // reset the distance count to 0 because we just dropped a domino
      dominoDropped = true; // domino has been dropped 
    } else if ((distanceSinceLastDrop >= 0.7 * DISPENSE_DISTANCE) && dominoDropped) {
      // if a domino was dropped and we're far enough away to close the domino gate without jamming
      servoMotor.write(SERVO_LEFT); // pick up a new domino for dropping
      dominoDropped = false; // we haven't dropped the new domino, so now this is false.
    }
  } else {                    // this code executes if the limit switch is pressed (vehicle is out of dominoes)
    if (!dominoDropped) { // check if a domino has been dropped
      servoMotor.write(SERVO_RIGHT); // If a domino is still in the magazine drop the domino
      distanceSinceLastDrop = 0; // reset the distanceSince LastDrop
      dominoDropped = true;
    }                      

    if (distanceSinceLastDrop >= DISPENSE_DISTANCE) { // Drive to the next point where a domino needs to be dropped. 
      motor1.brake(); // Stop both motors
      motor2.brake();

      // Stay in this position forever
      // This loop just repeats endlessly, or at least until the physical reset button is pressed.
      while(true);
    }      
  }
}
