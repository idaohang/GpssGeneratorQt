//SingleGenerator.h
//�������� ���������� ������ ���������� ���������� ������ SingleGenerator

#ifndef SINGLE_GENERATOR_H
#define	SINGLE_GENERATOR_H

#include "Generator.h"
#include "Function.h"

namespace GeneratorGPSS
{
	class SingleGenerator : public Generator
	{
		protected:
			//������, ���������� ������� ������������� ��������� ������ ��� ��������� �������
			std::vector<std::pair<int, Function*> > function;

		public:
			//����� ���������� ����������� ���� ���������� � ������ ������ ������
			//output - �������� �����, ���� ����� ������� ��������������� GPSS-�����
			virtual void GenerateDeclaration(std::ofstream &output);

			//����� ���������� GPSS-����� ��� �������� ���� ���������� � ������ thread
			//output - �������� �����, ���� ����� ������� ��������������� GPSS-�����
			//thread - ����� ������ ������
			virtual void GenerateDefinition(std::ofstream &output,const int thread);

			//���������� ������� ��� ������ thread
			void AddFunction(int thread, Function* f);

			//�������� ������� ��� ������ thread
			void DeleteFunction(int thread);
	};
}

#endif
