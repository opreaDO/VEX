#include "globals.h"
#include "main.h"
#include "pros/adi.hpp"
#include "pros/misc.h"
#include "pros/motors.h"
#include "pros/motors.hpp"

bool ptoOn = false; bool winchOn = false;

ADIDigitalOut pto(1);
ADIDigitalOut winch(3);

void winchControl(void) {
// weirdly formatted pto shift + controller screen update [midnight antics]
    if (master.get_digital_new_press(DIGITAL_X)) {
        ptoOn = !ptoOn;
        if (ptoOn){pto.set_value(1); delay(50);
        if (holdOn) {master.print(0, 0, "HOLD - PTO ENGAGED    ");}
        else {master.print(0, 0, "COAST - PTO ENGAGED   ");}}
        if (!ptoOn) {pto.set_value(0); delay(50);
        if (holdOn) {master.print(0, 0, "HOLD - PTO DISENGAGED ");}
        else {master.print(0, 0, "COAST - PTO DISENGAGED");}}}
    // release winch if pto active and button pressed
    if (master.get_digital(DIGITAL_A)) {
        winch.set_value(1);
    } else {winch.set_value(0);}
    // just to stop rgb spazzing
    if (master.get_digital_new_press(DIGITAL_A)) {
        ledStrip1.pulse(0x24C9A0, 22, 15);
        ledStrip2.pulse(0x24C9A0, 22, 15);
    }
    // drives winch [uses pre-existing drive declarations]
    if (master.get_digital(DIGITAL_UP)) {
        setDrive(127);
    } else {setDrive(0);}
}