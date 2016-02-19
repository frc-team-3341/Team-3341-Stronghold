#include "FollowWall.h"

FollowWall::FollowWall()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(drive);
	Requires(ultraSensor);
	WALL_CLOSE = 10.0;
}

// Called just before this Command runs the first time
void FollowWall::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void FollowWall::Execute()
{
	//TODO: Test Ultrasonic sensor to figure out how values work
	if (ultraSensor->getFrontSensorValue() >= WALL_CLOSE) {
		drive->arcadeDrive(0, 0.5);
	}
	/* Use this code instead of above depending on how IR Values work
	if (ultraSensor->getFrontSensorValue() <= WALL_CLOSE) {
		drive->arcadeDrive(0, 0.5);
	}
	*/
	else {
		drive->arcadeDrive(0.5,0);
	}
}

// Make this return true when this Command no longer needs to run execute()
bool FollowWall::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void FollowWall::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void FollowWall::Interrupted()
{

}
