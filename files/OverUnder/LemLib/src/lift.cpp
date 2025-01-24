#include "globals.h"
#include "main.h"
#include "pros/adi.hpp"
#include "pros/misc.h"
#include "pros/motors.h"
#include "pros/motors.hpp"

bool liftOn = false; bool macroOn = false; bool lockOn = false;
int liftHeight = 0;

ADIDigitalOut lift(7);
ADIDigitalOut kaboom(1);

void liftControl(void) {
    if (master.get_digital_new_press(DIGITAL_R1)) {
        lift.set_value(!liftOn); 
        liftOn = !liftOn;
        ledStrip1.pulse(0x43B5F7, 22, 15);
        ledStrip2.pulse(0x43B5F7, 22, 15);
    }

    if (master.get_digital_new_press(DIGITAL_X)) {
        kaboom.set_value(!lockOn);
        lockOn = !lockOn;}}
