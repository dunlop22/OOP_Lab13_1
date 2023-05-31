#pragma once
#include <string>
using namespace std;
class Distribution
{
protected:
	string town1;	//город отправителя
	string town2;	//город получателя

public:
	virtual Distribution* clone() = 0;
	virtual void print_inf() = 0;
};


