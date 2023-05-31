#pragma once
#include "Builder.h"
class Director
{
private:
	Builder* build;

public:
	Director(Builder* builder);
	Container* Contruct_Cont();
};

