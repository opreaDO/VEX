#include "main.h"

// Chassis constructor
ez::Drive chassis(
    // These are your drive motors, the first motor is used for sensing!
    {-16, -9, -20},     // Left Chassis Ports (negative port will reverse it!)
    {4, 5, 6},  // Right Chassis Ports (negative port will reverse it!)

    19,      // IMU Port
    2.75,  // Wheel Diameter (Remember, 4" wheels without screw holes are actually 4.125!)
    600);   // Wheel RPM = cartridge * (motor gear / wheel gear)