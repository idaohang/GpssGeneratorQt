//SingleGenerator.cpp

#include "SingleGenerator.h"

namespace GeneratorGPSS
{
	void SingleGenerator::GenerateDeclaration(std::ofstream &output)
	{
		std::vector<std::pair<int, Function*> >::iterator p;
		for(p=function.begin();p!=function.end();p++)
		{
			p->second->GenerateDeclaration(output);
		}
	}

	void SingleGenerator::GenerateDefinition(std::ofstream &output,const int thread)
	{
		std::vector<std::pair<int, Function*> >::iterator p;
		for(p=function.begin();p!=function.end();p++)
		{
			if(p->first==thread)
			{
				output<<"\t\t\tGENERATE \t(";
				p->second->GenerateDefinition(output);
				output<<")\n";

				output<<"L_"<<name<<"_"<<thread;

				for(std::vector<Statistics*>::iterator s=stats.begin();s!=stats.end();s++)
				{
					(*s)->GenerateDefinition(output,thread);
				}

				std::vector<std::pair<int, Node*> >::iterator next;
				for(next=nextNode.begin();next!=nextNode.end();next++)
				{
					if(next->first==thread)
					{
						output<<"\t\t\tTRANSFER \t"<<"1.0,,L_"<<next->second->GetName()<<"_"<<thread<<std::endl;
						break;
					}
				}
				if(next==nextNode.end())
				{
					output<<"\t\t\tTERMINATE \t1\n";
				}

				break;
			}
		}
		
	}

	void SingleGenerator::AddFunction(int thread, Function* f)
	{
		DeleteFunction(thread);

		function.push_back(std::make_pair(thread, f));
	}

	void SingleGenerator::DeleteFunction(int thread)
	{
		std::vector<std::pair<int, Function*> >::iterator p;

		for(p=function.begin();p!=function.end();p++)
		{
			if(p->first==thread)
			{
				function.erase(p);
				break;
			}
		}
	}
}
