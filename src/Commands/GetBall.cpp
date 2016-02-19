#include "GetBall.h"

GetBall::GetBall()
{
	Requires(acquirer);
}

void GetBall::Initialize()
{
}

void GetBall::Execute()
{
	acquirer->BallIn();
}

bool GetBall::IsFinished()
{
    return true;
}

void GetBall::End()
{
}

void GetBall::Interrupted()
{
}
