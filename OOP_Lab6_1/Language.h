#pragma once
#include <iostream>
using namespace std;
class Language
{

public:
	virtual void print_info() = 0;
	virtual void print_num_parc() = 0;
	virtual void print_town_1() = 0;
	virtual void print_town_2() = 0;
	virtual void print_spisok_town() = 0;
	virtual void print_gabarit_1() = 0;
	virtual void print_gabarit_2() = 0;
	virtual void print_gabarit_3() = 0;
	virtual void print_danger() = 0;
	virtual void print_weight() = 0;
	virtual void print_size() = 0;
	virtual void any_key_to_cont() = 0;
	virtual void print_yes() = 0;
	virtual void print_no() = 0;
};

