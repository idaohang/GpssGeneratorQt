//IntervalStatistics.h
//�������� ���������� ������ ����� ��� ����� ���������� �� ��������� IntervalStatistics


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
			//�����������
			//isInput - ����������, ��������� �� ������ ������ ������ ��������� ��� �����
			//thread - ���������� �����, � ������� ��������� ����������
			//histogram - ����������, ������ �� ������ ���������� ��� ����� �������� ������������� ��� ��� ���������� �����������
			IntervalStatistics(bool isInput,int thread, bool isHistogram=false);

			//����� ���������� ����������� ���� � ������ ������ ������
			//output - �������� �����, ���� ����� ������� ��������������� GPSS-�����
			virtual void GenerateDeclaration(std::ofstream &output);

			//����� ���������� GPSS-����� ��� �������� ���� � ������ thread
			//output - �������� �����, ���� ����� ������� ��������������� GPSS-�����
			//thread - ����� ������ ������
			virtual void GenerateDefinition(std::ofstream &output,const int thread);
	};
}

#endif
