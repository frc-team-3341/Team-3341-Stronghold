#include "WPILib.h"
#include "Commands/Command.h"
#include "Commands/LowBarAutonomous.h"
#include "Commands/MoveArm.h"
#include "Commands/AutonomousProgram.h"
#include "Commands/TurnAndDrive.h"
#include "Commands/WallFollow.h"
#include "CommandBase.h"
#include "Commands/MoatRun.h"
#include "Commands/TurnXDegrees.h"
#include <stdint.h>
#include <Subsystems/Acquirer.h>

class Robot: public IterativeRobot
{
    private:
        LiveWindow* lw;

        void RobotInit()
        {
            CommandBase::init();

            lw = LiveWindow::GetInstance();
        }

        void DisabledPeriodic()
        {
            Scheduler::GetInstance()->Run();
        }

        void AutonomousInit()
        {
        }

        void AutonomousPeriodic()
        {
            Scheduler::GetInstance()->Run();
        }

        void TeleopInit()
        {
            CommandBase::drive->ResetEncoders();
            CommandBase::gyro->ResetGyro();

        }

        void TeleopPeriodic()
        {
        	// Sensors currently disconnected
            //SmartDashboard::PutNumber("Gyro Angle", CommandBase::gyro->GetAngle());
            //SmartDashboard::PutNumber("IR Analog Input", CommandBase::acquirer->GetInput());
            //SmartDashboard::PutBoolean("Ball Loaded", CommandBase::acquirer->DetectBall());
            //SmartDashboard::PutNumber("Right Encoder distance", CommandBase::drive->GetRightEncoderDistance());
            //SmartDashboard::PutNumber("Left Encoder distance", CommandBase::drive->GetLeftEncoderDistance());

            Scheduler::GetInstance()->Run();
        }

        void TestPeriodic()
        {
        	/*
        	 * 	TODO: GamePad info:
        	 * 	Stick Left Y -> GetY
        	 * 	Stick Left X -> GetX
        	 * 	Stick Right Y -> GetThrottle
        	 * 	Stick Right X -> GetZ or GetTwist
        	 */

        	// Joystick Debug information
        	Joystick* testStick = CommandBase::oi->getDriveStickLeft();
            SmartDashboard::PutNumber("GetX", testStick->GetX());
            SmartDashboard::PutNumber("GetY", testStick->GetY());
            SmartDashboard::PutNumber("GetZ", testStick->GetZ());
            SmartDashboard::PutNumber("GetTwist", testStick->GetTwist());
            SmartDashboard::PutNumber("GetThrottle", testStick->GetThrottle());
            SmartDashboard::PutNumber("GetMagnitude", testStick->GetMagnitude());
            SmartDashboard::PutNumber("GetDirectionRadians", testStick->GetDirectionRadians());
            SmartDashboard::PutNumber("GetDirectionDegrees", testStick->GetDirectionDegrees());
            SmartDashboard::PutNumber("GetType", testStick->GetType());
            SmartDashboard::PutNumber("GetAxisCount", testStick->GetAxisCount());
            SmartDashboard::PutNumber("GetButtonCount", testStick->GetButtonCount());
            SmartDashboard::PutNumber("GetPOVCount", testStick->GetPOVCount());

            SmartDashboard::PutBoolean("GetIsXbox", testStick->GetIsXbox());
            lw->Run();
        }
};

START_ROBOT_CLASS(Robot);
