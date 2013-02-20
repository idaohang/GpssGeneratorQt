//TriangularFunction.h

#ifndef TRINAGULAR_FUNCTION_H
#define TRIANGULAR_FUNCTION_H

#include "Function.h"

namespace GeneratorGPSS
{
	class TriangularFunction : public Function
	{
		protected:
			int stream;
			double min;
			double max;
			double mode;
		public:
			TriangularFunction();

			virtual void GenerateDefinition(std::ofstream &output);

			void SetParams(int stream, double min,double max, double mode);

		private:
			void SetName(const std::string &name);
	};
}

#endif
