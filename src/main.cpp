/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// LFM                  motor         8               
// RFM                  motor         7               
// RBM                  motor         5               
// LeftY                encoder       A, B            
// RightY               encoder       G, H            
// X                    encoder       E, F            
// LBM                  motor         4               
// DR4B                 motor_group   11, 6           
// Dummy                bumper        D               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
using namespace vex;

// A global instance of competition
competition Competition;

// define your global instances of motors and other devices here
bool userControl = false;

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

int pird() {

  // Position
    float yPos = (LeftY.position(degrees) + RightY.position(degrees))/2;
    float xPos = X.position(degrees);
    float tspoon =  (LeftY.position(degrees) - RightY.position(degrees))/2;

  // PID system
    // y Position
      float desired = 0;
      float error = 0;
      float prevError = 0;
      float deriv = 0;
    // x Pos
      float sesired = 0;
      float serror = 0;
      float sPrevError = 0;
      float seriv = 0;
    // Turning
      float tesired = 0;
      float terror = 0;
      float tPrevError = 0;
      float teriv = 0;

  // Konstants
    // Going forward
      float kP = 0;
      float kI = 0;
      float kD = 0;
    // Side
      float skP = 0;
      float skI = 0;
      float skD = 0;
    // Turning
      float tkP = 0;
      float tkI = 0;
      float tkD = 0;

    while (!userControl) {
      // PID yPos
        error = yPos - desired;
        prevError += error;
        deriv = error - prevError;
      // PID xPos
        serror = xPos - sesired;
        sPrevError += serror;
        seriv = serror - sPrevError;
      // PID Turning
        terror = tspoon - tesired;
        tPrevError += terror; 
        teriv = terror - tPrevError;

      // Lateral movement
        float proton = (error * kP) + (prevError * kI) + (deriv * kD);
        float neutron = (serror * skP) + (sPrevError * skI) + (seriv * skD);
        float electron = (terror * tkP) + (tPrevError * tkI) + (teriv * tkD);
 
      // Motor Asignment   
        LFM.spin(forward, proton + electron + neutron, pct);
        LBM.spin(forward, proton + electron - neutron, pct);
        RBM.spin(forward, proton - electron + neutron, pct);
        RFM.spin(forward, proton - electron - neutron, pct);

        wait(10,msec);
    }
    

  return 1;
}

int resetPos() {
  LeftY.resetRotation();
  RightY.resetRotation();
  X.resetRotation();
  return 1;
}


void autonomous(void) {
  // Starting the engines
    vex::task drivePID(pird);
    vex::task resetpo(resetPos);
  // Autonomous commands





}

bool cancel = false;

int rueben() {
  Controller1.Screen.print("3.....");
  wait(1,sec);
  Controller1.Screen.print("2.....");
  wait(1,sec);
  Controller1.Screen.print("1.....");
  wait(1,sec);
  if (!cancel) {
  Controller1.Screen.print("Bye Bye");
  userControl = false;
  } else {
  Controller1.Screen.print("No worries");
  }
  wait(5,sec);
  userControl = true;
  return 1;
}

void usercontrol(void) {
  // User control code here, inside the loop
  userControl = true;
  while (userControl) {

  // Driving
    // User Motor inputs
      float pwr = Controller1.Axis3.position(percent);
      float speen = Controller1.Axis1.position(percent);
      float side = Controller1.Axis4.position(percent);
    // Motor Asignment
      LFM.spin(forward, pwr + speen + side, pct);
      LBM.spin(forward, pwr + speen - side, pct);
      RFM.spin(forward, pwr - speen - side, pct);
      RBM.spin(forward, pwr - speen + side, pct);

  // Special Sauce
    // DR4B
      if (Controller1.ButtonR1.pressing()) {
        DR4B.spin(forward, 100, pct);
      } else if (Controller1.ButtonR2.pressing()) {
        DR4B.spin(reverse, 100, pct);
      } else {
        DR4B.stop();
      }

  // Rueben's here
    // Time to fix that
      if (Dummy.pressing()) {
      cancel = false;
      vex::task stoopid(rueben);
      }
      if (Controller1.ButtonX.pressing()) cancel = true;

    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
