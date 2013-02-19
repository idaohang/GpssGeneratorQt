//Terminator.h
//Содержит объявление класса приемника Terminator

#ifndef TERMINATOR_H
#define TERMINATOR_H

#include "Node.h"
#include "Statistics.h"
#include <vector>

namespace GeneratorGPSS
{
	class Terminator : public Node
	{
		protected:
			//статистики для узла
			std::vector<Statistics* > stats;

                        std::vector<std::pair<int, Node*> > nextNode;
		public:
			//метод генерирует GPSS-текст для описания приемника в потоке thread 
			//output - выходной поток, куда будет записан сгенерированный GPSS-текст
			//thread - номер потока заявок
                        virtual void GenerateDefinition(std::ofstream &output,const int thread);

			//метод для добавления к генератору стандартных статистик
			//thread - поток, ля которого будут рассчитываться характеристики
			//при вызове без параметров - добавляется общая системная статистика 
			void GenerateStandartStatistics(int thread=-1);

                        void AddNode(int thread, Node* node);

                        void DeleteNode(int thread);

			//деструктор
			~Terminator();
	};
}

#endif
