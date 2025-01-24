#pragma once
#include "main.h"
extern pros::Motor leftA;
extern pros::Motor leftB;
extern pros::Motor rightA;
extern pros::Motor rightB;
extern pros::MotorGroup drive;
extern std::shared_ptr<okapi::OdomChassisController> chassisDrive;
extern std::string driveCurrent;
extern std::string brakeCurrent;
extern void chassisControl (void);

extern pros::MotorGroup rightDrive;
extern pros::MotorGroup leftDrive;