#include "main.h"
#include "stormlib/led.hpp"

// CHANGE PORTS & LENGTH
stormlib::aRGB strand1(5, 60);
stormlib::aRGB strand2(6, 60);
stormlib::aRGB strand3(7, 60);
stormlib::aRGB strand4(8, 60);
stormlib::aRGB_manager LEDmanager(&strand1, &strand2, &strand3, &strand4,
                                  nullptr, nullptr, nullptr, nullptr);

void rgb(void) {
    LEDmanager.rainbow(); // rainbow flows down all the strands
}