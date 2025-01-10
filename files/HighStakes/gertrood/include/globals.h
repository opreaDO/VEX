#pragma once
#include "globals.h"
#include "main.h"

// controller
extern Controller master;

// chassis
extern ez::Drive chassis;

// intake
extern Motor intakeA;
extern Motor intakeB;
extern MotorGroup intake;
extern int opposingAlliance;
extern void intakeControl(void);
extern void colourSorting(void);

// lady brown
extern Motor ladyBrown;
extern void ladyBrownControl(void);
extern Rotation rotation;

// poomatics
extern adi::DigitalOut mogoClamp;
extern adi::DigitalOut doinker;
extern void poomaticControl(void);