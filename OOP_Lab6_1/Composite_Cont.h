#pragma once
#include <iostream>
#include <list>
#include "Container.h"
#include "Transport.h"

#include "Automobile_Trans.h"
#include "Railway_Trans.h"
#include "Fly_Trans.h"

class Composite_Cont :
    public Container
{
private:
    list <Transport> children;
public:
    void accumulation_parcel(Container* Cont);
    void print_info();
};

