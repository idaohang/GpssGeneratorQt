//ObjectGPSS.h
#ifndef OBJECT_GPSS_H
#define OBJECT_GPSS_H

#include <string>
#include <fstream>

namespace GeneratorGPSS
{
	class ObjectGPSS
	{
		protected:
			std::string name;

		public:
			ObjectGPSS();

			virtual ~ObjectGPSS();

			virtual void GenerateDeclaration(std::ofstream &output)=0;

			std::string GetName();

			void SetName(const std::string &name);
	};
}

#endif
