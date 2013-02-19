//Facility.h
//Содержит определение методов класса устройства Facility

#include "Facility.h"
#include "IntervalStatistic.h"

namespace GeneratorGPSS
{
//установка количества каналов устройства
void Facility::SetChanelAmount(int chAmount)
{
    this->chanelAmount=chAmount;
}

//добавление узла для потока thread
void Facility::AddNode(int thread, Node* node)
{
    //удаляем узел из данного потока, если он имеется
    DeleteNode(thread);

    nextNode.push_back(std::make_pair(thread,node));
}

//удаление узла для потока thread
void Facility::DeleteNode(int thread)
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

//добавление функции для потока thread
void Facility::AddFunction(int thread, Function* f)
{
    //удаляем функцию из данного потока, если она уже была добавлена
    DeleteFunction(thread);

    function.push_back(std::make_pair(thread, f));
}

//удаление функции для потока thread
void Facility::DeleteFunction(int thread)
{
    std::vector<std::pair<int, Function*> >::iterator p;

    for(p=function.begin();p!=function.end();p++)
    {
        if(p->first==thread)
        {
            function.erase(p);
            break;
        }
    }
}

//метод генерирует определение узла генератора в начале текста модели
//output - выходной поток, куда будет записан сгенерированный GPSS-текст
void Facility::GenerateDeclaration(std::ofstream &output)
{
    if(chanelAmount>1)
    {
        output<<name<<"\t\t\tSTORAGE \t"<<chanelAmount<<std::endl;
    }

    //генерация описаний для статистик и функций
    for(int i=0;i<3;i++)
    {
        for(std::vector<Statistics*>::iterator p=stats[i].begin();p!=stats[i].end();p++)
        {
            (*p)->GenerateDeclaration(output);
        }
    }

    std::vector<std::pair<int,Function * > >::iterator f;
    for(f=function.begin();f!=function.end();f++)
    {
        f->second->GenerateDeclaration(output);
    }
}

//метод генерирует GPSS-текст для описания узла генератора в потоке thread
//output - выходной поток, куда будет записан сгенерированный GPSS-текст
//thread - номер потока заявок
void Facility::GenerateDefinition(std::ofstream &output,const int thread)
{
    std::vector<std::pair<int, Function*> >::iterator p;
    for(p=function.begin();p!=function.end();p++)
    {
        if(p->first==thread)
        {
            //выводим метку
            output<<"L_"<<name<<"_"<<thread;

            //выводим статистики до очереди
            for(std::vector<Statistics*>::iterator s=stats[0].begin();s!=stats[0].end();s++)
            {
                (*s)->GenerateDefinition(output,thread);
            }

            //захват канала
            if(chanelAmount>1)
            {
                output<<"\t\t\tENTER \t\t"<<name<<std::endl;
            }
            else
            {
                output<<"\t\t\tSEIZE \t\t"<<name<<std::endl;
            }

            //выводим статистики после очереди
            for(std::vector<Statistics*>::iterator s=stats[1].begin();s!=stats[1].end();s++)
            {
                (*s)->GenerateDefinition(output,thread);
            }

            //обработка в канале
            output<<"\t\t\tADVANCE \t(";
            p->second->GenerateDefinition(output);
            output<<")\n";

            //освобождение канала
            if(chanelAmount>1)
            {
                output<<"\t\t\tLEAVE \t\t"<<name<<std::endl;
            }
            else
            {
                output<<"\t\t\tRELEASE \t"<<name<<std::endl;
            }

            //выводим статистики после обработки
            for(std::vector<Statistics*>::iterator s=stats[2].begin();s!=stats[2].end();s++)
            {
                (*s)->GenerateDefinition(output,thread);
            }

            //ищем следующий узел для данного потока
            std::vector<std::pair<int, Node*> >::iterator next;
            for(next=nextNode.begin();next!=nextNode.end();next++)
            {
                if(next->first==thread)
                {
                    output<<"\t\t\tTRANSFER \t"<<"1.0,,L_"<<next->second->GetName()<<"_"<<thread<<std::endl;
                    break;
                }
            }
            //если переход не найден посылаем заявку на приемник
            if(next==nextNode.end())
            {
                output<<"\t\t\tTERMINATE \t1\n";
            }

            break;
        }
    }
}

//метод для добавления к узлу стандартных статистик
//thread - поток, ля которого будут рассчитываться характеристики
//mask - определяет, в каких позициях будут установлены очереди для статистики
//mask=1 - от начала очереди до захвата канала, 2 - от начала очереди до конца обработки, 3 - обе
void Facility::GenerateStandartStatistics(int thread, int mask)
{
    Statistics *s;

    char buf[9];
    //itoa(thread,buf,8);
    sprintf(buf,"%d",thread);

    if(mask&1)
    {
        s=new IntervalStatistics(true,thread);
        if(thread!=-1)
            s->SetName("w_"+name + "_" + buf);
        else
            s->SetName("w_"+name);
        s->SetNode(0);
        stats[0].push_back(s);

        s=new IntervalStatistics(false,thread);
        if(thread!=-1)
            s->SetName("w_"+name + "_" + buf);
        else
            s->SetName("w_"+name);
        s->SetNode(0);
        stats[1].push_back(s);
    }

    if(mask&2)
    {
        s=new IntervalStatistics(true,thread);
        if(thread!=-1)
            s->SetName(name + "_" + buf);
        else
            s->SetName(name);
        s->SetNode(0);
        stats[0].push_back(s);

        s=new IntervalStatistics(false,thread);
        if(thread!=-1)
            s->SetName(name + "_" + buf);
        else
            s->SetName(name);
        s->SetNode(0);
        stats[2].push_back(s);
    }
}

//деструктор
Facility::~Facility()
{
    std::vector<Statistics*>::iterator p;
    for(int i=0;i<3;i++)
    {
        for(p=stats[i].begin();p!=stats[i].end();p++)
        {
            delete (*p);
        }
    }
}
}
