#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
class FlyWeight
{
private:
	string town1;
	string town2;
	string contain;

public:
	FlyWeight();
	void set_info(string town);
	string get_info();
};




