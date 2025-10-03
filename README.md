# 56S-Lemlib-main

VEX V5 robotics control system for Team 56S built with LemLib and PROS for competitive autonomous navigation and precision control.

## Overview

This repository contains the competition code for Team 56S's VEX V5 robot. The project leverages the LemLib motion library to implement advanced odometry tracking, PID-based movement, and autonomous routines for VEX Robotics Competition (V5RC).

## Features

- **LemLib Motion Control**: Advanced path following and odometry algorithms
- **Autonomous Routines**: Competition-ready autonomous sequences
- **PID Controllers**: Tuned lateral and angular PID for precise movement
- **Odometry Tracking**: Real-time position tracking using IMU and tracking wheels
- **Driver Control**: Optimized control schemes for competitive play
- **PROS Integration**: Built on the PROS kernel for reliable performance

## Tech Stack

- **Framework**: PROS (Professional Robot Operating System)
- **Library**: LemLib v0.5.0+
- **Language**: C++
- **Platform**: VEX V5 Brain

## Hardware Requirements

- VEX V5 Brain
- VEX V5 Smart Motors
- VEX V5 Inertial Sensor (IMU)
- Optional: Tracking wheels for enhanced odometry accuracy

## Installation

### Prerequisites
- PROS CLI installed ([Installation Guide](https://pros.cs.purdue.edu/v5/getting-started/index.html))
- VEX V5 Toolchain
- Visual Studio Code (recommended)

### Setup

1. Clone the repository:

git clone https://github.com/jonahchang207/56S-Lemlib-main.git
cd 56S-Lemlib-main

2. Build the project:

pros make

3. Upload to V5 Brain:

pros upload

## Project Structure

56S-Lemlib-main/
├── src/              # Source files
│   └── main.cpp      # Main program logic
├── include/          # Header files
│   └── main.h        # Main header declarations
├── firmware/         # VEX firmware
├── Makefile          # Build configuration
└── project.pros      # PROS project settings

## Configuration

### Robot Setup
Configure your robot's hardware in the source files:
- Motor ports and gearing
- IMU port
- Tracking wheel configuration (if applicable)
- Chassis dimensions and wheel diameter

### PID Tuning
Tune the PID controllers for optimal performance:
- Lateral PID (forward/backward movement)
- Angular PID (turning)
- Adjust constants in the chassis configuration

## Usage

### Autonomous Mode
Select autonomous routines from the V5 brain screen during competition. Routines are pre-programmed for optimal scoring.

### Driver Control
Standard tank or arcade drive controls configured for competition driving.

## Development

### Building

pros make

### Uploading

pros upload

### Terminal Output

pros terminal

## Documentation

- [LemLib Documentation](https://lemlib.readthedocs.io/)
- [PROS Documentation](https://pros.cs.purdue.edu/)
- [VEX Robotics](https://www.vexrobotics.com/)

## Contributing

Contributions, bug reports, and feature requests are welcome! Please open an issue or submit a pull request.

## Team

**Team 56S** - VEX Robotics Competition

## License

This project is open source and available for use by VEX teams.

## Acknowledgments

- [LemLib Team](https://github.com/LemLib) - For the excellent motion control library
- [PROS Development Team](https://github.com/purduesigbots) - For the robust operating system
- VEX Robotics Community

---

**Go Team 56S!** 🤖
