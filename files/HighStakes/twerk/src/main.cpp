#include "main.h"

void initialize() {
	pros::lcd::initialize();
	pros::lcd::set_text(1, "Hello PROS User!");
}

void disabled() {}

void competition_initialize() {}


void autonomous() {}

void opcontrol() {
	while (true) {
		pros::delay(10);
	}
}