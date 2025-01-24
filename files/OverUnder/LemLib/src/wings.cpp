#include "globals.h"
#include "main.h"
#include "pros/adi.hpp"
#include "pros/misc.h"

bool bigOn = false; bool miniOn = false; bool beachOn = false;
ADIDigitalOut bigWings(8);
ADIDigitalOut miniWing(6);
ADIDigitalOut beach(4);

void wingsControl(void) {
    if (master.get_digital_new_press(DIGITAL_Y)) {
        bigWings.set_value(!bigOn);
        ledStrip1.pulse(0xF71302, 22, 15);
        ledStrip2.pulse(0xF71302, 22, 15);
        bigOn = !bigOn;
    }
    if (master.get_digital_new_press(DIGITAL_RIGHT)) {
        miniWing.set_value(!miniOn);
        miniOn = !miniOn;
    }
/*    if (master.get_digital_new_press(DIGITAL_DOWN)) {
        beach.set_value(!beachOn);
        beachOn = !beachOn;
    }
*/
}
