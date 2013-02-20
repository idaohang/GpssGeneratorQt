//Facility.h

#ifndef FACILITY_H
#define FACILITY_H

#include "Node.h"
#include "Function.h"
#include "Statistics.h"
#include <vector>
#include <utility>

namespace GeneratorGPSS
{
	class Facility : public Node
	{
		protected:		
			int chanelAmount;

			std::vector<std::pair<int, Node*> > nextNode;

			std::vector<std::pair<int, Function*> > function;

			std::vector<Statistics* > stats[3];
		public:
			void SetChanelAmount(int chAmount);

			void AddNode(int thread, Node* node);

			void DeleteNode(int thread);

			void AddFunction(int thread, Function* f);

			void DeleteFunction(int thread);

			virtual void GenerateDeclaration(std::ofstream &output);

			virtual void GenerateDefinition(std::ofstream &output,const int thread);

			void GenerateStandartStatistics(int thread, int mask);

			~Facility();
	};
}
#endif
