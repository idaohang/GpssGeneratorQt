//Function.h
//�������� ���������� ������ ������� Function

#ifndef FUNCTION_H
#define FUNCTION_H

#include "ObjectGPSS.h"

namespace GeneratorGPSS
{
	class Function : public ObjectGPSS
	{
		public:
			//����� ���������� ����������� ������� � ������ ������ ������
			//output - �������� �����, ���� ����� ������� ��������������� GPSS-�����
			virtual void GenerateDeclaration(std::ofstream &output);

			//����� ���������� GPSS-����� ��� �������� ������ �������
			//output - �������� �����, ���� ����� ������� ��������������� GPSS-�����
			virtual void GenerateDefinition(std::ofstream &output)=0;
	};
}

#endif
