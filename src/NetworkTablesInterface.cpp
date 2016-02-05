#include "NetworkTablesInterface.h"

bool NetworkTablesInterface::UFound()
{
	return NetworkTable::GetTable("cv")->GetBoolean("objectFound", false);
}

double NetworkTablesInterface::GetDistance()
{
	return NetworkTable::GetTable("cv")->GetNumber("distance_m", -1.0);
}

double NetworkTablesInterface::GetAzimuth()
{
	return NetworkTable::GetTable("cv")->GetNumber("azimuth_deg", -1.0);
}

double NetworkTablesInterface::GetAltitude()
{
	return NetworkTable::GetTable("cv")->GetNumber("altitude_deg", -1.0);
}
