#include "Parcel.h"

Parcel::Parcel()
{
}

Parcel::Parcel(string town_sender, string town_recipient, double shirina, double visota, double dlina, double weight, int danger)
{
	this->generate_id();	//���������� ����������� ������
	this->town_sender = town_sender;
	this->town_recipient = town_recipient;
	this->shirina = shirina;
	this->visota = visota;
	this->dlina = dlina;
	this->obem = this->dlina * this->visota * this->shirina;	//������� ������
	this->weight = weight;
	this->danger = danger;

	status = 0;
}

void Parcel::set_parcel(Parcel* parc)
{
}

bool Parcel::check_info()
{
	return false;
}

bool Parcel::send_parcel()
{
	return false;
}

int Parcel::get_id()
{
	return (this->id);
}
//����� ���������� � �������
void Parcel::print_information()
{
	cout << this->id << " : " << this->town_sender << "-->" << this->town_recipient;
	if (this->danger == 1)
	{
		cout << " (!_DANGER_!)";
	}
	else
	{
		cout << "             ";
	}
	cout << " (" << this->shirina << "x" << this->dlina << "x" << this->visota << ") " << this->weight << "��. " << this->obem << " (�^3)\n";
}

//��������� ���������� ������ ��� ������� (����������� �������� ������������)
void Parcel::generate_id()
{
	//��������� ���������� 8-�� �������� ������ id
	this->id = 10000000 + rand() % 90000000;
	//�������� ���������������� ������� ������ (���???)
}

//��������� ������ ����������
string Parcel::get_town()
{
	return (this->town_recipient);
}



void Parcel::set_information(Language* lang)
{
	//��������� ��������������� 8-�������� ������ ������� (ID)
	generate_id();

	do
	{
		system("cls");
		lang->print_info();
			cout << this->id;		//����� ����������� ������ �������
		lang->print_town_1();
		getline(cin, this->town_sender);
	} while (this->town_sender == "");

	vector<string> town = { "�������", "������", "�����������", "�����������", "������ ��������" };
	int num_town;
	do
	{
		lang->print_spisok_town();
		lang->print_town_2();
		num_town = _getch();
	} while (num_town < 49 || num_town >(town.size() + 48));
	this->town_recipient = town[num_town - 49];
	cout << "(" << this->town_recipient << ")";
	
	lang->print_gabarit_1();
	cin >> this->shirina;
	//this->shirina = 8 + rand() % (54 - 8 + 1);		//��������� ���������� �������� ������ (��� �����)
	
	lang->print_gabarit_2();
	cin >> this->visota;
	//this->visota = 8 + rand() % (54 - 8 + 1);		//��������� ���������� �������� ������ (��� �����)
	
	lang->print_gabarit_3();
	cin >> this->dlina;
	//this->dlina = 8 + rand() % (54 - 8 + 1);		//��������� ���������� �������� ������ (��� �����)
	
	lang->print_size();
	this->obem = this->dlina * this->visota * this->shirina;
	cout << this->obem;
	//this->obem = 8 + rand() % (54 - 8 + 1);		//��������� ���������� �������� ������ (��� �����)
	
	lang->print_weight();
	cin >> this->weight;
	//this->weight = 8 + rand() % (54 - 8 + 1);		//��������� ���������� �������� ������ (��� �����)
	do
	{
		lang->print_danger();
		this->danger = _getch();
	} while (this->danger != 49 && this->danger != 50);
	this->danger = this->danger - 48;


	if (this->danger == 1)
	{
		lang->print_yes();
	}
	else
	{
		lang->print_no();
	}
	lang->any_key_to_cont();
	cin.ignore();
	_getch();
}

double Parcel::get_obem()
{
	return this->obem;
}

vector <double> Parcel::get_dimensions()
{
	vector <double> dimensions;
	dimensions.push_back(this->dlina);
	dimensions.push_back(this->shirina);
	dimensions.push_back(this->visota);
	dimensions.push_back(this->danger);
	dimensions.push_back(this->weight);
	
	return dimensions;
}

void Parcel::update(int state)
{
	status = state;
}

int Parcel::get_status()
{
	//0 - ������� � ����������������� ������ ��� ���-�� �����
	//1 - ������� �������� � ���������
	//2 - ������� � ����
	//this->print_information();
	//cout << "������� �����-��, ������: ";
	cout << "������� (ID): " << this->get_id() << "\n������: ";
	
	if (status == 0)
	{
		cout << "��������� � ����������������� ������ ������ �����������\n\n";
	}
	else if (status == 1)
	{
		cout << "�������� � ���������\n\n";
	}
	else
	{
		cout << "� ����.\n\n";
	}

	return status;
}

Parcel* Parcel::clone()
{
	Parcel* parc_clone = new Parcel(*this);

	//cout << "������������ ������...\n" << this << " --clone--> " << lett_clone << endl;

	return parc_clone;
}
