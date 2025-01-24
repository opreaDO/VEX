#include "main.h"
#include "pros/motors.h"
bool kickerOn = false;
Motor kickerA(1, E_MOTOR_GEAR_200, true);
Motor kickerB(10, E_MOTOR_GEAR_200, false);
MotorGroup kicker({kickerA, kickerB});
Optical optical(1);

void kickerControl(void) {
    if (master.get_digital_new_press(DIGITAL_L1)) {
        if (kickerOn) {kicker.brake();}
        else {kicker.move_velocity(170);}
        kickerOn = !kickerOn;
    }
    if (master.get_digital_new_press(DIGITAL_A)) {
        if (kickerOn) {kicker.brake();}
        else {kicker.move_velocity(80);}
        kickerOn = !kickerOn;
    }
    if (master.get_digital_new_press(DIGITAL_LEFT)) {
        if (kickerOn) {kicker.brake();}
        else {kicker.move_velocity(-80);}
        kickerOn = !kickerOn;
    } 
}
