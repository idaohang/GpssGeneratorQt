//Router.h
//�������� ���������� ������ ����������� ���� Router

#ifndef ROUTER_H
#define ROUTER_H

#include <vector>
#include <utility>
#include "Node.h"

namespace GeneratorGPSS
{
	class Router : public Node
	{
		protected:
			//������, ���������� ������ �����, � ������� ����� ������� �� ������� ����������� ����, ��� ��������� �������
			//��� ������� ������ ������� ������ ��� <����, ����������� ��������>
			//��� ������� ������ ����� ������������ �������� ������ ���� ����� 1.0
			std::vector<std::pair<int, std::vector<std::pair<Node*,double> > > > nextNodes;

		public:
			//����� ���������� GPSS-����� ��� �������� ����������� ���� � ������ thread 
			//output - �������� �����, ���� ����� ������� ��������������� GPSS-�����
			//thread - ����� ������ ������
			virtual void GenerateDefinition(std::ofstream &output,const int thread);

			//���������� ���� ��� ������ thread
			//prob - ����������� �������� � ���� node �� ������� ����������� ����
			void AddNode(int thread, Node* node, double prob);

			//�������� ���� ����� ��� ������ thread
			void ClearNodes(int thread);
	};
}

#endif
