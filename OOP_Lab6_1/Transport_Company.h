#pragma once
#include <iostream>
#include <string>
#include <windows.h>
#include <cstdlib>;
#include <vector>
#include "Container.h"          //контейнер
#include "Transport.h"          //транспорт
#include "Parcel.h"             //посылка
#include "Solver.h"             //решатель распределения посылок
#include "ProxyParcel.h"        //прокси для посылки
#include "Decorate_Parcel.h"    //декоратор
#include "Composite_Cont.h"     //композит
#include "Buketik.h"            //класс для адаптера
#include "Adapter_Parcel.h"     //адаптер
#include "Iterator_My.h"		//итератор (LR5-6)
#include "Agregat_My.h"
#include "Element_My.h"			
#include "FlyWeight_Factory.h"	//легковес (LR7-8)
#include "Info_Expert.h"		//информационный эксперт (LR7-8)
#include "Facade.h"				//фасад (LR7-8)
#include "Letter.h"				//письмо-прототип (LR9-10)
#include "Journal.h"			//журнал-прототип (LR9-10)
#include "AbstractFactory.h"	//абстрактная фабрика (LR9-10)
#include "PoolDangerCont.h"		//пул опасных контейнеров (LR9-10)
#include "FactoryMethod.h"		//фабричный метод (LR9-10)
#include "Director.h"			//строитель (LR11)

#include "SendedStateCont.h"	//состояние (LR13)
#include "NotSendedStateCont.h"	//состояние (LR13)

using namespace std;
class Transport_Company
{
private:
	static Transport_Company* instance;
protected:
	Transport_Company() {}
public:
	static Transport_Company* Instance();

	void start_work();
};

