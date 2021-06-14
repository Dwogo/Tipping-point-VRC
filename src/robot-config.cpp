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
motor DR4B = motor(PORT5, ratio18_1, false);
motor Flip = motor(PORT6, ratio18_1, false);
motor LBM = motor(PORT4, ratio18_1, false);

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