#include "globals.h"
#include "main.h"
#include "pros/adi.hpp"
#include "pros/misc.h"

bool flOn = false; bool frOn = false; bool frontOn = false; bool rearOn = false; 
ADIDigitalOut flWing(5);
ADIDigitalOut frWing(4);
ADIDigitalOut rearWings(2);

void wingsControl(void) {
       // expand / retract front left wing [strobe red light on left side]
    if (master.get_digital_new_press(DIGITAL_RIGHT)) {
        flWing.set_value(!flOn);
        ledStrip1.pulse(0xF71302, 22, 15);
        flOn = !flOn;
    }
    // expand / retract front right wing [strobe red light on right side]
    if (master.get_digital_new_press(DIGITAL_R1)) {
        frWing.set_value(!frOn);
        ledStrip2.pulse(0xF71302, 22, 15);
        frOn = !frOn;
    }
    // expand / retract both front wings simultaneously [strobe red light on both sides]
    if (master.get_digital_new_press(DIGITAL_L1)) {
        flWing.set_value(!frontOn); frWing.set_value(!frontOn);
        ledStrip1.pulse(0xF71302, 22, 15);
        ledStrip2.pulse(0xF71302, 22, 15);
        frontOn = !frontOn;
    }
    // expand / retract both rear wings simultaneously [strobe blue light on both sides]
    if (master.get_digital_new_press(DIGITAL_Y)) {
        rearWings.set_value(!rearOn);
        ledStrip1.pulse(0x1B68E3, 22, 15, true);
        ledStrip2.pulse(0x1B68E3, 22, 15, true);
        rearOn = !rearOn;
    }
}
