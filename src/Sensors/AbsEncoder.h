#ifndef AbsEncoder_H
#define AbsEncoder_H

#include "WPILib.h"

class AbsEncoder
{
    private:
        SPI* myAbsEncoder;
        short input;

    public:
        AbsEncoder();
        short getInput();
};

#endif
