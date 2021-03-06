using namespace vex;

extern brain Brain;

// VEXcode devices
extern controller Controller1;
extern motor LFM;
extern motor RFM;
extern motor RBM;
extern encoder LeftY;
extern encoder RightY;
extern encoder X;
extern motor LBM;
extern motor_group DR4B;
extern bumper Dummy;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );