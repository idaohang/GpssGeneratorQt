//UniformFunction.cpp

#include "UniformFunction.h"

namespace GeneratorGPSS
{
	UniformFunction::UniformFunction()
	{
		this->name="uniform";
	}

	void UniformFunction::GenerateDefinition(std::ofstream &output)
	{
		output.setf(std::ios::fixed,std::ios::floatfield);
		output.precision(3);
		output<<name<<'('<<stream<<','<<min<<','<<max<<")";
	}

	void UniformFunction::SetParams(int stream, double min,double max)
	{
		this->stream=stream;
		this->min=min;
		this->max=max;
	}
}
