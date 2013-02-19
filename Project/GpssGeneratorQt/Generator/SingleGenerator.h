//SingleGenerator.h
//—одержит объ€вление класса одиночного генератора за€вок SingleGenerator

#ifndef SINGLE_GENERATOR_H
#define	SINGLE_GENERATOR_H

#include "Generator.h"
#include "Function.h"

namespace GeneratorGPSS
{
	class SingleGenerator : public Generator
	{
		protected:
			//массив, содержащий функции распределени€ генерации за€вок дл€ различных потоков
			std::vector<std::pair<int, Function*> > function;

		public:
			//метод генерирует определение узла генератора в начале текста модели
			//output - выходной поток, куда будет записан сгенерированный GPSS-текст
			virtual void GenerateDeclaration(std::ofstream &output);

			//метод генерирует GPSS-текст дл€ описани€ узла генератора в потоке thread
			//output - выходной поток, куда будет записан сгенерированный GPSS-текст
			//thread - номер потока за€вок
			virtual void GenerateDefinition(std::ofstream &output,const int thread);

			//добавление функции дл€ потока thread
			void AddFunction(int thread, Function* f);

			//удаление функции дл€ потока thread
			void DeleteFunction(int thread);
	};
}

#endif
