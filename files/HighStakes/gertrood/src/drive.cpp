#include "main.h"
#include "pros/motors.h"
#include "pros/motors.hpp"

// port 10 = rgb

// Placeholder ports, to be replaced
Motor leftA(9, MotorGears::ratio_6_to_1);
Motor leftB(20, MotorGears::ratio_6_to_1);
Motor leftC(16, MotorGears::ratio_6_to_1);
Motor rightA(-4, MotorGears::ratio_6_to_1);
Motor rightB(-5, MotorGears::ratio_6_to_1);
Motor rightC(-6, MotorGears::ratio_6_to_1);
MotorGroup leftDrive({9, 20, 16}, MotorGears::ratio_6_to_1);
MotorGroup rightDrive({-4, -5, -6}, MotorGears::ratio_6_to_1);
Imu imu(19);

// EZ chassis
ez::Drive chassis (
  // Left Chassis Ports (negative port will reverse it!)
  //   the first port is the sensored port (when trackers are not used!)
  {9, 20, 16}

  // Right Chassis Ports (negative port will reverse it!)
  //   the first port is the sensored port (when trackers are not used!)
  ,{-4, -5, -6}

  // IMU Port
  ,19

  // Wheel Diameter (Remember, 4" wheels are actually 4.125!)
  ,2.75

  // Cartridge RPM
  ,600

  // External Gear Ratio (MUST BE DECIMAL)
  // eg. if your drive is 84:36 where the 36t is powered, your RATIO would be 2.333.
  // eg. if your drive is 36:60 where the 60t is powered, your RATIO would be 0.6.
);