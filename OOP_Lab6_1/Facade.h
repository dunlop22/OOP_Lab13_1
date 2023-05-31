#pragma once
#include "Parcel.h"
#include "ProxyParcel.h"
#include <iostream>
#include <conio.h>
#include <locale.h>   
#include <windows.h>
#include "EngLanguage.h"
#include "RusLanguage.h"
#include <vector>
class Facade		//процесс приемки новой посылки
{
	Language* languag;
public:
	Facade(Language* lang);
	void get_new_parcel(vector<Parcel> *parcel_spisok, int* num_parcel);
	void set_language(Language* lang);
};

