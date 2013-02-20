//Facility.cpp

#include "Facility.h"
#include "IntervalStatistic.h"

namespace GeneratorGPSS
{

void Facility::SetChanelAmount(int chAmount)
{
    this->chanelAmount=chAmount;
}

void Facility::AddNode(int thread, Node* node)
{
    DeleteNode(thread);

    nextNode.push_back(std::make_pair(thread,node));
}

void Facility::DeleteNode(int thread)
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

void Facility::AddFunction(int thread, Function* f)
{
    DeleteFunction(thread);

    function.push_back(std::make_pair(thread, f));
}

void Facility::DeleteFunction(int thread)
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

void Facility::GenerateDeclaration(std::ofstream &output)
{
    if(chanelAmount>1)
    {
        output<<name<<"\t\t\tSTORAGE \t"<<chanelAmount<<std::endl;
    }

    for(int i=0;i<3;i++)
    {
        for(std::vector<Statistics*>::iterator p=stats[i].begin();p!=stats[i].end();p++)
        {
            (*p)->GenerateDeclaration(output);
        }
    }

    std::vector<std::pair<int,Function * > >::iterator f;
    for(f=function.begin();f!=function.end();f++)
    {
        f->second->GenerateDeclaration(output);
    }
}

void Facility::GenerateDefinition(std::ofstream &output,const int thread)
{
    std::vector<std::pair<int, Function*> >::iterator p;
    for(p=function.begin();p!=function.end();p++)
    {
        if(p->first==thread)
        {
            //label for node
            output<<"L_"<<name<<"_"<<thread;

            for(std::vector<Statistics*>::iterator s=stats[0].begin();s!=stats[0].end();s++)
            {
                (*s)->GenerateDefinition(output,thread);
            }
            
            if(chanelAmount>1)
            {
                output<<"\t\t\tENTER \t\t"<<name<<std::endl;
            }
            else
            {
                output<<"\t\t\tSEIZE \t\t"<<name<<std::endl;
            }

            for(std::vector<Statistics*>::iterator s=stats[1].begin();s!=stats[1].end();s++)
            {
                (*s)->GenerateDefinition(output,thread);
            }

            output<<"\t\t\tADVANCE \t(";
            p->second->GenerateDefinition(output);
            output<<")\n";

            if(chanelAmount>1)
            {
                output<<"\t\t\tLEAVE \t\t"<<name<<std::endl;
            }
            else
            {
                output<<"\t\t\tRELEASE \t"<<name<<std::endl;
            }

            for(std::vector<Statistics*>::iterator s=stats[2].begin();s!=stats[2].end();s++)
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

void Facility::GenerateStandartStatistics(int thread, int mask)
{
    Statistics *s;

    char buf[9];
    sprintf(buf,"%d",thread);

    if(mask&1)
    {
        s=new IntervalStatistics(true,thread);
        if(thread!=-1)
            s->SetName("w_"+name + "_" + buf);
        else
            s->SetName("w_"+name);
        s->SetNode(0);
        stats[0].push_back(s);

        s=new IntervalStatistics(false,thread);
        if(thread!=-1)
            s->SetName("w_"+name + "_" + buf);
        else
            s->SetName("w_"+name);
        s->SetNode(0);
        stats[1].push_back(s);
    }

    if(mask&2)
    {
        s=new IntervalStatistics(true,thread);
        if(thread!=-1)
            s->SetName(name + "_" + buf);
        else
            s->SetName(name);
        s->SetNode(0);
        stats[0].push_back(s);

        s=new IntervalStatistics(false,thread);
        if(thread!=-1)
            s->SetName(name + "_" + buf);
        else
            s->SetName(name);
        s->SetNode(0);
        stats[2].push_back(s);
    }
}

Facility::~Facility()
{
    std::vector<Statistics*>::iterator p;
    for(int i=0;i<3;i++)
    {
        for(p=stats[i].begin();p!=stats[i].end();p++)
        {
            delete (*p);
        }
    }
}
}
