//AbstractParser.h
//�������� ���������� ������ AbstractParser, ������������� ��������� ��� �������,
//������������� ��������� �������� ������ � ������ ������ Model

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
			//����� ��������� �������� ������ �� ������ input
			//� �������� �������� ������� ����� �������� ������ Model
			virtual void DescribeModel(std::ifstream &input,std::vector<Model*> &models)=0;
	};
}

#endif