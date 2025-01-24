/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

bool flySpinning = false;
bool intakeSpinning = false;
bool lipUp = false;

double flyPower = 8;

// A global instance of competition
competition Competition;

// Control Toggles



void lipToggle(void) {
  if (lipUp) {
    lip.set(false);
    flyPower = 10.5;}
  if (!lipUp) {
    lip.set(true);
    flyPower = 8;}
  lipUp = !lipUp;
  if (flySpinning) {
    flywheel.spin(forward, flyPower, volt);}
}

void flyToggle(void) {
  if (flySpinning) {
    flywheel.stop();}
  else {
    flywheel.spin(forward, flyPower, volt);}
  flySpinning = !flySpinning;}

void intakeToggle(void) {
  if (intakeSpinning) {
    rollerIntake.stop();}
  else {
    rollerIntake.spin(forward, 12, volt);}
  intakeSpinning = !intakeSpinning;}

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

void skills_auton(void) {
  flywheel.spin(forward, 10.5, volt);
  Drivetrain.driveFor(reverse, 3, inches);
  rollerIntake.spinFor(reverse, 2.25, sec);
  vexDelay(2250);
  Drivetrain.stop();
  Drivetrain.driveFor(forward, 4, inches);
  vexDelay(2500);
  indexer.set(true);
  vexDelay(2500);
  indexer.set(false);
  vexDelay(2500);
  indexer.set(true);
  vexDelay(2500);
  indexer.set(false);

  Drivetrain.driveFor(forward, 6, inches);
  Drivetrain.turnFor(right, 45, degrees);
  Drivetrain.driveFor(reverse, 6, inches);
  rollerIntake.spinFor(reverse, 2.25, sec);
  vexDelay(2250);
  Drivetrain.stop();
  
  Drivetrain.driveFor(forward, 6, inches);
  Drivetrain.turnFor(left, 45, degrees);
  Drivetrain.driveFor(reverse, 6, inches);
  expansion.set(true);
  vexDelay(500);
  expansion.set(false);
}

void awpAuton(void) {
  flywheel.spin(forward, 10.5, volt);
  Drivetrain.driveFor(reverse, 3, inches);
  rollerIntake.spinFor(reverse, 0.75, sec);
  vexDelay(750);
  Drivetrain.stop();
  vexDelay(2500);
  indexer.set(true);
  vexDelay(1500);
  indexer.set(false);
  vexDelay(1500);
  indexer.set(true);
  vexDelay(1500);
  indexer.set(false);

  Drivetrain.driveFor(forward, 6, inches);
  Drivetrain.turnFor(right, 45, degrees);
  Drivetrain.driveFor(reverse, 6, inches);
  rollerIntake.spinFor(reverse, 0.75, sec);
  vexDelay(2250);
  Drivetrain.stop();
}

void autonomous(void) {
  flywheel.spin(forward, 10.5, volt);
  Drivetrain.driveFor(reverse, 3, inches);
  rollerIntake.spinFor(reverse, 0.75, sec);
  vexDelay(750);
  Drivetrain.stop();
  vexDelay(5000);
  indexer.set(true);
  vexDelay(2500);
  indexer.set(false);
  vexDelay(2500);
  indexer.set(true);
  vexDelay(2500);
  indexer.set(false);
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol(void) {
  lip.set(true);
  lipUp = true;

  Controller1.ButtonL2.pressed(flyToggle);
  Controller1.ButtonRight.pressed(intakeToggle);
  Controller1.ButtonY.pressed(lipToggle);
  while (1) {
    if (Controller1.ButtonR1.pressing()){
      intakeSpinning = true;
      rollerIntake.spin(reverse, 12, volt);
    }

    if (Controller1.ButtonX.pressing()) {
      expansion.set(true);
      vexDelay(500);
      expansion.set(false);}

    if (Controller1.ButtonR2.pressing()) {
      indexer.set(true);}
    else {indexer.set(false);}

    

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
