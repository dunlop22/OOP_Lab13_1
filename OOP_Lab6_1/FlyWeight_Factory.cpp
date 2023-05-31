#include "FlyWeight_Factory.h"
FlyWeight_Factory::FlyWeight_Factory()
{
    srand(time(NULL));
}
int FlyWeight_Factory::random_num(int max)
{
    
    
    int num = rand() % (max + 1);

    return num;
}

FlyWeight& FlyWeight_Factory::get_pismo()
{
    //генераци€ города получени€ случайным образом
    string temp = town_send[random_num(town_send.size() - 1)];  
    for (int i = 0;i < FlyWeights.size();i++)
    {
        if (FlyWeights[i].get_info() == temp)
        {
            //легковес существует
            cout << "Ёлемент найден с конечным пунктом " << temp << " найден\n";
            return (FlyWeights[i]);
            
        }
    }
    FlyWeight* f = new FlyWeight();
    f->set_info(temp);      //создание нового легковеса
    cout << "—оздан новый элемент с конечным городом: " << temp << "\n";
    FlyWeights.push_back(*f);
    return *f;
}
