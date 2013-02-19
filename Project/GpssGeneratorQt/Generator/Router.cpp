//Router.cpp
//Содержит определение методов класса маршрутного узла Router

#include "Router.h"

namespace GeneratorGPSS
{
	//метод генерирует GPSS-текст для описания маршрутного узла в потоке thread 
	//output - выходной поток, куда будет записан сгенерированный GPSS-текст
	//thread - номер потока заявок
	void Router::GenerateDefinition(std::ofstream &output,const int thread)
	{
		//поиск нужного потока
		std::vector<std::pair<int, std::vector<std::pair<Node*,double> > > >::iterator p;
		for(p=nextNodes.begin();p!=nextNodes.end();p++)
		{
			//нужный поток найден
			if(p->first==thread)
			{
				//выводим метку
				output<<"L_"<<name<<"_"<<thread;

				//выводим GPSS-текст для самого маршрутного узла
				output.setf(std::ios::fixed, std::ios::floatfield);
				output.precision(3);

				double lastProb=1.0, curProb;
				std::vector<std::pair<Node*,double> >::iterator n;
				for(n=p->second.begin();n!=p->second.end();n++)
				{
					if(lastProb<0.000001)
						break;

					curProb=n->second/lastProb;
					if(curProb>1.0)
						curProb=1.0;

					output<<"\t\t\tTRANSFER \t"<<curProb<<",,L_"<<n->first->GetName()<<"_"<<thread<<std::endl;
					lastProb-=n->second;
				}

				break;
			}
		}
	}

	//добавление узла для потока thread
	//prob - вероятность перехода в узел node из данного маршрутного узла
	//данного узла не должно быть в потоке, куда он добавляется
	void Router::AddNode(int thread, Node* node, double prob)
	{
		//поиск нужного потока
		std::vector<std::pair<int, std::vector<std::pair<Node*,double> > > >::iterator p;
		for(p=nextNodes.begin();p!=nextNodes.end();p++)
		{
			//нужный поток найден
			if(p->first==thread)
			{
				p->second.push_back(std::make_pair(node, prob));

				break;
			}
		}

		//если в данном потоке еще нет ниодного узла, то создаем
		if(p==nextNodes.end())
		{
			nextNodes.push_back(std::make_pair(thread,std::vector<std::pair<Node*,double> >()));
			nextNodes.back().second.push_back(std::make_pair(node, prob));
		}
	}

	//удаление всех узлов для потока thread
	void Router::ClearNodes(int thread)
	{
		//поиск нужного потока
		std::vector<std::pair<int, std::vector<std::pair<Node*,double> > > >::iterator p;
		for(p=nextNodes.begin();p!=nextNodes.end();p++)
		{
			//нужный поток найден
			if(p->first==thread)
			{
				nextNodes.erase(p);
				break;
			}
		}
	}
}
