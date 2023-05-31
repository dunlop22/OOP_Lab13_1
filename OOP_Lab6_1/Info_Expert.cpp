#include "Info_Expert.h"

Info_Expert::Info_Expert(vector <Parcel*> parc_spisok_old)
{
	copy(parc_spisok_old.begin(), parc_spisok_old.end(), back_inserter(parc_spisok));
}

void Info_Expert::get_dimensions_count()
{
	sum_all = 0;
	sum_pok = 0;
	for (int i = 0;i < parc_spisok.size();i++)
	{
		double sum = 0;
		double sum_potr = 0;
		vector <double> temp;

		temp = parc_spisok[i]->get_dimensions();	//получение размеров посылок

		sum = temp[4] * 250;		//стоимость перевозки фактическая	1кг перевозимого груза - 250руб (для перевозчика / фактические расходы на перевозку)
		sum_potr = temp[4] * 350;
		if (temp[0] > 3 || temp[1] > 3 || temp[2] > 3)		//увеличение стоимости отправки на 25%
		{
			sum = sum * 1.25;
			sum_potr = sum_potr * 1.35;
		}
		sum = sum + sum * (0.15 * temp[3]);		//установка повышенной нормы для опасного груза
		sum_potr = sum_potr + sum_potr * (0.25 * temp[3]);

		sum_all = sum_all + sum;
		sum_pok = sum_pok + sum_potr;
	}
}

double Info_Expert::get_all_cost()
{
	return sum_all;
}

double Info_Expert::get_pok_cost()
{
	return sum_pok;
}
