#include "main.h"
#include "stormlib/led.hpp"
#include "liblvgl/widgets/lv_img.h"
#include "pros/rtos.hpp"

Controller master(pros::E_CONTROLLER_MASTER);

// 0 = Blue, 1 = Red
int allianceColour = 0;

// {{red range}, {blue range}}
int hueValues[2][2] = {{0, 30}, {215, 250}};

Motor ladyBrown(1);
Rotation rotation(2);
bool ladyBrownOn = false;

bool loadHeightOn = false;
int targetRotation = 27900;
int acceptableError = 100;
double kP = 0.25;

Motor intakeA(8);     
Motor intakeB(15);      
MotorGroup intake({8, 15});
Optical optical(7);
bool intakeOn = false;

adi::DigitalOut mogoClamp(1);
adi::DigitalOut doinker(2);
bool clampOn = false;
bool doinkerOn = false;

stormlib::aRGB strand1(3,20);
stormlib::aRGB strand2(4,20);
stormlib::aRGB_manager LEDmanager(&strand1, &strand2, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr);

void ladyBrownControl(void) {
    if ((master.get_digital(DIGITAL_R2)) && !(master.get_digital(DIGITAL_L2)) && (!loadHeightOn)) {
        ladyBrown.move(127);
        ladyBrownOn = true;
    } 
    else if ((master.get_digital(DIGITAL_L2)) && !(master.get_digital(DIGITAL_R2)) && (!loadHeightOn)) {
        ladyBrown.move(-127);
        ladyBrownOn = true;
    }
    else if ((master.get_digital(DIGITAL_L2)) && (master.get_digital(DIGITAL_R2))) {
        loadHeightOn = true; 
        ladyBrownOn = true;   
    }
    else if ((ladyBrownOn) && (!loadHeightOn)) {
        ladyBrown.brake();
        ladyBrownOn = false;
    }

    if (loadHeightOn) {
        double error = targetRotation - rotation.get_angle();
        double motorSpeed = kP * error;
        motorSpeed = std::clamp(motorSpeed, -127.0, 127.0);
        ladyBrown.move(motorSpeed);

        if (abs(rotation.get_angle() - targetRotation) <= acceptableError) {
            loadHeightOn = false;
            ladyBrownOn = false;
        } 
    } 
    }

void intakeControl(void) {
    if (master.get_digital_new_press(DIGITAL_R1) && !(master.get_digital(DIGITAL_L1))) {
        intake.move(127v);
        intakeOn = true;
    }
    if (master.get_digital_new_press(DIGITAL_L1) && !(master.get_digital(DIGITAL_R1))) {
        intake.brake();
        intakeOn = false;
    }
    if ((master.get_digital(DIGITAL_L1)) && (master.get_digital((DIGITAL_R1)))) {
        intake.move(-80);
        intakeOn = true;
    }
}

void poomaticControl(void) {
    if (master.get_digital_new_press(DIGITAL_Y)) {
        clampOn = !clampOn;
        mogoClamp.set_value(clampOn);
    }
    if (master.get_digital_new_press(DIGITAL_RIGHT)) {
        doinkerOn = !doinkerOn;
        doinker.set_value(doinkerOn);
    }
}

// Chassis constructor
ez::Drive chassis(
    // These are your drive motors, the first motor is used for sensing!
    {-16, -9, -20},     // Left Chassis Ports (negative port will reverse it!)
    {4, 5, 6},  // Right Chassis Ports (negative port will reverse it!)

    19,      // IMU Port
    2.75,  // Wheel Diameter (Remember, 4" wheels without screw holes are actually 4.125!)
    600);   // Wheel RPM = cartridge * (motor gear / wheel gear)

void initialize() {
  pros::delay(500);  
  chassis.opcontrol_curve_buttons_toggle(false);   // Enables modifying the controller curve with buttons on the joysticks
  chassis.opcontrol_curve_default_set(3.5);  // Defaults for curve. If using tank, only the first parameter is used. (Comment this line out if you have an SD card!)

  default_constants();

  // Initialize chassis and auton selector
  chassis.initialize();
  master.rumble(chassis.drive_imu_calibrated() ? "." : "---");
  ladyBrown.set_brake_mode(E_MOTOR_BRAKE_HOLD);
  LEDmanager.initialize(20);
}

void disabled() {}

void competition_initialize() {}


void autonomous() {
  chassis.pid_targets_reset();                // Resets PID targets to 0
  chassis.drive_imu_reset();                  // Reset gyro position to 0
  chassis.drive_sensor_reset();               // Reset drive sensors to 0
  chassis.odom_xyt_set(0_in, 0_in, 0_deg);    // Set the current position, you can start at a specific position with this
  chassis.drive_brake_set(MOTOR_BRAKE_HOLD);  // Set motors to hold.  This helps autonomous consistency

  //moveOffLine();
  //awpBlue();
  //awpRed();
  driveBack();
}

void opcontrol() {
  // This is preference to what you like to drive on
  LEDmanager.rainbow();
  chassis.drive_brake_set(MOTOR_BRAKE_COAST);
  intake.set_brake_mode(E_MOTOR_BRAKE_COAST);

  while (true) {
    chassis.opcontrol_tank();  // Tank control
    ladyBrownControl();
    intakeControl();
    poomaticControl();

    pros::delay(ez::util::DELAY_TIME);  // This is used for timer calculations!  Keep this ez::util::DELAY_TIME
  }
}
