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

// lady brown & mogo clamp
extern Motor ladyBrown;
extern adi::DigitalOut mogoClamp;
extern void ladyBrownControl(void);