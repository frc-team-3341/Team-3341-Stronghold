#ifndef FollowWall_H
#define FollowWall_H

#include "../CommandBase.h"
#include "WPILib.h"

class FollowWall: public CommandBase
{
private:
	const double WALL_CLOSE;
public:
	FollowWall();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
