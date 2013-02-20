//ExponentialFunction.h

#ifndef EXPONENTIAL_FUNCTION_H
#define EXPONENTIAL_FUNCTION_H

#include "Function.h"

namespace GeneratorGPSS
{
	class ExponentialFunction : public Function
	{
		protected:
			int stream;
			double locate;
			double scale;
		public:
			ExponentialFunction();

			//output - stream to write GPSS code
			virtual void GenerateDefinition(std::ofstream &output);

			//stream - seek for random
			void SetParams(int stream, double locate,double scale);

		private:
			//name for exponential function must be 'exponential'
			void SetName(const std::string &name);
	};
}

#endif
