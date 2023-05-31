#pragma once
#include <iostream>
#include "Distribution.h"
using namespace std;
class Journal :
    public Distribution
{
private:
    string name;

public:
    void set_name(string names);
    void set_town(string town1, string town2);
    void print_inf();
    Distribution* clone();
};

