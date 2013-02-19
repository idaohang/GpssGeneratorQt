//Facility.h
//Содержит объявление класса устройства Facility

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
			//количество каналов устройства
			int chanelAmount;

			//массив, содержащий узел, в который можно попасть из данного, для различных потоков
			std::vector<std::pair<int, Node*> > nextNode;

			//массив, содержащий функции распределения генерации заявок для различных потоков
			std::vector<std::pair<int, Function*> > function;

			//статистики для узла
			//stats[0] - до очереди
			//stats[1] - после очереди, перед захватом канала
			//stats[2] - после освобождения канала
			std::vector<Statistics* > stats[3];
		public:
			//установка количества каналов устройства
			void SetChanelAmount(int chAmount);

			//добавление узла для потока thread
			void AddNode(int thread, Node* node);

			//удаление узла для потока thread
			void DeleteNode(int thread);

			//добавление функции для потока thread
			void AddFunction(int thread, Function* f);

			//удаление функции для потока thread
			void DeleteFunction(int thread);

			//метод генерирует определение узла генератора в начале текста модели
			//output - выходной поток, куда будет записан сгенерированный GPSS-текст
			virtual void GenerateDeclaration(std::ofstream &output);

			//метод генерирует GPSS-текст для описания узла генератора в потоке thread
			//output - выходной поток, куда будет записан сгенерированный GPSS-текст
			//thread - номер потока заявок
			virtual void GenerateDefinition(std::ofstream &output,const int thread);

			//метод для добавления к узлу стандартных статистик
			//thread - поток, ля которого будут рассчитываться характеристики
			//mask - определяет, в каких позициях будут установлены очереди для статистики
			//mask=1 - от начала очереди до захвата канала, 2 - от начала очереди до конца обработки, 3 - обе
			void GenerateStandartStatistics(int thread, int mask);

			//деструктор
			~Facility();
	};
}

#endif
