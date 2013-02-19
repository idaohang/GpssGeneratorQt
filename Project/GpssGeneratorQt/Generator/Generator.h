//Generator.h
//Содержит объявление абстрактного класса генератора заявок Generator
#ifndef GENERATOR_H
#define	GENERATOR_H

#include "Node.h"
#include "Statistics.h"
#include <vector>
#include <utility>

namespace GeneratorGPSS
{
	class Generator : public Node
	{
		protected:
			//массив, содержащий узел, в который можно попасть из данного, для различных потоков
			std::vector<std::pair<int, Node*> > nextNode;

			//статистики для узла
			std::vector<Statistics* > stats;
		public:
			//добавление узла для потока thread
			void AddNode(int thread, Node* node);

			//удаление узла для потока thread
			void DeleteNode(int thread);

			//метод для добавления к генератору стандартных статистик
			//thread - поток, ля которого будут рассчитываться характеристики
			//при вызове без параметров - добавляется общая системная статистика 
			void GenerateStandartStatistics(int thread=-1);

			//деструктор
			virtual ~Generator();
	};
}

#endif
