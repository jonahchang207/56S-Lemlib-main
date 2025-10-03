/**
 * \file main.h
 *
 * Contains common definitions and header files used throughout your PROS
 * project.
 *
 * \copyright Copyright (c) 2017-2024, Purdue University ACM SIGBots.
 * All rights reserved.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#ifndef _PROS_MAIN_H_
#define _PROS_MAIN_H_

/**
 * If defined, some commonly used enums will have preprocessor macros which give
 * a shorter, more convenient naming pattern. If this isn't desired, simply
 * comment the following line out.
 *
 * For instance, E_CONTROLLER_MASTER has a shorter name: CONTROLLER_MASTER.
 * E_CONTROLLER_MASTER is pedantically correct within the PROS styleguide, but
 * not convenient for most student programmers.
 */
#define PROS_USE_SIMPLE_NAMES

/**
 * If defined, C++ literals will be available for use. All literals are in the
 * pros::literals namespace.
 *
 * For instance, you can do `4_mtr = 50` to set motor 4's target velocity to 50
 */
#define PROS_USE_LITERALS

#include "api.h"

/*
 * You should add more #includes here
 */
//#include "okapi/api.hpp"
#include "lemlib/api.hpp" // IWYU pragma: keep
#include "api.h" // IWYU pragma: keep
#include "intake_function.hpp" // IWYU pragma: keep
#include "subsystems.hpp" // IWYU pragma: keep
#include "color_sort.hpp" // IWYU pragma: keep
#include "touchscreen.hpp" // IWYU pragma: keep
// Auton registry and definitions
#include "auton/auton.hpp" // IWYU pragma: keep

/* All pros headers */
#include "pros/abstract_motor.hpp" // IWYU pragma: keep
#include "pros/adi.h" // IWYU pragma: keep
#include "pros/adi.hpp" // IWYU pragma: keep
#include "pros/ai_vision.h" // IWYU pragma: keep
#include "pros/ai_vision.hpp" // IWYU pragma: keep
#include "pros/apix.h" // IWYU pragma: keep
#include "pros/colors.h" // IWYU pragma: keep
#include "pros/colors.hpp" // IWYU pragma: keep
#include "pros/device.h" // IWYU pragma: keep
#include "pros/device.hpp" // IWYU pragma: keep
#include "pros/distance.h" // IWYU pragma: keep
#include "pros/distance.hpp" // IWYU pragma: keep
#include "pros/error.h" // IWYU pragma: keep
#include "pros/ext_adi.h" // IWYU pragma: keep
#include "pros/gps.h" // IWYU pragma: keep
#include "pros/gps.hpp" // IWYU pragma: keep
#include "pros/imu.h" // IWYU pragma: keep
#include "pros/imu.hpp" // IWYU pragma: keep
#include "pros/link.h" // IWYU pragma: keep
#include "pros/link.hpp" // IWYU pragma: keep
#include "pros/llemu.h" // IWYU pragma: keep
#include "pros/llemu.hpp" // IWYU pragma: keep
#include "pros/misc.h" // IWYU pragma: keep
#include "pros/misc.hpp" // IWYU pragma: keep
#include "pros/motor_group.hpp" // IWYU pragma: keep
#include "pros/motors.h" // IWYU pragma: keep
#include "pros/motors.hpp" // IWYU pragma: keep
#include "pros/optical.h" // IWYU pragma: keep
#include "pros/optical.hpp" // IWYU pragma: keep
#include "pros/rotation.h" // IWYU pragma: keep
#include "pros/rotation.hpp" // IWYU pragma: keep
#include "pros/rtos.h" // IWYU pragma: keep
#include "pros/rtos.hpp" // IWYU pragma: keep
#include "pros/screen.h" // IWYU pragma: keep
#include "pros/screen.hpp" // IWYU pragma: keep
#include "pros/serial.h" // IWYU pragma: keep
#include "pros/serial.hpp" // IWYU pragma: keep
#include "pros/version.h" // IWYU pragma: keep
#include "pros/vision.h" // IWYU pragma: keep
#include "pros/vision.hpp" // IWYU pragma: keep

/* LVGL */
#include "liblvgl/lvgl.h" // IWYU pragma: keep

//util definations 
#include <cmath> // IWYU pragma: keep
#include <string> // IWYU pragma: keep
#include <vector> // IWYU pragma: keep
#include <sstream> // IWYU pragma: keep
#include <iomanip> // IWYU pragma: keep
#include <iostream> // IWYU pragma: keep
#include <fstream> // IWYU pragma: keep
#include <iterator> // IWYU pragma: keep
#include <algorithm> // IWYU pragma: keep
#include <initializer_list> // IWYU pragma: keep
#include <memory> // IWYU pragma: keep
#include <array> // IWYU pragma: keep
#include <list> // IWYU pragma: keep
#include <map> // IWYU pragma: keep
#include <set> // IWYU pragma: keep
#include <queue> // IWYU pragma: keep
#include <stack> // IWYU pragma: keep
#include <utility> // IWYU pragma: keep             
#include <functional> // IWYU pragma: keep
#include <type_traits> // IWYU pragma: keep
#include <thread> // IWYU pragma: keep
#include <chrono> // IWYU pragma: keep
#include <condition_variable> // IWYU pragma: keep
#include <mutex> // IWYU pragma: keep
#include <atomic> // IWYU pragma: keep
#include <future> // IWYU pragma: keep
#include <stdexcept> // IWYU pragma: keep   
#include <cassert> // IWYU pragma: keep
#include <climits> // IWYU pragma: keep
#include <cstddef> // IWYU pragma: keep
#include <cstdint> // IWYU pragma: keep     
/**
 * If you find doing pros::Motor() to be tedious and you'd prefer just to do
 * Motor, you can use the namespace with the following commented out line.
 *
 * IMPORTANT: Only the okapi or pros namespace may be used, not both
 * concurrently! The okapi namespace will export all symbols inside the pros
 * namespace.
 */
// using namespace pros;
// using namespace pros::literals;
// using namespace okapi;

/**
 * Prototypes for the competition control tasks are redefined here to ensure
 * that they can be called from user code (i.e. calling autonomous from a
 * button press in opcontrol() for testing purposes).
 */
#ifdef __cplusplus
extern "C" {
#endif
void autonomous(void);
void initialize(void);
void disabled(void);
void competition_initialize(void);
void opcontrol(void);
#ifdef __cplusplus
}
#endif

// Shared global device declarations
// The actual definitions are in src/main.cpp
extern pros::Controller controller; // defined in src/main.cpp
extern pros::Motor intake1; // top intake motor - define port in src/main.cpp
extern pros::Motor intake2; // bottom intake motor - define port in src/main.cpp

#ifdef __cplusplus
/**
 * You can add C++-only headers here
 */
// Function in touchscreen to refresh the selected auton label
void update_match_data();
#include <iostream>
#endif

#endif  // _PROS_MAIN_H_
