#include "main.h"
#include "globals.h"
#include "pros/misc.h"

Motor intakeA(8);     
Motor intakeB(18);      
MotorGroup intake({8, 18});
Optical optical(7);

bool intakeOn = false;

// 0 = Blue, 1 = Red
int opposingAlliance = 0;

// {{red range}, {blue range}}
int hueValues[2][2] = {{40, 320}, {280, 170}};

void intakeControl(void) {
    if (master.get_digital_new_press(DIGITAL_R1) && !(master.get_digital(DIGITAL_L1))) {
        intake.move(127);
        intakeOn = true;
    }
    if (master.get_digital_new_press(DIGITAL_R1) && !(master.get_digital(DIGITAL_L1))) {
        intake.move(127);
        intakeOn = true;
    }
    if (master.get_digital_new_press(DIGITAL_L1) && !(master.get_digital(DIGITAL_R1))) {
        intake.brake();
        intakeOn = false;
    }
    if ((master.get_digital(DIGITAL_L1)) && (master.get_digital((DIGITAL_L2)))) {
        intake.move(-127);
        intakeOn = true;
    }
}

void colourSorting(void) {
    if ((optical.get_hue() < hueValues[opposingAlliance][0]) && (optical.get_hue() > hueValues[opposingAlliance][1]) && (intakeOn)) {
        intake.move(-127); delay(250);
        intake.move(127); delay(1000); // delay before it starts detecting colours again
    }  
}