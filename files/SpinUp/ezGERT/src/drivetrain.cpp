#include "main.h"
#include "pros/misc.h"
#include "pros/motors.h"
#include <cmath>

int leftTarget; int rightTarget;
int leftPower; int rightPower;
int leftPrev; int rightPrev;

bool driveInvert = false;
bool brakeHold = false;
std::string driveCurrent = "FW";
std::string brakeCurrent = "NB";

Motor leftA(7, E_MOTOR_GEARSET_06, false);
Motor leftB(8, E_MOTOR_GEARSET_06, false);
Motor leftC(9, E_MOTOR_GEARSET_06, false);
Motor rightA(1, E_MOTOR_GEARSET_06, true);
Motor rightB(2, E_MOTOR_GEARSET_06, true);
Motor rightC(3, E_MOTOR_GEARSET_06, true);
MotorGroup leftDrive({leftA, leftB, leftC});
MotorGroup rightDrive({rightA, rightB, rightC});
MotorGroup drive({leftA, leftB, leftC, rightA, rightB, rightC});

// Chassis constructor
Drive chassis (
  // Left Chassis Ports (negative port will reverse it!)
  //   the first port is the sensored port (when trackers are not used!)
  {7, 8, 9}

  // Right Chassis Ports (negative port will reverse it!)
  //   the first port is the sensored port (when trackers are not used!)
  ,{-1, -2, -3}

  // IMU Port
  ,10

  // Wheel Diameter (Remember, 4" wheels are actually 4.125!)
  //    (or tracking wheel diameter)
  ,2.75

  // Cartridge RPM
  //   (or tick per rotation if using tracking wheels)
  ,360

  // External Gear Ratio (MUST BE DECIMAL)
  //    (or gear ratio of tracking wheel)
  // eg. if your drive is 84:36 where the 36t is powered, your RATIO would be 2.333.
  // eg. if your drive is 36:60 where the 60t is powered, your RATIO would be 0.6.
  ,0.6

  // Uncomment if using tracking wheels
  // Left Tracking Wheel Ports (negative port will reverse it!)
  	 ,{-3, -4} // 3 wire encoder
  // Right Tracking Wheel Ports (negative port will reverse it!)
	 ,{5, 6} // 3 wire encoder


  // Uncomment if tracking wheels are plugged into a 3 wire expander
  // 3 Wire Port Expander Smart Port
  // ,1
);


float gradient = 0.5;
float scaledInput = 127;
float scaledOutput = 12000;

void chassisControl (void) {
// leftTarget = master.get_analog(ANALOG_LEFT_Y);
// rightTarget = master.get_analog(ANALOG_RIGHT_Y);
// leftPower = (scaledOutput * tan((leftTarget / scaledInput) * atan(gradient))) / gradient;
// rightPower = (scaledOutput * tan((rightTarget / scaledInput) * atan(gradient))) / gradient;
// 
// leftA.move_voltage((leftPower + leftPrev) / 2);
// leftB.move_voltage((leftPower + leftPrev) / 2);
// leftC.move_voltage((leftPower + leftPrev) / 2);
// rightA.move_voltage((rightPower + rightPrev) / 2);
// rightB.move_voltage((rightPower + rightPrev) / 2);
// rightC.move_voltage((rightPower + rightPrev) / 2);	
// 
// leftPrev = leftPower;
// rightPrev = rightPower;
  
  chassis.tank();

  if (master.get_digital_new_press(DIGITAL_A)) {drive_example();}
  if (master.get_digital_new_press(DIGITAL_B)) {turn_example();}}
