#include "EZ-Template/util.hpp"
#include "globals.h"
#include "main.h"
#include "pros/motors.h"
#include "pros/rtos.hpp"

/*void default_constants() {
  // PID Constants
  chassis.pid_drive_constants_set(10, 0, 100); // Sets forward and backward
  chassis.pid_heading_constants_set(3, 0, 20);
  chassis.pid_turn_constants_set(3, 0, 20);
  chassis.pid_swing_constants_set(5, 0, 30); // Sets forward and backward

  // Swing Constants
  chassis.slew_drive_constants_set(7_in, 80); // Sets forward and backward
  chassis.slew_turn_constants_set(5_deg, 50);
  chassis.slew_swing_constants_set(5_deg, 50); // Sets forward and backward
}*/

void nearOneTriball(void) {
    chassis.set_drive_pid(-45, 110, true); delay(1200);
    chassis.set_turn_pid(40, 100); delay(1200);
    chassis.set_drive_pid(-20, 110, true); delay(1200);
    chassis.set_drive_pid(30, 100, true); delay(1200);
    chassis.set_drive_pid(-30, 127, false); delay(1200);
    chassis.set_drive_pid(20, 110, true); delay(1200);
    chassis.set_drive_brake(pros::E_MOTOR_BRAKE_COAST);
}

void farOneTriball(void) {
    chassis.set_drive_pid(-55, 127, true); delay(1200);
    chassis.set_turn_pid(-40, 127); delay(1200);
    chassis.set_drive_pid(-20, 127, true); delay(1200);
    intake.move(-127); 
    chassis.set_drive_pid(-30, 127, true); delay(1200);
    chassis.set_drive_pid(30, 127, false); delay(1200);
    chassis.set_drive_pid(-20, 127, true); delay(1200);
    chassis.set_drive_brake(pros::E_MOTOR_BRAKE_COAST);
}

/*
void nearThreeTriball(void) {
    chassis.set_drive_pid(75, 110, true); chassis.wait_drive();
    chassis.set_turn_pid(-90, 100); chassis.wait_drive();
    intake.move_relative(-1000, 200);
    chassis.set_drive_pid(20, 110, true); chassis.wait_drive();
    chassis.set_drive_pid(-15, 110, true); chassis.wait_drive();
    chassis.set_turn_pid(90, 100); chassis.wait_drive();
    intake.move(127);
    chassis.set_drive_pid(20, 110, true); chassis.wait_drive();
    chassis.set_turn_pid(180, 100); chassis.wait_drive();
    intake.brake();
    chassis.set_drive_pid(20, 110, false); chassis.wait_drive();
    chassis.set_drive_pid(-15, 110, true); chassis.wait_drive();
    chassis.set_turn_pid(180, 100); chassis.wait_drive();
    intake.move(127);
    chassis.set_drive_pid(50, 110, true); chassis.wait_drive();
    chassis.set_drive_pid(-5, 110, false); chassis.wait_drive();
    chassis.set_turn_pid(180, 100); chassis.wait_drive();
    intake.brake();
    chassis.set_drive_pid(50, 110, true); chassis.wait_drive();
    chassis.set_drive_pid(-10, 110, false); chassis.wait_drive();
    chassis.set_drive_brake(pros::E_MOTOR_BRAKE_COAST);
}*/

void partialAWP(void) {
    intake.move_relative(-500, 200); delay(500);
    chassis.set_drive_pid(-50, 110, true); delay(1200);
    chassis.set_turn_pid(45, 100); delay(1200);
    chassis.set_drive_pid(-20, 110, true); delay(1200);
    chassis.set_drive_pid(15, 100, true); delay(1200);
    //chassis.set_drive_pid(-30, 127, false); delay(1200);
    //chassis.set_drive_pid(20, 110, true); delay(1200);
    chassis.set_turn_pid(0, 110); delay(500);
    chassis.set_drive_pid(30, 110, true); delay(1200);
    rearWings.set_value(0); delay(400);
    chassis.set_turn_pid(-90, 127); delay(1100);
    rearWings.set_value(1);
    chassis.set_turn_pid(0, 127); delay(600);
    chassis.set_drive_pid(20, 110, true); delay(600);
    chassis.set_turn_pid(-45, 127); delay(600);
    intake.move(127);
    chassis.set_drive_pid(59, 100);
    intake.move(-127); delay(800);
    intake.brake();
}

void farFiveTriball(void) {
    chassis.set_drive_brake(pros::E_MOTOR_BRAKE_HOLD);

    chassis.set_drive_brake(pros::E_MOTOR_BRAKE_COAST);
}

void basicSkills(void) {
    chassis.set_drive_pid(-40, 110, true); delay(2000);
    chassis.set_turn_pid(-20, 100); delay(1000);
    chassis.set_drive_pid(-10, 110, true); delay(1500);
    rearWings.set_value(1);
    
}

void skillsPush(void) {
    chassis.set_drive_pid(-40, 110, true); delay(2000);
    chassis.set_turn_pid(-20, 100); delay(1000);
    chassis.set_drive_pid(-10, 110, true); delay(1500);
    rearWings.set_value(1);
    chassis.set_drive_pid(70, 110, true); delay(3000);
    chassis.set_turn_pid(25, 100); delay(1500);
}

void farThreeTriball(void) {
    intake.move_relative(-500, 200); delay(500);
    intake.move(127);
    chassis.set_drive_pid(33, 110, true); delay(1500);
    chassis.set_drive_pid(-80, 110, true); delay(1500);
    chassis.set_turn_pid(135, 110); delay(600);
    intake.move(-127);
    rearWings.set_value(0);
    chassis.set_drive_pid(28, 110, true); delay(700);
    // turn used to be 65 deg
    chassis.set_turn_pid(30, 127); delay(700);    
    rearWings.set_value(1); delay(150);
    chassis.set_turn_pid(150, 110); delay(400);
    chassis.set_drive_pid(17, 110, true); delay(500);
    chassis.set_turn_pid(90, 110); delay(500);
    chassis.set_drive_pid(20, 127, true); delay(600);
    chassis.set_drive_pid(-40, 127, true); delay(600);
    chassis.set_turn_pid(112, 127); delay(400);
    chassis.set_drive_pid(50, 127, false); delay(800);
    chassis.set_drive_pid(-50, 127, false); delay(800);
    chassis.set_drive_pid(50, 127, false); delay(800);
    chassis.set_drive_pid(-50, 127, false); delay(800);
    chassis.set_drive_pid(50, 127, false); delay(800);
    chassis.set_drive_pid(-50, 127, false); delay(800);
    intake.brake();
}