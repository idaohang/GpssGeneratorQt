//TriangularFunction.cpp
//Содержит определение методов класса функции треугольного распределения ExponentialFunction

#include "TriangularFunction.h"

namespace GeneratorGPSS
{
	//конструктор
	TriangularFunction::TriangularFunction()
	{
		this->name="triangular";
	}

	//метод генерирует GPSS-текст для описания функции треугольного распределения в потоке thread
	//output - выходной поток, куда будет записан сгенерированный GPSS-текст
	//thread - номер потока заявок
	void TriangularFunction::GenerateDefinition(std::ofstream &output)
	{
		output.setf(std::ios::fixed,std::ios::floatfield);
		output.precision(3);
		output<<name<<'('<<stream<<','<<min<<','<<max<<","<<mode<<")";
	}

	//метод для задания параметров функции
	void TriangularFunction::SetParams(int stream, double min,double max, double mode)
	{
		this->stream=stream;
		this->min=min;
		this->max=max;
		this->mode=mode;
	}
}
