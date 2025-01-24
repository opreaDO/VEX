#pragma once
#include "globals.h"
#include "main.h"
#include "pros/motors.hpp"

// controller
extern pros::Controller master;

// chassis
extern void chassisControl(void);
extern Drive chassis;
extern void setDrive(int volt);
extern bool holdOn;

// intake
extern void intakeControl(void);
extern MotorGroup intake;

// winch + pto
extern void winchControl(void);
extern ADIDigitalOut pto;
extern ADIDigitalOut winch;
extern bool ptoOn;

// wings
extern void wingsControl(void);
extern ADIDigitalOut flWing;
extern ADIDigitalOut frWing;
extern ADIDigitalOut rearWings;

// rgb
extern void rgb(void);
extern sylib::Addrled ledStrip1;
extern sylib::Addrled ledStrip2;

// autons
extern void default_constants(void);
extern void nearOneTriball(void);
extern void farOneTriball(void);
extern void nearThreeTriball(void);
extern void farThreeTriball(void);
extern void partialAWP(void);
extern void farFiveTriball(void);
