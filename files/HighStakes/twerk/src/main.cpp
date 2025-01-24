#include "main.h"

void initialize() {
	LEDmanager.initialize(20);
	chassis.initialize();
}

void disabled() {}

void competition_initialize() {}

void autonomous() {}

void opcontrol() {
	LEDmanager.rainbow();
	while (true) {
		chassis.opcontrol_tank();
		poomaticControl();
		intakeControl();
		ladyBrownControl();
		colourSorting();
		pros::delay(10);
	}
}