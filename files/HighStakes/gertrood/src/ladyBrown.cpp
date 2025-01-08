#include "main.h"
#include "pros/adi.hpp"
#include "pros/misc.h"

Motor ladyBrown(14); 
adi::DigitalOut mogoClamp(1);

bool clampOn = false;

void ladyBrownControl(void) {
    if (master.get_digital(DIGITAL_L1)) {
        ladyBrown.move(127);
    }
    if (master.get_digital(DIGITAL_L2)) {
        ladyBrown.move(-127);
    }
    if (master.get_digital_new_press(DIGITAL_X)) {
        clampOn = !clampOn;
        mogoClamp.set_value(clampOn);
    }
}