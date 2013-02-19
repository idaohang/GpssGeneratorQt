//IntervalStatistics.cpp
//Содержит описание методов класса узла для сбора статистики на интервале IntervalStatistics

#include "IntervalStatistic.h"

namespace GeneratorGPSS
{
	//конструктор
	//isInput - определяет, описывает ли данный объект начало интервала или конец
	//thread - определяет поток, в котором находится статистика
	//histogram - определяет, служит ли данная статистика для сбора точечных характеристик или для построения гистограммы
	IntervalStatistics::IntervalStatistics(bool isInput,int thread, bool isHistogram)
	{
		this->isInput=isInput;
		this->thread=thread;
		this->isHistogram=isHistogram;
	}

	//метод генерирует определение узла в начале текста модели
	//output - выходной поток, куда будет записан сгенерированный GPSS-текст
	void IntervalStatistics::GenerateDeclaration(std::ofstream &output)
	{
		if(isHistogram)
		{
			output<<"TQ"<<name<<"\tTABLE\tQ"<<name<<",0,10,10\n";
		}
	}

	//метод генерирует GPSS-текст для описания узла в потоке thread
	//output - выходной поток, куда будет записан сгенерированный GPSS-текст
	//thread - номер потока заявок
	void IntervalStatistics::GenerateDefinition(std::ofstream &output,const int thread)
	{
		if(thread==this->thread || this->thread==-1)
		{
			if(isInput)
			{
                                output<<"\t\t\tqueue\t\t"<<name<<std::endl;
			}
			else
			{
                                output<<"\t\t\tdepart\t\t"<<name<<std::endl;
			}

			//для глобальных статистик выводим переход на следующий узел
			if(nextNode!=0)
			{
				output<<"\t\t\tTRANSFER \t"<<"1.0,,L_"<<nextNode->GetName()<<"_"<<thread<<std::endl;
			}
		}
	}
}
