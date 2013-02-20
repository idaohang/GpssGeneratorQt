//Terminator.cpp

#include "Terminator.h"
#include "IntervalStatistic.h"
#include <cstring>

namespace GeneratorGPSS
{
	void Terminator::GenerateDefinition(std::ofstream &output,const int thread)
	{
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
	}

	void Terminator::GenerateStandartStatistics(int thread)
	{
		Statistics *s;
		s=new IntervalStatistics(false,thread);
		if(thread==-1)
                        s->SetName("net");
		else
		{
			char buf[9];
                        sprintf(buf,"%d",thread);
                        s->SetName(std::string("net_")+buf);
		}

		s->SetNode(0);
		stats.push_back(s);
	}

        void Terminator::AddNode(int thread, Node* node)
        {
            DeleteNode(thread);

            nextNode.push_back(std::make_pair(thread,node));
        }

        void Terminator::DeleteNode(int thread)
        {
            std::vector<std::pair<int, Node * > >::iterator p;
            for(p=nextNode.begin();p!=nextNode.end();p++)
            {
                if(p->first==thread)
                {
                    nextNode.erase(p);
                    break;
                }
            }
        }

	Terminator::~Terminator()
	{
		std::vector<Statistics*>::iterator p;
		for(p=stats.begin();p!=stats.end();p++)
		{
			delete (*p);
		}
	}
}
