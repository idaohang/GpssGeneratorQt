//ObjectGPSS.cpp
//Содержит определение методов абстрактного класса ObjectGPSS

#include "ObjectGPSS.h"
#include <string>

namespace GeneratorGPSS
{
	//конструктор
	ObjectGPSS::ObjectGPSS()
	{
		this->name="";
	}

	//деструктор
	ObjectGPSS::~ObjectGPSS()
	{
	}

	//метод генерирует определение узла в начале текста модели
	//output - выходной поток, куда будет записан сгенерированный GPSS-текст
	void ObjectGPSS::GenerateDeclaration(std::ofstream &output)
	{
	}

	//метод для получения имени узла
	std::string ObjectGPSS::GetName()
	{
		return this->name;
	}

	//метод для установки имени узла
	void ObjectGPSS::SetName(const std::string &name)
	{
		this->name=name;
	}
}
