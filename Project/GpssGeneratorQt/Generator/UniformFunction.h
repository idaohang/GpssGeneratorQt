//UniformFunction.h
//Содержит объявление класса функции равномерного распределения UniformFunction

#ifndef UNIFORM_FUNCTION_H
#define UNIFORM_FUNCTION_H

#include "Function.h"

namespace GeneratorGPSS
{
	class UniformFunction : public Function
	{
		protected:
			int stream;
			double min;
			double max;
		public:
			//конструктор
			UniformFunction();

			//метод генерирует GPSS-текст для описания функции равномерного распределения в потоке thread
			//output - выходной поток, куда будет записан сгенерированный GPSS-текст
			//thread - номер потока заявок
			virtual void GenerateDefinition(std::ofstream &output);

			//метод для задания параметров функции
			void SetParams(int stream, double min,double max);

		private:
			//метод для установки имени функции
			void SetName(const std::string &name);
	};
}

#endif
