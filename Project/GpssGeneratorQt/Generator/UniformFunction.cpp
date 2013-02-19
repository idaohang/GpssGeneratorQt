//UniformFunction.cpp
//Содержит определение методов класса функции равномерного распределения UniformFunction

#include "UniformFunction.h"

namespace GeneratorGPSS
{
	//конструктор
	UniformFunction::UniformFunction()
	{
		this->name="uniform";
	}

	//метод генерирует GPSS-текст для описания функции экспоненциального распределения в потоке thread
	//output - выходной поток, куда будет записан сгенерированный GPSS-текст
	//thread - номер потока заявок
	void UniformFunction::GenerateDefinition(std::ofstream &output)
	{
		output.setf(std::ios::fixed,std::ios::floatfield);
		output.precision(3);
		output<<name<<'('<<stream<<','<<min<<','<<max<<")";
	}

	//метод для задания параметров функции
	void UniformFunction::SetParams(int stream, double min,double max)
	{
		this->stream=stream;
		this->min=min;
		this->max=max;
	}
}
