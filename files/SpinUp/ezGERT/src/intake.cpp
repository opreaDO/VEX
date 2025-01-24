#include "main.h"
#include "pros/misc.h"

bool intakeSpinning = false;
Motor intake(20, MOTOR_GEAR_200, false);

void intakeControl (void) {
		if (master.get_digital_new_press(DIGITAL_L2)){
			if (intakeSpinning) {intake.move_voltage(0);}
			else {intake.move_voltage(12000);}
			intakeSpinning = !intakeSpinning;}
		
		if (master.get_digital_new_press(DIGITAL_R2)) {intake.move_relative(-300, 200);}

		if (master.get_digital_new_press(DIGITAL_R1)) {
			if (intakeSpinning) {intake.move_voltage(0);}
			else {intake.move_voltage(-12000);}
			intakeSpinning = !intakeSpinning;}}
