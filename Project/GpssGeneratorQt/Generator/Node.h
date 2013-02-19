//Node.h
//Содержит объявление абстрактного класса Node
#ifndef NODE_H
#define	NODE_H

#include "ObjectGPSS.h"

namespace GeneratorGPSS
{
	class Node : public ObjectGPSS
	{
		public:
			//метод генерирует определение узла в начале текста модели
			//output - выходной поток, куда будет записан сгенерированный GPSS-текст
			virtual void GenerateDeclaration(std::ofstream &output);

			//метод генерирует GPSS-текст для описания узла в потоке thread
			//output - выходной поток, куда будет записан сгенерированный GPSS-текст
			//thread - номер потока заявок
			virtual void GenerateDefinition(std::ofstream &output,const int thread)=0;
        };
}

#endif
