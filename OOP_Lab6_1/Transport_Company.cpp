#include "Transport_Company.h"
Transport_Company* Transport_Company::instance = NULL;

Transport_Company* Transport_Company::Instance()
{
    if (instance == 0)
    {

        cout << "Транспортная компания ООО \"Везуха\" создана \n\n";
        instance = new Transport_Company();
    }
    else
    {
        cout << "Транспортная компания ООО \"Везуха\" уже осуществляет свою деятельность на территории РФ\n\n";
    }
    return instance;
}

void Transport_Company::start_work()
{
    std::vector<Parcel*> parcel_spisok;
    std::vector<Container*> container_spisok;
    Language* rus = new RusLanguage();  //установка языка

    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    int num_parcel = 0;     //общее количество неотправленных посылок
    int func;   //флаг для выбора пункта меню
    do
    {
        do           //главное меню
        {
            system("cls");
            cout << "\
1) Добавить несколько новых посылок\n\
2) Отправить посылки\n\
3) Просмотр информации об имеющихся посылках\n\
4) Абстрактная фабрика (Посылка + коробка)\n\
5) Прототип (Журнал, Письмо)\n\
6) Пул опасных контейнеров\n\
7) Состояние и наблюдатель\n\
ESC) Выход\n\nОбщее количество посылок на данный момент: " << parcel_spisok.size() << "\nОбщее количество контейнеров на данный момент: " << container_spisok.size() << "\n";
            func = _getch();
        } while (func < 49 || func > 55 && func != 27);

        if (func == 49)
        {
            
            int new_parcel; ///количество новых посылок
            do
            {
                system("cls");      //очистка экрана консоли
                cout << "Введите количество новых посылок: ";
                cin >> new_parcel;
            } while (new_parcel < 0);
            cin.get();

            for (int i = 0; i < new_parcel; i++)
            {
                Parcel* parce_temp = new Parcel();      //элемент списка посылка
                Parcel* Prox;
                do
                {
                    parce_temp->set_information(rus);
                    Prox = new ProxyParcel(parce_temp);
                } while (!(Prox->check_info()));        //минимальная  проверка. Опасный груз не может быть больше 50усл.ед.

                parcel_spisok.push_back(parce_temp);        //добавление посылки в список
            }
            num_parcel = num_parcel + new_parcel;       //общее количество посылок (вместе с только что добавленными)

            //отключение моста
            /*  
            Language* rus = new RusLanguage(),
                * eng = new EngLanguage();
            int lang;   //флажок для выбора языка интерфейса
            do
            {
                system("cls");
                cout << "Выберите язык интерфейса / Select the interface language\n\n1) Русский язык\n2) English Language\n\n";
                lang = _getch();
            } while (lang != 49 && lang != 50);

            Facade* facad = new Facade(rus);
            if (lang == 49) //переключение на русский язык интерфейса
            {
            }
            else if (lang == 50)    //переключение на английский язык интерфейса
            {
                facad->set_language(eng);
            }

            facad->get_new_parcel(&parcel_spisok, &num_parcel);
            delete facad;
            */

        }
        else if (func == 50)        //перемещение посылок в контейнеры
        {
            if (parcel_spisok.size() > 0)         //имеются посылки для отправления
            {
                system("cls");      //очистка экрана консоли
                //перемещение посылок в контейнеры


                Solver solv;
                solv.parcel_to_container(container_spisok, parcel_spisok, num_parcel);      //распределение посылок по контейнерам

                //удаление списка посылок
                for (int i = 0; i < parcel_spisok.size(); i++)
                {
                    parcel_spisok.clear();
                    parcel_spisok.shrink_to_fit();
                }

                //вывод контейнеров и их посылок
                for (int i = 0;i < container_spisok.size();i++)
                {
                    cout << "Контейнер №: " << i + 1 << "\n";
                    container_spisok[i]->print_information_c(1);
                    /*
                    container_spisok[i].get_cost_cont();        //подсчет стоимости перевозок посылок, содержащихся в контейнере
                    cout << "\nСтоимость посылок в контейнере: " << container_spisok[i].cost << "\n\n";
                    */
                }

                cout << "\n\n***   ***   ***   ***   ***   ***\nОбщее количество контейнеров: " << container_spisok.size();
                cout << "\n\nНажмите любую клавишу для продолжения (перемещение контейнеров в транспорт)";
                _getch();

                system("cls");      //очистка экрана консоли


                /*
                string town[5] = { "Барнаул", "Москва", "Новосибирск", "Владивосток", "Нижний Новгород" };
                cout << "\n\n\nПеремещение посылок в города...\n";

                for (int i = 0; i < 5; i++)
                {
                    for (int k = 0; k < container_spisok.size(); k++)
                    {
                        if (container_spisok[k].get_town() == town[i])
                        {
                            cout << "\n__" << town[i] << "__" << "\n";
                            cout << "Контейнер (ID): " << container_spisok[k].get_id();
                            cout << "\nПосылки:\n\n";
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
                            cout << "-->" << container_spisok[k].get_town() << "\nКонтейнер доставлен!\n";
                        }
                    }
                }


                */

                //перемещение контейнеров(посылок) в транспорт
                Composite_Cont* Compos = new Composite_Cont();
                for (int m = 0;m < container_spisok.size();m++)
                {
                    Compos->accumulation_parcel(container_spisok[m]);    //проверка распределения контейнера с дальнейшим определением в транспорт
                }

                //удаление списка контейнеров
                container_spisok.clear();
                container_spisok.shrink_to_fit();
                num_parcel = 0;

                Compos->print_info();

                cout << "\n\nНажмите любую клавишу для выхода в главное меню";
                _getch();

            }
            else        //посылок для отправления нет
            {
                system("cls");
                cout << "Нет посылок для отправления!\n\nДля продолжения нажмите любую клавишу";
                _getch();
            }
        }
        else if (func == 51)        //просмотр информации о существующих посылках
        {
            system("cls");  //очистка экрана консоли

            if (parcel_spisok.size() > 0)
            {

                //вывод информации о посылках 

                //стандартный способ
                /*
                for (int i = 0; i < parcel_spisok.size(); i++)
                {
                    parcel_spisok[i].print_information();
                }
                */

                //итератор
                cout << "Просмотр списка посылок с использованием итератора\n\n";
                typedef Agregat_My<Parcel*> MyCont_Parcel;
                MyCont_Parcel contain;

                //добавление посылок в контейнер
                for (int i = 0;i < parcel_spisok.size(); i++)
                {
                    contain.push(parcel_spisok[i]);
                }

                for (MyCont_Parcel::myIter it = contain.begin(); it != contain.end(); ++it) {
                    (*(it.next()))->print_information();
                }

                cout << "\n\nНажмите любую клавишу для вывода информации информационного эксперта";
                _getch();
                system("cls");  //очистка экрана консоли    
                //работа информационного эксперта

                Info_Expert* inf_exp = new Info_Expert(parcel_spisok);
                inf_exp->get_dimensions_count();

                cout << "Стоимость перевозки посылок для транспортной компании (внутренняя стоимость): ";
                cout << inf_exp->get_all_cost();

                cout << "\n\nСтоимость перевозки посылок для потребителя (внешняя стоимость): ";
                cout << inf_exp->get_pok_cost();
                /*
                for (int i = 0;i < parcel_spisok.size(); i++)
                {
                    cout << i + 1 << ": " << parcel_spisok[i].get_cost() << "руб\n";        //установка значений
                }
                */
                delete inf_exp;
            }
            else
            {
                cout << "Нет посылок для просмотра информации!";
            }
            cout << "\n\nДля продолжения нажмите любую клавишу\n";
            _getch();
        }
        else if (func == 52)    
        {
            system("cls");      //очистка экрана консоли
            AbstractFactory* abs_fact = new AbstractFactory();
            abs_fact->box_to_parcel(rus);
            delete abs_fact;
            /*          ////помещение посылок в коробки
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
                cout << "Нет посылок для просмотра информации!";
            }
            */
            cout << "\n\nДля продолжения нажмите любую клавишу\n";
            _getch();
        }

        else if (func == 53)        //прототип
        {
            system("cls");      //очистка экрана консоли
            string name_journal[10] = { "Юный натуралист", "Квантик", "Классный журнал", "Мурзилка", "Читайка", "Юный эрудит", "Лучик", "Понимашка", "Думай" };
            int num = (rand() % 9);
            Journal* jour_mass = new Journal[num];
            for (int i = 0;i <num ;i++)     //цикл создания
            {
                jour_mass[i].set_town("Барнаул", "Москва");
                jour_mass[i].set_name(name_journal[i]);
                cout << "\n\nЖурнал №" << (i + 1);
                jour_mass[i].print_inf();       //вывод информации о журнале
            }

            Distribution* jour_clon[10];
            for (int i = 0;i < num;i++)     //цикл клонирования
            {
                jour_clon[i] = jour_mass[i].clone();
                cout << "\n\nКлонированный журнал №" << (i + 1);
                jour_clon[i]->print_inf();       //вывод информации о журнале
            }

            cout << "\n\nНажмите любую клавишу для продолжения";
            _getch();

            string town[10] = { "Лермонтово", "Нижний Новгород", "Ольгинка", "Партенит", "Рязань", "Москва", "Барнаул", "Владивосток", "Сочи", "Тверь" };
            num = (rand() % 8);
            Letter* lett_mass = new Letter[num];
            for (int i = 0;i < num;i++)
            {
                lett_mass[i].set_town(town[i], town[i + 1]);
                lett_mass[i].set_ves(0.01);
                cout << "\n\nПисьмо №" << (i + 1);
                lett_mass[i].print_inf();
            }

            Distribution* lett_clon[10];
            for (int i = 0;i < num;i++)     //цикл клонирования
            {
                lett_clon[i] = lett_mass[i].clone();
                cout << "\n\nКлонированное письмо №" << (i + 1);
                lett_clon[i]->print_inf();       //вывод информации о журнале
            }

            cout << "\n\nНажмите любую клавишу для продолжения";
            _getch();
            delete jour_clon;
            delete jour_mass;
            delete lett_clon;
            delete lett_mass;
                //легковес  //LR7-8
            /*
            system("cls");      //очистка экрана консоли
            FlyWeight_Factory* factory = new FlyWeight_Factory();
            int nFlyWeight;
            do
            {
                cout << "Введите необходимое количество легковесов: ";
                cin >> nFlyWeight;
            } while (nFlyWeight <= 0);

            for (int i = 0;i < nFlyWeight;i++)
            {
                FlyWeight Fly = factory->get_pismo();
            }
            cout << "\n\nДля продолжения нажмите любую клавишу\n";
            _getch();
            */

                //Адаптер       //LR5-6
            /*
                system("cls");
                Buketik *buk = new Buketik();//создание объекта
                buk->set_inf();  //установка значений
                buk->printol(); //вывод информации о букетике


                Parcel* par_adap = new Adapter_Parcel(buk);
                par_adap->set_information();
                cout << "\n\nИнформация о посылке:\n";
                par_adap->print_information();
                cout << "Нажмите любую клавишу для продолжения";
                _getch();
                */
        }
        else if (func == 54)        //пул опасных контейнеров
        {
            system("cls");      //очистка экрана консоли
            PoolDangerCont* pool_cont = new PoolDangerCont();
            int num_cont;
            cout << "Введите количество создаваемых контейнеров в пуле (max: 40): ";
            cin >> num_cont;

            for (int i = 0;i < num_cont;i++)
            {
                pool_cont->pool_new_cont();     //создание опасного контейнера в пуле
            }


            cout << "\n\nТекущее количество контейнеров в пуле: " << pool_cont->get_num_cont();
            cout << "\n\nДля продолжения нажмите любую клавишу\n";
            _getch();
            //ручное добавление контейнера
            cout << "Введите количество контейнеров, которое необходимо создать и в дальнейшем поместить в пул: ";
            cin >> num_cont;

            for (int i = 0;i < num_cont;i++)
            {
                Danger_Cont* d_cont = new Danger_Cont();
                pool_cont->insert_cont(d_cont);     //помещение опасного контейнера в пул
            }


            cout << "\n\nТекущее количество контейнеров в пуле: " << pool_cont->get_num_cont();
            cout << "\n\nДля продолжения нажмите любую клавишу\n";
            _getch();

            cout << "Введите количество контейнеров, которые необходимо выдать из пула: ";
            cin >> num_cont;
            for (int i = 0;i < num_cont;i++)
            {
                pool_cont->get_pool_cont();     //выдача опасного контейнера из пула
            }
            cout << "Текущее количество контейнеров в пуле: " << pool_cont->get_num_cont();
            cout << "\n\nДля продолжения нажмите любую клавишу\n";
            _getch();
            delete pool_cont;
        }
        else if (func == 55)       //состояние и наблюдатель 
        {
            system("cls");      //очистка экрана консоли
             //создание состояний
            StateCont* state1 = new NotSendedStateCont();
            StateCont* state2 = new SendedStateCont();

            //создание большого контейнера с состояниями
            Container* myCont = new Big_Cont(state2, state1);       //объем - 300
            myCont->generate_id();

            myCont->print_information_c(0);
            myCont->save_empty();
            
            //создание посылок, которые будут помещены в контейнер
            vector<Parcel*> Parc;
            Parcel* parc_temp = new Parcel("Барнаул", "Пермь", 2, 4, 6, 56, 0);   //1 посылка, успешно помещена (48 единиц)
            Parc.push_back(parc_temp);

            Parcel* parc_temp1 = new Parcel("Москва", "Пермь", 7, 8, 5, 200, 0);   //2 посылка, не помещена, т.к. габариты большие (280 ед)
            Parc.push_back(parc_temp1);

            Parcel* parc_temp2 = new Parcel("Новосибирск", "Пермь", 6, 5, 3, 603, 0);   //3 посылка, успешно помещена (90 ед)
            Parc.push_back(parc_temp2);

            Parcel* parc_temp3 = new Parcel("Нижний Новгород", "Пермь", 3, 6, 5, 123, 0);   //4 посылка, успешно помещена (90 ед)
            Parc.push_back(parc_temp3);

            Parcel* parc_temp4 = new Parcel("Уфа", "Пермь", 4, 3, 2, 16, 0);   //5 посылка, не помещена, т.к. контейнер уже отправлен
            Parc.push_back(parc_temp4);


            for (int i = 0;i < Parc.size();i++)
            {
                cout << "Посылка №" << (i + 1) << "\n";
                Parc[i]->get_status(); // состояние ДО попытки размещения
                myCont->putParcel(Parc[i]);     //помещение посылки в контейнер
                Parc[i]->get_status(); // состояние ПОСЛЕ попытки размещения
                cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
            }

            for (int i = 0;i < Parc.size();i++)
            {
                Parc[i]->get_status(); // состояние после отправки контейнера
            }

            myCont->print_information_c(0);
            myCont->save_full();
            

            myCont->restore_empty();
            myCont->print_information_c(0);
            cout << "\n\n";
            Parcel* parc_temp5 = new Parcel("Уфа", "Пермь", 4, 3, 2, 16, 0);   //5 посылка, не помещена, т.к. контейнер уже отправлен
            Parcel* parc_temp6 = new Parcel("Уфа", "Пермь", 4, 3, 2, 16, 0);   //5 посылка, не помещена, т.к. контейнер уже отправлен
            myCont->putParcel(parc_temp5);
            myCont->putParcel(parc_temp6);

            myCont->print_information_c(0);

            cout << "\n\n";
            myCont->restore_empty();
            myCont->print_information_c(0);
            cout << "\n\n";
            myCont->restore_full();
            myCont->print_information_c(0);



            //удаление созданных объектов
            delete myCont;
            delete state1;
            delete state2;
            delete parc_temp;
            delete parc_temp1;
            delete parc_temp2;
            delete parc_temp3;
            delete parc_temp4;


            /*      //строитель
            Builder* buil = new Builder();
            Director* direc = new Director(buil);

            Container* cont_build = direc->Contruct_Cont();
            cont_build->print_wall_karkas();
            delete cont_build;
            delete buil;
            delete direc;

            /*      //Фабричный метод
            FactoryMethod* factr_meth = new FactoryMethod();
            PoolDangerCont* new_full_pool = factr_meth->new_full_pool();
            
            delete factr_meth;
            delete new_full_pool;
            */
            cout << "\n\nДля продолжения нажмите любую клавишу\n";
            _getch();
        }
    } while (func != 27);
    delete rus;
}
