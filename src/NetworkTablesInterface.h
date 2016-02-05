#ifndef NETWORK_TABLES_INTERFACE_H
#define NETWORK_TABLES_INTERFACE_H

#include "NetworkTables/NetworkTable.h"

class NetworkTablesInterface{
public:
	static bool UFound();
	static double GetDistance();
	static double GetAzimuth();
	static double GetAltitude();
};

#endif
