#include "main.h"
#include "pneumatics.h"

double robotAngleRatio = 1;

void turnRobot(double angle) {
    double robotAngle = angle * robotAngleRatio;
    leftDrive.move_relative(robotAngle, 600);
    rightDrive.move_relative(-(robotAngle), 600);  
}

void turnTest(void) {
    while (true) {
        if (master.get_digital_new_press(DIGITAL_LEFT)) {

        }
    }
}

void experimentalAuton(void) {
    chassisDrive->moveDistance(-3_in);
    intake.move_voltage(12000);
    delay(769);
    intake.move_voltage(0);
    chassisDrive->moveDistance(6_in);
    setFW(10000);
    delay(5000);
    indexToggle();
    delay(2500);
    indexToggle();
}

void rollerAuton(void) {
    setFW(10000);
    drive.move_relative(-70, 600);
    intake.move_voltage(-12000);
    delay(350);
    intake.move_voltage(0);
    drive.move_velocity(0);
    drive.move_relative(140, 600);
    delay(5400);
    indexToggle();
    delay(2500);
    indexToggle();
    delay(1000);
    setFW(0);
}

void awpAuton(void) {

}

void skillsAuton(void) {
    setFW(10000);
    drive.move_relative(-70, 600);
    intake.move_voltage(-12000);
    delay(350);
    intake.move_voltage(0);
    drive.move_velocity(0);
    drive.move_relative(140, 600);
    delay(5400);
    indexToggle();
    delay(2500);
    indexToggle();
    delay(1000);
    leftDrive.move_relative(45, 600);
    rightDrive.move_relative(-45, 600);
    /*stringS.set_value(true); 
    delay(200); 
    stringS.set_value(false);*/
}