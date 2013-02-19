//GaussianFunction.h
//�������� ���������� ������ ������� ����������� ������������ ������������� GaussianFunction

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
			//�����������
			GaussianFunction();

			//����� ���������� GPSS-����� ��� �������� ������� ����������� ������������ ������������� � ������ thread
			//output - �������� �����, ���� ����� ������� ��������������� GPSS-�����
			//thread - ����� ������ ������
			virtual void GenerateDefinition(std::ofstream &output);

			//����� ��� ������� ���������� �������
			void SetParams(int stream, double mean,double stdDev);

		private:
			//����� ��� ��������� ����� �������
			void SetName(const std::string &name);
	};
}

#endif
