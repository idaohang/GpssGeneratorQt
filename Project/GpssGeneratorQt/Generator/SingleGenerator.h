//SingleGenerator.h

#ifndef SINGLE_GENERATOR_H
#define	SINGLE_GENERATOR_H

#include "Generator.h"
#include "Function.h"

namespace GeneratorGPSS
{
	class SingleGenerator : public Generator
	{
		protected:
			std::vector<std::pair<int, Function*> > function;

		public:
			virtual void GenerateDeclaration(std::ofstream &output);

			virtual void GenerateDefinition(std::ofstream &output,const int thread);

			void AddFunction(int thread, Function* f);

			void DeleteFunction(int thread);
	};
}

#endif
