/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\trish                                            */
/*    Created:      Thu Mar 02 2023                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "sylib/system.hpp"
#include "vex.h"
#include "sylib/sylib.hpp"
#include "vex_competition.h"
#include "vex_drivetrain.h"
#include "vex_global.h"
#include "vex_triport.h"

using namespace vex;
competition Competition;

triport expander = triport(PORT13);
digital_out endgame = digital_out(expander.F);
digital_out lip = digital_out(expander.G);
digital_out blocker = digital_out(expander.H);

motor leftA = motor(PORT7, ratio6_1, false);
motor leftB = motor(PORT8, ratio6_1, false);
motor leftC = motor(PORT9, ratio6_1, false);
motor_group LeftDriveSmart = motor_group(leftA, leftB, leftC);
motor rightA = motor(PORT1, ratio6_1, true);
motor rightB = motor(PORT2, ratio6_1, true);
motor rightC = motor(PORT3, ratio6_1, true);
motor_group RightDriveSmart = motor_group(rightA, rightB, rightC);
inertial Inertial = inertial(PORT10);
smartdrive Drivetrain = smartdrive(LeftDriveSmart, RightDriveSmart, Inertial, 319.19, 258, 40, mm, 0.6);
motor intake = motor(PORT20, ratio18_1, true);
controller Controller1 = controller(primary);
sylib::SpeedControllerInfo flyController (
        [](double rpm){return 3;}, // kV function
        0.001, // kP
        1, // kI
        1, // kD
        0.001 // kH
);
sylib::Motor fly(15, 3600, true, flyController);

bool intakeSpinning = false;
void intakeToggle(void) {
  if (intakeSpinning) {intake.stop();}
  else {intake.spin(forward, 12, volt);}
  intakeSpinning = !intakeSpinning;}

bool flySpinning = false;
void flyToggle(void) {
  if (flySpinning) {fly.stop();}
  else {fly.set_velocity_custom_controller(2700);}
  flySpinning = !flySpinning;}

bool lipActive = false;
void lipToggle (void) {
  if (lipActive) {lip.set(false);}
  else {lip.set(true);}
  lipActive = !lipActive;
}

void rgb (void) {
    auto addrled1 = sylib::Addrled(22,1,25);
    addrled1.gradient(0xFF0000, 0xFF0005, 0, 0, false, true);
    addrled1.cycle(*addrled1, 4);
    auto addrled2 = sylib::Addrled(22,2,25);
    addrled2.gradient(0xFF0000, 0xFF0005, 0, 0, false, true);
    addrled2.cycle(*addrled2, 4);
}

void pre_auton (void) {
  vexcodeInit();
  sylib::initialize();
  rgb();
}

void autonomous(void) {
  Drivetrain.driveFor(-5, inches, true);
  intake.spinFor(350, msec);
  Drivetrain.driveFor(5, inches, true);
  Drivetrain.turnFor(-15, degrees);
  intake.spinFor(500, msec);
  vexDelay(1250);
  intake.spinFor(500, msec);
}

void usercontrol(void) {
  std::uint32_t now = sylib::millis();
  Controller1.ButtonL1.pressed(flyToggle);
  Controller1.ButtonL2.pressed(intakeToggle);
  Controller1.ButtonY.pressed(lipToggle);

  while (1) {
    leftA.spin(vex::directionType::fwd, Controller1.Axis2.value(), vex::voltageUnits::volt);
    leftB.spin(vex::directionType::fwd, Controller1.Axis2.value(), vex::voltageUnits::volt);
    leftC.spin(vex::directionType::fwd, Controller1.Axis2.value(), vex::voltageUnits::volt);
    rightA.spin(vex::directionType::fwd, Controller1.Axis3.value(), vex::voltageUnits::volt);                 
    rightB.spin(vex::directionType::fwd, Controller1.Axis3.value(), vex::voltageUnits::volt);
    rightC.spin(vex::directionType::fwd, Controller1.Axis3.value(), vex::voltageUnits::volt);
    
    ///////////////////////////////////////// Intake Controls (Start) ////////////////////////////////////
    if (Controller1.ButtonR2.pressing()){
      intakeSpinning = true;
      intake.spin(reverse, 12, volt);
    }
    ///////////////////////////////////////// Intake Controls (End) ////////////////////////////////////
    
    ////////////////////////////////////////  Blocker Controls (Start) /////////////////////////////////
    if (Controller1.ButtonRight.pressing()) {
      endgame.set(true);
      vexDelay(500);
      endgame.set(false);}
    ////////////////////////////////////////  Blocker Controls (End) ///////////////////////////////////

    ////////////////////////////////////////  Endgame Controls (Start) /////////////////////////////////
    if (Controller1.ButtonX.pressing()) {
      endgame.set(true);
      vexDelay(200);
      endgame.set(false);}
    ////////////////////////////////////////  Endgame Controls (End) ///////////////////////////////////

    sylib::delay_until(&now, 10);
  }
}

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
