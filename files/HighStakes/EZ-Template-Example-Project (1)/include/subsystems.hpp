#pragma once

#include "EZ-Template/api.hpp"
#include "api.h"

extern Drive chassis;

// lady brown
extern pros::Motor ladyBrown;
extern pros::Rotation rotation;
extern void ladyBrownControl(void);

// intake
extern pros::Motor intakeA;     
extern pros::Motor intakeB;      
extern pros:: MotorGroup intake;
extern int opposingAlliance;
extern void intakeControl(void);
extern void colourSorting(void);

// poomatics
extern pros::adi::DigitalOut mogoClamp;
extern pros::adi::DigitalOut doinker;
extern void poomaticControl(void);

// rgb
extern stormlib::aRGB_manager LEDmanager;
extern void rgb(void);

// Your motors, sensors, etc. should go here.  Below are examples

// inline pros::Motor intake(1);
// inline pros::adi::DigitalIn limit_switch('A');