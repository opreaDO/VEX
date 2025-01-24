#include "main.h"

stormlib::aRGB strand1(3,20);
stormlib::aRGB strand2(4,20);
stormlib::aRGB_manager LEDmanager(&strand1, &strand2, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr);