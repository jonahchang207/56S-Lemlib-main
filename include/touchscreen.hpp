// Simple touchscreen UI for auton selection and pose display
#pragma once

#include "liblvgl/lvgl.h"

// initialize touchscreen UI (create objects and start periodic updates)
void touchscreen_int();

namespace ui {
    // get currently selected autonomous index
    int selected_auton();
}
