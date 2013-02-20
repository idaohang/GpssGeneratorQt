//GaussianFunction.cpp

#include "GaussianFunction.h"

namespace GeneratorGPSS
{
	GaussianFunction::GaussianFunction()
	{
		this->name="normal";
	}

	void GaussianFunction::GenerateDefinition(std::ofstream &output)
	{
		output.setf(std::ios::fixed,std::ios::floatfield);
		output.precision(3);
		output<<name<<'('<<stream<<','<<mean<<','<<stdDev<<")";
	}

	void GaussianFunction::SetParams(int stream, double mean,double stdDev)
	{
		this->stream=stream;
		this->mean=mean;
		this->stdDev=stdDev;
	}
}
