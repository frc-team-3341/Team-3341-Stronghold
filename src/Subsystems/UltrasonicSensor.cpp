#include "UltrasonicSensor.h"
#include "../RobotMap.h"

UltrasonicSensor::UltrasonicSensor() :
Subsystem("ExampleSubsystem")
{
	ultra = new Ultrasonic(1, 1); // assigns ultra to be an ultrasonic sensor which uses DigitalOutput 1 for the echo pulse and DigitalInput 1 for the trigger pulse
	ultra->SetAutomaticMode(true); // turns on automatic mode}
}
void UltrasonicSensor::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}


/**
 * Note: As of 2/17/16 this method is placeholder code
 */
double getFrontSensorValue(){
	//TODO: Replace with working code
	double range = ultra->GetRangeInches(); // reads the range on the ultrasonic sensor

	return range;
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
