#include "main.h"

RobotDeviceInterfaces *global_robot;
pros::Controller *global_controller;

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	std::cout << "Initialize\n";
	global_robot = new RobotDeviceInterfaces();
	global_controller = new pros::Controller(CONTROLLER_MASTER);
	std::cout << "Initialization Finished\n";
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {
	std::cout << "Disabled\n";
	global_robot->deactivate_brakes();
}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
