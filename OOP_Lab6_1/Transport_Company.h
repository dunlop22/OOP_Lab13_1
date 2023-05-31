#pragma once
#include <iostream>
#include <string>
#include <windows.h>
#include <cstdlib>;
#include <vector>
#include "Container.h"          //���������
#include "Transport.h"          //���������
#include "Parcel.h"             //�������
#include "Solver.h"             //�������� ������������� �������
#include "ProxyParcel.h"        //������ ��� �������
#include "Decorate_Parcel.h"    //���������
#include "Composite_Cont.h"     //��������
#include "Buketik.h"            //����� ��� ��������
#include "Adapter_Parcel.h"     //�������
#include "Iterator_My.h"		//�������� (LR5-6)
#include "Agregat_My.h"
#include "Element_My.h"			
#include "FlyWeight_Factory.h"	//�������� (LR7-8)
#include "Info_Expert.h"		//�������������� ������� (LR7-8)
#include "Facade.h"				//����� (LR7-8)
#include "Letter.h"				//������-�������� (LR9-10)
#include "Journal.h"			//������-�������� (LR9-10)
#include "AbstractFactory.h"	//����������� ������� (LR9-10)
#include "PoolDangerCont.h"		//��� ������� ����������� (LR9-10)
#include "FactoryMethod.h"		//��������� ����� (LR9-10)
#include "Director.h"			//��������� (LR11)

#include "SendedStateCont.h"	//��������� (LR13)
#include "NotSendedStateCont.h"	//��������� (LR13)

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

