//Function.h
//—одержит объ€вление класса функции Function

#ifndef FUNCTION_H
#define FUNCTION_H

#include "ObjectGPSS.h"

namespace GeneratorGPSS
{
	class Function : public ObjectGPSS
	{
		public:
			//метод генерирует определение функции в начале текста модели
			//output - выходной поток, куда будет записан сгенерированный GPSS-текст
			virtual void GenerateDeclaration(std::ofstream &output);

			//метод генерирует GPSS-текст дл€ описани€ вызова функции
			//output - выходной поток, куда будет записан сгенерированный GPSS-текст
			virtual void GenerateDefinition(std::ofstream &output)=0;
	};
}

#endif
