#include "main.h"

Controller master(CONTROLLER_MASTER);
okapi::Controller okapiController;
std::string printSpeed;

void printer(void) {
    while (true) {
        master.print(0, 0, "%d", fly.get_velocity());
        master.clear_line(0); 
        delay(60);
    }
}