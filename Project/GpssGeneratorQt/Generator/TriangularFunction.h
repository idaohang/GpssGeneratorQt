//TriangularFunction.h
//—одержит объ€вление класса функции треугольного распределени€ TriangularFunction

#ifndef TRINAGULAR_FUNCTION_H
#define TRIANGULAR_FUNCTION_H

#include "Function.h"

namespace GeneratorGPSS
{
	class TriangularFunction : public Function
	{
		protected:
			int stream;
			double min;
			double max;
			double mode;
		public:
			//конструктор
			TriangularFunction();

			//метод генерирует GPSS-текст дл€ описани€ функции треугольного распределени€ в потоке thread
			//output - выходной поток, куда будет записан сгенерированный GPSS-текст
			//thread - номер потока за€вок
			virtual void GenerateDefinition(std::ofstream &output);

			//метод дл€ задани€ параметров функции
			void SetParams(int stream, double min,double max, double mode);

		private:
			//метод дл€ установки имени функции
			void SetName(const std::string &name);
	};
}

#endif
