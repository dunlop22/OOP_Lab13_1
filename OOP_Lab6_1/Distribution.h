#pragma once
#include <string>
using namespace std;
class Distribution
{
protected:
	string town1;	//����� �����������
	string town2;	//����� ����������

public:
	virtual Distribution* clone() = 0;
	virtual void print_inf() = 0;
};


