//IntervalStatistics.cpp

#include "IntervalStatistic.h"

namespace GeneratorGPSS
{
	IntervalStatistics::IntervalStatistics(bool isInput,int thread, bool isHistogram)
	{
		this->isInput=isInput;
		this->thread=thread;
		this->isHistogram=isHistogram;
	}

	void IntervalStatistics::GenerateDeclaration(std::ofstream &output)
	{
		if(isHistogram)
		{
			output<<"TQ"<<name<<"\tTABLE\tQ"<<name<<",0,10,10\n";
		}
	}

	void IntervalStatistics::GenerateDefinition(std::ofstream &output,const int thread)
	{
		if(thread==this->thread || this->thread==-1)
		{
			if(isInput)
			{
                                output<<"\t\t\tqueue\t\t"<<name<<std::endl;
			}
			else
			{
                                output<<"\t\t\tdepart\t\t"<<name<<std::endl;
			}

			if(nextNode!=0)
			{
				output<<"\t\t\tTRANSFER \t"<<"1.0,,L_"<<nextNode->GetName()<<"_"<<thread<<std::endl;
			}
		}
	}
}
