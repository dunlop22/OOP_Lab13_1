#pragma once
#include "StateCont.h"
class NotSendedStateCont :
    public StateCont
{
public:
    void putParcel(Parcel* parcel)
    {
        //сделать вывод: кладём такую-то посылку в такой-то контейнер
        if (myContainer->check_free_obem(parcel->get_obem()))
        {
            cout << "Данная посылка будет помещена в контейнер:\n";
            parcel->print_information();
            myContainer->get_parcel(parcel);
            cout << "\n";
        }
        else
        {
            cout << "\nДанная посылка не может быть помещена в контейнер, т.к. для данной посылки недостаточного свободного места.\n";
            parcel->print_information();
            cout << "\n";
        }
    }
};

