#pragma once
#include "main.h"

extern bool lipBool;
extern bool endgame;
extern pros::ADIDigitalOut indexer;
extern pros::ADIDigitalOut lip;
extern pros::ADIDigitalOut stringS;
extern void indexToggle (void);
extern void lipToggle (bool state);
extern void lipToggleCntrl (void);
extern void pneumatics (void);