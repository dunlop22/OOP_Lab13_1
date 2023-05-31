#include "Director.h"

Director::Director(Builder* builder)
{
	this->build = builder;
}

Container* Director::Contruct_Cont()
{
	build->buildBWall();
	build->buildSWall();
	build->buildKarkas();
	build->createCont();

	return build->get_cont();
}
