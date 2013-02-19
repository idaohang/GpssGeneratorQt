//ExponentialFunction.h
//Содержит объявление класса функции экспоненциального распределения ExponentialFunction

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
			//конструктор
			ExponentialFunction();

			//метод генерирует GPSS-текст для описания функции экспоненциального распределения в потоке thread
			//output - выходной поток, куда будет записан сгенерированный GPSS-текст
			//thread - номер потока заявок
			virtual void GenerateDefinition(std::ofstream &output);

			//метод для задания параметров функции
			void SetParams(int stream, double locate,double scale);

		private:
			//метод для установки имени функции
			void SetName(const std::string &name);
	};
}

#endif
