#include "main.h"

Motor lowerStage(8);     
Motor upperStage(15);      
MotorGroup intake({18, 15});
Optical optical(7);
bool intakeOn = false;

// 0 = Blue, 1 = Red
int opposingAlliance = 0;

// {{red range}, {blue range}}
int hueValues[2][2] = {{60, 300}, {180, 60}};


void intakeControl(void) {
    if (master.get_digital_new_press(DIGITAL_R1) && !(master.get_digital(DIGITAL_L1))) {
        lowerStage.move(127);
        upperStage.move(105);
        intakeOn = true;
    }
    if (master.get_digital_new_press(DIGITAL_L1) && !(master.get_digital(DIGITAL_R1))) {
        intake.brake();
        intakeOn = false;
    }
    if ((master.get_digital(DIGITAL_L1)) && (master.get_digital((DIGITAL_R1)))) {
        intake.move(-127);
        intakeOn = true;
    }
}

void colourSorting(void) {
    if ((intakeOn) && (optical.get_proximity() < 50)) { // TUNE DISTANCE 
        if ((optical.get_hue() < hueValues[opposingAlliance][0]) && (optical.get_hue() > hueValues[opposingAlliance][1])) {
            delay(500); // time taken to travel up the intake before reversing. TUNE
            intake.move(-127); delay(250);
            intake.move(127); delay(250); // delay before it starts detecting colours again
        }  
    }
    
}