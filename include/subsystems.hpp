#pragma once
#include "lemlib/api.hpp" // IWYU pragma: keep
#include "pros/optical.hpp"
// Subsystems header: declares motors, motor groups, sensors, drivetrain and settings

// Controller (already declared in main.h as extern)
// Intake motors
extern pros::Motor intake1;
extern pros::Motor intake2;

// Drive motor groups
extern pros::MotorGroup leftMotors;
extern pros::MotorGroup rightMotors;


// IMU
extern pros::Imu imu;

// Tracking encoders and wheels
extern pros::Rotation horizontalEnc;
extern pros::Rotation verticalEnc;
extern lemlib::TrackingWheel horizontal;
extern lemlib::TrackingWheel vertical;

// Drivetrain and controller settings
extern lemlib::Drivetrain drivetrain;
extern lemlib::ControllerSettings linearController;
extern lemlib::ControllerSettings angularController;
extern lemlib::OdomSensors sensors;
extern lemlib::ExpoDriveCurve throttleCurve;
extern lemlib::ExpoDriveCurve steerCurve;

// Chassis
extern lemlib::Chassis chassis;

extern pros::Optical optical;