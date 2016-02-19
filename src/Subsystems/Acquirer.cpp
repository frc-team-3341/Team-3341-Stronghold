#include <Subsystems/Acquirer.h>
#include "../RobotMap.h"

Acquirer::Acquirer(): Subsystem("Acquirer")
{
	motor = new Victor(2);
	enabled = false;
	ir = new DigitalInput(ACQUIRER_IR);
}

void Acquirer::Enable()
{
	enabled = true;
}

void Acquirer::Disable()
{
	enabled = false;
}

void Acquirer::BallIn()
{
	if(enabled)
	motor->SetSpeed(-1);
}

void Acquirer::BallOut()
{
	if(enabled)
	motor->SetSpeed(1);
}

void Acquirer::Stop()
{
	motor->SetSpeed(0);
}

bool Acquirer::IsEnabled()
{
	return enabled;
}

bool Acquirer::DetectBall()
{
	return false;
}
bool Acquirer::GetInput()
{ir->UpdateTable();
	return ir->Get();
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
