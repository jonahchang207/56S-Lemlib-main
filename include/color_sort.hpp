#pragma once

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
#include "pros/optical.hpp"
#include "pros/distance.hpp"
#include "pros/rotation.hpp"

// Color sort API

// Represents the target alliance color to react to
enum SortColor { SortColorRed, SortColorBlue };

// Enable or disable autonomous color sorting.
// When enabled, the optical sensor is used and the mid-intake runs
// whenever the selected color (red/blue) is detected.
// Call this periodically (e.g., in an auton loop).
void autonColorSort(SortColor color, bool enabled);


