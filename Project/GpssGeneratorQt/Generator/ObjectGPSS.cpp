//ObjectGPSS.cpp
//�������� ����������� ������� ������������ ������ ObjectGPSS

#include "ObjectGPSS.h"
#include <string>

namespace GeneratorGPSS
{
	//�����������
	ObjectGPSS::ObjectGPSS()
	{
		this->name="";
	}

	//����������
	ObjectGPSS::~ObjectGPSS()
	{
	}

	//����� ���������� ����������� ���� � ������ ������ ������
	//output - �������� �����, ���� ����� ������� ��������������� GPSS-�����
	void ObjectGPSS::GenerateDeclaration(std::ofstream &output)
	{
	}

	//����� ��� ��������� ����� ����
	std::string ObjectGPSS::GetName()
	{
		return this->name;
	}

	//����� ��� ��������� ����� ����
	void ObjectGPSS::SetName(const std::string &name)
	{
		this->name=name;
	}
}
