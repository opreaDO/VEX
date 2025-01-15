#include "main.h"

Controller master(pros::E_CONTROLLER_MASTER);

void initialize() {
  pros::delay(500);  // Stop the user from doing anything while legacy ports configure
  chassis.opcontrol_curve_default_set(3.5);  // Defaults for curve. If using tank, only the first parameter is used. (Comment this line out if you have an SD card!)

  // Set the drive to your own constants from autons.cpp!
  default_constants();

  chassis.initialize();
  LEDmanager.initialize(20);
	static Gif gif("/usd/slideshow.gif", lv_scr_act());
  master.rumble(chassis.drive_imu_calibrated() ? "." : "---");
}

void disabled() {

}


void competition_initialize() {

}

void autonomous() {
  chassis.pid_targets_reset();                // Resets PID targets to 0
  chassis.drive_imu_reset();                  // Reset gyro position to 0
  chassis.drive_sensor_reset();               // Reset drive sensors to 0
  chassis.odom_xyt_set(0_in, 0_in, 0_deg);    // Set the current position, you can start at a specific position with this
  chassis.drive_brake_set(MOTOR_BRAKE_HOLD);  // Set motors to hold.  This helps autonomous consistency

  moveOffLine();
}

void opcontrol() {
  ladyBrown.set_brake_mode(E_MOTOR_BRAKE_HOLD);
  chassis.drive_brake_set(MOTOR_BRAKE_COAST);
  intake.set_brake_mode(E_MOTOR_BRAKE_COAST);
  rgb();

  while (true) {
    chassis.opcontrol_tank();  // Tank control
    ladyBrownControl();
    intakeControl();
    poomaticControl();

    pros::delay(ez::util::DELAY_TIME);  // This is used for timer calculations!  Keep this ez::util::DELAY_TIME
  }
}
