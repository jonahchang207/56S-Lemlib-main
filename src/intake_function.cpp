#include "main.h" // IWYU pragma: keep




void intakeFunction() {
    bool r1_pressed = controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1);
    bool l1_pressed = controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1);
    bool r2_pressed = controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2);
    bool l2_pressed = controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2);
    
    // Motor power settings
    const int intake_power = 127;
    const int intake_power_slow = 80;  // For precision control
    
    // Advanced control logic for two-motor intake
    // Bottom motor always intakes (positive) when any spin mode active
    if (r1_pressed) {
        // High spin: top negative, bottom positive
        static int current_power = 0;
        if (current_power < intake_power) {
            current_power += 10;
        }
        intake1.move(-current_power); // top
        intake2.move(current_power);  // bottom
    }
    else if (r2_pressed) {
        // Middle spin: top positive, bottom positive
        static int current_power = 0;
        if (current_power < intake_power) {
            current_power += 10;
        }
        intake1.move(current_power);  // top
        intake2.move(-current_power);  // bottom
    }
    else if (l2_pressed) {
        // Reverse both
        static int current_power = 0;
        if (current_power < intake_power) {
            current_power += 10;
        }
        intake1.move(current_power);
        intake2.move(-current_power);
    }
    else if (l1_pressed) {
        // Bottom only in: top off, bottom positive
        static int current_power = 0;
        if (current_power < intake_power) {
            current_power += 10;
        }
        intake1.move(-current_power);
        intake2.move(0);
    }
    else {
        // No buttons: gradual deceleration/ramp-down
        static int current_power = 0;
        if (current_power > 0) {
            current_power -= 15;
            if (current_power < 0) current_power = 0;
        }
        intake1.move(0);
        intake2.move(0);
    }

}

void intakeFunctionAuton(IntakeMode mode, int power) {
    // clamp power to valid PROS range [-127, 127]
    if (power > 127) power = 127;
    if (power < -127) power = -127;

    switch (mode) {
        case intakeTop:
            // Middle spin: top positive, bottom positive
            intake1.move(power);
            intake2.move(power);
            break;
        case intakeBottom:
            // Reverse both
            intake1.move(-power);
            intake2.move(-power);
            break;
        case intakeMid:
            //just spin the bottom to hold balls in the middle
            intake1.move(-power);
            intake2.move(0);
            break;
        default:
            // High spin: top negative, bottom positive
            intake1.move(-power);
            intake2.move(power);
            break;
    }
}