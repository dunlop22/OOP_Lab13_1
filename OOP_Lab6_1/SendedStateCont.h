#pragma once
#include "StateCont.h"
class SendedStateCont :
    public StateCont
{
public:
    void putParcel(Parcel* parcel);
    string getStatus();
};

