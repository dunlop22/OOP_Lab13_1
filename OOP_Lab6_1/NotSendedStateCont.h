#pragma once
#include "StateCont.h"
class NotSendedStateCont :
    public StateCont
{
public:
    void putParcel(Parcel* parcel)
    {
        //������� �����: ����� �����-�� ������� � �����-�� ���������
        if (myContainer->check_free_obem(parcel->get_obem()))
        {
            cout << "������ ������� ����� �������� � ���������:\n";
            parcel->print_information();
            myContainer->get_parcel(parcel);
            cout << "\n";
        }
        else
        {
            cout << "\n������ ������� �� ����� ���� �������� � ���������, �.�. ��� ������ ������� �������������� ���������� �����.\n";
            parcel->print_information();
            cout << "\n";
        }
    }
};

