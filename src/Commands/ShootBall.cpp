#include "ShootBall.h"

ShootBall::ShootBall()
{
	Requires(acquirer);
}

void ShootBall::Initialize()
{

}

void ShootBall::Execute()
{
    // TODO: add shooting code
	acquirer->BallOut();
}

bool ShootBall::IsFinished()
{
    return true;
}

void ShootBall::End()
{
}

void ShootBall::Interrupted()
{
}
