#pragma once
#include "Container.h"
class Transport
{
	//перевозка опасного груза разрешается только на автомобильном транспорте
public:
	void generate_id();
	double check_free_obem();
	void print_information();
	void add_cont(Container Cont);
	vector<Container> Conte;
	int tip_tranporta;
			//1 - автомобильный
			//2 - железнодорожный
			//3 - воздушный

protected:
	int id;	//уникальный номер
	double free_obem;
};

