#pragma once
#include "SmallWall.h"
#include "BigWall.h"
#include "Karkas.h"
#include "Container.h"

class Builder
{
protected:
	SmallWall* sWall;
	BigWall* bWall;
	Karkas* kar;
	Container* Cont;

public:
	virtual void buildSWall();
	virtual void buildBWall();
	virtual void buildKarkas();
	virtual void createCont();
	virtual Container* get_cont();
};

