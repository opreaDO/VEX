#include "main.h"

float leftInput; float rightInput;
float leftPower; float rightPower;
bool holdOn = false;
Motor rightA(11, E_MOTOR_GEARSET_06, false);
Motor rightB(12, E_MOTOR_GEARSET_06, false);
Motor rightC(13, E_MOTOR_GEARSET_06, false);
Motor leftA(20, E_MOTOR_GEARSET_06, true);
Motor leftB(19, E_MOTOR_GEARSET_06, true);
Motor leftC(18, E_MOTOR_GEARSET_06, true);
MotorGroup leftDrive({leftA, leftB, leftC});
MotorGroup rightDrive({rightA, rightB, rightC});
Imu imu(11);

Drive chassis (
  // Left Chassis Ports (negative port will reverse it!)
  //   the first port is the sensored port (when trackers are not used!)
  {-20, -19, -18}

  // Right Chassis Ports (negative port will reverse it!)
  //   the first port is the sensored port (when trackers are not used!)
  ,{11,12,13}

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
  chassis.tank();

  if (master.get_digital_new_press(DIGITAL_LEFT)) {
    holdOn = !holdOn;
    if (holdOn) {
      chassis.set_drive_brake(E_MOTOR_BRAKE_HOLD);
      if (ptoOn) {
        master.print(0, 0, "HOLD - PTO WINCH ");
      } else {master.print(0, 0, "HOLD - PTO DRIVE ");}
    }
    else if (!holdOn) {
      chassis.set_drive_brake(E_MOTOR_BRAKE_COAST);
      if (ptoOn) {
        master.print(0, 0, "COAST - PTO WINCH");
      } else {master.print(0, 0, "COAST - PTO DRIVE");}
    }
  }

	leftInput = master.get_analog(ANALOG_LEFT_Y);
  rightInput = master.get_analog(ANALOG_RIGHT_Y);

//	leftPower = (atan((2 * leftInput - (leftInput / std::abs(leftInput))) * 5.5) / (2 * atan(5.5))) + (leftInput / (2 * std::abs(leftInput))) * 127;
//	rightPower = (atan((2 * rightInput - (rightInput / std::abs(rightInput))) * 5.5) / (2 * atan(5.5))) + (rightInput / (2 * std::abs(rightInput))) * 127;
	
/*	leftA.move(leftInput);
	leftB.move(leftInput);
	leftC.move(leftInput);
	rightA.move(rightInput);
	rightB.move(rightInput);
	rightC.move(rightInput);}*/}

void setDrive(int rpm) {leftA.move_velocity(rpm); leftB.move_velocity(rpm); leftC.move_velocity(rpm);
						rightA.move_velocity(rpm); rightB.move_velocity(rpm); rightC.move_velocity(rpm);}