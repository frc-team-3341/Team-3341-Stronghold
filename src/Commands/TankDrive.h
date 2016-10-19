#ifndef TankDrive_H
#define TankDrive_H

#include "../CommandBase.h"
#include "WPILib.h"

class TankDrive: public CommandBase {
public:
	TankDrive();
	void Initialize();
	void Execute();bool IsFinished();
	void End();
	void Interrupted();
private:
	double mapToCubic(double a, double b, double signal);
};

#endif
