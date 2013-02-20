//Model.cpp

#include "Model.h"

namespace GeneratorGPSS
{
	Model::Model() : nodes(), threads()
	{
	}

	void Model::GenerateTextGPSS(std::ofstream &output)
	{
		std::vector<int>::iterator thread;
		std::vector<Node *>::iterator node;


		output<<"**************************************************\n";
		output<<"*Declarations";
		output<<"\n**************************************************\n";

		for(node = nodes.begin(); node!=nodes.end();node++)
		{
			(*node)->GenerateDeclaration(output);
		}

		output<<"\n**************************************************\n";

		for(thread=threads.begin();thread!=threads.end();thread++)
		{
			output<<"\n**************************************************\n";
			output<<"*Thread "<<(*thread);
			output<<"\n**************************************************\n";

			for(node = nodes.begin(); node!=nodes.end();node++)
			{
				(*node)->GenerateDefinition(output,(*thread));
			}
		}
	}

	void Model::AddNode(Node *node)
	{
		nodes.push_back(node);
	}

	void Model::AddThread(int thread)
	{
		threads.push_back(thread);
	}

	Model::~Model()
	{
		std::vector<Node*>::iterator p;
		for(p=nodes.begin();p!=nodes.end();p++)
		{
			delete (*p);
		}
	}
}
