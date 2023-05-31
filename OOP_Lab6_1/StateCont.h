#pragma once
#include "Container.h"

class Container;

class StateCont
{
protected:
	Container* myContainer;

public:
	void setContainer(Container* container);
	virtual void putParcel(Parcel* parcel) = 0;
	virtual string getStatus() = 0;
};

