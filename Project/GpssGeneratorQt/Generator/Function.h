//Function.h

#ifndef FUNCTION_H
#define FUNCTION_H

#include "ObjectGPSS.h"

namespace GeneratorGPSS
{
	class Function : public ObjectGPSS
	{
		public:			
			virtual void GenerateDeclaration(std::ofstream &output);

			virtual void GenerateDefinition(std::ofstream &output)=0;
	};
}

#endif
