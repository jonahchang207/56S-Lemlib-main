#include "color_sort.hpp"
#include "main.h"
#include "auton/auton.hpp"

void blueWqeAuton() {
    autonColorSort(SortColorBlue, true);
    chassis.setPose(61, 16, 270);
    
    intakeFunctionAuton( intakeMid,127);
    chassis.moveToPose(27, 25, 230, 4000,{.forwards = true , .minSpeed=70});
    chassis.waitUntilDone();
    // to the mid goal
    chassis.moveToPose(11, 12, 230, 4000,{.forwards = true , .minSpeed=80});
    chassis.waitUntilDone();
    // intake block 
    intakeFunctionAuton(intakeBottom, 127);
    pros::delay(1500);
    intakeFunctionAuton(intakeMid, 127);
    // got ot the first match load
    chassis.moveToPose(27, 25, 230, 4000,{.forwards = false , .minSpeed=45});
    chassis.moveToPose(60, 47, 0, 4000,{.forwards = true , .minSpeed=45});
    chassis.waitUntilDone();

    intakeFunctionAuton(intakeMid, 127);
    pros::delay(1500);
    // go to high goal then score on high goal 1 
    chassis.moveToPose(31, 47, 0, 4000,{.forwards = false , .minSpeed=45});
    chassis.waitUntilDone();

    intakeFunctionAuton(intakeTop, 127);
    pros::delay(1500);
    intakeFunctionAuton(intakeMid, 127);

    chassis.moveToPose(42, 47, 0, 4000,{.forwards = true , .minSpeed=45});
    chassis.waitUntilDone();

    // to next 3 ball group 
    chassis.moveToPoint(22, -22, 4000,{.forwards = false , .minSpeed=45});
    chassis.waitUntilDone();

    // intake 3 balls from match load 
    chassis.moveToPose(58, -47, 0, 4000,{.forwards = true , .minSpeed=45});
    chassis.waitUntilDone();

    intakeFunctionAuton(intakeMid, 127);
    pros::delay(1500);
    //final high goal score
    chassis.moveToPose(32, -47, 0, 4000,{.forwards = false , .minSpeed=45});
    chassis.waitUntilDone();
    
    intakeFunctionAuton(intakeTop, 127);
}

void redWqeAuton() {
    chassis.setPose(-61, 16, 90);
    
    intakeFunctionAuton(intakeMid, 127);
    chassis.moveToPose(-27, 25, 130, 4000, {.forwards = true, .minSpeed = 45},false);
    chassis.moveToPose(-13.6, 12.8, 130, 4000, {.forwards = true, .minSpeed = 45},false);
    intakeFunctionAuton(intakeBottom, 127);
    pros::delay(1500);
    intakeFunctionAuton(intakeMid, 127);

    chassis.moveToPose(-27, 25, 130, 4000, {.forwards = false, .minSpeed = 45},false);
     
    chassis.moveToPose(-60, 47, 180, 4000, {.forwards = true, .minSpeed = 45},false);
     
    
    intakeFunctionAuton(intakeMid, 127);
    pros::delay(1500);

    chassis.moveToPose(-31, 47, 180, 4000, {.forwards = false, .minSpeed = 45},false);

    intakeFunctionAuton(intakeTop, 127);
    pros::delay(1500);
    intakeFunctionAuton(intakeMid, 127);

    chassis.moveToPose(-42, 47, 180, 4000, {.forwards = true, .minSpeed = 45},false);

    chassis.moveToPoint(-22, -22, 4000, {.forwards = false, .minSpeed = 45},false);

    chassis.moveToPose(-58, -47, 180, 4000, {.forwards = true, .minSpeed = 45},false);

    intakeFunctionAuton(intakeMid, 127);
    pros::delay(1500);

    chassis.moveToPose(-32, -47, 180, 4000, {.forwards = false, .minSpeed = 45},false);

    
    
    intakeFunctionAuton(intakeTop, 127);
}

void skillsAuton() {
    pros::lcd::print(4, "Running Skills Auton");
    pros::delay(1000);
}

void doNothingAuton() {
    pros::lcd::print(4, "Do Nothing Selected");
}
