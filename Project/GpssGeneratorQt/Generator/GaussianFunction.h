//GaussianFunction.h
//—одержит объ€вление класса функции нормального гауссовского распределени€ GaussianFunction

#ifndef GAUSSIAN_FUNCTION_H
#define GAUSSIAN_FUNCTION_H

#include "Function.h"

namespace GeneratorGPSS
{
	class GaussianFunction : public Function
	{
		protected:
			int stream;
			double mean;
			double stdDev;
		public:
			//конструктор
			GaussianFunction();

			//метод генерирует GPSS-текст дл€ описани€ функции нормального гауссовского распределени€ в потоке thread
			//output - выходной поток, куда будет записан сгенерированный GPSS-текст
			//thread - номер потока за€вок
			virtual void GenerateDefinition(std::ofstream &output);

			//метод дл€ задани€ параметров функции
			void SetParams(int stream, double mean,double stdDev);

		private:
			//метод дл€ установки имени функции
			void SetName(const std::string &name);
	};
}

#endif
