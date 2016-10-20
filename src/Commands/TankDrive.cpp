#include "TankDrive.h"

TankDrive::TankDrive() {
	Requires(drive);
}

void TankDrive::Initialize() {
}

void TankDrive::Execute() {
	double leftY;
	double rightY;

	Joystick* leftStick = oi->getDriveStickLeft();
	Joystick* rightStick = oi->getDriveStickRight();

	// If a gamepad is connected (has 4 axis)
	if (oi->getDriveStickLeft()->GetAxisCount() == 4) {
		leftY = -leftStick->GetY();
		rightY = leftStick->GetThrottle();
	} else // Regular FRC Joystick
	{
		leftY = leftStick->GetY();
		rightY = -rightStick->GetY();
	}

	// Map inputs to a cubic function
	leftY = mapToCubic(0.3, 0, leftY);
	rightY = mapToCubic(0.3, 0, rightY);

	// FOR CLUB RUSH ONLY: Reduce the max speed
	leftY /= 2;
	rightY /= 2;

	drive->tankDrive(leftY, rightY);
}

bool TankDrive::IsFinished() {
	return false;
}

void TankDrive::End() {
}

void TankDrive::Interrupted() {
}

double TankDrive::mapToCubic(double a, double b, double signal) {
	double control;

	if (signal > 0)
		control = b + (1 - b) * ((a * pow(signal, 3) + (1 - a) * signal));
	else
		control = -b + (1 - b) * ((a * pow(signal, 3) + (1 - a) * signal));

	return control;
}
