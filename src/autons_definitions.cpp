#include "main.h"

using namespace auton;

// Example: Blue WQE Auton
class BlueWqeAuton : public Auton {
public:
    void run() override {
        // Replace this with the actual autonomous steps
        pros::lcd::print(4, "Running Blue WQE Auton");
        pros::delay(1000);
        chassis.setPose(61, 16, 270);
        
        intakeFunctionAuton( intakeMid,127);
        chassis.moveToPose(27, 25, 230, 4000,{.forwards = true , .minSpeed=20});

        // to the mid goal
        chassis.moveToPose(13.6, 12.8, 230, 4000,{.forwards = true , .minSpeed=20});
        // intake block 
        intakeFunctionAuton(intakeBottom, 127);
        pros::delay(1500);
        intakeFunctionAuton( intakeMid,127);
        // got ot the first match load
        chassis.moveToPose(27, 25, 230, 4000,{.forwards = false , .minSpeed=20});
        chassis.moveToPose(60, 47, 0, 4000,{.forwards = true , .minSpeed=20});

        intakeFunctionAuton( intakeMid,127);
        pros::delay(1500);
        // go to high goal then score on high goal 1 
        chassis.moveToPose(31, 47, 0, 4000,{.forwards = false , .minSpeed=20});

        intakeFunctionAuton(intakeTop, 127);
        pros::delay(1500);
        intakeFunctionAuton( intakeMid,127);

        // to the mid goal
        chassis.moveToPose(13.6, 12.8, 230, 4000,{.forwards = true , .minSpeed=20});
        // intake block 
        intakeFunctionAuton(intakeBottom, 127);
        pros::delay(1500);
        intakeFunctionAuton( intakeMid,127);
        // got ot the first match load
        chassis.moveToPose(27, 25, 230, 4000,{.forwards = false , .minSpeed=20});
        chassis.moveToPose(60, 47, 0, 4000,{.forwards = true , .minSpeed=20});

        intakeFunctionAuton( intakeMid,127);
        // go to high goal then score on high goal 1 
        chassis.moveToPose(31, 47, 0, 4000,{.forwards = false , .minSpeed=20});

        intakeFunctionAuton(intakeTop, 127);
        pros::delay(1500);
        intakeFunctionAuton( intakeMid,127);
        chassis.moveToPose(42, 47, 0, 4000,{.forwards = true , .minSpeed=20});

        // to next 3 ball group 
        chassis.moveToPoint(22, -22, 4000,{.forwards = false , .minSpeed=20});

        // intake 3 balls from match load 
        chassis.moveToPose(58, -47, 0, 4000,{.forwards = true , .minSpeed=20});
        
        intakeFunctionAuton( intakeMid,127);
        pros::delay(1500);
        //final high goal score
        chassis.moveToPose(32, -47, 0, 4000,{.forwards = false , .minSpeed=20});

        intakeFunctionAuton(intakeTop, 127);
    }
    const char* name() const override { return "blue_wqe_auton"; }
};

static BlueWqeAuton blueWqeInstance;
static Registrar blueWqeReg(&blueWqeInstance);

// Example: Red WQE Auton
class RedWqeAuton : public Auton {
public:
    void run() override {
        pros::lcd::print(4, "Running Red WQE Auton");
        pros::delay(1000);
    }
    const char* name() const override { return "red_wqe_auton"; }
};

static RedWqeAuton redWqeInstance;
static Registrar redWqeReg(&redWqeInstance);

// Example: Skills Auton
class SkillsAuton : public Auton {
public:
    void run() override {
        pros::lcd::print(4, "Running Skills Auton");
        pros::delay(1000);
    }
    const char* name() const override { return "skills"; }
};

static SkillsAuton skillsInstance;
static Registrar skillsReg(&skillsInstance);
