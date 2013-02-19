//Generator.h
//�������� ���������� ������������ ������ ���������� ������ Generator
#ifndef GENERATOR_H
#define	GENERATOR_H

#include "Node.h"
#include "Statistics.h"
#include <vector>
#include <utility>

namespace GeneratorGPSS
{
	class Generator : public Node
	{
		protected:
			//������, ���������� ����, � ������� ����� ������� �� �������, ��� ��������� �������
			std::vector<std::pair<int, Node*> > nextNode;

			//���������� ��� ����
			std::vector<Statistics* > stats;
		public:
			//���������� ���� ��� ������ thread
			void AddNode(int thread, Node* node);

			//�������� ���� ��� ������ thread
			void DeleteNode(int thread);

			//����� ��� ���������� � ���������� ����������� ���������
			//thread - �����, �� �������� ����� �������������� ��������������
			//��� ������ ��� ���������� - ����������� ����� ��������� ���������� 
			void GenerateStandartStatistics(int thread=-1);

			//����������
			virtual ~Generator();
	};
}

#endif
