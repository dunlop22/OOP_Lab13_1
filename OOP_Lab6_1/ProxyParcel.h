#pragma once
#include "Parcel.h"
#include "Big_Cont.h"

class ProxyParcel :
    public Parcel
{
private:
    Parcel* Parce;

public:
    ProxyParcel(Parcel* parc) :Parcel()
    {
        Parce = parc;
        /*cout << "this" << this->Parce->obem << "\n";
        cout << "parc" << parc->obem;
        _getch();
        */
    };

    bool check_info();  //проверка вводимой инфомации
    bool send_parcel();   //генерация случайного события. будет отправлена посылка или нет     с вероятностью 1/3


};

