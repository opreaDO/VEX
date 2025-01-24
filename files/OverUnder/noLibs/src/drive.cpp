#include "main.h"

float leftInput; float rightInput;
float leftPower; float rightPower;

Motor rightA(11, E_MOTOR_GEARSET_06, false);
Motor rightB(12, E_MOTOR_GEARSET_06, false);
Motor rightC(13, E_MOTOR_GEARSET_06, false);
Motor leftA(20, E_MOTOR_GEARSET_06, true);
Motor leftB(19, E_MOTOR_GEARSET_06, true);
Motor leftC(18, E_MOTOR_GEARSET_06, true);
MotorGroup leftDrive({leftA, leftB, leftC});
MotorGroup rightDrive({rightA, rightB, rightC});
Imu imu(11);

void chassisControl (void) {
    leftInput = master.get_analog(ANALOG_LEFT_Y);
    rightInput = master.get_analog(ANALOG_RIGHT_Y);

//	leftPower = (atan((2 * leftInput - (leftInput / std::abs(leftInput))) * 5.5) / (2 * atan(5.5))) + (leftInput / (2 * std::abs(leftInput))) * 127;
//	rightPower = (atan((2 * rightInput - (rightInput / std::abs(rightInput))) * 5.5) / (2 * atan(5.5))) + (rightInput / (2 * std::abs(rightInput))) * 127;
	
	leftA.move(leftInput);
	leftB.move(leftInput);
	leftC.move(leftInput);
	rightA.move(rightInput);
	rightB.move(rightInput);
	rightC.move(rightInput);}

void setDrive(int volt) {leftA.move(volt); leftB.move(volt); leftC.move(volt);
						rightA.move(volt); rightB.move(volt); rightC.move(volt);}