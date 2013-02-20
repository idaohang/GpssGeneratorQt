//Generator.cpp

#include "Generator.h"
#include "IntervalStatistic.h"

namespace GeneratorGPSS
{
void Generator::AddNode(int thread, Node* node)
{
    DeleteNode(thread);

    nextNode.push_back(std::make_pair(thread,node));
}

void Generator::DeleteNode(int thread)
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

void Generator::GenerateStandartStatistics(int thread)
{
    Statistics *s;
    s=new IntervalStatistics(true,thread);
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

Generator::~Generator()
{
    std::vector<Statistics*>::iterator p;
    for(p=stats.begin();p!=stats.end();p++)
    {
        delete (*p);
    }
}
}
