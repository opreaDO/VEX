#include "main.h"
#include "pneumatics.h"

bool lipBool = false;
bool endgame = false;

ADIDigitalOut stringS({{13, 6}});
ADIDigitalOut blocker({{13, 8}});
ADIDigitalOut lip({{13, 7}});

void indexToggle (void) {
    indexer.set_value(true);
    delay(120);
    indexer.set_value(false);
}

void lipToggle (bool state) {
    if (state == true) {lip.set_value(true); fwPower = 9000; lipBool = true;}
    else if (state == false) {lip.set_value(false); fwPower = 10000; lipBool = false;}
    if (flySpinning) {fly.stop(); setFW(fwPower);}
}

void lipToggleCntrl (void) {
    if (lipBool == true) {lip.set_value(false); fwPower = 10000;}
    else if (lipBool == false) {lip.set_value(true); fwPower = 9000;}
    if (flySpinning) {fly.stop(); setFW(fwPower);}
    lipBool = !lipBool;
}

void pneumatics (void) {
//      if (master.get_digital_new_press(DIGITAL_R2)) {indexToggle();}
//      if (master.get_digital_new_press(DIGITAL_R1)) {indexToggle(); delay(150); indexToggle(); delay(150); indexToggle();}
        if (master.get_digital_new_press(DIGITAL_Y)) {lipToggleCntrl();}
        if (master.get_digital_new_press(DIGITAL_RIGHT)) {blocker.set_value(true); delay(150); blocker.set_value(false);}
        if (endgame && master.get_digital_new_press(DIGITAL_X)) {
            stringS.set_value(true);
            delay(150);
            stringS.set_value(false);}}


