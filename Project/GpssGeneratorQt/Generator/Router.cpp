//Router.cpp

#include "Router.h"

namespace GeneratorGPSS
{
	void Router::GenerateDefinition(std::ofstream &output,const int thread)
	{
		std::vector<std::pair<int, std::vector<std::pair<Node*,double> > > >::iterator p;
		for(p=nextNodes.begin();p!=nextNodes.end();p++)
		{
			if(p->first==thread)
			{
				output<<"L_"<<name<<"_"<<thread;

				output.setf(std::ios::fixed, std::ios::floatfield);
				output.precision(3);

				double lastProb=1.0, curProb;
				std::vector<std::pair<Node*,double> >::iterator n;
				for(n=p->second.begin();n!=p->second.end();n++)
				{
					if(lastProb<0.000001)
						break;

					curProb=n->second/lastProb;
					if(curProb>1.0)
						curProb=1.0;

					output<<"\t\t\tTRANSFER \t"<<curProb<<",,L_"<<n->first->GetName()<<"_"<<thread<<std::endl;
					lastProb-=n->second;
				}

				break;
			}
		}
	}

	void Router::AddNode(int thread, Node* node, double prob)
	{
		std::vector<std::pair<int, std::vector<std::pair<Node*,double> > > >::iterator p;
		for(p=nextNodes.begin();p!=nextNodes.end();p++)
		{
			if(p->first==thread)
			{
				p->second.push_back(std::make_pair(node, prob));

				break;
			}
		}

		if(p==nextNodes.end())
		{
			nextNodes.push_back(std::make_pair(thread,std::vector<std::pair<Node*,double> >()));
			nextNodes.back().second.push_back(std::make_pair(node, prob));
		}
	}

	void Router::ClearNodes(int thread)
	{
		std::vector<std::pair<int, std::vector<std::pair<Node*,double> > > >::iterator p;
		for(p=nextNodes.begin();p!=nextNodes.end();p++)
		{
			if(p->first==thread)
			{
				nextNodes.erase(p);
				break;
			}
		}
	}
}
