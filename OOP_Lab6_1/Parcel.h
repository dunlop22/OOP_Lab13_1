#pragma once
#define _CRT_SECURE_NO_WARNINGS
//#include "Container.h"
#include <conio.h>
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include "Language.h"
using namespace std;
class Parcel
{
public:
	int danger;
	double obem;
	int id;
	string town_sender;
	string town_recipient;
	double shirina;
	double visota;
	double dlina;
	double weight;
	int status;

public:
	Parcel();
	Parcel(string town_sender, string town_recipient, double shirina, double visota, double dlina, double weight, int danger);
	virtual void set_parcel(Parcel* parc);  //установка значения объекта
	virtual bool check_info();  //проверка вводимой инфомации
	virtual bool send_parcel();   //генерация случайного события. будет отправлена посылка или нет     с вероятностью 1/3
	
	int get_id();	//возвращение id

	//вывод информации о посылке
	void print_information();

	//генерация случайного номера для посылки (реализовать проверку уникальности)
	void generate_id();

	//получение города получателя
	string get_town();

	//внесение информации о посылке
	virtual void set_information(Language* lang);
	double get_obem();
	vector <double> get_dimensions();

	void update(int state);
	int get_status();
	Parcel* clone();
};

