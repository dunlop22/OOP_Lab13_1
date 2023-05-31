#include "FlyWeight.h"
FlyWeight::FlyWeight()
{
	this->town1 = "Барнаул";		//город отправки рассылки
	this->contain = "Массовая рассылка\n \
					 Данная рассылка создана в автоматическом режиме";

}
void FlyWeight::set_info(string town)
{
	this->town2 = town;
}

string FlyWeight::get_info()
{
	return this->town2;
}
