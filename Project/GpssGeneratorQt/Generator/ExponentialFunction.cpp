//ExponentialFunction.cpp
//Содержит определение методов класса функции экспоненциального распределения ExponentialFunction

#include "ExponentialFunction.h"

namespace GeneratorGPSS
{
	//конструктор
	ExponentialFunction::ExponentialFunction()
	{
		this->name="exponential";
	}

	//метод генерирует GPSS-текст для описания функции экспоненциального распределения в потоке thread
	//output - выходной поток, куда будет записан сгенерированный GPSS-текст
	//thread - номер потока заявок
	void ExponentialFunction::GenerateDefinition(std::ofstream &output)
	{
		output.setf(std::ios::fixed,std::ios::floatfield);
		output.precision(3);
		output<<name<<'('<<stream<<','<<locate<<','<<scale<<")";
	}

	//метод для задания параметров функции
	void ExponentialFunction::SetParams(int stream, double locate,double scale)
	{
		this->stream=stream;
		this->locate=locate;
		this->scale=scale;
	}
}
