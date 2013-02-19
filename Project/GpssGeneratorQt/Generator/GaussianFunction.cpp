//GaussianFunction.cpp
//Содержит определение методов класса функции нормального гауссового распределения GaussianFunction

#include "GaussianFunction.h"

namespace GeneratorGPSS
{
	//конструктор
	GaussianFunction::GaussianFunction()
	{
		this->name="normal";
	}

	//метод генерирует GPSS-текст для описания функции нормального гауссового распределения в потоке thread
	//output - выходной поток, куда будет записан сгенерированный GPSS-текст
	//thread - номер потока заявок
	void GaussianFunction::GenerateDefinition(std::ofstream &output)
	{
		output.setf(std::ios::fixed,std::ios::floatfield);
		output.precision(3);
		output<<name<<'('<<stream<<','<<mean<<','<<stdDev<<")";
	}

	//метод для задания параметров функции
	void GaussianFunction::SetParams(int stream, double mean,double stdDev)
	{
		this->stream=stream;
		this->mean=mean;
		this->stdDev=stdDev;
	}
}
