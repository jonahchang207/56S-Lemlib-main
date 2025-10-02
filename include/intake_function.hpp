
#include "pros/screen.hpp"   // IWYU pragma: keep
#include "pros/motors.hpp"   // IWYU pragma: keep
#include "pros/imu.hpp"      // IWYU pragma: keep
#include "pros/rtos.hpp"     // IWYU pragma: keep
#include "liblvgl/lvgl.h"    // IWYU pragma: keep
#include "pros/misc.hpp"     // IWYU pragma: keep
#include "pros/misc.hpp"      // IWYU pragma: keep
#include "api.h" // IWYU pragma: keep
#include "pros/imu.hpp"
#include "pros/motors.hpp"



// Function declarations
extern void intakeFunction();
// Autonomous intake control API
enum IntakeMode { intakeTop, intakeBottom, intakeMid, intakeBucket };
extern void intakeFunctionAuton(IntakeMode mode, int power);