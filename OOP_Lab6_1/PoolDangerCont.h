#pragma once
#include "Danger_Cont.h"
using namespace std;
class PoolDangerCont
{
private:
	vector <Danger_Cont*> pool_cont;
	int max_cont = 40;		//допустимое количество контейнеров в пуле

	
public: 
	bool pool_new_cont();		//создание нового опасного контейнера в пул
	void insert_cont(Danger_Cont* cont);	//помещение существующего опасного контейнера в пул
	Danger_Cont* get_pool_cont();		//выдача контейнера из пула
	int get_num_cont();		//получение текущего количества контейнеров в пуле
	~PoolDangerCont();
};

