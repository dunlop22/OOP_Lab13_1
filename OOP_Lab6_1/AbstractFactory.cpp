#include "AbstractFactory.h"

void AbstractFactory::box_to_parcel(Language* rus)
{
	Parcel* par_fab = new Parcel();
	par_fab->set_information(rus);	//создание посылки
	system("cls");
	Decorate_Parcel dec_parc(par_fab);
	dec_parc.set_information();		//декорирование посылки коробкой
	dec_parc.print_information();	//вывод информации о посылкие, которая помещена в коробку
	

		
}
