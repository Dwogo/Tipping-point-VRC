#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);
motor LFM = motor(PORT1, ratio18_1, false);
motor RFM = motor(PORT2, ratio18_1, true);
motor RBM = motor(PORT3, ratio18_1, true);
encoder LeftY = encoder(Brain.ThreeWirePort.A);
encoder RightY = encoder(Brain.ThreeWirePort.G);
encoder X = encoder(Brain.ThreeWirePort.E);
motor LBM = motor(PORT4, ratio18_1, false);
motor DR4BMotorA = motor(PORT5, ratio36_1, false);
motor DR4BMotorB = motor(PORT7, ratio36_1, true);
motor_group DR4B = motor_group(DR4BMotorA, DR4BMotorB);
bumper Dummy = bumper(Brain.ThreeWirePort.D);

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}