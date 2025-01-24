using namespace vex;

extern brain Brain;

// VEXcode devices
extern drivetrain Drivetrain;
extern controller Controller1;

extern motor flywheel;
extern motor rollerIntake;

extern digital_out indexer;
extern digital_out lip;
extern digital_out expansion;

extern triport expander;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );