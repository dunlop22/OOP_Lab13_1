#include "NotSendedStateCont.h"

void NotSendedStateCont::putParcel(Parcel* parcel)
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

string NotSendedStateCont::getStatus()
{
    return "�� ���������";
}
