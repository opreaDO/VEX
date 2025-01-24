#include "main.h"
Controller master(CONTROLLER_MASTER);

void initialize() {
	sylib::initialize();
	static Gif gif("/usd/slideshow.gif", lv_scr_act());
	rgb();
}

void disabled() {}

void competition_initialize() {}

void autonomous() {}

void opcontrol() {
	master.print(0, 0, "PTO DRIVE");
	while (true) {
		chassisControl();
		intakeControl();
		wingsControl();
		pros::delay(10);
	}
}
