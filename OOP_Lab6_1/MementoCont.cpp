#include "MementoCont.h"

MementoCont::MementoCont(StateCont* myState, vector<Parcel*> parc)
{
	this->myState_c = myState;
	std::copy(parc.begin(), parc.end(), parc_mem.begin());
}
