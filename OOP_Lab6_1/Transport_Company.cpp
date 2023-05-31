#include "Transport_Company.h"
Transport_Company* Transport_Company::instance = NULL;

Transport_Company* Transport_Company::Instance()
{
    if (instance == 0)
    {

        cout << "������������ �������� ��� \"������\" ������� \n\n";
        instance = new Transport_Company();
    }
    else
    {
        cout << "������������ �������� ��� \"������\" ��� ������������ ���� ������������ �� ���������� ��\n\n";
    }
    return instance;
}

void Transport_Company::start_work()
{
    std::vector<Parcel*> parcel_spisok;
    std::vector<Container*> container_spisok;
    Language* rus = new RusLanguage();  //��������� �����

    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    int num_parcel = 0;     //����� ���������� �������������� �������
    int func;   //���� ��� ������ ������ ����
    do
    {
        do           //������� ����
        {
            system("cls");
            cout << "\
1) �������� ��������� ����� �������\n\
2) ��������� �������\n\
3) �������� ���������� �� ��������� ��������\n\
4) ����������� ������� (������� + �������)\n\
5) �������� (������, ������)\n\
6) ��� ������� �����������\n\
7) ��������� � �����������\n\
ESC) �����\n\n����� ���������� ������� �� ������ ������: " << parcel_spisok.size() << "\n����� ���������� ����������� �� ������ ������: " << container_spisok.size() << "\n";
            func = _getch();
        } while (func < 49 || func > 55 && func != 27);

        if (func == 49)
        {
            
            int new_parcel; ///���������� ����� �������
            do
            {
                system("cls");      //������� ������ �������
                cout << "������� ���������� ����� �������: ";
                cin >> new_parcel;
            } while (new_parcel < 0);
            cin.get();

            for (int i = 0; i < new_parcel; i++)
            {
                Parcel* parce_temp = new Parcel();      //������� ������ �������
                Parcel* Prox;
                do
                {
                    parce_temp->set_information(rus);
                    Prox = new ProxyParcel(parce_temp);
                } while (!(Prox->check_info()));        //�����������  ��������. ������� ���� �� ����� ���� ������ 50���.��.

                parcel_spisok.push_back(parce_temp);        //���������� ������� � ������
            }
            num_parcel = num_parcel + new_parcel;       //����� ���������� ������� (������ � ������ ��� ������������)

            //���������� �����
            /*  
            Language* rus = new RusLanguage(),
                * eng = new EngLanguage();
            int lang;   //������ ��� ������ ����� ����������
            do
            {
                system("cls");
                cout << "�������� ���� ���������� / Select the interface language\n\n1) ������� ����\n2) English Language\n\n";
                lang = _getch();
            } while (lang != 49 && lang != 50);

            Facade* facad = new Facade(rus);
            if (lang == 49) //������������ �� ������� ���� ����������
            {
            }
            else if (lang == 50)    //������������ �� ���������� ���� ����������
            {
                facad->set_language(eng);
            }

            facad->get_new_parcel(&parcel_spisok, &num_parcel);
            delete facad;
            */

        }
        else if (func == 50)        //����������� ������� � ����������
        {
            if (parcel_spisok.size() > 0)         //������� ������� ��� �����������
            {
                system("cls");      //������� ������ �������
                //����������� ������� � ����������


                Solver solv;
                solv.parcel_to_container(container_spisok, parcel_spisok, num_parcel);      //������������� ������� �� �����������

                //�������� ������ �������
                for (int i = 0; i < parcel_spisok.size(); i++)
                {
                    parcel_spisok.clear();
                    parcel_spisok.shrink_to_fit();
                }

                //����� ����������� � �� �������
                for (int i = 0;i < container_spisok.size();i++)
                {
                    cout << "��������� �: " << i + 1 << "\n";
                    container_spisok[i]->print_information_c(1);
                    /*
                    container_spisok[i].get_cost_cont();        //������� ��������� ��������� �������, ������������ � ����������
                    cout << "\n��������� ������� � ����������: " << container_spisok[i].cost << "\n\n";
                    */
                }

                cout << "\n\n***   ***   ***   ***   ***   ***\n����� ���������� �����������: " << container_spisok.size();
                cout << "\n\n������� ����� ������� ��� ����������� (����������� ����������� � ���������)";
                _getch();

                system("cls");      //������� ������ �������


                /*
                string town[5] = { "�������", "������", "�����������", "�����������", "������ ��������" };
                cout << "\n\n\n����������� ������� � ������...\n";

                for (int i = 0; i < 5; i++)
                {
                    for (int k = 0; k < container_spisok.size(); k++)
                    {
                        if (container_spisok[k].get_town() == town[i])
                        {
                            cout << "\n__" << town[i] << "__" << "\n";
                            cout << "��������� (ID): " << container_spisok[k].get_id();
                            cout << "\n�������:\n\n";
                            for (int n = 0; n < (container_spisok[k].get_inf_parcel()).size(); n++)
                            {
                                (container_spisok[k].get_inf_parcel())[n].print_information();
                                cout << "\n";
                            }
                            for (int j = 0; j < 5; j++)
                            {
                                Sleep(500);
                                cout << "....";
                            }
                            cout << "-->" << container_spisok[k].get_town() << "\n��������� ���������!\n";
                        }
                    }
                }


                */

                //����������� �����������(�������) � ���������
                Composite_Cont* Compos = new Composite_Cont();
                for (int m = 0;m < container_spisok.size();m++)
                {
                    Compos->accumulation_parcel(container_spisok[m]);    //�������� ������������� ���������� � ���������� ������������ � ���������
                }

                //�������� ������ �����������
                container_spisok.clear();
                container_spisok.shrink_to_fit();
                num_parcel = 0;

                Compos->print_info();

                cout << "\n\n������� ����� ������� ��� ������ � ������� ����";
                _getch();

            }
            else        //������� ��� ����������� ���
            {
                system("cls");
                cout << "��� ������� ��� �����������!\n\n��� ����������� ������� ����� �������";
                _getch();
            }
        }
        else if (func == 51)        //�������� ���������� � ������������ ��������
        {
            system("cls");  //������� ������ �������

            if (parcel_spisok.size() > 0)
            {

                //����� ���������� � �������� 

                //����������� ������
                /*
                for (int i = 0; i < parcel_spisok.size(); i++)
                {
                    parcel_spisok[i].print_information();
                }
                */

                //��������
                cout << "�������� ������ ������� � �������������� ���������\n\n";
                typedef Agregat_My<Parcel*> MyCont_Parcel;
                MyCont_Parcel contain;

                //���������� ������� � ���������
                for (int i = 0;i < parcel_spisok.size(); i++)
                {
                    contain.push(parcel_spisok[i]);
                }

                for (MyCont_Parcel::myIter it = contain.begin(); it != contain.end(); ++it) {
                    (*(it.next()))->print_information();
                }

                cout << "\n\n������� ����� ������� ��� ������ ���������� ��������������� ��������";
                _getch();
                system("cls");  //������� ������ �������    
                //������ ��������������� ��������

                Info_Expert* inf_exp = new Info_Expert(parcel_spisok);
                inf_exp->get_dimensions_count();

                cout << "��������� ��������� ������� ��� ������������ �������� (���������� ���������): ";
                cout << inf_exp->get_all_cost();

                cout << "\n\n��������� ��������� ������� ��� ����������� (������� ���������): ";
                cout << inf_exp->get_pok_cost();
                /*
                for (int i = 0;i < parcel_spisok.size(); i++)
                {
                    cout << i + 1 << ": " << parcel_spisok[i].get_cost() << "���\n";        //��������� ��������
                }
                */
                delete inf_exp;
            }
            else
            {
                cout << "��� ������� ��� ��������� ����������!";
            }
            cout << "\n\n��� ����������� ������� ����� �������\n";
            _getch();
        }
        else if (func == 52)    
        {
            system("cls");      //������� ������ �������
            AbstractFactory* abs_fact = new AbstractFactory();
            abs_fact->box_to_parcel(rus);
            delete abs_fact;
            /*          ////��������� ������� � �������
            if (parcel_spisok.size() > 0)
            {
                for (int i = 0;i < parcel_spisok.size(); i++)
                {
                    Decorate_Parcel dec_parc(&parcel_spisok[i]);
                    dec_parc.set_information();
                    dec_parc.print_information();
                }

            }
            else
            {
                cout << "��� ������� ��� ��������� ����������!";
            }
            */
            cout << "\n\n��� ����������� ������� ����� �������\n";
            _getch();
        }

        else if (func == 53)        //��������
        {
            system("cls");      //������� ������ �������
            string name_journal[10] = { "���� ����������", "�������", "�������� ������", "��������", "�������", "���� ������", "�����", "���������", "�����" };
            int num = (rand() % 9);
            Journal* jour_mass = new Journal[num];
            for (int i = 0;i <num ;i++)     //���� ��������
            {
                jour_mass[i].set_town("�������", "������");
                jour_mass[i].set_name(name_journal[i]);
                cout << "\n\n������ �" << (i + 1);
                jour_mass[i].print_inf();       //����� ���������� � �������
            }

            Distribution* jour_clon[10];
            for (int i = 0;i < num;i++)     //���� ������������
            {
                jour_clon[i] = jour_mass[i].clone();
                cout << "\n\n������������� ������ �" << (i + 1);
                jour_clon[i]->print_inf();       //����� ���������� � �������
            }

            cout << "\n\n������� ����� ������� ��� �����������";
            _getch();

            string town[10] = { "����������", "������ ��������", "��������", "��������", "������", "������", "�������", "�����������", "����", "�����" };
            num = (rand() % 8);
            Letter* lett_mass = new Letter[num];
            for (int i = 0;i < num;i++)
            {
                lett_mass[i].set_town(town[i], town[i + 1]);
                lett_mass[i].set_ves(0.01);
                cout << "\n\n������ �" << (i + 1);
                lett_mass[i].print_inf();
            }

            Distribution* lett_clon[10];
            for (int i = 0;i < num;i++)     //���� ������������
            {
                lett_clon[i] = lett_mass[i].clone();
                cout << "\n\n������������� ������ �" << (i + 1);
                lett_clon[i]->print_inf();       //����� ���������� � �������
            }

            cout << "\n\n������� ����� ������� ��� �����������";
            _getch();
            delete jour_clon;
            delete jour_mass;
            delete lett_clon;
            delete lett_mass;
                //��������  //LR7-8
            /*
            system("cls");      //������� ������ �������
            FlyWeight_Factory* factory = new FlyWeight_Factory();
            int nFlyWeight;
            do
            {
                cout << "������� ����������� ���������� ����������: ";
                cin >> nFlyWeight;
            } while (nFlyWeight <= 0);

            for (int i = 0;i < nFlyWeight;i++)
            {
                FlyWeight Fly = factory->get_pismo();
            }
            cout << "\n\n��� ����������� ������� ����� �������\n";
            _getch();
            */

                //�������       //LR5-6
            /*
                system("cls");
                Buketik *buk = new Buketik();//�������� �������
                buk->set_inf();  //��������� ��������
                buk->printol(); //����� ���������� � ��������


                Parcel* par_adap = new Adapter_Parcel(buk);
                par_adap->set_information();
                cout << "\n\n���������� � �������:\n";
                par_adap->print_information();
                cout << "������� ����� ������� ��� �����������";
                _getch();
                */
        }
        else if (func == 54)        //��� ������� �����������
        {
            system("cls");      //������� ������ �������
            PoolDangerCont* pool_cont = new PoolDangerCont();
            int num_cont;
            cout << "������� ���������� ����������� ����������� � ���� (max: 40): ";
            cin >> num_cont;

            for (int i = 0;i < num_cont;i++)
            {
                pool_cont->pool_new_cont();     //�������� �������� ���������� � ����
            }


            cout << "\n\n������� ���������� ����������� � ����: " << pool_cont->get_num_cont();
            cout << "\n\n��� ����������� ������� ����� �������\n";
            _getch();
            //������ ���������� ����������
            cout << "������� ���������� �����������, ������� ���������� ������� � � ���������� ��������� � ���: ";
            cin >> num_cont;

            for (int i = 0;i < num_cont;i++)
            {
                Danger_Cont* d_cont = new Danger_Cont();
                pool_cont->insert_cont(d_cont);     //��������� �������� ���������� � ���
            }


            cout << "\n\n������� ���������� ����������� � ����: " << pool_cont->get_num_cont();
            cout << "\n\n��� ����������� ������� ����� �������\n";
            _getch();

            cout << "������� ���������� �����������, ������� ���������� ������ �� ����: ";
            cin >> num_cont;
            for (int i = 0;i < num_cont;i++)
            {
                pool_cont->get_pool_cont();     //������ �������� ���������� �� ����
            }
            cout << "������� ���������� ����������� � ����: " << pool_cont->get_num_cont();
            cout << "\n\n��� ����������� ������� ����� �������\n";
            _getch();
            delete pool_cont;
        }
        else if (func == 55)       //��������� � ����������� 
        {
            system("cls");      //������� ������ �������
             //�������� ���������
            StateCont* state1 = new NotSendedStateCont();
            StateCont* state2 = new SendedStateCont();

            //�������� �������� ���������� � �����������
            Container* myCont = new Big_Cont(state2, state1);       //����� - 300
            myCont->generate_id();

            myCont->print_information_c(0);
            myCont->save_empty();
            
            //�������� �������, ������� ����� �������� � ���������
            vector<Parcel*> Parc;
            Parcel* parc_temp = new Parcel("�������", "�����", 2, 4, 6, 56, 0);   //1 �������, ������� �������� (48 ������)
            Parc.push_back(parc_temp);

            Parcel* parc_temp1 = new Parcel("������", "�����", 7, 8, 5, 200, 0);   //2 �������, �� ��������, �.�. �������� ������� (280 ��)
            Parc.push_back(parc_temp1);

            Parcel* parc_temp2 = new Parcel("�����������", "�����", 6, 5, 3, 603, 0);   //3 �������, ������� �������� (90 ��)
            Parc.push_back(parc_temp2);

            Parcel* parc_temp3 = new Parcel("������ ��������", "�����", 3, 6, 5, 123, 0);   //4 �������, ������� �������� (90 ��)
            Parc.push_back(parc_temp3);

            Parcel* parc_temp4 = new Parcel("���", "�����", 4, 3, 2, 16, 0);   //5 �������, �� ��������, �.�. ��������� ��� ���������
            Parc.push_back(parc_temp4);


            for (int i = 0;i < Parc.size();i++)
            {
                cout << "������� �" << (i + 1) << "\n";
                Parc[i]->get_status(); // ��������� �� ������� ����������
                myCont->putParcel(Parc[i]);     //��������� ������� � ���������
                Parc[i]->get_status(); // ��������� ����� ������� ����������
                cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
            }

            for (int i = 0;i < Parc.size();i++)
            {
                Parc[i]->get_status(); // ��������� ����� �������� ����������
            }

            myCont->print_information_c(0);
            myCont->save_full();
            

            myCont->restore_empty();
            myCont->print_information_c(0);
            cout << "\n\n";
            Parcel* parc_temp5 = new Parcel("���", "�����", 4, 3, 2, 16, 0);   //5 �������, �� ��������, �.�. ��������� ��� ���������
            Parcel* parc_temp6 = new Parcel("���", "�����", 4, 3, 2, 16, 0);   //5 �������, �� ��������, �.�. ��������� ��� ���������
            myCont->putParcel(parc_temp5);
            myCont->putParcel(parc_temp6);

            myCont->print_information_c(0);

            cout << "\n\n";
            myCont->restore_empty();
            myCont->print_information_c(0);
            cout << "\n\n";
            myCont->restore_full();
            myCont->print_information_c(0);



            //�������� ��������� ��������
            delete myCont;
            delete state1;
            delete state2;
            delete parc_temp;
            delete parc_temp1;
            delete parc_temp2;
            delete parc_temp3;
            delete parc_temp4;


            /*      //���������
            Builder* buil = new Builder();
            Director* direc = new Director(buil);

            Container* cont_build = direc->Contruct_Cont();
            cont_build->print_wall_karkas();
            delete cont_build;
            delete buil;
            delete direc;

            /*      //��������� �����
            FactoryMethod* factr_meth = new FactoryMethod();
            PoolDangerCont* new_full_pool = factr_meth->new_full_pool();
            
            delete factr_meth;
            delete new_full_pool;
            */
            cout << "\n\n��� ����������� ������� ����� �������\n";
            _getch();
        }
    } while (func != 27);
    delete rus;
}
