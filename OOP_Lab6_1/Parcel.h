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
	virtual void set_parcel(Parcel* parc);  //��������� �������� �������
	virtual bool check_info();  //�������� �������� ���������
	virtual bool send_parcel();   //��������� ���������� �������. ����� ���������� ������� ��� ���     � ������������ 1/3
	
	int get_id();	//����������� id

	//����� ���������� � �������
	void print_information();

	//��������� ���������� ������ ��� ������� (����������� �������� ������������)
	void generate_id();

	//��������� ������ ����������
	string get_town();

	//�������� ���������� � �������
	virtual void set_information(Language* lang);
	double get_obem();
	vector <double> get_dimensions();

	void update(int state);
	int get_status();
	Parcel* clone();
};

