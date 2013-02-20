//Node.h
#ifndef NODE_H
#define	NODE_H

#include "ObjectGPSS.h"

namespace GeneratorGPSS
{
	class Node : public ObjectGPSS
	{
		public:
			virtual void GenerateDeclaration(std::ofstream &output);

			virtual void GenerateDefinition(std::ofstream &output,const int thread)=0;
        };
}

#endif
