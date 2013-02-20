//Statistics.h

#ifndef STATISTICS_H
#define STATISTICS_H

#include "Node.h"

namespace GeneratorGPSS
{
	class Statistics : public Node
	{
		protected:
			Node* nextNode;

			int thread;
		public:
			void SetNode(Node* node);
	};
}

#endif
