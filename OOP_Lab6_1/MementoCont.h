#pragma once
#include "Parcel.h"
#include "StateCont.h"

class StateCont;

class MementoCont
{
private:
	vector <Parcel*> parc_mem;
	StateCont* myState_c;

public:
	MementoCont(StateCont* myState, vector<Parcel*> parc);
	StateCont* getState();
	vector<Parcel*> getParcels();
};

