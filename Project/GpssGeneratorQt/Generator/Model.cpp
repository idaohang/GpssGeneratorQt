//Model.cpp
//—одержит определение методов класса модели Model

#include "Model.h"

namespace GeneratorGPSS
{
	//конструктор
	Model::Model() : nodes(), threads()
	{
	}

	//метод дл€ генерации GPSS-текста модели
	//output - поток, куда осуществл€етс€ запись текста мдели
	void Model::GenerateTextGPSS(std::ofstream &output)
	{
		std::vector<int>::iterator thread;
		std::vector<Node *>::iterator node;

		//вывод комментари€ перед определени€ми необходимых элементов
		output<<"**************************************************\n";
		output<<"*Declarations";
		output<<"\n**************************************************\n";

		//генерируем объ€вление узлов
		for(node = nodes.begin(); node!=nodes.end();node++)
		{
			(*node)->GenerateDeclaration(output);
		}

		//вывод комментари€ дл€ отделени€ определени€ необходимых элементов от основного текста модели
		output<<"\n**************************************************\n";

		//дл€ каждого потока генерируем GPSS-текст узлов
		for(thread=threads.begin();thread!=threads.end();thread++)
		{
			//вывод комментари€ дл€ разделени€ потоков
			output<<"\n**************************************************\n";
			output<<"*Thread "<<(*thread);
			output<<"\n**************************************************\n";

			for(node = nodes.begin(); node!=nodes.end();node++)
			{
				(*node)->GenerateDefinition(output,(*thread));
			}
		}
	}

	//добавление узла в модель
	void Model::AddNode(Node *node)
	{
		nodes.push_back(node);
	}

	//добавление потока в модель
	void Model::AddThread(int thread)
	{
		threads.push_back(thread);
	}

	//деструктор
	Model::~Model()
	{
		std::vector<Node*>::iterator p;
		for(p=nodes.begin();p!=nodes.end();p++)
		{
			delete (*p);
		}
	}
}
