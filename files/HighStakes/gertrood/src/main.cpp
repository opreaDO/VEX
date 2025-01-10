#include "main.h"

Controller master(pros::E_CONTROLLER_MASTER);

void initialize() {
	ladyBrown.set_brake_mode(E_MOTOR_BRAKE_BRAKE);
	chassis.initialize();
	chassis.opcontrol_curve_default_set(3.5, 3.5);
	static Gif gif("/usd/slideshow.gif", lv_scr_act());
}

void disabled() {}

void competition_initialize() {
	while (true) {
		if (master.get_digital_new_press(DIGITAL_A)) {
			opposingAlliance = !opposingAlliance;
			if (opposingAlliance == 0) {master.print(0, 0, "RED ALLIANCE SELECTED");}
			else {master.print(0, 0, "BLUE ALLIANCE SELECTED");}
			}
		delay(20);
	}
}

void autonomous() {}

void opcontrol() {	
	while (true) {
		chassis.opcontrol_tank();
		intakeControl();
		//colourSorting();
		ladyBrownControl();
		poomaticControl();
		pros::delay(20);
	}
}