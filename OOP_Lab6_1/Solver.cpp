#include "Solver.h"
//посылка, передвинься в контейнер
void Solver::parcel_to_container(vector<Container*> container_mass, vector<Parcel*> parcel_mass, int num_parcel)
{
	for (int i = 0; i < parcel_mass.size(); i++)
	{
		if (parcel_mass[i]->danger == 1)		//распределение опасной посылки
		{
			Container* container_temp = new Danger_Cont();

			container_temp->generate_id();
			container_temp->get_parcel(parcel_mass[i]);
			
			container_mass.push_back(container_temp);
		}
		else
		{
			if (container_mass.size() > 0)	//если уже есть контейнеры
			{
				//проверка наличия свободного места к существующих контейнерах
				for (int j = 0; j < container_mass.size(); j++)
				{
					if (container_mass[j]->check_free_obem(parcel_mass[i]->obem))
					{

						//проверка города направления
						if (container_mass[j]->get_town() == parcel_mass[i]->get_town())
						{
							if (container_mass[j]->danger == 0)
							{
								container_mass[j]->get_parcel(parcel_mass[i]);	//добавление 
							}
							else 
							{
								goto new_cont;		//создание нового контейнера
							}
						}
						else     //если контейнер для отправления в данный город еще не был создан/оформлен
						{
							goto new_cont;		//создание нового контейнера
						}
					}
					else    //переход к созданию нового контейнера
					{
						goto new_cont;
					}
				}
			}
			else    //создание нового контейнера
			{
			new_cont:
				Container* container_temp = new Big_Cont();

				container_temp->generate_id();
				container_temp->get_parcel(parcel_mass[i]);
				container_mass.push_back(container_temp);
			}
		}
	}
}




