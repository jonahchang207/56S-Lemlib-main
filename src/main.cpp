#include "main.h"
#include "lemlib/api.hpp" // IWYU pragma: keep
#include "touchscreen.hpp"
#include "auton/registry.hpp"

// controller
pros::Controller controller(pros::E_CONTROLLER_MASTER);



/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
    pros::lcd::initialize(); // initialize brain screen
    chassis.calibrate(); // calibrate sensors

     // clear the brain LCD after LVGL takes over to avoid overlapping output
    pros::lcd::clear();

    // initialize touchscreen UI (LVGL)
    touchscreen_int();
   

    // the default rate is 50. however, if you need to change the rate, you
    // can do the following.
    // lemlib::bufferedStdout().setRate(...);
    // If you use bluetooth or a wired connection, you will want to have a rate of 10ms

    // for more information on how the formatting for the loggers
    // works, refer to the fmtlib docs

    // thread to for brain screen and position logging
    // pros::Task screenTask([&]() {
    //     while (true) {
    //         // print robot location to the brain screen
    //         pros::lcd::print(0, "X: %f", chassis.getPose().x); // x
    //         pros::lcd::print(1, "Y: %f", chassis.getPose().y); // y
    //         pros::lcd::print(2, "Theta: %f", chassis.getPose().theta); // heading
    //         // log position telemetry
    //         lemlib::telemetrySink()->info("Chassis pose: {}", chassis.getPose());
    //         // delay to save resources
    //         pros::delay(50);
    //     }
    // });
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
    /*
    int sel = ui::selected_auton();
    pros::lcd::print(3, "Selected auton: %d", sel);
    const auto& list = auton::Registry::instance().autons();
    if (sel >= 0 && sel < (int)list.size()) {
        auto a = list[sel];
        if (a) a->run();
    } else {
        // invalid selection - do nothing
    }
    */
    chassis.setPose(61, 16, 270);
        
        intakeFunctionAuton( intakeMid,127);
        chassis.moveToPose(27, 25, 230, 4000,{.forwards = true , .minSpeed=45});
        
        // to the mid goal
        chassis.moveToPose(13.6, 12.8, 230, 4000,{.forwards = true , .minSpeed=45});
        // intake block 
        intakeFunctionAuton(intakeBottom, 127);
        pros::delay(1500);
        intakeFunctionAuton( intakeMid,127);
        // got ot the first match load
        chassis.moveToPose(27, 25, 230, 4000,{.forwards = false , .minSpeed=45});
        chassis.moveToPose(60, 47, 0, 4000,{.forwards = true , .minSpeed=45});

        intakeFunctionAuton( intakeMid,127);
        pros::delay(1500);
        // go to high goal then score on high goal 1 
        chassis.moveToPose(31, 47, 0, 4000,{.forwards = false , .minSpeed=45});

        intakeFunctionAuton(intakeTop, 127);
        pros::delay(1500);
        intakeFunctionAuton( intakeMid,127);

        chassis.moveToPose(42, 47, 0, 4000,{.forwards = true , .minSpeed=45});

        // to next 3 ball group 
        chassis.moveToPoint(22, -22, 4000,{.forwards = false , .minSpeed=45});

        // intake 3 balls from match load 
        chassis.moveToPose(58, -47, 0, 4000,{.forwards = true , .minSpeed=45});
        
        intakeFunctionAuton( intakeMid,127);
        pros::delay(1500);
        //final high goal score
        chassis.moveToPose(32, -47, 0, 4000,{.forwards = false , .minSpeed=45});

        intakeFunctionAuton(intakeTop, 127);
    

    

}

/**
 * Runs in driver control
 */
void opcontrol() {
    // controller
    // loop to continuously update motors
    while (true) {
        // get joystick positions
        int leftY = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
        int rightX = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);
        // move the chassis with curvature drive
        chassis.arcade(leftY, rightX);
        // delay to save resources
        intakeFunction(); // run intake function
        pros::delay(10);
        
    }
}