#include "FactoryMethod.h"

PoolDangerCont* FactoryMethod::new_full_pool()
{
	PoolDangerCont *factr_pool = new PoolDangerCont();
	int i = 0;
	cout << "���������� ���� ������� �����������\n\n";
	while (factr_pool->pool_new_cont())
	{
		i++;
	}
	cout << "\n\n� ���� ������� " << i << " ����� ������� �����������";
	return factr_pool;
}
