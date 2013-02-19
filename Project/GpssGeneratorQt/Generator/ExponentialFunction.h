//ExponentialFunction.h
//�������� ���������� ������ ������� ����������������� ������������� ExponentialFunction

#ifndef EXPONENTIAL_FUNCTION_H
#define EXPONENTIAL_FUNCTION_H

#include "Function.h"

namespace GeneratorGPSS
{
	class ExponentialFunction : public Function
	{
		protected:
			int stream;
			double locate;
			double scale;
		public:
			//�����������
			ExponentialFunction();

			//����� ���������� GPSS-����� ��� �������� ������� ����������������� ������������� � ������ thread
			//output - �������� �����, ���� ����� ������� ��������������� GPSS-�����
			//thread - ����� ������ ������
			virtual void GenerateDefinition(std::ofstream &output);

			//����� ��� ������� ���������� �������
			void SetParams(int stream, double locate,double scale);

		private:
			//����� ��� ��������� ����� �������
			void SetName(const std::string &name);
	};
}

#endif
