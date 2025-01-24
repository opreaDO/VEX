#include "main.h"

float leftInput; float rightInput;
float leftPower; float rightPower;
bool holdOn = false;

Motor leftA(20, E_MOTOR_GEARSET_06, false);
Motor leftB(19, E_MOTOR_GEARSET_06, false);
Motor leftC(18, E_MOTOR_GEARSET_06, false);
Motor rightA(11, E_MOTOR_GEARSET_06, true);
Motor rightB(12, E_MOTOR_GEARSET_06, true);
Motor rightC(13, E_MOTOR_GEARSET_06, true);
MotorGroup leftDrive({leftA, leftB, leftC});
MotorGroup rightDrive({rightA, rightB, rightC});
Imu imu(10);

Drive chassis (
  // Left Chassis Ports (negative port will reverse it!)
  //   the first port is the sensored port (when trackers are not used!)
  {20, 19, 18}

  // Right Chassis Ports (negative port will reverse it!)
  //   the first port is the sensored port (when trackers are not used!)
  ,{11, 12, 13}

  // IMU Port
  ,10

  // Wheel Diameter (Remember, 4" wheels are actually 4.125!)
  ,2.75

  // Cartridge RPM
  ,600

  // External Gear Ratio (MUST BE DECIMAL)
  // eg. if your drive is 84:36 where the 36t is powered, your RATIO would be 2.333.
  // eg. if your drive is 36:60 where the 60t is powered, your RATIO would be 0.6.
  ,0.75
);

void chassisControl (void) {
//  leftA.move(master.get_analog(ANALOG_LEFT_Y));
//  leftB.move(master.get_analog(ANALOG_LEFT_Y));
//  leftC.move(master.get_analog(ANALOG_LEFT_Y));
//  rightA.move(master.get_analog(ANALOG_RIGHT_Y));
//  rightB.move(master.get_analog(ANALOG_RIGHT_Y));
//  rightC.move(master.get_analog(ANALOG_RIGHT_Y));
  
  // weirdly formatted drive hold + controller screen update [midnight antics]
    
}

void setDrive(int volt) {leftDrive.move(volt); rightDrive.move(volt);}