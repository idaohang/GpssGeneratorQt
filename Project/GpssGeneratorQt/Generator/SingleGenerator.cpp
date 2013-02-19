//SingleGenerator.cpp
//Содержит описание методов класса одиночного генератора заявок SingleGenerator

#include "SingleGenerator.h"

namespace GeneratorGPSS
{
	//метод генерирует определение узла генератора в начале текста модели
	//output - выходной поток, куда будет записан сгенерированный GPSS-текст
	void SingleGenerator::GenerateDeclaration(std::ofstream &output)
	{
		//генерируем определение для всех функций
		std::vector<std::pair<int, Function*> >::iterator p;
		for(p=function.begin();p!=function.end();p++)
		{
			p->second->GenerateDeclaration(output);
		}
	}

	//метод генерирует GPSS-текст для описания узла генератора в потоке thread
	//output - выходной поток, куда будет записан сгенерированный GPSS-текст
	//thread - номер потока заявок
	void SingleGenerator::GenerateDefinition(std::ofstream &output,const int thread)
	{
		//поиск функции для данного потока
		std::vector<std::pair<int, Function*> >::iterator p;
		for(p=function.begin();p!=function.end();p++)
		{
			if(p->first==thread)
			{
				output<<"\t\t\tGENERATE \t(";
				p->second->GenerateDefinition(output);
				output<<")\n";

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

	//добавление функции для потока thread
	void SingleGenerator::AddFunction(int thread, Function* f)
	{
		//удаляем функцию из данного потока, если она уже была добавлена
		DeleteFunction(thread);

		function.push_back(std::make_pair(thread, f));
	}

	//удаление функции для потока thread
	void SingleGenerator::DeleteFunction(int thread)
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
}
