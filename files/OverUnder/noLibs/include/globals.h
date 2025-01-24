#pragma once
#include "main.h"

// controller
extern pros::Controller master;

// chassis
extern void chassisControl(void);
extern void setDrive(int volt);

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

// climber
extern void climberControl(void);
extern Motor roll;
extern ADIDigitalOut wheelExtend;

// rgb
extern void rgb(void);
extern sylib::Addrled ledStrip1;
extern sylib::Addrled ledStrip2;