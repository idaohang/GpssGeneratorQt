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
                        virtual void GenerateDeclaration(std::ofstream &output);

                        virtual void GenerateDefinition(std::ofstream &output,const int thread);

                        void AddCount(int thread, int count);

                        void DeleteCount(int thread);
        };
}

#endif // MULTIPLEGENERATOR_H
