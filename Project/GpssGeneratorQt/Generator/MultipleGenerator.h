#ifndef MULTIPLEGENERATOR_H
#define MULTIPLEGENERATOR_H

#include "Generator.h"
#include "Function.h"

namespace GeneratorGPSS
{
        class MultipleGenerator : public Generator
        {
                protected:
            std::vector<std::pair<int,int> > counts;

                public:
                        //метод генерирует определение узла генератора в начале текста модели
                        //output - выходной поток, куда будет записан сгенерированный GPSS-текст
                        virtual void GenerateDeclaration(std::ofstream &output);

                        //метод генерирует GPSS-текст для описания узла генератора в потоке thread
                        //output - выходной поток, куда будет записан сгенерированный GPSS-текст
                        //thread - номер потока заявок
                        virtual void GenerateDefinition(std::ofstream &output,const int thread);

                        //добавление функции для потока thread
                        void AddCount(int thread, int count);

                        //удаление функции для потока thread
                        void DeleteCount(int thread);
        };
}

#endif // MULTIPLEGENERATOR_H
