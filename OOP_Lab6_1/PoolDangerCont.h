#pragma once
#include "Danger_Cont.h"
using namespace std;
class PoolDangerCont
{
private:
	vector <Danger_Cont*> pool_cont;
	int max_cont = 40;		//���������� ���������� ����������� � ����

	
public: 
	bool pool_new_cont();		//�������� ������ �������� ���������� � ���
	void insert_cont(Danger_Cont* cont);	//��������� ������������� �������� ���������� � ���
	Danger_Cont* get_pool_cont();		//������ ���������� �� ����
	int get_num_cont();		//��������� �������� ���������� ����������� � ����
	~PoolDangerCont();
};

