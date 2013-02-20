//Router.h

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
			std::vector<std::pair<int, std::vector<std::pair<Node*,double> > > > nextNodes;

		public:
			virtual void GenerateDefinition(std::ofstream &output,const int thread);

			void AddNode(int thread, Node* node, double prob);

			void ClearNodes(int thread);
	};
}

#endif
