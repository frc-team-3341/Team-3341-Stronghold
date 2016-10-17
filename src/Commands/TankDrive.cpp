#include "TankDrive.h"

TankDrive::TankDrive()
{
	Requires(drive);
}

void TankDrive::Initialize()
{
}

void TankDrive::Execute()
{
	double leftY = oi->getDriveStickLeft()->GetY();
	double rightY = -oi->getDriveStickRight()->GetY();

	drive->tankDrive(leftY, rightY);
}

bool TankDrive::IsFinished()
{
	return false;
}

void TankDrive::End()
{
}

void TankDrive::Interrupted()
{
}
