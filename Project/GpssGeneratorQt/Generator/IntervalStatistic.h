//IntervalStatistics.h
//Содержит объявление класса узлов для сбора статистики на интервале IntervalStatistics


#ifndef INTERVAL_STATISTICS_H
#define iNTERVAL_STATISTICS_H

#include "Statistics.h"

namespace GeneratorGPSS
{
	class IntervalStatistics : public Statistics
	{
		protected:
			bool isInput;
			bool isHistogram;

		public:
			//конструктор
			//isInput - определяет, описывает ли данный объект начало интервала или конец
			//thread - определяет поток, в котором находится статистика
			//histogram - определяет, служит ли данная статистика для сбора точечных характеристик или для построения гистограммы
			IntervalStatistics(bool isInput,int thread, bool isHistogram=false);

			//метод генерирует определение узла в начале текста модели
			//output - выходной поток, куда будет записан сгенерированный GPSS-текст
			virtual void GenerateDeclaration(std::ofstream &output);

			//метод генерирует GPSS-текст для описания узла в потоке thread
			//output - выходной поток, куда будет записан сгенерированный GPSS-текст
			//thread - номер потока заявок
			virtual void GenerateDefinition(std::ofstream &output,const int thread);
	};
}

#endif
