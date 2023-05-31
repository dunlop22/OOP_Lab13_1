#include "Letter.h"

void Letter::set_town(string town1, string town2)
{
	this->town1 = town1;
	this->town2 = town2;
}

void Letter::set_ves(double ves)
{
	this->ves = ves;
}

void Letter::print_inf()
{
	cout << "\nГород отправителя: " << this->town1;
	cout << "\nГород получателя: " << this->town2;
	cout << "\nВес письма: " << this->ves << "\n";
}

Distribution* Letter::clone()
{
	Distribution* lett_clone = new Letter(*this);

	cout << "Клонирование письма...\n" << this << " --clone--> " << lett_clone << endl;

	return lett_clone;
}
