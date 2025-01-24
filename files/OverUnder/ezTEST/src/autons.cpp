#include "main.h"

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
    rearWings.set_value(1); delay(400);
    chassis.set_turn_pid(-90, 127); delay(1100);
    rearWings.set_value(0);
    chassis.set_turn_pid(0, 127); delay(600);
    chassis.set_drive_pid(20, 110, true); delay(600);
    chassis.set_turn_pid(-45, 127); delay(600);
    intake.move(127);
    chassis.set_drive_pid(59, 100);
    intake.move(-127); delay(800);
    intake.brake();
}

void farThreeTriball(void) {
    intake.move_relative(-500, 200); delay(500);
    intake.move(127);
    chassis.set_drive_pid(33, 110, true); delay(1500);
    chassis.set_drive_pid(-80, 110, true); delay(1500);
    chassis.set_turn_pid(135, 110); delay(600);
    intake.move(-127);
    rearWings.set_value(1);
    chassis.set_drive_pid(28, 110, true); delay(700);
    // turn used to be 65 deg
    chassis.set_turn_pid(30, 127); delay(700);    
    rearWings.set_value(0); delay(150);
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

void middleRush(void) {
    chassis.set_drive_pid(100, 110); chassis.wait_drive();
    chassis.set_turn_pid(90, 100); chassis.wait_drive();
    chassis.set_swing_pid(LEFT_SWING, 90, 100); chassis.wait_drive();
    chassis.set_swing_pid(RIGHT_SWING, 90, 100); chassis.wait_drive();
}