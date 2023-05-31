#include "StateCont.h"

void StateCont::setContainer(Container* container)
{
	myContainer = container;
}

void StateCont::putParcel(Parcel* parcel)
{
	this->myContainer->get_parcel(parcel);
}
