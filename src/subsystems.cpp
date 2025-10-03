#include "main.h"
#include "pros/optical.hpp"
#include "subsystems.hpp"

// controller is defined in main.cpp



// motor groups
pros::MotorGroup leftMotors({-1, -2, -3}, pros::MotorGearset::blue);
pros::MotorGroup rightMotors({4, 5, 6}, pros::MotorGearset::blue);


// Inertial Sensor
pros::Imu imu(7);

// tracking wheels
pros::Rotation horizontalEnc(19);
pros::Rotation verticalEnc(20);
lemlib::TrackingWheel horizontal(&horizontalEnc, lemlib::Omniwheel::NEW_2, -1.85);
lemlib::TrackingWheel vertical(&verticalEnc, lemlib::Omniwheel::NEW_2, -0.85);

// drivetrain settings
lemlib::Drivetrain drivetrain(&leftMotors, 
    &rightMotors, 
    14, 
    lemlib::Omniwheel::NEW_275, 
    450, 
    2);

// lateral motion controller TUNED DONT TOUCH)
lemlib::ControllerSettings linearController(
    24, 
    0, 
    99.7, 
    3, 
    1, 
    100, 
    3, 
    500, 
    20);

// angular motion controller
lemlib::ControllerSettings angularController(
    2.9, 
    0, 
    15, 
    3, 
    1, 
    100, 
    3, 
    500, 
    0);

// sensors for odometry
lemlib::OdomSensors sensors(&vertical, 
    nullptr, 
    &horizontal, 
    nullptr, 
    &imu);

// input curves
lemlib::ExpoDriveCurve throttleCurve(3, 10, 1.019);
lemlib::ExpoDriveCurve steerCurve(3, 10, 1.019);

// chassis
lemlib::Chassis chassis(drivetrain, 
    linearController, 
    angularController, 
    sensors, 
    &throttleCurve, 
    &steerCurve);

// Intake motors (ports are placeholders; change as needed)
pros::Motor intake1(12,pros::v5::MotorGears::blue); 
pros::Motor intake2(11,pros::v5::MotorGears::blue);
pros::Optical optical(8); // Optical sensor on port 8



