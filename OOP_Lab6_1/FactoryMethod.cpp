#include "FactoryMethod.h"

PoolDangerCont* FactoryMethod::new_full_pool()
{
	PoolDangerCont *factr_pool = new PoolDangerCont();
	int i = 0;
	cout << "Заполнение пула опасных контейнеров\n\n";
	while (factr_pool->pool_new_cont())
	{
		i++;
	}
	cout << "\n\nВ пуле создано " << i << " новых опасных контейнеров";
	return factr_pool;
}
