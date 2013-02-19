//Generator.cpp
//Содержит определение методов абстрактного класса генератора заявок Generator

#include "Generator.h"
#include "IntervalStatistic.h"

namespace GeneratorGPSS
{
//добавление узла для потока thread
void Generator::AddNode(int thread, Node* node)
{
    //удаляем узел из данного потока, если он имеется
    DeleteNode(thread);

    nextNode.push_back(std::make_pair(thread,node));
}

//удаление узла для потока thread
void Generator::DeleteNode(int thread)
{
    std::vector<std::pair<int, Node * > >::iterator p;
    for(p=nextNode.begin();p!=nextNode.end();p++)
    {
        if(p->first==thread)
        {
            nextNode.erase(p);
            break;
        }
    }
}

//метод для добавления к генератору стандартных статистик
//thread - поток, ля которого будут рассчитываться характеристики
//при вызове без параметров - добавляется общая системная статистика
void Generator::GenerateStandartStatistics(int thread)
{
    Statistics *s;
    s=new IntervalStatistics(true,thread);
    if(thread==-1)
        s->SetName("net");
    else
    {
        char buf[9];
        sprintf(buf,"%d",thread);
        //itoa(thread,buf,8);
        s->SetName(std::string("net_")+buf);
    }
    s->SetNode(0);
    stats.push_back(s);
}

//деструктор
Generator::~Generator()
{
    std::vector<Statistics*>::iterator p;
    for(p=stats.begin();p!=stats.end();p++)
    {
        delete (*p);
    }
}
}
