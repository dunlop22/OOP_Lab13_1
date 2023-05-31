#pragma once 
#include <string>
#include "Parcel.h"	
#include <vector>
#include "SmallWall.h"
#include "BigWall.h"
#include "Karkas.h"
#include "StateCont.h"
#include "MementoCont.h"
using namespace std;

class StateCont;

class Container
{
	//маленький
	//большой
	//для опасных грузов
private:
	int id;	//уникальный номер
	string town;	//направление контейнера
	vector<Parcel*> parce;
	int kol_vo_parcel = 0;		//Общее количество посылок в контейнере
	Karkas* kark;
	BigWall* bWall;
	SmallWall* sWall;

	StateCont* myState;

	StateCont* sendedState;
	StateCont* notSendedState;

	vector <MementoCont> Mem_con1;

public:
	double cost = 0;
	int vid_transporta;
	int danger = 0;
			//1 - автомобильный
			//2 - железнодорожный
			//3 - воздушный

protected:
	double free_obem;			//Количество свободного места в контейнере
	double space;

public:
	Container();
	Container(StateCont* sendedState, StateCont* notSendedState);
	Container(SmallWall* sWall1, BigWall* bWall1, Karkas* kark1);
	virtual double space_obem();
	virtual int gen_vid_transporta();	//генерация варианта отправки
	virtual bool check_danger();
	virtual void generate_id();
	virtual void get_parcel(Parcel* parc);
	virtual bool check_free_obem(double obem);
	virtual string get_town();
	virtual int get_id();
	virtual void print_information_c(int tip);
	virtual vector<Parcel*> get_inf_parcel();
	void print_wall_karkas();

	void putParcel(Parcel* parcel);
	double get_procent_occupancy();		//проверка заполненности контейнера
	void save_memento();
	void restore_memento();
	//void get_cost_cont();
};

//контейнер делегат транспортное средство

//при создании контейнера он конфигурируется под то транпортное средство, на котором он будет передвигаться