#include "Wall.h"

Wall::Wall(double dlina, double shirina)
{
	this->dlina = dlina;
	this->shirina = shirina;
}

double Wall::get_shirina()
{
	return this->shirina;
}

double Wall::get_dlina()
{
	return this->dlina;
}
