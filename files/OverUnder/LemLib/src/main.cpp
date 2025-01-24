#include "main.h"
#include "globals.h"
Controller master(CONTROLLER_MASTER);

void initialize() {
	chassis.initialize();
	//default_constants();
	static Gif gif("/usd/slideshow.gif", lv_scr_act());
	chassis.set_curve_default(3.5, 3.5);
}

void disabled() {}

void competition_initialize() {}

void autonomous() {
//	farFiveTriball();
//	nearOneTriball();
//	farOneTriball();
//	nearThreeTriball();
//	farThreeTriball();
	partialAWP();
}

void opcontrol() {
	sylib::initialize(); rgb();
	kaboom.set_value(0);
	kicker.set_brake_modes(E_MOTOR_BRAKE_HOLD); chassis.set_drive_brake(E_MOTOR_BRAKE_COAST); master.print(0, 0, "COAST");
	while (1) {
		chassisControl();
		kickerControl();
		intakeControl();
		liftControl();
		wingsControl();
		pros::delay(10);
		}
	}

