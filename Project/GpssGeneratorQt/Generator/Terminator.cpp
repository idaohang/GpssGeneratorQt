//Terminator.cpp
//Содержит определение методов класса приемника Terminator

#include "Terminator.h"
#include "IntervalStatistic.h"
#include <cstring>

namespace GeneratorGPSS
{
	//метод генерирует GPSS-текст для описания приемника в потоке thread 
	//output - выходной поток, куда будет записан сгенерированный GPSS-текст
	//thread - номер потока заявок
	void Terminator::GenerateDefinition(std::ofstream &output,const int thread)
	{
		//выводим метку для данного узла
		output<<"L_"<<name<<"_"<<thread;

		//выводим статистики
		for(std::vector<Statistics*>::iterator s=stats.begin();s!=stats.end();s++)
		{
			(*s)->GenerateDefinition(output,thread);
		}

                //ищем переход на следующий узел
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
                    //выводим GPSS-текст для самого приемника
                    output<<"\t\t\tTERMINATE \t1\n";
                }
	}

	//метод для добавления к генератору стандартных статистик
	//thread - поток, ля которого будут рассчитываться характеристики
	//при вызове без параметров - добавляется общая системная статистика 
	void Terminator::GenerateStandartStatistics(int thread)
	{
		Statistics *s;
		s=new IntervalStatistics(false,thread);
		if(thread==-1)
                        s->SetName("net");
		else
		{
			char buf[9];
                        sprintf(buf,"%d",thread);
                        s->SetName(std::string("net_")+buf);
		}

		s->SetNode(0);
		stats.push_back(s);
	}

        //добавление узла для потока thread
        void Terminator::AddNode(int thread, Node* node)
        {
            //удаляем узел из данного потока, если он имеется
            DeleteNode(thread);

            nextNode.push_back(std::make_pair(thread,node));
        }

        void Terminator::DeleteNode(int thread)
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

	//деструктор
	Terminator::~Terminator()
	{
		std::vector<Statistics*>::iterator p;
		for(p=stats.begin();p!=stats.end();p++)
		{
			delete (*p);
		}
	}
}
