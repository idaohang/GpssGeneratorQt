//ObjectGPSS.h
//Содержит объявление абстрактного класса ObjectGPSS
#ifndef OBJECT_GPSS_H
#define OBJECT_GPSS_H

#include <string>
#include <fstream>

namespace GeneratorGPSS
{
	class ObjectGPSS
	{
		protected:
			//поле для хранения имени узла, используемого в GPSS-тексте модели
			std::string name;

		public:
			//конструктор
			ObjectGPSS();

			//деструктор
			virtual ~ObjectGPSS();

			//метод генерирует определение объекта в начале текста модели
			//output - выходной поток, куда будет записан сгенерированный GPSS-текст
			virtual void GenerateDeclaration(std::ofstream &output)=0;

			//метод для получения имени узла
			std::string GetName();

			//метод для установки имени узла
			void SetName(const std::string &name);
	};
}

#endif
