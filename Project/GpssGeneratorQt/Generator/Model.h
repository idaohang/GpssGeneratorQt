//Model.h
#ifndef MODEL_H
#define MODEL_H

#include <vector>
#include <fstream>
#include "Node.h"

namespace GeneratorGPSS
{
	class Model
	{
		protected:
			std::vector<Node *> nodes;

			std::vector<int> threads;
		public:
			Model();

			void GenerateTextGPSS(std::ofstream &output);

			void AddNode(Node *node);

			void AddThread(int thread);

			virtual ~Model();
	};
}

#endif
