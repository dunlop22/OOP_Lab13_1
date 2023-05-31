#include "ProxyParcel.h"



bool ProxyParcel::check_info()
{
    //cout << this->obem;
    //_getch();
    if (this->Parce->danger == 1 && this->Parce->obem > 50)
    {
        cout << "\n\nНесоответствие типа посылки и занимаемого объема.\nНажмите любую клавишу для повторного ввода информации о посылке!\n";
        _getch();
        return false;
    }
    else
    {
        if (this->Parce->obem > 200)       //объем посылки больше, чем объем контейнера
        {

            cout << "\n\nОбъем посылки превышает возможные габариты.\nНажмите любую клавишу для повторного ввода информации о посылке!\n";
            _getch();
            return false;
        }
        else
        {

            return true;
        }
    }

}

bool ProxyParcel::send_parcel()
{
    {
        int num = 10 + rand() % (256 - 10 + 1);
        if (num % 2 == 0)
        {
            return true;
        }
        else
        {
            cout << "\n\nНевозможно доставить посылку в данный пункт назначения.\nНажмите любую клавишу для повторного ввода информации о посылке!\n";
            _getch();
            return false;
        }
    }
}


