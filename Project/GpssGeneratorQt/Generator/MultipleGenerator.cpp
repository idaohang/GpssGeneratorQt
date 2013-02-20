#include "MultipleGenerator.h"

namespace GeneratorGPSS
{
void MultipleGenerator::GenerateDeclaration(std::ofstream &output)
{
}

void MultipleGenerator::GenerateDefinition(std::ofstream &output,const int thread)
{
    std::vector<std::pair<int, int> >::iterator p;
    for(p=counts.begin();p!=counts.end();p++)
    {
        if(p->first==thread)
        {
            output<<"\t\t\tGENERATE \t,,,"<<p->second<<"\n";

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

void MultipleGenerator::AddCount(int thread, int count)
{
    DeleteCount(thread);

    counts.push_back(std::make_pair(thread, count));
}

void MultipleGenerator::DeleteCount(int thread)
{
    std::vector<std::pair<int, int> >::iterator p;

    for(p=counts.begin();p!=counts.end();p++)
    {
        if(p->first==thread)
        {
            counts.erase(p);
            break;
        }
    }
}
}

