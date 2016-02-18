#ifndef UltrasonicSensor_H
#define UltrasonicSensor_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class UltrasonicSensor: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	Ultrasonic* ultra;
public:
	UltrasonicSensor();
	void InitDefaultCommand();
	double getValue();
};

#endif
