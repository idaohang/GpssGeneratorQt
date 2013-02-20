//TriangularFunction.cpp

#include "TriangularFunction.h"

namespace GeneratorGPSS
{
	TriangularFunction::TriangularFunction()
	{
		this->name="triangular";
	}

	void TriangularFunction::GenerateDefinition(std::ofstream &output)
	{
		output.setf(std::ios::fixed,std::ios::floatfield);
		output.precision(3);
		output<<name<<'('<<stream<<','<<min<<','<<max<<","<<mode<<")";
	}

	void TriangularFunction::SetParams(int stream, double min,double max, double mode)
	{
		this->stream=stream;
		this->min=min;
		this->max=max;
		this->mode=mode;
	}
}
