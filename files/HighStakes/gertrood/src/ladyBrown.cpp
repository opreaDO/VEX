#include "main.h"
#include "pros/adi.hpp"
#include "pros/misc.h"
#include "pros/rotation.hpp"

Motor ladyBrown(14);
Rotation rotation(20);
bool ladyBrownOn = false;
bool loadHeightOn = false;

// TUNE
int targetRotation = 0;
int acceptableError = 100; // 100 centidegrees/1 degree
double kP = 0.25; 

void ladyBrownControl(void) {
    if ((master.get_digital(DIGITAL_R2)) && !(master.get_digital(DIGITAL_L2))) {
        ladyBrown.move(127);
        ladyBrownOn = true;
    } 
    else if ((master.get_digital(DIGITAL_L2)) && !(master.get_digital(DIGITAL_R2))) {
        ladyBrown.move(-127);
    }
    else if (ladyBrownOn) {
        ladyBrown.brake();
        ladyBrownOn = false;
    }

    /* LB toggle to load height 
    if ((master.get_digital_new_press(DIGITAL_L2)) && (master.get_digital(DIGITAL_R2))) {
        loadHeightOn = true;    
    }

    if (loadHeightOn) {
        double error = targetRotation - rotation.get_angle();
        double motorSpeed = kP * error;
        motorSpeed = std::clamp(motorSpeed, -127.0, 127.0);
        ladyBrown.move(motorSpeed);

        if (abs(rotation.get_angle() - targetRotation) <= acceptableError) {
            loadHeightOn = false;
        } 
    }

    */
}