//IntervalStatistics.h

#ifndef INTERVAL_STATISTICS_H
#define iNTERVAL_STATISTICS_H

#include "Statistics.h"

namespace GeneratorGPSS
{
	class IntervalStatistics : public Statistics
	{
		protected:
			bool isInput;
			bool isHistogram;

		public:
			IntervalStatistics(bool isInput,int thread, bool isHistogram=false);

			virtual void GenerateDeclaration(std::ofstream &output);

			virtual void GenerateDefinition(std::ofstream &output,const int thread);
	};
}

#endif
