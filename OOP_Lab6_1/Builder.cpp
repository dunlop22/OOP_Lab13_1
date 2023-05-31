#include "Builder.h"

void Builder::buildSWall()
{
	this->sWall = new SmallWall(3.7, 2.8);
}

void Builder::buildBWall()
{
	this->bWall = new BigWall(5.7, 2.8);
}

void Builder::buildKarkas()
{
	this->kar = new Karkas(2.7, 5.7, 2.8);
}

void Builder::createCont()
{
	Cont = new Container(sWall, bWall, kar);
}

Container* Builder::get_cont()
{
	sWall = nullptr;
	bWall = nullptr;
	kar = nullptr;

	return Cont;
}
