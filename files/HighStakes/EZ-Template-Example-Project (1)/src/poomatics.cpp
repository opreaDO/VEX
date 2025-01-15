#include "main.h"

adi::DigitalOut mogoClamp(1);
adi::DigitalOut doinker(2);
bool clampOn = false;
bool doinkerOn = false;

void poomaticControl(void) {
    if (master.get_digital_new_press(DIGITAL_Y)) {
        clampOn = !clampOn;
        mogoClamp.set_value(clampOn);
    }
    if (master.get_digital_new_press(DIGITAL_RIGHT)) {
        doinkerOn = !doinkerOn;
        doinker.set_value(doinkerOn);
    }
}
