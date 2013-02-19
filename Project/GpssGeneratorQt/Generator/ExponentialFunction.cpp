//ExponentialFunction.cpp
//�������� ����������� ������� ������ ������� ����������������� ������������� ExponentialFunction

#include "ExponentialFunction.h"

namespace GeneratorGPSS
{
	//�����������
	ExponentialFunction::ExponentialFunction()
	{
		this->name="exponential";
	}

	//����� ���������� GPSS-����� ��� �������� ������� ����������������� ������������� � ������ thread
	//output - �������� �����, ���� ����� ������� ��������������� GPSS-�����
	//thread - ����� ������ ������
	void ExponentialFunction::GenerateDefinition(std::ofstream &output)
	{
		output.setf(std::ios::fixed,std::ios::floatfield);
		output.precision(3);
		output<<name<<'('<<stream<<','<<locate<<','<<scale<<")";
	}

	//����� ��� ������� ���������� �������
	void ExponentialFunction::SetParams(int stream, double locate,double scale)
	{
		this->stream=stream;
		this->locate=locate;
		this->scale=scale;
	}
}
