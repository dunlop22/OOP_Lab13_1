#include "MementoCont.h"

MementoCont::MementoCont(StateCont* myState, vector<Parcel*> parc)
{
	this->myState_c = myState;
	parc_mem.resize(parc.size());
	std::copy(parc.begin(), parc.end(), parc_mem.begin());
}

StateCont* MementoCont::getState()
{
	return myState_c;
}

vector<Parcel*> MementoCont::getParcels()
{
	return parc_mem;
}
