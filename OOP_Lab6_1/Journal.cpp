#include "Journal.h"


void Journal::set_name(string names)
{
	this->name = names;
}

void Journal::set_town(string town1, string town2)
{
	this->town1 = town1;
	this->town2 = town2;
}

void Journal::print_inf()
{
	cout << "\nГород отправителя: " << this->town1;
	cout << "\nГород получателя: " << this->town2;
	cout << "\nНазвание журанала: " << this->name << "\n";
}

Distribution* Journal::clone()
{
	Distribution* jour_clone = new Journal(*this);
	cout << "\n\nКлонирование журнала!\n" << this << " <-клон-> " << jour_clone;
	return jour_clone;
}
