#pragma once
class Wall
{
protected:
	double dlina;
	double shirina;
public:
	Wall(double dlina, double shirina);
	virtual double get_shirina();
	virtual double get_dlina();
};

