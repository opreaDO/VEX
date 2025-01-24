#pragma once
#include "main.h"

// controller
extern pros::Controller master;

// chassis
extern Drive chassis;
extern void chassisControl(void);
extern void setDrive(int rpm);
extern bool holdOn;

// intake
extern void intakeControl(void);
extern MotorGroup intake;

// lift
extern void liftControl(void);
extern ADIDigitalOut lift;

// wings
extern void wingsControl(void);
extern void bigWings(void);
extern ADIDigitalOut rearWings;

// winch + pto
extern bool ptoOn;
extern ADIDigitalOut pto;
extern ADIDigitalOut winch;

// rgb
extern void rgb(void);
extern sylib::Addrled ledStrip1;
extern sylib::Addrled ledStrip2;

// autons
extern void partialAWP(void);
extern void farThreeTriball(void);
extern void middleRush(void);