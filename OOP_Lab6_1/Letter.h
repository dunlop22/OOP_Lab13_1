#pragma once
#include <iostream>
#include "Distribution.h"
using namespace std;
class Letter :
    public Distribution
{
private:
    double ves;
public:
    void set_town(string town1, string town2);
    void set_ves(double ves);
    void print_inf();
    Distribution* clone();
};

