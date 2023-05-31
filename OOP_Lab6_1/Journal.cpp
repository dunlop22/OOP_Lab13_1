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
	cout << "\n����� �����������: " << this->town1;
	cout << "\n����� ����������: " << this->town2;
	cout << "\n�������� ��������: " << this->name << "\n";
}

Distribution* Journal::clone()
{
	Distribution* jour_clone = new Journal(*this);
	cout << "\n\n������������ �������!\n" << this << " <-����-> " << jour_clone;
	return jour_clone;
}
