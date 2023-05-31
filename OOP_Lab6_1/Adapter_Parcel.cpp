#include "Adapter_Parcel.h"
Adapter_Parcel::Adapter_Parcel(Buketik* buke)
{
	bukt = buke;
	
	this->dlina = buke->d;
	this->shirina = buke->w;
	this->visota = buke->l;

	this->weight = buke->ves;
}

void Adapter_Parcel::set_information()
{
	//bukt->set_inf();

	this->generate_id();
	//заполнение недостающих
	do
	{
		cout << "Ввод информации о новой посылке\n\nУникальный номер посылки (id): " << this->id;
		cout << "\n\nВведите город отправителя: ";
		getline(cin, this->town_sender);
	} while (this->town_sender == "");

	vector<string> town = { "Барнаул", "Москва", "Новосибирск", "Владивосток", "Нижний Новгород" };
	int num_town;
	do
	{
		cout << "\n\n1) Барнаул\n2) Москва\n3) Новосибирск\n4) Владивосток\n5) Нижний Новгород";
		cout << "\n\nВыберите город получателя: ";
		num_town = _getch();
	} while (num_town < 49 || num_town >(town.size() + 48));
	this->town_recipient = town[num_town - 49];
	cout << "(" << this->town_recipient << ")";

	this->obem = this->visota * this->shirina * this->dlina;
	
	this->danger = 0;	//установка опасности посылки
}

