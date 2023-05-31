#include "PoolDangerCont.h"


bool PoolDangerCont::pool_new_cont()
{
    if (pool_cont.size() < max_cont)    //если в пуле имеется место то добавить в него контейнер
    {
        pool_cont.push_back(new Danger_Cont());         //добавление нового контейнера в пул

        //Danger_Cont* addr = pool_cont.front();

        cout << "Адрес нового контейнера в пуле : " << pool_cont[pool_cont.size() - 1] << "\n";
        return true;
    }
    else
    {
        cout << "\nПул переполнен. Добавление контейнера невозможно";
        return false;
    }
}



void PoolDangerCont::insert_cont(Danger_Cont* cont)
{
    if (pool_cont.size() < max_cont)    //если в пуле имеется место то добавить в него контейнер
    {
        pool_cont.push_back(cont);         //добавление нового контейнера в пул
    }
    else
    {
        cout << "\nПул переполнен. Добавление контейнера невозможно";
    }
}

Danger_Cont* PoolDangerCont::get_pool_cont()
{
    if (!pool_cont.empty())
    {
        cout << "Адрес контейнера: " << pool_cont[pool_cont.size() - 1] << "\n";
        Danger_Cont* addr_cont = pool_cont.back();
        pool_cont.pop_back();
        
        return addr_cont;
    }
    else
    {
        cout << "\nПул контейнеров пуст. Выдача контейнера невозможна";
    }
}

int PoolDangerCont::get_num_cont()
{
    return pool_cont.size();
}


PoolDangerCont::~PoolDangerCont()
{
        while (!pool_cont.empty())
        {
            delete pool_cont.front();
            pool_cont.pop_back();
        }
}
