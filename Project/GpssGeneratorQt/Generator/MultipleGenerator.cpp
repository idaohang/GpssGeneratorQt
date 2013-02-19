#include "MultipleGenerator.h"

namespace GeneratorGPSS
{
//метод генерирует определение узла генератора в начале текста модели
//output - выходной поток, куда будет записан сгенерированный GPSS-текст
void MultipleGenerator::GenerateDeclaration(std::ofstream &output)
{
}

//метод генерирует GPSS-текст для описания узла генератора в потоке thread
//output - выходной поток, куда будет записан сгенерированный GPSS-текст
//thread - номер потока заявок
void MultipleGenerator::GenerateDefinition(std::ofstream &output,const int thread)
{
    //поиск функции для данного потока
    std::vector<std::pair<int, int> >::iterator p;
    for(p=counts.begin();p!=counts.end();p++)
    {
        if(p->first==thread)
        {
            output<<"\t\t\tGENERATE \t,,,"<<p->second<<"\n";

            //выводим метку
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
                output<<"\t\t\tTERMINATE \t1\n";
            }

            break;
        }
    }

}

void MultipleGenerator::AddCount(int thread, int count)
{
    //удаляем функцию из данного потока, если она уже была добавлена
    DeleteCount(thread);

    counts.push_back(std::make_pair(thread, count));
}

void MultipleGenerator::DeleteCount(int thread)
{
    std::vector<std::pair<int, int> >::iterator p;

    for(p=counts.begin();p!=counts.end();p++)
    {
        if(p->first==thread)
        {
            counts.erase(p);
            break;
        }
    }
}
}

