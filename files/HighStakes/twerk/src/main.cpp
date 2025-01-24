#include "main.h"

void initialize() {
	LEDmanager.initialize(20);
	chassis.initialize();
	chassis.opcontrol_curve_default_set(3.5);
	optical.set_led_pwm(100);
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