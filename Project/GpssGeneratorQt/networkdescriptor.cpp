
#include "networkdescriptor.h"

namespace GeneratorGpss
{

int ThreadDescriptor::_id=1;

ThreadDescriptor::ThreadDescriptor():name("")
{
    this->id=_id++;
    type=OPEN;
}

ThreadDescriptor::ThreadDescriptor(const ThreadDescriptor &obj):name(obj.name)
{
    this->id=obj.id;
    this->type=obj.type;
}

void ThreadDescriptor::setName(QString name)
{
    this->name=name;
}

void ThreadDescriptor::setType(ThreadTypeEnum type)
{
    this->type=type;
}

int ThreadDescriptor::getId()
{
    return id;
}

QString ThreadDescriptor::getName()
{
    return name;
}

ThreadTypeEnum ThreadDescriptor::getType()
{
    return type;
}

int NodeDescriptor::_id=1;

NodeDescriptor::NodeDescriptor()
{
    id=_id++;
}

void NodeDescriptor::setName(QString name)
{
    this->name=name;
}

void NodeDescriptor::setType(NodeTypeEnum type)
{
    this->type=type;
}

int NodeDescriptor::getId()
{
    return id;
}

QString NodeDescriptor::getName()
{
    return name;
}

NodeTypeEnum NodeDescriptor::getType()
{
    return type;
}

vector<ThreadDescriptor> *NetworkDescriptor::getThreads()
{
    return &threads;
}

vector<NodeDescriptor> *NetworkDescriptor::getNodes()
{
    return &nodes;
}

NetworkDescriptor::NetworkDescriptor():threads(),nodes()
{

}

}
