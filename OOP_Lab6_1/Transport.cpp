#include "Transport.h"

void Transport::generate_id()
{
	this->id = 10000 + rand() % 90000;
}

double Transport::check_free_obem()
{
	return this->free_obem;
}

//вывод информации о перевозимых контейнерах
void Transport::print_information()
{
	cout << "Номер транспорта: " << this->id << " (";
	if (this->tip_tranporta == 1)
	{
		cout << "Автомобильный";
	}
	else if (this->tip_tranporta == 2)
	{
		cout << "Железнодорожный";
	}
	else if (this->tip_tranporta == 3)
	{
		cout << "Воздушный";
	}
	cout << ")\n\nСписок контейнеров:\n";		//вывод индивидуального номера
	for (int i = 0;i < Conte.size();i++)		//вывод информации о вложенных контейнерах и посылках
	{
		Conte[i].print_information_c(0);
	}
	cout << "\n\n";
}

void Transport::add_cont(Container Cont)
{
	this->Conte.push_back(Cont);		//помещение контейнера в транспорт
	this->free_obem = free_obem - Cont.space_obem();		//изменение пустого места в транспорте
}
