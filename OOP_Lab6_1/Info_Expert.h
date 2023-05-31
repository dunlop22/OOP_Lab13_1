#pragma once
#include <vector>
#include "Parcel.h"
class Info_Expert
{
	vector <Parcel*> parc_spisok;
	double sum_all;
	double sum_pok;
public:
	Info_Expert(vector <Parcel*> parc_spisok_old);
	void get_dimensions_count();
	double get_all_cost();
	double get_pok_cost();
};

