#pragma once
#include "globals.h"
#include "main.h"
#include "pros/motors.hpp"

// controller
extern pros::Controller master;

// chassis
extern void chassisControl(void);
// autons
extern void default_constants(void);
extern void nearOneTriball(void);
extern void farOneTriball(void);
extern void nearThreeTriball(void);
extern void farThreeTriball(void);
extern void partialAWP(void);
extern void farFiveTriball(void);

// kicker
extern void kickerControl(void);
extern void kickMacro(void);
extern MotorGroup kicker;
extern Optical optical;

// intake
extern void intakeControl(void);
extern MotorGroup intake;

// lift
extern void liftControl(void);
extern ADIDigitalOut lift;
extern ADIDigitalOut kaboom;

// wings
extern void wingsControl(void);
extern ADIDigitalOut bigWings;
extern ADIDigitalOut miniWing;
extern ADIDigitalOut beach;

// rgb
extern void rgb(void);
extern sylib::Addrled ledStrip1;
extern sylib::Addrled ledStrip2;
