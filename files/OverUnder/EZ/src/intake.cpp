#include "main.h"
bool intakeOn = false;
Motor intakeA(14, false);
Motor intakeB(17, true);
MotorGroup intake({intakeA, intakeB});

void intakeControl(void) {
    if (master.get_digital_new_press(DIGITAL_R2) && !(master.get_digital(DIGITAL_L2))) {
        if (intakeOn) {intake.brake();}
        else {intake.move(127);}
        intakeOn = !intakeOn;
    }
    if (master.get_digital(DIGITAL_L2) && (master.get_digital_new_press(DIGITAL_R2))) {
        if (intakeOn) {intake.brake();}
        else {intake.move(-127);}
        intakeOn = !intakeOn;
    }

}




