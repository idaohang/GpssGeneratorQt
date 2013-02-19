//Facility.h
//�������� ���������� ������ ���������� Facility

#ifndef FACILITY_H
#define FACILITY_H

#include "Node.h"
#include "Function.h"
#include "Statistics.h"
#include <vector>
#include <utility>

namespace GeneratorGPSS
{
	class Facility : public Node
	{
		protected:
			//���������� ������� ����������
			int chanelAmount;

			//������, ���������� ����, � ������� ����� ������� �� �������, ��� ��������� �������
			std::vector<std::pair<int, Node*> > nextNode;

			//������, ���������� ������� ������������� ��������� ������ ��� ��������� �������
			std::vector<std::pair<int, Function*> > function;

			//���������� ��� ����
			//stats[0] - �� �������
			//stats[1] - ����� �������, ����� �������� ������
			//stats[2] - ����� ������������ ������
			std::vector<Statistics* > stats[3];
		public:
			//��������� ���������� ������� ����������
			void SetChanelAmount(int chAmount);

			//���������� ���� ��� ������ thread
			void AddNode(int thread, Node* node);

			//�������� ���� ��� ������ thread
			void DeleteNode(int thread);

			//���������� ������� ��� ������ thread
			void AddFunction(int thread, Function* f);

			//�������� ������� ��� ������ thread
			void DeleteFunction(int thread);

			//����� ���������� ����������� ���� ���������� � ������ ������ ������
			//output - �������� �����, ���� ����� ������� ��������������� GPSS-�����
			virtual void GenerateDeclaration(std::ofstream &output);

			//����� ���������� GPSS-����� ��� �������� ���� ���������� � ������ thread
			//output - �������� �����, ���� ����� ������� ��������������� GPSS-�����
			//thread - ����� ������ ������
			virtual void GenerateDefinition(std::ofstream &output,const int thread);

			//����� ��� ���������� � ���� ����������� ���������
			//thread - �����, �� �������� ����� �������������� ��������������
			//mask - ����������, � ����� �������� ����� ����������� ������� ��� ����������
			//mask=1 - �� ������ ������� �� ������� ������, 2 - �� ������ ������� �� ����� ���������, 3 - ���
			void GenerateStandartStatistics(int thread, int mask);

			//����������
			~Facility();
	};
}

#endif
