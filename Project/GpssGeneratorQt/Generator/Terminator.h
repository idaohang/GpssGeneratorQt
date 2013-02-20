//Terminator.h

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
			std::vector<Statistics* > stats;

                        std::vector<std::pair<int, Node*> > nextNode;
		public:
                        virtual void GenerateDefinition(std::ofstream &output,const int thread);

			void GenerateStandartStatistics(int thread=-1);

                        void AddNode(int thread, Node* node);

                        void DeleteNode(int thread);

			~Terminator();
	};
}

#endif
