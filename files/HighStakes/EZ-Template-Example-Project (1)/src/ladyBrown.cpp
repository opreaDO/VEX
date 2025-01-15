#include "main.h"

Motor ladyBrown(1);
Rotation rotation(2);

bool ladyBrownOn = false;
bool loadHeightOn = false;
int targetRotation = 27900;
int acceptableError = 100;
double kP = 0.25;

void ladyBrownControl(void) {
    if ((master.get_digital(DIGITAL_R2)) && !(master.get_digital(DIGITAL_L2)) && (!loadHeightOn)) {
        ladyBrown.move(127);
        ladyBrownOn = true;
    } 
    else if ((master.get_digital(DIGITAL_L2)) && !(master.get_digital(DIGITAL_R2)) && (!loadHeightOn)) {
        ladyBrown.move(-127);
        ladyBrownOn = true;
    }
    else if ((master.get_digital(DIGITAL_L2)) && (master.get_digital(DIGITAL_R2))) {
        loadHeightOn = true; 
        ladyBrownOn = true;   
    }
    else if (ladyBrownOn) {
        ladyBrown.brake();
        ladyBrownOn = false;
    }

    if (loadHeightOn) {
        double error = targetRotation - rotation.get_angle();
        double motorSpeed = kP * error;
        motorSpeed = std::clamp(motorSpeed, -127.0, 127.0);
        ladyBrown.move(motorSpeed);

        if (abs(rotation.get_angle() - targetRotation) <= acceptableError) {
            loadHeightOn = false;
            ladyBrownOn = false;
        } 
    } 
    }