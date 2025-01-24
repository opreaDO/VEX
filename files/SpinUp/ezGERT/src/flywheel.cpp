#include "controller.h"
#include "main.h"
#include <string>

bool flySpinning = false;
// int fwSpeeds[3] = {2000, 3000, 3600};
// int fwIndex = 0;

double fwPower = 10500; 

sylib::SpeedControllerInfo flyController (
        [](double rpm){return 3;}, // kV function
        0.001,
        0,
        0,
        0.001
);

sylib::Motor fly(15, 3600, true, flyController);
void setFW (double power) {
//  fly.set_velocity_custom_controller(power);  
    fly.set_voltage((power * -1));
}

void flywheel (void) {
    fly.set_braking_mode(kV5MotorBrakeModeBrake);
    if (master.get_digital_new_press(DIGITAL_L1)) {
        if (flySpinning == true) {
            fly.stop();
        }
        else {
            setFW(fwPower);
            }
        flySpinning = !flySpinning;
        }}