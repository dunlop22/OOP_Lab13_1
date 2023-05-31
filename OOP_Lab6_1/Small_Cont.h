#pragma once
#include "Container.h"
class Small_Cont :
    public Container
{
public:
    Small_Cont();
    virtual bool check_danger();
};

