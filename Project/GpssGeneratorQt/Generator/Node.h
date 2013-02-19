//Node.h
//�������� ���������� ������������ ������ Node
#ifndef NODE_H
#define	NODE_H

#include "ObjectGPSS.h"

namespace GeneratorGPSS
{
	class Node : public ObjectGPSS
	{
		public:
			//����� ���������� ����������� ���� � ������ ������ ������
			//output - �������� �����, ���� ����� ������� ��������������� GPSS-�����
			virtual void GenerateDeclaration(std::ofstream &output);

			//����� ���������� GPSS-����� ��� �������� ���� � ������ thread
			//output - �������� �����, ���� ����� ������� ��������������� GPSS-�����
			//thread - ����� ������ ������
			virtual void GenerateDefinition(std::ofstream &output,const int thread)=0;
        };
}

#endif
