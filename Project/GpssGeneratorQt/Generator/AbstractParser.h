//AbstractParser.h
//—одержит объ€вление класса AbstractParser, определ€ющего интерфейс дл€ классов,
//преобразующих текстовое описание модели в объект класса Model

#ifndef ABSTRACT_PARSER_H
#define ABSTRACT_PARSER_H

#include <fstream>
#include <vector>
#include "Model.h"

namespace GeneratorGPSS
{
	class AbstractParser
	{
		public:
			//метод считывает описание модели из потока input
			//и согласно описанию создает набор объектов класса Model
			virtual void DescribeModel(std::ifstream &input,std::vector<Model*> &models)=0;
	};
}

#endif