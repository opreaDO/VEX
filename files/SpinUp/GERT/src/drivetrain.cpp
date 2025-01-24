#include "main.h"
#include "pros/misc.h"

int leftTarget; int rightTarget;
int leftPower; int rightPower;
int leftPrev; int rightPrev;

bool driveInvert = false;
bool brakeHold = false;
std::string driveCurrent = "FW";
std::string brakeCurrent = "NB";

Motor leftA(1, MOTOR_GEAR_600, false, MOTOR_ENCODER_DEGREES);
Motor leftB(2, MOTOR_GEAR_600, false, MOTOR_ENCODER_DEGREES);
Motor leftC(3, MOTOR_GEAR_600, false, MOTOR_ENCODER_DEGREES);
Motor rightA(4, MOTOR_GEAR_600, true, MOTOR_ENCODER_DEGREES);
Motor rightB(5, MOTOR_GEAR_600, true, MOTOR_ENCODER_DEGREES);
Motor rightC(6, MOTOR_GEAR_600, true, MOTOR_ENCODER_DEGREES);
MotorGroup leftDrive({leftA, leftB, leftC});
MotorGroup rightDrive({rightA, rightB, rightC});
MotorGroup drive({leftA, leftB, leftC, rightA, rightB, rightC});

std::shared_ptr<okapi::OdomChassisController> chassisDrive = okapi::ChassisControllerBuilder()
.withMotors({1, 2, 3}, {4, 5, 6})
// .withGains({0.001, 0, 0.0001},
//          {0.001, 0, 0.0001},
//          {0.001, 0, 0.0001})
.withSensors(okapi::ADIEncoder{'C', 'D'}, 
 		okapi::ADIEncoder{'E', 'F', true}, 
 		okapi::ADIEncoder{'G', 'H'})
.withDimensions({okapi::AbstractMotor::gearset::blue, (36.0/60.0)}, {{4.125_in, 15_in}, okapi::imev5BlueTPR})
.withOdometry({{2.75_in, 10.45_in, 6.5_in, 2.75_in}, okapi::quadEncoderTPR}, okapi::StateMode::FRAME_TRANSFORMATION)  // Add ADI Encoders after Gains and add tracking wheel size with track width
.buildOdometry();

void chassisControl (void) {
	leftTarget = master.get_analog(ANALOG_LEFT_Y);
	rightTarget = master.get_analog(ANALOG_RIGHT_Y);
	leftPower = (15.8 * (tan(M_PI * leftTarget / 260)));
	rightPower = (15.8 * (tan(M_PI * rightTarget / 260)));
	
	leftA.move(leftPower);
	leftB.move(leftPower);
	leftC.move(leftPower);
	rightA.move(rightPower);
	rightB.move(rightPower);
	rightC.move(rightPower);
	
//	leftA.move((leftPower + leftPrev) / 2);
//	leftB.move((leftPower + leftPrev) / 2);
//	leftC.move((leftPower + leftPrev) / 2);
//	rightA.move((rightPower + rightPrev) / 2);
//	rightB.move((rightPower + rightPrev) / 2);
//	rightC.move((rightPower + rightPrev) / 2);	
	
	leftPrev = leftPower;
	rightPrev = rightPower;}