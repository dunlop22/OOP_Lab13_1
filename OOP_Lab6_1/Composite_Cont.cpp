#include "Composite_Cont.h"

//проверка пустого места в транспорте
bool check_space(Transport trans, Container* Cont)
{
	if (trans.check_free_obem() >= Cont->space_obem())
	{
		return true;
	}
	return false;
}

//проверка соответствия типа транспорта
bool check_vid(Transport trans, int tip)
{
	if (trans.tip_tranporta == tip)
	{
		return true;
	}
	return false;
}

void Composite_Cont::accumulation_parcel(Container* Cont)
{
	int rez;
	if (children.size() != 0)		//проверка на наличие каких-либо контейнеров
	{
		for (auto iter = children.begin(); iter != children.end(); iter++)		//перебор всех видов транспорта
		{
			rez = 0;
			if (check_vid((*iter), Cont->vid_transporta))		//проверка совпадения видов транспорта
			{
				rez++;
				if (check_space((*iter), Cont))    //проверка свободного места в транспорте
				{
					rez++;
					//свободное место есть, вид транспорта совпадает
					//добавление контейнера в транспорт


				}
			}
			if (rez == 2)
			{
				//добавление контейнера в транспорт
				(*iter).add_cont(*Cont);

				return;
			}
		}
	}
	      //создание нового вида транспорта

	Transport* temp_tranport = new Automobile_Trans();
	delete temp_tranport;
	if (Cont->vid_transporta == 1)
	{
		temp_tranport = new Automobile_Trans();
		temp_tranport->tip_tranporta = 1;
	}
	else if (Cont->vid_transporta == 2)
	{
		temp_tranport = new Railway_Trans();
		temp_tranport->tip_tranporta = 2;
	}
	else if (Cont->vid_transporta == 3)
	{
		temp_tranport = new Fly_Trans();
		temp_tranport->tip_tranporta = 3;
	}
	temp_tranport->add_cont(*Cont);//добавление контейнера в транспорт
	children.push_back(*temp_tranport);		//добавление нового транспорта в список
}

void Composite_Cont::print_info()
{
	if (children.size() != 0)		//проверка на наличие какого-либо транспорта
	{
		for (auto iter = children.begin(); iter != children.end(); iter++)		//перебор всех видов транспорта
		{
			(*iter).print_information();	//вывод информации о внутренних контейнерах
		}
		cout << "\n\nВсего транспорта: " << children.size();
	}
}
