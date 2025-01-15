#include "main.h"

Controller master(pros::E_CONTROLLER_MASTER);

Motor ladyBrown(1);
Rotation rotation(2);

Motor intakeA(8);     
Motor intakeB(18);      
MotorGroup intake({8, 18});
Optical optical(7);
bool intakeOn = false;
bool ladyBrownOn = false;

bool loadHeightOn = false;
int targetRotation = 27900;
int acceptableError = 100;
double kP = 0.25;

adi::DigitalOut mogoClamp(1);
adi::DigitalOut doinker(2);
bool clampOn = false;
bool doinkerOn = false;

/////
// For installation, upgrading, documentations, and tutorials, check out our website!
// https://ez-robotics.github.io/EZ-Template/
/////

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
    else if (ladyBrownOn) {
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
        intake.move(105);
        intakeOn = true;
    }
    if (master.get_digital_new_press(DIGITAL_L1) && !(master.get_digital(DIGITAL_R1))) {
        intake.brake();
        intakeOn = false;
    }
    if ((master.get_digital(DIGITAL_L1)) && (master.get_digital((DIGITAL_R1)))) {
        intake.move(-60);
        intakeOn = true;
    }
}

// 0 = Blue, 1 = Red
int opposingAlliance = 0;

// {{red range}, {blue range}}
int hueValues[2][2] = {{60, 300}, {180, 60}};

void colourSorting(void) {
    if ((optical.get_hue() < hueValues[opposingAlliance][0]) && (optical.get_hue() > hueValues[opposingAlliance][1]) && (intakeOn)) {
        intake.move(-127); delay(250);
        intake.move(127); delay(1000); // delay before it starts detecting colours again
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
  pros::delay(500);  // Stop the user from doing anything while legacy ports configure
  // Configure your chassis controls
  //chassis.opcontrol_curve_buttons_toggle(true);   // Enables modifying the controller curve with buttons on the joysticks
  //chassis.opcontrol_drive_activebrake_set(0.0);   // Sets the active brake kP. We recommend ~2.  0 will disable.
  chassis.opcontrol_curve_default_set(3.5);  // Defaults for curve. If using tank, only the first parameter is used. (Comment this line out if you have an SD card!)

  // Set the drive to your own constants from autons.cpp!
  default_constants();

  // Initialize chassis and auton selector
  chassis.initialize();
  master.rumble(chassis.drive_imu_calibrated() ? "." : "---");
  //ladyBrown.set_brake_mode(E_MOTOR_BRAKE_HOLD);
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {
  // . . .
}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {
  // . . .
}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {
  chassis.pid_targets_reset();                // Resets PID targets to 0
  chassis.drive_imu_reset();                  // Reset gyro position to 0
  chassis.drive_sensor_reset();               // Reset drive sensors to 0
  chassis.odom_xyt_set(0_in, 0_in, 0_deg);    // Set the current position, you can start at a specific position with this
  chassis.drive_brake_set(MOTOR_BRAKE_HOLD);  // Set motors to hold.  This helps autonomous consistency

  /*
  Odometry and Pure Pursuit are not magic

  It is possible to get perfectly consistent results without tracking wheels,
  but it is also possible to have extremely inconsistent results without tracking wheels.
  When you don't use tracking wheels, you need to:
   - avoid wheel slip
   - avoid wheelies
   - avoid throwing momentum around (super harsh turns, like in the example below)
  You can do cool curved motions, but you have to give your robot the best chance
  to be consistent
  */
  moveOffLine();
}

/**
 * Gives you some extras to run in your opcontrol:
 * - run your autonomous routine in opcontrol by pressing DOWN and B
 *   - to prevent this from accidentally happening at a competition, this
 *     is only enabled when you're not connected to competition control.
 * - gives you a GUI to change your PID values live by pressing X
 */
void ez_template_extras() {
  // Only run this when not connected to a competition switch
  if (!pros::competition::is_connected()) {
    // PID Tuner
    // - after you find values that you're happy with, you'll have to set them in auton.cpp

    // Enable / Disable PID Tuner
    //  When enabled:
    //  * use A and Y to increment / decrement the constants
    //  * use the arrow keys to navigate the constants
    if (master.get_digital_new_press(DIGITAL_X))
      chassis.pid_tuner_toggle();

    // Trigger the selected autonomous routine
    if (master.get_digital(DIGITAL_B) && master.get_digital(DIGITAL_DOWN)) {
      pros::motor_brake_mode_e_t preference = chassis.drive_brake_get();
      autonomous();
      chassis.drive_brake_set(preference);
    }

    // Allow PID Tuner to iterate
    chassis.pid_tuner_iterate();
  }

  // Disable PID Tuner when connected to a comp switch
  else {
    if (chassis.pid_tuner_enabled())
      chassis.pid_tuner_disable();
  }
}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol() {
  // This is preference to what you like to drive on
  ladyBrown.set_brake_mode(E_MOTOR_BRAKE_HOLD);
  chassis.drive_brake_set(MOTOR_BRAKE_COAST);
  intake.set_brake_mode(E_MOTOR_BRAKE_COAST);

  while (true) {
    // Gives you some extras to make EZ-Template ezier
    //ez_template_extras();

    chassis.opcontrol_tank();  // Tank control
    ladyBrownControl();
    intakeControl();
    poomaticControl();
    // chassis.opcontrol_arcade_standard(ez::SPLIT);   // Standard split arcade
    // chassis.opcontrol_arcade_standard(ez::SINGLE);  // Standard single arcade
    // chassis.opcontrol_arcade_flipped(ez::SPLIT);    // Flipped split arcade
    // chassis.opcontrol_arcade_flipped(ez::SINGLE);   // Flipped single arcade

    // . . .
    // Put more user control code here!
    // . . .

    pros::delay(ez::util::DELAY_TIME);  // This is used for timer calculations!  Keep this ez::util::DELAY_TIME
  }
}
