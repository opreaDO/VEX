#include "globals.h"
#include "main.h"
#include "pros/adi.hpp"
#include "pros/misc.h"

bool flOn = false; bool frOn = false;
bool bigOn = false;
bool rearOn = false;
bool ptoOn = false;
ADIDigitalOut flWing(5);
ADIDigitalOut frWing(4);
ADIDigitalOut rearWings(2);
ADIDigitalOut pto(1);
ADIDigitalOut winch(3);

void bigWings(bool state) {
    flWing.set_value(state); frWing.set_value(state);
}

void wingsControl(void) {
    if (master.get_digital_new_press(DIGITAL_R1)) {
        frOn = !frOn;
        frWing.set_value(frOn);
        ledStrip2.pulse(0xF71302, 22, 15);
    }

    if (master.get_digital_new_press(DIGITAL_RIGHT)) {
        flOn = !flOn;
        flWing.set_value(flOn);
        ledStrip1.pulse(0xF71302, 22, 15);
    }   
    
    if (master.get_digital_new_press(DIGITAL_L1)) {
        bigOn = !bigOn;
        bigWings(bigOn);
        ledStrip1.pulse(0xF71302, 22, 15); ledStrip2.pulse(0xF71302, 22, 15);
    }
    if (master.get_digital_new_press(DIGITAL_Y)) {
        rearWings.set_value(!rearOn);
        rearOn = !rearOn;
        ledStrip1.pulse(0x1B68E3, 22, 15); ledStrip2.pulse(0x1B68E3, 22, 15);
    }

    if (master.get_digital(DIGITAL_UP)) {
        setDrive(127);}

    if (master.get_digital_new_press(DIGITAL_X)) {
        ptoOn = !ptoOn; pto.set_value(ptoOn);
        if (ptoOn) {
            master.print(0, 0, "PTO WINCH");
        } else {master.print(0, 0, "PTO DRIVE");}
    }

    if (master.get_digital(DIGITAL_A)) {
        winch.set_value(true);
    } else {winch.set_value(false);}
}