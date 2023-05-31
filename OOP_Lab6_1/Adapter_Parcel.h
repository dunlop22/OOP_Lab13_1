#pragma once
#include "Parcel.h"
#include "Buketik.h"
class Adapter_Parcel :
    public Parcel
{
private:

    Buketik* bukt;
public:
    
    Adapter_Parcel(Buketik* buke);
    void set_information();
};

