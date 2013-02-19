//Model.h
//Содержит объявление класса модели Model
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
			//множество узлов модели
			std::vector<Node *> nodes;

			//номера потоков модели
			std::vector<int> threads;
		public:
			//конструктор
			Model();

			//метод для генерации GPSS-текста модели
			//output - поток, куда осуществляется запись текста мдели
			void GenerateTextGPSS(std::ofstream &output);

			//добавление узла в модель
			void AddNode(Node *node);

			//добавление потока в модель
			void AddThread(int thread);

			//деструктор
			virtual ~Model();
	};
}


#endif
