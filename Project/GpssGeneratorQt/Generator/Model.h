//Model.h
//�������� ���������� ������ ������ Model
#ifndef MODEL_H
#define MODEL_H

#include <vector>
#include <fstream>
#include "Node.h"

namespace GeneratorGPSS
{
	class Model
	{
		protected:
			//��������� ����� ������
			std::vector<Node *> nodes;

			//������ ������� ������
			std::vector<int> threads;
		public:
			//�����������
			Model();

			//����� ��� ��������� GPSS-������ ������
			//output - �����, ���� �������������� ������ ������ �����
			void GenerateTextGPSS(std::ofstream &output);

			//���������� ���� � ������
			void AddNode(Node *node);

			//���������� ������ � ������
			void AddThread(int thread);

			//����������
			virtual ~Model();
	};
}


#endif
