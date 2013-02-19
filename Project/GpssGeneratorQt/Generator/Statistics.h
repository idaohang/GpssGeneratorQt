//Statistics.h
//Содержит объявление абстрактного класса узлов для сбора статистики Statistics

#ifndef STATISTICS_H
#define STATISTICS_H

#include "Node.h"

namespace GeneratorGPSS
{
	class Statistics : public Node
	{
		protected:
			//указатель на следующий за данным узел
			Node* nextNode;

			//номер потока, в котором рассчитываются характеристики
			int thread;
		public:
			//установить следующий узел
			void SetNode(Node* node);
	};
}

#endif
