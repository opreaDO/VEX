#include "main.h"
#include "controller.h"
#include "flywheel.h"
#include "intake.h"
#include "pneumatics.h"
#include "pros/rtos.hpp"

int startTime;
int desiredVal = 3000;

void disabled() {}
void competition_initialize() {}

void initialize() {
	sylib::initialize();
	static Gif gif("/usd/slideshow.gif", lv_scr_act());
	rgb();
}

void autonomous() {
	rollerAuton();
}

void opcontrol() {
	startTime = millis();
	lip.set_value(true);
	lipBool = true;
	fwPower = 9000;
	
	while (true) {
		std::uint32_t now = millis();
		chassisControl();
		flywheel();
		intakeControl();
		pneumatics();
		if ((now - startTime) > 95000) {endgame = true;}
//		printf("%d,%d,%f\n", smillis(), desiredVal,fly.get_velocity();
		Task::delay_until(&now, 10);
	}}