//Router.h
//Содержит объявление класса маршрутного узла Router

#ifndef ROUTER_H
#define ROUTER_H

#include <vector>
#include <utility>
#include "Node.h"

namespace GeneratorGPSS
{
	class Router : public Node
	{
		protected:
			//массив, содержащий список узлов, в которые можно попасть из данного маршрутного узла, для различных потоков
			//для каждого потока имеется массив пар <узел, вероятность перехода>
			//для каждого потока сумма вероятностей перехода должна быть равна 1.0
			std::vector<std::pair<int, std::vector<std::pair<Node*,double> > > > nextNodes;

		public:
			//метод генерирует GPSS-текст для описания маршрутного узла в потоке thread 
			//output - выходной поток, куда будет записан сгенерированный GPSS-текст
			//thread - номер потока заявок
			virtual void GenerateDefinition(std::ofstream &output,const int thread);

			//добавление узла для потока thread
			//prob - вероятность перехода в узел node из данного маршрутного узла
			void AddNode(int thread, Node* node, double prob);

			//удаление всех узлов для потока thread
			void ClearNodes(int thread);
	};
}

#endif
