#pragma once

#include "EZ-Template/api.hpp"
#include "api.h"

// drive
extern Drive chassis;

// intake
extern pros::Motor intakeA;     
extern pros::Motor intakeB;      
extern pros::MotorGroup intake;
extern bool intakeOn;

// poomatics
extern pros::adi::DigitalOut mogoClamp;
extern pros::adi::DigitalOut doinker;
extern bool clampOn;
extern bool doinkerOn;

// Your motors, sensors, etc. should go here.  Below are examples

// inline pros::Motor intake(1);
// inline pros::adi::DigitalIn limit_switch('A');