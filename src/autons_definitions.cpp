#include "main.h"

using namespace auton;

// Example: Blue WQE Auton
class BlueWqeAuton : public Auton {
public:
    void run() override {
        // Replace this with the actual autonomous steps
        pros::lcd::print(4, "Running Blue WQE Auton");
        pros::delay(1000);
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
