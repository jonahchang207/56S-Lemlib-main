#include "main.h"
#include "lemlib/api.hpp" // IWYU pragma: keep
#include "touchscreen.hpp"
#include "subsystems.hpp"

// controller
pros::Controller controller(pros::E_CONTROLLER_MASTER);

// odom offset functions 
void check_odom_direction(){
    pros::lcd::initialize(); // initialize brain screen
    while (true) { // infinite loop
        pros::lcd::print(1, "Rotation Sensor V: %i", verticalEnc.get_position());
        pros::delay(10); // delay to save resources
    }
}

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
    //pros::lcd::initialize(); // initialize brain screen
    chassis.calibrate(); // calibrate sensors

     // clear the brain LCD after LVGL takes over to avoid overlapping output
    pros::lcd::clear();

    //check_odom_direction();
    
    // initialize touchscreen UI (LVGL)
    touchscreen_int();
   

    
}

/**
 * Runs while the robot is disabled
 */
void disabled() {}

/**
 * runs after initialize if the robot is connected to field control
 */
void competition_initialize() {}

// get a path used for pure pursuit
// this needs to be put outside a function
ASSET(example_txt); // '.' replaced with "_" to make c++ happy

/**
 * Runs during auto
 *
 * This is an example autonomous routine which demonstrates a lot of the features LemLib has to offer
 */
void autonomous() {
    // show which auton was selected on the brain screen
    chassis.setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);

    //for turning tuning
    //chassis.turnToHeading(180,99999999,{.maxSpeed = 90},false); 
    // for driving tuning
    //chassis.moveToPoint(0,24,9999999999, {.maxSpeed = 90},false);
    blueWqeAuton(); 
    /*
    int sel = ui::selected_auton();
    pros::lcd::print(3, "Selected auton: %d", sel);
    
    switch(sel) {
        case 0:
            blueWqeAuton();
            break;
        case 1:
            redWqeAuton();
            break;
        case 2:
            skillsAuton();
            break;
        case 3:
            doNothingAuton();
            break;
        default:
            pros::lcd::print(4, "Invalid auton selection");
            break;
    }
    */
    
    
}

/**
 * Runs in driver control
 */
void opcontrol() {
    // controller
    // loop to continuously update motors
    chassis.setBrakeMode(pros::E_MOTOR_BRAKE_COAST);
    while (true) {
        // get joystick positions
        int leftY = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
        int rightX = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);
        // move the chassis with curvature drive
        chassis.arcade(leftY, rightX);
        // delay to save resources
        intakeFunction(); // run intake function
        pros::delay(10);

        if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_B)) {
            flap.toggle(); // extend
        }
        if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_A)) {
            furrydescoremech.toggle(); // extend
        }
    }
}