#pragma once
#include "Container.h"
class Danger_Cont :
	public Container
{
public:
	virtual bool check_danger();
	Danger_Cont();
};

