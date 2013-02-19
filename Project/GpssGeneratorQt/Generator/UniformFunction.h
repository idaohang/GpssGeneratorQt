//UniformFunction.h
//�������� ���������� ������ ������� ������������ ������������� UniformFunction

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
			//�����������
			UniformFunction();

			//����� ���������� GPSS-����� ��� �������� ������� ������������ ������������� � ������ thread
			//output - �������� �����, ���� ����� ������� ��������������� GPSS-�����
			//thread - ����� ������ ������
			virtual void GenerateDefinition(std::ofstream &output);

			//����� ��� ������� ���������� �������
			void SetParams(int stream, double min,double max);

		private:
			//����� ��� ��������� ����� �������
			void SetName(const std::string &name);
	};
}

#endif
