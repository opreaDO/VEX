#pragma once

#include "EZ-Template/api.hpp"
#include "main.h"

// drive
extern Drive chassis;

// lady brown
extern pros::Motor ladyBrown;
extern pros::Rotation rotation;
extern void ladyBrownControl(void);

// intake
extern pros::Motor intakeA;     
extern pros::Motor intakeB;      
extern pros:: MotorGroup intake;
extern pros:: Optical optical;
extern int opposingAlliance;
extern void intakeControl(void);
extern void colourSorting(void);

// poomatics
extern pros::adi::DigitalOut mogoClamp;
extern pros::adi::DigitalOut doinker;
extern void poomaticControl(void);

// rgb
extern stormlib::aRGB_manager LEDmanager;

// autons
void default_constants();
void moveOffLine(void);
void almostSoloAWP(void);