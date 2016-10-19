#include "OI.h"
#include "Commands/DriveReverse.h"
#include "Commands/DriveForward.h"
#include "Commands/TurnAndDrive.h"
#include "Commands/ShootBall.h"
#include "Commands/StopAcquirer.h"
#include "Commands/GetBall.h"
#include "CommandBase.h"

/*
 * DESCRIPTION:
 *
 * DRIVESTICK is used to drive robot and control drive functionality
 * via use of buttons
 * 		Buttons: Hold down button 13 to Drive Reverse
 * 				 Press button 5 to ToggleRotationCurve (Cubic vs Normal control)
 *
 * OPERATORSTICK is used to control the Arm via Joystick and
 * Acquirer via buttons
 * 		Buttons: Hold down button 10 to shoot ball
 * 				 Hold down button 9 to get ball
 * 				 Press button 8 to stop acquirer (in case of emergency)
 */
OI::OI() :
    driveStickLeft(new Joystick(DRIVESTICKLEFT)),
	driveStickRight(new Joystick(DRIVESTICKRIGHT)),
	operatorStick(new Joystick(OPERATORSTICK))
{
	// TODO: Make toggle for TankDrive -> ArcadeDrive


    // Hold down button 2 to "switch the front and back sides" of the robot
    // Make driving in reverse much easier
    Button* toggleReverse = new JoystickButton(driveStickLeft, 5);
    toggleReverse->WhenPressed(new DriveReverse());
    toggleReverse->WhenReleased(new DriveForward());
}

Joystick* OI::getDriveStickLeft()
{
    return driveStickLeft;
}

Joystick* OI::getDriveStickRight()
{
	return driveStickRight;
}

Joystick* OI::getOperatorStick()
{
    return operatorStick;
}
