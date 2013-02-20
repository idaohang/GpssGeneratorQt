//Generator.h
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
			std::vector<std::pair<int, Node*> > nextNode;

			std::vector<Statistics* > stats;
		public:
			void AddNode(int thread, Node* node);

			void DeleteNode(int thread);

			void GenerateStandartStatistics(int thread=-1);

			virtual ~Generator();
	};
}

#endif
